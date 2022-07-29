#include "TestOneQWaitConditionBase.h"
#include "ui_TestOneQWaitConditionBase.h"

TestOneQWaitConditionBase::TestOneQWaitConditionBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestOneQWaitConditionBase)
{
        ui->setupUi(this);
        this->initSignalSlotConnection();
        ui->btnStartThread->setEnabled(true);
        ui->btnStopThread->setEnabled(false);
}

TestOneQWaitConditionBase::~TestOneQWaitConditionBase()
{
    delete ui;
}

// 1. 关闭窗口事件,防止线程还在运行
void TestOneQWaitConditionBase::closeEvent(QCloseEvent *event)
{
    if (threadProducer.isRunning())
    {
        threadProducer.stopDice(); // 生产者模型直接停止生产即可
        threadProducer.wait();
    }

    if (threadConsumer.isRunning())
    {
        threadConsumer.terminate(); //消费者模型可能处于等待生产的状态,所以用terminate强制结束
        threadConsumer.wait();
    }
    event->accept();
}

// 2. 初始化信号绑定
void TestOneQWaitConditionBase::initSignalSlotConnection()
{
    // 1. 生产者和消费者模型启动,就通知状态栏
    connect(&threadProducer,SIGNAL(started()),this,SLOT(on_producerThread_started()));
    connect(&threadConsumer,SIGNAL(started()),this,SLOT(on_consumerThread_started()));
    // 2. 生产者和消费者模型结束,就通知状态栏
    connect(&threadProducer,SIGNAL(finished()),this,SLOT(on_producerThread_finshed()));
    connect(&threadConsumer,SIGNAL(finished()),this,SLOT(on_consumerThread_finshed()));
    // 3. 消费者模型读取的骰子数和掷骰子总次数
    connect(&threadConsumer,SIGNAL(readDiceValue(int,int)),this,SLOT(on_producerThread_readDiceValue(int,int)));
}

// 3. 生产者和消费者模型启动通知状态栏
void TestOneQWaitConditionBase::on_producerThread_started()
{
    ui->LabA->setText("生产者模型线程已经启动");
}
void TestOneQWaitConditionBase::on_consumerThread_started()
{
    ui->LabB->setText("消费者模型线程已经启动");
}

// 4. 生产者和消费者模型结束通知状态栏
void TestOneQWaitConditionBase::on_producerThread_finshed()
{
    ui->LabA->setText("生产者模型线程已经结束");
}
void TestOneQWaitConditionBase::on_consumerThread_finshed()
{
    ui->LabB->setText("消费者模型线程已经结束");
}

// 5. 消费者模型读取数据
void TestOneQWaitConditionBase::on_producerThread_readDiceValue(int frequency,int diceValue)
{
    QString  str=QString::asprintf("第 %d 次掷骰子，点数为：%d",
                                   frequency,diceValue);
    ui->plainTextEdit->appendPlainText(str);
    QPixmap pic;
    QString filename=QString::asprintf(":/images/d%d.jpg",diceValue);
    pic.load(filename);
    ui->LabPic->setPixmap(pic);
}

// 6. 启动线程
void TestOneQWaitConditionBase::on_btnStartThread_clicked()
{
    threadConsumer.start();
    threadProducer.start();
    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);
}

// 7. 结束线程
void TestOneQWaitConditionBase::on_btnStopThread_clicked()
{
    threadProducer.stopDice();// 结束生产者模型线程的run()函数执行
    threadProducer.wait();// 让其无限期等待

    // threadConsumer.stopRead();//结束消费者模型线程的run()函数执行,可能结束不了
    threadConsumer.terminate(); //因为消费者模型线程可能处于等待状态,所以用terminate强制结束
    threadConsumer.wait();//让其无限期等待

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);
}

// 8. 清空文本
void TestOneQWaitConditionBase::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}
