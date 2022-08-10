#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
class clientThread : public QThread
{
      Q_OBJECT
public:
      explicit clientThread(QObject* parent = nullptr);
      ~clientThread();
      void startClientThread(const QString &portName, int waitTimeout, const QString &request);
      void run() Q_DECL_OVERRIDE;
signals:
      void response(const QString &s);
      void error(const QString &s);
      void timeout(const QString &s);
private:
      QString portName;//串口名称
      QString request; //客户端发给服务端的请求
      int waitTimeout;//等待服务端回复消息的允许超时时间
      QMutex mutex;
      QWaitCondition cond;
      bool quit;
};

#endif // CLIENTTHREAD_H
