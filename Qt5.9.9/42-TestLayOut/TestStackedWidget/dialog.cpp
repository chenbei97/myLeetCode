#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
  : QDialog(parent) // 必须是QDialog,如果是MainWindow布局会有问题不显示
{
      // (1)垂直布局
      QVBoxLayout * vlayout = new QVBoxLayout;
      // (1.1)垂直布局组件1
      listwidget = new QListWidget;
      listwidget->insertItem(0,tr("Window1")); // 插入3个条目
      listwidget->insertItem(1,tr("Window2"));
      listwidget->insertItem(2,tr("Window3"));
      // (1.2) 垂直布局组件2
      combo = new QComboBox;
      QStringList list;
      list << "Window1"<<"Window2"<<"Window3";
      combo->addItems(list);
      vlayout->addWidget(listwidget);
      vlayout->addWidget(combo);

      // (2)水平布局
      QHBoxLayout * hlayout = new QHBoxLayout;
      //(2.1) 垂直布局整体作为水平布局的一部分
      hlayout->addLayout(vlayout,2);
      // (2.2) 堆叠窗口作为组件
      stack = new QStackedWidget;
      label1 = new QLabel(tr("TestWindow1"));
      label2 = new QLabel(tr("TestWindow2"));
      label3 = new QLabel(tr("TestWindow3"));
      stack->addWidget(label1);
      stack->addWidget(label2);
      stack->addWidget(label3);
      hlayout->setMargin(10); // 水平布局到窗口周边的距离
      hlayout->setSpacing(5);
      hlayout->addWidget(stack,0,Qt::AlignHCenter);
      //hlayout->setStretchFactor(stack,3); // 指定组件指针
      hlayout->setStretch(1,3); // 指定位置也可以


      connect(combo,SIGNAL(currentIndexChanged(int)),stack,SLOT(setCurrentIndex(int)));
      connect(listwidget,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
      this->setLayout(hlayout);
      this->resize(400,200);
      this->setWindowTitle(tr("StackedWindows"));
}

MainWindow::~MainWindow()
{

}

