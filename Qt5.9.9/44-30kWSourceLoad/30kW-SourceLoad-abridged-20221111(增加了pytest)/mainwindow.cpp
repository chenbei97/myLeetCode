#include "mainwindow.h"
#include "communication/communication.h" //在这里避免相互包含

MainWindow::MainWindow(QWidget *parent,Lanuage lan)
  : QDialog(parent) , mLanuage(lan)
{
       setMinimumSize(QSize(600,200));
       setFont(QFont("Times New Roman",12));
       setWindowIcon(QIcon(":/images/dahua.png"));
       setWindowTitle(tr("30kW双向电源上位机"));
       setWindowFlag(Qt::Window);
       setWindowFlag(Qt::WindowStaysOnTopHint);//保持在前, http://t.zoukankan.com/linuxAndMcu-p-11533636.html
       setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);//添加最大最小化按钮

       mWorkMode = WORKMODE::CV;// 默认工作模式CV
       mainMonitor = new Monitor(mWorkMode,this); // 监控界面(关掉主窗口监控界面也要关掉所以基于this)
       mainCommunication = new Communication(this); // 同理要基于this

       createActions(); // 创建动作在前
       createMenus();
       createToolButtons(); // 因为工具按钮要关联创建的动作
       createLayout();
       initConnections();
}

void MainWindow::openMonitor()
{
      on_MonitorInterfaceAct(); // 打开监控界面
}

void MainWindow::closeMonitor()
{
      mainMonitor->close(); // 关闭监控界面
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
      Q_UNUSED(e);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *e)
{
      Q_UNUSED(e);
      QMenu * menulist = new QMenu(this);
      menulist->addAction(BasicSettingsAct);
      menulist->addSeparator();
      menulist->addAction(CommunicationAct);
      menulist->exec(QCursor::pos());
}

