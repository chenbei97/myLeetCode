#ifndef ASYNCTERMINAL_H
#define ASYNCTERMINAL_H

#include <QMainWindow>
#include <QSerialPort>
#include <QLabel>
#include <QMutex>
#include "serial_port_configuration/portConfig.h"

QT_BEGIN_NAMESPACE
namespace Ui { class asyncTerminal; }
QT_END_NAMESPACE

class asyncTerminal : public QMainWindow
{
        Q_OBJECT
public:
        explicit asyncTerminal(QWidget *parent = nullptr);
        ~asyncTerminal();
private slots: // function/actslot.cpp
        void on_actSetPortParams_triggered(); // 配置串口
        void on_actConnect_triggered(); // 连接串口
        void on_actDisconnect_triggered();// 断开连接
        void on_actClear_triggered(); // 清空消息
        void on_actAbout_triggered(); // 关于应用
        void on_actAboutQt_triggered();//关于Qt
private: // core/core.cpp
        void init();
        void initConnections();
private slots: // function/consoleslot.cpp
        void on_textEditor_eventInfomation(const QString &s); // 响应textEditor的eventInformation信号
        void on_textEditor_forwardKeyInput(const QByteArray& s); // 响应textEditor的forwardKeyInput信号
private slots: // function/portslot.cpp
        void on_mPort_errorOccurred(QSerialPort::SerialPortError error); // 响应串口的errorOccurred
        void on_mPort_readyRead();
private:
        Ui::asyncTerminal *ui;
        portConfig * mConfig;
        QSerialPort * mPort;
        QLabel * mPortStatus;
        QMutex  mutex;
};
#endif // ASYNCTERMINAL_H
