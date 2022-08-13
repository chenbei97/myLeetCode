#include "portConfig.h"
#include "ui_portConfig.h"
#include <QSerialPortInfo>

static const char blankString[] = QT_TRANSLATE_NOOP("portConfig", "N/A"); // 在portConfig上下文环境空白字符串翻译为N/A

// 初始化可用串口并存储它们的信息到对应下拉项
void portConfig::initAvailPorts()
{
        ui->availPortsComboBox->clear();
        QString name; // 串口名称
        QString serialNumber; // 串口编号
        QString location; // 串口位置
        QString description; // 描述信息
        QString manufacturer; // 制造商
        quint16 vendor; // 供应商编号
        quint16 productIdentifier; // 产品编号
        const auto infos = QSerialPortInfo::availablePorts(); // 可用串口

        for (const QSerialPortInfo &info : infos)
        {
                QStringList list;
                name = info.portName();
                serialNumber = info.serialNumber();
                location = info.systemLocation();
                description = info.description();
                manufacturer = info.manufacturer();
                vendor = info.vendorIdentifier();
                productIdentifier = info.productIdentifier();

                // 信息为空时就打印N/A表示空白
                list << name
                     << location
                     << (!serialNumber.isEmpty() ? serialNumber : blankString)
                     << (!description.isEmpty() ? description : blankString)
                     << (!manufacturer.isEmpty() ? manufacturer : blankString)
                     << (vendor ? QString::number(info.vendorIdentifier(), 16) : blankString)
                     << (productIdentifier ? QString::number(info.productIdentifier(), 16) : blankString);
                ui->availPortsComboBox->addItem(info.portName(),list); // 注意这里,list也存进去了,每个项存储对应的信息
        }
}

// 打印串口的信息
void portConfig::showPortInfo(int idx)
{
    if (idx == -1)
        return;

    QStringList list = ui->availPortsComboBox->itemData(idx).toStringList(); // 获取当前串口项的存储数据转为stringList
    // list的信息依次是串口名(0),串口编号(1),串口位置(2),描述信息(3),制造商(4),供应商(5),和产品编号(6)
    // 使用三元运算符判断,没有这种信息的话就不打印.也就是空白字符串N/A
    ui->portNumberId->setText(tr("串口编号：%1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    ui->portLocation->setText(tr("串口位置：%1").arg(list.count() > 2 ? list.at(2) : tr(blankString)));
    ui->portDesrciption->setText(tr("描述信息：%1").arg(list.count() > 3 ? list.at(3) : tr(blankString)));
    ui->portManufacturer->setText(tr("制造商：%1").arg(list.count() > 4 ? list.at(4) : tr(blankString)));
    ui->portVendor->setText(tr("供应商：%1").arg(list.count() > 5 ? list.at(5) : tr(blankString)));
    ui->portProductId->setText(tr("产品编号：%1").arg(list.count() > 6 ? list.at(6) : tr(blankString)));
}
