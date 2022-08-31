#include "timerThread.h"
#include <QDataStream>
#include <QDateTime>

TimerThread::TimerThread(qintptr socketDescriptor,QObject*parent):
    QThread(parent)
    , mSocketDescriptor(socketDescriptor)
{

}

void TimerThread::run()
{
      QTcpSocket  tcpsocket; // 网络通讯的中间人: 套接字
      if (!tcpsocket.setSocketDescriptor(mSocketDescriptor))
      {
            // 如果可用,则返回本机套接字描述符传递给mSocketDescriptor否则返回-1
            emit error(tcpsocket.error());
            emit state(tcpsocket.state());
            return;
      }
      QByteArray block;
      QDataStream out(&block,QIODevice::WriteOnly);
      out.setVersion(QDataStream::Qt_5_9);

      uint currenttime = QDateTime::currentDateTime().toTime_t();//将日期时间作为自协调世界时 (Qt::UTC) 1970-01-01T00:00:00 以来经过的秒数返回
      out<<currenttime; // 写入block
      tcpsocket.write(block); // 对客户端发回网络时间消息
      tcpsocket.disconnectFromHost(); // 服务端断开连接
      tcpsocket.waitForDisconnected();//等待客户端断开连接
}
