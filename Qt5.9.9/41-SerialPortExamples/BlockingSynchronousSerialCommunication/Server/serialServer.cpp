#include "serialServer.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QtSerialPort/QSerialPortInfo>

serialServer::serialServer(QWidget *parent)
    : QDialog(parent)
    , processRequestCount(0)
    , serialPortLabel(new QLabel(tr("串口名称：")))
    , serialPortComboBox(new QComboBox())
    , waitRequestLabel(new QLabel(tr("设置允许客户端请求超时时间(ms)：")))
    , waitRequestSpinBox(new QSpinBox())
    , responseLabel(new QLabel(tr("设置发送客户端的回复：")))
    , responseLineEdit(new QLineEdit(tr("我很好!")))
    , trafficLabel(new QLabel(tr("当前没有客户端的新请求")))
    , statusLabel(new QLabel(tr("当前服务端状态：未连接")))
    , runButton(new QPushButton(tr("开始/更新连接")))
{

    this->waitRequestSpinBox->setRange(0, 10000);
    this->waitRequestSpinBox->setValue(10000); // 默认超时等待时间为10s

    const auto infos = QSerialPortInfo::availablePorts(); // 可用串口更新列表
    for (const QSerialPortInfo &info : infos)
        this->serialPortComboBox->addItem(info.portName());

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(serialPortLabel, 0, 0);
    mainLayout->addWidget(serialPortComboBox, 0, 1);
    mainLayout->addWidget(waitRequestLabel, 1, 0);
    mainLayout->addWidget(waitRequestSpinBox, 1, 1);
    mainLayout->addWidget(runButton, 0, 2, 1, 1);
    mainLayout->addWidget(responseLabel, 2, 0);
    mainLayout->addWidget(responseLineEdit, 2, 1, 1, 3);
    mainLayout->addWidget(trafficLabel, 3, 0, 1, 4);
    mainLayout->addWidget(statusLabel, 4, 0, 1, 5);
    this->setLayout(mainLayout);
    this->setWindowTitle(tr("串口服务端"));
    this->serialPortComboBox->setFocus();
    this->setFont(QFont("Time New Roman",12));

    connect(runButton, &QPushButton::clicked, this, &serialServer::startServerThread);
    connect(&thread, &serverThread::request, this,&serialServer::processRequest);
    connect(&thread, &serverThread::error, this, &serialServer::processError);
    connect(&thread, &serverThread::timeout, this, &serialServer::processTimeout);
    // 重载版本的信号需要事先静态转换,currentIndexChanged和valueChanged有const QString&和int2个版本
    connect(serialPortComboBox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),this, &serialServer::activateRunButton);
    connect(waitRequestSpinBox, static_cast<void (QSpinBox::*)(const QString &)>(&QSpinBox::valueChanged),this, &serialServer::activateRunButton);
    connect(responseLineEdit, &QLineEdit::textChanged, this, &serialServer::activateRunButton);
}

serialServer::~serialServer()
{

}

// 开启串口服务端线程
void serialServer::startServerThread()
{
    this->runButton->setEnabled(false);
    this->statusLabel->setText(tr("当前服务端状态：已连接串口%1").arg(serialPortComboBox->currentText()));
    this->thread.startServerThread(serialPortComboBox->currentText(),waitRequestSpinBox->value(),responseLineEdit->text());
}

// 处理来自客户端的请求
void serialServer::processRequest(const QString &s)
{
    this->statusLabel->setText(tr("当前服务端状态：已连接且正常处理请求"));
    this->trafficLabel->setText(tr("有来自客户端的新请求(请求累计次数为%1)："
                             "\n\r---客户端发送的请求： %2"
                             "\n\r---服务端回复的消息：%3")
                          .arg(++this->processRequestCount).arg(s).arg(this->responseLineEdit->text()));
}

// 处理错误(无论是客户端导致还是服务端导致)
void serialServer::processError(const QString &s)
{
    this->activateRunButton();
    this->statusLabel->setText(tr("当前服务端状态：未连接 错误原因：%1").arg(s));
    this->trafficLabel->setText(tr("当前没有客户端的新请求"));
}

// 处理超时(无论是1.客户端发送请求超时2.服务端发送回复超时3.服务端读取请求超时)
void serialServer::processTimeout(const QString &s)
{
    this->statusLabel->setText(tr("当前服务端状态：已连接  超时原因：%1").arg(s));
    this->trafficLabel->setText(tr("当前没有客户端的新请求"));
}

// 更新按钮使能
void serialServer::activateRunButton()
{
    this->runButton->setEnabled(true);
}
