#include "mainwindow.h"
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
       // (1) 主窗口
       QTextEdit * textedit = new QTextEdit(this); // this为父窗口
       textedit->setText("main window");
       textedit->setAlignment(Qt::AlignCenter);
        this->setCentralWidget(textedit);
        // (2) 停靠窗口1
       QDockWidget * dock1 = new QDockWidget(tr("DockWindow1"),this);
       dock1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetVerticalTitleBar); // 可移动
       dock1->setAllowedAreas(Qt::LeftDockWidgetArea| Qt::RightDockWidgetArea);// 可停靠区域左边和右边
       dock1->setFloating(false);
       QTextEdit * edit1 = new QTextEdit();
       edit1->setText(tr("可被移动的标题栏显示在左侧的停靠窗口,但不可以悬浮和关闭"));
       dock1->setWidget(edit1);
       this->addDockWidget(Qt::LeftDockWidgetArea,dock1);
       // (3) 停靠窗口2
       QDockWidget * dock2  = new QDockWidget("DockWindow2",this);
       dock2->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
       QTextEdit * edit2 = new QTextEdit();
       edit2->setText(tr("可悬浮和关闭的窗口,但不可以移动只能双击来实现悬浮"));
       dock2->setWidget(edit2);
       this->addDockWidget(Qt::RightDockWidgetArea,dock2);
       // (4) 停靠窗口3
       QDockWidget * dock3 = new QDockWidget("DockWindow3",this);
       dock3->setFeatures(QDockWidget::AllDockWidgetFeatures);
       QTextEdit * edit3 = new QTextEdit();
       edit3->setText(tr("具有所有特点的窗口"));
       dock3->setWidget(edit3);
       this->addDockWidget(Qt::BottomDockWidgetArea,dock3);

       this->resize(800,600);
       this->setWindowTitle(tr("DockWindow"));
}

MainWindow::~MainWindow()
{
}

