#include "../../inc/tcp/tcpassemblercontroller.h"

TcpAssemblerController::TcpAssemblerController(QObject *parent) : QObject(parent)
{
    //LOG<<"assemble controller's thread is "<<QThread::currentThread();
    loop = new QEventLoop;
    assembler = new TcpAssembler;
    assembler->moveToThread(&assemblethread);
    connect(this,&TcpAssemblerController::assemble,assembler,&TcpAssembler::assemble);
    connect(this,&TcpAssemblerController::assemble,this,[&]{loop->exec();});//组装时同步等待异步的assembleFinished
    connect(assembler,&TcpAssembler::assembleResult,this,[&](const QByteArray& m){msg=m;emit assembleFinished();});

    connect(this,&TcpAssemblerController::assembleFinished,loop,&QEventLoop::quit);
    assemblethread.start();
}

QByteArray TcpAssemblerController::message() const
{
    return msg;
}

TcpAssemblerController::~TcpAssemblerController()
{
    assemblethread.quit();
    assemblethread.wait();
}
