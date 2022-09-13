#ifndef NEWTCPSERVER_H
#define NEWTCPSERVER_H

#include <QTcpServer>

class NewTcpServer : public QTcpServer // 解决nextPendingConnection返回的套接字指针不能在子线程工作的处理方法
{
  Q_OBJECT
public:
  explicit  NewTcpServer(QObject * parent);
protected:
  void incomingConnection(qintptr handle) override;
signals:
  void newDescriptor(qintptr descriptor);
};

#endif // NEWTCPSERVER_H
