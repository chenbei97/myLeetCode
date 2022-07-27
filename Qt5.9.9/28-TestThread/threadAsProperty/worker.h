#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker: public QObject
{
    Q_OBJECT
public:
    Worker();
public slots:
    void doWork(int select);
signals:
    void resultReady(const QString& result);
};

#endif // WORKER_H
