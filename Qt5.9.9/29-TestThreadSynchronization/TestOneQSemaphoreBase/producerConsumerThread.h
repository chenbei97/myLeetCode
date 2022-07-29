#ifndef PRODUCERCONSUMERTHREAD_H
#define PRODUCERCONSUMERTHREAD_H
#include <QThread>
// （1）生产者模型
class Producer : public QThread
{
    Q_OBJECT
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    void stopProduce();
private:
    bool isProduce;
};
// （2）消费者模型
class Consumer : public QThread
{
    Q_OBJECT
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    void stopConsume();
private:
    bool isConsumed;
signals:
    void  newValue(int *data,int count, int bufId);
};
#endif // PRODUCERCONSUMERTHREAD_H
