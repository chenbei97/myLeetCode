#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H
#include    <QObject>
#include    <QWidget>
#include    <QStyledItemDelegate>

class spinBoxDelegate: public QStyledItemDelegate
{
Q_OBJECT
public:
  spinBoxDelegate(QObject *parent=0);

    //自定义代理组件必须继承以下4个函数
    //创建编辑组件
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // SPINBOXDELEGATE_H
