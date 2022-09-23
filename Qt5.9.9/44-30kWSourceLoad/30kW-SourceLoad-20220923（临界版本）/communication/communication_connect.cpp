#include "communication/communication.h"

void Communication::initConnections()
{
        initUIConnections();
        initFixedQueryToCommunicationConnections();
        initCommunicationToFixedQueryConnections();

        // 串口配置改变
        connect(this,&Communication::updatePortSettings,this,[=]{
                // 如果串口配置的新参数和上次不一致就立刻更新mPort的属性
                // 同时让连接按钮使能,断开按钮禁用
                mPort->setPortName(mPortSettings.Name);
                mPort->setBaudRate(mPortSettings.BaudRate);
                mPort->setParity(mPortSettings.Parity);
                mPort->setDataBits(mPortSettings.DataBit);
                mPort->setStopBits(mPortSettings.StopBit);
                mPort->setFlowControl(mPortSettings.FlowControl);
                PortConnectBtn->setEnabled(true); // 配置了串口,连接串口可用,断开按钮不可用
                PortDisconnectBtn->setEnabled(false);
        });

        // 定时器
        connect(mFixedQueryTimer,&QTimer::timeout,this,[=]{
                //mPort->moveToThread(mFixedQueryThread); // 这个是必要的!,不过不必每次都要移动到此线程,移动1次就可以,在mPort创建时移动即可
                mFixedQueryThread->startFixedQueryThread(mPort);
        });
}

void Communication::initUIConnections()
{
       // USB组件的3个按钮
        connect(PortConnectBtn,SIGNAL(clicked()),this,SLOT(on_PortConnectBtn()));
        connect(PortDisconnectBtn,SIGNAL(clicked()),this,SLOT(on_PortDisconnectBtn()));
        connect(PortConfigureBtn,SIGNAL(clicked()),this,SLOT(on_PortConfigureBtn()));

        // TCP组件的2个按钮
        connect(TCPConnectBtn,SIGNAL(clicked()),this,SLOT(on_TCPConnectBtn()));
        connect(TCPConfigureBtn,SIGNAL(clicked()),this,SLOT(on_TCPConfigureBtn()));

        // 退出按钮
        connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
}

// 固定查询线程的信号=>通讯界面的槽函数
void Communication::initFixedQueryToCommunicationConnections()
{
        // 固定查询线程自己的finished信号和deleteLater槽函数
        connect(mFixedQueryThread,SIGNAL(finished()),mFixedQueryThread,
                      SLOT(deleteLater()),Qt::DirectConnection); //保证工作线程结束之后删除对象,因为是同一线程所以直接连接
        // 固定查询线程发射的MEAS-VAPR数据信号,传递给通讯界面
        connect(mFixedQueryThread,SIGNAL(availableFixedQueryData(QByteArray)),
                      this,SLOT(on_FixedQueryThread_AvailableFixedQueryData(QByteArray)));
        // 固定查询线程发射的设定查询数据信号,传递给通信界面
        connect(mFixedQueryThread,SIGNAL(availableSetQueryData(QByteArray,QByteArray,SETTINGVARIABLE)),
                      this,SLOT(on_FixedQueryThread_AvailableSetQueryData(QByteArray,QByteArray,SETTINGVARIABLE)));
       // 固定查询线程发射的串口错误码和串口写入回复超时信息
        connect(mFixedQueryThread,SIGNAL(errorCode(TIMEOUTCODE)),
                      this,SLOT(on_FixedQueryThread_ErrorCode(TIMEOUTCODE)));
        connect(mFixedQueryThread,SIGNAL(errorCode(SERIALERROR)),
                      this,SLOT(on_FixedQueryThread_ErrorCode(SERIALERROR)));
}

// 通讯界面的信号=>固定查询线程的槽函数
void Communication::initCommunicationToFixedQueryConnections()
{
        connect(this,SIGNAL(sendInfo(SETTINGVARIABLE,QByteArray)),
                      mFixedQueryThread,SLOT(on_SendInfo(SETTINGVARIABLE,QByteArray))); // 更新设定查询的角色
}






