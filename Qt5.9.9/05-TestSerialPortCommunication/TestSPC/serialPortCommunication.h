#ifndef SERIALPORTCOMMUNICATION_H
#define SERIALPORTCOMMUNICATION_H

#include <QMainWindow>
#include  <QtSerialPort/QSerialPort>
#include  <QtSerialPort/QSerialPortInfo>
#include "serialPortFactory.h"
#include "spctime.h"
QT_BEGIN_NAMESPACE
namespace Ui { class SerialPortCommunication; }
QT_END_NAMESPACE

class SerialPortCommunication : public QMainWindow
{
  Q_OBJECT

public:
  SerialPortCommunication(QWidget *parent = nullptr);
  ~SerialPortCommunication();
private:
  void initialize_spinBox_component();

  void delay(unsigned int msec);
  void sleep(unsigned int msec);
private slots:
  void receive_port_data();
  void send_command_to_hardware();
  void receive_data_from_hardware();

  void on_serialNameBox_currentIndexChanged(const QString &arg1);
  void on_serialBaudRateBox_currentIndexChanged(const QString &arg1);

  void on_openSerialPort_clicked();
  void on_closeSerialPort_clicked();

  void on_volInput_valueChanged(double arg1);
  void on_curInput_valueChanged(double arg1);
  void on_powInput_valueChanged(double arg1);
  void on_RInput_valueChanged(double arg1);

private:
  Ui::SerialPortCommunication *ui;
  serialPortFactory  portFactory;
  QSerialPort * Port;
};
#endif // SERIALPORTCOMMUNICATION_H
