#ifndef TCPDEALCONTROLLER_H
#define TCPDEALCONTROLLER_H

#include "tcpdealer.h"
#include "qeventloop.h"

class COMPONENT_IMEXPORT TcpDealController : public QObject
{
    Q_OBJECT
public:
    explicit TcpDealController(QObject *parent = nullptr);
    ~TcpDealController();
private:
    QThread dealerthread;
    TcpDealer * dealer;
    QEventLoop loop;
signals:
    void parse(const QString&frame, const QByteArray& msg); // 外部调用
    void parseFinished(const QVariant&d); // 外部接收
};

#endif // TCPDEALCONTROLLER_H
