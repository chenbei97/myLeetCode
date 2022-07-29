#include "TestTwoQSemaphoreBase.h"
#include "ui_TestTwoQSemaphoreBase.h"

TestTwoQSemaphoreBase::TestTwoQSemaphoreBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestTwoQSemaphoreBase)
{
    ui->setupUi(this);
    connect(&producer,SIGNAL(stringProduced(const QString)),this,SLOT(on_stringProduced(const QString)));
    connect(&consumer,SIGNAL(stringConsumed(const QString)),this,SLOT(on_stringConsumed(const QString)));
}

void TestTwoQSemaphoreBase::on_stringProduced(const QString&text)
{
    ui->plainTextEdit->appendPlainText(QString::asprintf("正在生产第%d个数据：",++count1)+text);
}

void TestTwoQSemaphoreBase::on_stringConsumed(const QString& text)
{
    ui->plainTextEdit->appendPlainText(QString::asprintf("正在读取生产的第%d个数据：",++count2)+text);
}

TestTwoQSemaphoreBase::~TestTwoQSemaphoreBase()
{
    delete ui;
}

void TestTwoQSemaphoreBase::on_pushButton_clicked()
{
    producer.start();
    consumer.start();
}
