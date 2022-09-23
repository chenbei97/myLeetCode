#ifndef SERIALVARIABLESETTINGTHREAD_H
#define SERIALVARIABLESETTINGTHREAD_H

#include <QObject>
#include <QSerialPort>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <core/spic_command.h>

using namespace  SPICCOMAND;

class SerialSetQuery : public QObject
{
      Q_OBJECT
public:
      explicit SerialSetQuery(QSerialPort * port,QObject*parent = Q_NULLPTR);
      void setVariable(SETTINGVARIABLE role,const QByteArray& value );
private:
      QSerialPort * mPort;
      QMutex mMutex;
      static const quint32 mQueryInterval = 300;
};

#endif // SERIALVARIABLESETTINGTHREAD_H
