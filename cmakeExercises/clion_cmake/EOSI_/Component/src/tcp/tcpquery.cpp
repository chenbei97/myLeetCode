#include "../../inc/tcp/tcpquery.h"

TcpQuery::TcpQuery(QObject *parent) : QObject(parent)
{
    socket = TcpLoader::instance().mSocket;
    mErrorCode = NoErrorCode; // 先初始化否则parseFinished的首次调用导致越界
    autoreconnect = true;
    Q_ASSERT(socket!=0);
    connect(socket,&TcpSocket::connected,this,&TcpQuery::connected);
    connect(socket,&TcpSocket::disconnected,this,&TcpQuery::disconnected);
}

bool TcpQuery::exec(const QString& f,const QByteArray& c)
{
    LOG <<"request msg = "<<c;
    mErrorCode =  socket->exec(f,c); // 执行完已经同步结果,再发送信号
    if (f  == TcpFramePool.frame0x0000 && mErrorCode == EmptyDataErrorCode)
        mErrorCode = NoErrorCode; // 对于0x0000命令,不会返回任何数据,空数据不是错误
    //LOG<<"error = "<<errorString();
    emit parseResult(result());
    emit parseError(errorString());
    emit parseError(errorCode());

    if (!haveError()) return true;

    if (needReconnect(f,c)) // 先处理掉线错误,重连失败返回false
        return false;

    if (needRepeat()) { // 再处理要求重发,每次重发也要检测是否是断开错误
        unsigned int i = 0;
        while (needRepeat() && i < 3) {
            LOG<<"正在重发 "<<c<<" 第"<<i+1<<"次";
            mErrorCode = socket->exec(f,c);
            if (needReconnect(f,c)) // 先处理掉线错误
                return false;
            ++i;
        }
        if (i == 3) {
            mErrorCode = MultipleRetransmissionErrorCode;
            //LOG<<"多次重发错误 ";
        }
    }

    return !haveError();
}

void TcpQuery::setAutoConnect(bool e)
{// 此函数是为了解决启动连接失败时不显示登录窗口直接显示是否重连的对话框问题
    // 希望不出现对话框,就要设置不要自动重连,提早返回显示登陆界面
    autoreconnect = e;
}

bool TcpQuery::needReconnect(const QString& f,const QByteArray& c)
{ // 重连错误的处理
    if  (mErrorCode == UnConnectedErrorCode)
    {
        if (!autoreconnect)  // 不使用自动重连,返回true,让TcpQuery::exec返回false
            return true;
         int recnt = reconnect();
         LOG<<"reconnect's count = "<<recnt;
         if (socket->isConnected())
            mErrorCode = socket->exec(f,c);
         else {
             if (recnt >= 5)
                 mErrorCode = MultipleUnConnectedErrorCode;
             else if (recnt < 0)
                 mErrorCode = QuitReconnectErrorCode; // 主动退出重连
             return true; // 没连上说明还是需要重连返回true
         }
    }
    return false;
}

QVariant TcpQuery::result() const
{// 没有错误时调用本函数才有意义
    if (mErrorCode != NoErrorCode) return QVariant();
    return socket->result();
}

QString TcpQuery::errorString() const
{
    return TcpErrorStrings[mErrorCode];
}

TcpErrorCode TcpQuery::errorCode() const
{
    return mErrorCode;
}

bool TcpQuery::haveError() const
{
    return mErrorCode != NoErrorCode;
}

bool TcpQuery::needRepeat() const
{ // 下位机返回的repeat字段为1时,上位机将其解析为ReceiveResponseErrorCode
    return mErrorCode == ReceiveResponseErrorCode;
}
