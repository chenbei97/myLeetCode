#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"
#include  <QDebug>
#include <QIODevice>
#include <QMessageBox>
#include  <QList>
#include <QDateTime>
#include <QThread>
#include <QTimer>
#include <QCoreApplication>
SerialPortCommunication::SerialPortCommunication(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::SerialPortCommunication)
{
  ui->setupUi(this);
  ui->statusbar->showMessage("当前运行模式为：xx模式");
  this->Port = this->portFactory.createPort();
  this->initialize_spinBox_component();
}
// 0. 析构函数
SerialPortCommunication::~SerialPortCommunication()
{
  delete ui;
}

// 1. 私有函数 delay
void SerialPortCommunication::delay(unsigned int msec)
{
      //定义一个新的事件循环
      QEventLoop loop;
      //创建单次定时器,槽函数为事件循环的退出函数
      QTimer::singleShot(msec, &loop, SLOT(quit()));
      //事件循环开始执行,程序会卡在这里,直到定时时间到,本循环被退出
      loop.exec();
}

// 2. 私有函数sleep
void SerialPortCommunication::sleep(unsigned int msec)
{
      QTime dieTime = QTime::currentTime().addMSecs(msec);
      while( QTime::currentTime() < dieTime )
      {
          //强制进入当前线程的事件循环,这样可以把堵塞的事件都处理掉,从而避免程序卡死。
          QCoreApplication::processEvents();// QEventLoop::AllEvents, 100
          //如果去掉QCoreApplication::processEvents; 可以延时,但会阻塞线程
      }
}
// 3.串口名称选项变化时的槽函数
void SerialPortCommunication::on_serialNameBox_currentIndexChanged(const QString &arg1)
{
  this->Port->setPortName(arg1);
}

// 4. 波特率选项变化时的槽函数
void SerialPortCommunication::on_serialBaudRateBox_currentIndexChanged(const QString &arg1)
{
    this->Port->setBaudRate(arg1.toInt());
}

// 5.初始化spinbox组件的私有函数
void SerialPortCommunication::initialize_spinBox_component()
{
  // 1. 电压、电流、功率、内阻、回读时间的doubleSpinBox初始化
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
  ui->backReadTime->setReadOnly(true);

  //1.3 只读值隐藏掉倒立的2个三角
  ui->volOuput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->curOuputEL->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->curOuputPS->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->powOuputEL->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->powOuputPS->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->ROuputEL->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->ROuputPS->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->backReadTime->setButtonSymbols(QAbstractSpinBox::NoButtons);

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

  ui->backReadTime->setSuffix("ms");
  ui->backReadTime->setValue(0.00);

   // 1.5 最大值设置
  ui->volInput->setMaximum(2000.);
  ui->volOuput->setMaximum(2000.);
  ui->curInput->setMaximum(2000.);
  ui->curOuputPS->setMaximum(2000.);
  ui->curOuputEL->setMaximum(2000.);
  ui->powInput->setMaximum(2000.);
  ui->powOuputPS->setMaximum(2000.);
  ui->powOuputEL->setMaximum(2000.);
  ui->RInput->setMaximum(2000.);
  ui->ROuputEL->setMaximum(2000.);
  ui->ROuputPS->setMaximum(2000.);
  ui->backReadTime->setMaximum(1000.);
  // 2. 初始化串口名称和波特率的2个spinbox组件以及是否可编辑
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
 this->ui->serialNameBox->setEnabled(true); // 初始时可编辑
 this->ui->serialBaudRateBox->setEnabled(true);

 // 3.打开串口可编辑,关闭串口不可编辑
 this->ui->openSerialPort->setEnabled(true);
 this->ui->closeSerialPort->setEnabled(false);
}

// 6. 电压输入值设定
void SerialPortCommunication::on_volInput_valueChanged(double arg1)
{
     // 这里电压的输入值改变时应当发出设定的命令
    QString prefix= QString::asprintf("SOUR:VOLT %.2f\n",arg1);
    const char * res = prefix.toStdString().c_str();
     qDebug()<<res;
    this->Port->write(res);
}

