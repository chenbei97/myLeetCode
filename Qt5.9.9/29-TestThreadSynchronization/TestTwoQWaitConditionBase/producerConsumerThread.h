#ifndef PRODUCERCONSUMERTHREAD_H
#define PRODUCERCONSUMERTHREAD_H
#include <QThread>

class Producer : public QThread
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = nullptr);
protected:
    void run() override;
signals:
    void stringProduced(const QString &text);
};

class Consumer : public QThread
 {
     Q_OBJECT
 public:
     explicit Consumer(QObject *parent = nullptr);
protected:
     void run() override;
 signals:
     void stringConsumed(const QString &text);
 };
#endif // PRODUCERCONSUMERTHREAD_H
