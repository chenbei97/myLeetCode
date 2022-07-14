#include "TestSerial.h"
#include "ui_TestSerial.h"
#include <QDebug>
#include <QTime>

TestSerial::TestSerial(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestSerial)
{
      ui->setupUi(this);
      this->fixedQueryTimer = new QTimer;
      this->fixedQueryTimer->setInterval(1000);
      this->fixedQueryTimer->start();
      connect(this->fixedQueryTimer,SIGNAL(timeout()),this,SLOT(send_query()));

      this->port = new QSerialPort();
      this->port->setPortName("COM7");
      this->port->setBaudRate(115200);
      this->port->setDataBits(QSerialPort::Data8);
      // qDebug()<<this->port->readBufferSize();
      // this->port->setReadBufferSize(1024);
      this->port->open(QSerialPort::ReadWrite);
      connect(this->port,SIGNAL(readyRead()),this,SLOT(receive_reply()));
      connect(this->port,SIGNAL(bytesWritten(qint64)),this,SLOT(write_query(qint64)));

      // ui->lineEdit->setFrame(false);
//      ui->lineEdit->redo();
ui->lineEdit->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);
}

TestSerial::~TestSerial()
{
    delete ui;
    this->port->close();
}

void TestSerial::send_query()
{
      // qDebug()<<QTime::currentTime().toString("hh::mm::ss")<<" send query";

      this->port->write("MEAS:VOLT?;:MEAS:CURR?;:MEAS:POW?\n"); // 34个字符
       port->flush();
}

void TestSerial::receive_reply()
{

//        qDebug()<<"before: "<<this->port->bytesAvailable();
//        qDebug()<<"canReadLine = "<<this->port->canReadLine();

        char buf[1024];
        qint64 lineLength = this->port->readLine(buf,sizeof(buf));
        this->bufferBytes.append(buf);


        qDebug()<<"before bufferbytes = "<< bufferBytes;
        int currEnd = bufferBytes.indexOf('\n'); // 可能为-1,但是-1的话command变为"",后续再判断即可,remove(0,0)也不会影响
        auto data = bufferBytes.left(currEnd); // 只能使用left来获取

        bufferBytes.remove(0,currEnd+1);//remove是返回移除后的bufferBytes不是返回移除的字符串!
        qDebug()<<"data = "<<data<<" bufferSize = "<<bufferBytes.size();
        if (data !="") // 数据有效
        {
              // 后边可以把数据分出来
              // 如果数据包含了分号 => 后台查询的

              // 否则是设置命令
        }
}

void TestSerial::write_query(qint64 bytes)
{
    // qDebug()<<"正在写入字节数"<<bytes; // 34个字符
}

void TestSerial::on_lineEdit_returnPressed()
{
    qDebug()<<"returnPressed";
    QLineEdit * lineEdit = qobject_cast<QLineEdit*>(sender()) ;//获取发送信息的对象
    QByteArray text = "MEAS:VOLT "+lineEdit->text().toLocal8Bit()+"\n"; // 获取文本

    this->port->write(text); // 按下回车才写入命令
}

