#ifndef TESTHOSTINFORMATIONQUERY_H
#define TESTHOSTINFORMATIONQUERY_H

#include <QMainWindow>
#include <QHostInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class TestHostInformationQuery; }
QT_END_NAMESPACE

class TestHostInformationQuery : public QMainWindow
{
    Q_OBJECT
public:
    explicit TestHostInformationQuery(QWidget *parent = nullptr);
    ~TestHostInformationQuery();
private slots:
    void on_btnGetHostInfo_clicked();
    void on_btnClear_clicked();
    void on_btnLookup_clicked();
    void on_btnDetail_clicked();
    void on_btnALLInterface_clicked();
    void on_btnGetDNS_clicked();
    // 自定义槽函数,lookupHost的槽函数
    void lookedUpHostInfo(const QHostInfo &host);
private:
    Ui::TestHostInformationQuery *ui;
    QString  protocolName(QAbstractSocket::NetworkLayerProtocol protocol); // 通过协议类型返回协议名称
};
#endif // TESTHOSTINFORMATIONQUERY_H
