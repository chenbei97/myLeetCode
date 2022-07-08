#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"

//// 串口接收数据的函数,单独管理
//void SerialPortCommunication::receive_port_data()
//{
//        // 1.先判断串口状态
//        if (this->serialstate == SPIC::serialState::OFF ){
//               qDebug()<<QTime::currentTime()<<" 串口是关闭状态,无法读取数据";
//                return;
//        }
//        qDebug()<<"here";
//        // 2.根据发送者信息读取数据
//        while (this->Port->bytesAvailable())
//        {
//              qDebug()<<QDateTime::currentDateTime().toString("yyyy MM dd hh mm ss : ")
//                     <<this->Port->portName()<<"数据正在被读取";
//              QList<QByteArray> data = this->Port->readAll().split(';');
//              bool isSelect = select_processing_method(data,this->senderinfo); // 发送者信息会在发送时被设置好
//              unsigned int repeatime = 0;
//              while (!isSelect && repeatime<=5){
//                  isSelect = select_processing_method(data,this->senderinfo); // 尝试5次
//                  ++repeatime;
//              }
//              if (!isSelect){
//                  qDebug()<<"串口数据无法处理,不能选择合适的处理方法"; // log it
//                  return;
//              }
//        }
//}
