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
protected:
      void run() override;
private:
      static const quint32 mQueryInterval = 300; // 300ms固定查询
      bool mQuit;
      QMutex mMutex;
      QWaitCondition mCond;
      QSerialPort * mPort;
      ResponseProcessor mProcessor;
signals:
      void setRoleValue(SETTINGVARIABLE role,QByteArray value); // 通讯 => this
      void errorCode(TIMEOUTCODE code); // 错误码 => 通讯
      void errorCode(SERIALERROR code);
      void portFixedQueryData(const QList<QByteArray>& data); //  数据 => 通讯
      void portSetQueryData(bool ret,SETTINGVARIABLE role);
};

#endif // SERIALFIXEDQUERY_H
