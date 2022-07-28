#include "writeThread.h"
#include <QDebug>

QQueue<int> buffer; // 全局缓冲区
// QMutex mutex ; // 全局互斥量
// 如果使用QMutex,任何时候只能有1个线程去持有它,如果是1个写线程和2个读线程
// 实际上2个读线程同时访问buffer是不会冲突的,如果使用QMutex2个读线程还需要排队,这样相当于互斥量降低了程序性能
//void writeThread::run()
//{
//    qsrand(QTime::currentTime().msec());
//    mutex.lock();
//    for (int i = 0; i <100; ++i)
//            buffer.append(qrand() %100+1);
//    mutex.unlock();
//}

// 改用基于读写操作的锁,这样2个读线程可以同时使用lockForRead不要排队也不会造成阻塞,它只会在写操作时才会阻塞
// 这里的代码是写线程
QReadWriteLock Lock; // 全局读写锁
void writeThread::run()
{
    isWrite = true;
    qsrand(QTime::currentTime().msec());
    QWriteLocker Locker(&Lock); // 用写锁也可以
    //Lock.lockForWrite();
    while (isWrite)
    {
        qDebug()<<"write thread is running "<<buffer.size();
        buffer.append(qrand() %100+1);
        msleep(100);
//        if (buffer.size() == 20) break;
    }
    //Lock.unlock();
    quit();
}

void writeThread::reset()
{
    this->isWrite = false;
    buffer.clear();
}

writeThread::writeThread()
{

}

void writeThread::stopWrite()
{
    this->isWrite = false;
}
