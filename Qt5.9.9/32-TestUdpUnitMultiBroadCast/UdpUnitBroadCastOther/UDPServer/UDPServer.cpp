#include "UDPServer.h"
#include <QDebug>

UDPServer::UDPServer(QWidget *parent,Qt::WindowFlags f)
  : QDialog(parent,f)
{
      this->setWindowTitle(tr("UDPServer"));
      TimerLabel = new QLabel(tr("发送报文："));
      TextLineEdit = new QLineEdit("你好吗?");
      StartBtn = new QPushButton(tr("开始"));

      mainLayout = new QVBoxLayout;
      mainLayout->addWidget(TimerLabel);
      mainLayout->addWidget(TextLineEdit);
      mainLayout->addWidget(StartBtn);
      this->setLayout(mainLayout);
      this->setFont(QFont("Times New Roman",12));
      this->resize(250,150);

      portId = 5555; // 端口号参数,服务器将定时给此端口发送广播消息
      isStarted = false;
      udpSocket = new QUdpSocket;
      timer = new QTimer;
      connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));
      connect(timer,SIGNAL(timeout()),this,SLOT(Timeout()));
}

void UDPServer::StartBtnClicked()
{
     if (!isStarted)
     {
          qDebug()<<"starting...";
          StartBtn->setText(tr("停止"));
          isStarted = true;
          timer->setInterval(1000);
          timer->start();
     }
     else
     {
          qDebug()<<"stoping...";
          StartBtn->setText(tr("开始"));
          isStarted = false;
          timer->stop();
     }
}

void UDPServer::Timeout()
{
      QString msg = TextLineEdit->text(); // 要发送的消息
      qint64 length = 0;
      if (msg =="")
      {
          return;
      }
      QByteArray local8bit = msg.toLocal8Bit(); // 用这个格式传输不会中文乱码
      qint64 bytesSize = udpSocket->writeDatagram(local8bit,local8bit.length(),QHostAddress::Broadcast,portId);
      if ((length = bytesSize ) != msg.length())
      {
          qDebug()<<"send datagram failed!";
          return;
      }
      qDebug()<<"send datagram successful!";
}
