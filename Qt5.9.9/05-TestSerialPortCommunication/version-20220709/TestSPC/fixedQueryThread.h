#ifndef FIXEDQUERYTHREAD_H
#define FIXEDQUERYTHREAD_H
#include <QObject>
#include <QThread>
#include <QString>
#include <QMutex>
#include <QMutexLocker>
class fixedQueryThread : public QThread
{
  Q_OBJECT
public:
  fixedQueryThread();
  void startQuery();
  void stopQuery();
protected:
  void run() Q_DECL_OVERRIDE;
private:
   bool _stop ; // 线程停止标志位
   QString command;
   QMutex mutex;
   const static int flush_time = 300;
signals:
  void sendCommand(QString command); // 产生新命令的信号
};

#endif // FIXEDQUERYTHREAD_H
