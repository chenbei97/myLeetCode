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
      connect(this->port,SIGNAL(readyRead()),this,SLOT(receive_reply()),Qt::QueuedConnection);// ,Qt::QueuedConnection,Qt::AutoConnection
      connect(this->port,SIGNAL(bytesWritten(qint64)),this,SLOT(write_query(qint64))); // 这个槽函数没用
}

void TestSerial::receive_reply()
{
        char buf[32];
        qint64 lineLength = this->port->readLine(buf,sizeof(buf));
        qDebug()<<"receive_reply";
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
        }
}
void TestSerial::func1()
{
   // 1.第一种写法 waitForReadyRead+AutoConnection
    QLineEdit * lineEdit = qobject_cast<QLineEdit*>(sender()) ;
    QByteArray text = lineEdit->text().toLocal8Bit();
    QByteArray command = "MEAS:VOLT "+text+";:MEAS:VOLT?\n";
    mutex.lock();
    mutex.unlock();
    this->port->write(command);
    this->inputVal = text.toDouble();

    unsigned int t = 1;
    while ((!port->waitForReadyRead(300) ) && // 等待300ms没结果
                t<=5 ) //  重发次数不超过5次时while会执行
    {
        // receive_reply函数虽然能够执行,但是readyRead信号被阻塞,总是超时
        // waitForReadyRead的超时功能失效,仅仅起到了延时的功能
        mutex.lock();
        this->port->write(command);
        mutex.unlock();
        qDebug()<<"超时"<<t<<"次";
        ++t;
    }
     if (t<5) // t>=5总是会成立,但观察feedbackval和Inputval其实已经相等了,所以引入第2种写法不能只用超时返回值判断
    {
        QMessageBox::information(this,"设定成功","设定输入电压成功!");
        return;
    }
      QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
      ui->lineEdit->clear();
      this->inputVal = 0.0;
}
void TestSerial::func2()
{
    // 2.第二种写法 waitForReadyRead+AutoConnection+feedbackval
    QLineEdit * lineEdit = qobject_cast<QLineEdit*>(sender()) ;
    QByteArray text = lineEdit->text().toLocal8Bit();
    QByteArray command = "MEAS:VOLT "+text+";:MEAS:VOLT?\n";
    mutex.lock();
    mutex.unlock();
    this->port->write(command);
    this->inputVal = text.toDouble();

    unsigned int t = 1;
    while ((!port->waitForReadyRead(300) ) && // 单纯的延时功能,在该循环内阻塞readyRead但不阻止receive_reply函数执行
                t<=5 &&(qAbs(inputVal-feedbackVal)>=1e-3)) //  还要多判断feedbackval和inputval辅助作为while事件的条件
    {
        // receive_reply函数能够及时的更新feedbackval的情况反馈给这里的while循环
        mutex.lock();
        this->port->write(command);
        mutex.unlock();
        qDebug()<<"超时"<<t<<"次";
        ++t;
    }
    if (t<5)
    {
        QMessageBox::information(this,"设定成功","设定输入电压成功!");
        return;
    }
      QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
      ui->lineEdit->clear();
      this->inputVal = 0.0;
}
void TestSerial::func3()
{
    // 3. 第三种写法Timer+AutoConnection
    QLineEdit * lineEdit = qobject_cast<QLineEdit*>(sender());
    QByteArray text = lineEdit->text().toLocal8Bit();
    QByteArray command = "MEAS:VOLT "+text+";:MEAS:VOLT?\n";
    mutex.lock();
    mutex.unlock();
    this->port->write(command);
    this->inputVal = text.toDouble();

    QTime timer;
    timer.start();
    unsigned int t = 1;
    // 这里会发现总是超时,因为while循环卡住了receive_reply函数的执行无法给feedbackVal反馈
    // 所以还不能用普通的延时循环,必须使用waitForReadyRead的延时
    while (!(qAbs(inputVal-feedbackVal)<1e-3) && (t<=5)) // 不仅阻塞readyRead还阻塞receive_reply函数
    {
        // 创建一个延时,给300ms让串口收到数据进行处理设置feedbackVal
         if (timer.elapsed()>300) // 如果等待了300ms还不满足条件就++t
         {
            qDebug()<<QTime::currentTime()<<" "<<QString::asprintf("第%d次重发",t);
            this->port->write(command);
            ++t;
            timer.restart();
         }
    }
    if (t<5)
    {
        QMessageBox::information(this,"设定成功","设定输入电压成功!");
        return;
    }
    QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
    ui->lineEdit->clear();
    this->inputVal = 0.0;
}
void TestSerial::on_lineEdit_returnPressed()
{
    qDebug()<<"returnPressed";
    // 1. 第一种写法 waitForReadyRead+AutoConnection (不能解决问题)
    // func1();

    // 2.第二种写法 waitForReadyRead+AutoConnection+feedbackVal  (解决问题)
    // func2();

    // 3. 第二种写法Timer+AutoConnection (不能解决问题)
    func3();
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
