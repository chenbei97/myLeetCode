#ifndef TCPSETQUERY_H
#define TCPSETQUERY_H

#include <QObject>
#include <QTcpSocket>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <core/spic_command.h>

using namespace  SPICCOMAND;

class TcpSetQuery : public QObject
{
      Q_OBJECT
public:
      explicit TcpSetQuery(QTcpSocket * socket,QObject*parent = Q_NULLPTR);
      void setVariable(SETTINGVARIABLE role,const QByteArray& value);
private:
      QTcpSocket * mSocket;
      QMutex mMutex;
};

#endif // TCPSETQUERY_H
