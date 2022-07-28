#include "rollDice.h"
#include <QTime>

rollDice::rollDice() : diceValue(0),diceFrequency(0),dstop(false),dpause(true)
{
          // 默认进入子线程后就能执行run()函数
         // dstop=false,描述的状态是线程已经开始
         // dpause=true,表示没处于掷骰子的状态
}

// 原理上下方的3个函数stopDice(),startDice(),pauseDice()涉及的变量dstop和dpause会被主线程修改
// 应该使用互斥量保护,但是这3个函数都只有1条赋值语句,所以认为是原子操作,所以可以不用锁定保护
void rollDice::stopDice()
{
    this->dstop = true;
}

void rollDice::startDice()
{
    this->dpause = false;
}

void rollDice::pauseDice()
{
    this->dpause = true;
}


void rollDice::run() // 工作线程
{
    this->dstop = false; // 开启状态
    qsrand(QTime::currentTime().msec()); // 以返回的毫秒时间作为随机种子

    while (!dstop)  // 只要外部没有停止它就执行
    {
        if (!dpause) // 只要外部没点暂停就执行
        {
            // 第3个区别,使用互斥量保护关键代码
            // QMutexLocker Locker(&this->mutex); // 只用这句简化代码也可以
            this->mutex.lock(); // 第1个区别:关键代码处锁定互斥量
            this->diceValue = qrand()% 6 +1; // 随机数,转换到数字[1,6]之间
            ++ this->diceFrequency; // 次数+1
            // emit this->transmit_dice_val_fre(diceValue,diceFrequency); // 把数据传递出去
            this->mutex.unlock(); // 第2个区别:配对使用解锁互斥量
        }
        msleep(500); // 工作线程不要太快,500ms掷骰子1次
    }
    quit(); // 等价于exit(0),表示成功退出线程
}

// 第4个区别,不使用信号槽机制就需要提供公共函数访问
bool rollDice::transmit_dice_val_fre(int *val, int *fre)
{
    if (this->mutex.tryLock()) // 读取的时候尝试锁定互斥量,如果锁定成功说明可以读取,不会发生读取的时候工作线程修改这2个值
    {
        *val = this->diceValue;
        *fre = this->diceFrequency;
        mutex.unlock();
        return true;
    }
    return false;
}
