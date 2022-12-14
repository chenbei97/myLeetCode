#ifndef SERIALFIXEDQUERY_H
#define SERIALFIXEDQUERY_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QSerialPort>
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <core/spic_command.h>
#include <core/enum.h>
#include <core/data_processing.h>

using namespace SPICCOMAND;
class SerialFixedQueryThread : public QThread
{
      Q_OBJECT
public:
      explicit SerialFixedQueryThread(QObject * parent = Q_NULLPTR);
      ~SerialFixedQueryThread();
      void startFixedQueryThread(QSerialPort * port);
private:
      void run() override;
      static const quint32 mQueryInterval = 300; // 300ms固定查询
      bool mQuit;
      QMutex mMutex;
      QWaitCondition mCond;
      QSerialPort * mPort;
      ResponseProcessor mProcessor;
signals:
      void setRoleValue(SETTINGVARIABLE role,QByteArray value); // 通讯 => this 告知要设定的角色和设定的值
      void portFixedQueryData(const QList<QByteArray>& data); //  固定查询得到的数据 => 通讯
      void portSetQueryData(bool ret,SETTINGVARIABLE role);// 设定查询 => 通讯
      void errorCode(TIMEOUTCODE code); // 错误码 => 通讯
      void errorCode(SERIALERROR code);
};

#endif // SERIALFIXEDQUERY_H
