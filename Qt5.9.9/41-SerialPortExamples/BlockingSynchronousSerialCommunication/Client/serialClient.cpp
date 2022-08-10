#include "serialClient.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>

serialClient::serialClient(QWidget *parent)
    : QDialog(parent)
    , processResponseCount(0)
    , serialPortLabel(new QLabel(tr("串口名称：")))
    , serialPortComboBox(new QComboBox())
    , waitResponseLabel(new QLabel(tr("设置允许服务端回复超时时间(ms)：")))
    , waitResponseSpinBox(new QSpinBox())
    , requestLabel(new QLabel(tr("设置发送客户端的请求：")))
    , requestLineEdit(new QLineEdit(tr("你好吗?")))
    , trafficLabel(new QLabel(tr("当前没有服务端的新回复")))
    , statusLabel(new QLabel(tr("当前客户端状态：未连接")))
    , runButton(new QPushButton(tr("开始/更新连接")))
    , timer(new QTimer)
{
      const auto infos = QSerialPortInfo::availablePorts();
      for (const QSerialPortInfo &info : infos)
            this->serialPortComboBox->addItem(info.portName());

      this->waitResponseSpinBox->setRange(0, 10000);
      this->waitResponseSpinBox->setValue(1000);

      QGridLayout * mainLayout = new QGridLayout;
      mainLayout->addWidget(serialPortLabel, 0, 0);
      mainLayout->addWidget(serialPortComboBox, 0, 1);
      mainLayout->addWidget(waitResponseLabel, 1, 0);
      mainLayout->addWidget(waitResponseSpinBox, 1, 1);
      mainLayout->addWidget(runButton, 0, 2, 1,1);
      mainLayout->addWidget(requestLabel, 2, 0);
      mainLayout->addWidget(requestLineEdit, 2, 1, 1, 3);
      mainLayout->addWidget(trafficLabel, 3, 0, 1, 4);
      mainLayout->addWidget(statusLabel, 4, 0, 1, 5);
      this->setLayout(mainLayout);
      this->setWindowTitle(tr("串口客户端"));
      this->serialPortComboBox->setFocus();
      this->setFont(QFont("Time New Roman",12));

      timer->setInterval(1000);
      //connect(timer,&QTimer::timeout,runButton,&QPushButton::clicked);
      connect(timer,SIGNAL(timeout()),runButton,SIGNAL(clicked())); // 信号和信号绑定必须使用SIGNAL不能使用函数指针
      connect(runButton, &QPushButton::clicked, this, &serialClient::startClientThread);
      connect(&thread, &clientThread::response, this, &serialClient::processResponse);
      connect(&thread, &clientThread::error, this, &serialClient::processError);
      connect(&thread, &clientThread::timeout, this, &serialClient::processTimeout);
}

serialClient::~serialClient()
{

}

// 开启串口客户端线程
void serialClient::startClientThread()
{
    this->timer->start();
    this->setControlsEnabled(false);  // 开启后就不能再次点击,有回复/超时/错误发生会解除冻结
    statusLabel->setText(tr("当前客户端状态：已连接串口%1").arg(serialPortComboBox->currentText()));
    thread.startClientThread(serialPortComboBox->currentText(),waitResponseSpinBox->value(),requestLineEdit->text()); // 内部启动线程
}

// 处理来自服务端的回复
void serialClient::processResponse(const QString &s)
{
    this->statusLabel->setText(tr("当前客户端状态：已连接且正常收到回复"));
    this->setControlsEnabled(true); // 无论有没有回复都会解除冻结
    trafficLabel->setText(tr("有来自服务端的新回复(回复累计次数为%1)：" // 记录接收的消息次数
                             "\n\r---客户端发送的请求：%2"
                             "\n\r---服务端回复的消息：%3")
                          .arg(++processResponseCount).arg(this->requestLineEdit->text()).arg(s));
}

// 处理错误(无论是客户端导致还是服务端导致)
void serialClient::processError(const QString &s)
{
    this->setControlsEnabled(true);
    this->statusLabel->setText(tr("当前客户端状态：未连接 错误原因：%1").arg(s));
    this->trafficLabel->setText(tr("当前没有服务端的新回复"));
}

// 处理超时(无论是1.服务端回复超时2.客户端发送请求超时3.客户端读取回复超时)
void serialClient::processTimeout(const QString &s)
{
    this->setControlsEnabled(true);
    this->statusLabel->setText(tr("当前客户端状态：已连接  超时原因：%1.").arg(s));
    this->trafficLabel->setText(tr("当前没有服务端的新回复"));
}

// 控制4个组件的冻结
void serialClient::setControlsEnabled(bool enable)
{
    this->runButton->setEnabled(enable);
    this->serialPortComboBox->setEnabled(enable);
    this->waitResponseSpinBox->setEnabled(enable);
    this->requestLineEdit->setEnabled(enable);
}
