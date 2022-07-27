#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     ui->spinBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    qDebug()<<"spinbox==> select = "<<arg1;
     cWorker->operate(arg1);
}

void MainWindow::on_handleResult(const QString&result)
{
    ui->statusBar->showMessage("反馈结果是："+result);
}

void MainWindow::on_pushButton_clicked()
{
    this->cWorker = new controllWorker; // 一经构造内部线程已经跑了起来
    connect(cWorker,SIGNAL(handleResult(const QString&)),this,SLOT(on_handleResult(const QString&))); //把结果拿到
    cWorker->start();
    qDebug()<<"工作线程启动";
    ui->spinBox->setEnabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    cWorker->stop();
    qDebug()<<"工作线程结束";
    ui->spinBox->setEnabled(false);
}
