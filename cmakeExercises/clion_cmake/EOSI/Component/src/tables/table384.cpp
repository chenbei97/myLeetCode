#include "../../inc/tables/table384.h"

Table384::Table384(QWidget *parent) : Table(parent)
{
    setDelegate(new TableViewDelegate2x2);
    setDelegate(mDelegate);
    setDelegateType(Widget2x2Delegate);
    setItemCount(8,12);
}




