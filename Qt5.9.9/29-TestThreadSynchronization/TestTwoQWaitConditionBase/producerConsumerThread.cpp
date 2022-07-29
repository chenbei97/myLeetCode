#include "producerConsumerThread.h"
#include <QTime>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

// DataSize 是生产者将生成的数据量
const int DataSize = 1000; // 最大数据大小
// BufferSize 是循环缓冲区的大小,它小于 DataSize
const int BufferSize = 900; // 缓冲大小
// 生产者到达缓冲区的末尾时会从头开始重新启动
char buffer[BufferSize]; // 全局缓存

//为了同步生产者和消费者,我们需要两个等待条件和一个互斥锁
QMutex mutex;
// 当生产者生成一些数据时,会发出bufferNotEmpty条件,告诉消费者它可以开始读取它
QWaitCondition bufferNotEmpty; // 全局条件变量：缓存不为空（生产者负责发布，消费者负责等待）
// 当消费者读取了一些数据时，会发出 bufferNotFull 条件，告诉生产者它可以生成更多数据
QWaitCondition bufferNotFull;// 全局条件变量：缓存不为满（消费者负责发布，生产者负责等待）
// numUsedBytes 是缓冲区中当前包含数据的字节数
int numUsedBytes = 0;

// 等待条件、互斥体和 numUsedBytes 计数器一起确保生产者永远不会在缓存区满时还继续生产数据
// 并且消费者永远不会读取生产者尚未生成的数据

// （1）生产者模型
Producer::Producer(QObject *parent) : QThread(parent)
{
}
void Producer::run()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < DataSize; ++i) {
        mutex.lock();
        if (numUsedBytes == BufferSize) // 如果缓存满了不能再写入数据必须先等待读取
        {
            qDebug()<<"缓冲区已满,新的一轮开始!";
            bufferNotFull.wait(&mutex); // 这里阻塞,等待消费者读取后通知的bufferNotFull信号
        }

        mutex.unlock();// 生产者接收到才会解锁执行后边的代码继续生产数据

        // i % BufferSize可以保证没存满之前都会按照顺序依次存取,一旦i=BufferSize就会从头覆盖数据
        buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4]; // "ACGT"随机选择1个字母存进去
        emit stringProduced(QString(buffer[i % BufferSize]));
        mutex.lock();
        ++numUsedBytes; // 写入数据,计数器++
        bufferNotEmpty.wakeAll(); // 生产者需要发布buffer不为空通知以便于消费者接收到才会读取有效的数据
        mutex.unlock();

        msleep(100);
    }
}

// （2）消费者模型
Consumer::Consumer(QObject *parent) : QThread(parent)
{
}
void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        mutex.lock();
        if (numUsedBytes == 0) // 如果缓存区没有数据就不要继续读取
        {
            qDebug()<<"缓冲区已空,等待数据生产!";
            bufferNotEmpty.wait(&mutex); // 这里阻塞线程,等待生产者发布缓冲区不为空的信号
        }
        mutex.unlock(); // 接收到信号以后消费者才会继续读取数据
        fprintf(stderr, "%c", buffer[i % BufferSize]);
        emit stringConsumed(QString(buffer[i % BufferSize]));
        mutex.lock();
        --numUsedBytes; // 读取数据,计数器--
        bufferNotFull.wakeAll();  // 消费者需要发布buffer不为满通知以便于生产者接收到才会继续生产数据
        mutex.unlock();
        msleep(200);
    }
    fprintf(stderr, "\n");
}
