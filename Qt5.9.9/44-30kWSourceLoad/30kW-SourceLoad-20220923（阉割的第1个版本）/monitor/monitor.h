#ifndef MONITOR_H
#define MONITOR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QSplitter>
#include <QCheckBox>
#include <QEvent>
#include <QShowEvent>
#include <QStatusBar>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QMessageBox>
#include <monitor/monitor_label.h>
#include <monitor/monitor_spinbox.h>
#include <core/enum.h>

class Monitor : public QMainWindow
{
    Q_OBJECT
public:
    explicit Monitor(WORKMODE  workmode = WORKMODE::CV,QWidget *parent = Q_NULLPTR);
    WORKMODE workMode() const;
    void setMessageState(TIMEOUTCODE code); // 超时状态设置
    void setConnectState(SERIALERROR error); // 串口连接和TCP连接状态
    void setConnectState(TCPERRORSTATE error);
    void showMeasureState(const QList<QByteArray> &data); //
    void showSetState(bool ret ,SETTINGVARIABLE role);
    static QString translateErrorCode(SERIALERROR code); // 翻译串口错误码
    static QString translateErrorCode(TCPERRORSTATE code); // 翻译套接字错误状态码
    static QString translateErrorCode(TIMEOUTCODE code); // 翻译超时错误码
    static QString translateErrorCode(SETTINGVARIABLE role); // 翻译设定角色
public slots:
    bool eventFilter(QObject* watchedObj, QEvent * event) override; // 事件过滤器
private:
    void initCVUI();
    void initCCUI();
    void initCommonUI();
    void showEvent(QShowEvent * e) override;
    WORKMODE mWorkMode;
private: // 窗口UI组件
    QSplitter * mainLayout;
    QLabel* IsShowResistanceLabel; QCheckBox* IsShowResistance;

    MonitorLabel * ShowPower; // 功率读取1个,功率设置2个
    QLabel * SetPowerSourceLabel; MonitorSpinBox * SetPowerSource;
    QLabel * SetPowerLoadLabel; MonitorSpinBox * SetPowerLoad;

    MonitorLabel * ShowResistance; // 电阻读取1个,电阻设置2个
    QLabel * SetResistanceSourceLabel; MonitorSpinBox * SetResistanceSource;
    QLabel * SetResistanceLoadLabel; MonitorSpinBox * SetResistanceLoad;

    MonitorLabel * ShowVoltage; // 电压读取1个-->对应电流设置2个(但是2个设置是new出来的不是全局的)
    MonitorLabel * ShowCurrent; // 电流读取1个-->对应电压设置2个(但是2个设置是new出来的不是全局的)

    QGroupBox * VoltageGroupBox;
    QGroupBox * CurrentGroupBox;
    QGroupBox * PowerGroupBox;
    QGroupBox * ResistanceGroupBox;

    QLabel * ConnectState; // 连接状态
    QLabel * MessageRequestState; // 消息请求状态
    QLabel * MessageResponseState; // 消息回复状态
    QLabel * MessageSetState; // 设定查询是否成功

 signals:
     void setRoleValue(SETTINGVARIABLE role, const QByteArray& value); // 监控设定的角色和值 => 监控界面
};
#endif // MONITOR_H