// 7.电流输入值设定
void SerialPortCommunication::on_curInput_valueChanged(double arg1)
{
  // 这里电流的输入值改变时应当发出电电流设定的命令
  QString prefix= QString::asprintf("SOUR:CURR %.2f\n",arg1);
  const char * res = prefix.toStdString().c_str();
  qDebug()<<res;
  this->Port->write(res);
}
// 8 . 功率输入值设定
void SerialPortCommunication::on_powInput_valueChanged(double arg1)
{
   // 这里功率的输入值改变时应当发出功率设定的命令,单位是w
  QString prefix= QString::asprintf("SOUR:POW %.2f\n",arg1*1000.0);
  const char * res = prefix.toStdString().c_str();
  qDebug()<<res;
  this->Port->write(res);
}
// 9. 电阻输入值设定
void SerialPortCommunication::on_RInput_valueChanged(double arg1)
{
  // 这里电阻的输入值改变时应当发出电阻设定的命令
  QString prefix= QString::asprintf("SOUR:RES %.2f\n",arg1);
  const char * res = prefix.toStdString().c_str();
  qDebug()<<res;
  this->Port->write(res);
}

// 7. 打开串口按钮
void SerialPortCommunication::on_openSerialPort_clicked()
{
   // 点击打开串口,连接信号,并open串口
  connect(this->Port,&QSerialPort::readyRead,this,&SerialPortCommunication::receive_port_data);
  // connect(this->Port,&QSerialPort::readChannelFinished,this,&SerialPortCommunication::receive_volPort_data);
  if (!this->Port->isOpen())
    {
      Port->open(QIODevice::ReadWrite);
      if (this->Port->isOpen())
        qDebug()<<Port->portName()<<" serial port has been successfully opened, the baud rate is "<<Port->baudRate();
      else{
          qDebug()<<"The serial port failed to open, please check whether it is occupied or does not exist!";
          QMessageBox::critical(this,"错误","串口打开失败，请检查是否占用或者不存在!");
        }
    }
  else
    {
      qDebug()<<"The serial port is already open.";
      QMessageBox::information(this,"提示","串口已打开");
    }
   // this->Port->close(); 要注释掉,否则收不到消息,串口的关闭可以手动关闭,即使不关闭会在串口工厂类的析构函数自行关闭

  // 设置选择串口和波特率的组件、打开串口的按钮处于不可编辑状态，关闭串口处于可编辑状态
  this->ui->serialNameBox->setEnabled(false);
  this->ui->serialBaudRateBox->setEnabled(false);
  this->ui->openSerialPort->setEnabled(false);
  this->ui->closeSerialPort->setEnabled(true);
}

// 8. 关闭串口按钮
void SerialPortCommunication::on_closeSerialPort_clicked()
{
  // 恢复使能状态
  this->ui->serialNameBox->setEnabled(true);
  this->ui->serialBaudRateBox->setEnabled(true);
  this->ui->openSerialPort->setEnabled(true);
  this->ui->closeSerialPort->setEnabled(false);

    disconnect(this->Port,&QSerialPort::readyRead,this,&SerialPortCommunication::receive_port_data);
    this->Port->close();
}

// 9. 串口接收数据的函数
void SerialPortCommunication::receive_port_data()
{
  while (this->Port->bytesAvailable()) {
      qDebug()<<QDateTime::currentDateTime().toString("yyyy MM dd hh mm ss : ")<<this->Port->portName()<<" port has cached data, which can be read.";
      // 1.这种写法ok
      char buf [1024];
      qint64 lineLength = this->Port->readLine(buf,sizeof(buf));
      if (lineLength != -1){
          ui->volOuput->setValue(QString(buf).toDouble());
        }
      // 2.这种写法也可以
//      QByteArray dataBytes = this->Port->readAll();
//      double data = dataBytes.toDouble();
//      ui->volOuput->setValue(data);
    }
}


void SerialPortCommunication::send_command_to_hardware()
{

}
void SerialPortCommunication::receive_data_from_hardware()
{

}
