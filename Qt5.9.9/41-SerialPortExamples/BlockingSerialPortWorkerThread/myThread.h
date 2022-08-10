#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
class myThread : public QThread
{
  Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);
    ~myThread();
    void transaction(const QString &portName, int waitTimeout, const QString &request);
    void run() Q_DECL_OVERRIDE;
signals:
    void response(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);
private:
    QString portName;
    QString request;
    int waitTimeout;
    QMutex mutex;
    QWaitCondition cond;
    bool quit;
};

#endif // MYTHREAD_H
