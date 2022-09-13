#include "newreceivefile.h"
#include <QFile>
#include <QDebug>

NewReceiveFile::NewReceiveFile(qintptr descriptor,QObject * parent ):QThread(parent)
, mTcpSocket(new QTcpSocket(this))//传递套接字描述符的方法,那么这里不再是用传递来的套接字指针初始化而是内部直接新建1个
{
      mTcpSocket->setSocketDescriptor(descriptor); // 只是把套接字描述符从主线程拿到,而主线程是通过NewTcpServer的信号newDescriptor拿到的信号参数
      // 而NewTcpServer的信号newDescriptor会在新连接到来后发射，也就是重载了incommingConnection函数
}

void NewReceiveFile::run()
{
      qDebug()<<"接收文件线程地址："<<QThread::currentThread();
      QFile  * file = new QFile("test.txt"); // 会自动写入到exe目录的同级test.txt文件
      file->open(QIODevice::WriteOnly);

      // 接收数据
      connect(mTcpSocket,&QTcpSocket::readyRead,this, [=]{ // 服务器接收数据
           static int hasReceiveSize = 0; // 已接收的大小
           static int total = 0; // 总的大小在第一次接收时拿到发送的4字节数据
           if (hasReceiveSize == 0)
           {
               mTcpSocket->read((char*)&total,4); // 只读取4个字节
               qDebug()<<"total = "<<total;
           }
           // 剩下的数据就是纯文本数据
           QByteArray  data = mTcpSocket->readAll();
           hasReceiveSize += data.size();
           file->write(data);
           // 如果数据接收完毕
           if (total == hasReceiveSize)
           {
                mTcpSocket->close(); // 套接字的关闭、删除操作只能在工作线程执行
                mTcpSocket->deleteLater();
                file->close();
                file->deleteLater();
                emit receiveEnd(); // 通知主线程
           }
      });

      // 不过上边的函数未必能执行(只有客户端已经发送文件),所以如果不执行就要先进入事件循环
      exec(); // 不能直接退出
}
