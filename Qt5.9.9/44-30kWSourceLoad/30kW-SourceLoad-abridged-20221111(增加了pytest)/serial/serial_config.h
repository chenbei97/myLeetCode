#ifndef SERIALCONFIG_H
#define SERIALCONFIG_H

#include <QObject>
#include <QDialog>
#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QIntValidator>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

static constexpr char blankString[] = QT_TRANSLATE_NOOP("SerialConfig", "N/A");
// 在SerialConfig上下文环境空白字符串翻译为N/A
class SerialConfig : public QDialog
{
      Q_OBJECT
public:
        struct Settings //串口配置参数
        {
            QString Name;
            qint32 BaudRate;
            QString BaudRateString;
            QSerialPort::DataBits DataBit;
            QString DataBitString;
            QSerialPort::Parity Parity;
            QString ParityString;
            QSerialPort::StopBits StopBit;
            QString StopBitString;
            QSerialPort::FlowControl FlowControl;
            QString FlowControlString;

            Settings() : Name(tr(""))
              , BaudRate(9600), BaudRateString(QString::number(9600))
              , DataBit(QSerialPort::Data8), DataBitString(QString::number(8))
              , Parity(QSerialPort::NoParity),ParityString(QStringLiteral("None"))
              , StopBit(QSerialPort::OneStop),StopBitString(QString::number(1))
              ,FlowControl(QSerialPort::NoFlowControl),FlowControlString(QStringLiteral("None"))
            {

            }
        };
      explicit SerialConfig(QWidget * parent = Q_NULLPTR);
      SerialConfig::Settings settings() const;
      void setSettings(const SerialConfig::Settings & settings);
protected:
      void paintEvent(QPaintEvent*e);
private:
      void initUI();
      void initConnections();
      void initPortInformation();
      void initPortConfig();
      void updateSettings();
private:
      void on_PortChanged(int index);
      void on_BaudRateChanged(int index);
      void on_OkBtn();
private:
      QGridLayout * mainLayout;
      SerialConfig::Settings mSettings;
private: // 串口信息
      QGroupBox * PortInformation;
      QComboBox * AvailPortsCombo;
      QLabel * PortNameLabel;
      QLabel * PortLocationLabel;
      QLabel * PortDescriptionLabel;
      QLabel * PortManufacturerLabel;
      QLabel * PortVendorLabel;
      QLabel * PortIdentifierLabel;
private: // 串口配置
      QGroupBox * PortConfig;
      QLabel * PortBaudRateLabel;
      QLabel * PortParityLabel;
      QLabel * PortDataBitLabel;
      QLabel * PortStopBitLabel;
      QLabel * PortFlowControlLabel;
      QComboBox * PortBaudRateCombo;
      QComboBox * PortParityCombo;
      QComboBox * PortDataBitCombo;
      QComboBox * PortStopBitCombo;
      QComboBox * PortFlowControlCombo;
private:
      QPushButton * okBtn;
};

#endif // SERIALCONFIG_H
