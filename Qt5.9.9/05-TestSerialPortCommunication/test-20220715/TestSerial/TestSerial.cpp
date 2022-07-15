#include "TestSerial.h"
#include "ui_TestSerial.h"
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <QProgressDialog>

TestSerial::TestSerial(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestSerial)
{
      ui->setupUi(this);
      this->fixedQueryTimer = new QTimer;
      this->fixedQueryTimer->setInterval(300);
      this->fixedQueryTimer->start();
      connect(this->fixedQueryTimer,SIGNAL(timeout()),this,SLOT(send_query()));

      this->port = new QSerialPort();
      this->port->setPortName("COM7");
      this->port->setBaudRate(115200);
      this->port->setDataBits(QSerialPort::Data8);
      this->port->open(QSerialPort::ReadWrite);
      connect(this->port,SIGNAL(readyRead()),this,SLOT(receive_reply()),Qt::AutoConnection);// ,Qt::QueuedConnection,Qt::AutoConnection
       connect(this->port,SIGNAL(bytesWritten(qint64)),this,SLOT(write_query(qint64))); // 这个槽函数没用
}

void TestSerial::receive_reply()
{
        char buf[32];
        qint64 lineLength = this->port->readLine(buf,sizeof(buf));
        // if (lineLength == -1) ui->statusbar->showMessage("没有数据进来"); // 因为某些问题没有数据读取,然而如果真的没有数据就不会有readyRead信号,此函数本来也就不会执行
        this->bufferBytes.append(buf);
        int currEnd = bufferBytes.indexOf('\n'); // 可能为-1
        auto data = bufferBytes.left(currEnd); // 使用left来获取,舍弃\n字符
        bufferBytes.remove(0,currEnd+1);//remove是返回移除后的bufferBytes不是返回移除的字符串!
        if (data.contains(';')){ // 如果数据包含了分号 => 后台查询的反馈
              QList<QByteArray> spilitData = data.split(';');
              if (spilitData.size()!=3) {return;} // 反馈不是3条数据返回
              for (auto &d : spilitData)
              {
                  int idx = d.indexOf('.')+1; //小数点所在的位置 一般是1或者2,由于索引从0开始,所以再+1
                  if (d.length() != (idx+6)) {return;} // 如果小数点后不是6位数字,说明此数据不对
              }
              ui->statusbar->showMessage(data);// ok,成功接收到3条正确的信息
        }
        else { // 电压、电流、功率的设定和查询命令
            // 不需要判断小数点后的位数,因为不是固定查询,输入值不固定(lineEditText),电压设定和电压反馈值比较不能使用文本格式对比
            // 只能使用double格式对比,用户的输入值可能是11不会是11.0或者11.000000
            this->feedbackVal = data.toDouble();
            qDebug()<<"反馈值="<<feedbackVal<<" 输入值="<<inputVal;
            if (qAbs(feedbackVal - inputVal)>1e-3) {this->setVariableAccepted=false;return;}// 数据长度对,但是误差容限内数值没对上
            this->setVariableAccepted = true;
        }
}

void TestSerial::on_lineEdit_returnPressed()
{
    qDebug()<<"returnPressed";
    QLineEdit * lineEdit = qobject_cast<QLineEdit*>(sender()) ;//获取发送信息的对象
    QByteArray text = lineEdit->text().toLocal8Bit(); // 获取文本
    QByteArray command = "MEAS:VOLT "+text+";:MEAS:VOLT?\n";

    mutex.lock();
    mutex.unlock();
    this->port->write(command);
    this->inputVal = text.toDouble(); // 保存用户想要设定的命令参数,用于在接收数据时比较,浮点数可以不精确相等
    unsigned int t = 1;
    while ((!port->waitForReadyRead(300) ) && // 单纯的延时功能,利用它在Qt::AutoConnection模式下可以在该循环内不阻止receive_reply函数执行
                t<=5 ) //  重发次数不超过5次时while会执行
    {
        // 单单setVariableAccepted情况还不行,因为用户更改输入值以后setVariableAccepted还没来得及变化保持上次的true
        if (this->setVariableAccepted && (qAbs(inputVal-feedbackVal)<1e-3)) // 这样receive_reply函数能够及时的更新setVariableAccepted的情况反馈给这里的while循环
        {
            QMessageBox::information(this,"设定成功","设定输入电压成功!");
            return;
        }
        mutex.lock();
        this->port->write(command);
        mutex.unlock();
        ++t;
    }

    QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
    ui->lineEdit->clear();
    this->inputVal = 0.0;
}
TestSerial::~TestSerial()
{
    delete ui;
    this->port->close();
}

void TestSerial::send_query()
{
      this->port->write("MEAS:VOLT?;:MEAS:CURR?;:MEAS:POW?\n"); // 34个字符
      // 固定查询因为本身就是重发机制,不适用while之类的进行阻塞超时重发判断
      //无论数据反馈的对不对,这边一样重发
       port->flush();
}
void TestSerial::write_query(qint64 bytes)
{
     // qDebug()<<"正在写入字节数"<<bytes; // 34个字符
    if (!this->port->bytesAvailable()) this->ui->statusbar->showMessage(QTime::currentTime().toString("hh:mm:ss：")+"暂时没有数据进来");
}
