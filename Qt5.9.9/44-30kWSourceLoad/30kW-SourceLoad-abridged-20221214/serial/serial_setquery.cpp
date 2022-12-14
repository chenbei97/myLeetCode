#include <serial/serial_setquery.h>

SerialSetQuery::SerialSetQuery(QSerialPort * port,QObject * parent):QObject(parent)
          ,mPort(port)
{
       // 串口资源只有1个，一般来说串口应当是已打开的状态
}

void SerialSetQuery::setQuery(SETTINGVARIABLE role ,const QByteArray& value)
{
       if (!mPort->isOpen()) return;// 如果真的因为某些原因是没打开的状态
       QByteArray c = getSetQueryCommand(role,value);
       QMutexLocker locker(&mMutex);
       mPort->write(c);
}
