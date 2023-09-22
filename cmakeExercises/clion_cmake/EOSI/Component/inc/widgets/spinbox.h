#ifndef SPINBOX_H
#define SPINBOX_H

#include "qspinbox.h"
#include "../public.h"

class COMPONENT_IMEXPORT SpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit SpinBox(QWidget*parent = nullptr);
    void wheelEvemt(QWheelEvent*e) ;
};

#endif // SPINBOX_H
