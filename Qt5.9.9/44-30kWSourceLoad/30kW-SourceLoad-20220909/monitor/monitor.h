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
#include <monitor/monitor_label.h>
#include <monitor/monitor_spinbox.h>
#include <core/enum.h>

class Monitor : public QMainWindow
{
    Q_OBJECT
public:
    explicit Monitor(WORKMODE  workmode = WORKMODE::CV,QWidget *parent = Q_NULLPTR);
    WORKMODE workMode() const;
private:
   WORKMODE mWorkMode;
private: // 监控界面组件的响应槽函数
    void on_IsShowResistance(bool checked);
    void on_SetPowerSource(double value);
    void on_SetPowerLoad(double value);
    void on_SetResistanceSource(double value);
    void on_SetResistanceLoad(double value);
    void on_SetVoltage(double value);
    void on_SetCurrentSource(double value);
    void on_SetCurrentLoad(double value);
    void on_SetCurrent(double value);
    void on_SetVoltageSource(double value);
    void on_SetVoltageLoad(double value);
public slots:
    bool eventFilter(QObject* watchedObj, QEvent * event) override; // 事件过滤器
    //  连接关系在mainwindow.cpp直接确定,因为主窗口同时拥有通讯和监控界面,可以实现连接
    void on_Communication_AvailableFixedQueryData(const QList<QByteArray> &data);// 从串口固定查询线程得到的数据 => communication窗口 => 本监控界面
    void on_Communication_ErrorCode(SERIALERROR code); // 从串口固定查询发来的串口错误码
    void on_Communication_ErrorCode(TIMEOUTCODE code);// 从串口固定查询发来的超时错误码
    void on_Communication_ErrorCode(bool failed,SETTINGVARIABLE role);// 从串口设定查询发来的是否设定成功的状态
protected:
    void showEvent(QShowEvent * e) override;
private: // 私有函数
    void initCVUI();
    void initCCUI();
    void initCommonUI();
    void initConnections();
    static QString translateErrorCode(SERIALERROR code); // 翻译定时查询串口错误码
    static QString translateErrorCode(TIMEOUTCODE code); // 翻译定时查询超时错误码
    static QString translateErrorCode(SETTINGVARIABLE role); // 翻译设定查询角色
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

    QLabel * ConnectState; // 串口状态
    QLabel * MessageRequestState; // 串口写入请求状态
    QLabel * MessageReceiveState; // 串口读取回复状态
    QLabel * MessageSetState; // 设定查询是否成功

 signals:
     // 组件因为是私有的,所以其valueChanged信号无法被外界拿到绑定到communication.cpp的槽函数
     // 所以这里定义公有的信号就可以绑定到communication.cpp的槽函数
     // 当然能同时有监控界面和通讯界面还是在mainwindow.cpp中完成2者的连接
     // 之所以要使用信号传递,因为监控界面仅仅是要拿到设定的值而已,传播到communication.cpp很简单
     // 但是如果把串口指针从communication.cpp发射给监控界面用是比较困难的
     // 所以关于设定各类值的串口线程不在这里完成,只作一部分工作把value转为QByteArray
     void powSourceChanged(QByteArray value);
     void powLoadChanged(QByteArray value);

     void resSourceChanged(QByteArray value);
     void resLoadChanged(QByteArray value);

     void voltChanged(QByteArray value);
     void currSourceChanged(QByteArray value);
     void currLoadChanged(QByteArray value);

     void currChanged(QByteArray value);
     void voltSourceChanged(QByteArray value);
     void voltLoadChanged(QByteArray value);
};


#endif // MONITOR_H
