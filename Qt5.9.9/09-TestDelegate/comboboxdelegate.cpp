#include "comboBoxDelegate.h"
#include    <QComboBox>

comboBoxDelegate::comboBoxDelegate(QObject *parent):QItemDelegate(parent)
{

}

// 1.创建编辑器
QWidget *comboBoxDelegate::createEditor(QWidget *parent,
       const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     // 使用comboBox创建
    QComboBox *editor = new QComboBox(parent); // 注意,基于parent创建

    editor->addItem("优");
    editor->addItem("良");
    editor->addItem("一般");
    editor->addItem("不合格");

    Q_UNUSED(option);
    Q_UNUSED(index);
    return editor;
}

// 2.获取底层数据转为combobox显示,从数据模型获取数据,显示到代理组件中
// 当双击单元格进入编辑状态时就会自动调用此函数
void comboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString str = index.model()->data(index, Qt::EditRole).toString(); // 把index指向的模型数据转为str放在combobox显示

    QComboBox *comboBox = static_cast<QComboBox*>(editor); // 将其转为combobox指针
    comboBox->setCurrentText(str); // 设置文字
}

// 3. 通过combobox来设置模型数据,将代理组件的数据,保存到数据模型中
// 当用户完成编辑时就会自动调用此函数将界面的数组更新给模型
void comboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    QString str = comboBox->currentText();

    model->setData(index, str, Qt::EditRole);
}

// 4. 设置代理组件大小
void comboBoxDelegate::updateEditorGeometry(QWidget *editor,
                const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // option.rect传递了适合单元格显示的大小
    editor->setGeometry(option.rect);
    Q_UNUSED(index);
}
