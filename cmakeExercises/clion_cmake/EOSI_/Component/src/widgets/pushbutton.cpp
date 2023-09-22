#include "../../inc/widgets/pushbutton.h"

PushButton::PushButton(QWidget*parent):QPushButton(parent)
{
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}


PushButton::PushButton(const QString&text,QWidget*parent):QPushButton(parent)
{
    setText(text);
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}

