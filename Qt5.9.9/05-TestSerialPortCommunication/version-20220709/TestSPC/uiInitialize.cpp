#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"
#include "serialPortFactory.h"
#include "threadFactory.h"
#include  <QDebug>
#include <QMessageBox>
#include  <QList>

/*
************定义用于初始化的函数
************ 初始化串口优先
************ 初始化界面组件的静态属性
************ 初始化后台的动态属性
*/
static const  int  _initialize_functions_num = 17;
static const QList<const char *> __initialize__functions__ = {
        "initialize", // 1
        "initialize_serial_port",
        "initialize_io_spinbox",
        "initialize_serial_name_spinbox",
        "initialize_serial_baudrate_spinbox", // 5
        "initialize_open_serial_pushbutton",
        "initialize_close_serial_pushbutton",
        "initialize_power_state_radiobutton",
        "initialize_work_mode_radiobutton",
        "initialize_work_status_checkbox", // 10
        "initialize_open_supply_pushbutton",
        "initialize_close_supply_pushbutton",
        "initialize_fixedQuery_thread",
        "initialize_timer_timeout",
        "initialize_connection",
        "initialize_enumeration_value",
        "initialize_ouput_setting_value", // 17
};
// 1. 全局初始化函数
void SerialPortCommunication::initialize()
{
      this->initialize_serial_port() ; //优先初始化,否则程序会异常退出  1个

      // 以下没有初始化先后顺序的要求

      // 1.初始化静态视图组件的属性 10个
      this->initialize_io_spinbox();
      this->initialize_serial_name_spinbox();
      this->initialize_serial_baudrate_spinbox();
      this->initialize_open_serial_pushbutton();
      this->initialize_close_serial_pushbutton();
      this->initialize_open_supply_pushbutton();
      this->initialize_close_supply_pushbutton();
      this->initialize_power_state_radiobutton();
      this->initialize_work_mode_radiobutton();
      this->initialize_work_status_checkbox();

      // 2. 初始化动态组件的属性 5个
      this->initialize_fixedQuery_thread();
      this->initialize_timer_timeout();
      this->initialize_connection();
      this->initialize_enumeration_value();
      this->initialize_ouput_setting_value();
}

// 2. 初始化串口
void SerialPortCommunication::initialize_serial_port()
{
      this->Port =serialPortFactory::createPort(); // 初始化串口
}

// 3.初始化输入输出的spinbox
void SerialPortCommunication::initialize_io_spinbox()
{
      // 按照CV模式初始化,电压1个,电流2个,功率2个

      // 1.1 输入的步长设置
      this->reset_spinbox_step();

      // 1.2 初始值设定
      this->reset_spinbox_value();

      // 1.3 设置后缀
      this->reset_spinbox_suffix();

      // 1.4 最大值设置
      this->reset_spinbox_range();

      // 1.5 3个输出框输出回读值不可修改
      ui->voltOuput->setReadOnly(true);
      ui->currOuput->setReadOnly(true);
      ui->powOuput->setReadOnly(true);

      //1.6 隐藏掉倒立的2个三角,使之看起来更像文本输入框
      ui->voltOuput->setButtonSymbols(QAbstractSpinBox::NoButtons);
      ui->currOuput->setButtonSymbols(QAbstractSpinBox::NoButtons);
      ui->powOuput->setButtonSymbols(QAbstractSpinBox::NoButtons);
}

// 4.初始化串口名称的spinbox
void SerialPortCommunication::initialize_serial_name_spinbox()
{
      const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts(); // 调用静态函数列出可用串口
      foreach (const QSerialPortInfo& info , infos)
      {
            ui->serialNameBox->addItem(info.portName());
       }
       this->ui->serialNameBox->setEnabled(true); // 初始时选择串口可编辑
       ui->serialNameBox->setCurrentText("COM6"); // 初始时设定串口名称为COM6-->以后要改,可能没有这样的名称
}

// 5.初始化串口波特率的spinbox
void SerialPortCommunication::initialize_serial_baudrate_spinbox()
{
        QList<qint32> baudrates = QSerialPortInfo::standardBaudRates();
        for(const qint32& baudrate : baudrates)
        {
              ui->serialBaudRateBox->addItem(QString::asprintf("%d",baudrate));
        }
        ui->serialBaudRateBox->setCurrentText("9600");
        this->ui->serialBaudRateBox->setEnabled(true);// 初始时选择波特率可编辑
}

