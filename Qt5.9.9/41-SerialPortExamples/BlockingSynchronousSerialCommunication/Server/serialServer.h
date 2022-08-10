#ifndef SERIALSERVER_H
#define SERIALSERVER_H

#include <QDialog>
#include "serverThread.h"
QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QComboBox;
class QSpinBox;
class QPushButton;
QT_END_NAMESPACE

class serialServer : public QDialog
{
    Q_OBJECT

public:
    explicit serialServer(QWidget *parent = nullptr);
    ~serialServer();
private slots:
    void startServerThread(); // 响应按钮的clicked信号,内部会调用服务端线程的startServerThread函数
    void processRequest(const QString &s); // 处理来自客户端的请求
    void processError(const QString &s); // 处理服务端发生的错误,例如没有可用串口或者串口被占用
    void processTimeout(const QString &s); // 处理服务端或客户端引起的超时
    void activateRunButton(); // 1.串口改变2.允许服务端等待请求的超时时间3.服务端回复客户端的消息改变都会重新激活按钮,
private:
    int processRequestCount; // 记录处理客户端请求的次数
    QLabel *serialPortLabel;
    QComboBox *serialPortComboBox;
    QLabel *waitRequestLabel;
    QSpinBox *waitRequestSpinBox;
    QLabel *responseLabel;
    QLineEdit *responseLineEdit;
    QLabel *trafficLabel;
    QLabel *statusLabel;
    QPushButton *runButton;
    serverThread thread;
};
#endif // SERIALSERVER_H
