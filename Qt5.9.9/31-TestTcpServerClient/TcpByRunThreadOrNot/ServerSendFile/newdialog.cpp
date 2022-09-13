#include "newdialog.h"
#include <newreceivefile.h>
#include <QMessageBox>
#include <QDebug>

NewDialog::NewDialog(QWidget *parent)
  : QDialog(parent)
  , mainLayout(new QHBoxLayout(this))
  , PortLabel(new QLabel("端口："))
  , PortEdit(new QLineEdit("8899"))
  , ConnectBtn(new QPushButton("开始监听"))
  , mTcpServer(new NewTcpServer(this))
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

      // 此时不再使用newConnection,而是使用自己的信号
      connect(mTcpServer,&NewTcpServer::newDescriptor,this,[=](qintptr descriptor){
                NewReceiveFile * worker = new NewReceiveFile(descriptor);
              // 传递到子线程的方式有2种,第一种是信号槽,第二种是传参的方式(传参还可以直接传递指针,也可以只传递指针的必要参数也就是套接字描述符)
              // 如果传参使用传递指针的方式,要注意主线程不能对该套接字进行任何操作，例如开启和关闭，只能在工作线程来控制
              // 如果是传递套接字描述符的方法，需要重载服务器对象的函数mTcpServer->incomingConnection()

              // 这里演示第二种传参法,且是传递套接字描述符的方法，那么需要在NewReceiveFile构造函数使用qintptr参数
              // 同时自定义服务器对象newtcpserver
                worker->start();

                connect(worker,&NewReceiveFile::receiveEnd,this,[=]{ // 当工作任务退出后要释放工作线程对象
                         worker->quit();
                         worker->wait();
                         worker->deleteLater();
                         ConnectBtn->setEnabled(true);
                         QMessageBox::information(this,"消息","文件接收完毕");
                });
      });
}

