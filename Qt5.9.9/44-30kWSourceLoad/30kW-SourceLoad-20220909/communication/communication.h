#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include "mainwindow.h"
#include "serial/serial_config.h"
#include "serial/serial_fixedquerythread.h"
#include "serial/serial_variablesetting.h"

class Communication : public QDialog
{
    Q_OBJECT
public:
    explicit Communication(QWidget * parent = Q_NULLPTR);
    void initUI();
    void initUSB();
    void initTCP();
    void initConnections();
private:
    QGridLayout * mainLayout;
    MainWindow * mainWindow;
    QPushButton * quitBtn;
    QLabel * PortLabel;
    QPushButton * PortConnectBtn;
    QPushButton * PortDisconnectBtn;
    QPushButton * PortConfigureBtn;
    QLabel * TCPLabel;
    QPushButton * TCPConnectBtn;
    QPushButton * TCPDisconnectBtn;
    QPushButton * TCPConfigureBtn;
private slots: // 组件的按钮信号连接
    void on_PortConnectBtn();
    void on_PortDisconnectBtn();
    void on_PortConfigureBtn();
    void on_TCPConnectBtn();
    void on_TCPConfigureBtn();
private slots:
    void on_UpdatePortSettings(); // 接收自定义的更新串口设置updatePortSettings信号,在点击串口配置关闭界面后会自动更新串口属性才能连接
    void startFixedQueryThread();// 接收定时器的timeout信号
private slots: // 响应来自固定查询的3个信号
    void on_FixedQueryThread_AvailableFixedQueryData(QByteArray data);  // 响应availableFixedQueryData信号 (数据传递: 工作线程 => communication )
    void on_FixedQueryThread_AvailableSetQueryData(QByteArray response,QByteArray request,SETTINGVARIABLE role); // 响应availableSetQueryData信号
    void on_FixedQueryThread_ErrorCode(TIMEOUTCODE code); // 响应void errorCode(ErrorCode code)信号
    void on_FixedQueryThread_ErrorCode(SERIALERROR code); // errorCode重载信号
private slots: // 响应来自监控界面的10个信号,连接见cconnect.cpp
    void on_Monitor_PowSourceChanged(QByteArray value);
    void on_Monitor_PowLoadChanged(QByteArray value);
    void on_Monitor_ResSourceChanged(QByteArray value);
    void on_Monitor_ResLoadChanged(QByteArray value);
    void on_Monitor_VoltChanged(QByteArray value);
    void on_Monitor_CurrSourceChanged(QByteArray value);
    void on_Monitor_CurrLoadChanged(QByteArray value);
    void on_Monitor_CurrChanged(QByteArray value);
    void on_Monitor_VoltSourceChanged(QByteArray value);
    void on_Monitor_VoltLoadChanged(QByteArray value);
signals:
    void updatePortSettings(); // on_PortConfigureBtn()中发信号,void on_UpdatePortSettings()接收
    void sendInfo(SETTINGVARIABLE role,QByteArray request); // 在communicate_with_monitor.cpp中使用,告知设定的角色和要设定的值
    // 连接见cconnect.cpp
    void availableFixedQueryData(const QList<QByteArray> & values); // (数据传递: communication => 外部(监控界面))
    void errorCode(TIMEOUTCODE code); // 定时查询-超时错误
    void errorCode(SERIALERROR code); // 定时查询-串口错误
    void errorCode(bool failed,SETTINGVARIABLE role) ; // 设定查询-设定成功或失败
private:
    SerialConfig::Settings mPortSettings;
    bool hasChanged(SerialConfig::Settings settings);
    QSerialPort * mPort;
    QTimer * mFixedQueryTimer;
    static const int mFixedQueryTime = 300;
    SerialFixedQueryThread * mFixedQueryThread;
    SerialVariableSetting * mSetController; // 控制器(把监控界面拿到的设定值整合成命令写入串口,并返回设定结果)
    QThread * mSetControllerThread; // 控制器线程
};

#endif // COMMUNICATION_H
