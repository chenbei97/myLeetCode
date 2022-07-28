#include "TestQReadWriteLockBase.h"
#include "ui_TestQReadWriteLockBase.h"
#include <QDebug>
TestQReadWriteLockBase::TestQReadWriteLockBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestQReadWriteLockBase)
{
        ui->setupUi(this);
        this->wThread = new writeThread;
        this->rThread = new readThread;
        this->sThread = new saveThread;
        connect(rThread,SIGNAL(readValue(int)),this,SLOT(onReadValue(int)));
        connect(sThread,SIGNAL(saveValue(int)),this,SLOT(onSaveValue(int)));
}

TestQReadWriteLockBase::~TestQReadWriteLockBase()
{
        delete ui;
}

// 开始写操作
void TestQReadWriteLockBase::on_pushButton_2_clicked()
{
    this->wThread->start();
}

// 开始读操作
void TestQReadWriteLockBase::on_pushButton_clicked()
{
    this->rThread->start();
}

// 停止写操作
void TestQReadWriteLockBase::on_pushButton_3_clicked()
{
        this->wThread->stopWrite();
}

// 停止读操作
void TestQReadWriteLockBase::on_pushButton_4_clicked()
{
    this->rThread->stopRead();
}

// 开始保存操作
void TestQReadWriteLockBase::on_pushButton_5_clicked()
{
    this->sThread->start();
}

// 停止保存操作
void TestQReadWriteLockBase::on_pushButton_6_clicked()
{
    this->sThread->stopSave();
}

void TestQReadWriteLockBase::onReadValue(int ret)
{
    QByteArray str = QString::asprintf("%d",ret).toLocal8Bit();
    // qDebug()<<"str="<<str;
    if (str == "-1")
    {
        ui->plainTextEdit->appendPlainText("没有新数据可以读取!");
        return;
    }
    if (str == "-2")
    {
        ui->plainTextEdit->appendPlainText("暂停读取数据!");
        return;
    }
    ui->plainTextEdit->appendPlainText(QString::asprintf("正在读取第%d个数据: ",++count1)+str);
}

void TestQReadWriteLockBase::onSaveValue(int ret)
{
    QByteArray str = QString::asprintf("%d",ret).toLocal8Bit();
    // qDebug()<<"str="<<str;
    if (str == "-1")
    {
        ui->plainTextEdit->appendPlainText("没有新数据可以保存!");
        return;
    }
    if (str == "-2")
    {
        ui->plainTextEdit->appendPlainText("暂停保存数据!");
        return;
    }
    ui->plainTextEdit->appendPlainText(QString::asprintf("正在保存第%d个数据: ",++count2)+str);
}

void TestQReadWriteLockBase::on_pushButton_7_clicked()
{
    this->sThread->reset();
    this->sThread->quit();
    this->sThread->wait();

    this->rThread->reset();
    this->rThread->quit();
    this->rThread->wait();

    this->wThread->reset();
    this->wThread->quit();
    this->wThread->quit();

    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("全部重置成功!");
}
