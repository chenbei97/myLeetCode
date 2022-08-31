#include "timerServer.h"
#include "server.h"

TimerServer::TimerServer(QObject*parent):QTcpServer(parent)
{
      if (parent != Q_NULLPTR)
          mServer = (Server*) parent; // TimerServer的父类是Server,将其强转为Server指针保存在子类的内部
      // 这样的目的是TimerServer会用到TimerThread,它发出的2个信号就可以再TimerServer的内部直接传递给Server指针显示
      // 如果借助信号和槽函数,肯定是要连接TimerThread的信号和Server的槽函数
      // 但是这个TimerThread对象Server拿不到,它在TimerServer的incomingConnection函数里
      // 所以只能借助存储父类的指针来访问
}

void TimerServer::incomingConnection(qintptr socketDescriptor)
{
      TimerThread * thread = new TimerThread(socketDescriptor,0);//为到来的客户端连接构建新的线程
      //线程内部开始执行run函数,有错误的时候把2个信号发出去
      // 没有错误的时候,线程会写入时间信息
      // 说白了就是这个thread内部的QTcpSocket做的工作本应在这里执行
      // 但是引入了新线程所以转移到run函数,但是需要知道socketDescriptor
      // socketDescriptor传递给线程,这样新的QTcpSocket就是和客户端的QTcpSocket一一对应
      connect(thread,SIGNAL(finished()),this->mServer,SLOT(on_threadSignals())); // 信号是跨线程的所以默认使用排队连接
      connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),Qt::DirectConnection);//这里是同一线程故使用直接连接
      thread->start(); // 开始执行线程任务
}
