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
#include <iostream>
using std::cout;
using std::endl;
SerialPortCommunication::SerialPortCommunication(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::SerialPortCommunication)
{
  ui->setupUi(this);
  ui->statusbar->showMessage("当前运行模式为：xx模式");
  this->Port = this->portFactory.createPort();
  this->initialize_timer_component();
  this->initialize_spinBox_component();
  this->initialize_workStatus_component();
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
  // 1. 电压、电流、功率的doubleSpinBox初始化(按照CV模式初始化,电压1个,电流2个,功率2个)
  // 1.1 输入的步长设置
  ui->Input1->setSingleStep(0.01);
  ui->Input2PS->setSingleStep(0.01);
  ui->Input2EL->setSingleStep(0.01);
  ui->powInputEL->setSingleStep(0.01);
  ui->powInputPS->setSingleStep(0.01);
  // 1.2输出回读值不可修改
  ui->Ouput1->setReadOnly(true);
  ui->Ouput2->setReadOnly(true);
  ui->powOuput->setReadOnly(true);
  //1.3 只读值隐藏掉倒立的2个三角
  ui->Ouput1->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->Ouput2->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->powOuput->setButtonSymbols(QAbstractSpinBox::NoButtons);
  // 1.4 设置后缀和初始值
  ui->Input1->setSuffix("V");
  ui->Ouput1->setSuffix("V");
  ui->Input1->setValue(0.00);
  ui->Ouput1->setValue(0.00);

  ui->Input2EL->setSuffix("A");
  ui->Input2PS->setSuffix("A");
  ui->Ouput2->setSuffix("A");
  ui->Input2EL->setValue(0.00);
  ui->Input2PS->setValue(0.00);
  ui->Ouput2->setValue(0.00);

  ui->powInputPS->setSuffix("kW");
  ui->powInputEL->setSuffix("kW");
  ui->powOuput->setSuffix("kW");
  ui->powInputPS->setValue(0.0);
  ui->powInputEL->setValue(0.0);
  ui->powOuput->setValue(0.0);

   // 1.5 最大值设置
  ui->Input1->setMaximum(2000.);
  ui->Input2EL->setMaximum(2000.);
  ui->Input2PS->setMaximum(2000.);
  ui->powInputEL->setMaximum(2000.);
  ui->powInputPS->setMaximum(2000.);
  ui->Ouput1->setMaximum(2000.);
  ui->Ouput2->setMaximum(2000.);
  ui->powOuput->setMaximum(2000.);
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

  // 4
}

// 6. 1号框输入值设定,CV模式下为电压,CC模式下为电流
void SerialPortCommunication::on_Input1_valueChanged(double arg1)
{
  // 如果是CV,1号框就表示电压,电压只有1个;如果是CC,1号框表示电流,电流也只有1个
  // 所以对应的命令都是直接设置值的版本
  SPIC::COMMAND spic = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_VAL):
                                              (SPIC::COMMAND::SOUR_VOLT_SET_VAL);
  QString prefix = SPIC::spic(spic);
  prefix += QString::asprintf("%.2f",arg1);
  const char * res = prefix.toStdString().c_str();
  qDebug()<<res;
  this->Port->write(res);
}

// 7.  2号框输入值设定,PS状态,CV模式为电流,CC模式为电压
void SerialPortCommunication::on_Input2PS_valueChanged(double arg1)
{
  // 如果是CV,2号框就表示电流,电流有2个;如果是CC,2号框表示电压,电压有2个
  // 这里CV设置的电流和CC设置的电压都是PS状态
  SPIC::COMMAND spic = ui->rbtCV->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_LIM_POS):
                                              (SPIC::COMMAND::SOUR_VOLT_SET_LIM_POS);
  QString prefix = SPIC::spic(spic);
  prefix += QString::asprintf("%.2f",arg1);
  const char * res = prefix.toStdString().c_str();
  qDebug()<<res;
  this->Port->write(res);
}

