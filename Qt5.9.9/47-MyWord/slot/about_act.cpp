#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_action_triggered()
{
    QMessageBox::about(this,tr("关于"),tr("这是一个自定义的Office软件"));
}

void MainWindow::on_action_Qt_triggered()
{
    QMessageBox::aboutQt(this,tr("关于Qt"));
}
