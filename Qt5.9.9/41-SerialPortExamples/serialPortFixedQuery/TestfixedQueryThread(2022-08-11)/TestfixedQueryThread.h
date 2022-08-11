#ifndef TESTFIXEDQUERYTHREAD_H
#define TESTFIXEDQUERYTHREAD_H

#include <QDialog>
#include <QTimer>
#include <QLabel>
#include <QComboBox>
#include <QtSerialPort/QSerialPort>
#include "serialFixedQueryThread.h"

class TestfixedQueryThread : public QDialog
{
  Q_OBJECT
public:
  explicit TestfixedQueryThread(QWidget *parent = nullptr);
  ~TestfixedQueryThread();
private slots:
    void startFixedQueryThread();
    void onTimeOut_FixedQueryThread(quint32 count);
    void onError_FixedQueryThread(const QString& s);
    void onResponse_FixedQueryThread(const QString&s);
    void onResponseRequesetCount_FixedQueryThread(quint32 c1,quint32 c2);
private:
    void onPortNameChanged_ComboBox(const QString& s);
    void onBaudRateChanged_ComboBox(const QString& s);
    void onFixedQueryTimeChanged_ComboBox(const QString&s);
private:
  QSerialPort * mPort;
  QTimer * mFixedQueryTimer;
  bool quit;
  serialFixedQueryThread mFixedQueryThread;
  QLabel * mErrorString;
  QLabel * mResponseString;
  QLabel * mTimeoutCount;
  QLabel * mErrorStringShow;
  QLabel * mResponseStringShow;
  QLabel * mTimeoutCountShow;
  QLabel * mRequestCount;
  QLabel * mResponseCount;
  QComboBox * serialPortComboBox;
  QComboBox * serialBaudRateComboBox;
  QLabel * fixedQueryTimeShow;
  QComboBox * fixedQueryTime;
};
#endif // TESTFIXEDQUERYTHREAD_H
