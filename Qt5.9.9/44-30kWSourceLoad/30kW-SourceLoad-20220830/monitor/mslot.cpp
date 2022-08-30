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
        mPRSettings.PowerSource = value;
        mPRSettings.PowerSourceString = QString::number(value,'f',3);
}

void Monitor::on_SetPowerLoad(double value)
{
        mPRSettings.PowerLoad = value;
        mPRSettings.PowerLoadString = QString::number(value,'f',3);
}

// （3）电阻面板的2个设置
void Monitor::on_SetResistanceSource(double value)
{
        mPRSettings.ResistanceSource = value;
        mPRSettings.ResistanceSourceString = QString::number(value,'f',3);
}

void Monitor::on_SetResistanceLoad(double value)
{
        mPRSettings.ResistanceLoad = value;
        mPRSettings.ResistanceLoadString = QString::number(value,'f',3);
}

// （4）CV模式，1个电压，2个电流
void Monitor::on_SetVoltage(double value)
{
        mCVSettings.Voltage = value;
        mCVSettings.VoltageString = QString::number(value,'f',3);
        //qDebug()<<mCVSettings.Voltage<<" "<<mCVSettings.VoltageString;
}

void Monitor::on_SetCurrentSource(double value)
{
        mCVSettings.CurrentSource= value;
        mCVSettings.CurrentSourceString = QString::number(value,'f',3);
}

void Monitor::on_SetCurrentLoad(double value)
{
        mCVSettings.CurrentLoad= value;
        mCVSettings.CurrentLoadString = QString::number(value,'f',3);
}

// （5） CC模式，1个电流，2个电压
void Monitor::on_SetCurrent(double value)
{
        mCCSettings.Current = value;
        mCCSettings.CurrentString = QString::number(value,'f',3);
}

void Monitor::on_SetVoltageSource(double value)
{
        mCCSettings.VoltageSource = value;
        mCCSettings.VoltageSourceString = QString::number(value,'f',3);
}

void Monitor::on_SetVoltageLoad(double value)
{
        mCCSettings.VoltageLoad = value;
        mCCSettings.VoltageLoadString = QString::number(value,'f',3);
}
