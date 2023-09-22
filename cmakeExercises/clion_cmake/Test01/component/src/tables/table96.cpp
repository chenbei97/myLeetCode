#include "../../inc/tables/table96.h"

Table96::Table96(QWidget *parent) : Table(parent)
{
    mDelegate = new TableViewDelegateLabel;
    setDelegate(mDelegate);
    setDelegateType(LabelDelegate);
    setItemCount(8,12);
}
