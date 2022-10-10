#include <tcp/tcp_fixedquery.h>

TcpFixedQuery::TcpFixedQuery(QTcpSocket * socket,QObject *parent) : QObject(parent),
      mTcpSocket(socket)
{

        // （1） this => 处理器
        connect(this,&TcpFixedQuery::setRoleValue,&mProcessor,&ResponseProcessor::updateRoleValue);

        // （2）处理器 => this
        connect(&mProcessor,&ResponseProcessor::fixedQuery,this,&TcpFixedQuery::tcpFixedQueryData); // 拆分好的数据
        connect(&mProcessor,&ResponseProcessor::setQuery,this,&TcpFixedQuery::tcpSetQueryData); // bool+role

        // （3）套接字 => this
        connect(mTcpSocket,&QTcpSocket::connected,this,&TcpFixedQuery::connected);
        connect(mTcpSocket,&QTcpSocket::disconnected,this,&TcpFixedQuery::disconnected);

        qRegisterMetaType<QAbstractSocket::SocketState>("QAbstractSocket::SocketState"); //这句话是必要的否则会提示没有注册过类型
        connect(mTcpSocket,static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketState)>(&QTcpSocket::stateChanged),this,[=](QAbstractSocket::SocketState state){
                  switch (state)
                 {
                     case QAbstractSocket::SocketState::UnconnectedState: emit errorCode(TCPERRORSTATE::UnconnectedState);emit disconnected();break;//未连接的时候可能是错误导致的有必要发送此信号让通讯清理资源
                     case QAbstractSocket::SocketState::HostLookupState: emit errorCode(TCPERRORSTATE::HostLookupState); break;
                     case QAbstractSocket::SocketState::ConnectingState: emit errorCode(TCPERRORSTATE::ConnectingState);break;
                     case QAbstractSocket::SocketState::ConnectedState: emit errorCode(TCPERRORSTATE::ConnectedState);break;
                     case QAbstractSocket::SocketState::BoundState: emit errorCode(TCPERRORSTATE::BoundState);break;
                     case QAbstractSocket::SocketState::ClosingState: emit errorCode(TCPERRORSTATE::ClosingState);break;
                     case QAbstractSocket::SocketState::ListeningState: emit errorCode(TCPERRORSTATE::ListeningState);break;
                 }
        });

        qRegisterMetaType<QAbstractSocket::SocketError>("QAbstractSocket::SocketError"); // 同理
        connect(mTcpSocket,static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error), this,[=](QAbstractSocket::SocketError error){
                  switch (error)
                  {
                        case QAbstractSocket::SocketError::ConnectionRefusedError:
                                emit errorCode(TCPERRORSTATE::ConnectionRefusedError);break;
                        case QAbstractSocket::SocketError::RemoteHostClosedError:
                                emit errorCode(TCPERRORSTATE::RemoteHostClosedError);break;
                        case QAbstractSocket::SocketError::HostNotFoundError:
                                emit errorCode(TCPERRORSTATE::HostNotFoundError);break;
                        case QAbstractSocket::SocketError::SocketAccessError:
                                emit errorCode(TCPERRORSTATE::SocketAccessError);break;
                        case QAbstractSocket::SocketError::SocketResourceError:
                                emit errorCode(TCPERRORSTATE::SocketResourceError);break;
                        case QAbstractSocket::SocketError::SocketTimeoutError:
                                emit errorCode(TCPERRORSTATE::SocketTimeoutError);break;
                        case QAbstractSocket::SocketError::DatagramTooLargeError:
                                emit errorCode(TCPERRORSTATE::DatagramTooLargeError);break;
                        case QAbstractSocket::SocketError::NetworkError:
                                emit errorCode(TCPERRORSTATE::NetworkError);break;
                        case QAbstractSocket::SocketError::AddressInUseError:
                                emit errorCode(TCPERRORSTATE::AddressInUseError);break;
                        case QAbstractSocket::SocketError::SocketAddressNotAvailableError:
                                emit errorCode(TCPERRORSTATE::SocketAddressNotAvailableError);break;
                        case QAbstractSocket::SocketError::UnsupportedSocketOperationError:
                                emit errorCode(TCPERRORSTATE::UnsupportedSocketOperationError);break;
                        case QAbstractSocket::SocketError::ProxyAuthenticationRequiredError:
                                emit errorCode(TCPERRORSTATE::ProxyAuthenticationRequiredError);break;
                        case QAbstractSocket::SocketError::SslHandshakeFailedError:
                                emit errorCode(TCPERRORSTATE::SslHandshakeFailedError);break;
                        case QAbstractSocket::SocketError::UnfinishedSocketOperationError:
                                emit errorCode(TCPERRORSTATE::UnfinishedSocketOperationError);break;
                        case QAbstractSocket::SocketError::ProxyConnectionRefusedError:
                                emit errorCode(TCPERRORSTATE::ProxyConnectionRefusedError);break;
                        case QAbstractSocket::SocketError::ProxyConnectionClosedError:
                                emit errorCode(TCPERRORSTATE::ProxyConnectionClosedError);break;
                        case QAbstractSocket::SocketError::ProxyConnectionTimeoutError:
                                emit errorCode(TCPERRORSTATE::ProxyConnectionTimeoutError);break;
                        case QAbstractSocket::SocketError::ProxyNotFoundError:
                                emit errorCode(TCPERRORSTATE::ProxyNotFoundError);break;
                        case QAbstractSocket::SocketError::ProxyProtocolError:
                                emit errorCode(TCPERRORSTATE::ProxyProtocolError);break;
                        case QAbstractSocket::SocketError::OperationError:
                                emit errorCode(TCPERRORSTATE::OperationError);break;
                        case QAbstractSocket::SocketError::SslInternalError:
                                emit errorCode(TCPERRORSTATE::SslInternalError);break;
                        case QAbstractSocket::SocketError::SslInvalidUserDataError:
                                emit errorCode(TCPERRORSTATE::SslInvalidUserDataError);break;
                        case QAbstractSocket::SocketError::TemporaryError:
                                emit errorCode(TCPERRORSTATE::TemporaryError);break;
                        case QAbstractSocket::SocketError::UnknownSocketError:
                                emit errorCode(TCPERRORSTATE::UnknownSocketError);break;
                  }
        });

        connect(mTcpSocket,&QTcpSocket::readyRead,this,[=]{
              emit errorCode(TCPERRORSTATE::ConnectedState);
              mProcessor.setData(mTcpSocket->readAll());
              mProcessor.run();
        });

}

