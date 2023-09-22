#ifndef TABLEVIEWDELEGATE2X2_H
#define TABLEVIEWDELEGATE2X2_H

#include "../widgets/picture.h"
#include "tableviewwidget2x2.h"
#include "tablemodeldata.h"
#include "tableview.h"

class COMPONENT_IMEXPORT TableViewDelegate2x2 : public QStyledItemDelegate
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
private:
    void paintBorder(QPainter *painter, const QStyleOptionViewItem &option) const;
    void paintPixmap(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paintSelectedHighlight(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paintMouseHighlight(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // TABLEVIEWDELEGATE2X2_H
