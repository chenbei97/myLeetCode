#include "rollDice.h"
#include <QTime>

rollDice::rollDice() : diceValue(0),diceFrequency(0),dstop(false),dpause(true)
{
          // 默认进入子线程后就能执行run()函数
         // dstop=false,描述的状态是线程已经开始
         // dpause=true,表示没处于掷骰子的状态
}

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
            this->diceValue = qrand()% 6 +1; // 随机数,转换到数字[1,6]之间

            ++ this->diceFrequency; // 次数+1

            emit this->transmit_dice_val_fre(diceValue,diceFrequency); // 把数据传递出去
        }
        msleep(500); // 工作线程不要太快,500ms掷骰子1次
    }
    quit(); // 等价于exit(0),表示成功退出线程
}




