#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QThread>
#include <QMutex>
#include <QReadWriteLock>
#include <QQueue>
#include <QTime>
#include <QWriteLocker>

class writeThread : public QThread
{
    Q_OBJECT
public:
    writeThread();
    void stopWrite();
    void reset();
protected:
    void run() override;
private:
    bool isWrite;
};

#endif // WRITETHREAD_H
