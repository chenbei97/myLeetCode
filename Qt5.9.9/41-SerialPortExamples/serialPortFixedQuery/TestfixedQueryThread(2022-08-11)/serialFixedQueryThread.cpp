#include "serialFixedQueryThread.h"
#include <QDebug>
#include <QTime>

serialFixedQueryThread::serialFixedQueryThread(QObject * parent)
    : QThread(parent)
    ,mQuit(false)
    ,mTimeOutCount(0)
    ,mRequsetCount(0)
    ,mResponseCount(0)
{

}

serialFixedQueryThread::~serialFixedQueryThread()
{
    mutex.lock(); //  保护
    cond.wakeOne(); // 析构时先唤醒线程,让线程永远等待
    mQuit = true;
    mutex.unlock(); // 保护
    if (this->isRunning())
        this->terminate();
    this->wait();// 当前线程持续等待
}
void serialFixedQueryThread::startFixedQueryThread(QSerialPort * port, quint32 queryInterval)
{
      QMutexLocker locker(&mutex);
      mPort = port;
      mQueryInterval = queryInterval;
      if (!this->isRunning()) // 如果当前线程没有启动过
      {
            this->start(); // 启动线程
            qDebug()<<QTime::currentTime().toString()+" [BEGIN] 首次进入查询线程";
      }
      else {
          cond.wakeOne(); // 唤醒当前线程
          qDebug()<<QTime::currentTime().toString()+" [1] 唤醒查询线程";
      }
}

