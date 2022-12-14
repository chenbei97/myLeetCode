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
#include <QTcpSocket>
#include <QHostAddress>
#include <QIntValidator>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <mainwindow.h>
#include <serial/serial_config.h>
#include <serial/serial_fixedquery.h>
#include <serial/serial_setquery.h>
#include <tcp/tcp_query.h>

class Communication : public QDialog
{
    Q_OBJECT
public:
    explicit Communication(QWidget * parent = Q_NULLPTR);
    enum Type {None,Serial, Tcp};
private:
    void initUI();
    void initSerialConnections();
    void initTcpConnections();
    void on_PortConfigureBtn();
    void on_TCPConfigureBtn();
    void closeEvent(QCloseEvent *) override;
    void paintEvent(QPaintEvent *e) override;
    bool hasChanged(SerialConfig::Settings settings);

    quint32  mLogMultiple; // 日志周期相对mFixedQueryTime的倍数,默认30也就是9s记录1次
    quint32  mLogHandle; // 关闭定时器清0,mLogHandle=mLogPeriodRate清0并让mLogExec=true
    bool mLogExec; // 打log时变成true,默认false
    Communication::Type mCommunicationType;
    static const quint32 mFixedQueryTime = 300;
    SerialConfig::Settings mPortSettings;
    MainWindow * mainWindow; // 本窗口的父窗口
    QSerialPort * mPort;
    SerialFixedQueryThread * mPortFixedQueryThread; // 查询线程(重载run)
    QTimer * mPortFixedQueryTimer; // 定时器
    SerialSetQuery * mPortSetQueryWorker; // 设定线程工作对象
    QThread * mPortSetQueryThread; // 设定线程

    QString mHostName; // TCP的IP地址
    quint16 mHostPort;// TCP的端口号
    QTcpSocket * mTcpSocket; // 套接字资源
    QThread * mTcpQueryThread; // 查询线程
    TcpQuery * mTcpQueryWorker; // 查询线程工作对象
    QTimer * mTcpQueryTimer; // 定时器
private:
    QGridLayout * mainLayout;
    QLabel * PortLabel;
    QPushButton * PortConnectBtn;
    QPushButton * PortDisconnectBtn;
    QPushButton * PortConfigureBtn;
    QLabel * TCPLabel;
    QPushButton * TCPConnectBtn;
    QPushButton * TCPDisconnectBtn;
    QPushButton * TCPConfigureBtn;
signals:
    void updatePortSettings(); // on_PortConfigureBtn()中发信号,更新串口配置
    void getRoleValue(SETTINGVARIABLE role,const QByteArray& value); // 监控信号=>通讯信号
    void setRoleValue(SETTINGVARIABLE role,QByteArray value); // 通讯信号=>线程信号=>处理器槽函数
    void fixedQueryData(const QList<QByteArray> &); //  固定查询信号 =>监控界面(串口,TCP共用)
    void setQueryData(bool ret,SETTINGVARIABLE role); // 设定查询信号 => 监控界面(串口,TCP共用)
    void errorCode(TIMEOUTCODE); // 固定查询-超时错误 =>监控界面
    void errorCode(SERIALERROR); // 固定查询-串口错误 =>监控界面
    void errorCode(TCPERRORSTATE); //套接字错误或状态 => 监控界面
    void selectedPeriod(quint32 ms, quint32 s = 0,quint32 m = 0, quint32 h = 0);//mTableSPDlg=>communication
    void log(const QList<QByteArray>&); // fixedQueryData信号中截取的log数据
};

#endif // COMMUNICATION_H
