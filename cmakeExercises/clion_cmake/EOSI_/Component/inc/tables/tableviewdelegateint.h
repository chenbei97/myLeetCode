#ifndef TABLEVIEWDELEGATEINT_H
#define TABLEVIEWDELEGATEINT_H

#include "../widgets/lineedit.h"

#define GroupNameColumn 0
#define PointXColumn 1
#define PointYColumn 2
#define PointNameColumn 3
#define PointOrderColumn 4

class COMPONENT_IMEXPORT TableViewDelegateInt : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit TableViewDelegateInt(int min,int max,QObject*parent = nullptr);
    void setRange(int min,int max);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,const QModelIndex &index) const override;
private:
    int bottom;
    int top;
};

#endif // TABLEVIEWDELEGATEINT_H
