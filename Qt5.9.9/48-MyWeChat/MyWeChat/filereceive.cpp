#include "filereceive.h"
#include "ui_filereceive.h"

FileReceive::FileReceive(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::FileReceive)
{
        ui->setupUi(this);
        myCntSocket = new QTcpSocket(this);
        mySrvPort = 5555;
        connect(myCntSocket, &QTcpSocket::readyRead, this,&FileReceive::readChatMsg);
        myFileNameSize = 0;
        myTotalBytes = 0;
        myRcvedBytes = 0;
        connect(ui->cntClosePushButton,&QPushButton::clicked,this,[=]{
            myCntSocket->abort();
            myLocPathFile->close();
            close();
        });
}

void FileReceive::getLocalPath(QString path)
{
    myLocPathFile = new QFile(path);
}

void FileReceive::getReceiveAddr(QHostAddress saddr)
{
    mySrvAddr = saddr;
    myBlockSize = 0;
    myCntSocket->abort();
    myCntSocket->connectToHost(mySrvAddr, mySrvPort);
    mytime.start();
}

void FileReceive::readChatMsg()
{
    QDataStream in(myCntSocket);
    in.setVersion(QDataStream::Qt_5_9);
    float usedTime = mytime.elapsed();
    if (myRcvedBytes <= sizeof(qint64)*2)
    {
        if ((myCntSocket->bytesAvailable() >= sizeof(qint64)*2) && (myFileNameSize == 0))
        {
            in >> myTotalBytes >> myFileNameSize;
            myRcvedBytes += sizeof(qint64)*2;
        }
        if ((myCntSocket->bytesAvailable() >= myFileNameSize) && (myFileNameSize != 0))
        {
            in >> myFileName;
            myRcvedBytes += myFileNameSize;
            myLocPathFile->open(QFile::WriteOnly);
            ui->rfileNameLineEdit->setText(myFileName);
        } else {
            return;
        }
    }
    if (myRcvedBytes < myTotalBytes)
    {
        myRcvedBytes += myCntSocket->bytesAvailable();
        myInputBlock = myCntSocket->readAll();
        myLocPathFile->write(myInputBlock);
        myInputBlock.resize(0);
    }
    ui->recvProgressBar->setMaximum(myTotalBytes);
    ui->recvProgressBar->setValue(myRcvedBytes);
    double transpeed = myRcvedBytes / usedTime;
    ui->rfileSizeLineEdit->setText(tr("%1").arg(myTotalBytes / (1024 * 1024)) + " MB");
    ui->recvSizeLineEdit->setText(tr("%1").arg(myRcvedBytes / (1024 * 1024)) + " MB");
    ui->rateLabel->setText(tr("%1").arg(transpeed * 1000 / (1024 * 1024), 0, 'f', 2) + " MB/秒");
    if (myRcvedBytes == myTotalBytes)
    {
        myLocPathFile->close();
        myCntSocket->close();
        ui->rateLabel->setText("接收完毕！");
    }
}
void FileReceive::closeEvent(QCloseEvent * e)
{
    myCntSocket->abort();
    myLocPathFile->close();
    this->close();
}
