#include "serial/serial.h"

void SerialConfig::on_PortChanged(int index)
{
      if (index < -1) return;
      QStringList list = AvailPortsCombo->itemData(index).toStringList(); // 获取当前串口项的存储数据转为stringList
      // list的信息依次是串口名(0),串口位置(1),描述信息(2),制造商(3),供应商(4),和产品编号(5)
      // 使用三元运算符判断,没有这种信息的话就不打印.也就是空白字符串N/A
      PortLocationLabel->setText(tr("串口位置：%1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
      PortDescriptionLabel->setText(tr("串口信息：%1").arg(list.count() > 2 ? list.at(2) : tr(blankString)));
      PortManufacturerLabel->setText(tr("制造商：%1").arg(list.count() > 3 ? list.at(3) : tr(blankString)));
      PortVendorLabel->setText(tr("供应商：%1").arg(list.count() > 4 ? list.at(4) : tr(blankString)));
      PortIdentifierLabel->setText(tr("产品编号：%1").arg(list.count() > 5 ? list.at(5) : tr(blankString)));
}

void SerialConfig::on_BaudRateChanged(int index)
{

    if (index+1 == PortBaudRateCombo->count()) // 最后1个选项(自定义)
    {
        QStandardItemModel * model = qobject_cast<QStandardItemModel*>(PortBaudRateCombo->model());
        QStandardItem * item = model->item(index);
        item->setToolTip(tr("请注意,自定义波特率只支持[0,4000000]的范围!"));
        PortBaudRateCombo->setEditable(true); //可编辑,让用户自己输入
        PortBaudRateCombo->clearEditText();
        QLineEdit *lineEdit = PortBaudRateCombo->lineEdit();// 获取编辑框(QComboBox默认使用的代理是QLineEdit)
        lineEdit->setValidator(new QIntValidator(0, 4000000)); // 设置约束使之只能输入指定范围的整数
    }
    else {
        PortBaudRateCombo->setEditable(false); //改回来不可编辑
    }

}

void SerialConfig::on_OkBtn()
{
        // 串口名
        mSettings.Name = AvailPortsCombo->currentText();
        // 波特率
        mSettings.BaudRate = PortBaudRateCombo->currentText().toInt();
        mSettings.BaudRateString = QString::number(mSettings.BaudRate);
        // 数据位
        mSettings.DataBit = static_cast<QSerialPort::DataBits>(PortDataBitCombo->itemData(PortDataBitCombo->currentIndex()).toInt()); // 数据在初始化项时已经给了5,6,7,8
        mSettings.DataBitString = PortDataBitCombo->currentText();
        // 校验位
        mSettings.Parity = static_cast<QSerialPort::Parity>(PortParityCombo->itemData(PortParityCombo->currentIndex()).toInt());
        mSettings.ParityString = PortParityCombo->currentText();
        // 停止位
        mSettings.StopBit = static_cast<QSerialPort::StopBits>(PortStopBitCombo->itemData(PortStopBitCombo->currentIndex()).toInt());
        mSettings.StopBitString = PortStopBitCombo->currentText();
        // 流控制
        mSettings.FlowControl = static_cast<QSerialPort::FlowControl>(PortFlowControlCombo->itemData(PortFlowControlCombo->currentIndex()).toInt());
        mSettings.FlowControlString = PortFlowControlCombo->currentText();

         this->accept();
}
