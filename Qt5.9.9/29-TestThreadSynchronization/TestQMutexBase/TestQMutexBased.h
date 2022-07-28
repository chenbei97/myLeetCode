#ifndef TESTQMUTEXBASED_H
#define TESTQMUTEXBASED_H

#include <QMainWindow>
#include <QTimer>
#include "rollDice.h"
QT_BEGIN_NAMESPACE
namespace Ui { class TestQMutexBased; }
QT_END_NAMESPACE

class TestQMutexBased : public QMainWindow
{
    Q_OBJECT
private:
    int diceValue, diceFrequency;// 第1个区别:不借助信号槽机制,就需要2个变量接收rollDice的公共函数transmit_dice_val_fre(int*,int*)
    QTimer mTimer; // 第2个区别是没有信号槽机制,只能通过增加定时器来定时主动的读取数据,timeout的槽函数onTimeOut()内部调用transmit_dice_val_fre
    // 但是不保证每次读取的就是新的数据,很可能工作线程来不及修改2个值,这时就需要diceFrequency来保存之前读取的变量,diceFrequency和读取来的fre比较
    // 如果一致说明是旧数据,本次定时查询无效,不一致再更新2个值diceFrequency和diceValue,并显示在QPlainText上
public:
    TestQMutexBased(QWidget *parent = nullptr);
    ~TestQMutexBased();
private:
    void initialize_button_enable(); // 初始化使能的工作
    void initialize_signals_slots_connection();
protected:
    void closeEvent(QCloseEvent * event);
private slots:
    // UI的槽函数,5个pushButton
    void on_btnStartThread_clicked();
    void on_btnStopThread_clicked();
    void on_btnDiceBegin_clicked();
    void on_btnDicePause_clicked();
    void on_btnClear_clicked();
    // 自定义槽函数
    void thread_status_show(); // 显示在QLabel
    // void dice_show(int val,int fre); // 显示在QPlainText,注释掉,改用onTimeOut()
    void onTimeOut(); // 第3个区别: 定时获取数值的槽函数,显示在QPlainText
private:
    Ui::TestQMutexBased *ui;
    rollDice * rolldice;
};
#endif // TESTQMUTEXBASED_H
