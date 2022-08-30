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
#include <QDebug>
#include <core/enum.h>

class Monitor : public QMainWindow
{
      Q_OBJECT
public:
      explicit Monitor(QWidget *parent = nullptr, WORKMODE  workmode = WORKMODE::CV);
      WORKMODE workMode() const;
private:
      void initCVUI();
      void initCCUI();
      void initCommonUI();
      void initConnections();
      void on_IsShowResistance(bool checked);
private:
      WORKMODE mWorkMode;
private:
      QSplitter * mainLayout;
      QLabel* IsShowResistanceLabel; QCheckBox* IsShowResistance;

      QLabel * ShowPower; // 功率读取1个,功率设置2个
      QLabel * SetPowerSourceLabel; QDoubleSpinBox * SetPowerSource;
      QLabel * SetPowerLoadLabel; QDoubleSpinBox * SetPowerLoad;

      QLabel * ShowResistance; // 电阻读取1个,电阻设置2个
      QLabel * SetResistanceSourceLabel; QDoubleSpinBox * SetResistanceSource;
      QLabel * SetResistanceLoadLabel; QDoubleSpinBox * SetResistanceLoad;


      QGroupBox * VoltageGroupBox;
      QGroupBox * CurrentGroupBox;
      QGroupBox * PowerGroupBox;
      QGroupBox * ResistanceGroupBox;

};

#endif // MONITOR_H
