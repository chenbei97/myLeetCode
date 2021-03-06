#ifndef ROLLDICE_H
#define ROLLDICE_H
#include <QThread>

class rollDice : public  QThread
{
    Q_OBJECT
public:
    rollDice();
private:
    int diceValue ; // 掷骰子得到的点数
    int diceFrequency; // 掷骰子的次数
    bool dstop; // 掷骰子停止标记位
    bool dpause; // 掷骰子暂停标记位

protected:
    void run() override; // 定义自己的线程任务

public:
    void startDice(); // 设定dpause标志位为false,封装start()函数,给主线程使用
    void stopDice(); // 设定dstop标志位为true,封装stop()函数,给主线程使用
    void pauseDice(); // 设定dpause标志位为true
signals:
    void transmit_dice_val_fre(int val,int fre); // 在run()函数调用传递参数的信号
};

#endif // ROLLDICE_H
