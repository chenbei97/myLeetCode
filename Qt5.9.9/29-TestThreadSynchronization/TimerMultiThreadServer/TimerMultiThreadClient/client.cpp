#include "client.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDataStream>
#include <QMessageBox>

Client::Client(QWidget *parent)
  : QDialog(parent)
  , serverNameLabel(new QLabel("服务器名："))
  , serverNameEdit(new QLineEdit("LocalHost"))
  , portLabel(new QLabel("端口："))
  , portEdit(new QLineEdit)
  , dateTimeEdit(new QDateTimeEdit)
  , stateLabel(new QLabel("请先运行服务器!"))
  , GetBtn(new QPushButton("获取时间"))
  , quitBtn(new QPushButton("退出"))
  , tcpSocket(new QTcpSocket)
{
      setWindowTitle("多线程时间客户端");
      setFont(QFont("Times New Roman",12));

      QGridLayout * layout = new QGridLayout;
      layout->addWidget(serverNameLabel,0,0);
      layout->addWidget(serverNameEdit,0,1);
      layout->addWidget(portLabel,1,0);
      layout->addWidget(portEdit,1,1);

      QHBoxLayout * hlayout1 = new QHBoxLayout;
      hlayout1->addWidget(dateTimeEdit);
      QHBoxLayout * hlayout2 = new QHBoxLayout;
      hlayout2->addWidget(stateLabel);

      QHBoxLayout * hlayout3 = new QHBoxLayout;
      GetBtn->setDefault(true); //设为默认按钮,用户敲回车会执行此按钮
      GetBtn->setEnabled(false); // 连接上服务器才能获取
      hlayout3->addStretch();
      hlayout3->addWidget(GetBtn);
      hlayout3->addWidget(quitBtn);

      QVBoxLayout * mainLayout = new QVBoxLayout(this);
      mainLayout->addLayout(layout);
      mainLayout->addLayout(hlayout1);
      mainLayout->addLayout(hlayout2);
      mainLayout->addLayout(hlayout3);

      connect(serverNameEdit,SIGNAL(textChanged(QString)),this,SLOT(on_GetBtn_Enable()));
      connect(portEdit,SIGNAL(textChanged(QString)),this,SLOT(on_GetBtn_Enable()));
      connect(GetBtn,SIGNAL(clicked()),this,SLOT(on_GetBtn_Time()));
      connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
      connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(on_ReadTime()));//服务器没有连接这个信号是因为这个服务器有连接时只发消息不会去读
      connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(on_showError(QAbstractSocket::SocketError)));
      portEdit->setFocus();
}

void Client::on_GetBtn_Enable()
{
      GetBtn->setEnabled(!serverNameEdit->text().isEmpty() && !portEdit->text().isEmpty());//2个均不为空成立才设为true
}

void Client::on_GetBtn_Time()
{
      GetBtn->setEnabled(false); // 连接上以后不能再获取
      currentTime = 0;
      tcpSocket->abort(); // 终止连接
      tcpSocket->connectToHost(serverNameEdit->text(),portEdit->text().toInt());//连接新的
}

void Client::on_ReadTime()
{
      QDataStream in(tcpSocket);
      in.setVersion(QDataStream::Qt_5_9);
      if (currentTime == 0)
      {
            if (tcpSocket->bytesAvailable() < (int) sizeof (uint)) // 时间不能超过最大可表示范围
            {
                  return;
            }
            in >> currentTime; // 读取的信息在in里,in再把信息写进currentTime
      }
      dateTimeEdit->setDateTime(QDateTime::fromTime_t(currentTime));//把s转为时间
      GetBtn->setEnabled(true);
}

void Client::on_showError(QAbstractSocket::SocketError socketError)
{
    typedef QAbstractSocket::SocketError e;
    switch (socketError)
    {
          case e::RemoteHostClosedError:break;//不是一个错误,客户端退出后服务器的套接字就会关闭
          case e::HostNotFoundError:QMessageBox::information(this,"消息","没有找到服务器!");break;
          case e::ConnectionRefusedError:QMessageBox::information(this,"消息","连接被拒绝!");break;
          default:QMessageBox::information(this,"消息",tr("错误类型为: ").arg(tcpSocket->errorString()));break;
    }
    GetBtn->setEnabled(true);
}

