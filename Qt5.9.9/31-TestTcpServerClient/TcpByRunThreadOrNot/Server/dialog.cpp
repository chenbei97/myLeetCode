#include "dialog.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
  : QDialog(parent)
  , mainLayout(new QGridLayout(this))
  , PortLabel(new QLabel("端口"))
  , PortEdit(new QLineEdit("8899"))
  , StartConnectBtn(new QPushButton("开始监听"))
  , HistoryMsgBox(new QGroupBox("历史消息"))
  , HistoryMsgEdit(new QPlainTextEdit)
  , HistoryLayout(new QVBoxLayout)
  , SendMsgBox(new QGroupBox("发送消息"))
  , SendMsgEdit(new QPlainTextEdit)
  , SendMsgLayout(new QVBoxLayout)
  , SendBtn(new QPushButton("发送"))
  , mTcpServer(new QTcpServer(this))
{
      resize(600,400);
      setFont(QFont("Times New Roman",12));
      SendBtn->setEnabled(false); // 启动监听后才能发送消息
      mTcpSocket = nullptr;
      //SendBtn->setFixedSize(100,30);

      HistoryLayout->addWidget(HistoryMsgEdit);
      HistoryMsgBox->setLayout(HistoryLayout);

      SendMsgLayout->addWidget(SendMsgEdit);
      SendMsgBox->setLayout(SendMsgLayout);

      mainLayout->addWidget(PortLabel,0,0);
      mainLayout->addWidget(PortEdit,0,1);
      mainLayout->addWidget(HistoryMsgBox,1,0,2,2);
      mainLayout->addWidget(SendMsgBox,3,0,2,2);
      mainLayout->addWidget(StartConnectBtn,5,0);
      mainLayout->addWidget(SendBtn,5,1);

      connect(mTcpServer,&QTcpServer::newConnection,this,[=]{
            mTcpSocket = mTcpServer->nextPendingConnection(); // 获取和客户端连接的套接字
            SendBtn->setEnabled(true); // 有新连接才能发送消息
            HistoryMsgEdit->appendPlainText(QTime::currentTime().toString("hh:mm:ss")+"有新客户端请求连接...");

            connect(mTcpSocket,&QTcpSocket::connected,this,[=]{
            });

            connect(mTcpSocket,&QTcpSocket::disconnected,this,[=]{
                   HistoryMsgEdit->appendPlainText(QTime::currentTime().toString("hh:mm:ss")+"客户端已断开连接...");
                   mTcpSocket->close();
                   mTcpSocket->deleteLater();
                   StartConnectBtn->setDisabled(false);
            });

            connect(mTcpSocket,static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),
                                        this,[=](QAbstractSocket::SocketError socketError){
                      HistoryMsgEdit->appendPlainText(QTime::currentTime().toString("hh:mm:ss")+"连接错误，发生"+mTcpSocket->errorString());
                      Q_UNUSED(socketError);
                      SendBtn->setEnabled(false); // 发生错误就不能再发送消息
                      StartConnectBtn->setEnabled(true);
            });

            // 此时客户端连接上了,就可以处理来自客户端的数据,监听套接字的readyRead信号
            connect(mTcpSocket,&QTcpSocket::readyRead, this, [=]{
                  QByteArray  msg = mTcpSocket->readAll();
                  HistoryMsgEdit->appendPlainText(QString::fromLocal8Bit(msg));
            });


      }); // 有新的连接到来时进行的处理

      connect(StartConnectBtn,&QPushButton::clicked,this,[=]{
            ushort port = PortEdit->text().toUShort();
            mTcpServer->listen(QHostAddress::Any,port);//监听的ip地址类型和端口
            StartConnectBtn->setEnabled(false);
      });

      connect(SendBtn,&QPushButton::clicked,this,[=]{
            QString msg = SendMsgEdit->toPlainText();
            msg = QTime::currentTime().toString("hh:mm:ss")+" 来自服务器的消息：" + msg;
            mTcpSocket->write(msg.toLocal8Bit());
            HistoryMsgEdit->appendPlainText(msg); // 历史消息记录
      });
}


