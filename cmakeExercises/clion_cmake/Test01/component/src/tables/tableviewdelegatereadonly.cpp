#include "../../inc/tables/tableviewdelegatereadonly.h"

QWidget *TableViewDelegateReadOnly::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const
{
    Q_UNUSED(parent);
    Q_UNUSED(index);
    Q_UNUSED(option);
    return nullptr;
}
