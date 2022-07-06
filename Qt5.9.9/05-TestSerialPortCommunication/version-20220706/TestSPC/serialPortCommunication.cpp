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
  : QMainWindow(parent),ui(new Ui::SerialPortCommunication)
{
        // 列表初始化
        // 1.初始化电源状态
        // 2.初始化工作模式
        // 3.初始化工作状态
        // 4.初始化串口状态
        ui->setupUi(this);
        ui->statusbar->showMessage("当前运行模式为：xx模式");
        this->Port = this->portFactory.createPort(); // 初始化串口
        this->initialize_member_variables(); // 初始化枚举值和数值成员变量
        this->initialize_ui_components();// 初始化UI组件的一些性质
        //this->initialize_timer_component();// 初始化定时器与查询函数的绑定
}
void SerialPortCommunication::initialize_member_variables()
{
      // 1. 初始化枚举值变量
      this->serialstate = SPIC::serialState::UNKNOW;
      this->powerstate = SPIC::powerState::UNKNOW;
      this->workmode = SPIC::workMode::UNKNOW;
      this->workstatus = SPIC::workStatus::UNKNOW;
      this->senderinfo = SPIC::senderInfo::UNKNOW;

      // 2.初始化CV/CC模式下U/I/P的输出设定值成员变量
      this->cv_volt = 0.; // 单位V,A,kW
      this->cv_curr_ps = 0.;
      this->cv_curr_el = 0.;
      this->cc_curr = 0.;
      this->cc_volt_ps = 0.;
      this->cc_volt_el = 0.;
      this->pow_ps = 0.;
      this->pow_el = 0.;
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

bool SerialPortCommunication::strcpy(char *dst, char *src)
{
   if (src == nullptr){
        dst = nullptr;
        return false;
   }
   if (dst == nullptr){
      return false;
   }
   while ((*(dst++) = *(src++))){}; // 多加1层括号,解决警告信息
   return true;
}
bool SerialPortCommunication::strcpy(int *dst, char *src)
{
     if (src == nullptr){
        dst = nullptr;
        return false;
   }
   if (dst == nullptr){
      return false;
   }
   while (*src != '\0'){
          *dst = static_cast<int>(*src) - static_cast<int>('0'); // 将其转为int类型
          ++dst;
          ++src;
   }
   return true;
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
void SerialPortCommunication::initialize_ui_components()
{
        // 1. 只读只写的电压、电流、功率的doubleSpinBox初始化
        // 默认先按照CV模式初始化,电压1个,电流2个,功率2个
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
        // 1.4 初始值设定
        ui->Input1->setValue(0.00);
        ui->Input2EL->setValue(0.00);
        ui->Input2PS->setValue(0.00);
        ui->powInputPS->setValue(0.0);
        ui->powInputEL->setValue(0.0);
        ui->Ouput1->setValue(0.00);
        ui->Ouput2->setValue(0.00);
        ui->powOuput->setValue(0.0);
        // 1.5 设置后缀和初始值
        ui->Input1->setSuffix("V"); // 按CV模式设置的是1个电压
        ui->Input2EL->setSuffix("A");  // 按CV模式设置的是2个电流
        ui->Input2PS->setSuffix("A");
        ui->powInputPS->setSuffix("kW"); // 功率值不论CC还是CV都是2个
        ui->powInputEL->setSuffix("kW");
        ui->Ouput2->setSuffix("A");
        ui->Ouput1->setSuffix("V");
        ui->powOuput->setSuffix("kW");
         // 1.6 最大值设置
        ui->Input1->setMaximum(2000.);
        ui->Input2EL->setMaximum(2000.);
        ui->Input2PS->setMaximum(2000.);
        ui->powInputEL->setMaximum(2000.);
        ui->powInputPS->setMaximum(2000.);
        ui->Ouput1->setMaximum(2000.);
        ui->Ouput2->setMaximum(2000.);
        ui->powOuput->setMaximum(2000.);

        // 2. 初始化串口名称spinbox组件
        const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
        foreach (const QSerialPortInfo& info , infos)
        {
              ui->serialNameBox->addItem(info.portName());
         }
         this->ui->serialNameBox->setEnabled(true); // 初始时选择串口可编辑
         ui->serialNameBox->setCurrentText("COM6"); // 初始时设定串口名称为COM6-->以后要改,可能没有这样的名称

        // 3.初始化波特率的选择spinbox组件
        QList<qint32> baudrates = QSerialPortInfo::standardBaudRates();
        for(const qint32& baudrate : baudrates)
        {
              ui->serialBaudRateBox->addItem(QString::asprintf("%d",baudrate));
        }
        ui->serialBaudRateBox->setCurrentText("9600");
        this->ui->serialBaudRateBox->setEnabled(true);// 初始时选择波特率可编辑

        // 4.打开和关闭串口的设置pushButton
        this->ui->openSerialPort->setEnabled(true);// 打开串口可编辑
        this->ui->closeSerialPort->setEnabled(false); // 关闭串口不可编辑
        this->serialstate = SPIC::serialState::OFF; // 状态为OFF

        // 5.电源输出状态checkBox
        ui->rbton->setEnabled(false);// 状态是不可编辑,只用于显示
        ui->rbtoff->setEnabled(false);
        ui->rbton->setChecked(false); // off为初始时的状态
        ui->rbtoff->setChecked(true);
        this->powerstate = SPIC::powerState::OFF;

        //  5.电源工作状态checkBox
        this->initialize_workstatus_components();

        // 6.工作模式radioButton
        ui->rbtCC->setEnabled(true); // 可以进行选择
        ui->rbtCV->setEnabled(true);
        ui->rbtCV->setChecked(true); //工作模式初始化为恒压模式
        ui->rbtCC->setChecked(false);
        this->workmode = SPIC::workMode::CV_WORK_MODE;

        // 7.开启和关闭电源pushButton
        ui->closePowerSupply->setEnabled(false); // 初始化打开和关闭电源不可编辑
        ui->openPowerSupply->setEnabled(false); // 打开串口的前提可以设置
}

// 6. 1号输入框的值变化槽函数
void SerialPortCommunication::on_Input1_valueChanged(double arg1)
{
        // CC模式时为True,设置的是输出电流;否则设置的输出电压
        // 判断是否为CC或者CV模式使用this->workmode判断也可以直接使用组件的isChecked判断

        // <1> 写入命令
        // 1.1 获取设定的命令
        SPIC::COMMAND setVal = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_VAL):
                                                    (SPIC::COMMAND::SOUR_VOLT_SET_VAL);
        QString command = SPIC::spic(setVal); // 命令翻译成字符串
        command += QString::asprintf("%.2f",arg1)+"\n"; // 因为是设定值的命令,要跟上设定的数值arg1
        const char * setc = command.toStdString().c_str(); // 转为const char*,write函数需要的格式

         // 2.1.保存设定的值和保存发送者信息
         // 这里解决过1个bug,保存信息要在判断串口是否打开之前保存
         // 如果串口没打开直接返回,后台信息实际上是没更新的,和视图组件信息不一致
         // 用户打开串口以后,不会再下拉,理所应当的认为应该恢复正常,而不是尝试再点一下
        if (this->workmode == SPIC::workMode::CC_WORK_MODE){
              this->cc_curr = arg1; // CC模式下设定的值传递给cc_curr保存,这个变量在receive_port_data用来和回读值比较判断命令是否写入正确
              this->senderinfo = SPIC::senderInfo::CC_CURR_SENDER ; // CC模式,发送者是电流
        }
        else if (this->workmode == SPIC::workMode::CV_WORK_MODE)
        {
              this->cv_volt = arg1;
              this->senderinfo = SPIC::senderInfo::CV_VOLT_SENDER ; // CV模式,发送者是电压
        }

        // 1.2 写入命令前加入一层判断,串口是否打开状态
        if (this->serialstate != SPIC::serialState::ON){
            QMessageBox::information(this,"ERROR","请先打开串口!");
            return;
        }
        // 1.3 写入命令
        this->Port->write(setc);// 写入设置命令

         // <2> 询问是否写入正确,保证安全

        // 2.2 发送询问设置的命令
        SPIC::COMMAND getVal = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_CURR_GET_VAL):  // CC模式,1号框是电流询问
                                    (SPIC::COMMAND::SOUR_VOLT_GET_VAL);// CV模式,1号框是电压询问
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 7.  2号PS输入框的值变化槽函数
void SerialPortCommunication::on_Input2PS_valueChanged(double arg1)
{
        // 如果是CV,2号框就表示电流,电流有2个;如果是CC,2号框表示电压,电压有2个
        // 这里CV设置的电流和CC设置的电压都是PS状态

          // <1> 写入命令
        // 1.1得到要写入的命令
        SPIC::COMMAND setVal = ui->rbtCV->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_LIM_POS):
                                                    (SPIC::COMMAND::SOUR_VOLT_SET_LIM_POS);
        QString command = SPIC::spic(setVal);
        command += QString::asprintf("%.2f",arg1)+"\n";
        const char * setc = command.toStdString().c_str();

         // 2.1.保存设定的值和保存发送者信息
        // 这里解决过1个bug,保存信息要在判断串口是否打开之前保存
        // 如果串口没打开直接返回,后台信息实际上是没更新的,和视图组件信息不一致
        // 用户打开串口以后,不会再下拉,理所应当的认为应该恢复正常,而不是尝试再点一下

        if (this->workmode == SPIC::workMode::CC_WORK_MODE){
              this->cc_volt_ps = arg1;
              this->senderinfo = SPIC::senderInfo::CC_VOLT_PS_SENDER; // CC模式,发送者是PS电压
        }
        else if (this->workmode == SPIC::workMode::CV_WORK_MODE)
        {
              this->cv_curr_ps = arg1;
              this->senderinfo = SPIC::senderInfo::CV_CURR_PS_SENDER ; // CV模式发送者是PS电流
        }
        // 1.2 写入命令前加入一层判断,串口是否打开状态
        if (this->serialstate != SPIC::serialState::ON){
            QMessageBox::information(this,"ERROR","请先打开串口!");
            return;
        }
         // 1.3 写入命令
        this->Port->write(setc);

         // <2> 询问是否写入正确,保证安全
        // 2.2 发送询问设置的命令
        SPIC::COMMAND getVal = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_VOLT_GET_LIM_POS): // CC模式,2号框是PS电压询问
                                    (SPIC::COMMAND::SOUR_CURR_GET_LIM_POS); // CV模式,2号框是PS电流询问
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 8.  2号EL输入框的值变化槽函数
void SerialPortCommunication::on_Input2EL_valueChanged(double arg1)
{
        // 如果是CV,2号框就表示电流,电流有2个;如果是CC,2号框表示电压,电压有2个
        // 这里CV设置的电流和CC设置的电压都是EL状态

          // <1> 写入命令
        // 1.1得到要写入的命令
        SPIC::COMMAND setVal = ui->rbtCV->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_LIM_NEG):
                                                    (SPIC::COMMAND::SOUR_VOLT_SET_LIM_NEG);
        QString command = SPIC::spic(setVal);
        command += QString::asprintf("%.2f",arg1)+"\n";
        const char * setc = command.toStdString().c_str();

         // 2.1.保存设定的值和保存发送者信息
        // 这里解决过1个bug,保存信息要在判断串口是否打开之前保存
        // 如果串口没打开直接返回,后台信息实际上是没更新的,和视图组件信息不一致
        // 用户打开串口以后,不会再下拉,理所应当的认为应该恢复正常,而不是尝试再点一下
        if (this->workmode == SPIC::workMode::CC_WORK_MODE){
              this->cc_volt_el = arg1;
              this->senderinfo = SPIC::senderInfo::CC_VOLT_EL_SENDER; // CC模式,发送者是EL电压
        }
        else if (this->workmode == SPIC::workMode::CV_WORK_MODE){
              this->cv_curr_el = arg1;
              this->senderinfo = SPIC::senderInfo::CV_CURR_EL_SENDER ; // CV模式发送者是EL电流
        }

        // 1.2 写入命令前加入一层判断,串口是否打开状态
        if (this->serialstate != SPIC::serialState::ON){
            QMessageBox::information(this,"ERROR","请先打开串口!");
            return;
        }
         // 1.3 写入命令
        this->Port->write(setc);

         // <2> 询问是否写入正确,保证安全

        // 2.2 发送询问设置的命令
        SPIC::COMMAND getVal = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_VOLT_GET_LIM_NEG): // CC模式,2号框是EL电压询问
                                    (SPIC::COMMAND::SOUR_CURR_GET_LIM_NEG); // CV模式,2号框是EL电流询问
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 9 . power EL输入框的值变化槽函数
void SerialPortCommunication::on_powInputEL_valueChanged(double arg1)
{
         // 无论是CC还是CV,PS状态对应命令不变

         // <1> 写入命令
        // 1.1得到要写入的命令
        SPIC::COMMAND setVal = SPIC::COMMAND::SOUR_POW_SET_LIM_NEG;
        QString command = SPIC::spic(setVal);
        command += QString::asprintf("%.2f",arg1)+"\n";
        const char * setc = command.toStdString().c_str();

        // <2> 询问是否写入正确,保证安全
        // 2.1.保存设定的值和保存发送者信息
        // 这里解决过1个bug,保存信息要在判断串口是否打开之前保存
        // 如果串口没打开直接返回,后台信息实际上是没更新的,和视图组件信息不一致
        // 用户打开串口以后,不会再下拉,理所应当的认为应该恢复正常,而不是尝试再点一下
        this->pow_el = arg1;
        this->senderinfo = SPIC::senderInfo::POW_EL_SENDER; // 发送者是EL功率

        // 1.2 写入命令前加入一层判断,串口是否打开状态
        if (this->serialstate != SPIC::serialState::ON){
            QMessageBox::information(this,"ERROR","请先打开串口!");
            return;
        }
         // 1.3 写入命令
        this->Port->write(setc);

        // 2.2 发送询问设置的命令
        SPIC::COMMAND getVal = SPIC::COMMAND::SOUR_POW_GET_LIM_NEG;
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 10.power PS输入框的值变化槽函数
void SerialPortCommunication::on_powInputPS_valueChanged(double arg1)
{
  // 无论是CC还是CV,PS状态对应命令不变

         // <1> 写入命令
        // 1.1得到要写入的命令
        SPIC::COMMAND setVal = SPIC::COMMAND::SOUR_POW_SET_LIM_POS;
        QString command = SPIC::spic(setVal);
        command += QString::asprintf("%.2f",arg1)+"\n";
        const char * setc = command.toStdString().c_str();

        // 2.1.保存设定的值和保存发送者信息
        // 这里解决过1个bug,保存信息要在判断串口是否打开之前保存
        // 如果串口没打开直接返回,后台信息实际上是没更新的,和视图组件信息不一致
        // 用户打开串口以后,不会再下拉,理所应当的认为应该恢复正常,而不是尝试再点一下
        this->pow_ps = arg1;
        this->senderinfo = SPIC::senderInfo::POW_PS_SENDER; // 发送者是PS功率

        // 1.2 写入命令前加入一层判断,串口是否打开状态
        if (this->serialstate != SPIC::serialState::ON){
            QMessageBox::information(this,"ERROR","请先打开串口!");
            return;
        }
         // 1.3 写入命令
        this->Port->write(setc);

         // <2> 询问是否写入正确,保证安全

        // 2.2 发送询问设置的命令
        SPIC::COMMAND getVal = SPIC::COMMAND::SOUR_POW_GET_LIM_POS;
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
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
              {
                     qDebug()<<Port->portName()<<" serial port has been successfully opened, the baud rate is "<<Port->baudRate();
                    this->serialstate = SPIC::serialState::ON;
              }
              else
            {
                  qDebug()<<"The serial port failed to open, please check whether it is occupied or does not exist!";
                  QMessageBox::critical(this,"错误","串口打开失败，请检查是否占用或者不存在!");
                   this->serialstate = SPIC::serialState::OFF;
            }
        }
        else
        {
              qDebug()<<"The serial port is already open.";
              this->serialstate = SPIC::serialState::ON;
              QMessageBox::information(this,"提示","串口已是打开状态");
        }
         // this->Port->close(); 要注释掉,否则收不到消息,串口的关闭可以手动关闭,即使不关闭会在串口工厂类的析构函数自行关闭

        // 设置和波特率的组件、打开串口的按钮处于不可编辑状态，关闭串口处于可编辑状态
        this->ui->serialNameBox->setEnabled(false); // 不可再选择串口
        this->ui->serialBaudRateBox->setEnabled(false); // 不可再选择波特率
        this->ui->openSerialPort->setEnabled(false); // 不可再次打开串口
        this->ui->closeSerialPort->setEnabled(true); // 关闭串口打开
        this->ui->openPowerSupply->setEnabled(true);// 开启电源打开
        this->ui->closePowerSupply->setEnabled(true); // 关闭电源打开
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
        this->serialstate = SPIC::serialState::OFF;
}

