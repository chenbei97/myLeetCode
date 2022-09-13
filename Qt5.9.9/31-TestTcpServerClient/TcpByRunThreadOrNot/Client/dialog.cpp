#include "dialog.h"
#include <QTime>

Dialog::Dialog(QWidget *parent)
  : QDialog(parent)
  , mainLayout(new QGridLayout(this))
  , ServerPortLabel(new QLabel("服务器端口："))
  , ServerPort(new QLineEdit("8899"))
  , ServerIPLabel(new QLabel("服务器地址："))
  , ServerIP(new QLineEdit("127.0.0.1"))
  , HistoryMsgBox(new QGroupBox("历史消息"))
  , HistoryMsgEdit(new QPlainTextEdit)
  , HistoryMsgLayout(new QVBoxLayout)
  , SendMsgBox(new QGroupBox("发送消息"))
  , SendMsgEdit(new QPlainTextEdit)
  , SendMsgLayout(new QVBoxLayout)
  , ConnectBtn(new QPushButton("开始连接"))
  , DisconnectBtn(new QPushButton("断开连接"))
  , SendBtn(new QPushButton("发送消息"))
  , mTcpSocket(new QTcpSocket(this)) // 服务器的套接字要一开始就创建好
{
      resize(600,450);
      setFont(QFont("Times New Roman",12));
      SendBtn->setEnabled(false); // 开始连接后才能发送消息
      DisconnectBtn->setEnabled(false); // 还没连接不能断开

      HistoryMsgLayout->addWidget(HistoryMsgEdit);
      HistoryMsgBox->setLayout(HistoryMsgLayout);
      SendMsgLayout->addWidget(SendMsgEdit);
      SendMsgBox->setLayout(SendMsgLayout);

      mainLayout->addWidget(ServerPortLabel,0,0);
      mainLayout->addWidget(ServerPort,0,1);
      mainLayout->addWidget(ServerIPLabel,1,0);
      mainLayout->addWidget(ServerIP,1,1);
      mainLayout->addWidget(HistoryMsgBox,2,0,2,2);
      mainLayout->addWidget(SendMsgBox,4,0,2,2);
      mainLayout->addWidget(ConnectBtn,6,0);
      mainLayout->addWidget(DisconnectBtn,6,1);
      mainLayout->addWidget(SendBtn,7,1);

      connect(ConnectBtn,&QPushButton::clicked,this,[=]{
            QString ip = ServerIP->text();
            ushort port = ServerPort->text().toUShort();
            mTcpSocket->connectToHost(ip,port,QIODevice::ReadWrite);
            ConnectBtn->setEnabled(false);
      });

      connect(DisconnectBtn,&QPushButton::clicked,this,[=]{
            mTcpSocket->disconnectFromHost();
            mTcpSocket->close();
            DisconnectBtn->setEnabled(false);
      });

      connect(SendBtn,&QPushButton::clicked,this,[=]{

            QByteArray msg = (QTime::currentTime().toString("hh:mm:ss")+" 来自客户端的消息："+SendMsgEdit->toPlainText()).toLocal8Bit();
            mTcpSocket->write(msg);
            HistoryMsgEdit->appendPlainText(QString::fromLocal8Bit(msg)); // 历史消息记录
      });

      connect(mTcpSocket,&QTcpSocket::connected,this,[=]{
            SendBtn->setEnabled(true);
            DisconnectBtn->setEnabled(true);
            HistoryMsgEdit->appendPlainText(QTime::currentTime().toString("hh:mm:ss")+"已成功连接服务器...");
      });

      connect(mTcpSocket,&QTcpSocket::disconnected,this,[=]{
            SendBtn->setEnabled(false);
            ConnectBtn->setEnabled(true);
            HistoryMsgEdit->appendPlainText(QTime::currentTime().toString("hh:mm:ss")+"已断开服务器...");
      });

      connect(mTcpSocket,&QTcpSocket::readyRead,this,[=]{ // 读取来自服务器的回复
            QByteArray msg = mTcpSocket->readAll();
            HistoryMsgEdit->appendPlainText(QString::fromLocal8Bit(msg)); // 历史消息记录
      });
}


