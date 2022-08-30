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
#include <QDebug>
#include <monitor/mlabel.h>
#include <monitor/mspinbox.h>
#include <core/enum.h>

class Monitor : public QMainWindow
{
    Q_OBJECT
public:
    explicit Monitor(WORKMODE  workmode = WORKMODE::CV,QWidget *parent = Q_NULLPTR);

    struct PRSettings
    {
          double PowerSource; QString PowerSourceString;
          double PowerLoad; QString PowerLoadString;
          double ResistanceSource; QString ResistanceSourceString;
          double ResistanceLoad; QString ResistanceLoadString;

          PRSettings(): PowerSource(0.000),PowerSourceString(QString::number(0.000,'f',3))
          , PowerLoad(0.000),PowerLoadString(QString::number(0.000,'f',3))
          , ResistanceSource(0.000),ResistanceSourceString(QString::number(0.000,'f',3))
          , ResistanceLoad(0.000),ResistanceLoadString(QString::number(0.000,'f',3))
          {

          }
    };
    struct CVSettings
    {
          double Voltage; QString VoltageString;
          double CurrentSource; QString CurrentSourceString;
          double CurrentLoad; QString CurrentLoadString;

          CVSettings(): Voltage(0.000),VoltageString(QString::number(0.000,'f',3))
          , CurrentSource(0.000),CurrentSourceString(QString::number(0.000,'f',3))
          , CurrentLoad(0.000),CurrentLoadString(QString::number(0.000,'f',3))
          {

          }
    };
    struct CCSettings
    {
          double Current; QString CurrentString;
          double VoltageSource; QString VoltageSourceString;
          double VoltageLoad; QString VoltageLoadString;

          CCSettings(): Current(0.000),CurrentString(QString::number(0.000,'f',3))
          , VoltageSource(0.000),VoltageSourceString(QString::number(0.000,'f',3))
          , VoltageLoad(0.000),VoltageLoadString(QString::number(0.000,'f',3))
          {

          }
    };
    WORKMODE workMode() const;
    PRSettings prsettings() const;
    CVSettings cvsettings() const;
    CCSettings ccsettings() const;
    void setPRSettings(const Monitor::PRSettings & settings);
    void setCVSettings(const Monitor::CVSettings & settings);
    void setCCSettings(const Monitor::CCSettings & settings);
private:
    PRSettings mPRSettings;
    CVSettings mCVSettings;
    CCSettings mCCSettings;
private:
    void initCVUI();
    void initCCUI();
    void initCommonUI();
    void initConnections();
private:
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
    bool eventFilter(QObject* watchedObj, QEvent * event); // 事件过滤器
protected:
    void showEvent(QShowEvent * e) override;
private:
    WORKMODE mWorkMode;
private:
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
};


#endif // MONITOR_H
