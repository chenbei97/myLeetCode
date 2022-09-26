#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      setFont(QFont("Times New Roman",12));
      init();

}

void MainWindow::closeEvent(QCloseEvent *e)
{
    chatLine(OffLine);
    e->accept();
}

void MainWindow::init()
{
    mUdpSocket = new QUdpSocket(this);
    mUdpPort = 23232; // 指定绑定模式
    mUdpSocket->bind(mUdpPort, QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

    // 套接字信号
    connect(mUdpSocket, &QUdpSocket::readyRead,this,&MainWindow::recvAndProcessChatMsg);
    mFileSend = new FileSend(this);

    // 发送文件的信号
    connect(mFileSend, &FileSend::sendFileName, this, [=](QString name){
            mFileName = name;
            int row = ui->userListTableWidget->currentRow();
            QString rmtName = ui->userListTableWidget->item(row, 0)->text();
            chatLine(FileName,rmtName);
    });

    // 搜索消息按钮
    connect(ui->searchPushButton,&QPushButton::clicked,this,[=]{
          mName = this->windowTitle();
          ui->userLabel->setText(mName);
          chatLine(OnLine); // 上线的消息
    });

    // 发送消息按钮
    connect(ui->sendPushButton,&QPushButton::clicked,this,[=]{
          chatLine(ChatLine);
    });

    // 传输文件按钮
    connect(ui->transPushButton,&QPushButton::clicked,this,[=]{
          if (ui->userListTableWidget->selectedItems().isEmpty())
          {
                QMessageBox::warning(0, tr("选择好友"), tr("请先选择文件接收方！"), QMessageBox::Ok);
                return;
          }
          mFileSend->show();
    });
}
