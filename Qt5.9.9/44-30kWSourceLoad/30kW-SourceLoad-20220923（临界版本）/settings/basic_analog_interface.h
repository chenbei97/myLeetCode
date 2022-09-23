#ifndef ANALOGINTERFACE_H
#define ANALOGINTERFACE_H

#include <QDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QGridLayout>

class AnalogInterface : public QDialog
{
      Q_OBJECT
public:
      explicit AnalogInterface(QWidget*parent=Q_NULLPTR);
      enum RemoteControl {PROHIBT,ALLOW};
      enum VoltageRange {ZERO_ONE,ZERO_FIVE};
      enum PinSix {OT,PF,OT_PF};
      enum PinFourteen {OVP,OCP,OPP,OVP_OCP,OVP_OPP,OCP_OPP,OVP_OCP_OPP};
      enum PinFifteen {ADJUSTED_MODE,DC_CONDITION};
      enum VCMon {DEFAULT,EL,PS,EL_PS,AMODE,BMODE};
      enum RemSBState {NORMAL,FLIPPED};
      enum RemSBAction {DC_ON_OFF,DC_OFF};
      struct Settings
      {
            RemoteControl remoteControl;
            QString remoteControlString;
            VoltageRange voltageRange;
            QString voltageRangeString;
            PinSix pinSix;
            QString pinSixString;
            PinFourteen pinFourteen;
            QString pinFourteenString;
            PinFifteen pinFifteen;
            QString pinFifteenString;
            VCMon vcMon;
            QString vcMonString;
            RemSBState remSBState;
            QString remSBStateString;
            RemSBAction remSBAction;
            QString remSBActionString;

            // 提供1个默认构造函数,防止没初始化可能遇到的错误(字母数字无需tr,使用QStringLiteral可以利用移动语义)
            Settings(): remoteControl(PROHIBT),remoteControlString(tr("禁止"))
            ,voltageRange(ZERO_ONE),voltageRangeString(QStringLiteral("0.1 V"))
            ,pinSix(OT),pinSixString(QStringLiteral("OT"))
            ,pinFourteen(OVP),pinFourteenString(QStringLiteral("OVP"))
            ,pinFifteen(ADJUSTED_MODE),pinFifteenString(tr("调整模式"))
            ,vcMon(DEFAULT),vcMonString(tr("默认"))
            ,remSBState(NORMAL),remSBStateString(tr("正常状态"))
            ,remSBAction(DC_ON_OFF),remSBActionString(tr("直流开关状态"))
            {

            }
      };
      AnalogInterface::Settings settings() const;
      void setSettings(const AnalogInterface::Settings & settings);
private:
      void initUI();
      void initConnections();
      void updateSettings();
      void setComboBoxAlignCenter(QComboBox * combo); // 对comBoBox进行居中对齐的
private slots:
      void on_remoteControl(int checked);
      void on_voltageRange(int index);
      void on_pinSix(int index);
      void on_pinFourteen(int index);
      void on_pinFifteen(int index);
      void on_vcMon(int index);
      void on_remSBState(int index);
      void on_remSBAction(int index);
private:
      AnalogInterface::Settings mSettings;
      QGridLayout * mainLayout;
      QLabel * remoteControlLabel; // 允许远程控制 默认false
      QLabel * voltageRangeLabel;// 模拟接口范围 0.1V,0.5V 2个选项
      QLabel * pinSixLabel; // 引脚6 OT,PF以及OT&PF选项
      QLabel * pinFourteenLabel; // 引脚14 OVP,OCP,OPP,OVP&OCP,OVP&OPP,OCP&OPP,OVP&OCP&OPP
      QLabel * pinFifteenLabel; // 引脚15 调整模式/直流状况
      QLabel * vcMonLabel; // VMON/CMON 默认/实际电流EL/实际电流PS/实际电流EL&PS/A模式/B模式
      QLabel * remSBStateLabel; // 模拟接口Rem-SB状态, 正常/已翻转
      QLabel * remSBActionLabel;// 模拟接口Rem-SB动作,直流开&关/直流关

      QCheckBox * remoteControl;
      QComboBox * voltageRange;
      QComboBox * pinSix;
      QComboBox * pinFourteen;
      QComboBox * pinFifteen;
      QComboBox * vcMon;
      QComboBox * remSBState;
      QComboBox * remSBAction;
};
#endif // ANALOGINTERFACE_H
