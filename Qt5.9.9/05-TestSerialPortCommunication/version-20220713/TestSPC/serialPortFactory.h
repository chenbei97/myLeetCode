#ifndef SERIALPORTFACTORY_H
#define SERIALPORTFACTORY_H
#include <QtGlobal>
#include  <QtSerialPort/QSerialPort>
#include <QIODevice>
#include <QList>
// 这是1个专门用于管理串口的类
class serialPortFactory
{
public:
  serialPortFactory();
  ~serialPortFactory();
  static QSerialPort * createPort(const QString &name = "COM1",
                           qint32 baudRate=9600,QSerialPort::Directions direction = QSerialPort::AllDirections,
                            QSerialPort::Parity parity = QSerialPort::NoParity,QSerialPort::DataBits databit =QSerialPort::Data8,
                           QSerialPort::StopBits stopbit = QSerialPort::StopBits::OneStop,QSerialPort::FlowControl flowcontrol =  QSerialPort::NoFlowControl);
private:
    static QList<QSerialPort*> ports;
};

#endif // SERIALPORTFACTORY_H
