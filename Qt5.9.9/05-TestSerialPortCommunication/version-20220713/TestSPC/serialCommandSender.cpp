#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"
#include <QMessageBox>
#include <QList>
#include  <QDebug>

#include <QMutex>
/*
 ***************接收串口数据的函数只有1个,就是receive_port_data()
 *************** receive_port_data()函数在"打开串口"按钮点击后就被绑定到串口的readyReady信号
 ***************界面组件的一些信号对应的特殊槽函数,绑定发送者,因为这些槽函数的特点是需要发送查询命令
 *************** 从函数注释可以看出目前一共涉及到11个发送者角色
 *************** 发送者有哪些成员参见"spiCommand.h"的枚举值类型 SPIC::senderInfo
*/
static const  int  _sender_functions_num = 10;

static const QList<const char *>  __sender__slot__functions__ =  {
        "receive_port_data",

        "on_sendCommand", // senderInfo::FIXED_QUERY;
        "on_timeout_fixedQuery",  // senderInfo::FIXED_QUERY;

        "on_Input1_valueChanged", // CC_CURR_SENDER ; or senderInfo::CV_VOLT_SENDER
        "on_Input2PS_valueChanged", // senderInfo::CC_VOLT_PS_SENDER; or senderInfo::CV_CURR_PS_SENDER ;
        "on_Input2EL_valueChanged", //  senderInfo::CC_VOLT_EL_SENDER; or senderInfo::CV_CURR_EL_SENDER ;

        "on_powInputPS_valueChanged", //  senderInfo::POW_PS_SENDER;
        "on_powInputEL_valueChanged",//  senderInfo::POW_EL_SENDER;

        "on_openPowerSupply_clicked",// senderInfo::POW_ON_SENDER;
        "on_closePowerSupply_clicked",// senderInfo::POW_OFF_SENDER;
};

// 1.串口接收数据的函数
void SerialPortCommunication::receive_port_data() //本函数必须放在当前cpp文件否则会找不到引用
{
        // 1.先判断串口状态,然后电源输出是否打开状态
        if (this->serialstate != SPIC::serialState::ON ){ // 查询命令不需要开启电源输出,设定命令需要开启电源输出
               qDebug()<<QTime::currentTime()<<" 串口是关闭状态,无法读取数据";
                return;
        }
        // 2.根据发送者信息读取数据
        // 这里不要使用bool QIODevice::waitForReadyRead(int msecs),可能会导致界面冻结
        // while循环配合,只要数据有效就读出来
        while (this->Port->bytesAvailable())
        {
              qDebug()<<QDateTime::currentDateTime().toString("yyyy MM dd hh::mm::ss : ")
                     <<this->Port->portName()<<"数据正在被读取";
              QByteArray data = this->Port->readAll();
              QList<QByteArray> spilitData = data.split(';');
              select_processing_method(spilitData,this->senderinfo); // 发送者信息会在发送时被设置好
        }
}

// 2. 利用thread实现的固定查询的槽函数 =>senderInfo::FIXED_QUERY
void SerialPortCommunication::on_sendCommand(QString command)
{
        if (this->serialstate != SPIC::serialState::ON){
             qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss")<<" 串口是关闭状态,无法读取数据";
              return;
        }
       qDebug()<<"thread => "<<command;
       this->senderinfo = SPIC::senderInfo::FIXED_QUERY; // 发送人就是固定查询
       this->Port->write(command.toStdString().c_str());// 假如转换成字符串必须在这里转,不能借助第三方函数转为const char*,否则会乱码或收的不对
       // 接下来就是receive_port_data()函数的处理
}

