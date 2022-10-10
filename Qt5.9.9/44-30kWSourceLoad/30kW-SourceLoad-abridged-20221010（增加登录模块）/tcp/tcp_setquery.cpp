#include <tcp/tcp_setquery.h>

TcpSetQuery::TcpSetQuery(QTcpSocket * socket,QObject * parent):QObject(parent)
          ,mSocket(socket)
{
       // 套接字资源只有1个，一般来说套接字应当是已连接的状态
}

void TcpSetQuery::setVariable(SETTINGVARIABLE role,const QByteArray& value)
{
       if (!mSocket->isOpen()) return;// 如果真的因为某些原因是没打开的状态
       QByteArray c = getSetQueryCommand(role,value);
       QMutexLocker locker(&mMutex);
       mSocket->write(c);
}
