#ifndef CONTROLLWORKERTHREAD_H
#define CONTROLLWORKERTHREAD_H

#include <QObject>
#include <QThread>
class controllWorker:public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    controllWorker();
    ~controllWorker(){
        workerThread.quit(); // 控制器的析构函数控制线程停止和无限期等待
        workerThread.wait();
    }
    void start();
    void stop();
public slots:
    void handleReady(const QString&result);
signals:
    void operate(int select);
    void handleResult(const QString&result);
};

#endif // CONTROLLWORKERTHREAD_H
