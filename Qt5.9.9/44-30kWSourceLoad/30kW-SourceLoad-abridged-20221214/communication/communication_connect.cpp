#include <communication/communication.h>

void Communication::initSerialConnections()
{
        // （1）串口固定查询线程的固定查询数据、设定查询数据、错误 =>通讯界面
        // 注：写入查询是2个线程分别对串口写入命令，但是处理数据是同时完成的，依据情况返回2类数据，所以串口查询线程有2个数据信号
        connect(mPortFixedQueryThread,static_cast<void (SerialFixedQueryThread::*)(const QList<QByteArray>&)>(&SerialFixedQueryThread::portFixedQueryData),
                this,[=](const QList<QByteArray>& data){
                emit fixedQueryData(data); //一方面数据转发给监控界面,另一方面定时器每执行mLogPeriodRate次(此时mLogExec=true)要打1次log
                if (mLogExec) {
                    QByteArray now = QDateTime::currentDateTime().toString("yyyy/MM/dd-hh::mm::ss").toLocal8Bit();
                     mLogExec = !mLogExec;
                     QList<QByteArray> logData;
                     logData << now << data;
                     //qDebug()<<"log data = " << logData <<" size = "<<logData.size();
                     emit log(logData);//转发给设置再到表格
                }

                // 可以在processor处理然后在那取出数据,但这样需要先从this传递log到线程再到processor就很麻烦
                // 考虑到timeout执行的次数最终和portFixedQueryData执行的次数是同步的,所以可以在processor的出口取出数据就可以了
               // 信号的流程是mPortFixedQueryThread->startFixedQueryThread => processor's portFixedQueryData => communication's fixedQueryData
        });
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

        // （2） 通讯界面的设定查询角色和值信号 => 串口固定查询线程
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

        connect(mPortFixedQueryTimer,&QTimer::timeout,this,[=]{
                mPortFixedQueryThread->startFixedQueryThread(mPort);// 定时器开启固定查询线程
                ++mLogHandle;
                if (mLogHandle == mLogMultiple) // 如果通讯中途改变了mLogMultiple不会起作用,断开重新连接才起作用
                {
                    mLogHandle = 0;
                    mLogExec = !mLogHandle;
                }
        });

        connect(PortConnectBtn,&QPushButton::clicked,this,[=]{ // 串口连接按钮
                  mCommunicationType = Type::Serial; // 更新通讯类型
                  mainWindow->openMonitor(); // 打开监控器
                  mPortFixedQueryTimer->start(); // 控制定时器,不要直接控制串口,串口在子线程中控制
                  PortConnectBtn->setEnabled(false);
                  PortDisconnectBtn->setEnabled(true);
                  PortConfigureBtn->setEnabled(false);
        });
        connect(PortDisconnectBtn,&QPushButton::clicked,this,[=]{// 串口断开连接按钮
                  mPortFixedQueryTimer->stop(); // 同理
                  mLogHandle = 0;
                  mLogExec = false;
                  PortConfigureBtn->setEnabled(true);
                  PortConnectBtn->setEnabled(true);
                  PortDisconnectBtn->setEnabled(false);
                  mainWindow->closeMonitor();
        });
        connect(PortConfigureBtn,&QPushButton::clicked,this,&Communication::on_PortConfigureBtn);

        // （4）其它（USB/TCP共用同一个getRoleValue信号获取设定角色和值,但是执行的工作对象不同,才引入了mCommunicationType）
          connect(this,static_cast<void (Communication::*)(SETTINGVARIABLE,const QByteArray&)>(&Communication::getRoleValue),this,
                [=](SETTINGVARIABLE role, const QByteArray& value){ // 监控 =>this
                          switch (mCommunicationType)
                          {
                                case Type::None : break;
                                case Type::Serial:
                                        mPortSetQueryWorker->setQuery(role,value); // usb的设定查询工作对象是独立的
                                        emit setRoleValue(role,value);
                                        break;
                                case Type::Tcp:
                                      mTcpQueryWorker->setQuery(role,value); // tcp的固定和设定查询都是同1个
                                      emit setRoleValue(role,value);
                                      break;
                          }
                    }
          );
}


