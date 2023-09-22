#ifndef TCPDEALER_H
#define TCPDEALER_H

#include "../utilities/jsonreadwrite.h"
#include "../tcp/tcpprotocol.h"

class COMPONENT_IMEXPORT TcpDealer : public QObject
{
    Q_OBJECT
public:
    explicit TcpDealer(QObject *parent = nullptr);
    void parse(const QString&f,const QByteArray &msg);
private:
    QVariant d;
    QMutex mutex;
signals:
    void parseFinished(const QVariant&d);
};

#endif // TCPDEALER_H
