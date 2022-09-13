#ifndef NEWRECEIVEFILE_H
#define NEWRECEIVEFILE_H


#include <QThread>
#include <QTcpSocket>

class NewReceiveFile : public QThread
{
  Q_OBJECT
public:
  explicit NewReceiveFile(qintptr descriptor,QObject * parent = Q_NULLPTR);
protected:
  void run() override;
private:
   QTcpSocket * mTcpSocket;
signals:
   void receiveEnd();
};

#endif // NEWRECEIVEFILE_H
