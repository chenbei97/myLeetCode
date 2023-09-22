#include "../../inc/widgets/dateedit.h"

DateEdit::DateEdit(QWidget*parent):QDateEdit(parent)
{
    setCalendarPopup(true);
    setDateRange(QDate(2023,6,8),QDate::currentDate());
    setDisplayFormat("yyyy/MM/dd");
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}
