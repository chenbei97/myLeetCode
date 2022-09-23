#include "serial/serial.h"

void SerialConfig::initConnections()
{
      // 串口
      connect(AvailPortsCombo,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                                     this,&SerialConfig::on_PortChanged); // 切换串口展示对应的信息,并更新设置
      // 波特率
      connect(PortBaudRateCombo,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                             this,&SerialConfig::on_BaudRateChanged); // 切换波特率更改保存的设置
      // 确定按钮
      connect(okBtn,&QPushButton::clicked,this, &SerialConfig::on_OkBtn);
}
