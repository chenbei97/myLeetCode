#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
protected:
    void run() override;
signals:
    void resultReady(const QString &s);
};

#endif // MYTHREAD_H
