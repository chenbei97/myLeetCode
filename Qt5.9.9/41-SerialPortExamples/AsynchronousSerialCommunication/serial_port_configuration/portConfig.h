#ifndef PORTCONFIG_H
#define PORTCONFIG_H

#include <QDialog>
#include <QSerialPort>
#include <QIntValidator>

namespace Ui {
class portConfig;
}
class portConfig : public QDialog
{
    Q_OBJECT
public:
        struct Configs //串口配置参数
        {
            QString name;
            qint32 baudRate;
            QString stringBaudRate;
            QSerialPort::DataBits dataBits;
            QString stringDataBits;
            QSerialPort::Parity parity;
            QString stringParity;
            QSerialPort::StopBits stopBits;
            QString stringStopBits;
            QSerialPort::FlowControl flowControl;
            QString stringFlowControl;
        };
        Configs configs() const; // 返回设置的串口参数
        explicit portConfig(QWidget *parent = nullptr);
        ~portConfig();
private slots:
        void on_btnConfigSure_clicked();// 应用配置,点击确定
        void on_availPortsComboBox_currentIndexChanged(int index);
        void on_portBaudRateCombo_currentIndexChanged(int index);
private:
        void initAvailPorts();
        void showPortInfo(int idx);
        void initConfigs();
        void updateConfigs(); // 用户点击确定后会更新设置
private:
        Ui::portConfig *ui;
        Configs currentConfigs; // 当前的串口配置参数
        QIntValidator * intValidator; // 用于限制lineEdit(comboBox)的输入必须是指定的整数
};
#endif // PORTCONFIG_H