// 3. 利用timeout实现的固定查询的槽函数 =>senderInfo::FIXED_QUERY
void SerialPortCommunication::fixedQuery()
{
        // 此槽函数被手动连接到1个QTimer的timeout信号
        if (this->serialstate != SPIC::serialState::ON){
             qDebug()<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss")<<" 串口是关闭状态,无法读取数据";
              return;
        }
        this->senderinfo = SPIC::senderInfo::FIXED_QUERY; // 发送人就是固定查询

          // 要查询的命令如下,分号隔开,最后1个命令使用\n结束
          // MEAS:VOLT?;MEAS:CURR?;MEAS:POW?;STAT:OPERA?\n
        QList<QString> commands = {
                (SPIC::spic(SPIC::COMMAND::MEAS_VOLT_AVAE)+";"),//电压测量值=>Ouput1&Ouput2
                (SPIC::spic(SPIC::COMMAND::MEAS_CURR_AVAE)+";"),// 电流测量值=>Ouput1&Ouput2
                (SPIC::spic(SPIC::COMMAND::MEAS_POW_AVAE)+";"),//功率测量值=>powOuput
                (SPIC::spic(SPIC::COMMAND::GET_WORK_STATUS)+"\n")// 工作状态用位表示,OFF/ON[6],CC[7],CV[8],CW[9],CC-[11],CP-[12]
        };
        QString command = commands[0]+commands[1]+commands[2]+commands[3];
        qDebug()<<"timer => "<<command;
        this->Port->write(command.toStdString().c_str());// 假如转换成字符串必须在这里转,不能借助第三方函数转为const char*,否则会乱码或收的不对
        // 接下来就是receive_port_data()函数的处理
}

