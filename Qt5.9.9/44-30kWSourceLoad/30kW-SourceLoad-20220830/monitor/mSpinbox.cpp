#include "mspinbox.h"
// spinbox组件想要设置固定宽度和高度
MonitorSpinBox::MonitorSpinBox(QWidget * parent):QDoubleSpinBox(parent)
{
      this->setDecimals(3);
      this->setAlignment(Qt::AlignCenter);
      if (parent != Q_NULLPTR)
      {
            this->setFixedSize(parent->width()/4,40);
      }
}
