#include "communication/communication.h"

// 响应来自监控界面的10个信号 和 来自设定控制器的5个信号

// 功率
void Communication::on_Monitor_PowSourceChanged(QByteArray value)
{
      mSetController->setVariable(value,SETTINGVARIABLE::PowerSource);
      emit sendInfo(SETTINGVARIABLE::PowerSource,value);
}

void Communication::on_Monitor_PowLoadChanged(QByteArray value)
{
      mSetController->setVariable(value,SETTINGVARIABLE::PowerLoad);
      emit sendInfo(SETTINGVARIABLE::PowerLoad,value);
}

// 电阻
void Communication::on_Monitor_ResSourceChanged(QByteArray value)
{
      mSetController->setVariable(value,SETTINGVARIABLE::ResistanceSource);
      emit sendInfo(SETTINGVARIABLE::ResistanceSource,value);
}

void Communication::on_Monitor_ResLoadChanged(QByteArray value)
{
     mSetController->setVariable(value,SETTINGVARIABLE::ResistanceLoad);
     emit sendInfo(SETTINGVARIABLE::ResistanceLoad,value);
}

// CV模式电压+2个电流
void Communication::on_Monitor_VoltChanged(QByteArray value)
{
    mSetController->setVariable(value,SETTINGVARIABLE::Voltage);
    emit sendInfo(SETTINGVARIABLE::Voltage,value);
}

void Communication::on_Monitor_CurrSourceChanged(QByteArray value)
{
    mSetController->setVariable(value,SETTINGVARIABLE::CurrentSource);
    emit sendInfo(SETTINGVARIABLE::CurrentSource,value);
}

void Communication::on_Monitor_CurrLoadChanged(QByteArray value)
{
    mSetController->setVariable(value,SETTINGVARIABLE::CurrentLoad);
    emit sendInfo(SETTINGVARIABLE::CurrentLoad,value);
}

// CC模式电流+2个电压
void Communication::on_Monitor_CurrChanged(QByteArray value)
{
    mSetController->setVariable(value,SETTINGVARIABLE::Current);
    emit sendInfo(SETTINGVARIABLE::Current,value);
}

void Communication::on_Monitor_VoltSourceChanged(QByteArray value)
{
    mSetController->setVariable(value,SETTINGVARIABLE::VoltageSource);
    emit sendInfo(SETTINGVARIABLE::VoltageSource,value);
}

void Communication::on_Monitor_VoltLoadChanged(QByteArray value)
{
    mSetController->setVariable(value,SETTINGVARIABLE::VoltageLoad);
    emit sendInfo(SETTINGVARIABLE::VoltageLoad,value);
}
