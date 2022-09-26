#include "filesend.h"
#include "ui_filesend.h"

FileSend::FileSend(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::FileSend)
{
      ui->setupUi(this);
      myTcpSrv = new QTcpServer(this);
      mySrvPort = 5555;
      connect(myTcpSrv,&QTcpServer::newConnection,this,&FileSend::sendChatMsg);
      myTcpSrv->close();
      myTotalBytes = 0;
      mySendBytes = 0;
      myBytesTobeSend = 0;
      myPayloadSize = 64 * 1024;
      ui->sendProgressBar->reset();
      ui->openFilePushButton->setEnabled(true);
      ui->sendFilePushButton->setEnabled(false);

      connect(ui->openFilePushButton,&QPushButton::clicked,this,[=]{
          myPathFile = QFileDialog::getOpenFileName(this);
          if(!myPathFile.isEmpty())
          {
              myFileName = myPathFile.right(myPathFile.size() - myPathFile.lastIndexOf('/') - 1);
              ui->sfileNameLineEdit->setText(tr("%1").arg(myFileName));
              ui->sendFilePushButton->setEnabled(true);
              ui->openFilePushButton->setEnabled(false);
          }
      });

      connect(ui->sendFilePushButton,&QPushButton::clicked,this,[=]{
          if(!myTcpSrv->listen(QHostAddress::Any, mySrvPort))//开始监听
          {
              QMessageBox::warning(0, QObject::tr("异常"), "打开TCP端口出错,请检查网络连接！");
              close();
              return;
          }
          emit sendFileName(myFileName);
      });

      connect(ui->srvClosePushButton,&QPushButton::clicked,this,[=]{
          if(myTcpSrv->isListening())
          {
              myTcpSrv->close();
              myLocPathFile->close();
              mySrvSocket->abort();
          }
          close();
      });
}

void FileSend::closeEvent(QCloseEvent *e)
{
      ui->srvClosePushButton->click();
      e->accept();
}

void FileSend::sendRefused()
{
    myTcpSrv->close();
    QMessageBox::warning(0, QObject::tr("提示"), "对方拒绝接收!");
}

void FileSend::sendChatMsg()
{
    ui->sendFilePushButton->setEnabled(false);
    mySrvSocket = myTcpSrv->nextPendingConnection();
    connect(mySrvSocket,&QTcpSocket::bytesWritten,this,&FileSend::onBytesWritten);
    myLocPathFile = new QFile(myPathFile);
    myLocPathFile->open((QFile::ReadOnly));
    myTotalBytes = myLocPathFile->size();
    QDataStream sendOut(&myOutputBlock, QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_9);
    mytime.start();  // 开始计时
    QString curFile = myPathFile.right(myPathFile.size() - myPathFile.lastIndexOf('/') - 1);
    sendOut << qint64(0) << qint64(0) << curFile;
    myTotalBytes += myOutputBlock.size();
    sendOut.device()->seek(0);
    sendOut << myTotalBytes << qint64((myOutputBlock.size() - sizeof(qint64) * 2));
    myBytesTobeSend = myTotalBytes - mySrvSocket->write(myOutputBlock);
    myOutputBlock.resize(0);
}

void FileSend::onBytesWritten(qint64 size)
{
    qApp->processEvents();
    mySendBytes += (int)size;
    if (myBytesTobeSend > 0)
    {
        myOutputBlock = myLocPathFile->read(qMin(myBytesTobeSend, myPayloadSize));
        myBytesTobeSend -= (int)mySrvSocket->write(myOutputBlock);
        myOutputBlock.resize(0);
    } else {
        myLocPathFile->close();
    }
    ui->sendProgressBar->setMaximum(myTotalBytes);
    ui->sendProgressBar->setValue(mySendBytes);
    ui->sfileSizeLineEdit->setText(tr("%1").arg(myTotalBytes / (1024 * 1024)) + " MB");
    ui->sendSizeLineEdit->setText(tr("%1").arg(mySendBytes / (1024 * 1024)) + " MB");
    if(mySendBytes == myTotalBytes)
    {
        myLocPathFile->close();
        myTcpSrv->close();
        QMessageBox::information(0, QObject::tr("完毕"), "文件传输完成！");
    }
}
