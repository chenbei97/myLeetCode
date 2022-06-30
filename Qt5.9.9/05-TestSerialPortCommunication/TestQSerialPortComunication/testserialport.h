#ifndef TESTSERIALPORT_H
#define TESTSERIALPORT_H

#include <QMainWindow>
#include  <QtSerialPort/QSerialPort>
#include  <QtSerialPort/QSerialPortInfo>
#include  <QList>
#include "manageserialport.h"
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
  void receive_volPort_data();
  void on_flushdata_clicked();

private:
  void initialize_spinBox_component();

private:
  Ui::TestSerialPort *ui;
  manageSerialPort  portFactory;
  QSerialPort * volPort;
};
#endif // TESTSERIALPORT_H