// 6.初始化打开串口的pushbutton
void SerialPortCommunication::initialize_open_serial_pushbutton()
{
        this->ui->openSerialPort->setEnabled(true);// 打开串口可编辑
}

// 7.初始化关闭串口的pushbutton
void SerialPortCommunication::initialize_close_serial_pushbutton()
{
       this->ui->closeSerialPort->setEnabled(false); // 关闭串口不可编辑
}

// 8.初始化显示电源开关状态的radiobutton
void SerialPortCommunication::initialize_power_state_radiobutton()
{
        // 状态是不可编辑,只用于显示
        ui->rbton->setEnabled(false);
        ui->rbtoff->setEnabled(false);
        // off为初始时的状态
        ui->rbton->setChecked(false);
        ui->rbtoff->setChecked(true);
}

// 9. 初始化显示电源工作模式的radiobutton
void SerialPortCommunication::initialize_work_mode_radiobutton()
{
        // 只有2种mode：CC、CV
        // 使能打开,可以切换模式
        ui->rbtCC->setEnabled(true);
        ui->rbtCV->setEnabled(true);
        // 初始化工作模式是CV模式
        ui->rbtCV->setChecked(true);
        ui->rbtCC->setChecked(false);
}

// 10.初始化显示电源工作状态的checkbox
void SerialPortCommunication::initialize_work_status_checkbox()
{
        // 只有5种status：CP-、CC-、CP、CV、CC，对应0、1、3、4、5位

         // 统一管理电源工作状态的视图组件
        QList<QCheckBox*> workstatus ;
        workstatus.append(ui->checkBoxCPNeg); // 12 负向恒功率 CP-
        workstatus.append(ui->checkBoxCCNeg); // 11 负向恒流 CC-
        workstatus.append(ui->checkBoxCPPos); // 9 正向恒功率 CW
        workstatus.append(ui->checkBoxCV); // 8 恒压 CV
        workstatus.append(ui->checkBoxCCPos); // 7 正向恒流 CC+

        foreach(const auto&status,workstatus)
        {
               status->setChecked(false); // 统一不选中
               status->setEnabled(false); // 使能关闭,只用于显示
        }
        workstatus[3]->setChecked(true);//默认开启是恒压状态
}

// 11.初始化打开电源的pushbutton
void SerialPortCommunication::initialize_open_supply_pushbutton()
{
      ui->openPowerSupply->setEnabled(false); // 使能关闭,打开串口后才可用
}

// 12.初始化关闭电源的pushbutton
void SerialPortCommunication::initialize_close_supply_pushbutton()
{
    ui->closePowerSupply->setEnabled(false); // 使能关闭,打开串口后才可用
}

// 13. 初始化子线程,300ms进行1次查询
void SerialPortCommunication::initialize_fixedQuery_thread()
{
    this->fixed_query_thread =  new fixedQueryThread();
}

// 14. 初始化定时器,每300ms进行1次查询(效果相同)
void SerialPortCommunication::initialize_timer_timeout()
{
      this->timer = new QTimer();
      this->timer->setInterval(this->flushTime);
      this->timer->setTimerType(Qt::PreciseTimer);
      this->timer->setSingleShot(false);
}

// 15. 初始化连接函数
void SerialPortCommunication::initialize_connection()
{
      // 其实2个函数效果是完全一样的,二选一连接1个就行,如果都选好像也不会冲突
      // 因为一个是子线程一个是主线程
    connect(this->fixed_query_thread,SIGNAL(sendCommand(QString)),this,SLOT(on_sendCommand(QString)));
    connect(this->timer,SIGNAL(timeout()),this,SLOT(fixedQuery()));
}
// 16. 初始化成员枚举值
void SerialPortCommunication::initialize_enumeration_value()
{
      // 注意这里和视图组件的checked状态一致,不要修改它
      this->serialstate = SPIC::serialState::OFF;
      this->powerstate = SPIC::powerState::OFF;
      this->workmode = SPIC::workMode::CV_WORK_MODE;
      this->workstatus = SPIC::workStatus::CV_WORK_STATUS;
      this->senderinfo = SPIC::senderInfo::UNKNOW;
}

// 17. 初始化记录变量
void SerialPortCommunication::initialize_ouput_setting_value()
{
      this->cv_volt = 0.;
      this->cv_curr_ps = 0.;
      this->cv_curr_el = 0.;
      this->cc_curr = 0.;
      this->cc_volt_ps = 0.;
      this->cc_volt_el = 0.;
      this->pow_ps = 0.;
      this->pow_el = 0.;
}
