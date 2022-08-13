#include "asyncTerminal.h"
#include "ui_asyncTerminal.h"
#include <QMessageBox>
#include <QDebug>

// 1. 配置串口
void asyncTerminal::on_actSetPortParams_triggered()
{
        this->mConfig->show();// 显示出来让用户设置
}

// 2. 连接串口
void asyncTerminal::on_actConnect_triggered()
{
    // 执行顺序是:先连接串口(可以事先配置或者不配置使用默认的),如果配置过,也就是点击确定按钮时内部更新了currentConfigs
    // 此时主窗口连接串口时就得到的是最新设置的参数,这也是主窗口和子窗口交互的关键,无需通过槽机制,而是通过一个逻辑关系利用公共函数得到最新配置
    portConfig::Configs p = this->mConfig->configs(); // 获取最新配置
    this->mPort->setPortName(p.name);
    this->mPort->setBaudRate(p.baudRate);
    this->mPort->setDataBits(p.dataBits);
    this->mPort->setParity(p.parity);
    this->mPort->setStopBits(p.stopBits);
    this->mPort->setFlowControl(p.flowControl);

    if (this->mPort->open(QIODevice::ReadWrite)) {
        ui->textEditor->setEnabled(true); // 可以编辑
        ui->actDisconnect->setEnabled(true);// 只允许断开串口
        ui->actConnect->setEnabled(false);
        ui->actSetPortParams->setEnabled(false);
        QString info = tr("Connected to %1 : baudrate %2, databit %3, parity %4, stopbit %5, flowcontrol %6")
                .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl);
        this->mPortStatus->setText(info);
        ui->textMonitor->appendPlainText(info);
    }
    else
    {
        QMessageBox::critical(this, tr("串口打开错误"), this->mPort->errorString());
        this->mPortStatus->setText(tr("Serial Port Open error"));
        ui->textMonitor->appendPlainText(tr("Serial Port Open error"));
    }
}

// 3. 断开连接
void asyncTerminal::on_actDisconnect_triggered()
{
    if (this->mPort->isOpen())
        this->mPort->close();
    ui->textEditor->setEnabled(false); // 不可编辑
    ui->actConnect->setEnabled(true);
    ui->actSetPortParams->setEnabled(true);
    ui->actDisconnect->setEnabled(false);
    this->mPortStatus->setText(QStringLiteral("Disconnected"));
}

// 4. 清空消息
void asyncTerminal::on_actClear_triggered()
{
    ui->textEditor->clear();
    ui->textMonitor->clear();
}

// 5. 关于应用
void asyncTerminal::on_actAbout_triggered()
{
    QMessageBox::about(this, tr("About App"),
                       tr(" <b>This is a show how to use asynchronous mode for serial communication.</b> \n"
                          " The interface mainly has three functions: connecting the serial port, disconnecting the connection and configuring serial port parameters. \n"
                          " On the left side of the interface is a text editor, which can input characters, which will be automatically written to the serial port and sent to the receiver, "
                          " and will also automatically read the messages from the other party. \n"
                          " On the right side of the interface is a text monitor for monitoring various operations (mouse and keys) in the text editor."));
}

// 6. 关于Qt
void asyncTerminal::on_actAboutQt_triggered()
{
        QMessageBox::aboutQt(this,"关于Qt");
}
