#include "BlockingSerialPort.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>
#include <QtSerialPort/QSerialPortInfo>
QT_USE_NAMESPACE

BlockingSerialPort::BlockingSerialPort(QWidget *parent)
    : QDialog(parent)
    , transactionCount(0)
    , serialPortLabel(new QLabel(tr("串口名称：")))
    , serialPortComboBox(new QComboBox())
    , waitResponseLabel(new QLabel(tr("允许超时时间(ms)：")))
    , waitResponseSpinBox(new QSpinBox())
    , requestLabel(new QLabel(tr("发送的消息：")))
    , requestLineEdit(new QLineEdit(tr("你好！")))
    , trafficLabel(new QLabel(tr("没有新消息")))
    , statusLabel(new QLabel(tr("状态=>停止运行")))
    , runButton(new QPushButton(tr("开始")))
    ,timer(new QTimer)
{
      const auto infos = QSerialPortInfo::availablePorts();
      for (const QSerialPortInfo &info : infos)
            serialPortComboBox->addItem(info.portName());

      waitResponseSpinBox->setRange(0, 10000);
      waitResponseSpinBox->setValue(1000);

      QGridLayout * mainLayout = new QGridLayout;
      mainLayout->addWidget(serialPortLabel, 0, 0);
      mainLayout->addWidget(serialPortComboBox, 0, 1);
      mainLayout->addWidget(waitResponseLabel, 1, 0);
      mainLayout->addWidget(waitResponseSpinBox, 1, 1);
      mainLayout->addWidget(runButton, 0, 2, 1,1); // 位置在第1行第3列,行跨度2,列跨度1
      mainLayout->addWidget(requestLabel, 2, 0);
      mainLayout->addWidget(requestLineEdit, 2, 1, 1, 3);
      mainLayout->addWidget(trafficLabel, 3, 0, 1, 4);
      mainLayout->addWidget(statusLabel, 4, 0, 1, 5);
      this->setLayout(mainLayout);

      this->setWindowTitle(tr("Blocking Master"));
      serialPortComboBox->setFocus();

      timer->setInterval(1000);

      // connect(timer,&QTimer::timeout,runButton,&QPushButton::clicked);
      connect(timer,SIGNAL(timeout()),runButton,SIGNAL(clicked())); // 信号和信号绑定必须使用SIGNAL不能使用函数指针
      connect(runButton, &QPushButton::clicked, this, &BlockingSerialPort::transaction);
      connect(&thread, &myThread::response, this, &BlockingSerialPort::showResponse);
      connect(&thread, &myThread::error, this, &BlockingSerialPort::processError);
      connect(&thread, &myThread::timeout, this, &BlockingSerialPort::processTimeout);
}

BlockingSerialPort::~BlockingSerialPort()
{

}

void BlockingSerialPort::transaction()
{
    setControlsEnabled(false);  // 点击动作关联此函数,调用点击就设置使能false
    statusLabel->setText(tr("状态=>运行中, 正在连接串口%1") // 尝试连接
                         .arg(serialPortComboBox->currentText()));
    thread.transaction(serialPortComboBox->currentText(), // 线程以指定的时超时时间和发送的消息启动串口
                       waitResponseSpinBox->value(),
                       requestLineEdit->text()); // 内部启动线程
}

void BlockingSerialPort::showResponse(const QString &s)
{
    timer->start();
    setControlsEnabled(true); // 无论有没有回复都会解除冻结
    trafficLabel->setText(tr("收发次数=>%1次:" // 记录接收的消息次数
                             "\n\r---发送请求=>%2" // 换行显示之前发送的请求
                             "\n\r---收到回复=>%3") // 换行显示收到的回复
                          .arg(++transactionCount).arg(requestLineEdit->text()).arg(s));
}

void BlockingSerialPort::processError(const QString &s)
{
    // s是收到的回复：取值有：
    // error(tr("Can't open %1, error code %2").arg(portName).arg(serial.error()));
    // emit error(tr("No port name specified"));
    // 有错误的时候会进入此函数,例如打开一个已被占用的串口
    setControlsEnabled(true);
    statusLabel->setText(tr("状态=>停止运行, 串口错误类型=>%1").arg(s));
    trafficLabel->setText(tr("没有新消息"));
}

void BlockingSerialPort::processTimeout(const QString &s)
{
    // 串口是正常的只是收发超时
    setControlsEnabled(true);
    statusLabel->setText(tr("状态=>运行中, 超时错误类型=>%1.").arg(s));
    trafficLabel->setText(tr("No traffic."));

    // s的取值：写入或者读取超时
   // emit timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
   // emit timeout(tr("Wait write request timeout %1").arg(QTime::currentTime().toString()));
}

void BlockingSerialPort::setControlsEnabled(bool enable)
{
    runButton->setEnabled(enable);
    serialPortComboBox->setEnabled(enable);
    waitResponseSpinBox->setEnabled(enable);
    requestLineEdit->setEnabled(enable);
}

