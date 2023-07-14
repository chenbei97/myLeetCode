#ifndef DOUBLESPINBOXDELEGATE_H
#define DOUBLESPINBOXDELEGATE_H
#include    <QObject>
#include    <QWidget>
#include    <QStyledItemDelegate>

class doubleSpinBoxDelegate: public QStyledItemDelegate
{
public:
  doubleSpinBoxDelegate(QObject *parent=0);
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

#endif // DOUBLESPINBOXDELEGATE_H
