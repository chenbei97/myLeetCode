#ifndef COMMONSETTINGS_H
#define COMMONSETTINGS_H

#include <QDialog>
#include <QComboBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QDoubleValidator>
#include <QLabel>
#include <QStandardItemModel>
#include <QDebug>

class CommonSettings : public QDialog
{
      Q_OBJECT
public:
      explicit CommonSettings(QWidget*parent=Q_NULLPTR);
      enum WorkMode {CV,CC};
      struct Settings
      {
            WorkMode workmode;
            QString workmodeString;
            double voltageRisingSlope;
            QString voltageRisingSlopeString;
            double voltageDropingSlope;
            QString voltageDropingSlopeString;
            double currentRisingSlope;
            QString currentRisingSlopeString;
            double currentDropingSlope;
            QString currentDropingSlopeString;
            double DcOutputDelayOn;
            QString DcOutputDelayOnString;
            double DcOutputDelayOff;
            QString DcOutputDelayOffString;

            // 提供1个默认构造函数,防止没初始化可能遇到的错误(字母数字无需tr)
            Settings (): workmode(WorkMode::CV), workmodeString(QStringLiteral("CV"))
              , voltageRisingSlope(0.00), voltageRisingSlopeString(QString::number(0.00,'f',2))
              , voltageDropingSlope(0.00), voltageDropingSlopeString(QString::number(0.00,'f',2))
              , currentRisingSlope(0.00), currentRisingSlopeString(QString::number(0.00,'f',2))
              , currentDropingSlope(0.00), currentDropingSlopeString(QString::number(0.00,'f',2))
              , DcOutputDelayOn(0.000), DcOutputDelayOnString(QString::number(0.000,'f',3))
              , DcOutputDelayOff(0.000), DcOutputDelayOffString(QString::number(0.000,'f',3))
            {

            }
      };
      CommonSettings::Settings settings() const;
      void setSettings(const CommonSettings::Settings& settings);
private:
      void initUI();
      void initConnections();
      void updateSettings();
private slots:
      void on_workMode(int index);
      void on_voltageRisingSlope(double d);
      void on_voltageDropingSlope(double d);
      void on_currentRisingSlope(double d);
      void on_currentDropingSlope(double d);
      void on_DcOutputDelayOn(double d);
      void on_DcOutputDelayOff(double d);
private:
      CommonSettings::Settings mSettings;
      QGridLayout * mainLayout;
      QComboBox * workMode; // CC/CV
      QDoubleSpinBox * voltageRisingSlope; // 电压上升斜率 V/ms
      QDoubleSpinBox * voltageDropingSlope;// 电压下降斜率 V/ms
      QDoubleSpinBox * currentRisingSlope;// 电流上升斜率 V/ms
      QDoubleSpinBox * currentDropingSlope; // 电流下降斜率 A/ms
      QDoubleSpinBox * DcOutputDelayOn; // 直流输出延时开  s
      QDoubleSpinBox * DcOutputDelayOff; // 直流输出延时关  s

      QLabel  * workModeLabel;
      QLabel * voltageRisingSlopeLabel;
      QLabel * voltageDropingSlopeLabel;
      QLabel * currentRisingSlopeLabel;
      QLabel * currentDropingSlopeLabel;
      QLabel * DcOutputDelayOnLabel;
      QLabel * DcOutputDelayOffLabel;
};

#endif // COMMONSETTINGS_H
