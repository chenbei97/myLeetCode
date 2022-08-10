#include "serverThread.h"
#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QDebug>

serverThread::serverThread(QObject *parent ) : QThread(parent), waitTimeout(0), quit(false)
{

}

serverThread::~serverThread()
{
    this->mutex.lock();
    this->quit = true;
    this->mutex.unlock();
    this->wait(); // 让线程等待
}

// 外部UI按钮来开启线程,只要开启就只能析构函数才能关闭,之后按钮的功能就值限于更新3个私有属性了
void serverThread::startServerThread(const QString &portName, int waitTimeout, const QString &response)
{
    QMutexLocker locker(&mutex);
    this->portName = portName;
    this->waitTimeout = waitTimeout;
    this->response = response;
    if (!isRunning())
        {this->start(); qDebug()<<QTime::currentTime().toString()+" [1] 服务端线程首次开启";}
    else {qDebug()<<QTime::currentTime().toString()+" [2] 服务端线程已连接,更新服务端信息";}
    // 没有了条件变量的wakeOne()调用,其它和客户端的代码完全一样
}

// 核心函数
void serverThread::run()
{
    qDebug()<<QTime::currentTime().toString()+" [3] 进入服务端线程";
    bool currentPortNameChanged = false;
    bool currentWaitTimeoutChanged= false;
    bool currentResponeChanged  = false;
    qDebug()<<QTime::currentTime().toString()+" [4] 检查服务端的串口信息";
    mutex.lock();
    QString currentPortName;
    if (currentPortName != this->portName) {
        currentPortName = this->portName;
        currentPortNameChanged = true;
        qDebug()<<QTime::currentTime().toString()+" [4.1.1] 连接串口发生更改,更新设置";
    }
    else {qDebug()<<QTime::currentTime().toString()+" [4.1.2] 连接串口未发生更改";}

    int currentWaitTimeout = -1;
    if (currentWaitTimeout != this->waitTimeout)
    {
        currentWaitTimeout = this->waitTimeout;
        currentWaitTimeoutChanged = true;
        qDebug()<<QTime::currentTime().toString()+" [4.2.1] 允许等待超时时间发生更改,更新设置";
    }
    else {qDebug()<<QTime::currentTime().toString()+" [4.2.2] 允许等待超时时间未发生更改";}

    QString currentRespone;
    currentRespone= this->response;
    if (currentRespone != this->response)
    {
        currentRespone = this->response;
        currentResponeChanged  = true;
        qDebug()<<QTime::currentTime().toString()+" [4.3.1] 回复客户端的消息发生更改,更新设置";
    }
    else {qDebug()<<QTime::currentTime().toString()+" [4.3.2] 回复客户端的消息未发生更改";}

    mutex.unlock();
    QSerialPort serial;

    qDebug()<<QTime::currentTime().toString()+" [5] 准备首次进入while循环";
    while (!quit)
    {
         qDebug()<<QTime::currentTime().toString()+" [6] 再次进入while循环";
        if (currentPortNameChanged)
        {
             qDebug()<<QTime::currentTime().toString()+" [7] 之前的连接串口发生更改,更新设置";
            serial.close();
            serial.setPortName(currentPortName);
            if (!serial.open(QIODevice::ReadWrite))
            {
                qDebug()<<QTime::currentTime().toString()+" [8] 新的串口打开失败";
                emit error(tr("不能打开串口%1, 错误码为%2").arg(portName).arg(serial.error()));
                return;
            }
        }
        // while内部在这之前的代码和客户端的代码也完全一样,下方的代码开始不同

        // 客户端是先写入数据发送请求,然后判断写入有没有超时,没有超时再判断是否可以读取,读取没有超时再读取数据
        // 读到了回复的数据会把数据发送出去,写入或者读取超时没有读到数据则都会发送超时错误,处理完一次事件后都会阻塞

        // 这里作为服务端的角色被动接收来自客户端的请求,只要客户端发送过请求,这里waitForReadyRead就会准备好开始读取
        // 无论读取是否成功,回复客户端是否成功都只是作出对应的反应,不会阻碍while循环,执行完剩余的代码后又会回到while初始代码处
         qDebug()<<QTime::currentTime().toString()+" [9] 准备读取来自客户端写入串口的请求";
        if (serial.waitForReadyRead(currentWaitTimeout)) // 每次调用read/readLine/readAll之前必须调用waitForReadyRead
        {
            // 读取请求
             qDebug()<<QTime::currentTime().toString()+" [10.1] 读取未超时,服务端正在读取来自客户端的请求";
            QByteArray requestData = serial.readAll();
            while (serial.waitForReadyRead(10)) // 同样的手法,如果此时还有新数据进来就读取它
                requestData += serial.readAll();

            // 回复请求
            QByteArray responseData = currentRespone.toLocal8Bit();
            serial.write(responseData);
             qDebug()<<QTime::currentTime().toString()+" [11] 服务端正在回复来自客户端的请求,回复的信息为<"+currentRespone+">";
            if (serial.waitForBytesWritten(waitTimeout)) // 调用write后要立即调用waitForBytesWritten
            {
                qDebug()<<QTime::currentTime().toString()+" [12.1 ] 服务端回复客户端的请求成功";
                emit request(QString::fromLocal8Bit(requestData)); // 把收到的请求发出去
            }
            else
            {
                qDebug()<<QTime::currentTime().toString()+" [12.2] 服务器端回复客户端的请求失败";
                emit timeout(tr("服务端回复客户端的请求超时 %1").arg(QTime::currentTime().toString()));
            }
        }
        else
        {
            qDebug()<<QTime::currentTime().toString()+" [10.2] 读取超时,服务端不能读取来自客户端的请求";
            emit timeout(tr("服务端等待客户端的请求超时 %1").arg(QTime::currentTime().toString()));
        }

        mutex.lock(); // 唯一的区别是这里没有条件变量的wait,不会在这里阻塞,下方的客户端代码完全一样
        qDebug()<<QTime::currentTime().toString()+" [13] 监测是否有来自用户界面的信息更新：";
        if (currentPortName != this->portName)
        {
            currentPortName = this->portName;
            currentPortNameChanged = true;
            qDebug()<<QTime::currentTime().toString()+" [14.1.1] 反馈：连接串口发生更改,更新设置";
        }
        else{ currentPortNameChanged = false; qDebug()<<QTime::currentTime().toString()+" [14.1.2] 反馈：连接串口未发生更改";}
        if (currentRespone != this->response)
        {
            currentRespone = this->response;
            currentResponeChanged = true;
             qDebug()<<QTime::currentTime().toString()+" [14.2.1]反馈：回复客户端的消息发生更改,更新设置";
        }
        else{currentResponeChanged = false; qDebug()<<QTime::currentTime().toString()+" [14.2.2] 反馈：回复客户端的消息未发生更改";}
        if (currentWaitTimeout != this->waitTimeout)
        {
              currentWaitTimeout = this->waitTimeout;
              currentWaitTimeoutChanged = true;
              qDebug()<<QTime::currentTime().toString()+" [14.3.1]反馈：允许等待超时时间发生更改,更新设置";
        }
        else{currentWaitTimeoutChanged = false; qDebug()<<QTime::currentTime().toString()+" [14.3.2] 反馈：允许等待超时时间未发生更改";}
        mutex.unlock();
        qDebug()<<QTime::currentTime().toString()+" [15] 服务端处理完本次客户端的请求";
    }
}

