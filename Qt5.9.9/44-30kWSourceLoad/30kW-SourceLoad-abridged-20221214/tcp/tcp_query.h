#ifndef TCPFIXEDQUERY_H
#define TCPFIXEDQUERY_H

#include <QObject>
#include <QTcpSocket>
#include <QMessageBox>
#include <QMutex>
#include <QMutexLocker>
#include <QCoreApplication>
#include <QProgressDialog>
#include <QProgressBar>
#include <core/data_processing.h>
#include <core/spic_command.h>
#include <QDebug>

using namespace  SPICCOMAND;

class TcpQuery : public QObject
{
      Q_OBJECT
public:
      explicit TcpQuery(QTcpSocket * socket,QObject *parent = Q_NULLPTR);
      void fixedQuery(); // 提供给外部固定查询
      void setQuery(SETTINGVARIABLE role,const QByteArray& value); // 提供给外部设定查询
private:
      QTcpSocket * mTcpSocket;
      ResponseProcessor mProcessor;
      QMutex mMutex;
signals:
      void setRoleValue(SETTINGVARIABLE role,QByteArray request);// 通讯的设定角色和值 => this
      void selectedPeriod(quint32 ms, quint32 s = 0,quint32 m = 0, quint32 h = 0); // 通讯的日志周期 => this
      void connected();
      void disconnected();
      void errorCode(TCPERRORSTATE code); //  错误码=> 通讯
      void errorCode(TIMEOUTCODE code);
      void tcpFixedQueryData(const QList<QByteArray>& data); // 处理器的数据 => 通讯
      void tcpSetQueryData(bool ret,SETTINGVARIABLE role);
};

#endif // TCPFIXEDQUERY_H
