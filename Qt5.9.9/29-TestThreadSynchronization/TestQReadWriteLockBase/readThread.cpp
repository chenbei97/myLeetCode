#include "readThread.h"
#include <QDebug>

extern QQueue<int> buffer;
extern QReadWriteLock Lock; // 全局读写锁

// extern QMutex mutex ; // 全局互斥量
// 如果使用QMutex,任何时候只能有1个线程去持有它,如果是1个写线程和2个读线程
// 实际上2个读线程同时访问buffer是不会冲突的,如果使用QMutex2个读线程还需要排队,这样相当于互斥量降低了程序性能
//void readThread::run()
//{
//    mutex.lock();
//    while (!buffer.isEmpty())
//    {
//        int ret = buffer.dequeue();
//        emit readValue(ret);
//    }
//    mutex.unlock();
//}

 // 改用基于读写操作的锁,这样2个读线程可以同时使用lockForRead不要排队也不会造成阻塞,它只会在写操作时才会阻塞
 // 这里的代码是读线程

void readThread::run()
{
    isRead = true;
    QReadLocker Locker(&Lock); // 使用写锁也可以
    // Lock.lockForRead();

//    while (!buffer.isEmpty() && isRead)
//    {
//        int ret = buffer.dequeue();
//        // qDebug()<<"read thread is running";
//        emit readValue(ret);
//        msleep(100);
//    }
//    if (buffer.isEmpty()) // 如果是没数据的原因发射-1
//        emit readValue(-1);
//    if (!isRead) // 如果是isRead暂停的原因
//        emit readValue(-2);

    // 因为涉及2个读线程,所以不要使用dequeue更改了buffer,只是单纯遍历读取,暂停的话记录位置保存在pos
    // 即使buffer又写入了很多数据,不会影响pos之前的数据已经被读取过,不需要再读取
    int i  = 0;
    for(i = pos; i < buffer.size(); ++i) // 从暂停位置开始读
    {
        if (!isRead)
        {
            emit readValue(-2);
            this->pos = i ;//更新暂停位置
            break;
        }
        emit readValue(buffer[i]);
        msleep(50);
    }
    if (i == buffer.size()) emit readValue(-1) ; // 如果数据读完了发送-1
    this->pos = i;
    qDebug()<<"pos = "<<pos;
    // Lock.unlock();
    quit();
}

void readThread::stopRead()
{
    this->isRead = false;
}

void readThread::reset()
{
    this->pos = 0;
    this->isRead = false;
}

readThread::readThread()
{
    pos = 0;
}