// 13. 串口接收数据的函数
void SerialPortCommunication::receive_port_data()
{
        // 1.先判断串口状态
        if (this->serialstate == SPIC::serialState::OFF ){
               qDebug()<<QTime::currentTime()<<" 串口是关闭状态,无法读取数据";
                return;
        }

        // 2.根据发送者信息读取数据
        while (this->Port->bytesAvailable())
        {
              qDebug()<<QDateTime::currentDateTime().toString("yyyy MM dd hh mm ss : ")
                     <<this->Port->portName()<<"数据正在被读取";
              QList<QByteArray> data = this->Port->readAll().split(';');
              bool isSelect = select_processing_method(data,this->senderinfo); // 发送者信息会在发送时被设置好
              unsigned int repeatime = 0;
              while (!isSelect && repeatime<=5){
                  isSelect = select_processing_method(data,this->senderinfo); // 尝试5次
                  ++repeatime;
              }
              if (!isSelect){
                  qDebug()<<"串口数据无法处理,不能选择合适的处理方法"; // log it
                  return;
              }
        }
}

bool SerialPortCommunication::select_processing_method(const QList<QByteArray> & data,
          const SPIC::senderInfo & sender)
{
        if (sender == SPIC::senderInfo::UNKNOW ) {
            qDebug()<<"发送者不知道是谁";//这里要记录,纳入日志管理 log it
            return false;
        }
        switch (sender)
        {
            case SPIC::senderInfo::FIXED_QUERY:processing_fixed_quiery(data);break;
            case SPIC::senderInfo::CV_VOLT_SENDER : processing_cvVolt(data);break;
            case SPIC::senderInfo::CV_CURR_PS_SENDER:processing_cvCurrPS(data);break;
            case SPIC::senderInfo::CV_CURR_EL_SENDER:processing_cvCurrEL(data);break;
            case SPIC::senderInfo::CC_CURR_SENDER:processing_ccCurr(data);break;
            case SPIC::senderInfo::CC_VOLT_PS_SENDER:processing_ccVoltPS(data);break;
            case SPIC::senderInfo::CC_VOLT_EL_SENDER:processing_ccVoltEL(data);break;
            case SPIC::senderInfo::POW_PS_SENDER:processing_powPS(data);break;
            case SPIC::senderInfo::POW_EL_SENDER:processing_powEL(data);break;
            default: break;
        }
      return true;
}

