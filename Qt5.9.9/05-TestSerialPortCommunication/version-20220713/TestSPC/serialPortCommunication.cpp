#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"
#include <QCloseEvent>
// 1.构造函数
SerialPortCommunication::SerialPortCommunication(QWidget *parent)
  : QMainWindow(parent),ui(new Ui::SerialPortCommunication)
{
        ui->setupUi(this);
        ui->statusbar->showMessage("当前运行模式为：xx模式");
        this->initialize();
}

// 2. 析构函数
SerialPortCommunication::~SerialPortCommunication()
{
        delete ui;
        delete timer;
        delete  Port;
        delete fixed_query_thread;
}


// 3. 重载窗口关闭事件,避免关闭窗口后线程仍在运行
void SerialPortCommunication::closeEvent(QCloseEvent *event)
{
    // 出现：QThread: Destroyed while thread is still running
    if (this->fixed_query_thread->isRunning())
    {
        this->fixed_query_thread->stopQuery();
        this->fixed_query_thread->wait();
    }
    event->accept();
}








