#ifndef PARALLELSETTINGS_H
#define PARALLELSETTINGS_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QMessageBox>

class ParallelSettings : public QDialog
{
      Q_OBJECT
public:
      explicit ParallelSettings(QWidget * parent = Q_NULLPTR);
      enum MasterSlaveMode {OFF,MASTER,SLAVE};
      enum MasterSlaveState {UNINITIALIZED,INITIALIZED};
      struct Settings
      {
            MasterSlaveMode masterSlaveMode;
            QString masterSlaveModeString;
            MasterSlaveState masterModeState;
            QString masterModeStateString;
            int masterModbusAddress;
            QString masterModbusAddressString;
            int slaveCount;
            QString slaveCountString;

            Settings () : masterSlaveMode(OFF),masterSlaveModeString(tr("关闭"))
              , masterModeState(UNINITIALIZED),masterModeStateString(tr("未初始化"))
              , masterModbusAddress(1), masterModbusAddressString(QStringLiteral("1"))
              , slaveCount(0), slaveCountString(QStringLiteral("0"))
            {

            }
      };
      ParallelSettings::Settings settings() const;
      void setSettings(const ParallelSettings::Settings & settings);
private:
      ParallelSettings::Settings mSettings;
      QGridLayout * mainLayout;
private:
      void initUI();
      void initConnections();
      void updateSettings();
      void setComboBoxAlignCenter(QComboBox * combo);
private slots:
      void on_masterSlaveMode(int index);
      void on_masterModeState(int index);
      void on_masterModbusAddress(int value);
      void on_slaveCount(int value);
      void on_rebootSystem();
private:
      QLabel * masterSlaveModeLabel; // 主从模式: 关/主机/从机
      QLabel * masterModeStateLabel; // 主模式状态：未初始化/已初始化
      QLabel * masterModbusAddressLabel;// 本机/Modbus地址
      QLabel * slaveCountLabel;// 从机个数
      QComboBox * masterSlaveMode;
      QComboBox * masterModeState;
      QSpinBox * masterModbusAddress;
      QSpinBox * slaveCount;

      QPushButton * rebootSystem; // 重启系统
signals:
      void reboot(bool Checked = false); // 在rebootSystem中把这条消息发出去
};

#endif // PARALLELSETTINGS_H
