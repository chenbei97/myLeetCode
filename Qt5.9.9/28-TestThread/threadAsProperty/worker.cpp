#include "worker.h"
#include <QDebug>

Worker::Worker()
{

}

void Worker::doWork(int select)
{

    QString result =QString::asprintf("%d",select);
    qDebug()<<"doWork===>select = "<<result;
    emit resultReady(result);
    // 把doWork函数获取的结果传播出去
}
