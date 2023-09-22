#ifndef TCPLOADER_H
#define TCPLOADER_H

#include "tcpsocket.h"

class TcpQuery;
class COMPONENT_IMEXPORT TcpLoader : public QObject
{
    Q_OBJECT
public:
    friend class TcpQuery;// 友元类
    static TcpLoader& instance();

    void connectToHost(const QString &ip, quint16 port,QIODevice::OpenMode openMode = QIODevice::ReadWrite);
    void disconnectFromHost();
    bool waitForConnected(int msecs = SocketWaitTime);
    bool isConnected() const;
    QString lastError() const;
private:
    TcpSocket * mSocket = nullptr;
private:
    explicit TcpLoader(QObject *parent = nullptr);
    TcpLoader(const TcpLoader&){}
    TcpLoader operator= (const TcpLoader&){return *this;}
    ~TcpLoader(){}
signals:

};

static int reconnect(QWidget*parent = nullptr)
{
    if (!TcpLoaderPointer->isConnected()) // 防止重复打开
        TcpLoaderPointer->connectToHost(SocketLocalHost,SocketPort);
    // 定时重连的逻辑
    int ret = 0 ;
    bool r = TcpLoaderPointer->waitForConnected(SocketWaitTime);
    if (r){
        QMessageBox::information(parent,QObject::tr("消息"),QObject::tr("重连成功!"),QMessageBox::Ok);
        return 1;
    }

    unsigned int i = 0; // 已经运行了1次
    while (!r && i<5) { // 这里需要阻塞,否则点第·1下等一会连上了但是下边图标已经执行设置了notok
        ret = QMessageBox::critical(parent,QObject::tr("错误"),QObject::tr("未连接,尝试重连? [%1]").arg(i+1),
                                    QMessageBox::Yes | QMessageBox::No);
        ++i;
       if (ret == QMessageBox::Yes) {
           TcpLoaderPointer->connectToHost(SocketLocalHost, SocketPort);
           r = TcpLoaderPointer->waitForConnected(SocketWaitTime);
           if (!r) QMessageBox::critical(parent,QObject::tr("错误"),QObject::tr("重连失败!"),QMessageBox::Ok);
           else break;
       }
       else break;
    }

    if (ret == QMessageBox::No) return -1; // 如果是取消操作直接返回

    if (i >= 5) {
        QMessageBox::critical(parent,QObject::tr("错误"),QObject::tr("已尝试5次,请稍后再连接!"),QMessageBox::Ok);
    } else {
         QMessageBox::information(parent,QObject::tr("消息"),QObject::tr("重连成功!"),QMessageBox::Ok);
     }
    return i;
}

#endif // TCPLOADER_H