void SerialPortCommunication::processing_fixed_quiery(const QList<QByteArray> & data)
{
         // 固定函数查询的串口数据处理
        if (data.size() != 4){
            // 输入的命令具备这样的格式：15.578;33.543;27855;384 用分号隔开
            qDebug()<<"数据格式错误,应当有4条命令"; // log it
            return;
        }

        // 1.把读取的电压、电流、功率直接值取出来
        ui->Ouput1->setValue(data[0].toDouble()) ;// 测量电压值
        ui->Ouput2->setValue(data[1].toDouble()); // 测量电流值
        ui->powOuput->setValue(data[2].toDouble()/1000.0); // 测量功率值,单位是W转为kW

        // 2.状态寄存器的值需要二进制化处理
        int status_int = data[3].toInt(Q_NULLPTR,10); // 状态值先转为10进制整数
        /*
            二进制位的主要位含义如下:
            6 OFF 仪器on/off为off状态     int数组的第6位
            7 CC 正向恒流状态                 int数组的第5位
            8 CV  恒压状态                        int数组的第4位
            9 CW 正向恒功率状态            int数组的第3位
            11 CC- 负向恒流状态              int数组的第1位
            12 CP- 负向恒功率状态         int数组的第0位
        */
        const int byte_size = 13;
        QString status_string = QString::number(status_int,2); // 转二进制显示的字符串
        int n = byte_size - status_string.size(); // 转为二进制要补的0个数,13是这个寄存器应该有13位
        status_string = status_string.prepend(QString("0").repeated(n));  // 高位补0
        char * status_char = status_string.toLatin1().data();//得到完整的13位字符串

        int  bytes[byte_size];// 转为整型表示的字符串
        bool iscpy = this->strcpy(bytes,status_char); //方便作为bool值传递给checkBox组件显示

        if (iscpy) // 防止复制意外
        {
                for (int i = 0;i<byte_size; ++i){cout<<bytes[i]<<" ";}
                cout<<endl;
                qDebug()<<"strcpy is successful";

                bool powerInputState = bytes[byte_size-7]; // 电源输入状态
                ui->rbton->setChecked(powerInputState); // 传递给电源输出状态checkBox显示,无论是ON还是OFF

                // 对OFF的情况单独处理
                if (!powerInputState)
                { // OFF状态,int数组0-5位一定为0,无需再判断工作状态位
                        this->powerstate = SPIC::powerState::OFF;
                        for (const auto &work_status : this->workStatus)
                        {
                                work_status->setChecked(false);  // 工作状态都不打√
                        }
                }
                else // 电源输出状态为ON时,工作状态只会有1个位为0
                {
                      this->powerstate = SPIC::powerState::ON;
                      for (int j = 0; j <5 ; ++j) // 0-5位有1个值为1
                      {
                            if (bytes[j] == 1){ // 发现0-5位有值为1,就设置该位对应的work_status为True
                                this->workStatus[j]->setChecked(true); // workStatus[i]表示的含义和bytes[i]依次对应
                            }
                            else
                            {
                                this->workStatus[j]->setChecked(false);
                            }
                      }
                 }
          }
          else   // 复制失败导致的意外
          {
                qDebug()<<"strcpy is failed"; // log it
                return;
            }

}

