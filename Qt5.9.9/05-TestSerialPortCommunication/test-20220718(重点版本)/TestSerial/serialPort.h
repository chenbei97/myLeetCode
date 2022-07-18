#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <QSerialPort>

class serialPort : public QSerialPort
{
public:
  serialPort();

private:
    bool canReadLine() const override;
};

#endif // SERIALPORT_H
