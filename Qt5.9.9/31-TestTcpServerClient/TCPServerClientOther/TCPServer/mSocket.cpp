#include "mSocket.h"

mSocket::mSocket(QObject * parent)
{
    Q_UNUSED(parent);
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(unConnected()));//注意这里连接的是继承的无参数信号
}

void mSocket::dataReceived()
{// 套接字拿到数据就取出来发送给外部,这部分程序本应在TCPServer中编写,在这里编写好以后
// TCPServer就可以直接拿到msg和length,无需再使用while+read读取数据
    while (this->bytesAvailable()) // 数据有效
    {
        qint64 length = bytesAvailable(); // 有效的字节数
        char buf[1024];
        this->read(buf,length);
        QByteArray bytes = buf;
        QString msg = QString::fromLocal8Bit(bytes.left(length)); // 有效的数据长度
        emit sendMessage(msg,length); // 把得到的数据和数据长度信息发送出去
    }
}

void mSocket::unConnected()
{
    // disconnected信号做了一层封装是为了把套接字描述符信息带出去
    emit disconnected(this->socketDescriptor());
}
