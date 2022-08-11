#ifndef SERIALFIXEDQUERYTHREAD_H
#define SERIALFIXEDQUERYTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QtSerialPort/QSerialPort>
class serialFixedQueryThread : public QThread
{
  Q_OBJECT
public:
  explicit serialFixedQueryThread(QObject * parent = nullptr);
  ~serialFixedQueryThread();
  void startFixedQueryThread(QSerialPort * port, quint32 queryInterval = 300);
  void run() override;
private:
  QSerialPort * mPort;
  QMutex mutex;
  QWaitCondition cond;
  bool mQuit;
  quint32 mQueryInterval;
  quint32 mTimeOutCount; // 固定查询的累计超时次数
  quint32 mRequsetCount; // 累计请求次数
  quint32 mResponseCount; // 累计收到回复次数
signals:
  void error(const QString& s);
  void timeout(quint32 count);
  void response(const QString& s);
  void responseRequesetCount(quint32 c1,quint32 c2);
private:
  QString errorCodeToString(QSerialPort::SerialPortError errorCode);
};

#endif // SERIALFIXEDQUERYTHREAD_H
