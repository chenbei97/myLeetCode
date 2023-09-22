#include "../../inc/tables/table6.h"

Table6::Table6(QWidget *parent) : Table(parent)
{
    mDelegate = new TableViewDelegateLabel;
    setDelegate(mDelegate);
    setDelegateType(LabelDelegate);
    setItemCount(2,3);
}
