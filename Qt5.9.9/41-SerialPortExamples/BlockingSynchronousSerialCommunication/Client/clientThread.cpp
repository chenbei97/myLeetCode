#include "clientThread.h"
#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QDebug>

clientThread::clientThread(QObject*parent): QThread(parent), waitTimeout(0), quit(false)
{

}

clientThread::~clientThread()
{
    this->mutex.lock();
    this->quit = true;
    this->cond.wakeOne();
    this->mutex.unlock();
    this->wait();
}

// 外部UI按钮来开启线程,只要开启就只能析构函数才能关闭,之后按钮的功能就值限于更新3个私有属性了
void clientThread::startClientThread(const QString &portName, int waitTimeout, const QString &request)
{
    QMutexLocker locker(&mutex);
    this->portName = portName; // 把UI传过来的串口名、超时时间和要发送的消息保存
    this->waitTimeout = waitTimeout;
    this->request = request;

    if (!isRunning())
        {start();qDebug()<<QTime::currentTime().toString()+" [1] 客户端线程首次开启";}
    else // 线程启动过就唤醒这个线程,这个线程应该在上次的while循环内cond.wait(&mutex)阻塞
        {cond.wakeOne();qDebug()<<QTime::currentTime().toString()+" [2] 客户端线程已连接,唤醒线程并更新服务端信息";} // 唤醒之后立刻会继续上次冻结的状态向下执行
}

