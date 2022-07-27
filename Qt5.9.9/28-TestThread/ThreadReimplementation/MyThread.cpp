#include "mythread.h"
#include <QTime>
MyThread::MyThread()
{

}

void MyThread::run()
{
    QString result = "123";
    qsrand(QTime::currentTime().second());
    qint32 res = qrand();
    emit resultReady(result+QString(res));
}
