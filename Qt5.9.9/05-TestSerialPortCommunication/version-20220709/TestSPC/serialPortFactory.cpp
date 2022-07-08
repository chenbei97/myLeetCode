#include "serialPortFactory.h"
QList<QSerialPort*> serialPortFactory::ports;
serialPortFactory::serialPortFactory()
{

}
serialPortFactory::~serialPortFactory()
{

}
QSerialPort* serialPortFactory::createPort(const QString &name, qint32 baudRate, QSerialPort::Directions direction,
                                           QSerialPort::Parity parity, QSerialPort::DataBits databit, QSerialPort::StopBits stopbit,
                                           QSerialPort::FlowControl flowcontrol)
{
           QSerialPort * port= new QSerialPort();
           port->setBaudRate(baudRate,direction);//默认9600,双向串口
           port->setPortName(name);//默认要链接COM串口名,唯一需要指定的参数,其它都有默认参数
           port->setParity(parity); // 没有奇偶校验位,最常见的奇偶校验设置,错误检测由通信协议处理
           port->setDataBits(databit); // 设置数据位为8位,大多数时候都是8bit
           port->setStopBits(stopbit);// 设置停止位数量1个
           port->setFlowControl(flowcontrol); // 没有硬件流控制
           port->setReadBufferSize(12800);
           ports.append(port);
          return port;
}



