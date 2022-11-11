#include <tcp/tcp_query.h>

TcpQuery::TcpQuery(QTcpSocket * socket,QObject *parent) : QObject(parent),
      mTcpSocket(socket)
{

        // （1） this => 处理器
        connect(this,&TcpQuery::setRoleValue,&mProcessor,&ResponseProcessor::updateRoleValue);

        // （2）处理器 => this
        connect(&mProcessor,&ResponseProcessor::fixedQuery,this,&TcpQuery::tcpFixedQueryData); // 拆分好的数据
        connect(&mProcessor,&ResponseProcessor::setQuery,this,&TcpQuery::tcpSetQueryData); // bool+role

        // （3）套接字 => this
        connect(mTcpSocket,&QTcpSocket::connected,this,&TcpQuery::connected);
        connect(mTcpSocket,&QTcpSocket::disconnected,this,&TcpQuery::disconnected);

//        connect(mTcpSocket,static_cast<void (QTcpSocket::*)(qint64)>(&QTcpSocket::bytesWritten),this,[=](qint64 bytes){
//            qDebug()<<"当前写入的字节数为 => "<<bytes;
//        });

        qRegisterMetaType<QAbstractSocket::SocketState>("QAbstractSocket::SocketState"); //这句话是必要的否则会提示没有注册过类型
        connect(mTcpSocket,static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketState)>(&QTcpSocket::stateChanged),this,[=](QAbstractSocket::SocketState state){
                  switch (state)
                 {
                     case QAbstractSocket::SocketState::UnconnectedState: emit errorCode(TCPERRORSTATE::UnconnectedState);break;//未连接的时候可能是错误导致的有必要发送此信号让通讯清理资源
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
              emit errorCode(ConnectedState);
              if (mTcpSocket->canReadLine())
              {
                  QByteArray data = mTcpSocket->readAll();
                  //qDebug()<<"原始数据 => "<<data;
                  mProcessor.setData(data);
                  mProcessor.run();
              }
        });
}

// 下边的3个函数都是提供给外部的TCP连接按钮或者断开按钮使用的
void TcpQuery::fixedQuery()
{
        if (mTcpSocket->state() != QAbstractSocket::ConnectedState) return;
        //QMutexLocker locker(&mMutex); // 写入保护
        //mTcpSocket->write(SPICCOMAND::MEAS_VCPR);

        mTcpSocket->write("FETCH:VOLT?;:FETCH:CURR?;:FETCH:POW?\n");
        if (mTcpSocket->waitForBytesWritten(100)) // 请求正常（严格一些100ms必须写入）
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents); // 解决监控界面轻微卡顿现象
            emit errorCode(TIMEOUTCODE::RequestNormal);
            if (mTcpSocket->waitForReadyRead(200)) //  回复正常
            {
                  QCoreApplication::processEvents(QEventLoop::AllEvents); // 解决监控界面轻微卡顿现象
                  emit errorCode(TIMEOUTCODE::ReceiveNormal);
            }
            else {emit errorCode(TIMEOUTCODE::ReceiveTimeout); qDebug()<<"mTcpSocket 回复超时";}// 回复超时
        }
        else
        {
            qDebug()<<"mTcpSocket 请求超时";
            emit errorCode(TIMEOUTCODE::RequestTimeout);
            emit errorCode(TIMEOUTCODE::ReceiveTimeout);
            // 请求超时(如果是请求超时回复自然也超时)
        }
}

void TcpQuery::setQuery(SETTINGVARIABLE role,const QByteArray& value)
{
    if (mTcpSocket->state() != QAbstractSocket::ConnectedState) return;
    QByteArray c = getSetQueryCommand(role,value);
    //QMutexLocker locker(&mMutex);
    mTcpSocket->write(c);
}
