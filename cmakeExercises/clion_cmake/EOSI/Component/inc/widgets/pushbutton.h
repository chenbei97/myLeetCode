#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "qpushbutton.h"
#include "../public.h"

class COMPONENT_IMEXPORT PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget*parent=nullptr);
    explicit PushButton(const QString&text,QWidget*parent=nullptr);
};

#endif // PUSHBUTTON_H