void Communication::initTcpConnections()
{

      // （1）this=>TCP工作对象
       connect(this,&Communication::setRoleValue,mTcpQueryWorker,&TcpQuery::setRoleValue);

      // （2）TCP工作对象=> this
      connect(mTcpQueryWorker,&TcpQuery::connected,this,[=]{ // 已连接（进行处理）
                    QMessageBox::information(this,tr("消息"),tr("TCP通讯已连接!"));
                    TCPConnectBtn->setEnabled(false);
                    TCPDisconnectBtn->setEnabled(true);
                    TCPConfigureBtn->setEnabled(false);
                    mainWindow->openMonitor();
        });

      connect(mTcpQueryWorker,&TcpQuery::disconnected,this,[=]{ //未连接（进行处理）
                  QMessageBox::information(this,tr("消息"),tr("TCP通讯已断开!"));
                  mainWindow->closeMonitor();
                  TCPConnectBtn->setEnabled(true);
                  TCPDisconnectBtn->setEnabled(false);
                  TCPConfigureBtn->setEnabled(true);
                  mTcpQueryThread->quit();
                  mTcpQueryThread->wait();
      });

      // 来自工作对象处理得到的数据/错误信号等 => 通讯界面的信号
        connect(mTcpQueryWorker,static_cast<void (TcpQuery::*)(const QList<QByteArray>&)>(&TcpQuery::tcpFixedQueryData),
                this,[=](const QList<QByteArray>& data){
                emit fixedQueryData(data); //一方面数据转发给监控界面,另一方面定时器每执行mLogPeriodRate次(此时mLogExec=true)要打1次log
                if (mLogExec) {
                    QByteArray now = QDateTime::currentDateTime().toString("yyyy/MM/dd-hh::mm::ss").toLocal8Bit();
                     mLogExec = !mLogExec;
                     QList<QByteArray> logData;
                     logData << now << data;
                     //qDebug()<<"log data = " << logData <<" size = "<<logData.size();
                     emit log(logData);//转发给设置再到表格
                }
        });
        connect(mTcpQueryWorker,SIGNAL(tcpSetQueryData(bool,SETTINGVARIABLE)),
                      this,SIGNAL(setQueryData(bool,SETTINGVARIABLE)));
        connect(mTcpQueryWorker,SIGNAL(errorCode(TIMEOUTCODE)),
                      this,SIGNAL(errorCode(TIMEOUTCODE)));
        connect(mTcpQueryWorker,SIGNAL(errorCode(TCPERRORSTATE)),
                      this,SIGNAL(errorCode(TCPERRORSTATE)));

       // （3）this <=> this
        connect(mTcpQueryTimer,&QTimer::timeout,this,[=]{ // 定时器
                mTcpQueryWorker->fixedQuery();
                ++mLogHandle;
                if (mLogHandle == mLogMultiple)
                {
                    mLogHandle = 0;
                    mLogExec = !mLogHandle;
                }
        });
        connect(TCPConnectBtn,&QPushButton::clicked,this,[=]{ // 按钮
                  mTcpSocket->abort();
                  mCommunicationType = Type::Tcp;
                  mTcpSocket->connectToHost(mHostName,mHostPort);
                  mTcpQueryThread->start();
                  mTcpQueryTimer->start();
        });
        connect(TCPDisconnectBtn,&QPushButton::clicked,this,[=]{
                mTcpSocket->disconnectFromHost();
                mTcpQueryTimer->stop();
                mLogHandle = 0;
                mLogExec = false;
        });
        connect(TCPConfigureBtn,&QPushButton::clicked,this,&Communication::on_TCPConfigureBtn);
}
