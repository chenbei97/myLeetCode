#include "mainwindow.h"
#include <QListWidget>
#include <QSplitter>
#include <QApplication>

int main(int argc, char *argv[])
{
      QApplication a(argc, argv);
      a.setFont(QFont("Times New Roman",12));

      QSplitter * splitter = new QSplitter(Qt::Horizontal,0); // 水平方向的分割器
      splitter->setOpaqueResize(false);
      splitter->setChildrenCollapsible(true);
      splitter->setWindowTitle("修改用户资料");
      splitter->resize(750,600);
      //splitter->setMinimumSize(splitter->minimumSize()); // 设置最小尺寸为自身大小
      //splitter->setMaximumSize(splitter->maximumSize()); // 设置最大尺寸为自身大小

      QListWidget * listwidget = new QListWidget(splitter);
      listwidget->addItems(QStringList{"基本信息","联系方式","详细资料"});
      listwidget->setFocus(Qt::FocusReason::MouseFocusReason);

      // MainWindow w;
      // w.show();
      MainWindow * window = new MainWindow(splitter); // 不直接显示,顶级父窗口改成splitter
      QObject::connect(listwidget,SIGNAL(currentRowChanged(int)),window->stackWindow,SLOT(setCurrentIndex(int)));
      QObject::connect(window->AmendBtn,SIGNAL(clicked()),splitter,SLOT(hide()));
      QObject::connect(window->CloseBtn,SIGNAL(clicked()),splitter,SLOT(close()));
      splitter->show();
      return a.exec();
}