// 8.  2号框输入值设定,EL状态,CV模式为电流,CC模式为电压
void SerialPortCommunication::on_Input2EL_valueChanged(double arg1)
{
  // 如果是CV,2号框就表示电流,电流有2个;如果是CC,2号框表示电压,电压有2个
  // 这里CV设置的电流和CC设置的电压都是EL状态
  SPIC::COMMAND spic = ui->rbtCV->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_LIM_NEG):
                                              (SPIC::COMMAND::SOUR_VOLT_SET_LIM_NEG);
  QString prefix = SPIC::spic(spic);
  prefix += QString::asprintf("%.2f",arg1);
  const char * res = prefix.toStdString().c_str();
  qDebug()<<res;
  this->Port->write(res);
}

// 9 . EL功率输入值设定,始终使用LIM版本的命令
void SerialPortCommunication::on_powInputEL_valueChanged(double arg1)
{
   // 无论是CC还是CV,PS状态对应命令不变
  QString prefix = SPIC::spic(SPIC::COMMAND::SOUR_POW_SET_LIM_NEG);
  prefix += QString::asprintf("%.2f",arg1*1000.0);
  const char * res = prefix.toStdString().c_str();
  qDebug()<<res;
  this->Port->write(res);
}

// 10.PS功率输入值设定,始终使用LIM版本的命令
void SerialPortCommunication::on_powInputPS_valueChanged(double arg1)
{
  // 无论是CC还是CV,PS状态对应命令不变
  QString prefix = SPIC::spic(SPIC::COMMAND::SOUR_POW_SET_LIM_POS);
  prefix += QString::asprintf("%.2f",arg1*1000.0);
  const char * res = prefix.toStdString().c_str();
  qDebug()<<res;
  this->Port->write(res);
}

