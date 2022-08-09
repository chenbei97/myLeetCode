#ifndef BLOCKINGSERIALPORT_H
#define BLOCKINGSERIALPORT_H

#include <QDialog>
#include "myThread.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QSpinBox;
class QPushButton;
class QComboBox;
class QTimer;
QT_END_NAMESPACE

class BlockingSerialPort : public QDialog
{
  Q_OBJECT

public:
      explicit BlockingSerialPort(QWidget *parent = nullptr);
      ~BlockingSerialPort();
private slots:
      void transaction();
      void showResponse(const QString &s);
      void processError(const QString &s);
      void processTimeout(const QString &s);
private:
      void setControlsEnabled(bool enable);
private:
      int transactionCount;
      QLabel *serialPortLabel;
      QComboBox *serialPortComboBox;
      QLabel *waitResponseLabel;
      QSpinBox *waitResponseSpinBox;
      QLabel *requestLabel;
      QLineEdit *requestLineEdit;
      QLabel *trafficLabel;
      QLabel *statusLabel;
      QPushButton *runButton;
      QTimer *timer;
      myThread thread;
};
#endif // BLOCKINGSERIALPORT_H