void clientThread::run()
{
     qDebug()<<QTime::currentTime().toString()+" [3] 进入客户端线程";
    // （1）UI传递进来的3个信息来初始化局部变量,因为这3个值是随时可能被修改的,而本函数又在使用这3个变量
    // 所以下边这段对临时数据的改变代码段需要使用mutex保护起来
    bool currentPortNameChanged = false;
    bool currentWaitTimeoutChanged= false;
    bool currentRequestChanged  = false;
    qDebug()<<QTime::currentTime().toString()+" [4] 检查客户端的串口信息";

    mutex.lock();
    QString currentPortName;
    if (currentPortName != this->portName) {
        currentPortName = this->portName;
        currentPortNameChanged = true;
        qDebug()<<QTime::currentTime().toString()+" [4.1.1] 连接串口发生更改,更新设置";
    }
    else {qDebug()<<QTime::currentTime().toString()+" [4.1.2] 连接串口未发生更改";}

     if (currentPortName.isEmpty()) {
          qDebug()<<QTime::currentTime().toString()+" [4.1.3] 没有可用串口";
          emit error(tr("没有可用串口"));
          return;
    }

    int currentWaitTimeout = -1;
    if (currentWaitTimeout != this->waitTimeout)
    {
        currentWaitTimeout = this->waitTimeout;
        currentWaitTimeoutChanged = true;
        qDebug()<<QTime::currentTime().toString()+" [4.2.1] 允许等待超时时间发生更改,更新设置";
    }
    else {qDebug()<<QTime::currentTime().toString()+" [4.2.2] 允许等待超时时间未发生更改";}

    QString currentRequest;
    currentRequest= this->request;
    if (currentRequest != this->request)
    {
        currentRequest = this->request;
        currentRequestChanged  = true;
        qDebug()<<QTime::currentTime().toString()+" [4.3.1] 发送服务端的请求发生更改,更新设置";
    }
    else {qDebug()<<QTime::currentTime().toString()+" [4.3.2] 发送服务端的请求未发生更改";}

    mutex.unlock();
    QSerialPort serial;

    // （2）对于阻塞型代码需要自行构建事件循环
    qDebug()<<QTime::currentTime().toString()+" [5] 准备首次进入while循环";
    while (!this->quit) // quit在构造函数初始化为false,故这是1个死循环
    {
        qDebug()<<QTime::currentTime().toString()+" [6] 再次进入while循环";
        if (currentPortNameChanged) // 检查是否更改了串口,因为可能上次while线程冻结时外部可能通过clicked把3个私有信息已经改变
        {
            qDebug()<<QTime::currentTime().toString()+" [7] 之前的连接串口发生更改,更新设置";
            serial.close();
            serial.setPortName(currentPortName);
            if (!serial.open(QIODevice::ReadWrite)) // 把打开串口的错误发送出去
            {
                qDebug()<<QTime::currentTime().toString()+" [8] 新的串口打开失败";
                emit error(tr("不能打开串口%1, 错误码为%2").arg(portName).arg(serial.error()));
                return;
            }
        }

        qDebug()<<QTime::currentTime().toString()+" [9] 准备向串口写入发给服务端的请求";
        // 客户端先写入数据发送请求,如果发送请求成功,服务端会收到之后回复,此时客户端就能够读取服务的回复
        // 如果客户端发送请求超时.或者服务端的原因回复超时亦或者客户端读取数据超时,都会发送超时错误
        // 无论客户端有没有发送请求成功,有没有读取回复成功处理完一次事件后都会阻塞
        QByteArray requestData = currentRequest.toLocal8Bit();// 将发送的请求转为当前语言环境下的本地8bit字符形式的QByteArray
        serial.write(requestData);

        // （3）【注意阻塞型方式每次调用write都要紧跟着waitForBytesWritten确保是否写入成功】
        if (serial.waitForBytesWritten(this->waitTimeout)) // 写入没有超时再读取回复
        {
            qDebug()<<QTime::currentTime().toString()+" [10.1] 请求未超时,客户端正在向服务端发送请求";
            if (serial.waitForReadyRead(currentWaitTimeout))   // 每次调用read/readLine/readAll之前必须调用waitForReadyRead
            {
                qDebug()<<QTime::currentTime().toString()+" [11] 客户端正在读取来自服务端的回复";
                QByteArray responseData = serial.readAll(); // 读取回复的数据
                while (serial.waitForReadyRead(10))// 继续读取剩下的可能没读取完的数据,10s是自定义的安全阈值
                    responseData += serial.readAll(); // 如果之前读取的比较慢没读完,可以把10s适当延长
                    // 注意如果延长至超过回复消息的速度,例如回复消息固定300ms1次,而这里设置等待>300ms
                    // 那么waitForReadyRead状态永远是true,因为等待期间内总是有新数据进来,总是处于准备读取的状态
                    // 那么永远不会退出这个while循环直到外部不再发送消息,responseData就会累计成很大的字符串
                    // 如果设置的是10s,这么短的时间内不会有新数据进来,那么就不处于准备读取的状态,while退出循环
                QString info = QString::fromLocal8Bit(responseData);
                qDebug()<<QTime::currentTime().toString()+" [12.1 ] 客户端收到服务端的回复成功,回复的信息为<"+info+">";
                emit response(info); // 把收到的回复发出去
            }
            else // 读取超时
            {
                qDebug()<<QTime::currentTime().toString()+" [12.2] 客户端读取来自服务端的回复失败";
                emit timeout(tr("客户端读取来自服务端的回复超时 %1").arg(QTime::currentTime().toString()));
            }
        }
        else  // 写入超时
        {
            qDebug()<<QTime::currentTime().toString()+" [10.2] 发送超时,客户端不能向服务端发送请求";
            emit timeout(tr("客户端发送给服务端的请求超时 %1").arg(QTime::currentTime().toString()));
        }

        // （4）无论有没有新数据,读取有没有超时,在这之后线程都会进入阻塞直到出现下一个事件
        mutex.lock(); // 使用条件变量的wait之前mutex必须处于lock状态,因为wait内部会对mutex解锁
        cond.wait(&mutex);//这里开始阻塞下一个事件,死循环并不是真正的死循环是通过阻塞可以控制的

        // （5）下一个事件就是clicked的触发,重新调用startClientThread函数,使用wakeOne唤醒了当前线程,同时把最新的3个变量信息更新
        // 并直接跳转至这里继续执行,然后又回到while循环的开头处理下一次事件(因为这是个循环),然后再到这里等待,如此往复
        // 注意（4）处冻结的时候在等待下一次clicked,也就是说用户需要手动点击按钮接收服务端的回复
        // 如果数据一直在发送,但是用户迟迟不点击接收,就会导致一次性接收的回复巨大
        // 可能的做法是在UI界面的设计中不需要人去点击,定时器的timeout信号绑定到按钮的clicked信号,clicked信号绑定好槽函数
        // 就可以实现定时的读取数据了,不过这个会造成一些其它问题需要完善,考虑到会比较复杂所以把关于定时器的代码已经注释掉

        // 冻结的时候外部UI的信息可能通过clicked信号传递给了this,局部变量需要进行一个判断来更新
        qDebug()<<QTime::currentTime().toString()+" [13] 监测是否有来自用户界面的信息更新：";
        if (currentPortName != this->portName)
        {
            currentPortName = this->portName;
            currentPortNameChanged = true;
            qDebug()<<QTime::currentTime().toString()+" [14.1.1] 反馈：连接串口发生更改,更新设置";
        }
        else{ currentPortNameChanged = false; qDebug()<<QTime::currentTime().toString()+" [14.1.2] 反馈：连接串口未发生更改";}

        if (currentRequest != this->request)
        {
            currentRequest = this->request;
            currentRequestChanged = true;
             qDebug()<<QTime::currentTime().toString()+" [14.2.1]反馈：发送服务端的请求发生更改,更新设置";
        }
        else{currentRequestChanged = false; qDebug()<<QTime::currentTime().toString()+" [14.2.2] 反馈：回复服务端的请求未发生更改";}

        if (currentWaitTimeout != this->waitTimeout)
        {
              currentWaitTimeout = this->waitTimeout;
              currentWaitTimeoutChanged = true;
              qDebug()<<QTime::currentTime().toString()+" [14.3.1]反馈：允许等待超时时间发生更改,更新设置";
        }
        else{currentWaitTimeoutChanged = false; qDebug()<<QTime::currentTime().toString()+" [14.3.2] 反馈：允许等待超时时间未发生更改";}
        mutex.unlock();
        qDebug()<<QTime::currentTime().toString()+" [15] 客户端处理完本次服务端的回复";
    }
}
