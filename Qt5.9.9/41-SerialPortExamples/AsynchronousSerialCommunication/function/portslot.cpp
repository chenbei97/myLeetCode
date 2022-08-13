#include "asyncTerminal.h"
#include "ui_asyncTerminal.h"
#include <QMessageBox>

void asyncTerminal::on_mPort_errorOccurred(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), this->mPort->errorString());
        this->on_actDisconnect_triggered(); // 关闭
    }
    if (error != QSerialPort::SerialPortError::NoError)
        ui->textMonitor->appendPlainText(QStringLiteral("Serial port error, error type: ")+this->mPort->errorString());
    else{
        ui->textMonitor->appendPlainText(QStringLiteral("Serial connection is normal"));
    }
}

void asyncTerminal::on_mPort_readyRead()
{
    QByteArray data = this->mPort->readAll();
    ui->textEditor->appendText(data);//串口读取到的数据写入文本编辑框
}
