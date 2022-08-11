#include "TestfixedQueryThread.h"
#include <QGridLayout>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

TestfixedQueryThread::TestfixedQueryThread(QWidget *parent)
  : QDialog(parent)
  , mPort(new QSerialPort)
  ,mFixedQueryTimer(new QTimer)
  ,mErrorStringShow(new QLabel("错误类型："))
  ,mTimeoutCountShow(new QLabel("超时次数："))
  ,mResponseStringShow(new QLabel("收到的回复："))
  ,mErrorString(new QLabel("NoError"))
  ,mTimeoutCount(new QLabel("0"))
  ,mResponseString(new QLabel("对方无应答"))
  ,mRequestCount(new QLabel("累计请求次数：0"))
  ,mResponseCount(new QLabel("累计回复次数：0"))
  ,serialPortComboBox(new QComboBox)
  ,serialBaudRateComboBox(new QComboBox)
  ,fixedQueryTime(new QComboBox)
  ,fixedQueryTimeShow(new QLabel("设定后台查询时间："))
{

     const auto infos1 = QSerialPortInfo::availablePorts();
     for (const QSerialPortInfo &info : infos1)
            this->serialPortComboBox->addItem(info.portName());
      this->serialPortComboBox->setCurrentIndex(4); // com6
     const auto infos2 = QSerialPortInfo::standardBaudRates();
      for (const qint32 &rate : infos2)
            this->serialBaudRateComboBox->addItem(QString::number(rate));
     this->serialBaudRateComboBox->setCurrentIndex(12); //115200

    QStringList supportedQueryTime;
    supportedQueryTime<<"100"<<"200"<<"300"<<"500"<<"800"<<"1000"<<"2000"<<"5000"; //支持的固定查询时间
    this->fixedQueryTime->addItems(supportedQueryTime);
    this->fixedQueryTime->setCurrentIndex(5); // 默认300ms

    QGridLayout * mainLayout = new QGridLayout;
    mainLayout->addWidget(mErrorStringShow, 0, 0);
    mainLayout->addWidget(mErrorString,0,1);
    mainLayout->addWidget(mTimeoutCountShow,1,0);
    mainLayout->addWidget(mTimeoutCount,1,1);
    mainLayout->addWidget(mResponseStringShow,2,0);
    mainLayout->addWidget(mResponseString,2,1);
    mainLayout->addWidget(mRequestCount,3,0);
    mainLayout->addWidget(mResponseCount,3,1);
    mainLayout->addWidget(serialPortComboBox,4,0);
    mainLayout->addWidget(serialBaudRateComboBox,4,1);
    mainLayout->addWidget(fixedQueryTimeShow,5,0);
    mainLayout->addWidget(fixedQueryTime,5,1);

    this->setLayout(mainLayout);
    this->setWindowTitle(tr("串口固定查询"));
    this->setFont(QFont("Time New Roman",12));

    qDebug()<<serialPortComboBox->currentText()<<"  "<<serialBaudRateComboBox->currentText().toUInt();
    mPort->setPortName(serialPortComboBox->currentText());
    mPort->setBaudRate(serialBaudRateComboBox->currentText().toUInt());
    mPort->moveToThread(&mFixedQueryThread); // 这句是为了解决下边的问题, https://blog.csdn.net/qq_35511927/article/details/121422908
    // QObject: Cannot create children for a parent that is in a different thread.
    // (Parent is QSerialPort(0x1794ba98), parent's thread is QThread(0x17947aa8), current thread is serialFixedQueryThread(0x7bfdc4)

    mFixedQueryTimer->setInterval(fixedQueryTime->currentText().toUInt()); // 必须写在连接信号之前
    connect(mFixedQueryTimer,SIGNAL(timeout()),this,SLOT(startFixedQueryThread()));

    connect(&mFixedQueryThread,SIGNAL(timeout(quint32)),this,SLOT(onTimeOut_FixedQueryThread(quint32)));
    connect(&mFixedQueryThread,SIGNAL(error(const QString&)),this,SLOT(onError_FixedQueryThread(const QString&)));
    connect(&mFixedQueryThread,SIGNAL(response(const QString&)),this,SLOT(onResponse_FixedQueryThread(const QString&)));
    connect(&mFixedQueryThread,SIGNAL(responseRequesetCount(quint32,quint32)),this,SLOT(onResponseRequesetCount_FixedQueryThread(quint32,quint32)));

    connect(serialPortComboBox,static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged),this,&TestfixedQueryThread::onPortNameChanged_ComboBox);
    connect(serialBaudRateComboBox,static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged),this,&TestfixedQueryThread::onBaudRateChanged_ComboBox);

    connect(fixedQueryTime,static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged),this,&TestfixedQueryThread::onFixedQueryTimeChanged_ComboBox);
    mFixedQueryTimer->start();
}

TestfixedQueryThread::~TestfixedQueryThread()
{
      if (!mFixedQueryTimer->isActive())
          mFixedQueryTimer->stop();
      delete  mFixedQueryTimer;
//      if (mFixedQueryThread.isRunning())
//          mFixedQueryThread.terminate(); // 用quit杀不掉
//       mFixedQueryThread.wait();
      QThread::currentThread()->quit();
}

void TestfixedQueryThread::startFixedQueryThread()
{
    qDebug()<<mPort->portName()<<"  "<<mPort->baudRate();
    mFixedQueryThread.startFixedQueryThread(mPort,fixedQueryTime->currentText().toUInt());
}

void TestfixedQueryThread::onTimeOut_FixedQueryThread(quint32 count)
{
     this->mTimeoutCount->setText(QString::number(count));
}
void TestfixedQueryThread::onError_FixedQueryThread(const QString& s)
{
     this->mErrorString->setText(s);
}
void TestfixedQueryThread::onResponse_FixedQueryThread(const QString&s)
{
     this->mResponseString->setText(s);
}

void TestfixedQueryThread::onResponseRequesetCount_FixedQueryThread(quint32 c1,quint32 c2)
{
     this->mResponseCount->setText(QString::asprintf("累计回复次数：%d",c1));
     this->mRequestCount->setText(QString::asprintf("累计请求次数：%d",c2));
}

void TestfixedQueryThread::onPortNameChanged_ComboBox(const QString &s)
{
    qDebug()<<"portname = "<<s;
    mPort->setPortName(s);
}
void TestfixedQueryThread::onBaudRateChanged_ComboBox(const QString &s)
{
  qDebug()<<"baudrate = "<<s.toUInt();
   mPort->setBaudRate(s.toUInt());
}
void TestfixedQueryThread::onFixedQueryTimeChanged_ComboBox(const QString &s)
{
    mFixedQueryTimer->stop();
    mFixedQueryTimer->setInterval(s.toUInt());
    mFixedQueryTimer->start();
}
