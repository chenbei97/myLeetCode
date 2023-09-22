#include "../../inc/tables/table24.h"

Table24::Table24(QWidget *parent) : Table(parent)
{
    mDelegate = new TableViewDelegateLabel;
    setDelegate(mDelegate);
    setDelegateType(LabelDelegate);
    setItemCount(4,6);
}
