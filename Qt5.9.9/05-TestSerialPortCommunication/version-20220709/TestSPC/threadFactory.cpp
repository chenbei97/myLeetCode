#include "threadFactory.h"
#include <QThread>
#include <QDebug>
QList<QThread*> threadFactory:: threads;
threadFactory::threadFactory()
{

}
threadFactory::~threadFactory()
{

}
QThread* threadFactory::createThread(QThread::Priority priority)
{
    QThread* thread = new QThread();
    thread->setPriority(priority);
    thread->start();
    threads.append(thread);
    return thread;
}


