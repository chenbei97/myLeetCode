#ifndef TCPREADWRITEEXAMPLE_H
#define TCPREADWRITEEXAMPLE_H

#include "qtcpsocket.h"
#include "qthread.h"
#include "../public.h"

class COMPONENT_IMEXPORT SocketReader : public QObject
 {
     Q_OBJECT

 public :
     SocketReader(QTcpSocket *socket, QObject *parent = nullptr)
         : QObject(parent), socket_(socket)
     {
         connect(socket_, &QTcpSocket::readyRead, this, &SocketReader::readData);
     }

 private slots:
     void readData() {
         // 在读线程中读取数据
         qDebug()<<"read's thread = "<<QThread::currentThread();
         while (socket_->bytesAvailable() > 0) {
             QByteArray data = socket_->readAll();
             // 处理读取到的数据
             qDebug() << "Received data:" << data;
         }
     }

 private:
     QTcpSocket *socket_;
 };

 class COMPONENT_IMEXPORT SocketWriter : public QObject
 {
     Q_OBJECT

 public:
     SocketWriter(QTcpSocket *socket, QObject *parent = nullptr)
         : QObject(parent) , socket_(socket){}

 public slots:
     void sendData(const QByteArray &data) {
         qDebug()<<"write's thread = "<<QThread::currentThread();
         socket_->write(data);
     }
 private:
     QTcpSocket *socket_;
 };


static void test_tcpreadwrite()
{ // 这段代码复制放在主程序,不要直接调用这个函数,局部变量会回收导致异常
    // 从结果来看,读写都是一个线程,不是不同的线程
    QTcpSocket * socket = new QTcpSocket;
    socket->connectToHost("localhost", 3000);
    SocketReader * reader = new SocketReader(socket);
    SocketWriter * writer = new SocketWriter(socket);
    QTimer * timer = new QTimer;
    QObject::connect(timer,&QTimer::timeout, writer, [&]{
        writer->sendData("hello word");
    });
    timer->start(1000);
}
#endif // TCPREADWRITEEXAMPLE_H
