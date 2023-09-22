#include "../../inc/tcp/tcpdealer.h"

void TcpDealer::parse(const QString&f,const QByteArray &msg)
{
    QMutexLocker locker(&mutex);

    //LOG<<"current parse thread is "<<QThread::currentThread();
    d.clear();

    JsonReadWrite m;
    m.parseJson(msg);
    auto map = m.map();

//    long long i = 0; // 模拟计算量很大 loop exec 和 parsed finshed之间存在延迟
//    qDebug()<<i;
//    while (i <5000000000) { i++;}
//    qDebug()<<i;

    LOG<<"response msg = "<<msg;

    if (map.isEmpty()) { // 不排除解析的json格式有问题无法解析
        d = ResponsetJsonFormatError;
        emit parseFinished(d);
        return;
    }

    auto keys = map.keys();

    if (!keys.contains(FrameField)){
        d = FrameFieldMissedError;
        emit parseFinished(d);

        return;
    }

    if (!keys.contains(RepeatField)) {
        d = RepeatFieldMissedError;
        emit parseFinished(d);
        return;
    }

    auto frame = map[FrameField].toString(); // 返回消息的帧

    if (f != frame ) {// 返回和发送帧不等
        d = ResponseFrameError;
        emit parseFinished(d);
        return;
    }

    if (map[RepeatField].toUInt()) { // 需要重发
        d = ReceiveResponseError; // repeat= 1
        emit parseFinished(d);
        return;
    }

    d = TcpParseFunctions[frame](map); // 调用函数指针解析
    emit parseFinished(d);

    //LOG<<"parsed is finished";
}

TcpDealer::TcpDealer(QObject *parent) : QObject(parent)
{
}