// 下边的3个函数都是提供给外部的TCP连接按钮或者断开按钮使用的
void TcpFixedQuery::fixedQuery()
{
        QMutexLocker locker(&mMutex); // 写入保护
        mTcpSocket->write(SPICCOMAND::MEAS_VCPR);
        if (mTcpSocket->waitForBytesWritten(100)) // 请求正常（严格一些100ms必须写入）
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents); // 解决监控界面轻微卡顿现象
            emit errorCode(TIMEOUTCODE::RequestNormal);
            if (mTcpSocket->waitForReadyRead(300)) //  回复正常（300ms回复了就行宽松一些）
            {
                  QCoreApplication::processEvents(QEventLoop::AllEvents); // 解决监控界面轻微卡顿现象
                  emit errorCode(TIMEOUTCODE::ReceiveNormal);
            }
            else emit errorCode(TIMEOUTCODE::ReceiveTimeout); // 回复超时
        }
        else
        {
            emit errorCode(TIMEOUTCODE::RequestTimeout);
            emit errorCode(TIMEOUTCODE::ReceiveTimeout);
            // 请求超时(如果是请求超时回复自然也超时)
        }
}

void TcpFixedQuery::connectHost(const QString &ip, uint16_t port)
{
        mTcpSocket->connectToHost(ip,port);
        QProgressDialog * dlg = new QProgressDialog(tr("正在尝试连接"),tr("取消连接"),0,400000);
        dlg->setWindowTitle(tr("TCP连接"));
        dlg->setFont(QFont("Times New Roman",12));
        dlg->setFixedSize(400,150);
        dlg->setModal(true);
        dlg->setAutoClose(true);
        dlg->show();

        int i = 1;
        while (mTcpSocket->state() != QAbstractSocket::ConnectedState &&(i<=400000))
        {
             dlg->setValue(i); // 35-45万之间的循环模拟一个进度条,数字太小看不到进度条,太大等待时间有点久
              ++i;
              if (dlg->wasCanceled())
                break;
        }

        if (mTcpSocket->state() != QAbstractSocket::ConnectedState) // 如果还没连上就报错
        {
             QMessageBox::critical(Q_NULLPTR,tr("错误"),mTcpSocket->errorString());
             emit disconnected();
             emit errorCode(TCPERRORSTATE::UnconnectedState);
             return;
        }
        emit errorCode(TCPERRORSTATE::ConnectedState);
        dlg->deleteLater();
}

void TcpFixedQuery::disconnectHost()
{
        mTcpSocket->disconnectFromHost();
        mTcpSocket->close();
        emit errorCode(TCPERRORSTATE::UnconnectedState);
}
