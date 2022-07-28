#ifndef SAVETHREAD_H
#define SAVETHREAD_H

#include <QThread>
#include <QMutex>
#include <QReadWriteLock>
#include <QQueue>
#include <QReadLocker>

class saveThread : public QThread
{
    Q_OBJECT
public:
    saveThread();
    void stopSave();
    void reset();
protected:
    void run() override;
signals:
    void saveValue(int ret);
private:
    bool isSave;
    int pos;
};

#endif // SAVETHREAD_H
