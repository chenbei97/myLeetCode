#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    MyThread*workerThread = new MyThread;// 实例在主线程中
    // 检测到resultReady信号后就会调用handleResults处理(),handleResults在主线程执行
    connect(workerThread, SIGNAL(resultReady(const QString&)), this, SLOT(handleResults(const QString &)));
    // 检测到线程结束后,就释放掉,注意这里是workerThread的信号和workerThread的槽函数(主线程中调用)
    connect(workerThread, &MyThread::finished, workerThread, &QObject::deleteLater);
    workerThread->start(); // run()函数执行,是子线程
}

void MainWindow::handleResults(const QString &s)
{
     ui->statusbar->showMessage(s);
}
