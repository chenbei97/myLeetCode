#ifndef TCPASSEMBLERCONTROLLER_H
#define TCPASSEMBLERCONTROLLER_H

#include "tcpassembler.h"

class COMPONENT_IMEXPORT TcpAssemblerController : public QObject
{
    Q_OBJECT
public:
    explicit TcpAssemblerController(QObject *parent = nullptr);
    ~TcpAssemblerController();
    QByteArray message() const;
private:
    QThread assemblethread;
    TcpAssembler * assembler;
    QByteArray msg;
    QEventLoop * loop;
signals:
    void assemble(const QString&frame, const QVariantMap& m);
    void assembleFinished();
};

#endif // TCPASSEMBLERCONTROLLER_H
