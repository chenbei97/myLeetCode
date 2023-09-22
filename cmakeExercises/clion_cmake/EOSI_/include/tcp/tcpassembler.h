#ifndef TCPASSEMBLER_H
#define TCPASSEMBLER_H

#include "tcpprotocol.h"

class COMPONENT_IMEXPORT TcpAssembler : public QObject
{
    Q_OBJECT
public:
    explicit TcpAssembler(QObject *parent = nullptr);
    void assemble(const QString&frame,const QVariantMap& m);
private:
    QMutex mutex;
signals:
    void assembleResult(const QByteArray& d);
};

#endif // TCPASSEMBLER_H
