#include "portConfig.h"
#include "ui_portConfig.h"
#include <QSerialPortInfo>

void portConfig::initConfigs()
{
    // 波特率
    QList<qint32> baudrates = QSerialPortInfo::standardBaudRates();
    QStringList stringBaudrates;
    foreach (const quint32& rate, baudrates)
                stringBaudrates << QString::number(rate,10);
    ui->portBaudRateCombo->addItems(stringBaudrates);
    ui->portBaudRateCombo->addItem(tr("Custom"));
    ui->portBaudRateCombo->setEditable(false);
    ui->portBaudRateCombo->setCurrentIndex(12); // 对应115200的位置

    // 数据位,QStringLiteral可以避免QString临时变量的复制
    ui->portDataBitsCombo->addItem(QStringLiteral("5"), QSerialPort::Data5); // 存储到指定userData下
    ui->portDataBitsCombo->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->portDataBitsCombo->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->portDataBitsCombo->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->portDataBitsCombo->setCurrentIndex(3); // 默认是Data8

    // 校验位
    ui->portParityCombo->addItem(tr("None"), QSerialPort::NoParity);// 存储到指定userData下
    ui->portParityCombo->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->portParityCombo->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->portParityCombo->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->portParityCombo->addItem(tr("Space"), QSerialPort::SpaceParity);

    // 停止位
    ui->portStopBitCombo->addItem(QStringLiteral("1"), QSerialPort::OneStop);// // 存储到指定userData下
    #ifdef Q_OS_WIN // 此类型的停止位只支持window平台
    ui->portStopBitCombo->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
    #endif
    ui->portStopBitCombo->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    // 流控制
    ui->portFlowControlCombo->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->portFlowControlCombo->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->portFlowControlCombo->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
}
