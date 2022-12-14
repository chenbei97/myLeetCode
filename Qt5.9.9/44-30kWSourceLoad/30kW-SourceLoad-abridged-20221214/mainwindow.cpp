#include "mainwindow.h"
#include "communication/communication.h" //在这里避免相互包含

MainWindow::MainWindow(QWidget *parent,LANUAGE lan)
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
       mainCommunication = new Communication(this); // 通讯界面
       mainSettings = new Setting(this); // 设置界面
       mainWorkMode = new WorkModeDialog(mWorkMode,this); // 工作模式设置界面

       createActions(); // 创建动作在前
       createMenus();
       createToolButtons(); // 因为工具按钮要关联创建的动作
       createLayout();
       initConnections();
}

void MainWindow::openMonitor()
{
    int ret = QMessageBox::information(this,tr("消息"),tr("是否已设置电源模式?(默认CV模式)"),
                                                              QMessageBox::Yes,QMessageBox::No);
    if (ret == QMessageBox::No) // 如果没有设置就弹出设置的界面
    {
        // 设置工作模式的界面启动
        int ret = mainWorkMode->exec();
        if (ret == QDialog::Accepted)// 如果点击的是确定按钮
        {
             bool checked = mainWorkMode->isCVMode; // 工作模式点击确定后isCVMode更新过可以用
             mWorkMode = checked?WORKMODE::CV: WORKMODE::CC; // 更新模式
        }
        // 如果是取消按钮,保持原有的状态即可
    }
     if (mainMonitor->workMode() != mWorkMode) // 说明切换了工作模式
     {
          delete mainMonitor;
          mainMonitor = new Monitor(mWorkMode);//新的工作界面,信号连接要重新绑定
          connect(mainCommunication,&Communication::fixedQueryData, mainMonitor,&Monitor::showMeasureState);
          connect(mainCommunication,&Communication::setQueryData,mainMonitor,&Monitor::showSetState);
          connect(mainCommunication,static_cast<void (Communication::*)(TIMEOUTCODE)>(&Communication::errorCode),
                       mainMonitor,&Monitor::setMessageState);
          connect(mainCommunication,static_cast<void (Communication::*)(SERIALERROR)>(&Communication::errorCode),
                       mainMonitor,static_cast<void (Monitor::*)(SERIALERROR)>(&Monitor::setConnectState));
          connect(mainCommunication,static_cast<void (Communication::*)(TCPERRORSTATE)>(&Communication::errorCode),
                       mainMonitor,static_cast<void (Monitor::*)(TCPERRORSTATE)>(&Monitor::setConnectState));
          connect(mainMonitor,&Monitor::setRoleValue,mainCommunication,&Communication::getRoleValue);
          connect(mainSettings,&Setting::selectedPeriod,mainCommunication,&Communication::selectedPeriod);
     }
    mainMonitor->showNormal();
    WorkModeAct->setEnabled(false);// 监控打开时不能再设置工作模式以防出错
    //mainMonitor->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::closeMonitor()
{
      mainMonitor->close(); // 关闭监控界面
      WorkModeAct->setEnabled(true);// 监控关闭时可以设置工作模式
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

