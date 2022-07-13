#ifndef THREADFACTORY_H
#define THREADFACTORY_H
#include <QThread>
#include <QList>
#include <QObject>
class threadFactory :public QObject
{
    Q_OBJECT
public:
  threadFactory();
  ~threadFactory();
  static QThread *  createThread(QThread::Priority priority = QThread::Priority::InheritPriority);
private:
  static QList<QThread*> threads;
};
#endif // THREADFACTORY_H
