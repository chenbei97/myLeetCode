#ifndef SERIALCLIENT_H
#define SERIALCLIENT_H

#include <QDialog>
#include "clientThread.h"
QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QSpinBox;
class QPushButton;
class QComboBox;
class QTimer;
QT_END_NAMESPACE

class serialClient : public QDialog
{
    Q_OBJECT
    private slots:
      void startClientThread(); // 响应按钮的clicked信号,内部会调用客户端线程的startClientThread函数
      void processResponse(const QString &s);// 处理来自服务端的回复
      void processError(const QString &s); // 处理客户端发生的错误,例如没有可用串口或者串口被占用
      void processTimeout(const QString &s); // 处理客户端或服务端引起的超时
private:
      void setControlsEnabled(bool enable); // 1.串口改变2.允许客户端等待回复的超时时间3.客户端给服务器发送的请求改变都会重新激活按钮
private:
      int processResponseCount; // 记录处理服务端回复的次数
      QLabel *serialPortLabel;
      QComboBox *serialPortComboBox;
      QLabel *waitResponseLabel;
      QSpinBox *waitResponseSpinBox;
      QLabel *requestLabel;
      QLineEdit *requestLineEdit;
      QLabel *trafficLabel;
      QLabel *statusLabel;
      QPushButton *runButton;
      clientThread thread;
      QTimer *timer;
public:
    serialClient(QWidget *parent = nullptr);
    ~serialClient();
};
#endif // SERIALCLIENT_H
