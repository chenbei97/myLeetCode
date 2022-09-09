#ifndef ENUM_H
#define ENUM_H
#include <QMetaType>

enum WORKMODE
{
        CC,
        CV
};

enum TIMEOUTCODE
{
    ReceiveTimeout,
    RequestTimeout,
    ReceiveNormal,
    RequestNormal
};

enum SERIALERROR // 和QSerialPort::SerialPortError保持一致
{
      NoError = 0,
      DeviceNotFoundError = 1,
      PermissionError = 2,
      OpenError = 3,
      NotOpenError = 13,
      ParityError = 4,
      FramingError = 5,
      BreakConditionError = 6,
      WriteError = 7,
      ReadError = 8,
      ResourceError = 9,
      UnsupportedOperationError = 10,
      TimeoutError = 12,
      UnknownError = 11
};

enum SETTINGVARIABLE // 要设定的变量,用于serial_variablesetting.h/communicate_with_monitor.cpp确定给串口写入什么类型的命令(1个设定1个查询)
{
    PowerSource,
    PowerLoad,

    ResistanceSource,
    ResistanceLoad,

    Voltage,
    CurrentSource,
    CurrentLoad,

    Current,
    VoltageSource,
    VoltageLoad,

    None
};

// 除了在这里声明注册以外还要在main函数使用qRegisterMetaType<>("")注册类型
Q_DECLARE_METATYPE(WORKMODE)
Q_DECLARE_METATYPE(TIMEOUTCODE)
Q_DECLARE_METATYPE(SERIALERROR)
Q_DECLARE_METATYPE(SETTINGVARIABLE)
#endif // ENUM_H
