#include "mainwindow.h"
#include <QSplitter>
#include <QTextEdit>
#include <QListView>
#include <QTreeView>
#include <QTableView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
      QSplitter *  mainsplitter =  new QSplitter(Qt::Horizontal,this); // 父窗口为this
      QListView * listview = new QListView(mainsplitter);
      QTreeView * treeview = new QTreeView;
      mainsplitter->addWidget(treeview);

      QSplitter * rightsplitter = new QSplitter(Qt::Vertical,mainsplitter);
      QTextEdit * textEdit = new QTextEdit("hello qt!",rightsplitter);
      textEdit->setAlignment(Qt::AlignCenter);
      QTableView * tableview = new QTableView(rightsplitter);
      Q_UNUSED(listview);
      Q_UNUSED(tableview);

      mainsplitter->setOpaqueResize(false);
      mainsplitter->setHandleWidth(10); // 拆分器的宽度
      mainsplitter->setChildrenCollapsible(false); // 不允许部件宽度压缩到0
      mainsplitter->setStretchFactor(1,2); // 设置treeview的拉伸因子
      this->setCentralWidget(mainsplitter);
      int min = 0 ,max = 0;
      mainsplitter->getRange(1,&min,&max); // 获取第1个部件的范围,第0个总是0,0
      qDebug()<<"treeView的水平范围："<<min<<" "<<max;
      qDebug()<<"treeView的index："<<mainsplitter->indexOf(treeview);
      qDebug()<<"部件个数："<<mainsplitter->count();
}

MainWindow::~MainWindow()
{
}

