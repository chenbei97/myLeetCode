#include "UdpMultiCast.h"
#include "ui_UdpMultiCast.h"
#include <QHostInfo>

UdpMultiCast::UdpMultiCast(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::UdpMultiCast)
{
      ui->setupUi(this);
      this->LabSocketState=new QLabel;//状态栏显示
      this->LabSocketState->setMinimumWidth(200);
      ui->statusbar->addWidget(LabSocketState);

      QString localIP=getLocalIP();//本地主机名
      this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);

      udpSocket=new QUdpSocket(this);//udp客户端

      // MulticastTtlOption表示UDP组播的数据报生存期,数据报一般每跨1个路由都会减1,缺省值为1表示只能在同一路由下局域网内传播
      udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption,1);
      // udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption,ui->spinTTL->value());

      // udp的2个信号stateChanged和readyRead
      connect(udpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)), this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
      this->onSocketStateChange(udpSocket->state());
      connect(udpSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}

UdpMultiCast::~UdpMultiCast()
{
    delete ui;
    udpSocket->abort();
    delete udpSocket;
}

// 1. 获取本机IP
QString UdpMultiCast::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo hostInfo=QHostInfo::fromName(hostName);
    QString localIP="";
    QList<QHostAddress> addList=hostInfo.addresses();
    if (!addList.isEmpty())
      for (int i=0;i<addList.count();i++)
      {
          QHostAddress aHost=addList.at(i);
          if (QAbstractSocket::IPv4Protocol==aHost.protocol())
          {
              localIP=aHost.toString();
              break;
          }
      }
    return localIP;
}

// 2. 响应stateChanged信号
void UdpMultiCast::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
        case QAbstractSocket::UnconnectedState:
            LabSocketState->setText("UDP客户端连接状态：UnconnectedState");
            break;
        case QAbstractSocket::HostLookupState:
            LabSocketState->setText("UDP客户端连接状态：HostLookupState");
            break;
        case QAbstractSocket::ConnectingState:
            LabSocketState->setText("UDP客户端连接状态：ConnectingState");
            break;
        case QAbstractSocket::ConnectedState:
            LabSocketState->setText("UDP客户端连接状态：ConnectedState");
            break;
        case QAbstractSocket::BoundState:
            LabSocketState->setText("UDP客户端连接状态：BoundState");
            break;
        case QAbstractSocket::ClosingState:
            LabSocketState->setText("UDP客户端连接状态：ClosingState");
            break;
        case QAbstractSocket::ListeningState:
            LabSocketState->setText("UDP客户端连接状态：ListeningState");
    }
}

// 3. 响应readyRead信号
void UdpMultiCast::onSocketReadyRead()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray   datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress    peerAddr; // 发送消息的IP地址
        quint16 peerPort; // 发送消息的端口
        udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
        QString str=datagram.data();
        if (!str.isEmpty())
        {
              QString peer="[来自["+peerAddr.toString()+"]["+QString::number(peerPort)+"]的消息: ";
              ui->plainTextEdit->appendPlainText(peer+str);
        }
        else{
              ui->plainTextEdit->appendPlainText("没有收到消息!");
        }
    }
}

// 4. 连接组播
void UdpMultiCast::on_actStart_triggered()
{
    QString IP=ui->comboIP->currentText();
    this->groupAddress=QHostAddress(IP);//多播组地址,必须是239.0.0.0～239.255.255.255范围,绝对不能用本机地址作为组播地址
    quint16  groupPort=ui->spinPort->value();//端口
    if (udpSocket->bind(QHostAddress::AnyIPv4, groupPort, QUdpSocket::ShareAddress))//任何共享型的IPV4地址和指定端口
    {
          udpSocket->joinMulticastGroup(groupAddress); //加入多播组
          ui->plainTextEdit->appendPlainText("**加入多组播成功");
          ui->plainTextEdit->appendPlainText("**多组播的IP地址："+groupAddress.toString());
          ui->plainTextEdit->appendPlainText("**多组播的绑定端口："+QString::number(groupPort));
          ui->actStart->setEnabled(false);
          ui->actStop->setEnabled(true);
          ui->comboIP->setEnabled(false);
    }
    else
        ui->plainTextEdit->appendPlainText("**加入多组播失败");
}

// 5. 离开组播
void UdpMultiCast::on_actStop_triggered()
{
      udpSocket->leaveMulticastGroup(this->groupAddress);//退出组播
      udpSocket->abort(); //解除绑定
      ui->actStart->setEnabled(true);
      ui->actStop->setEnabled(false);
      ui->comboIP->setEnabled(true);
      ui->plainTextEdit->appendPlainText("**已退出组播,解除端口绑定");
}

// 6. 本机IPV4地址列表
void UdpMultiCast::on_actHostInfo_triggered()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    ui->plainTextEdit->appendPlainText("本机主机名："+hostName+"\n");
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QList<QHostAddress> addList=hostInfo.addresses();//地址列表
    if (!addList.isEmpty())
      for (int i=0;i<addList.count();i++)
      {
          QHostAddress aHost=addList.at(i);
          if (QAbstractSocket::IPv4Protocol==aHost.protocol())
          {
              QString IP=aHost.toString();
              ui->plainTextEdit->appendPlainText("本机IP地址："+aHost.toString());
              if (ui->comboIP->findText(IP)<0)
                  ui->comboIP->addItem(IP);
          }
      }
}

// 7. 发送组播消息
void UdpMultiCast::on_btnMulticast_clicked()
{
    quint16  groupPort=ui->spinPort->value();
    QString  msg=ui->editMsg->text();
    QByteArray  datagram=msg.toUtf8();
    // udpSocket->writeDatagram(datagram,this->groupAddress,groupPort);
    udpSocket->writeDatagram(datagram.data(),datagram.size(),groupAddress,groupPort);
    ui->plainTextEdit->appendPlainText("[组播模式发] "+msg);
    ui->editMsg->clear();
    ui->editMsg->setFocus();
}

// 8.清空文本框
void UdpMultiCast::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}
