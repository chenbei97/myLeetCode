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

enum TCPERRORSTATE // 融合了QAbstractSocket::SocketError和QAbstractSocket::SocketState
{
     ConnectionRefusedError = 0, // 连接被拒绝
     RemoteHostClosedError = 1, // 远程服务器关闭
     HostNotFoundError = 2, // 未找到服务器
     SocketAccessError = 3, // 套接字没有权限
     SocketResourceError = 4, // 套接字资源错误
     SocketTimeoutError = 5 , // 套接字连接超时错误
     DatagramTooLargeError = 6, // 数据报太大
     NetworkError = 7, // 网络错误
     AddressInUseError = 8, // 远程服务器已被占用
     SocketAddressNotAvailableError = 9, // IP地址错误
     UnsupportedSocketOperationError = 10, // 不支持的套接字操作(例如缺乏IPV6支持)
     ProxyAuthenticationRequiredError = 12, // 套接字代理需要身份验证
     SslHandshakeFailedError = 13, // SSL/TLS 握手失败
     UnfinishedSocketOperationError = 11, // 未完成的套接字操作
     ProxyConnectionRefusedError = 14, // 连接代理服务器被拒绝
     ProxyConnectionClosedError =15, // 与代理服务器的意外关闭
     ProxyConnectionTimeoutError = 16, // 与代理服务器连接超时
     ProxyNotFoundError = 17, // 未找到代理
     ProxyProtocolError = 18, // 与代理服务器的连接协商失败
     OperationError = 19, // 套接字处于不允许的状态
     SslInternalError = 20, // SSL库内部错误
     SslInvalidUserDataError =21, // 无效的SSL证明
     TemporaryError = 22, // 临时错误
     UnknownSocketError = -1, // 未知错误

     UnconnectedState = 30, // 未连接
     HostLookupState  = 31, // 正在查找主机
     ConnectingState = 32, // 正在连接
     ConnectedState = 33, // 已连接
     BoundState = 34, //  阻塞
     ListeningState = 35, // 正在监听
     ClosingState = 36, // 即将关闭
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
Q_DECLARE_METATYPE(TCPERRORSTATE)
#endif // ENUM_H
