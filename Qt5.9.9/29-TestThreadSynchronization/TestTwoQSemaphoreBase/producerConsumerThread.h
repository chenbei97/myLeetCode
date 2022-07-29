#ifndef PRODUCERCONSUMERTHREAD_H
#define PRODUCERCONSUMERTHREAD_H
#include <QThread>

class Producer : public QThread
{
    Q_OBJECT
public:
    void run() override;
signals:
    void stringProduced(const QString &text);
};

class Consumer : public QThread
 {
     Q_OBJECT
 public:
     void run() override;
 signals:
     void stringConsumed(const QString &text);
 protected:
     bool finish;
 };
#endif // PRODUCERCONSUMERTHREAD_H
