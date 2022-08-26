#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "mServer.h"
// 服务器程序 <---> 套接字(列表) <---> 客户端程序
// 自定义的服务器和自定义的套接字作了本该TCPServer做的事情

// mSocket完成的事情：
// 1. 定义了对readyRead信号的槽函数,这样TCPServer可以直接拿到数据,相当于简化了TCPServer的程序
// 2. disconnected信号多携带了一个信息，即套接字描述符descriptor

// mServer完成的事情：
// 1. 定义客户端套接字列表统一管理
// 2. 对指定地址和端口的listen,如果是QTcpServer,应该要手动listen,但是mServer构造函数就进行了监听
// 3. 拿到套接字的信息后对客户端进行广播
// 4. 一个客户端断开连接后,对客户端套接字列表的对等套接字的清理工作

// TCPServer只需要做的事情
// 1. 指定端口号创建服务器对象,即mServer的对象
// 2. CreateBtn的槽函数编写
// 3. 响应mServer的updateServer信号直接显示在UI上即可
class TCPServer : public QDialog
{
      Q_OBJECT
public:
      explicit TCPServer(QWidget *parent = nullptr);
private:
      qint64 port;
      mServer * tcpServer;//由于mServer作了大量工作,这里的程序简化了许多
private slots:
      void onCreateBtnClicked();
      void onUpdateServer(QString msg,qint64 length);
private:
      QListWidget *  Content;
      QLabel * PortLabel;
      QLineEdit * PortEdit;
      QPushButton * CreateBtn;
      QGridLayout * mainLayout;
};
#endif // TCPSERVER_H
