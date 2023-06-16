#include "mainwindow.h"
#include <QQuickView>
#include <QQuickItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    btn = new QPushButton("点击");
    setCentralWidget(btn);
    resize(400,300);
    setFont(QFont("Times New Roman"));

    connect(btn,&QPushButton::clicked,this,[=]{
       QQuickView *view = new QQuickView;
      view->setSource(QUrl::fromLocalFile("./dialog.qml"));
      view->show();
      QQuickItem * item = view->rootObject();

      connect(item,&QQuickItem::heightChanged,this,[=]{
          qDebug()<<"height is changed!";
      });
      connect(item,SIGNAL(username(QString)),this,SLOT(onUsernameChanged(QString)));
      connect(item,SIGNAL(password(QString)),this,SLOT(onPasswordChanged(QString)));
    });
}

void MainWindow::onUsernameChanged(QString name){
    qDebug()<<"c++: => name = "<<name;
}

void MainWindow::onPasswordChanged(QString pwd)
{
    qDebug()<<"c++: => pwd = "<<pwd;
}

MainWindow::~MainWindow()
{
}

