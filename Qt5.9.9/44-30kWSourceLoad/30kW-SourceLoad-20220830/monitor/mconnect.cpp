#include "monitor/monitor.h"

void Monitor::initConnections()
{
      connect(IsShowResistance,&QCheckBox::stateChanged,this,&Monitor::on_IsShowResistance);
      connect(SetPowerSource,static_cast<void (QDoubleSpinBox::*)(double) > (&QDoubleSpinBox::valueChanged)
                                              ,this,&Monitor::on_SetPowerSource);
      connect(SetPowerLoad,static_cast<void (QDoubleSpinBox::*)(double) > (&QDoubleSpinBox::valueChanged)
                                              ,this,&Monitor::on_SetPowerLoad);
      connect(SetResistanceSource,static_cast<void (QDoubleSpinBox::*)(double) > (&QDoubleSpinBox::valueChanged)
                                              ,this,&Monitor::on_SetResistanceSource);
      connect(SetResistanceLoad,static_cast<void (QDoubleSpinBox::*)(double) > (&QDoubleSpinBox::valueChanged)
                                              ,this,&Monitor::on_SetResistanceLoad);
}
