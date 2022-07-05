#ifndef SERIALPORTCOMMUNICATION_H
#define SERIALPORTCOMMUNICATION_H

#include <QMainWindow>
#include  <QtSerialPort/QSerialPort>
#include  <QtSerialPort/QSerialPortInfo>
#include <QTimer>
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
public :
  enum class  Name{chen,wang,li,sun,unknow};

private:
  void initialize_spinBox_component();
  void initialize_timer_component();

  void delay(unsigned int msec);
  void sleep(unsigned int msec);
  const char* test_enum(Name name = Name::unknow){
    switch (name) {
      case Name::sun: return "sun";break;
      case Name::wang: return "wang";break;
      case Name::li:return "li";break;
      case Name::chen: return"chen";break;
      default: return"";break;
      }
  }
private slots:
  void receive_port_data();
  void send_query_command();
  void receive_query_result();

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
  QTimer * timer;

};
#endif // SERIALPORTCOMMUNICATION_H
