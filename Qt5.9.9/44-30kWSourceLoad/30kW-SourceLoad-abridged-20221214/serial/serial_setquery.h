#ifndef SERIALSETQUERY_H
#define SERIALSETQUERY_H

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
      void setQuery(SETTINGVARIABLE role,const QByteArray& value );
private:
      QSerialPort * mPort;
      QMutex mMutex;
      static const quint32 mQueryInterval = 300;
};

#endif // SERIALSETQUERY_H
