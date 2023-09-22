#ifndef TABLEVIEWDELEGATEREADONLY_H
#define TABLEVIEWDELEGATEREADONLY_H

#include "../public.h"

class COMPONENT_IMEXPORT TableViewDelegateReadOnly : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
};

#endif // TABLEVIEWDELEGATEREADONLY_H
