#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"

/*
************* 定义了一些中介函数
************* 可以看成是为了减少代码重复而抽取出来固定代码的一类函数
************* 或者是为了程序可读性增加的函数
************* select_processing_method()方法在receive_port_data()被调用,依据不同的发送者调用后面不同on打头的函数
*/
static const  int  _mediation_functions_num = 8;

static const QList<const char *> __mediation__functions__ = {
        "select_processing_method",
        "change_label_component",
        "clear_state",
        "reset_spinbox_step",
        "reset_spinbox_range",
        "reset_spinbox_value",
        "reset_spinbox_suffix",
        "disconnect_connection"
};

// 1. 根据发送者的不同选择不同的方法处理数据,被receive_port_data()函数调用
void SerialPortCommunication::select_processing_method(const QList<QByteArray> & data,
          const SPIC::senderInfo & sender)
{
        if (sender == SPIC::senderInfo::UNKNOW ) {
            qDebug()<<"发送者不知道是谁";//这里要记录,纳入日志管理 log it
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
              case SPIC::senderInfo::POW_ON_SENDER:processing_powON(data);break;
              case SPIC::senderInfo::POW_OFF_SENDER:processing_powOFF(data);break;
              default: break;
        }
}

// 2. 根据工作模式radiobutton切换界面显示状态
void SerialPortCommunication::change_label_component(const SPIC::workMode &workMode)
{
       if (workMode == SPIC::workMode::CV_WORK_MODE){// 要切换成CV模式
               // label文本为1号框是电压设置,2号框是两个电流设置
               ui->label_Input1->setText("电压设置：");
               ui->label_Input2_PS->setText("电流设置(PS)：");
               ui->label_Input2_EL->setText("电流设置(EL)：");
               // 相应的改变后缀符号为1号框"V",2号框"A"
               ui->Input1->setSuffix("V");
               ui->Input2PS->setSuffix("A");
               ui->Input2EL->setSuffix("A");
         }
       else {
               // label文本为1号框是电流设置,2号框是两个电压设置
               ui->label_Input1->setText("电流设置：");
               ui->label_Input2_PS->setText("电压设置(PS)：");
               ui->label_Input2_EL->setText("电压设置(EL)：");
               // 相应的改变后缀符号为1号框"A",2号框"V"
               ui->Input1->setSuffix("A");
               ui->Input2PS->setSuffix("V");
               ui->Input2EL->setSuffix("V");
         }

         this->clear_state(); // 清除状态
}

// 3.清除状态
void SerialPortCommunication::clear_state()
{
    // 清除状态会让用户必须重新设定spinbox值(否则是0),并清除原来的输入设定值
    // 这样用户必须要重新设定或者下拉值,这是为了避免切换模式后,因为spinbox值没变,发送串口命令出错的问题
    // 强制用户重新设定可以避免这个不好形容出来的问题
    // 总之这里的代码不要改动

    this->reset_spinbox_value(); // spinbox初始值需要重置
    this->initialize_ouput_setting_value(); // 原来的输出设定值需要重置

    // 工作模式跟随radiobutton,在rbtCC和rbtCV槽函数中会设置好state,不需要重置
    // 工作状态跟随定时查询,在fixed_query读取命令解析后显示,不需要重置
    // 电源输出状态跟随pushbutton,在openSupply和closeSupply已设置,不需要重置
    // 串口状态跟随pushbutton,openSerial和closeSerial已设置,不需要重置

}

// 4.初始化spinbox的步长
void SerialPortCommunication::reset_spinbox_step()
{
      // 5个输入框
      ui->Input1->setSingleStep(0.01);
      ui->Input2PS->setSingleStep(0.01);
      ui->Input2EL->setSingleStep(0.01);
      ui->powInputEL->setSingleStep(0.01);
      ui->powInputPS->setSingleStep(0.01);

      // 3个输出框不需要设置,因为只读
}

// 5.初始化spinbox的初始值
void SerialPortCommunication::reset_spinbox_value()
{
     // 5个输入框
      ui->Input1->setValue(0.00);
      ui->Input2EL->setValue(0.00);
      ui->Input2PS->setValue(0.00);
      ui->powInputPS->setValue(0.0);
      ui->powInputEL->setValue(0.0);

      // 3个输出框
      ui->voltOuput->setValue(0.00);
      ui->currOuput->setValue(0.00);
      ui->powOuput->setValue(0.0);
}

// 6. 初始化spinbox的范围
void ::SerialPortCommunication::reset_spinbox_range()
{
      // 5个输入框
      ui->Input1->setMaximum(2000.);
      ui->Input2EL->setMaximum(2000.);
      ui->Input2PS->setMaximum(2000.);
      ui->powInputEL->setMaximum(2000.);
      ui->powInputPS->setMaximum(2000.);

      // 3个输出框
      ui->voltOuput->setMaximum(2000.);
      ui->currOuput->setMaximum(2000.);
      ui->powOuput->setMaximum(2000.);
}

// 7.初始化spinbox的后缀
void ::SerialPortCommunication::reset_spinbox_suffix()
{
        // 5个输入框
        ui->Input1->setSuffix("V"); //  按CV模式设置的是1个电压
        ui->Input2EL->setSuffix("A");  // 按CV模式设置的是2个电流 PS
        ui->Input2PS->setSuffix("A");  // 按CV模式设置的是2个电流 EL
        ui->powInputPS->setSuffix("kW"); // 功率值不论CC还是CV都是2个 PS
        ui->powInputEL->setSuffix("kW");// 功率值不论CC还是CV都是2个 EL

       // 3个输出框
        ui->voltOuput->setSuffix("A");
        ui->currOuput->setSuffix("V");
        ui->powOuput->setSuffix("kW");
}

// 8. 终止连接,可以在设定值临时关闭后台查询函数
void SerialPortCommunication::disconnect_connection()
{
    disconnect(this->fixed_query_thread,SIGNAL(sendCommand(QString)),this,SLOT(on_sendCommand(QString)));
    disconnect(this->timer,SIGNAL(timeout()),this,SLOT(fixedQuery()));
}
