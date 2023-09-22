#ifndef TESTTCP_H
#define TESTTCP_H

#include "../widgets/pushbutton.h"
#include "../widgets/textedit.h"
#include "../widgets/lineedit.h"
#include "../utilities/path.h"
#include "../utilities/testtcpreadwrite.h"
#include "../utilities/encry.h"
#include "tcploader.h"
#include "tcpquery.h"
#include "tcpassemblercontroller.h"

class COMPONENT_IMEXPORT TestTcp : public QWidget
{
    Q_OBJECT
public:
    explicit TestTcp(QWidget *parent = nullptr);
    QPushButton * connectBtn;
    QPushButton * disconnectBtn;
    QPushButton * sendBtn;
    QLineEdit * sendEdit;
    QTextEdit * edit;
    QByteArray json;
    TcpQuery query;
    void onSend();
    void onConnect();
    void onDisconnect();
    QVariantMap fakeDatafor0x0000() const;
    QVariantMap fakeDatafor0x0002() const;
    void test0();
    void test1();
    void test2();
signals:

};

class COMPONENT_IMEXPORT Worker : public QObject
  {
      Q_OBJECT

  public slots:
      void doWork(const QString &parameter) {
          QString result;
          /* ... here is the expensive or blocking operation ... */
          result = parameter + "////123";
          emit resultReady(result);
          qDebug()<<"dowork thread = "<<QThread::currentThread();
      }

  signals:
      void resultReady(const QString &result);
  };

  class COMPONENT_IMEXPORT Controller : public QObject
  {
      Q_OBJECT
      QThread workerThread;
  public:
      Controller() {
          Worker *worker = new Worker;
          worker->moveToThread(&workerThread);
          connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
          connect(this, &Controller::operate, worker, &Worker::doWork);
          connect(worker, &Worker::resultReady, this, &Controller::handleResults);
          workerThread.start();
          qDebug()<<"worker's thread = "<<worker->thread()->currentThread();
          qDebug()<<"controller current thread = "<<QThread::currentThread();
      }
      ~Controller() {
          workerThread.quit();
          workerThread.wait();
      }
  public slots:
      void handleResults(const QString & result){
          qDebug()<<"result = "<<result;
          qDebug()<<"handleResults thread = "<<QThread::currentThread();
      };
  signals:
      void operate(const QString & param);
  };



#endif // TESTTCP_H
