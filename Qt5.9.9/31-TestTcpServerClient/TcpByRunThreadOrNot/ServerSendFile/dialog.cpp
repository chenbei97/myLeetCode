#include "dialog.h"
#include <receivefile.h>
#include <QMessageBox>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
  : QDialog(parent)
  , mainLayout(new QHBoxLayout(this))
  , PortLabel(new QLabel("端口："))
  , PortEdit(new QLineEdit("8899"))
  , ConnectBtn(new QPushButton("开始监听"))
  , mTcpServer(new QTcpServer(this))
{
      qDebug()<<"服务器线程地址："<<QThread::currentThread();
      resize(400,250);
      setFont(QFont("Times New Roman",12));

      mainLayout->addWidget(PortLabel);
      mainLayout->addWidget(PortEdit);
      mainLayout->addWidget(ConnectBtn);

      connect(ConnectBtn,&QPushButton::clicked,this,[=]{
            ushort port = PortEdit->text().toUShort();
            mTcpServer->listen(QHostAddress::Any,port);
            ConnectBtn->setEnabled(false);
      });

      connect(mTcpServer,&QTcpServer::newConnection,this,[=]{
              QTcpSocket * mTcpSocket = mTcpServer->nextPendingConnection(); // 这个套接字要在子线程操作(接收数据)
              // 传递到子线程的方式有2种,第一种是信号槽,第二种是传参的方式(传参还可以直接传递指针,也可以只传递指针的必要参数也就是套接字描述符)
              // 如果传参使用传递指针的方式,要注意主线程不能对该套接字进行任何操作，例如开启和关闭，只能在工作线程来控制
              // 如果是传递套接字描述符的方法，需要重载服务器对象的函数mTcpServer->incomingConnection()

              // 这里演示第二种传参法,且是传递指针的方法，那么需要在ReceiveFile构造函数新增1个参数
              ReceiveFile * worker = new ReceiveFile(mTcpSocket); // 传递指针
              worker->start();

              connect(worker,&ReceiveFile::receiveEnd,this,[=]{ // 当工作任务退出后要释放工作线程对象
                       worker->quit();
                       worker->wait();
                       worker->deleteLater();
                       ConnectBtn->setEnabled(true);
                       QMessageBox::information(this,"消息","文件接收完毕");
              });
      });
}

