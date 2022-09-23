#include "serial/serial_fixedquery.h"

SerialFixedQueryThread::SerialFixedQueryThread(QObject * parent) : QThread(parent)
    , mQuit(false)
{
        // 监控 setRoleValue => 通讯 setRoleValue => this setRoleValue => 处理器 updateRoleValue

        // （1）this => 处理器
        connect(this,&SerialFixedQueryThread::setRoleValue,&mProcessor,&ResponseProcessor::updateRoleValue);

        // （2）处理器 => this
        connect(&mProcessor,&ResponseProcessor::fixedQuery,this,&SerialFixedQueryThread::portFixedQueryData);
        connect(&mProcessor,&ResponseProcessor::setQuery,this,&SerialFixedQueryThread::portSetQueryData);
}

SerialFixedQueryThread::~SerialFixedQueryThread()
{
      mMutex.lock(); //  保护
      mCond.wakeOne(); // 析构时先唤醒线程,让线程永远等待
      mQuit = true;
      mMutex.unlock(); // 保护
      if (this->isRunning())
          this->terminate();
      this->wait();// 当前线程持续等待
}

void SerialFixedQueryThread::startFixedQueryThread(QSerialPort * port)
{
      QMutexLocker locker(&mMutex);
      mPort = port;
      if (!this->isRunning()) // 如果当前线程没有启动过
      {
            this->start(); // 启动线程
      }
      else {
          mCond.wakeOne(); // 否则本函数的再次调用视为一次唤醒,唤醒之前的已运行线程
      }
}


void SerialFixedQueryThread::run()
{
    // 串口的信息可能在休眠的时候发生变化,先用几个变量记录开始时串口信息
    bool portChanged = true; // 初始值只会执行1次之后只会在while内部执行,首次进入一定要true那么while内就会打开串口
    mMutex.lock();
    auto name = mPort->portName();
    if (name.isEmpty())
    {
          emit errorCode(SERIALERROR::DeviceNotFoundError);
          mMutex.unlock();
          return;//没有可用串口
     }
    auto baudrate = mPort->baudRate();
    auto parity = mPort->parity();
    auto databit = mPort->dataBits();
    auto stopbit = mPort->stopBits();
    auto flowcontrol = mPort->flowControl();

    mMutex.unlock();
    while(!mQuit) // 一经启动只会在析构函数停止线程,while内部可以让线程睡眠等待下一次事件(定时器)触发新的while循环
    {
        if (portChanged) // 这个值初始是true,之后就是while末尾段代码决定了,一般是false无需重新打开
        {
             mPort->close(); // 在这里关闭是ok的
             if (!mPort->open(QIODevice::ReadWrite)) //以新的串口属性打开
            {
                  quint32 index = static_cast<quint32>(mPort->error());
                  emit errorCode(SERIALERROR(index)); // 串口错误码和自定义的串口错误码定义是一致的
                  //quit(); // 使用quit,可能用户发现串口错误后没去改变串口设置又点击重连导致软件异常退出,不使用即使重连也不会异常退出只会弹出消息框提醒
                  //return; // 暴力返回,对用户来讲就是软件异常退出
            }
            else emit errorCode(SERIALERROR::NoError); // 正常打开就发送无错误
        }
        // 串口没有改变过就直接执行
        mPort->write(MEAS_VCPR);

        quint32 writeCount = 0; // 重复写入次数
        quint32 maxAllowWriteTimeout = mQueryInterval/5; // 假设查询周期是300ms必须完成一次查询,极端情况重复了5次,故每次最多允许等待60ms

         while(!mPort->waitForBytesWritten(maxAllowWriteTimeout) // 超时且超时次数<5时重发
              && writeCount < 5) //  writeCount等于4的时候写入第5次,然后等于5退出,故这里不取等号
         {
              mPort->write(MEAS_VCPR); // 重复写入
              ++writeCount;
         }

         if (writeCount >=5) // 说明是因为超时退出while的
         {
              emit errorCode(TIMEOUTCODE::RequestTimeout); // 请求超时
         }
         else // 说明写入请求已经成功,可以等待回复
         {
              emit errorCode(TIMEOUTCODE::RequestNormal); // 请求正常
              // 计算waitForBytesWritten等待花费的时间(上限值),实际比这个值小
              // 按300ms计算,如果等待了0次,说明没有发生重复写入,但是也至少等待了一段时间,只是<60ms,可能10ms
              quint32 usedWaitWriteTime = (writeCount+1) *maxAllowWriteTimeout; //,如果等待了1次一定在(60,120)之间,可能70ms
              quint32 availWaitReadTimePer = (mQueryInterval - usedWaitWriteTime) / 5; // 留给读取的超时等待时间,因为剩下的时间没有读取到数据相当于固定查询失败了

              quint32 readCount = 0;
              while (!mPort->waitForReadyRead(availWaitReadTimePer) // 在剩下有效的读取时间内没有读取就重复读取
                        && readCount<5) // 60ms->1>120ms->2->180ms->3->240ms->4->300ms->5,故不取等号
              {
                    ++readCount; // 如果没有准备好读取,就继续等待
              }
              if (readCount >= 5)
              {
                  emit errorCode(TIMEOUTCODE::ReceiveTimeout); // 接收超时
              }
              else // 说明读取成功
              {
                  emit errorCode(TIMEOUTCODE::ReceiveNormal); // 接收正常           
                  mProcessor.setData(mPort->readAll());
                  mProcessor.run();
              }
         }
         // 到了这里,无论写入请求成功与否,读取回复成功与否,都会在这里等待下次事件(也就是下次查询的到来唤醒线程)
         mMutex.lock();
         mCond.wait(&mMutex); // 线程休眠,等待下次唤醒,在startFixedQueryThread中唤醒

         // 线程休眠的时候(也就是暂停的时候或者说定时器停止时)外部串口信息可能发生变化
         // 要及时更新再进入while的开头,防止出现错误
         bool ret1 = name!=mPort->portName();
         bool ret2 = baudrate != mPort->baudRate();
         bool ret3 = parity != mPort->parity();
         bool ret4 = stopbit != mPort->stopBits();
         bool ret5 = databit != mPort->dataBits();
         bool ret6 = flowcontrol != mPort->flowControl();
         if (ret1) name = mPort->portName();
         if (ret2) baudrate = mPort->baudRate();
         if (ret3) parity = mPort->parity();
         if (ret4) stopbit = mPort->stopBits();
         if (ret5) databit = mPort->dataBits();
         if (ret6) flowcontrol = mPort->flowControl();
         // 如果外界确实发生了改变,那么这6个局部变量就得到了更新,同时portChanged=true就可以影响到while内部的串口
         // 当portChanged=true时串口会重新关闭并打开,注意,串口的关闭和打开始终只能在工作线程完成不能在外部控制
         portChanged = (ret1 | ret2 | ret3 | ret4 | ret5 | ret6); // 有1个为真(改变了)就为真
         mMutex.unlock();
    }
}
