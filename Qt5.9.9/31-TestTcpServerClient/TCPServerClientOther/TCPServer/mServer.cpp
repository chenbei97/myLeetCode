#include "mServer.h"

mServer::mServer(QObject * parent, int port) : QTcpServer(parent)
{
    this->listen(QHostAddress::Any,port);//监听指定端口下任何类型的地址
}

void mServer::incomingConnection(int descriptor)
{
    // 这个虚函数重写时必须要做4件事
    // 1.新连接到来时创建一个新的对等套接字和客户端通信
    // 2. 设置套接字描述符descriptor
    // 3. 把新创建的套接字放入套接字列表进行管理
    // 4. 发出newConnection信号
    // 5. 然后再定义服务器的其他需求
    mSocket * socket = new mSocket; // 1.
    socket->setSocketDescriptor(descriptor); // 2.
    mSocketList.append(socket); //3.
    emit newConnection(); // 4.
    // 5.其他需求就是作了本该QTCPServer的事情
    // 5.1 服务器拿到信息以后进行广播,这样所有的客户端都能收到这个消息
    connect(socket,SIGNAL(sendMessage(QString,qint64)),this,SLOT(updateClient(QString,qint64)));
    // 5.2 服务器如果断开了连接
    connect(socket,SIGNAL(disconnected(int)),this,SLOT(unConnected(int)));
}

void mServer::updateClient(QString msg , qint64 length)
{
      // 将任意客户端发来的信息进行广播,这样聊天室所有成员都可以看到其他人的发言
      emit updateServer(msg,length); //这是为了让TCPServer拿到,因为套接字拿到了信息在sendMessage这里,它绑定在本函数中再转发出去
      for (int i = 0; i < mSocketList.count(); ++i)
      {
           mSocket * socket = mSocketList.at(i);
           if (socket->write(msg.toLocal8Bit(),length)!=length) // 给每个客户端的套接字发送消息
           {
               continue;
           }
      }
}

void mServer::unConnected(int descriptor)
{
      for (int i = 0; i < mSocketList.count(); ++i)
      {
              mSocket * socket = mSocketList.at(i);
              if (socket->socketDescriptor() == descriptor)
              {
                      mSocketList.removeAt(i); // 清理客户端套接字列表的工作
                      return;
              }
      }
}
