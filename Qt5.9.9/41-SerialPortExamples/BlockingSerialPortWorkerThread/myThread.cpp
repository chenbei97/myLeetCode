#include "myThread.h"
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTime>

myThread::myThread(QObject *parent)
    : QThread(parent), waitTimeout(0), quit(false)
{

}

myThread::~myThread()
{
    this->mutex.lock();
    this->quit = true;
    this->cond.wakeOne();
    this->mutex.unlock();
    this->wait();
}

void myThread::transaction(const QString &portName, int waitTimeout, const QString &request)
{
    QMutexLocker locker(&mutex); // 先锁定mutex
    // 把UI传过来的串口名、超时时间和要发送的消息保存
    this->portName = portName;
    this->waitTimeout = waitTimeout;
    this->request = request;

    if (!isRunning()) // 如果没启动过线程就启动线程
        start();
    else // 线程启动过就唤醒这个线程,这个线程应该在上次的while循环内cond.wait(&mutex)阻塞
        cond.wakeOne(); // 唤醒之后立刻会继续上次冻结的状态向下执行,也就是跳转至run()函数的注释（5）这里接着执行
}

void myThread::run()
{
    bool currentPortNameChanged = false;

    // （1）UI传递进来的3个信息来初始化局部变量,因为这3个值是随时可能被修改的,而本函数又在使用这3个变量
    // 所以下边这段对临时数据的改变代码段需要使用mutex保护起来
    mutex.lock();
    QString currentPortName; // UI传递进来的串口名称负责初始化此变量
    if (currentPortName != this->portName) { // 不相等说明进来的串口名称可用
        currentPortName = this->portName;
        currentPortNameChanged = true;
    }
    int currentWaitTimeout = this->waitTimeout; // UI传递进来的超时时间
    QString currentRequest = this->request; // UI传递进来的串口请求消息
    mutex.unlock();// 临时变量的写入保护截至

    if (currentPortName.isEmpty()) { // 说明外部没有可用串口
        emit error(tr("没有可用串口")); // 把消息传递出去
        return;
    }

    QSerialPort serial;

    // （2）对于阻塞型代码需要自行构建事件循环
    while (!this->quit) // quit在构造函数初始化为false,故这是1个死循环
    {
        if (currentPortNameChanged) // 时刻检查是否更改了串口
        {
            serial.close(); // 先关闭串口
            serial.setPortName(currentPortName);
            if (!serial.open(QIODevice::ReadWrite)) // 把打开串口的错误发送出去
            {
                emit error(tr("不能打开串口%1, 错误码为%2")
                           .arg(portName).arg(serial.error()));
                return;
            }
        }

        // 想要发送的消息转为QByteArray按字符处理,前提是转为当前语言环境下的本地8bit字符串表示
        QByteArray requestData = currentRequest.toLocal8Bit();
        serial.write(requestData); // 串口写入请求

        // （3）【注意阻塞型方式每次调用write都要紧跟着waitForBytesWritten确保是否写入成功】
        if (serial.waitForBytesWritten(this->waitTimeout)) // 写入没有超时再读取回复
        {
            // 每次调用read/readLine/readAll之前必须调用waitForReadyRead
            if (serial.waitForReadyRead(currentWaitTimeout))  // 读取没有超时
            {
                QByteArray responseData = serial.readAll(); // 读取回复的数据
                while (serial.waitForReadyRead(10))// 继续读取剩下的可能没读取完的数据,10s是自定义的安全阈值
                    responseData += serial.readAll(); // 如果之前读取的比较慢没读完,可以把10s适当延长
                    // 注意如果延长至超过回复消息的速度,例如回复消息固定300ms1次,而这里设置等待>300ms
                    // 那么waitForReadyRead状态永远是true,因为等待期间内总是有新数据进来,总是处于准备读取的状态
                    // 那么永远不会退出这个while循环直到外部不再发送消息,responseData就会累计成很大的字符串
                    // 如果设置的是10s,这么短的时间内不会有新数据进来,那么就不处于准备读取的状态,while退出循环

                emit response(QString(responseData)); // 把收到的恢复发送出去
            }
            else // 读取超时
            {
                emit timeout(tr("读取数据超时"));
            }
        }
        else  // 写入超时
        {
            emit timeout(tr("写入数据超时"));
        }

        // （4）无论有没有新数据,读取有没有超时,在这之后线程都会进入阻塞直到出现下一个事件
        mutex.lock(); // wait内部会释放mutex,前提是mutex处于lock状态
        cond.wait(&mutex);//这里开始阻塞下一个事件,死循环并不是真正的死循环是通过阻塞可以控制的

        // （5）下一个事件就是clicked的触发,重新调用transaction函数,使用wakeOne唤醒了当前线程
        // 并直接跳转至这里继续执行完毕后又回到while循环的开头(因为这是个循环),再一次处理数据,无论数据读取的情况如何
        // 在（4）处会继续冻结等待下一次clicked,也就是说用户需要手动点击接收数据,UI不能自动更新收到的消息
        // 如果数据一直在发送,但是用户迟迟不点击接收,就会导致一次性发送累计的消息巨大
        // 可能的做法是在UI界面的设计中不需要人去点击,定时器的timeout信号绑定到按钮的clicked信号,clicked信号绑定好槽函数
        // 就可以实现定时的读取数据了

        if (currentPortName != this->portName) {
            currentPortName = portName;
            currentPortNameChanged = true;
        }
        else
        {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = this->waitTimeout;
        currentRequest = this->request;
        mutex.unlock();
    }
}
