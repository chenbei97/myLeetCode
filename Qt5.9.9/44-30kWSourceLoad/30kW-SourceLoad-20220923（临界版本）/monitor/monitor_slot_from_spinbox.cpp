#include "monitor/monitor.h"

// （1）是否显示电阻面板
void Monitor::on_IsShowResistance(bool checked)
{
       if (checked)
       {
            ResistanceGroupBox->show();
       }
       else {
            ResistanceGroupBox->hide();
       }
}

// （2）功率面板的2个设置
void Monitor::on_SetPowerSource(double value)
{
        auto s = QString::number(value,'f',3).toLocal8Bit();
        emit powSourceChanged(s);
}

void Monitor::on_SetPowerLoad(double value)
{
      auto s = QString::number(value,'f',3).toLocal8Bit();
       emit powLoadChanged(s);
}

// （3）电阻面板的2个设置
void Monitor::on_SetResistanceSource(double value)
{
      auto s = QString::number(value,'f',3).toLocal8Bit();
      emit resSourceChanged(s);
}

void Monitor::on_SetResistanceLoad(double value)
{
     auto s = QString::number(value,'f',3).toLocal8Bit();
     emit resLoadChanged(s);
}

// （4）CV模式，1个电压，2个电流
void Monitor::on_SetVoltage(double value)
{
      auto s = QString::number(value,'f',3).toLocal8Bit();
      emit voltChanged(s);
}

void Monitor::on_SetCurrentSource(double value)
{
      auto s = QString::number(value,'f',3).toLocal8Bit();
      emit currSourceChanged(s);
}

void Monitor::on_SetCurrentLoad(double value)
{
      auto s = QString::number(value,'f',3).toLocal8Bit();
      emit currLoadChanged(s);
}

// （5） CC模式，1个电流，2个电压
void Monitor::on_SetCurrent(double value)
{
    auto s = QString::number(value,'f',3).toLocal8Bit();
    emit currChanged(s);
}

void Monitor::on_SetVoltageSource(double value)
{
    auto s = QString::number(value,'f',3).toLocal8Bit();
    emit voltSourceChanged(s);
}

void Monitor::on_SetVoltageLoad(double value)
{
    auto s = QString::number(value,'f',3).toLocal8Bit();
    emit voltLoadChanged(s);
}
