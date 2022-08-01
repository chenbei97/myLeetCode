#include "TCPServer.h"
#include "ui_TCPServer.h"
#include <QHostInfo>
#include <QDebug>

TCPServer::TCPServer(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TCPServer)
{
    ui->setupUi(this);

    this->LabListen = new QLabel;
    this->LabListen->setMinimumWidth(150);
    ui->statusbar->addWidget(LabListen);
    this->LabSocketState=new QLabel;
    this->LabSocketState->setMinimumWidth(200);
    ui->statusbar->addWidget(LabSocketState);

    QString localIP=getLocalIP();//本机IP
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);
    ui->comboIP->addItem(localIP);

    tcpServer=new QTcpServer(this); // 服务器是固定的,在这里new只需要每次调用即可
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection())); //有新的连接时通知槽函数
}

TCPServer::~TCPServer()
{
  delete ui;
}

// 1. 关闭事件
void TCPServer::closeEvent(QCloseEvent *event)
{
    // 关闭时停止监听
    if (tcpServer->isListening())
        tcpServer->close();
    event->accept();
}

// 2. 获取本机IP地址(IPV4地址)
QString TCPServer::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName); // 查找主机名的IP地址信息
    QString localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();// 列出所有IP地址

    if (!addList.isEmpty())
      for (int i=0;i<addList.count();i++)
      {
          QHostAddress aHost=addList.at(i); // 每一个Address都是一个QHostAddress对象
          if (QAbstractSocket::IPv4Protocol==aHost.protocol()) // 把IPV4地址取出来
          {
              localIP=aHost.toString();
              break;
          }
      }
    return localIP;
}

// 3. 开始监听
void TCPServer::on_actStart_triggered()
{
    QString IP=ui->comboIP->currentText();//IP地址
    quint16 port=ui->spinPort->value();//端口
    QHostAddress addr(IP); // 转为QHostAddress对象
    tcpServer->listen(addr,port);// 服务器监听地址和端口
    // tcpServer->listen(QHostAddress::LocalHost,port);//等价于监听QHostAddress("127.0.0.1").
    ui->plainTextEdit->appendPlainText("**服务器开始监听...");
    ui->plainTextEdit->appendPlainText("**服务器地址："+tcpServer->serverAddress().toString());
    ui->plainTextEdit->appendPlainText("**服务器端口："+QString::number(tcpServer->serverPort()));
    ui->actStart->setEnabled(false);
    ui->actStop->setEnabled(true);
    this->LabListen->setText("监听状态：正在监听");
}

// 4. 停止监听
void TCPServer::on_actStop_triggered()
{
    if (tcpServer->isListening()) //tcpServer正在监听
    {
        tcpServer->close();//停止监听
        ui->actStart->setEnabled(true);
        ui->actStop->setEnabled(false);
        LabListen->setText("监听状态：已停止监听");
    }
}

// 5. 获取本机地址
void TCPServer::on_actHostInfo_triggered()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    ui->plainTextEdit->appendPlainText("本机主机名："+hostName+"\n");
    QHostInfo hostInfo=QHostInfo::fromName(hostName);
    QList<QHostAddress> addList=hostInfo.addresses();// 本机的IP地址列表
    if (!addList.isEmpty())
      for (int i=0;i<addList.count();i++)
      {
          QHostAddress aHost=addList.at(i);
          if (QAbstractSocket::IPv4Protocol==aHost.protocol()) //只显示IPV4地址
          {
              QString IP=aHost.toString();
              ui->plainTextEdit->appendPlainText("本机IP地址："+aHost.toString());
              if (ui->comboIP->findText(IP)<0) // 把IP地址放到下拉项中
                  ui->comboIP->addItem(IP);
          }
      }
}

