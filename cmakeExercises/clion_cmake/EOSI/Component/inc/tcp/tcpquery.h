#ifndef TCPQUERY_H
#define TCPQUERY_H

#include "tcploader.h"

class COMPONENT_IMEXPORT TcpQuery : public QObject
{
    Q_OBJECT
public:
    explicit TcpQuery(QObject *parent = nullptr);
    bool exec(const QString& f,const QByteArray& c);
    void setAutoConnect(bool e);
    QVariant result() const;

    QString errorString() const;
    TcpErrorCode errorCode() const;
    bool haveError() const;
private:
    bool autoreconnect;
    TcpSocket * socket;
    TcpErrorCode mErrorCode;
    bool needRepeat() const;
    bool needReconnect(const QString& f,const QByteArray& c);
signals:
    void parseResult(const QVariant& d);
    void parseError(const QString& e);
    void parseError(TcpErrorCode code);
    void connected();
    void disconnected();
};

#endif // TCPQUERY_H
