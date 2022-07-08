#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"
#include <QList>
#include <QMessageBox>
#include <QDebug>

/*
**********界面组件的一些信号对应的普通槽函数,不绑定发送者,因为这些槽函数的特点是不发送查询命令
********** 串口名称、串口波特率的下拉索引变化的槽函数
********** 打开、关闭串口，切换CV、CC工作模式的点击槽函数
*/
static const  int  _ui_slot_functions_num = 6;

static const QList<const char *> __ui__slot__functions__ = {
          "on_serialNameBox_currentIndexChanged",
          "on_serialBaudRateBox_currentIndexChanged",
          "on_openSerialPort_clicked",
          "on_closeSerialPort_clicked",
          "on_rbtCV_clicked",
          "on_rbtCC_clicked"
};

// 1.选择串口spinbox的槽函数
void SerialPortCommunication::on_serialNameBox_currentIndexChanged(const QString &arg1)
{
        this->Port->setPortName(arg1);
}

// 2.. 选择波特率spinbox的槽函数
void SerialPortCommunication::on_serialBaudRateBox_currentIndexChanged(const QString &arg1)
{
        this->Port->setBaudRate(arg1.toInt());
}

// 3. 打开串口 pushbutton的槽函数
void SerialPortCommunication::on_openSerialPort_clicked()
{
        // 点击打开串口,连接信号,并open串口

        connect(this->Port,&QSerialPort::readyRead,this,&SerialPortCommunication::receive_port_data);

        if (!this->Port->isOpen())
        {
              this->Port->open(QIODevice::ReadWrite); // 尝试再次打开
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

         this->fixed_query_thread->startQuery(); //开启线程
        this->timer->start(); // 开启定时器

        // 设置和波特率的组件、打开串口的按钮处于不可编辑状态，关闭串口处于可编辑状态
        this->ui->serialNameBox->setEnabled(false); // 不可再选择串口
        this->ui->serialBaudRateBox->setEnabled(false); // 不可再选择波特率
        this->ui->openSerialPort->setEnabled(false); // 不可再次打开串口
        this->ui->closeSerialPort->setEnabled(true); // 关闭串口打开
        this->ui->openPowerSupply->setEnabled(true);// 开启电源使能
        this->ui->closePowerSupply->setEnabled(false); // 关闭电源禁止
        this->ui->rbtoff->setChecked(true);// 默认电源无输出
        this->ui->rbton->setChecked(false);
}

// 4. 关闭串口pushbutton的槽函数
void SerialPortCommunication::on_closeSerialPort_clicked()
{
        this->fixed_query_thread->stopQuery(); // 关闭线程
        this->timer->stop(); //关闭定时器

        // 恢复使能状态
        this->ui->serialNameBox->setEnabled(true);
        this->ui->serialBaudRateBox->setEnabled(true);

        this->ui->openSerialPort->setEnabled(true); //打开串口使能
        this->ui->closeSerialPort->setEnabled(false);// 关闭串口禁止

        this->ui->rbton->setChecked(false); // 关闭之前是on或者off,关闭之后必定是off
        this->ui->rbtoff->setChecked(true);

        // 关闭串口后电源输出2个使能都禁止
        this->ui->openPowerSupply->setEnabled(false);
        this->ui->closePowerSupply->setEnabled(false);

        disconnect(this->Port,&QSerialPort::readyRead,this,&SerialPortCommunication::receive_port_data);
        this->Port->close();

        this->serialstate = SPIC::serialState::OFF;
        this->powerstate = SPIC::powerState::OFF; // 关闭也必定是OFF
        this->senderinfo = SPIC::senderInfo::UNKNOW;
        this->workmode = SPIC::workMode::CV_WORK_MODE; // 回归默认值
        this->workstatus = SPIC::workStatus::CV_WORK_STATUS; // 回归默认值
}

// 5. 切换CV模式radiobutton的槽函数
void SerialPortCommunication::on_rbtCV_clicked()
{
      if (this->workmode == SPIC::workMode::CV_WORK_MODE){ // 如果点击之前已经是CV模式
          return; // 不需要改变任何信息直接返回
      }
      else if (this->workmode == SPIC::workMode::CC_WORK_MODE) // 点击之前是CC模式
      {

          int select = QMessageBox::warning(this,"警告","您选择切换至CV模式,界面信息将更新,是否确认?",
                QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
           if (select == QMessageBox::No || select == QMessageBox::Cancel)
           {
                ui->rbtCC->setChecked(true); // 因为用户的点击让按钮变化了,要恢复到以前的CC状态
                ui->rbtCV->setChecked(false);
              return;
           }
           this->workmode = SPIC::workMode::CV_WORK_MODE;// 点了确定再更新状态
           change_label_component(SPIC::workMode::CV_WORK_MODE); // 切换至CV模式
      }

}

// 6. 切换CC模式radiobutton的槽函数
void SerialPortCommunication::on_rbtCC_clicked()
{
      if (this->workmode == SPIC::workMode::CC_WORK_MODE)// 如果点击之前已经是CC模式
      {
          return; // 不需要改变任何信息直接返回
      }
      else if (this->workmode == SPIC::workMode::CV_WORK_MODE) // 点击之前是CV模式
      {
          int select = QMessageBox::warning(this,"警告","您选择切换至CC模式,界面信息将更新,是否确认?",
                QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
           if (select == QMessageBox::No || select == QMessageBox::Cancel)
           {
              ui->rbtCC->setChecked(false); // 因为用户的点击让按钮变化了,要恢复到以前的CV状态
              ui->rbtCV->setChecked(true);
              return;
           }
           this->workmode = SPIC::workMode::CC_WORK_MODE; // 点了确定再更新状态
           change_label_component(SPIC::workMode::CC_WORK_MODE); // 切换至CC模式
      }
}
