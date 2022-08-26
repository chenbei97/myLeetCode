#ifndef MSERVER_H
#define MSERVER_H
// 用自定义的套接字继续定义自己的服务器
// 定义客户端套接字列表统一管理，这也本应是TCPServer应该做的事
#include <QTcpServer>
#include "mSocket.h"
class mServer : public QTcpServer
{
  Q_OBJECT
public:
   explicit mServer(QObject * parent, int port = 0);
   QList<mSocket*> mSocketList;
signals:
   void updateServer(QString msg, qint64 length); //这是为了把mServer内部mSocket拿到的信息转发出被TCPServer拿到,因为TCPServer无法直接从mSocket拿到
public slots:
   void updateClient(QString msg, qint64 length);
   void unConnected(int descriptor);
protected:
    void incomingConnection(int descriptor) override; //自定义服务器时需要重载的函数,对即将到来的客户端连接定义自己的处理方式
};

#endif // MSERVER_H
