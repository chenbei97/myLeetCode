#include "testserialport.h"
#include "ui_testserialport.h"
#include  <QDebug>
#include <QStringList>
#include <QIODevice>
#include <QMessageBox>
TestSerialPort::TestSerialPort(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestSerialPort)
{
  ui->setupUi(this);

  this->volPort = this->portFactory.createPort();
  connect(this->volPort,&QSerialPort::readyRead,this,&TestSerialPort::receive_volPort_data);
  ui->statusbar->showMessage("当前运行模式为：xx模式");

  this->initialize_spinBox_component();


}
void TestSerialPort::initialize_spinBox_component() // 初始化spinbox组件
{
  // 1. 电压、电流、功率、内阻的doubleSpinBox初始化
  // 1.1 输入的步长设置
  ui->volInput->setSingleStep(0.01);
  ui->curInput->setSingleStep(0.01);
  ui->powInput->setSingleStep(0.01);
  ui->RInput->setSingleStep(1);

  // 1.2输出回读值不可修改
  ui->volOuput->setReadOnly(true);
  ui->curOuputEL->setReadOnly(true);
  ui->curOuputPS->setReadOnly(true);
  ui->powOuputEL->setReadOnly(true);
  ui->powOuputPS->setReadOnly(true);
  ui->ROuputEL->setReadOnly(true);
  ui->ROuputPS->setReadOnly(true);

  //1.3 只读值隐藏掉倒立的2个三角
  ui->volOuput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->curOuputEL->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->curOuputPS->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->powOuputEL->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->powOuputPS->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->ROuputEL->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->ROuputPS->setButtonSymbols(QAbstractSpinBox::NoButtons);

  // 1.4 设置后缀和初始值
  ui->volInput->setSuffix("V");
  ui->volOuput->setSuffix("V");
  ui->volInput->setValue(0.00);
  ui->volOuput->setValue(0.00);

  ui->curInput->setSuffix("A");
  ui->curOuputEL->setSuffix("A");
  ui->curOuputPS->setSuffix("A");
  ui->curInput->setValue(0.00);
  ui->curOuputEL->setValue(0.00);
  ui->curOuputPS->setValue(0.00);

  ui->powInput->setSuffix("kW");
  ui->powOuputEL->setSuffix("kW");
  ui->powOuputPS->setSuffix("kW");
  ui->powInput->setValue(0.0);
  ui->powOuputEL->setValue(0.0);
  ui->powOuputPS->setValue(0.0);

  ui->RInput->setSuffix("Ω");
  ui->ROuputEL->setSuffix("Ω");
  ui->ROuputPS->setSuffix("Ω");
  ui->RInput->setValue(0.00);
  ui->ROuputEL->setValue(0.00);
  ui->ROuputPS->setValue(0.00);

  // 2. 初始化串口名称和波特率的2个spinbox组件
  const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
  foreach (QSerialPortInfo info , infos){
       ui->serialNameBox->addItem(info.portName());
  }
 QList<qint32> baudrates = QSerialPortInfo::standardBaudRates();
 for(const qint32& baudrate : baudrates){
    ui->serialBaudRateBox->addItem(QString::asprintf("%d",baudrate));
   }
 ui->serialNameBox->setCurrentText("COM6");
 ui->serialBaudRateBox->setCurrentText("9600");
}

TestSerialPort::~TestSerialPort()
{
  delete ui;
}


void TestSerialPort::on_serialNameBox_currentIndexChanged(const QString &arg1)
{

  this->volPort->setPortName(arg1);
}


void TestSerialPort::on_serialBaudRateBox_currentIndexChanged(const QString &arg1)
{
    this->volPort->setBaudRate(arg1.toInt());
}

void TestSerialPort::receive_volPort_data()
{
  if (!this->volPort->isOpen()) this->volPort->open(QIODevice::ReadWrite);
  if (this->volPort->bytesAvailable()) {
      qDebug()<<"数据不为空,可以读取";
      QByteArray dataBytes = this->volPort->readAll();
      double data = dataBytes.toDouble();
      ui->volOuput->setValue(data);
    }
//  else{
//      QMessageBox::critical(this,"错误","缓存区没有数据!");
//    }
}
void TestSerialPort::on_volInput_valueChanged(double arg1)
{
    if (!this->volPort->isOpen()) {
        volPort->open(QIODevice::ReadWrite);
        if (this->volPort->isOpen())
           qDebug()<<volPort->portName()<<" opened successful, baudRate is "<<volPort->baudRate();
        else qDebug()<<"The serial port opened failed!";
    } else {
        qDebug()<<"The serial port is already open.";
    }
    const char * arg = QString::number(arg1,'f',2).toStdString().c_str();
   //  qDebug()<<arg;
    quint64 byteSize = this->volPort->write(arg);
    Q_UNUSED(byteSize);


    // this->volPort->close(); 要注释掉,否则收不到消息,串口的关闭会在串口管理类的析构函数自行关闭
}

void TestSerialPort::on_flushdata_clicked()
{
   receive_volPort_data();
}
