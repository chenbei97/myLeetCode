#include "spinBoxDelegate.h"
#include <QSpinBox>
spinBoxDelegate::spinBoxDelegate(QObject *parent):QStyledItemDelegate(parent)
{

}
// 1.创建代理编辑组件
QWidget *spinBoxDelegate::createEditor(QWidget *parent,
   const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    QSpinBox *editor = new QSpinBox(parent); //创建一个QSpinBox
    editor->setFrame(false); //设置为无边框
    editor->setMinimum(0);
    editor->setMaximum(10000);

    return editor;  //返回此编辑器
}
// 2. 从数据模型获取数据,显示到代理组件中
// 当双击单元格进入编辑状态时就会自动调用此函数
void spinBoxDelegate::setEditorData(QWidget *editor,
                      const QModelIndex &index) const
{
    //获取数据模型的模型索引指向的单元的数据
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);  //强制类型转换
    spinBox->setValue(value); //设置编辑器的数值
}
// 3. 将代理组件的数据，保存到数据模型中
// 当用户完成编辑时就会自动调用此函数将界面的数组更新给模型
void spinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                      const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor); //强制类型转换
    spinBox->interpretText(); //解释数据，如果数据被修改后，就触发信号

    int value = spinBox->value(); //获取spinBox的值
    model->setData(index, value, Qt::EditRole); //更新到数据模型
}
// 4. 设置组件大小
void spinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const
{
    // option.rect传递了适合单元格显示的大小
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
