#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
class TimerServer; // 不能在"server.h"引入"timerServer.h","timerServer.h"中引入"server.h",这样造成相互包含会有问题

class Server : public QDialog
{
  Q_OBJECT
public:
  explicit Server(QWidget *parent = nullptr);
public slots:
    void on_threadSignals(); // 响应来自线程的2个信号
private:
   TimerServer * mTcpServer; // 实际上Server并包含了TimerServer,TimerServer也包含了Server
   QLabel * portID;
   int requestCount;
   QLabel * requestCountLabel;
   QPushButton * quitBtn;
};
#endif // SERVER_H
