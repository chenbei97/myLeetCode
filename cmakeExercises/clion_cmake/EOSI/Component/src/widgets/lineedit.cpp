#include "../../inc/widgets/lineedit.h"

LineEdit::LineEdit(QWidget*parent):QLineEdit(parent)
{
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}

LineEdit::LineEdit(const QString&text,QWidget*parent):QLineEdit(parent)
{
    setText(text);
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}

void LineEdit::setIntRange(int min,int max)
{
    if (validator == nullptr) {
        validator = new QIntValidator(min,max,this);
    } else {
        validator->setRange(min,max);
    }
    setValidator(validator);
}

void LineEdit::setRegExp(const QRegExp &rx)
{
    if (regexValidator == nullptr) {
        regexValidator = new QRegExpValidator(rx,this);
    } else {
        regexValidator->setRegExp(rx);
    }
    setValidator(regexValidator);
}
