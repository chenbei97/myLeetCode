#ifndef TESTSERIALPORT_H
#define TESTSERIALPORT_H

#include <QMainWindow>
#include  <QtSerialPort/QSerialPort>
#include  <QtSerialPort/QSerialPortInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class TestSerialPort; }
QT_END_NAMESPACE

class TestSerialPort : public QMainWindow
{
  Q_OBJECT

public:
  TestSerialPort(QWidget *parent = nullptr);
  ~TestSerialPort();
private slots:
  void on_serialNameBox_currentIndexChanged(const QString &arg1);
  void on_serialBaudRateBox_currentIndexChanged(const QString &arg1);
  void on_volInput_valueChanged(double arg1);

private:
  void initialize_spinBox_component();
  void initialize_serial_port();
  void print_serial_port_info();
private:
  Ui::TestSerialPort *ui;
  QSerialPort * port;
  QSerialPortInfo * portInfo;
};
#endif // TESTSERIALPORT_H
