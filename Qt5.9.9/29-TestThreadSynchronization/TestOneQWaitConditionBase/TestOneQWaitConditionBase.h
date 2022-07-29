#ifndef TESTONEQWAITCONDITIONBASE_H
#define TESTONEQWAITCONDITIONBASE_H

#include <QMainWindow>
#include <QTimer>
#include "rollDiceThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestOneQWaitConditionBase; }
QT_END_NAMESPACE

class TestOneQWaitConditionBase : public QMainWindow
{
    Q_OBJECT
private:
    QThreadProducer   threadProducer;
    QThreadConsumer   threadConsumer;
    void initSignalSlotConnection();
protected:
    void    closeEvent(QCloseEvent *event);
public:
    explicit TestOneQWaitConditionBase(QWidget *parent = nullptr);
    ~TestOneQWaitConditionBase();
private slots:
    // 3个按钮的槽函数
    void on_btnStartThread_clicked();
    void on_btnStopThread_clicked();
    void on_btnClear_clicked();
    // 绑定到生产者和消费者线程的started/finshed信号通知状态栏
    void on_producerThread_started();
    void on_consumerThread_started();
    void on_producerThread_finshed();
    void on_consumerThread_finshed();
    // 绑定到消费者模型线程的readDiceValue信号
    void on_producerThread_readDiceValue(int frequency,int diceValue);
private:
    Ui::TestOneQWaitConditionBase *ui;
};
#endif // TESTONEQWAITCONDITIONBASE_H
