#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "qtcpsocket.h"
#include "tcpdealer.h"
#include "tcpdealcontroller.h"
#include "../public.h"

class COMPONENT_IMEXPORT TcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = nullptr);
    ~TcpSocket();

    void connectToHost(const QString &hostName, quint16 port,QIODevice::OpenMode openMode = QIODevice::ReadWrite);
    void disconnectFromHost();
    bool isConnected() const;
    bool detectConnectionState();

    qintptr socketDescriptor() const;

    bool waitForConnected(int msecs = SocketWaitTime);

    TcpErrorCode exec(const QString& f,const QByteArray& c);
    QVariant result() const ;
    QString lastError() const;

    void write(QByteArray d);

private:
    QTcpSocket * socket = nullptr;
    QByteArray command ;
    QString frame;
    QByteArray message;
    QQueue<QByteArray> messageQueue;
    QHash<QString,QVariant> data;
    TcpDealController * controller;
    bool mConnected;
    TcpErrorCode mLastErrorCode;
    void onReadyReadSlot();
    void processQueueMessage();
    void onParseFinished(const QVariant&d);
signals:
    //void parseFinished();
    void connected();
    void disconnected();
};

#endif // TCPSOCKET_H
