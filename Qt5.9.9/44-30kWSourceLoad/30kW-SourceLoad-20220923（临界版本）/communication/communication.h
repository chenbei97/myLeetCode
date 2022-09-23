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
#include "serial/serial.h"
#include "serial/serial_fixedquery_thread.h"
#include "serial/serial_variable_setting.h"

class Communication : public QDialog
{
    Q_OBJECT
public:
    explicit Communication(QWidget * parent = Q_NULLPTR);
private:
    void initUI();
    void initUSB();
    void initTCP();
    void initConnections();
    void initUIConnections();
    void initFixedQueryToCommunicationConnections();
    void initCommunicationToFixedQueryConnections();
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
private slots: // 响应来自固定查询的4个信号
    void on_FixedQueryThread_AvailableFixedQueryData(QByteArray data);  // MEAS数据信号
    void on_FixedQueryThread_AvailableSetQueryData(QByteArray response,QByteArray request,SETTINGVARIABLE role); // 设定查询数据信号
    void on_FixedQueryThread_ErrorCode(TIMEOUTCODE code); // 超时错误码信号
    void on_FixedQueryThread_ErrorCode(SERIALERROR code); // 串口错误码信号
private slots: // 响应来自监控界面的10个信号,连接见mainwindow_connect.cpp
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
    void updatePortSettings(); // on_PortConfigureBtn()中发信号,响应函数见communication_connect.cpp
    void sendInfo(SETTINGVARIABLE role,QByteArray request); // 在communication_slot_from_monitor.cpp中使用,通讯界面=>设定查询告知设定的角色和要设定的值
    void availableFixedQueryData(const QList<QByteArray> & values); //  固定查询-数据VAPR =>监控界面
    void errorCode(TIMEOUTCODE code); // 固定查询-超时错误 =>监控界面
    void errorCode(SERIALERROR code); // 固定查询-串口错误 =>监控界面
    void errorCode(bool failed,SETTINGVARIABLE role) ; // 设定查询-设定成功或失败 =>监控界面
private:
    SerialConfig::Settings mPortSettings;
    bool hasChanged(SerialConfig::Settings settings);
    QSerialPort * mPort;
    QTimer * mFixedQueryTimer;
    static const int mFixedQueryTime = 300;
    SerialFixedQueryThread * mFixedQueryThread;
    SerialVariableSetting * mSetController; // 设定线程工作对象(把监控界面拿到的设定值整合成命令写入串口,并返回设定结果)
    QThread * mSetControllerThread; // 设定线程(mSetController要moveToThreadmSetControllerThread)
};

#endif // COMMUNICATION_H
