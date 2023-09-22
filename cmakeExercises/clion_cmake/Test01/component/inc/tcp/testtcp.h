#ifndef TESTTCP_H
#define TESTTCP_H

#include "../widgets/pushbutton.h"
#include "../widgets/textedit.h"
#include "../widgets/lineedit.h"
#include "../utilities/path.h"
#include "../utilities/testtcpreadwrite.h"
#include "../utilities/encry.h"
#include "tcploader.h"
#include "tcpquery.h"
#include "tcpassemblercontroller.h"

class COMPONENT_IMEXPORT TestTcp : public QWidget
{
    Q_OBJECT
public:
    explicit TestTcp(QWidget *parent = nullptr);
    QPushButton * connectBtn;
    QPushButton * disconnectBtn;
    QPushButton * sendBtn;
    QLineEdit * sendEdit;
    QTextEdit * edit;
    QByteArray json;
    TcpQuery query;
    void onSend();
    void onConnect();
    void onDisconnect();
    QVariantMap fakeDatafor0x0000() const;
    QVariantMap fakeDatafor0x0002() const;
    void test0();
    void test1();
    void test2();
signals:

};


#endif // TESTTCP_H
