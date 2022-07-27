#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "setPenDialog.h"

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

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QRect rect(0,0,this->width(),this->height());
    painter.setViewport(rect);
    painter.setWindow(0,0,100,50);
    painter.setPen(this->mpen);
    painter.drawRect(10,10,80,30); // 画一个矩形是为了去反应画笔变化了,而不是矩形本身有什么含义
}

void MainWindow::on_action_Pen_triggered()
{
    bool    ok=false;
    QPen    pen=setPenDialog::getPen(this->mpen,ok); // 打开设置画笔的对话框
    if (ok)
    {
        this->mpen=pen;
        this->repaint();
    }
}
