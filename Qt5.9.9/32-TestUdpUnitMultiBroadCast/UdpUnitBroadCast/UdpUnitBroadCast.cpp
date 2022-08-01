#include "UdpUnitBroadCast.h"
#include "ui_UdpUnitBroadCast.h"
#include <QHostInfo>

UdpUnitBroadCast::UdpUnitBroadCast(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::UdpUnitBroadCast)
{
    ui->setupUi(this);

    this->LabSocketState=new QLabel;// 连接情况状态栏显示
    this->LabSocketState->setMinimumWidth(200);
    ui->statusbar->addWidget(LabSocketState);

    QString localIP=getLocalIP();//本机IP
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);
    ui->comboTargetIP->addItem(localIP);

    this->udpSocket=new QUdpSocket(this);//udp客户端
    // udp的2个信号
    connect(udpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    this->onSocketStateChange(udpSocket->state()); // 先调用1次
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}

UdpUnitBroadCast::~UdpUnitBroadCast()
{
    udpSocket->abort();
    delete udpSocket;
    delete ui;
}

// 1. 获取本机地址
QString UdpUnitBroadCast::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo hostInfo=QHostInfo::fromName(hostName);
    QString localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();//
    if (!addList.isEmpty())
      for (int i=0;i<addList.count();i++)
      {
          QHostAddress aHost=addList.at(i);
          if (QAbstractSocket::IPv4Protocol==aHost.protocol()) // 只显示IPV4地址
          {
              localIP=aHost.toString();
              break;
          }
      }
    return localIP;
}

// 2. 响应udp的stateChanged
void UdpUnitBroadCast::onSocketStateChange(QAbstractSocket::SocketState socketState)
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

// 3. 响应udp的readyRead
void UdpUnitBroadCast::onSocketReadyRead()
{
    while(udpSocket->hasPendingDatagrams()) //当此udp客户端有可以读取的数据报时
    {
        QByteArray   datagram;
        datagram.resize(udpSocket->pendingDatagramSize());//调整至待读取的数据报字节大小,一般不超过512字节
        QHostAddress    peerAddr; // 用于记录对方客户端的地址
        quint16 peerPort; // 用于记录对方客户端的端口
        this->udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort); //开始读取,必须指定读取的大小
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

// 4. 绑定端口
void UdpUnitBroadCast::on_actStart_triggered()
{
    quint16 port=ui->spinBindPort->value(); //本机UDP端口
    if (udpSocket->bind(port))//绑定端口成功
    {
        ui->plainTextEdit->appendPlainText("**"+QString::number(port)+"端口已成功绑定");
        ui->actStart->setEnabled(false);
        ui->actStop->setEnabled(true);
    }
    else
        ui->plainTextEdit->appendPlainText("**"+QString::number(port)+"端口绑定失败");
}

// 5. 解除端口绑定
void UdpUnitBroadCast::on_actStop_triggered()
{
    this->udpSocket->abort(); //直接终止
    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
    ui->plainTextEdit->appendPlainText("**"+ui->spinBindPort->text()+"端口已解除绑定");
}

// 6. 获取本机IP信息
void UdpUnitBroadCast::on_actHostInfo_triggered()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    ui->plainTextEdit->appendPlainText("本机主机名："+hostName+"\n");
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QList<QHostAddress> addList=hostInfo.addresses();//
    if (!addList.isEmpty())
      for (int i=0;i<addList.count();i++)
      {
          QHostAddress aHost=addList.at(i);
          if (QAbstractSocket::IPv4Protocol==aHost.protocol())
          {
              QString IP=aHost.toString();
              ui->plainTextEdit->appendPlainText("本机IP地址："+aHost.toString());
              if (ui->comboTargetIP->findText(IP)<0)
                  ui->comboTargetIP->addItem(IP);
          }
      }
}

// 7. 清除文本框
void UdpUnitBroadCast::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

// 8. 发送消息（必须指定目标IP地址和端口）
void UdpUnitBroadCast::on_btnSend_clicked()
{
    QString targetIP=ui->comboTargetIP->currentText(); //目标IP
    QHostAddress  targetAddr(targetIP);
    quint16 targetPort=ui->spinTargetPort->value();//目标port
    QString  msg=ui->editMsg->text();//发送的消息内容
    QByteArray  str=msg.toUtf8(); // 无需换行符号
    udpSocket->writeDatagram(str,targetAddr,targetPort); //发出数据报
    ui->plainTextEdit->appendPlainText("[单播模式发] "+msg);
    ui->editMsg->clear();
    ui->editMsg->setFocus();
}

// 9. 广播消息
void UdpUnitBroadCast::on_btnBroadcast_clicked()
{
    quint16 targetPort=ui->spinTargetPort->value(); //目标端口
    QString  msg=ui->editMsg->text();
    QByteArray  str=msg.toUtf8();
    udpSocket->writeDatagram(str,QHostAddress::Broadcast,targetPort); // 唯一的区别,指定广播模式
    ui->plainTextEdit->appendPlainText("[广播模式发] "+msg);
    ui->editMsg->clear();
    ui->editMsg->setFocus();
}
