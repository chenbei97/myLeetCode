#include "communication/communication.h"

void Communication::initConnections()
{
       // USB组件的3个按钮
        connect(PortConnectBtn,SIGNAL(clicked()),this,SLOT(on_PortConnectBtn()));
        connect(PortDisconnectBtn,SIGNAL(clicked()),this,SLOT(on_PortDisconnectBtn()));
        connect(PortConfigureBtn,SIGNAL(clicked()),this,SLOT(on_PortConfigureBtn()));
        // 串口属性改变
        connect(this,SIGNAL(updatePortSettings()),this,SLOT(on_UpdatePortSettings())); // 信号只要改变就更改port的设置
        // 固定查询线程
        connect(mFixedQueryThread,SIGNAL(finished()),mFixedQueryThread,SLOT(deleteLater()),Qt::DirectConnection); //保证工作线程结束之后删除对象,因为是同一线程所以直接连接
        connect(mFixedQueryThread,SIGNAL(availableFixedQueryData(QByteArray)),this,SLOT(on_FixedQueryThread_AvailableFixedQueryData(QByteArray)));//处理固定查询数据
        connect(mFixedQueryThread,SIGNAL(availableSetQueryData(QByteArray,QByteArray,SETTINGVARIABLE)),this,SLOT(on_FixedQueryThread_AvailableSetQueryData(QByteArray,QByteArray,SETTINGVARIABLE)));// 处理设定查询数据
        connect(mFixedQueryThread,SIGNAL(errorCode(TIMEOUTCODE)),this,SLOT(on_FixedQueryThread_ErrorCode(TIMEOUTCODE)));
        connect(mFixedQueryThread,SIGNAL(errorCode(SERIALERROR)),this,SLOT(on_FixedQueryThread_ErrorCode(SERIALERROR)));
        connect(this,SIGNAL(sendInfo(SETTINGVARIABLE,QByteArray)),mFixedQueryThread,SLOT(on_SendInfo(SETTINGVARIABLE,QByteArray))); // 更新设定查询的角色
        // 设定控制器线程
        connect(mSetControllerThread,SIGNAL(finished()),mSetControllerThread,SLOT(deleteLater()),Qt::DirectConnection);
        // 定时器
        connect(mFixedQueryTimer,SIGNAL(timeout()),this,SLOT(startFixedQueryThread()));

        // TCP组件的2个按钮
        connect(TCPConnectBtn,SIGNAL(clicked()),this,SLOT(on_TCPConnectBtn()));
        connect(TCPConfigureBtn,SIGNAL(clicked()),this,SLOT(on_TCPConfigureBtn()));

        // 退出按钮
        connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
}
