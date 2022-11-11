#include <communication/communication.h>

void Communication::initSerialConnections()
{

        mPortFixedQueryTimer->setInterval(mFixedQueryTime);
        mPort->moveToThread(mPortFixedQueryThread);
        mPortSetQueryWorker->moveToThread(mPortSetQueryThread);

        // （1）串口线程 =>this
        connect(mPortFixedQueryThread,SIGNAL(portFixedQueryData(const QList<QByteArray>&)), // 固定查询
                      this,SIGNAL(fixedQueryData(const QList<QByteArray>&)));
        connect(mPortFixedQueryThread,SIGNAL(portSetQueryData(bool,SETTINGVARIABLE)), // 设定查询
                      this,SIGNAL(setQueryData(bool,SETTINGVARIABLE)));
        connect(mPortFixedQueryThread,SIGNAL(errorCode(TIMEOUTCODE)), // 超时错误
                      this,SIGNAL(errorCode(TIMEOUTCODE)));
        connect(mPortFixedQueryThread,static_cast<void (SerialFixedQueryThread::*)(SERIALERROR)>(&SerialFixedQueryThread::errorCode),
            this,[=](SERIALERROR code){ // 串口错误 需要做一定处理不能直接转发,防止传播错误到监控界面
                emit errorCode(code);
                if (code != SERIALERROR::NoError)
                {
                      mPortFixedQueryTimer->stop();
                      PortConfigureBtn->setEnabled(true);
                      PortDisconnectBtn->setEnabled(false);
                      PortConnectBtn->setEnabled(false);//禁用连接,防止用户再次点击连接造成异常退出,重新配置串口设置后才可使用
                      QMessageBox::critical(this, tr("串口打开错误，请检查串口名称是否正确!"), mPort->errorString());
                }
         });

        // （2） this => 串口线程
        connect(this,&Communication::setRoleValue,mPortFixedQueryThread,&SerialFixedQueryThread::setRoleValue);

       // （3）this <=> this
        connect(this,&Communication::updatePortSettings,this,[=]{// 如果串口配置的新参数和上次不一致就立刻更新mPort的属性
                mPort->setPortName(mPortSettings.Name);
                mPort->setBaudRate(mPortSettings.BaudRate);
                mPort->setParity(mPortSettings.Parity);
                mPort->setDataBits(mPortSettings.DataBit);
                mPort->setStopBits(mPortSettings.StopBit);
                mPort->setFlowControl(mPortSettings.FlowControl);
                PortConnectBtn->setEnabled(true);
                PortDisconnectBtn->setEnabled(false);
        });

        connect(mPortFixedQueryTimer,&QTimer::timeout,this,[=]{// 定时器
                mPortFixedQueryThread->startFixedQueryThread(mPort);
        });

        connect(PortConnectBtn,&QPushButton::clicked,this,[=]{ // 按钮
              mCommunicationType = Type::Serial;
              mainWindow->openMonitor();
              mPortFixedQueryTimer->start(); // 只控制定时器不要控制串口,串口在子线程中控制
              PortConnectBtn->setEnabled(false);
              PortDisconnectBtn->setEnabled(true);
              PortConfigureBtn->setEnabled(false);
        });
        connect(PortDisconnectBtn,&QPushButton::clicked,this,[=]{
              mPortFixedQueryTimer->stop(); // 同理
              PortConfigureBtn->setEnabled(true);
              PortConnectBtn->setEnabled(true);
              PortDisconnectBtn->setEnabled(false);
              mainWindow->closeMonitor();
        });
        connect(PortConfigureBtn,&QPushButton::clicked,this,&Communication::on_PortConfigureBtn);

        // （4）其它（串口/TCP共用）
          connect(this,static_cast<void (Communication::*)(SETTINGVARIABLE,const QByteArray&)>(&Communication::getRoleValue),this,
                [=](SETTINGVARIABLE role, const QByteArray& value){ // 监控 =>this
                          switch (mCommunicationType)
                          {
                                case Type::None : break;
                                case Type::Serial:
                                        mPortSetQueryWorker->setVariable(role,value);
                                        emit setRoleValue(role,value);
                                        break;
                                case Type::Tcp:
                                      mTcpFixedQueryWorker->setQuery(role,value);
                                      emit setRoleValue(role,value);
                                      break;
                          }
                    }
          );
}


void Communication::initTcpConnections()
{

      // （1）this=>TCP工作对象
       connect(this,&Communication::setRoleValue,mTcpFixedQueryWorker,&TcpQuery::setRoleValue);

       mTcpFixedQueryTimer->setInterval(mFixedQueryTime);
       mTcpFixedQueryWorker->moveToThread(mTcpFixedQueryThread);

      // （2）TCP工作对象=> this
      connect(mTcpFixedQueryWorker,&TcpQuery::connected,this,[=]{ // 已连接（进行处理）
                QMessageBox::information(this,tr("消息"),tr("TCP通讯已连接!"));
                TCPConnectBtn->setEnabled(false);
                TCPDisconnectBtn->setEnabled(true);
                TCPConfigureBtn->setEnabled(false);
                mainWindow->openMonitor();
        });

      connect(mTcpFixedQueryWorker,&TcpQuery::disconnected,this,[=]{ //未连接（进行处理）
              QMessageBox::information(this,tr("消息"),tr("TCP通讯已断开!"));
              mainWindow->closeMonitor();
              TCPConnectBtn->setEnabled(true);
              TCPDisconnectBtn->setEnabled(false);
              TCPConfigureBtn->setEnabled(true);
              mTcpFixedQueryThread->quit();
              mTcpFixedQueryThread->wait();
      });

      // 来自工作对象处理得到的数据/错误信号等 => 通讯界面的信号
        connect(mTcpFixedQueryWorker,SIGNAL(tcpFixedQueryData(const QList<QByteArray>&)), // (只做转发处理)
                      this,SIGNAL(fixedQueryData(const QList<QByteArray>&)));
        connect(mTcpFixedQueryWorker,SIGNAL(tcpSetQueryData(bool,SETTINGVARIABLE)),
                      this,SIGNAL(setQueryData(bool,SETTINGVARIABLE)));
        connect(mTcpFixedQueryWorker,SIGNAL(errorCode(TIMEOUTCODE)),
                      this,SIGNAL(errorCode(TIMEOUTCODE)));
        connect(mTcpFixedQueryWorker,SIGNAL(errorCode(TCPERRORSTATE)),
                      this,SIGNAL(errorCode(TCPERRORSTATE)));

       // （3）this <=> this
        connect(mTcpFixedQueryTimer,&QTimer::timeout,this,[=]{ // 定时器
                mTcpFixedQueryWorker->fixedQuery();
        });
        connect(TCPConnectBtn,&QPushButton::clicked,this,[=]{ // 按钮
              mTcpSocket->abort();
              mCommunicationType = Type::Tcp;
              mTcpSocket->connectToHost(mHostName,mHostPort);
              mTcpFixedQueryThread->start();
              mTcpFixedQueryTimer->start();
        });
        connect(TCPDisconnectBtn,&QPushButton::clicked,this,[=]{
            mTcpSocket->disconnectFromHost();
            mTcpFixedQueryTimer->stop();
        });
        connect(TCPConfigureBtn,&QPushButton::clicked,this,&Communication::on_TCPConfigureBtn);
}
