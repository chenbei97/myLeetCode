#include "TestOneQSemaphoreBase.h"
#include "ui_TestOneQSemaphoreBase.h"

// 窗口关闭
void TestOneQSemaphoreBase::closeEvent(QCloseEvent *event)
{
    if (producer.isRunning())
    {
        producer.terminate();//结束线程的run()函数执行
        producer.wait();
    }

    if (consumer.isRunning())
    {
        consumer.terminate(); //因为threadB可能处于等待状态,所以用terminate强制结束
        consumer.wait();
    }
    event->accept();
}

TestOneQSemaphoreBase::~TestOneQSemaphoreBase()
{
    delete ui;
}

TestOneQSemaphoreBase::TestOneQSemaphoreBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestOneQSemaphoreBase)
{
        ui->setupUi(this);
        // 生产和消费者线程的开始和结束反馈到状态栏
        connect(&producer,SIGNAL(started()),this,SLOT(on_producer_started()));
        connect(&producer,SIGNAL(finished()),this,SLOT(on_producer_finished()));
        connect(&consumer,SIGNAL(started()),this,SLOT(on_consumer_started()));
        connect(&consumer,SIGNAL(finished()),this,SLOT(on_consumer_finished()));
        // 消费者拿到的数据用于文本显示
        connect(&consumer,SIGNAL(newValue(int*,int,int)),this,SLOT(on_consumer_newValue(int*,int,int)));
}

// 1. 生产和消费者线程的开始和结束反馈到状态栏
void TestOneQSemaphoreBase::on_producer_started()
{
    ui->LabA->setText("生产者模型线程开始运行!");
}
void TestOneQSemaphoreBase::on_producer_finished()
{
    ui->LabA->setText("生产者模型线程已经结束!");
}
void TestOneQSemaphoreBase::on_consumer_started()
{
    ui->LabB->setText("消费者模型线程开始运行!");
}
void TestOneQSemaphoreBase::on_consumer_finished()
{
    ui->LabB->setText("消费者模型线程已经结束!");
}

// 2. 处理消费者拿到的数据
void TestOneQSemaphoreBase::on_consumer_newValue(int *data,int count, int bufId)
{
    QString  str=QString::asprintf("第 %d 个缓冲区：",bufId);
    for (int i=0;i<count;i++)
    {
        str=str+QString::asprintf("%d, ",*data);
        data++;
    }
    str=str+'\n';
    ui->plainTextEdit->appendPlainText(str);
}

void TestOneQSemaphoreBase::on_btnStartThread_clicked()
{
    consumer.start(); // 启动线程时必须先启动消费者,否则可能会丢失数据
    producer.start(); // 后启动生产者
    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);
}

void TestOneQSemaphoreBase::on_btnStopThread_clicked()
{
    consumer.stopConsume();//结束线程的run()函数执行
    consumer.terminate(); //可能处于等待状态,所以用terminate强制结束
    consumer.wait();

    producer.stopProduce();//结束线程的run()函数执行
    producer.wait();

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);
}

void TestOneQSemaphoreBase::on_btnClear_clicked()
{
        ui->plainTextEdit->clear();
}
