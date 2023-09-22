﻿#include "../../inc/widgets/spinbox.h"

SpinBox::SpinBox(QWidget*parent):QDoubleSpinBox(parent)
{
    setDecimals(0);
    setValue(1);
    INIT_COMPONENT_MINSIZE;
    INIT_FONT;
}

void SpinBox::wheelEvemt(QWheelEvent *e)
{
    QPoint angle = e->angleDelta();
    //qDebug()<<angle;
    if (angle.y() > 0) { // 鼠标前转,数值增加
        if (value()+singleStep() <= maximum()) // 例如359+1=360
            setValue(value()+singleStep()); // 360还是可以设置的
        else setValue(minimum()); // 再大超出范围直接变成最小值
    }
    else { // 鼠标后转,数值减少
        if (value() - singleStep() >= minimum()) // 1-1=0
            setValue(value()-singleStep()); // 0还可以设置
        else setValue(maximum());//倒退为最大值
    }
    e->accept();
}