void SerialPortCommunication::processing_cvVolt(const QList<QByteArray> & data)
{
    // 处理CV_VOLT_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    if (qAbs(acceptVal - this->cv_volt) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         qDebug()<<"设定CV_VOLT成功";
    }
    else {
        qDebug()<<"设定CV_VOLT失败";
    }
}
void SerialPortCommunication::processing_cvCurrPS(const QList<QByteArray> &data)
{
    // 处理CV_CURR_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    if (qAbs(acceptVal - this->cv_curr_ps) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         qDebug()<<"设定CV_CURR_PS成功";
    }
    else {
        qDebug()<<"设定CV_CURR_PS失败";
    }
}
void SerialPortCommunication::processing_cvCurrEL(const QList<QByteArray> &data)
{
    // 处理CV_CURR_EL_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    if (qAbs(acceptVal - this->cv_curr_el) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         qDebug()<<"设定CV_CURR_EL成功";
    }
    else {
        qDebug()<<"设定CV_CURR_EL失败";
    }
}
void SerialPortCommunication::processing_ccCurr(const QList<QByteArray> &data)
{
    // 处理CC_CURR_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    if (qAbs(acceptVal - this->cc_curr) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         qDebug()<<"设定CC_CURR成功";
    }
    else {
        qDebug()<<"设定CC_CURR失败";
    }
}
void SerialPortCommunication::processing_ccVoltPS(const QList<QByteArray> &data)
{
    // 处理CC_VOLT_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    if (qAbs(acceptVal - this->cc_volt_ps) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         qDebug()<<"设定CC_VOLT_PS成功";
    }
    else {
        qDebug()<<"设定CC_VOLT_PS失败";
    }
}
void SerialPortCommunication::processing_ccVoltEL(const QList<QByteArray> &data)
{
    // 处理CC_VOLT_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    if (qAbs(acceptVal - this->cc_volt_el) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         qDebug()<<"设定CC_VOLT_EL成功";
    }
    else {
        qDebug()<<"设定CC_VOLT_EL失败";
    }
}
void SerialPortCommunication::processing_powPS(const QList<QByteArray> &data)
{
    // 处理POW_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    if (qAbs(acceptVal - this->pow_ps) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         qDebug()<<"设定POW_PS成功";
    }
    else {
        qDebug()<<"设定POW_PS失败";
    }
}
void SerialPortCommunication::processing_powEL(const QList<QByteArray> &data)
{
    // 处理POW_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    if (qAbs(acceptVal - this->pow_el) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         qDebug()<<"设定POW_EL成功";
    }
    else {
        qDebug()<<"设定POW_EL失败";
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
        if (this->serialstate == SPIC::serialState::OFF || this->powerstate == SPIC::powerState::OFF
          || this->serialstate == SPIC::serialState::UNKNOW || this->powerstate == SPIC::powerState::UNKNOW){
             qDebug()<<"串口不是打开状态或者电源不是输出状态,无法读取数据";
             this->senderinfo = SPIC::senderInfo::UNKNOW; // 发送人未知
              return;
        }
        this->senderinfo = SPIC::senderInfo::FIXED_QUERY; // 发送人就是固定查询

        // 要查询的命令如下,分号隔开,最后1个命令使用\n结束
        QList<QString> commands = {
                (SPIC::spic(SPIC::COMMAND::MEAS_VOLT_AVAE)+";"),//电压测量值=>Ouput1&Ouput2
                (SPIC::spic(SPIC::COMMAND::MEAS_CURR_AVAE)+";"),// 电流测量值=>Ouput1&Ouput2
                (SPIC::spic(SPIC::COMMAND::MEAS_POW_AVAE)+";"),//功率测量值=>powOuput
                (SPIC::spic(SPIC::COMMAND::GET_WORK_STATUS)+"\n")// 工作状态用位表示,OFF/ON[6],CC[7],CV[8],CW[9],CC-[11],CP-[12]
        };

        QString command = commands[0]+commands[1]+commands[2]+commands[3];
        this->Port->write(command.toStdString().c_str());// 假如转换成字符串必须在这里转,不能借助第三方函数转为const char*,否则会乱码或收的不对
}

