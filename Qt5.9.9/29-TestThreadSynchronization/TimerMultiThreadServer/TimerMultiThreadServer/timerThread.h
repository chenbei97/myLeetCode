#ifndef TIMERTHREAD_H
#define TIMERTHREAD_H

#include <QThread>
#include <QtNetwork/QTcpSocket>

class TimerThread : public QThread
{
      Q_OBJECT
public: // qintptr是指针类型,根据系统自动选择qint32*或者qint64*
      TimerThread(qintptr socketDescriptor, QObject * parent = Q_NULLPTR);
protected:
      void run() override;
signals:
      void error(QTcpSocket::SocketError socketError);
      void state(QTcpSocket::SocketState socketState);
private:
      qintptr mSocketDescriptor; // 套接字描述符
};

#endif // TIMERTHREAD_H
