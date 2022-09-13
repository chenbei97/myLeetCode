#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QTcpSocket>

class SendFile : public QObject
{
  Q_OBJECT
public:
  explicit SendFile(QObject *parent = nullptr);
   // 连接服务器
   void connectHost(QString ip, ushort port);
   // 发送文件
   void sendFile(QString filepath);
private:
    QTcpSocket * mTcpSocket;
signals:
    void connected();
    void disconnected();
    void sendPercentProgress(int percent);
};

#endif // SENDFILE_H
