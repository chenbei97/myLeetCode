#include "TestTwoQWaitConditionBase.h"
#include "ui_TestTwoQWaitConditionBase.h"
#include <QDebug>

void TestTwoQWaitConditionBase::closeEvent(QCloseEvent *event)
{
//    if (producer.isRunning())
//    {
//        producer.quit();
//        producer.wait();
//    }

//    if (consumer.isRunning())
//    {
//        consumer.terminate(); //消费者模型可能处于等待生产的状态,所以用terminate强制结束
//        consumer.wait();
//    }
    event->accept();
}

TestTwoQWaitConditionBase::TestTwoQWaitConditionBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestTwoQWaitConditionBase)
{
    ui->setupUi(this);
    connect(&producer,SIGNAL(stringProduced(const QString)),this,SLOT(on_stringProduced(const QString)));
    connect(&consumer,SIGNAL(stringConsumed(const QString)),this,SLOT(on_stringConsumed(const QString)));
}

TestTwoQWaitConditionBase::~TestTwoQWaitConditionBase()
{
    delete ui;
}

void TestTwoQWaitConditionBase::on_stringProduced(const QString& text)
{
    ui->plainTextEdit->appendPlainText(QString::asprintf("正在生产第%d个数据：",++count1)+text);
}

void TestTwoQWaitConditionBase::on_stringConsumed(const QString&text)
{
    ui->plainTextEdit->appendPlainText(QString::asprintf("正在读取生产的第%d个数据：",++count2)+text);
}
void TestTwoQWaitConditionBase::on_pushButton_clicked()
{
    producer.start();
    consumer.start();
}
