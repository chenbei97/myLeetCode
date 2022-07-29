#ifndef ROLLDICETHREAD_H
#define ROLLDICETHREAD_H
#include <QThread>
 // 使用生产者-消费者模型

// 专门用于生成骰子点数的线程
class QThreadProducer : public QThread
{
    Q_OBJECT
private:
    bool    stopdice=false; //停止线程
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    QThreadProducer();
    void    stopDice();
};

// 专门用于读取骰子点数的线程
class QThreadConsumer : public QThread
{
    Q_OBJECT
private:
    bool    stopread=false; //停止线程
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    QThreadConsumer();
    void    stopRead();
signals:
    void    readDiceValue(int frequency,int diceValue);
};
#endif // ROLLDICETHREAD_H
