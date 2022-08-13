#include "asyncTerminal.h"
#include "ui_asyncTerminal.h"

// 初始化一些必要的功能
void asyncTerminal::init()
{
        // 主界面相关
        this->setMinimumWidth(1550);
        this->setMouseTracking(true); // 设置鼠标跟随

        // 界面动作使能相关
        ui->actConnect->setEnabled(true); // 初始时只能先连接串口和配置串口
        ui->actSetPortParams->setEnabled(true);
        ui->actDisconnect->setEnabled(false); // 不能断开串口

        // 串口相关
        this->mPort = new QSerialPort(this);

        // 串口配置相关
        this->mConfig = new portConfig(this);

        // 串口状态相关
        this->mPortStatus = new QLabel;
        this->mPortStatus->setMinimumWidth(400);
        ui->statusbar->addWidget(this->mPortStatus);

        // 文本编辑器相关
        ui->textEditor->setEnabled(false);

        // 文本监控器相关
        ui->textMonitor->setReadOnly(true);// 文本监控器不可编辑
        ui->textMonitor->appendPlainText(QString("文本编辑器宽度%1,高度%2").arg(ui->textEditor->width()).arg(ui->textEditor->height()));
}

// 初始化信号连接
void asyncTerminal::initConnections()
{
        // UI界面的退出动作
        connect(ui->actQuit,SIGNAL(triggered()),this,SLOT(close()));

        // 串口的errorOccurred和readyRead信号
        connect(this->mPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(on_mPort_errorOccurred(QSerialPort::SerialPortError)));
        connect(this->mPort, SIGNAL(readyRead()), this, SLOT(on_mPort_readyRead()));

        //  textEditor的2个信号,获取键盘输入写入串口和事件信号响应
        connect(ui->textEditor,SIGNAL(eventInformation(const QString&)),this,SLOT(on_textEditor_eventInfomation(const QString &)));
        connect(ui->textEditor,SIGNAL(forwardKeyInput(const QByteArray&)),this,SLOT(on_textEditor_forwardKeyInput(const QByteArray&)));
}