void SerialPortCommunication::initialize_workstatus_components()
{
        // 统一管理电源工作状态的视图组件
        this->workStatus.append(ui->checkBoxCCPos); // 7 正向恒流
        this->workStatus.append(ui->checkBoxCV); // 8 恒压
        this->workStatus.append(ui->checkBoxCPPos); // 9 正向恒功率
        this->workStatus.append(ui->checkBoxCCNeg); // 11 负向恒流
        this->workStatus.append(ui->checkBoxCPNeg); // 12 负向恒功率
        foreach(QCheckBox*status,this->workStatus)
        {
               status->setChecked(false); // checked均为false
               status->setEnabled(false); // 状态不可编辑
        }
        workStatus[1]->setChecked(true);//默认开启是恒压状态
        this->workstatus = SPIC::workStatus::CV_WORK_STATUS;
}

// 根据CC&CV模式切换QLabel和QSpinBox的组件显示状态
void SerialPortCommunication::change_label_spinBox_component(const SPIC::workMode &workMode)
{
       if (workMode == SPIC::workMode::CV_WORK_MODE){//
               // label文本为1号框是电压设置,2号框是电流设置
               ui->label_Input1->setText("电压设置：");
               ui->label_Input2_PS->setText("电流设置(PS)：");
               ui->label_Input2_EL->setText("电流设置(EL)：");
               // 相应的改变后缀符号为1号框"V",2号框"A"
               ui->Input1->setSuffix("V");
               ui->Input2PS->setSuffix("A");
               ui->Input2EL->setSuffix("A");
               this->workmode = workMode; // 更新工作模式
         }
       else if (workMode == SPIC::workMode::CC_WORK_MODE){
               // label文本为1号框是电流设置,2号框是电流设置
               ui->label_Input1->setText("电流设置：");
               ui->label_Input2_PS->setText("电压设置(PS)：");
               ui->label_Input2_EL->setText("电压设置(EL)：");
               // 相应的改变后缀符号为1号框"A",2号框"V"
               ui->Input1->setSuffix("A");
               ui->Input2PS->setSuffix("V");
               ui->Input2EL->setSuffix("V");
               this->workmode = workMode; // 更新工作模式
         }
       else if (workMode == SPIC::workMode::UNKNOW) { // 未处于任何状态
              // log
         }
         this->clearState();
}

