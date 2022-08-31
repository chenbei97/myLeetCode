#ifndef TIMERSERVER_H
#define TIMERSERVER_H

#include <QtNetwork/QTcpServer>
#include "timerThread.h"
class Server; // 不能在"timerServer.h"中引入"server.h","server.h"引入"timerServer.h",这样造成相互包含会有问题

class TimerServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TimerServer(QObject * parent=Q_NULLPTR);
protected:
     void incomingConnection(qintptr socketDescriptor) override;
private:
      Server * mServer;
};

#endif // TIMERSERVER_H
