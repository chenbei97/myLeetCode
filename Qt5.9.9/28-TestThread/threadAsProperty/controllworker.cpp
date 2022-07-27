#include "controllworker.h"
#include "worker.h"
#include <QDebug>

controllWorker::controllWorker()
{
    // 新的工作对象,工作线程转交给一个QThread对象
    Worker * worker= new Worker;
    worker->moveToThread(&this->workerThread);

    // 工作线程结束后,要把工作对象释放掉(工作线程的finished控制工作对象的析构)
    connect(&this->workerThread,&QThread::finished,worker,&QObject::deleteLater);

    // worker的doWork函数执行就会触发resultReady,继而触发handleReady
    // 那么谁来控制doWork,可以使用UI的按钮,点击按钮就执行了worker的doWork函数
    // 但是这里controllWorker封装了一层,对mainwindow来说没法使用
    // 即使worker是全局定义的还必须是public权限,这样的话不好用
    // 所以可以让一个信号连接doWork就行,触发这个信号就等同于执行worker的doWork函数
    // doWork可以被任何对象/线程的信号连接,所以这里定义了一个operate信号连接它
    // 而这个operate信号可以直接被mainwindow使用,例如连接到按钮的槽函数
    // 因为doWork的参数是int,所以operate也要定义参数为int
    // 注意信号连接函数,所以这里operate在前,doWork在后,不能反过来
    connect(this,&controllWorker::operate,worker,&Worker::doWork);

    // 工作对象发出的信号要被拿到被处理(工作对象的readyRead连接控制器的handleReady)
    connect(worker,&Worker::resultReady,this,&controllWorker::handleReady);

}

void controllWorker::start()
{
    this->workerThread.start();
}

void controllWorker::stop()
{
    this->workerThread.quit();
    this->workerThread.wait();
}

void controllWorker::handleReady(const QString&result)
{
    qDebug()<<"handleReady==>result = "<<result;
   emit handleResult(result);
}