void SerialPortCommunication::on_rbtCV_clicked()
{
      if (this->workmode == SPIC::workMode::CV_WORK_MODE){ // 如果点击之前已经是CV模式
          return; // 不需要改变任何信息直接返回
      }
      else if (this->workmode == SPIC::workMode::CC_WORK_MODE)
      { // 点击之前是CC模式

          int select = QMessageBox::warning(this,"警告","您选择切换至CV模式,界面信息将更新,是否确认?",
                QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
           if (select == QMessageBox::No || select == QMessageBox::Cancel)
           {
              ui->rbtCC->setChecked(true); // 因为用户的点击让按钮变化了,要恢复到以前的CC状态
              ui->rbtCV->setChecked(false);
              return;
           }
           change_label_spinBox_component(SPIC::workMode::CV_WORK_MODE); // 切换至CV模式
      }

}
void SerialPortCommunication::on_rbtCC_clicked()
{
      if (this->workmode == SPIC::workMode::CC_WORK_MODE)
      { // 如果点击之前已经是CC模式
          qDebug()<<"cc mode";
          return; // 不需要改变任何信息直接返回
      }
      else if (this->workmode == SPIC::workMode::CV_WORK_MODE)
      { // 点击之前是CV模式
          int select = QMessageBox::warning(this,"警告","您选择切换至CC模式,界面信息将更新,是否确认?",
                QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
           if (select == QMessageBox::No || select == QMessageBox::Cancel)
           {
              ui->rbtCC->setChecked(false); // 因为用户的点击让按钮变化了,要恢复到以前的CV状态
              ui->rbtCV->setChecked(true);
              return;
           }
           change_label_spinBox_component(SPIC::workMode::CC_WORK_MODE); // 切换至CC模式
      }
}

void SerialPortCommunication::clearState()
{
    // 刷新的状态就是设置的值和回读的清0,发送者信息变化,
    // 别的后台信息不要改变,例如串口状态,电源输出状态,工作状态,工作模式切换时就会变化了也不用再动
    // 这样用户必须要重新设定或者下拉值,避免出现切换模式后,因为spinbox值没变,直接发送串口命令就会出错
    // 也就是从逻辑上避免bug而不是真正的解决bug
    ui->Input1->setValue(0.);
    ui->Ouput1->setValue(0.);
    ui->Input2PS->setValue(0.);
    ui->Input2EL->setValue(0.);
    ui->Ouput2->setValue(0.);
    ui->powOuput->setValue(0.);
    ui->powInputPS->setValue(0.);
    ui->powInputEL->setValue(0.);

    this->cv_volt = 0.;
    this-> cv_curr_ps = 0.;
    this->cv_curr_el = 0.;
    this->cc_curr = 0.;
    this->cc_volt_ps = 0.;
    this->cc_volt_el = 0.;
    this->pow_ps = 0.;
    this->pow_el = 0.;

    this->senderinfo = SPIC::senderInfo::UNKNOW; // 免的再点出错
}
void SerialPortCommunication::on_openPowerSupply_clicked()
{
    if (this->serialstate == SPIC::serialState::OFF){
        QMessageBox::information(this,"错误","请先打开串口");
        return;
    }
}

void SerialPortCommunication::on_closePowerSupply_clicked()
{

}


