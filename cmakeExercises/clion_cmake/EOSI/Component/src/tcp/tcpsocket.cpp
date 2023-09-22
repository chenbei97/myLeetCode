#include "../../inc/tcp/tcpsocket.h"

void TcpSocket::onReadyReadSlot()
{
    while (socket->bytesAvailable()) {
        QByteArray msg = socket->readAll();
        messageQueue.enqueue(msg); // 将消息添加到队列中
        //LOG<<"queue before = "<<messageQueue;
        processQueueMessage(); // 处理队列中的消息
       //LOG<<"queue after = "<<messageQueue;
   }
}

void TcpSocket::processQueueMessage()
{
    if (!messageQueue.isEmpty()) {
       message = messageQueue.head();

       controller->parse(frame,message);
       messageQueue.dequeue(); // 从队列中取出消息
   }

    //data[frame] = controller->result(); // 此行代码流程上优先于parse的异步处理,所以总是invalid
    // 所以不要在这里把结果直接取出来,而应该借助异步信号来赋值
    // exec在顺序执行的时候,data[frame]已经被异步的改变了,实际上已经同步
}

void TcpSocket::onParseFinished(const QVariant &d)
{
    data[frame] = d;
}

QVariant TcpSocket::result() const
{ // 拿到结果,例如0x0001应该返回图像路径
    auto res = data.find(frame); // command可能没被赋值
    if (res == data.end()) return "";
    return *res;
}

QString TcpSocket::lastError() const
{
    return  TcpErrorStrings[mLastErrorCode];
}

void TcpSocket::write(QByteArray d)
{
    socket->write(d);
}

TcpErrorCode TcpSocket::exec(const QString& f,const QByteArray& c)
{
        //LOG<<"current socket's thread is "<<QThread::currentThread();

        // 0. 每次发送都要检查连接是否已连接
        if (!isConnected()) {
            mLastErrorCode = UnConnectedErrorCode;
            return mLastErrorCode;
        }


        //  1. 数字帧头是否有错误,静态命令列表搜索
        if (f.isEmpty() || !TcpParseFunctions.keys().contains(f)){
            mLastErrorCode = RequestFrameErrorCode;
            return mLastErrorCode;
        }

        frame = f;
        command = c; // 当前要执行的命令

        // 2. 请求是否有错误
        QEventLoop loop1;
        QTimer timer1;
        timer1.setSingleShot(true);
        connect(&timer1, &QTimer::timeout, &loop1,&QEventLoop::quit); // 写入超时或写入成功都要停止事件循环
        connect(socket,&QTcpSocket::bytesWritten,&loop1,&QEventLoop::quit);
        //LOG<<"socket is write "<<c;
        socket->write(c);
        timer1.start(SocketWaitTime); // 等待3s
        loop1.exec(); // 如果没有写入成功会一直阻塞

        if (!detectConnectionState()) {//  loop1结束要检测下连接状态
            mLastErrorCode = UnConnectedErrorCode;
            return mLastErrorCode;
        }

        if (!timer1.isActive())  {// 请求超时
            mLastErrorCode = SocketRequestErrorCode;
            return mLastErrorCode;
        }

        // 3. 回复是否有错误
        QEventLoop loop2;
        QTimer timer2;
        timer2.setSingleShot(true);
        connect(&timer2, &QTimer::timeout, this,[&]{
                data[frame] = ""; // 如果超时要清空上次数据,没超时,数据已被更新不需要清空
                loop2.quit(); // 限制没收到消息超时指定时间退出
            });

        connect(socket,&QTcpSocket::readyRead,&loop2,&QEventLoop::quit);
        timer2.start(SocketWaitTime );
        loop2.exec(); // 同步执行

        if (!detectConnectionState()) {//  loop2结束要检测下连接状态
            mLastErrorCode = UnConnectedErrorCode;
            return mLastErrorCode;
        }

        if (!timer2.isActive()){// 回复超时
            mLastErrorCode = SocketResponseErrorCode;
            return mLastErrorCode;
        }

        // loop2收到消息就开始异步解析数据
        // 但是由于顺序执行以下代码先执行,所以需要一个阻塞同步解析结果

//        QEventLoop loop; // 这段代码已经移动到TcpDealController实现了
//        connect(controller,&TcpDealController::parseFinished,&loop,&QEventLoop::quit);
//        loop.exec(); // 这样不管用,实际上parseFinished在exec之前就已经发出
        // 异步信号来退出时间循环,要求异步信号同时也把data更新了,不要在onReadyReadSlot()直接拿结果没有用


        // 这里已经根据异步信号完成了同步
        //LOG<<"data["<<frame<<"] = "<<data[frame];


        if (!detectConnectionState()) {//  loop2结束要检测下连接状态
            mLastErrorCode = UnConnectedErrorCode;
            return mLastErrorCode;
        }

        if (data[frame].isNull()) {// 不一定是错误,有的就是没有数据回复
            mLastErrorCode = EmptyDataErrorCode;
            return mLastErrorCode;
        }
        else {
            auto text = data[frame].toString();// 如果是错误码转换成string不会失败
            auto index = TcpErrorStrings.indexOf(text); // 是错误码index>=0
            //LOG<<"data = "<<text<<" index = "<<index;
            if (index < 0) {
                mLastErrorCode = NoErrorCode;
                return mLastErrorCode;
            }
            else {
                mLastErrorCode = TcpErrorCode(index);
                return mLastErrorCode;
            }
        }

        mLastErrorCode = NoErrorCode;
        return NoErrorCode;
}

TcpSocket::TcpSocket(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    controller = new TcpDealController(this);
    connect(socket,&QTcpSocket::readyRead,this,&TcpSocket::onReadyReadSlot);
    connect(socket,&QTcpSocket::connected,this,&TcpSocket::connected);
    connect(socket,&QTcpSocket::disconnected,this,&TcpSocket::disconnected);
    connect(controller,&TcpDealController::parseFinished,this,&TcpSocket::onParseFinished);
}

void TcpSocket::connectToHost(const QString &hostName, quint16 port,QIODevice::OpenMode openMode)
{
    socket->connectToHost(hostName,port,openMode);
}

void TcpSocket::disconnectFromHost()
{
    socket->disconnectFromHost();
}

bool TcpSocket::waitForConnected(int msecs)
{
    return socket->waitForConnected(msecs);
}

qintptr TcpSocket::socketDescriptor() const
{
    return socket->socketDescriptor();
}

bool TcpSocket::isConnected() const
{
    return socket->state() == QTcpSocket::ConnectedState;
}

bool TcpSocket::detectConnectionState()
{
    if (!isConnected()) {
        QMessageBox::critical(nullptr,tr("错误"),tr("检测到套接字意外退出连接!"),QMessageBox::Ok);
        return false;
    }
    return true;
}

TcpSocket::~TcpSocket()
{
    if(socket) {
        socket->disconnectFromHost();
        socket->close();
        delete socket;
        socket = nullptr;
    }
}
