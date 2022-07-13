#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"
#include <QMessageBox>
#include <QList>
#include  <QDebug>

/*
********定义了一些函数，用于处理基于特定发送者发的命令所返回的串口数据
******** 处理串口数据的方式取决于发送者是谁,也就是this->senderInfo
******** 发送者有哪些成员参见"spiCommand.h"的枚举值类型 SPIC::senderInfo
*/
static const  int  _receiver_functions_num = 11;

static const QList<const char *>  __all__receiver__functions__ = {
      "processing_fixed_quiery",
      "processing_cvVolt",
      "processing_cvCurrPS",
      "processing_cvCurrEL",
      "processing_ccCurr",
      "processing_ccVoltPS",
      "processing_ccVoltEL",
      "processing_powPS",
      "processing_powEL",
      "processing_powON",
      "processing_powOFF"
};

// 1. 每300ms进行1次输出电压、电流和功率的查询
void SerialPortCommunication::processing_fixed_quiery(const QList<QByteArray> & data)
{
         // 固定函数查询的串口数据处理
        if (data.size() != 4){
            // 输入的命令具备这样的格式：15.578;33.543;27855;320 用分号隔开
            qDebug()<<"数据格式错误,应当有4条命令"; // log it
            return;
        }

        // 如果回"0"说明是电源没输出,所有状态位都是0,也就没必要再读
        if (data[3] == "0"){ // 如果是0,电源没输出
            ui->rbtoff->setChecked(true);
            ui->rbton->setChecked(false);
            this->powerstate = SPIC::powerState::OFF;
            ui->openPowerSupply->setEnabled(true);
            ui->closePowerSupply->setEnabled(false);

            qDebug()<<"power supply don't have output";
            return;
        }
        // 如果有输出,例如如果回的是320就是0000101000000 = 2^6+2^8 = 64 + 256 = 320
        ui->rbton->setChecked(true);
        ui->rbtoff->setChecked(false);
        ui->openPowerSupply->setEnabled(false);
        ui->closePowerSupply->setEnabled(true); // 有输出的时候关闭使能
        this->powerstate = SPIC::powerState::ON;

        //  状态寄存器的值需要二进制化处理
        int status_int = data[3].toInt(Q_NULLPTR,10); // 状态值先转为10进制整数

        // 1.把读取的电压、电流、功率直接值先取出来直接赋值
        ui->voltOuput->setValue(data[0].toDouble()) ;// 测量电压值
        ui->currOuput->setValue(data[1].toDouble()); // 测量电流值
        ui->powOuput->setValue(data[2].toDouble()/1000.0); // 测量功率值,单位是W转为kW

         // 2.取出状态STAT:OPERA?的回复信息
        /*
            状态的二进制位的主要位含义如下:
            6 OFF 仪器on/off为off状态     int数组的第6位
            7 CC 正向恒流状态                 int数组的第5位
            8 CV  恒压状态                        int数组的第4位
            9 CW 正向恒功率状态            int数组的第3位
            11 CC- 负向恒流状态              int数组的第1位
            12 CP- 负向恒功率状态         int数组的第0位
            0000 101 000000 => CV状态
        */
        const int byte_size = 13;
        QString status_string = QString::number(status_int,2); // 转二进制显示的字符串
        int n = byte_size - status_string.size(); // 转为二进制要补的0个数,13是这个寄存器应该有13位
        status_string = status_string.prepend(QString("0").repeated(n));  // 高位补0
        char * status_char = status_string.toLatin1().data();//得到完整的13位字符串
        qDebug()<<status_char;

        int  bytes[byte_size];// 转为整型表示的字符串
        bool iscpy = this->strcpy(bytes,status_char); //方便作为bool值传递给checkBox组件显示

        if (iscpy) // 防止复制意外
        {
              qDebug()<<"strcpy is successful";
              ui->checkBoxCPNeg->setChecked(bytes[0]); // 0位对应CP-
              ui->checkBoxCCNeg->setChecked(bytes[1]); // 1位对应CC-
              ui->checkBoxCPPos->setChecked(bytes[3]); // 3位对应CP+
              ui->checkBoxCV->setChecked(bytes[4]); // 4位对应CV
              ui->checkBoxCCPos->setChecked(bytes[5]); // 5位对应CC+
          }
          else   // 复制失败导致的意外
          {
                qDebug()<<"strcpy is failed"; // log it
                return;
            }
}

//  2. CV模式电压设定命令的处理
void SerialPortCommunication::processing_cvVolt(const QList<QByteArray> & data)
{
    // 处理CV_VOLT_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值,这是收到的命令反馈的值

    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (qAbs(acceptVal - this->cv_volt) < 1e-3){ // 浮点数相等应当用误差容限值来比较
          // qDebug()<<"设定CV_VOLT成功";
         QMessageBox::information(this,"Information","设定CV模式下的输出电压值成功!");
    }
    else {
        // qDebug()<<"设定CV_VOLT失败";
        QMessageBox::critical(this,"Error","设定CV模式下的输出电压值失败!");
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
    }
}

//  3. CV模式PS电流设定命令的处理
void SerialPortCommunication::processing_cvCurrPS(const QList<QByteArray> &data)
{
    // 处理CV_CURR_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (qAbs(acceptVal - this->cv_curr_ps) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         // qDebug()<<"设定CV_CURR_PS成功";
         QMessageBox::information(this,"Information","设定CV模式下PS的输出电流值成功!");
    }
    else {
        // qDebug()<<"设定CV_CURR_PS失败";
        QMessageBox::critical(this,"Error","设定CV模式下PS的输出电流值失败!");
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
    }
}

