#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QDialog(parent)
{
       this->mainMonitor = nullptr; // 这是必要的,否则在monitoring.cpp中的判断是否为空会出错
       this->mWorkMode = WORKMODE::CV;// 默认工作模式CV
       this->setMinimumSize(QSize(800,400));
       this->setFont(QFont("Times New Roman",12));
       this->setWindowFlag(Qt::WindowStaysOnTopHint);//保持在前, http://t.zoukankan.com/linuxAndMcu-p-11533636.html
       this->setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);//添加最大最小化按钮
       this->createActions(); // 创建动作在前
       this->createMenus();
       this->createToolButtons(); // 因为工具按钮要关联创建的动作
       this->createToolLabels();
       this->createLayout();
       this->initConnections();
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
      MenuBar->setGeometry(QRect(0,0,e->size().width(),30));
}

void MainWindow::paintEvent(QPaintEvent *e)
{
      // 绘图开始的左上角顶点的X坐标是0，Y坐标应该是菜单栏的高度30
      int x = 0;
      int y = MenuBar->height();
      int height = this->height()- y; //要绘制的高度
      int width = this->width(); // 要绘制的宽度
      QRect rect(x,y,width,height);
      QPixmap pix;
      pix.load(":/images/DH.png");
      QPainter painter; // 不要使用指针的方式,new出来的无法销毁
      painter.begin(this);
      painter.setOpacity(0.2);
      painter.setRenderHint(QPainter::SmoothPixmapTransform);
      painter.drawPixmap(rect,pix);
      painter.end();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *e)
{
      Q_UNUSED(e);
      QMenu * menulist = new QMenu(this);
      //menulist->addMenu(MenuSettings);
      menulist->addAction(SystemSettingsAct);
      menulist->addSeparator();
      menulist->addAction(BasicSettingsAct);
      menulist->addSeparator();
      menulist->addAction(UserSettingsAct);
      //menulist->addMenu(MenuFunctions);
      menulist->addSeparator();
      //menulist->addMenu(MenuAbout);
      menulist->addAction(ProtectiveFunctionAct);
      menulist->addSeparator();
      menulist->addAction(FunctionGeneratorAct);
      menulist->addSeparator();
      menulist->addAction(CommunicationAct);
      menulist->addSeparator();
      menulist->addAction(AboutCNAct);
      menulist->addSeparator();
      menulist->addAction(AboutENAct);
      menulist->exec(QCursor::pos());
}

