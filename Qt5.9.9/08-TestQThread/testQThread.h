#ifndef TESTQTHREAD_H
#define TESTQTHREAD_H

#include <QMainWindow>
#include "rollDice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestQThread; }
QT_END_NAMESPACE

class TestQThread : public QMainWindow
{
    Q_OBJECT

public:
    TestQThread(QWidget *parent = nullptr);
    ~TestQThread();
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
    void dice_show(int val,int fre); // 显示在QPlainText

private:
    Ui::TestQThread *ui;
    rollDice * rolldice;
};
#endif // TESTQTHREAD_H
