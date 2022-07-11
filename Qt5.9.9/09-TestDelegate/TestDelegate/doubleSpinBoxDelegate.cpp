#include "doubleSpinBoxDelegate.h"
#include  <QDoubleSpinBox>
doubleSpinBoxDelegate::doubleSpinBoxDelegate(QObject *parent):QStyledItemDelegate(parent)
{

}
// 1.创建编辑器
QWidget *doubleSpinBoxDelegate::createEditor(QWidget *parent,
   const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
    editor->setFrame(false); // 无边框
    editor->setMinimum(0);
    editor->setDecimals(2);
    editor->setMaximum(10000);

    return editor;
}
// 2. 从数据模型获取数据,显示到代理组件中
// 当双击单元格进入编辑状态时就会自动调用此函数
void doubleSpinBoxDelegate::setEditorData(QWidget *editor,
                      const QModelIndex &index) const
{
    float value = index.model()->data(index, Qt::EditRole).toFloat();
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->setValue(value);
}
// 3. 将代理组件的数据,保存到数据模型中
// 当用户完成编辑时就会自动调用此函数将界面的数组更新给模型
void doubleSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->interpretText();
    float value = spinBox->value();
    QString str=QString::asprintf("%.2f",value);

    model->setData(index, str, Qt::EditRole);
}
// 4. 设置代理组件大小
void doubleSpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // option.rect传递了适合单元格显示的大小
    editor->setGeometry(option.rect);
    Q_UNUSED(index);
}
