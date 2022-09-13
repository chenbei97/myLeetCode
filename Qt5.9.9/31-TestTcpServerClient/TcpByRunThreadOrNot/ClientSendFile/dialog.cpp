#include "dialog.h"
#include "sendfile.h"
#include <QThread>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
  : QDialog(parent)
  , mainLayout(new QGridLayout(this))
  , PortLabel(new QLabel("端口："))
  , PortEdit(new QLineEdit("8899"))
  , IPLabel(new QLabel("地址："))
  , IPEdit(new QLineEdit("127.0.0.1"))
  , SelectFileEdit(new QLineEdit)
  , SelectFileBtn(new QPushButton("选择文件"))
  , PBar(new QProgressBar)
  , ConnectBtn(new QPushButton("开始连接"))
  , SendFileBtn(new QPushButton("发送文件"))
{
       qDebug()<<"客户端线程地址："<<QThread::currentThread();
      resize(400,250);
      setFont(QFont("Times New Roman",12));
      PBar->setFixedSize(370,30);
      PBar->setValue(0);
      PBar->setRange(0,100);
      SendFileBtn->setEnabled(false); // 先选择文件才能发送文件

      mainLayout->addWidget(PortLabel,0,0);
      mainLayout->addWidget(PortEdit,0,1);
      mainLayout->addWidget(IPLabel,1,0);
      mainLayout->addWidget(IPEdit,1,1);
      mainLayout->addWidget(SelectFileEdit,2,0);
      mainLayout->addWidget(SelectFileBtn,2,1);
      mainLayout->addWidget(PBar,3,0,1,2);
      mainLayout->addWidget(ConnectBtn,4,1);
      mainLayout->addWidget(SendFileBtn,4,0);

      // 创建线程对象
      QThread * t = new QThread;
      // 创建工作任务对象(发送文件)
      SendFile * worker = new SendFile;
      // 让任务在子线程执行
      worker->moveToThread(t);

      connect(this,&Dialog::readyConnect,worker,&SendFile::connectHost); // 主线程=>工作线程(开始连接)
      connect(this,&Dialog::sendFile,worker,&SendFile::sendFile); // 主线程=>工作线程(开始发送文件)

      connect(worker,&SendFile::connected,this,[=]{ // 工作线程=> 主线程(已经连接成功)
            QMessageBox::information(this,"消息","服务器已经连接成功");
            SendFileBtn->setEnabled(true); // 连接成功是充要条件
            ConnectBtn->setEnabled(false);
      });
      connect(worker,&SendFile::disconnected,this,[=]{ // 工作线程=> 主线程(任务执行完毕,断开连接)
              t->quit();
              t->wait();
              worker->deleteLater();
              t->deleteLater();
              SendFileBtn->setEnabled(false); // 结束连接后恢复禁用
              ConnectBtn->setEnabled(true);
      });
//      connect(worker,static_cast<void (SendFile::*)(int)>(&SendFile::sendPercentProgress),this,[=](int percent){
//              PBar->setValue(percent);
//      });
      connect(worker,&SendFile::sendPercentProgress,PBar,&QProgressBar::setValue); //这样更简洁

      connect(ConnectBtn,&QPushButton::clicked,this,[=]{
            QString ip = IPEdit->text();
            ushort port = PortEdit->text().toUShort();
            //worker->connectHost(ip,port); // 任务对象提供公共函数给这里使用,让主程序控制启动
            // 或者再加一层抽象,主程序提供1个信号,而这个信号事先已经绑定好任务对象的公共函数也可
            emit readyConnect(ip,port);
            t->start();
      });

      connect(SendFileBtn,&QPushButton::clicked,this,[=]{
             QString path = SelectFileEdit->text();
             emit sendFile(path);
      });

      connect(SelectFileBtn,&QPushButton::clicked,this,[=]{
            QDir curpath = QDir::current(); // exe路径
            curpath.cdUp(); // 回到上一级,也就是工作代码的路径
            QString path = QFileDialog::getOpenFileName(this,"选择1个文件",curpath.path(),
                                                      "C++文件(*.h *cpp);;文本文件(*.txt);;所有文件(*.*)");
            if (!path.isEmpty())
            {
                SelectFileEdit->setText(path);
                // SendFileBtn->setEnabled(true); // 选择以后能发送是必要条件而不是充分条件
            }
      });

}


