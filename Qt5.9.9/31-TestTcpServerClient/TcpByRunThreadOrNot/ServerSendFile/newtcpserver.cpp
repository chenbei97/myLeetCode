#include "newtcpserver.h"

NewTcpServer::NewTcpServer(QObject * parent) : QTcpServer(parent)
{

}

// 也就是说nextPendingConnection其实是对incommingConnection的一层封装
// 这里只是不再使用这层封装,而是重载incommingConnection函数只是转发出去给newdialog使用
void NewTcpServer::incomingConnection(qintptr handle) // newConnection信号出现时就会自动调用
{
      emit newDescriptor(handle);
}
