#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>
#include <QMutex>
#include <QReadWriteLock>
#include <QQueue>
#include <QReadLocker>

class readThread:public QThread
{
    Q_OBJECT
public:
    readThread();
    void stopRead();
    void reset();
protected:
    void run() override;
signals:
    void readValue(int ret);
private:
    bool isRead;
    int pos;
};

#endif // READTHREAD_H