// 4. CV模式EL电流设定命令的处理
void SerialPortCommunication::processing_cvCurrEL(const QList<QByteArray> &data)
{
    // 处理CV_CURR_EL_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (qAbs(acceptVal - this->cv_curr_el) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         // qDebug()<<"设定CV_CURR_EL成功";
         QMessageBox::information(this,"Information","设定CV模式下EL的输出电流值成功!");
    }
    else {
       // qDebug()<<"设定CV_CURR_EL失败";
       QMessageBox::critical(this,"Error","设定CV模式下EL的输出电流值失败!");
       this->clear_state();
      this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
    }
}

// 5. CC模式电流设定命令的处理
void SerialPortCommunication::processing_ccCurr(const QList<QByteArray> & data)
{
    // 处理CC_CURR_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值,这是收到的命令反馈的值
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (qAbs(acceptVal - this->cc_curr) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         // qDebug()<<"设定CC_CURR成功";
         QMessageBox::information(this,"Information","设定CC模式下的输出电流值成功!");
    }
    else {
        // qDebug()<<"设定CC_CURR失败";
        QMessageBox::critical(this,"Error","设定CC模式下的输出电流值失败!");
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
    }
}

// 6. CC模式PS电压设定命令的处理
void SerialPortCommunication::processing_ccVoltPS(const QList<QByteArray> &data)
{
    // 处理CC_VOLT_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (qAbs(acceptVal - this->cc_volt_ps) < 1e-3){ // 浮点数相等应当用误差容限值来比较
          // qDebug()<<"设定CC_VOLT_PS成功";
          QMessageBox::information(this,"Information","设定CC模式下PS的输出电压值成功!");
    }
    else {
        // qDebug()<<"设定CC_VOLT_PS失败";
        QMessageBox::critical(this,"Error","设定CC模式下PS的输出电压值失败!");
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
    }
}

// 7. CC模式EL电压设定命令的处理
void SerialPortCommunication::processing_ccVoltEL(const QList<QByteArray> &data)
{
    // 处理CC_VOLT_EL_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (qAbs(acceptVal - this->cc_volt_el) < 1e-3){ // 浮点数相等应当用误差容限值来比较
          // qDebug()<<"设定CC_VOLT_EL成功";
          QMessageBox::information(this,"Information","设定CC模式下EL的输出电压值成功!");
    }
    else {
        // qDebug()<<"设定CC_VOLT_EL失败";
        QMessageBox::critical(this,"Error","设定CC模式下EL的输出电压值失败!");
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
    }
}

// 8.PS功率设定命令的处理
void SerialPortCommunication::processing_powPS(const QList<QByteArray> &data)
{
    // 处理POW_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (qAbs(acceptVal - this->pow_ps) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         QMessageBox::information(this,"Information","设定PS的输出功率值成功!");
         // qDebug()<<"设定POW_PS成功";
    }
    else {
        // qDebug()<<"设定POW_PS失败";
        QMessageBox::critical(this,"Error","设定PS的输出功率值失败!");
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
    }
}

// 9.EL功率设定命令的处理
void SerialPortCommunication::processing_powEL(const QList<QByteArray> &data)
{
    // 处理POW_PS_SENDER发送者收到的信息
    if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    double acceptVal =data.at(0).toDouble(); //转为double值
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (qAbs(acceptVal - this->pow_el) < 1e-3){ // 浮点数相等应当用误差容限值来比较
         // qDebug()<<"设定POW_EL成功";
         QMessageBox::information(this,"Information","设定EL的输出功率值成功!");
    }
    else {
        // qDebug()<<"设定POW_EL失败";
        QMessageBox::critical(this,"Error","设定EL的输出功率值失败!");
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
    }
}

// 10. 开启电源设定命令的处理
void SerialPortCommunication::processing_powON(const QList<QByteArray> &data)
{
      // 处理POW_ON_SENDER发送者收到的消息
     if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    QByteArray state = data.at(0);
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (state == "ON" || state == "1" || state == "on")// 说明成功收到
        QMessageBox::information(this,"Information","开启电源输出成功!");
    else {
        QMessageBox::critical(this,"Error","开启电源输出失败!");
        // 电源状态要恢复
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
        this->powerstate = SPIC::powerState::OFF;
        ui->openPowerSupply->setEnabled(true);//因为开启电源输出失败,所以开启选项保持使能
        ui->closePowerSupply->setEnabled(false);
        ui->rbton->setChecked(false); // 电源输出状态显示为OFF
        ui->rbtoff->setChecked(true);
    }
}

// 11. 关闭电源设定命令的处理
void SerialPortCommunication::processing_powOFF(const QList<QByteArray> &data)
{
      // 处理POW_OFF_SENDER发送者收到的消息
     if (data.size() != 1 )
    {
        qDebug()<<"数据格式错误,应当只有1条命令"; //log it
        return;
    }
    QByteArray state = data.at(0);
    this->initialize_connection(); // 收到值以后就可以恢复后台查询,无论设定是否成功都恢复
    if (state == "OFF" || state == "0" || state == "off") // 说明成功收到
        QMessageBox::information(this,"Information","关闭电源输出成功!");
    else {
        QMessageBox::critical(this,"Error","关闭电源输出失败!");
        this->clear_state();
        this->initialize_connection(); // 因为clear_state函数会再次设置spinbox值,槽函数响应导致暂停,故要恢复连接
        // 电源状态要恢复
        this->powerstate = SPIC::powerState::ON;
        ui->openPowerSupply->setEnabled(false);//因为关闭电源输出失败,所以关闭选项保持使能
        ui->closePowerSupply->setEnabled(true);
        ui->rbton->setChecked(true); // 电源输出状态显示为ON
        ui->rbtoff->setChecked(false);
    }
}
