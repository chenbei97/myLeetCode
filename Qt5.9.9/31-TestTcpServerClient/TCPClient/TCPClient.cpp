#include "TCPClient.h"
#include "ui_TCPClient.h"
#include <QHostAddress>
#include <QHostInfo>

TCPClient::TCPClient(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TCPClient)
{
      ui->setupUi(this);
      this->tcpClient=new QTcpSocket(this); //创建客户端套接字

    LabSocketState=new QLabel;//状态栏标签
    LabSocketState->setMinimumWidth(250);
    ui->statusbar->addWidget(LabSocketState);

    QString localIP=getLocalIP();//本机IP
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);
    ui->comboServer->addItem(localIP);

    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));
}

TCPClient::~TCPClient()
{
  delete ui;
}

// 1. 关闭事件
void TCPClient::closeEvent(QCloseEvent *event)
{
    if (tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
    event->accept();
}

// 2. 获取本机IP
QString TCPClient::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo hostInfo=QHostInfo::fromName(hostName);
    QString localIP="";
    QList<QHostAddress> addList=hostInfo.addresses();//
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

// 3.连接服务器
void TCPClient::on_actConnect_triggered()
{
    QString  addr=ui->comboServer->currentText();
    quint16  port=ui->spinPort->value();
    tcpClient->connectToHost(addr,port);//连接本机,本机作为服务器,同时本机也作为客户端
}

// 4. 断开连接
void TCPClient::on_actDisconnect_triggered()
{
    if (tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
}

// 5.客户端发送消息给服务器
void TCPClient::on_btnSend_clicked()
{
    QString msg=ui->editMsg->text();
    ui->plainTextEdit->appendPlainText("[发送给服务器的消息：] "+msg);
    ui->editMsg->clear();
    ui->editMsg->setFocus();
    QByteArray  str=msg.toUtf8();
    str.append('\n');
    tcpClient->write(str);
}

// 6.清空文本框
void TCPClient::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

// 7. 响应connected
void TCPClient::onConnected()
{
    ui->plainTextEdit->appendPlainText("**已连接到服务器");
    ui->plainTextEdit->appendPlainText("**服务器地址:"+tcpClient->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("**服务器端口:"+QString::number(tcpClient->peerPort()));
    ui->actConnect->setEnabled(false);
    ui->actDisconnect->setEnabled(true);
}

// 9. 响应disconnected
void TCPClient::onDisconnected()
{
    ui->plainTextEdit->appendPlainText("**已断开与服务器的连接");
    ui->actConnect->setEnabled(true);
    ui->actDisconnect->setEnabled(false);
}

// 10. 响应readyRead
void TCPClient::onSocketReadyRead()
{
    while(this->tcpClient->canReadLine())
        ui->plainTextEdit->appendPlainText("[来自服务器的消息：] "+tcpClient->readLine());
}

// 11. 响应stateChanged
void TCPClient::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        LabSocketState->setText("服务器连接状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        LabSocketState->setText("服务器连接状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        LabSocketState->setText("服务器连接状态：ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        LabSocketState->setText("服务器连接状态：ConnectedState");
        break;
    case QAbstractSocket::BoundState:
        LabSocketState->setText("服务器连接状态：BoundState");
        break;
    case QAbstractSocket::ClosingState:
        LabSocketState->setText("服务器连接状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        LabSocketState->setText("服务器连接状态：ListeningState");
        break;
     }
}

void TCPClient::on_comboServer_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->plainTextEdit->appendPlainText("**请先停止当前连接,再连接新的IP地址和端口!");
}

void TCPClient::on_spinPort_valueChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->plainTextEdit->appendPlainText("**请先停止当前连接,再连接新的IP地址和端口!");
}
