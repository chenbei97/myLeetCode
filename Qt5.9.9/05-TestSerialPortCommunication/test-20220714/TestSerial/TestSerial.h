#ifndef TESTSERIAL_H
#define TESTSERIAL_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>
#include <QTimer>
#include <QString>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class TestSerial; }
QT_END_NAMESPACE

class TestSerial : public QMainWindow
{
  Q_OBJECT

public:
  TestSerial(QWidget *parent = nullptr);
  ~TestSerial();

private:
  Ui::TestSerial *ui;
  QMutex mutex;
  QSerialPort * port;
  QTimer * fixedQueryTimer;
   QByteArray bufferBytes;
private slots:
   void send_query();
   void receive_reply();
   void write_query(qint64 bytes);

   void on_lineEdit_returnPressed();
signals:
    void lineEditTextChanged(const QString& text);

};
#endif // TESTSERIAL_H
