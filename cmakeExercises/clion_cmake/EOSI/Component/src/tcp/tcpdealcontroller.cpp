#include "../../inc/tcp/tcpdealcontroller.h"

TcpDealController::TcpDealController(QObject *parent) : QObject(parent)
{
    //LOG<<"deal controller's thread is "<<QThread::currentThread();
    dealer = new TcpDealer;
    dealer->moveToThread(&dealerthread);

    //connect(&dealerthread, &QThread::finished, dealer, &QObject::deleteLater);
    connect(this,&TcpDealController::parse,dealer,&TcpDealer::parse);
    connect(this,&TcpDealController::parse,this,[&]{loop.exec();}); // 开始解析就进入时间循环等待同步
    connect(dealer,&TcpDealer::parseFinished,this,&TcpDealController::parseFinished);
    connect(this,&TcpDealController::parseFinished,&loop,&QEventLoop::quit);

    // 异步信号来退出时间循环,要求异步信号同时也把data更新了,不要在onReadyReadSlot()直接拿结果没有用
    dealerthread.start();
}

TcpDealController::~TcpDealController()
{
    dealerthread.quit();
    dealerthread.wait();
}

