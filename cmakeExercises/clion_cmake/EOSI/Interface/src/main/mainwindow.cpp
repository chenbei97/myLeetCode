#include "../../inc/main/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    auto db = QSqlDatabase::addDatabase("QMYSQL","mysql");
//    db.setPort(3306);
//    db.setUserName("root");
//    db.setHostName("127.0.0.1");
//    db.setPassword("199791");
//    db.setDatabaseName("eosi");
//    db.open();
    QString rccpath = QDir::currentPath()+"/images.rcc";
    QResource::registerResource(rccpath);
    QMenu * menu1 = new QMenu(tr("文件"));
    QMenu * menu2 = new QMenu(tr("分析"));
    QMenu * menu3 = new QMenu(tr("帮助"));
    QMenu * menu4 = new QMenu(tr("其它"));
    auto act41 = menu4->addAction(tr("版本"));
    auto act42 = menu4->addAction(tr("语言"));
    auto act43 = menu4->addAction(tr("退出"));

    auto menubar = new QMenuBar;
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);
    menubar->addMenu(menu4);
    setMenuBar(menubar);

    connect(act43,&QAction::triggered,this,&MainWindow::close);

    mTab = new QTabWidget(this);
    mScanPanel = new ScanLoad(this);
    mQueryPanel = new SqlQueryConsole(this);

    www = new GradientHiddenWidget;
    mTab->addTab(mScanPanel,tr("创建实验"));
    mTab->addTab(mQueryPanel,tr("查询实验"));
    mTab->addTab(www,tr("当前实验"));

    setCentralWidget(mTab);
    INIT_FONT;
    INIT_WINDOW_MINSIZE;

    connect(&mCheckConnectedTimer,&QTimer::timeout,this,&MainWindow::onCheckConnectedState);
    mCheckConnectedTimer.start(SocketCheckFrequency);
}

void MainWindow::onCheckConnectedState()
{ // 后台定时检查套接字的连接状态
    if (!TcpLoaderPointer->isConnected())
    {
        QMessageBox::information(this,tr("消息"),tr("主机意外退出!"),QMessageBox::Ok);
        setEnabled(false);
        reconnect(this); // 尝试重连
     } else setEnabled(true);
}

void MainWindow::setStyle(QCString filename)
{
    QFile f(filename);
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&f);
    auto style = ts.readAll();
    setStyleSheet(style);
    mScanPanel->setStyle(style);
}

void MainWindow::setLoginIP(QCString ip)
{
    mLoginIP = ip;
    LOG<<"login's ip is "<<mLoginIP;
}

void MainWindow::setLoginUser(QCString user)
{ // 传递给数据库用的,只显示当前用户
    LOG<<"login's user is "<<user;
    mQueryPanel ->setCurrentUser(user);
    mScanPanel->setCurrentUser(user);
}

