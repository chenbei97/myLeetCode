#ifndef TABLEVIEWDELEGATELABEL_H
#define TABLEVIEWDELEGATELABEL_H

#include "../widgets/label.h"
#include "../widgets/picture.h"
#include "tablemodeldata.h"

class COMPONENT_IMEXPORT TableViewDelegateLabel : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const Q_DECL_OVERRIDE;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option, const QModelIndex &index) Q_DECL_OVERRIDE;
};
Q_DECLARE_METATYPE(QPixmap*)
#endif // TABLEVIEWDELEGATELABEL_H
