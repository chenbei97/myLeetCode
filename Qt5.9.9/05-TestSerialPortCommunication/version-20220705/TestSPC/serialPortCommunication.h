#ifndef SERIALPORTCOMMUNICATION_H
#define SERIALPORTCOMMUNICATION_H

#include <QMainWindow>
#include  <QtSerialPort/QSerialPort>
#include  <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include "serialPortFactory.h"
#include "spctime.h"
#include "spiCommand.h"
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
  void initialize_workStatus_component();
  void initialize_timer_component();
  void change_label_spinBox_component(const SPIC::STATUS &workMode =
      SPIC::STATUS::CV_WORK_MODE);

  void delay(unsigned int msec);
  void sleep(unsigned int msec);
private slots:
  void receive_port_data();
  void send_query_command();

  void on_serialNameBox_currentIndexChanged(const QString &arg1);
  void on_serialBaudRateBox_currentIndexChanged(const QString &arg1);

  void on_openSerialPort_clicked();
  void on_closeSerialPort_clicked();

  void on_Input1_valueChanged(double arg1);
  void on_Input2PS_valueChanged(double arg1);
  void on_Input2EL_valueChanged(double arg1);
  void on_powInputEL_valueChanged(double arg1);
  void on_powInputPS_valueChanged(double arg1);

  void on_rbtCV_clicked(bool checked);
  void on_rbtCC_clicked(bool checked);

private:
  Ui::SerialPortCommunication *ui;
  serialPortFactory  portFactory;
  QSerialPort * Port;
  QTimer * timer;
  static const unsigned int flushTime = 2000;


};
#endif // SERIALPORTCOMMUNICATION_H