// 6. 发送消息（这里是服务器端发给客户端）
void TCPServer::on_btnSend_clicked()
{
    // 发送1行字符串,以换行符结束
    // 一般来说,Socket之间通信有2种方式,基于行的或者基于数据块的
    QString msg=ui->editMsg->text();
    ui->plainTextEdit->appendPlainText("[发送给客户端的消息：] "+msg);
    ui->editMsg->clear();
    ui->editMsg->setFocus();
    QByteArray str=msg.toUtf8();
    str.append('\n');//添加一个换行符
    this->tcpSocket->write(str); // 写入获取的客户端套接字
}

// 7. 清空文本框
void TCPServer::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

// 8. 响应stateChanged信号
void TCPServer::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    // enum QAbstractSocket::SocketState一共7种状态
    switch(socketState)
    {
        case QAbstractSocket::UnconnectedState:
            LabSocketState->setText("客户端连接状态：UnconnectedState");
            break;
        case QAbstractSocket::HostLookupState:
            LabSocketState->setText("客户端连接状态：HostLookupState");
            break;
        case QAbstractSocket::ConnectingState:
            LabSocketState->setText("客户端连接状态：ConnectingState");
            break;
        case QAbstractSocket::ConnectedState:
            LabSocketState->setText("客户端连接状态：ConnectedState");
            break;
        case QAbstractSocket::BoundState:
            LabSocketState->setText("客户端连接状态：BoundState");
            break;
        case QAbstractSocket::ClosingState:
            LabSocketState->setText("客户端连接状态：ClosingState");
            break;
        case QAbstractSocket::ListeningState:
            LabSocketState->setText("客户端连接状态：ListeningState");
    }
}

// 9. 响应newConnection信号
void TCPServer::onNewConnection()
{
    qDebug()<<"new connection...";
    // 在newConnection的槽函数中,应该使用nextPendingConnection()接受客户端的连接
    // nextPendingConnection()会返回下一个挂起的连接(因为可能连接处于排队状态)
    // ui->plainTextEdit->appendPlainText("有新连接");
    this->tcpSocket = this->tcpServer->nextPendingConnection(); //创建socket

    // 有新的连接以后,tcpSocket会有已连接connected信号发出
    connect(this->tcpSocket, SIGNAL(connected()),this, SLOT(onClientConnected()));
    this->onClientConnected();// 调用响应槽函数

    // 断开连接信号disconnected先绑定好槽函数
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));

    // 状态改变信号stateChanged绑定好槽函数,这里需要调用1次
    connect(tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    this->onSocketStateChange(tcpSocket->state());// 调用响应槽函数

    // 如果socket有数据会发出readyRead信号,绑定好槽函数
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}

// 10. 响应客户端的connected信号
void TCPServer::onClientConnected()
{
    ui->plainTextEdit->appendPlainText("**客户端已连接成功...");
    ui->plainTextEdit->appendPlainText("**客户端地址:"+tcpSocket->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("**客户端端口:"+QString::number(tcpSocket->peerPort()));
}

// 11. 响应客户端的unConnected信号
void TCPServer::onClientDisconnected()
{
    ui->plainTextEdit->appendPlainText("**客户端已断开连接...");
    tcpSocket->deleteLater(); // tcpSocket是有新连接就创建,断开连接就删除对象,每次是不同的
    // QObject::deleteLater();
}

// 12. 响应服务器端的readyRead信号
void TCPServer::onSocketReadyRead()
{
    while(tcpSocket->canReadLine())
    {
        ui->plainTextEdit->appendPlainText("[来自客户端的消息：] "+tcpSocket->readLine()); // 读取服务器端写入的数据
    }
}

// 13. 监听过程切换了IP地址
void TCPServer::on_comboIP_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->plainTextEdit->appendPlainText("**请先停止当前监听,再监听新的IP地址和端口!");
}

// 14. 监听过程切换了端口
void TCPServer::on_spinPort_valueChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->plainTextEdit->appendPlainText("**请先停止当前监听,再监听新的IP地址和端口!");
}
