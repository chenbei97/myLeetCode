#include "rollDiceThread.h"
#include <QWaitCondition>
#include <QTime>
#include <QMutex>
#include <QDebug>

QMutex  mutex; // 全局互斥量
QWaitCondition  newdataAvailable; // 全局等待条件变量(读取的数据是否有效)
// 生产者模型中,有了新数据后要唤醒其他所有线程(发布条件满足通知)
// 消费者模型中,要等待条件满足通知,接收到信号后就可以读取数据了

int     frequency;//掷骰子的次数累计
int     diceValue; // 骰子点数

// （1）生产者模型
QThreadProducer::QThreadProducer()
{

}

void QThreadProducer::run()
{
    this->stopdice=false;//启动线程时令m_stop=false
    frequency=-1; // 启动线程时就初始化全局掷骰子总次数为-1
    // (不知道为啥初始化为0的话frequency第1次传播出去的时候变成了2)
    // 从测试结果来看now fre =  -1; now fre =  0连续执行了2次,也就是now fre =  -1;时消费者模型没有读取到这个数据
    qsrand(QTime::currentTime().msec());//随机数初始化，qsrand是线程安全的

    while(!stopdice)//循环主体
    {
        mutex.lock();
        diceValue=qrand(); //获取随机数
        diceValue=(diceValue % 6)+1;
        qDebug()<<"now fre = "<<frequency;
        frequency++; // 掷骰子次数增加
        mutex.unlock();

        newdataAvailable.wakeAll();// 唤醒所有线程,有新数据了,给所有线程发布通知
        msleep(100); //线程休眠100ms
    }
}

void QThreadProducer::stopDice()
{
    // 停止掷骰子
    QMutexLocker  locker(&mutex);
    this->stopdice=true;
}

// （2）消费者模型
QThreadConsumer::QThreadConsumer()
{

}

void QThreadConsumer::run()
{
    this->stopread=false;// 读取数据的线程
    while(!stopread)//循环主体
    {
        mutex.lock(); // 先锁定
        // 然后wait内部会先解锁使其可被生产者模型使用,然后等待通知,处于阻塞状态
        newdataAvailable.wait(&mutex);// 当生产者模型有了数据就会发布通知,wait内部就会锁定这个互斥量先执行后续语句读取这个数据
        qDebug()<<frequency<<" "<<diceValue;
        emit    readDiceValue(frequency,diceValue); // 把此时的数据传播出去
        mutex.unlock(); // 然后再次解锁,这样生产者模型就能再次使用互斥量,再次发布新数据,如此反复
        // msleep(100); //线程休眠100ms
    }
}

void QThreadConsumer::stopRead()
{
    QMutexLocker  locker(&mutex);
    this->stopread=true;
}