// 4. 1号输入框的值变化槽函数 => senderInfo::CV_VOLT_SENDER  or  senderInfo::CC_CURR_SENDER
void SerialPortCommunication::on_Input1_valueChanged(double arg1)
{
        // CC模式时为True,设置的是输出电流;否则设置的输出电压
        // 判断是否为CC或者CV模式使用this->workmode判断也可以直接使用组件的isChecked判断

        // 1.1 获取设定的命令
        SPIC::COMMAND setVal = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_VAL):
                                                    (SPIC::COMMAND::SOUR_VOLT_SET_VAL);
        QString command = SPIC::spic(setVal); // 命令翻译成字符串
        command += QString::asprintf("%.2f",arg1)+"\n"; // 因为是设定值的命令,要跟上设定的数值arg1
        const char * setc = command.toStdString().c_str(); // 转为const char*,write函数需要的格式

        // 1.2 写入命令前加入一层判断,串口是否打开状态,然后电源输出是否打开状态
        if (this->serialstate != SPIC::serialState::ON ){
           // 解决方法是这里再加1层判断,如果当前显示的值已经是0.0就不用再弹出此消息,因为clear_state是重置为0
           if (!(qAbs(ui->Input1->value()-0.0)<1e-3))  // 不为0需要弹出消息框,这个条件不要写在上边的if判断,这样会直接跳过执行更后边的代码块
                  QMessageBox::information(this,"Error","请先打开串口!");
            this->clear_state(); // 这里清除状态会调用设置spinbox的value为0的函数,相当于本槽函数会被再次触发,会执行2次(解决方法见上)
            return;
        }

        // 1.3 输入值改变后再更新发送者信息
        if (this->workmode == SPIC::workMode::CC_WORK_MODE){
              this->cc_curr = arg1; // CC模式下设定的值传递给cc_curr保存,这个变量在receive_port_data用来和回读值比较判断命令是否写入正确
              this->senderinfo = SPIC::senderInfo::CC_CURR_SENDER ; // CC模式,发送者是电流
        }
        else if (this->workmode == SPIC::workMode::CV_WORK_MODE)
        {
              this->cv_volt = arg1;
              this->senderinfo = SPIC::senderInfo::CV_VOLT_SENDER ; // CV模式,发送者是电压
        }

        // 先终止后台函数查询的连接,防止冲突
        this->disconnect_connection();

        // 1.4 写入命令
        this->Port->write(setc);// 写入设置命令

        // 1.5 发询问是否写入正确,保证硬件收到了此命令
        SPIC::COMMAND getVal = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_CURR_GET_VAL):  // CC模式,1号框是电流询问
                                    (SPIC::COMMAND::SOUR_VOLT_GET_VAL);// CV模式,1号框是电压询问
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 5. 2号PS输入框的值变化槽函数 => senderInfo::CC_VOLT_PS_SENDER or senderInfo::CV_CURR_PS_SENDER
void SerialPortCommunication::on_Input2PS_valueChanged(double arg1)
{
        // 如果是CV,2号框就表示电流,电流有2个;如果是CC,2号框表示电压,电压有2个
        // 这里CV设置的电流和CC设置的电压都是PS状态

        // 1.1得到要写入的命令
        SPIC::COMMAND setVal = ui->rbtCV->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_LIM_POS):
                                                    (SPIC::COMMAND::SOUR_VOLT_SET_LIM_POS);
        QString command = SPIC::spic(setVal);
        command += QString::asprintf("%.2f",arg1)+"\n";
        const char * setc = command.toStdString().c_str();

        // 1.2 写入命令前加入一层判断,串口是否打开状态,然后电源输出是否打开状态
        if (this->serialstate != SPIC::serialState::ON ){
           // 解决方法是这里再加1层判断,如果当前显示的值已经是0.0就不用再弹出此消息,因为clear_state是重置为0
           if (!(qAbs(ui->Input2PS->value()-0.0)<1e-3))  // 不为0需要弹出消息框,这个条件不要写在上边的if判断,这样会直接跳过执行更后边的代码块
                QMessageBox::information(this,"Error","请先打开串口");
            this->clear_state(); // 这里清除状态会调用设置spinbox的value为0的函数,相当于本槽函数会被再次触发,会执行2次(解决方法见上)
            return;
        }

        // 1.3 输入值改变后再更新发送者信息
        if (this->workmode == SPIC::workMode::CC_WORK_MODE){
              this->cc_volt_ps = arg1;
              this->senderinfo = SPIC::senderInfo::CC_VOLT_PS_SENDER; // CC模式,发送者是PS电压
        }
        else if (this->workmode == SPIC::workMode::CV_WORK_MODE)
        {
              this->cv_curr_ps = arg1;
              this->senderinfo = SPIC::senderInfo::CV_CURR_PS_SENDER ; // CV模式发送者是PS电流
        }

        // 先终止后台函数查询的连接,防止冲突
        this->disconnect_connection();

         // 1.4 写入命令
        this->Port->write(setc);

        // 1.5 发询问是否写入正确,保证硬件收到了此命令
        SPIC::COMMAND getVal = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_VOLT_GET_LIM_POS): // CC模式,2号框是PS电压询问
                                    (SPIC::COMMAND::SOUR_CURR_GET_LIM_POS); // CV模式,2号框是PS电流询问
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 6. 2号EL输入框的值变化槽函数
void SerialPortCommunication::on_Input2EL_valueChanged(double arg1)
{
        // 如果是CV,2号框就表示电流,电流有2个;如果是CC,2号框表示电压,电压有2个
        // 这里CV设置的电流和CC设置的电压都是EL状态

        // 1.1得到要写入的命令
        SPIC::COMMAND setVal = ui->rbtCV->isChecked()?(SPIC::COMMAND::SOUR_CURR_SET_LIM_NEG):
                                                    (SPIC::COMMAND::SOUR_VOLT_SET_LIM_NEG);
        QString command = SPIC::spic(setVal);
        command += QString::asprintf("%.2f",arg1)+"\n";
        const char * setc = command.toStdString().c_str();

        // 1.2 写入命令前加入一层判断,串口是否打开状态,然后电源输出是否打开状态
        if (this->serialstate != SPIC::serialState::ON){
           // 解决方法是这里再加1层判断,如果当前显示的值已经是0.0就不用再弹出此消息,因为clear_state是重置为0
           if (!(qAbs(ui->Input2EL->value()-0.0)<1e-3))  // 不为0需要弹出消息框,这个条件不要写在上边的if判断,这样会直接跳过执行更后边的代码块
                QMessageBox::information(this,"Error","请先打开串口!");
            this->clear_state(); // 这里清除状态会调用设置spinbox的value为0的函数,相当于本槽函数会被再次触发,会执行2次(解决方法见上)
            return;
        }

        // 1.3 输入值改变后再更新发送者信息
        if (this->workmode == SPIC::workMode::CC_WORK_MODE){
              this->cc_volt_el = arg1;
              this->senderinfo = SPIC::senderInfo::CC_VOLT_EL_SENDER; // CC模式,发送者是EL电压
        }
        else if (this->workmode == SPIC::workMode::CV_WORK_MODE){
              this->cv_curr_el = arg1;
              this->senderinfo = SPIC::senderInfo::CV_CURR_EL_SENDER ; // CV模式发送者是EL电流
        }

        // 先终止后台函数查询的连接,防止冲突
        this->disconnect_connection();

         // 1.4 写入命令
        this->Port->write(setc);

        // 1.5 发询问是否写入正确,保证硬件收到了此命令
        SPIC::COMMAND getVal = ui->rbtCC->isChecked()?(SPIC::COMMAND::SOUR_VOLT_GET_LIM_NEG): // CC模式,2号框是EL电压询问
                                    (SPIC::COMMAND::SOUR_CURR_GET_LIM_NEG); // CV模式,2号框是EL电流询问
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 7.  power PS输入框的值变化槽函数
void SerialPortCommunication::on_powInputPS_valueChanged(double arg1)
{
        // 无论是CC还是CV,PS状态对应命令不变

        // 1.1得到要写入的命令
        SPIC::COMMAND setVal = SPIC::COMMAND::SOUR_POW_SET_LIM_POS;
        QString command = SPIC::spic(setVal);
        command += QString::asprintf("%.2f",arg1)+"\n";
        const char * setc = command.toStdString().c_str();

        // 1.2 写入命令前加入一层判断,串口是否打开状态,然后电源输出是否打开状态
        if (this->serialstate != SPIC::serialState::ON ){
           // 解决方法是这里再加1层判断,如果当前显示的值已经是0.0就不用再弹出此消息,因为clear_state是重置为0
           if (!(qAbs(ui->powInputPS->value()-0.0)<1e-3))  // 不为0需要弹出消息框,这个条件不要写在上边的if判断,这样会直接跳过执行更后边的代码块
                QMessageBox::information(this,"Error","请先打开串口!");
            this->clear_state(); // 这里清除状态会调用设置spinbox的value为0的函数,相当于本槽函数会被再次触发,会执行2次(解决方法见上)
            return;
        }

        // 1.3 输入值改变后再更新发送者信息
        this->pow_ps = arg1;
        this->senderinfo = SPIC::senderInfo::POW_PS_SENDER; // 发送者是PS功率

         // 1.4 写入命令
        this->Port->write(setc);

        // 1.5 发询问是否写入正确,保证硬件收到了此命令
        SPIC::COMMAND getVal = SPIC::COMMAND::SOUR_POW_GET_LIM_POS;
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 8 . power EL输入框的值变化槽函数
void SerialPortCommunication::on_powInputEL_valueChanged(double arg1)
{
         // 无论是CC还是CV,PS状态对应命令不变
         // <1> 写入命令
        // 1.1得到要写入的命令
        SPIC::COMMAND setVal = SPIC::COMMAND::SOUR_POW_SET_LIM_NEG;
        QString command = SPIC::spic(setVal);
        command += QString::asprintf("%.2f",arg1)+"\n";
        const char * setc = command.toStdString().c_str();

        // 1.2 写入命令前加入一层判断,串口是否打开状态,然后电源输出是否打开状态
        if (this->serialstate != SPIC::serialState::ON){
           // 解决方法是这里再加1层判断,如果当前显示的值已经是0.0就不用再弹出此消息,因为clear_state是重置为0
           if (!(qAbs(ui->powInputEL->value()-0.0)<1e-3))  // 不为0需要弹出消息框,这个条件不要写在上边的if判断,这样会直接跳过执行更后边的代码块
                QMessageBox::information(this,"Error","请先打开串口!");
            this->clear_state(); // 这里清除状态会调用设置spinbox的value为0的函数,相当于本槽函数会被再次触发,会执行2次(解决方法见上)
            return;
        }

        // 1.3 输入值改变后再更新发送者信息
        this->pow_el = arg1;
        this->senderinfo = SPIC::senderInfo::POW_EL_SENDER; // 发送者是EL功率

        // 先终止后台函数查询的连接,防止冲突
        this->disconnect_connection();

         // 1.4 写入命令
        this->Port->write(setc);

        // 1.5 发询问是否写入正确,保证硬件收到了此命令
        SPIC::COMMAND getVal = SPIC::COMMAND::SOUR_POW_GET_LIM_NEG;
        const char * getc = (SPIC::spic(getVal)+"\n").toStdString().c_str(); // 转为字符串
        this->Port->write(getc); // 写入查询设置的命令,后边就是receive_port_data函数进行处理
}

// 9. 开启电源pushbutton的槽函数
void SerialPortCommunication::on_openPowerSupply_clicked()
{
        // 1.1 获取命令
        SPIC::COMMAND setVal = SPIC::COMMAND::OUTP_SET_ON_STATE; // 设置开启电源输出命令
        QString command = SPIC::spic(setVal) +"\n"; // 命令翻译成QString,设定的命令都要跟上\n作为结束符
        const char * setc = command.toStdString().c_str(); // 转为const char*,write函数需要的格式

        // 1.2 无需对串口状态判断,因为打开串口之前开启和关闭电源使能都禁止,也就是说串口打开必然是先决条件
        // 打开串口以后开启电源使能,关闭电源依然禁止(由开启和关闭电源自己控制)
        // 发送方认为的状态,如果回读命令反馈设置失败,这段代码的功能会被重置恢复之前的状态
        ui->openPowerSupply->setEnabled(false);//开启电源禁用
        ui->closePowerSupply->setEnabled(true);//关闭电源可用
        ui->rbton->setChecked(true); // 电源输出状态显示为ON
        ui->rbtoff->setChecked(false);

        // 1.3 输入值改变后再更新发送者信息
        this->senderinfo = SPIC::senderInfo::POW_ON_SENDER;//设置发送者信息
        this->powerstate = SPIC::powerState::ON; // 发送方认为现在电源是输出状态

        // 先终止后台函数查询的连接,防止冲突
        this->disconnect_connection();

        // 1.4 写入设置命令
        this->Port->write(setc);// 写入设置命令,后边就是receive_port_data函数进行处理

        // 1.5 写入回读命令确保硬件收到了命令
        SPIC::COMMAND getVal = SPIC::COMMAND::OUTP_GET_STATE; // 获取电源输出状态的命令
        const char * getc = (SPIC::spic(getVal) +"\n").toStdString().c_str(); // 转为const char*,write函数需要的格式
        this->Port->write(getc); // 写入数据,在receive_port_data()函数处理
}

// 10.关闭电源pushbutton的槽函数
void SerialPortCommunication::on_closePowerSupply_clicked()
{
        // 1.1 获取命令
        SPIC::COMMAND setVal = SPIC::COMMAND::OUTP_SET_OFF_STATE; // 设置关闭电源输出命令
        QString command = SPIC::spic(setVal) +"\n"; // 命令翻译成QString,设定的命令都要跟上\n作为结束符
        const char * setc = command.toStdString().c_str(); // 转为const char*,write函数需要的格式

        // 1.2 无需对串口状态判断,因为打开串口之前开启和关闭电源使能都禁止,也就是说串口打开必然是先决条件
        // 打开串口以后开启电源使能,关闭电源依然禁止(由开启和关闭电源自己控制)
        // 发送方认为的状态,如果回读命令反馈设置失败,这段代码的功能会被重置恢复之前的状态
        ui->openPowerSupply->setEnabled(true);//开启电源禁用
        ui->closePowerSupply->setEnabled(false);//关闭电源可用
        ui->rbton->setChecked(false); // 电源输出状态显示为ON
        ui->rbtoff->setChecked(true);

        // 1.3 输入值改变后再更新发送者信息
        this->senderinfo = SPIC::senderInfo::POW_OFF_SENDER;//设置发送者信息
        this->powerstate = SPIC::powerState::OFF; // 发送方认为现在电源是关闭状态

        // 先终止后台函数查询的连接,防止冲突
        this->disconnect_connection();

        // 1.4 写入设置命令
        this->Port->write(setc);// 写入设置命令,后边就是receive_port_data函数进行处理

        // 1.5 写入回读命令确保硬件收到了命令
        SPIC::COMMAND getVal = SPIC::COMMAND::OUTP_GET_STATE; // 获取电源输出状态的命令
        const char * getc = (SPIC::spic(getVal) +"\n").toStdString().c_str(); // 转为const char*,write函数需要的格式
        this->Port->write(getc); // 写入数据,在receive_port_data()函数处理
}
