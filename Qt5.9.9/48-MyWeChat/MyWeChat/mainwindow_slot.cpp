#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::recvAndProcessChatMsg()
{
    while (mUdpSocket->hasPendingDatagrams())
    {
        QByteArray qba;
        qba.resize(mUdpSocket->pendingDatagramSize());
        mUdpSocket->readDatagram(qba.data(), qba.size());
        QDataStream read(&qba, QIODevice::ReadOnly);
        int msgType;
        read >> msgType;
        QString name, hostip, chatmsg, rname, fname;
        QString curtime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch (msgType)
        {
        case ChatLine: {
            read >> name >> hostip >> chatmsg;
            ui->chatTextBrowser->setTextColor(Qt::darkGreen);
            ui->chatTextBrowser->setCurrentFont(QFont("Times New Roman", 14));
            ui->chatTextBrowser->append("【" + name + "】" + curtime);
            ui->chatTextBrowser->append(chatmsg);
            break;
        }
        case OnLine:
            read >> name >> hostip;
            onLine(name, curtime);
            break;
        case OffLine:
            read >> name;
            offLine(name, curtime);
            break;
        case FileName:
            read >> name >> hostip >> rname >> fname;
            recvFileName(name, hostip, rname, fname);
            break;
        case Refuse:
            read >> name >> hostip >> rname;
            if (mName == rname) mFileSend->sendRefused();
            break;
        }
    }
}

void MainWindow::chatLine(ChatMsgType type, QString name)
{
    QByteArray qba;
    QDataStream write(&qba, QIODevice::WriteOnly);
    QString locHostIp = getLocalHostIP();
    QString locChatMsg = getLocalMsg();
    write << type << mName;
    switch (type)
    {
          case ChatLine:
              write << locHostIp << locChatMsg;
              break;
          case OnLine:
              write << locHostIp;
              break;
          case OffLine:
              break;
          case FileName:
              write << locHostIp << name << mFileName;
              break;
          case Refuse:
              write << locHostIp <<mName;
              break;
    }
    mUdpSocket->writeDatagram(qba, qba.length(), QHostAddress::Broadcast, mUdpPort);
}
