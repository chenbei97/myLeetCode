#include "communication/communication.h"

void Communication::initUI()
{
          initUSB();
          initTCP();

          quitBtn = new QPushButton(tr("退出"));

          mainLayout = new QGridLayout(this);
          mainLayout->addWidget(PortLabel,0,0);
          mainLayout->addWidget(PortConfigureBtn,0,1);
          mainLayout->addWidget(PortConnectBtn,0,2);
          mainLayout->addWidget(PortDisconnectBtn,0,3);
          mainLayout->addWidget(TCPLabel,1,0);
          mainLayout->addWidget(TCPConfigureBtn,1,1);
          mainLayout->addWidget(TCPConnectBtn,1,2);
          mainLayout->addWidget(TCPDisconnectBtn,1,3);
          mainLayout->setRowStretch(2,0);
          mainLayout->addWidget(quitBtn,2,3); // 要求用户只能从这里退出窗口,退出按钮的使能是可以控制的,如果处于运行状态则禁用用户不能退出,逻辑上让用户必须先停止运行才能推出
}

void Communication::initUSB()
{
        PortLabel = new QLabel(tr("串口通信："));
        PortConnectBtn = new QPushButton(tr("连接"));
        PortConfigureBtn = new QPushButton(tr("配置"));
        PortDisconnectBtn = new QPushButton(tr("断开"));
        PortConfigureBtn->setIcon(QIcon(":/images/portsettings.png"));
        PortConnectBtn->setIcon(QIcon(":/images/portconnect.png"));
        PortDisconnectBtn->setIcon(QIcon(":/images/portdisconnect.png"));
        PortConnectBtn->setEnabled(false);
        PortDisconnectBtn->setEnabled(false); // 必须先配置串口
}


void Communication::initTCP()
{
        TCPLabel = new QLabel(tr("TCP通信："));
        TCPConnectBtn = new QPushButton(tr("连接"));
        TCPDisconnectBtn = new QPushButton(tr("断开"));
        TCPConfigureBtn = new QPushButton(tr("配置"));
        TCPDisconnectBtn->setEnabled(false);
}
