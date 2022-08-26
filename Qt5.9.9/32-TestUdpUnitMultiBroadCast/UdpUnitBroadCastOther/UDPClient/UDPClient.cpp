#include "UDPClient.h"
#include <QDebug>
#include <QDateTime>

UDPClient::UDPClient(QWidget *parent,Qt::WindowFlags f)
  : QDialog(parent,f)
{
    setWindowTitle(tr("UDPClient"));
    resize(400,200);
    setFont(QFont("Times New Roman",12));

    mainLayout = new QVBoxLayout(this);
    closedBtn = new QPushButton("关闭");
    textEdit = new QTextEdit;
    mainLayout->addWidget(textEdit);
    mainLayout->addWidget(closedBtn);

    portId = 5555;
    udpSocket = new QUdpSocket;
    bool ret = udpSocket->bind(portId);
    if (!ret)
    {
          QMessageBox::critical(this,tr("错误"),tr("UDP连接绑定端口失败!"));
          return;
    }
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(ReceiveDatagram())); //绑定成功接收来自服务器的信息
    connect(closedBtn,SIGNAL(clicked()),this,SLOT(close()));
}

void UDPClient::ReceiveDatagram()
{
      while (udpSocket->hasPendingDatagrams())  // 如果有信息,readyRead会准备好同时hasPendingDatagrams()返回true
      {
           QByteArray datagram;
           datagram.resize(udpSocket->pendingDatagramSize());//调整接收的大小
           udpSocket->readDatagram(datagram.data(),datagram.size());//读取报文
           // QString msg = datagram.data(); //中文会乱码
           QString msg = QString::fromLocal8Bit(datagram); // 翻译成可读
           textEdit->insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss：")+msg+"\n");
      }
}