// 11. 打开串口按钮
void SerialPortCommunication::on_openSerialPort_clicked()
{
   // 点击打开串口,连接信号,并open串口
  connect(this->Port,&QSerialPort::readyRead,this,&SerialPortCommunication::receive_port_data);

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

// 12. 关闭串口按钮
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

// 13. 串口接收数据的函数
void SerialPortCommunication::receive_port_data()
{

  QTime time = QTime::currentTime();
  if (!this->Port->isOpen()){
      qDebug()<<time.toString("hh::mm::ss")<<"No serial port is opened";
      return;
    }

  while (this->Port->bytesAvailable()) {
      qDebug()<<QDateTime::currentDateTime().toString("yyyy MM dd hh mm ss : ")
             <<this->Port->portName()<<"数据正在被读取";
      // 1.这种写法ok
//      char buf [1024];
//      qint64 lineLength = this->Port->readLine(buf,sizeof(buf));
//      if (lineLength != -1){
//          qDebug()<<buf;
//          // ui->Ouput1->setValue(QString(buf).toDouble());
//        }
      // 2.这种写法也可以
      QList<QByteArray> dataBytes = this->Port->readAll().split(';');
      if (dataBytes.size() == 4) {
            // 把读取的电压、电流、功率和状态寄存器值取出来
          ui->Ouput1->setValue(dataBytes[0].toDouble()) ;// 电压值
          ui->Ouput2->setValue(dataBytes[1].toDouble());
          ui->powOuput->setValue(dataBytes[2].toDouble());
          int status_opera = dataBytes[3].toInt(Q_NULLPTR,10);
          /*
        6 OFF 仪器on/off为off状态
        7 CC 正向恒流状态
        8 CV  恒压状态
        9 CW 正向恒功率状态
        11 CC- 负向恒流状态
        12 CP- 负向恒功率状态
         */
          // 一共13位,剩下的高位补0
          QString opera = QString::number(status_opera,2);
          int n = 13 - opera.size(); // 要补的0个数
          opera = opera.prepend(QString("0").repeated(n));
          qDebug()<<opera<<" "<<opera.size();
          qDebug()<<opera[opera.size()-7]; // 第6位
          qDebug()<<opera[opera.size()-8]; // 第7位
          qDebug()<<opera[opera.size()-9]; // 第8位
          qDebug()<<opera[opera.size()-10]; // 第9位
          qDebug()<<opera[opera.size()-12]; // 第11位
          qDebug()<<opera[opera.size()-13]; // 第12位,也就是最高位,为索引0的位置
        }
      else {
           // 可能有问题
        }
//      for
//      double data = dataBytes.toDouble();
//      ui->Ouput1->setValue(data);
    }
}

// 14. 初始化定时器,每300ms进行1次查询
void SerialPortCommunication::initialize_timer_component()
{
  this->timer = new QTimer();
  this->timer->setInterval(this->flushTime);
  this->timer->setTimerType(Qt::PreciseTimer);
  this->timer->setSingleShot(false);
  this->timer->start();
  connect(this->timer,&QTimer::timeout,this,&SerialPortCommunication::send_query_command);
}

// 15.每300ms此函数被调用1次,发布查询的命令来更新状态
void SerialPortCommunication::send_query_command()
{
   // 要查询的命令如下
  QList<QString> commands = {
    (SPIC::spic(SPIC::COMMAND::MEAS_VOLT_AVAE)+";"),//电压测量值=>Ouput1&Ouput2
    (SPIC::spic(SPIC::COMMAND::MEAS_CURR_AVAE)+";"),// 电流测量值=>Ouput1&Ouput2
    (SPIC::spic(SPIC::COMMAND::MEAS_POW_AVAE)+";"),//功率测量值=>powOuput
    (SPIC::spic(SPIC::COMMAND::GET_WORK_STATUS)+"\n")// 工作状态用位表示,OFF/ON[6],CC[7],CV[8],CW[9],CC-[11],CP-[12]
  };
  QString command = commands[0]+commands[1]+commands[2]+commands[3];
   this->Port->write(command.toStdString().c_str());// 假如转换成字符串必须在这里转,不能借助第三方函数转为const char*,否则会乱码或收的不对
}

void SerialPortCommunication::initialize_workStatus_component()
{
   ui->checkBoxCV->setChecked(true);
   ui->checkBoxCCPos->setChecked(false);
   ui->checkBoxCCNeg->setChecked(false);
   ui->checkBoxCPPos->setChecked(false);
   ui->checkBoxCPNeg->setChecked(false);

   ui->checkBoxCV->setEnabled(false);
   ui->checkBoxCCPos->setEnabled(false);
   ui->checkBoxCCNeg->setEnabled(false);
   ui->checkBoxCPPos->setEnabled(false);
   ui->checkBoxCPNeg->setEnabled(false);
}
// 根据CC&CV模式切换QLabel和QSpinBox的组件显示状态
void SerialPortCommunication::change_label_spinBox_component(const SPIC::STATUS &workMode)
{
   if (workMode == SPIC::STATUS::CV_WORK_MODE){//该枚举值作为FLAG使用
       // label文本为1号框是电压设置,2号框是电流设置
       ui->label_Input1->setText("电压设置：");
       ui->label_Input2_PS->setText("电流设置(PS)：");
       ui->label_Input2_EL->setText("电流设置(EL)：");
       // 相应的改变后缀符号为1号框"V",2号框"A"
       ui->Input1->setSuffix("V");
       ui->Input2PS->setSuffix("A");
       ui->Input2EL->setSuffix("A");
     }
   else if (workMode == SPIC::STATUS::CC_WORK_MODE){
       // label文本为1号框是电流设置,2号框是电流设置
       ui->label_Input1->setText("电流设置：");
       ui->label_Input2_PS->setText("电压设置(PS)：");
       ui->label_Input2_EL->setText("电压设置(EL)：");
       // 相应的改变后缀符号为1号框"A",2号框"V"
       ui->Input1->setSuffix("A");
       ui->Input2PS->setSuffix("V");
       ui->Input2EL->setSuffix("V");
     }
   else {
       //...
     }
}

void SerialPortCommunication::on_rbtCV_clicked(bool checked)
{
  checked? change_label_spinBox_component() : // cv模式
           change_label_spinBox_component(SPIC::STATUS::CC_WORK_MODE);// cc模式
}

void SerialPortCommunication::on_rbtCC_clicked(bool checked)
{
  checked? change_label_spinBox_component(SPIC::STATUS::CC_WORK_MODE) : // cc模式
           change_label_spinBox_component();// cv模式
}
