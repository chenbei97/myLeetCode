#include "testserialport.h"
#include "ui_testserialport.h"
#include  <QDebug>
#include <QList>
TestSerialPort::TestSerialPort(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestSerialPort)
{
  ui->setupUi(this);
  ui->statusbar->showMessage("当前运行模式为：xx模式");
  this->initialize_spinBox_component();
  this->initialize_serial_port();
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
}

TestSerialPort::~TestSerialPort()
{
  delete ui;
}
void TestSerialPort::initialize_serial_port()
{
   this->port = new QSerialPort(this);

  const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
  // qDebug()<<infos.empty();
  for (const QSerialPortInfo &info : infos){
      // qDebug()<<info.portName();
      ui->serialNameBox->addItem(info.portName());
    }
 QList<qint32> baudrates = QSerialPortInfo::standardBaudRates();
 for(const qint32& baudrate : baudrates){
    // qDebug()<<baudrate;
     ui->serialBaudRateBox->addItem(QString::asprintf("%d",baudrate));
   }
}
void TestSerialPort::print_serial_port_info() // 用于调试用的
{
  qDebug()<<this->port->portName();
  qDebug()<<this->port->baudRate();
}

void TestSerialPort::on_serialNameBox_currentIndexChanged(const QString &arg1)
{
  this->port->setPortName(arg1);
// print_serial_port_info();
}


void TestSerialPort::on_serialBaudRateBox_currentIndexChanged(const QString &arg1)
{
    this->port->setBaudRate(arg1.toInt());
   // print_serial_port_info();
}


void TestSerialPort::on_volInput_valueChanged(double arg1)
{
    qDebug()<<arg1;
}
