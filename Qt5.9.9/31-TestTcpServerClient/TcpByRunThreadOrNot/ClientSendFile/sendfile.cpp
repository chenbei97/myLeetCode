#include "sendfile.h"
#include <QFile>
#include <QFileInfo>
#include <QThread>
#include <QDebug>

SendFile::SendFile(QObject *parent) : QObject(parent)
{

}

void SendFile::connectHost(QString ip, ushort port)
{
        mTcpSocket = new QTcpSocket;
        mTcpSocket->connectToHost(ip,port);
        connect(mTcpSocket,&QTcpSocket::connected,this,&SendFile::connected); // 信号连接信号,这个信号通知主程序连接成功
        connect(mTcpSocket,&QTcpSocket::disconnected,this,[=]{ // 信号断开
              mTcpSocket->close(); // 清除资源
              mTcpSocket->deleteLater();
              emit disconnected(); // 并通知主程序连接关闭
        });
}

void SendFile::sendFile(QString filepath)
{
      qDebug()<<"发送文件线程地址："<<QThread::currentThread();
      QFile  file(filepath);
      QFileInfo info(filepath);
      int filesize = info.size();

      if (!file.open(QIODevice::ReadOnly)) return;
      // 注意这里必须使用&地址符号否则会异常退出
      mTcpSocket->write((char*)&filesize,4); // 首先写入文件总大小这个4字节的数据目的是让服务器拿到后能够知道文件是否发送完毕
      while (!file.atEnd())
      {
            static int hasSendSize = 0;
            QByteArray line = file.readLine();
            mTcpSocket->write(line); // 发送给服务器
            hasSendSize += line.size(); // 已发送的大小
            int percent = hasSendSize / filesize * 100; // 百分比进度的方式发出
            emit sendPercentProgress(percent); // 主线程来接收这个信号,无需知道文件总大小
      }
}
