#include "../../inc/tcp/tcpassembler.h"

TcpAssembler::TcpAssembler(QObject *parent) : QObject(parent)
{

}

void TcpAssembler::assemble(const QString&frame,const QVariantMap &m)
{
    QMutexLocker locker(&mutex);
    //LOG<<"current assemble thread is "<<QThread::currentThread();
    auto json = TcpAssembleFunctions[frame](m);
    //LOG<<"assemble's message is "<<json;
    emit assembleResult(json);
}
