#ifndef MSOCKET_H
#define MSOCKET_H
#include <QTcpSocket>
#include <QObject>
// QTcpSocket基本继承了QAbstractSocket的全部信号和槽函数,自己是没有信号和槽函数的
// 做了本该TCPServer做的：定义了对readyRead信号的槽函数,这样TCPServer可以直接拿到数据,相当于简化了TCPServer的程序
// 其次：对disconnected()信号做了一层封装多携带了一个信息descriptor,即disconnected(int descriptor);
// unConnected()内部只是对disconnected(int descriptor)作了一层转发
class mSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit mSocket(QObject * parent = nullptr);
signals:
    void sendMessage(QString msg,qint64 length); //自定义的
    void disconnected(int descriptor);//自定义的,相比继承来的多了参数int,是为了把套接字描述符带出去
protected slots:
    void dataReceived();
    void unConnected();
};

#endif // MSOCKET_H

