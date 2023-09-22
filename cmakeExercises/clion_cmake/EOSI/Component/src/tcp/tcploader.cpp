#include "../../inc/tcp/tcploader.h"

TcpLoader& TcpLoader::instance()
{
    static TcpLoader instance;
    return instance;
}

TcpLoader::TcpLoader(QObject*parent):QObject(parent)
{
    mSocket = new TcpSocket(this);
}

void TcpLoader::connectToHost(const QString &ip, quint16 port, QIODevice::OpenMode openMode)
{
    if (isConnected()) return;
    mSocket->connectToHost(ip,port,openMode);
}

void TcpLoader::disconnectFromHost()
{
    mSocket->disconnectFromHost();
}

bool TcpLoader::waitForConnected(int msecs)
{
    return mSocket->waitForConnected(msecs);
}

bool TcpLoader::isConnected() const
{ // 套接字是否已连接
    return mSocket->isConnected();
}

QString TcpLoader::lastError() const
{
    return mSocket->lastError();
}
