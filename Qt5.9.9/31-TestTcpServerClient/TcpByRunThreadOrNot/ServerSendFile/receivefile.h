#ifndef RECEIVEFILE_H
#define RECEIVEFILE_H

#include <QThread>
#include <QTcpSocket>

class ReceiveFile : public QThread
{
  Q_OBJECT
public:
  explicit ReceiveFile(QTcpSocket * socket,QObject * parent = Q_NULLPTR);
protected:
  void run() override;
private:
   QTcpSocket * mTcpSocket;
signals:
   void receiveEnd();
};

#endif // RECEIVEFILE_H
