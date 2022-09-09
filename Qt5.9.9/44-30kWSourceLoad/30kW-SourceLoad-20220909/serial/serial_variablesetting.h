#ifndef SERIALVARIABLESETTINGTHREAD_H
#define SERIALVARIABLESETTINGTHREAD_H

#include <QObject>
#include <QSerialPort>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include "core/spic_command.h"
#include "core/enum.h"

using namespace  SPICCOMAND;

class SerialVariableSetting : public QObject
{
      Q_OBJECT
public:
      explicit SerialVariableSetting(QSerialPort * port,QObject*parent = Q_NULLPTR);
public slots:
      void setVariable(const QByteArray& value, SETTINGVARIABLE type );
signals:
      void portNotOpen();
private:
      QSerialPort * mPort;
      QMutex mMutex;
      static QByteArray getSetCommand(const QByteArray& value,SETTINGVARIABLE type);
      static QByteArray getQueryCommand(SETTINGVARIABLE type);
      static const quint32 mQueryInterval = 300;
};

#endif // SERIALVARIABLESETTINGTHREAD_H
