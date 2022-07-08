#include "fixedQueryThread.h"
#include "spiCommand.h"
#include <QDebug>
fixedQueryThread::fixedQueryThread()
{
    QList<QString> commands = {
            (SPIC::spic(SPIC::COMMAND::MEAS_VOLT_AVAE)+";"),//电压测量值=>Ouput1&Ouput2
            (SPIC::spic(SPIC::COMMAND::MEAS_CURR_AVAE)+";"),// 电流测量值=>Ouput1&Ouput2
            (SPIC::spic(SPIC::COMMAND::MEAS_POW_AVAE)+";"),//功率测量值=>powOuput
            (SPIC::spic(SPIC::COMMAND::GET_WORK_STATUS)+"\n")// 工作状态用位表示,OFF/ON[6],CC[7],CV[8],CW[9],CC-[11],CP-[12]
    };
    this->command = commands[0]+commands[1]+commands[2]+commands[3];
}

void fixedQueryThread::startQuery()
{
    this->_stop = false;
    this->start();
}

void fixedQueryThread::stopQuery()
{
    this->_stop = true;
    this->wait(); // 阻止线程执行,防止界面其它的功能引起该线程意外执行
}

void fixedQueryThread::run()// 线程任务
{
    // 启动线程时
    this->_stop = false; // 这个可以在主线程去更改

    while (!this->_stop) // 线程只要还在执行
    {
          // QMutexLocker Locker(&this->mutex);
          emit sendCommand(this->command);
          msleep(flush_time);// 子线程休息300ms
    }
    quit(); // 相当于exit(0),成功退出子线程的事件循环
}
