#include "monitor/monitor.h"

// 监控界面的功率和电阻spinbox组件在源载2个模式下的值改变信号、是否显示电阻面板的checkbox
// 没有电压和电流是因为分为CC/CV模式，这些组件是动态创建的不是全局指针
// monitor_initial.cpp在初始化spinbox时就完成了信号槽的连接
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
