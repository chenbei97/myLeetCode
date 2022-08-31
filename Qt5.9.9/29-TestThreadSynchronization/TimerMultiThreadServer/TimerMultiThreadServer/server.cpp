#include "server.h"
#include "timerServer.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

Server::Server(QWidget *parent)
  : QDialog(parent)
  , mTcpServer(new TimerServer(this)) //一定要指定this,TimerServer内部才能得到Server的指针
  , portID(new QLabel("服务器端口："))
  , requestCount(0)
  , requestCountLabel(new QLabel(tr("请求次数：%1").arg(requestCount)))
  , quitBtn(new QPushButton("退出"))

{
      setWindowTitle("多线程时间服务器");
      setFont(QFont("Times New Roman",12));
      resize(250,120);

      QHBoxLayout * BtnLayout = new QHBoxLayout;
      BtnLayout->addStretch(1);
      BtnLayout->addWidget(quitBtn);
      BtnLayout->addStretch(1);

      QVBoxLayout * mainLayout = new QVBoxLayout;
      mainLayout->addWidget(portID);
      mainLayout->addWidget(requestCountLabel);
      mainLayout->addLayout(BtnLayout);
      this->setLayout(mainLayout);

      connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));

      if (!mTcpServer->listen()) // 如果服务器没有处于监听
      {
            QMessageBox::critical(this,tr("错误"),tr("无法启动服务器：%1").arg(mTcpServer->errorString()));//响应了mTcpServer内部线程发射的错误信号
            close();
            return;
      }
      portID->setText(tr("服务器端口：%1").arg(mTcpServer->serverPort()));//把端口号写进去(自动分配的)
}

void Server::on_threadSignals()
{
      requestCountLabel->setText(tr("请求次数：%1").arg(++requestCount));
}