void serialFixedQueryThread::run()
{

    qDebug()<<QTime::currentTime().toString()+" [3] 首次进入run()函数";
    // 串口有没有发生变化
    bool portNameChanged = false;
    bool portBaudRateChanged = false;
    QString portName;
    qint32 portBaudRate = 0;

    mutex.lock(); // 保护开始,因为串口信息可能发生变化
    if (portName != mPort->portName())
    {
        qDebug()<<QTime::currentTime().toString()+ " [4.1] 串口名称发生变化";
        portName = mPort->portName();
        portNameChanged = true;
    }else {qDebug()<<QTime::currentTime().toString()+" [4.2] 串口名称没有变化";}

    if (portBaudRate !=mPort->baudRate())
    {
        qDebug()<<QTime::currentTime().toString()+" [5.1] 串口波特率发生变化";
        portBaudRate = mPort->baudRate();
        portBaudRateChanged = true;
    }else {qDebug()<<QTime::currentTime().toString()+"[5.2] 串口波特率没有变化";}
    mutex.unlock(); // 保护截止

    qDebug()<<QTime::currentTime().toString()+" [6] 准备进入while循环";
    while(!mQuit) // 一经启动只会在析构函数停止线程,while内部可以让线程睡眠等待下一次事件触发新的while循环
    {
          qDebug()<<QTime::currentTime().toString()+" [7] 再次进入while循环";
          if (portBaudRateChanged || portNameChanged)
          {
                  qDebug()<<QTime::currentTime().toString()+" [8] 之前的连接串口发生更改,更新设置";
                  mPort->close();
                 if (!mPort->open(QIODevice::ReadWrite))
                {
                    qDebug()<<QTime::currentTime().toString()+" [9.1] 新的串口打开失败";
                    QSerialPort::SerialPortError errorCode = mPort->error(); // 错误代码
                    emit error(errorCodeToString(errorCode));
                    return;
                }
                qDebug()<<QTime::currentTime().toString()+" [9.2] 新的串口打开成功";
                emit error(errorCodeToString(mPort->error())); // NoError
          }

         QByteArray requestBytes = QString("hello! how are you?").toLocal8Bit(); // 这里的请求就是要查询的命令这里简单代替
         mPort->write(requestBytes);
         ++mRequsetCount; // 请求+1
         qDebug()<<QTime::currentTime().toString()+" [10] 准备写入请求,累计请求次数"+QString::number(mRequsetCount)+"次";
         quint32 writeCount = 0; // 重复写入次数
         quint32 maxAllowWriteTimeout = mQueryInterval/5; // 假设查询周期是300ms必须完成一次查询,极端情况重复了5次,故每次最多允许等待60ms
         while(!mPort->waitForBytesWritten(maxAllowWriteTimeout)
              && writeCount < 5) //  writeCount等于4的时候写入第5次,然后等于5退出,故这里不取等号
         {
              mPort->write(requestBytes); // 重复写入
              ++writeCount;
              ++mRequsetCount; // 累计请求次数
              qDebug()<<QTime::currentTime().toString()+ " [11] 写入超时"+writeCount+"次,正在重复请求,累计请求次数"+QString::number(mRequsetCount)+"次";
         }
         if (writeCount >=5) // 说明是因为超时退出while的
         {
            qDebug()<<QTime::currentTime().toString()+" [12] 写入超时6次,本次查询失败";
            emit timeout(++mTimeOutCount); //每次超时60ms,超时5次意味着本次查询已经失败
            emit error("连接不正常：发送请求超时");
         }
         else
         { // 说明写入请求已经成功,可以等待回复
              // 计算waitForBytesWritten等待花费的时间(上限值),实际比这个值小

              // 按300ms计算,如果等待了0次,说明没有发生重复写入,但是也至少等待了一段时间,只是<60ms,可能10ms
              quint32 usedWaitWriteTime = (writeCount+1) *maxAllowWriteTimeout; //,如果等待了1次一定在(60,120)之间,可能70ms
              quint32 availWaitReadTimePer = (mQueryInterval - usedWaitWriteTime) / 5; // 留给读取的超时等待时间,因为剩下的时间没有读取到数据相当于固定查询失败了

              qDebug()<<QTime::currentTime().toString()+ " [13] 写入未发生超时,已花费时间<"+QString::number(usedWaitWriteTime)+"ms. "
                                  +"开始准备读取回复,允许读取等待的超时时间为"+QString::number(availWaitReadTimePer)+"ms";
              quint32 readCount = 0;
              while (!mPort->waitForReadyRead(availWaitReadTimePer)
                        && readCount<5) // 60ms->1>120ms->2->180ms->3->240ms->4->300ms->5,故不取等号
              {
                    ++readCount; // 如果没有准备好读取,就继续等待
                    qDebug()<<QTime::currentTime().toString()+" [14] 读取超时"+QString::number(readCount)+"次,继续等待";
              }
              if (readCount >= 5)
              {
                  qDebug()<<QTime::currentTime().toString()+" [15] 读取超时6次,本次查询失败";
                  emit timeout(++mTimeOutCount); // 对方没有回复或者自己没读取到都算超时
                  emit error("连接正常：对方无应答");
              }
              else // 说明读取成功
              {
                  QByteArray responseBytes = mPort->readAll(); // 传输协议是Local8Bit
                  ++mResponseCount; // 累积回复次数
                  qDebug()<<QTime::currentTime().toString()+ " [16] 读取回复成功,累计读取回复次数为"+QString::number(mResponseCount)+"次";
                  QString responseData = QString::fromLocal8Bit(responseBytes); // 转为可读文本
                  emit response(responseData);// 发送的请求不需要显示到UI,读取的回复需要显示,所以要送出去
                  emit error("连接正常：对方已回复");
              }
         }


         // 到了这里,无论写入请求成功与否,读取回复成功与否,都会在这里等待下次事件(也就是下次查询的到来唤醒线程)
         emit responseRequesetCount(mResponseCount,mRequsetCount); // 把累计请求和回复次数发出去
         mutex.lock();
         cond.wait(&mutex); // 线程休眠,等待下次唤醒,在startFixedQueryThread中唤醒

         // 线程休眠的时候外部信息可能发生变化要及时更新再进入while的开头,防止出现错误
         if (portName != mPort->portName())
         {
              portName = mPort->portName();
              portNameChanged = true;
         }else {portNameChanged = false;}

         if (portBaudRate != mPort->baudRate())
         {
              portBaudRate = mPort->baudRate();
              portBaudRateChanged = true;
         }else {portBaudRateChanged = false;}

         mutex.unlock();
         qDebug()<<QTime::currentTime().toString()+" [END] 本次查询服务已经完成";
         qDebug()<<"*************************************************************************";
    }
}

QString serialFixedQueryThread::errorCodeToString(QSerialPort::SerialPortError erroeCode)
{
      QString s = "NoError";
      typedef QSerialPort::SerialPortError SerialPortError;
      switch (erroeCode)
      {
            case  SerialPortError::OpenError: s = "OpenError";break;
            case  SerialPortError::ReadError: s = "ReadError";break;
            case  SerialPortError::WriteError: s = "WriteError";break;
            case  SerialPortError::ParityError: s = "ParityError";break;
            case  SerialPortError::FramingError: s = "FramingError";break;
            case  SerialPortError::NotOpenError: s = "NotOpenError";break;
            case  SerialPortError::TimeoutError: s = "TimeoutError";break;
            case  SerialPortError::ResourceError: s = "ResourceError";break;
            case  SerialPortError::PermissionError: s = "PermissionError";break;
            case  SerialPortError::BreakConditionError: s = "BreakConditionError";break;
            case  SerialPortError::DeviceNotFoundError: s = "DeviceNotFoundError";break;
            case  SerialPortError::UnsupportedOperationError: s = "UnsupportedOperationError";break;
            case  SerialPortError::UnknownError: s = "UnknownError";break;
            default: break;
      }
      return s;
}
