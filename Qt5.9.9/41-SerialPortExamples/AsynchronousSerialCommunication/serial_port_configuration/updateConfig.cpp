#include "portConfig.h"
#include "ui_portConfig.h"
#include <QDebug>

void portConfig::updateConfigs()
{
        // 串口名
        this->currentConfigs.name = ui->availPortsComboBox->currentText();

        // 波特率
         // 这里在initConfig.cpp中没有给波特率的每个项加用户数据,所以这里是不能使用itemData获取对应的波特率的
        // this->currentConfigs.baudRate = static_cast<qint32>( ui->portBaudRateCombo->itemData( // 传入索引参数,返回值是QVariant,所以必须强制转换为qint32类型
        //        ui->portBaudRateCombo->currentIndex()).toInt());  // 因为currentIndex()是字符串,需要转为int传入
        this->currentConfigs.baudRate = ui->portBaudRateCombo->currentText().toInt(); // 直接获取当前的索引即可
        this->currentConfigs.stringBaudRate = QString::number(this->currentConfigs.baudRate); // 字符串表示

        // 数据位
        this->currentConfigs.dataBits = static_cast<QSerialPort::DataBits>(
                    ui->portDataBitsCombo->itemData(ui->portDataBitsCombo->currentIndex()).toInt());
        this->currentConfigs.stringDataBits = ui->portDataBitsCombo->currentText();// 字符串表示

        // 校验位
        this->currentConfigs.parity = static_cast<QSerialPort::Parity>(
                    ui->portParityCombo->itemData(ui->portParityCombo->currentIndex()).toInt());
        this->currentConfigs.stringParity = ui->portParityCombo->currentText();// 字符串表示

        // 停止位
        this->currentConfigs.stopBits = static_cast<QSerialPort::StopBits>(
                    ui->portStopBitCombo->itemData(ui->portStopBitCombo->currentIndex()).toInt());
        this->currentConfigs.stringStopBits = ui->portStopBitCombo->currentText();// 字符串表示

        // 流控制
        this->currentConfigs.flowControl = static_cast<QSerialPort::FlowControl>(
                    ui->portFlowControlCombo->itemData(ui->portFlowControlCombo->currentIndex()).toInt());
        this->currentConfigs.stringFlowControl = ui->portFlowControlCombo->currentText();// 字符串表示
}
