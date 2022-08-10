#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H
#include <QThread>
#include <QMutex>

class serverThread : public QThread
{
    Q_OBJECT
public:
    explicit serverThread(QObject *parent = nullptr);
    ~serverThread();
    void startServerThread(const QString &portName, int waitTimeout, const QString &response); //UI按钮调用此函数更新3个私有属性
    void run() Q_DECL_OVERRIDE;
signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);
private:
    QString portName; // 串口名称
    QString response; // 服务端发给客户端的消息
    int waitTimeout; // 等待客户端发起请求的允许超时时间
    QMutex mutex;
    bool quit;
};
#endif // SERVERTHREAD_H
