#include "TestHostInformationQuery.h"
#include "ui_TestHostInformationQuery.h"
#include    <QNetworkInterface>

TestHostInformationQuery::TestHostInformationQuery(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestHostInformationQuery)
{
    ui->setupUi(this);
}

TestHostInformationQuery::~TestHostInformationQuery()
{
    delete ui;
}

//  1. QHostInfo获取主机信息
void TestHostInformationQuery::on_btnGetHostInfo_clicked()
{
    QString hostName=QHostInfo::localHostName();// 静态函数,本地主机名
    ui->plainTextEdit->appendPlainText("本机主机名为："+hostName);

    QHostInfo hostInfo=QHostInfo::fromName(hostName); // 从主机名获取本机IP地址(非异步方式)
    QList<QHostAddress> addList=hostInfo.addresses();// IP地址列表

    if (!addList.isEmpty())
    {
        ui->plainTextEdit->appendPlainText("IP地址个数为："+QString::asprintf("%d",addList.count()));
        for (int i=0;i<addList.count();i++)
        {
            QHostAddress aHost=addList.at(i); //每一项是一个QHostAddress
            bool show=ui->chkOnlyIPv4->isChecked();// 是否只显示IPv4协议类型
            if (show) // 如果只想显示IPV4,当前的协议类型是IPV4的时候再显示
                show=(QAbstractSocket::IPv4Protocol==aHost.protocol()); // 判断IP地址的协议类型,是IPV4为true否则false
            else
                show=true; // 不只显示IPV4(都显示)就为true
            if (show) { // 如果确实为IPV4的协议类型,想要显示的话可以显示; 或者不想显示IPV4
                ui->plainTextEdit->appendPlainText(QString::asprintf("第%d个协议类型为：",i+1)+this->protocolName(aHost.protocol()));//协议类型
                ui->plainTextEdit->appendPlainText("其IP地址为："+aHost.toString()); // IP地址转为字符串显示
                ui->plainTextEdit->appendPlainText("----------------------------------------");
            }
        }
    }
}

// 2. 获取本机DNS域名
void TestHostInformationQuery::on_btnGetDNS_clicked()
{
    QString dnsName=QHostInfo::localDomainName();// 静态函数,本地主机名
    ui->plainTextEdit->appendPlainText("本机DNS域名为："+dnsName);
}

// 3. 通过协议类型返回协议名称
QString TestHostInformationQuery::protocolName(QAbstractSocket::NetworkLayerProtocol protocol)
{
    switch(protocol)
    {
      case QAbstractSocket::IPv4Protocol:
          return "IPv4协议类型";
      case QAbstractSocket::IPv6Protocol:
        return "IPv6协议类型";
      case QAbstractSocket::AnyIPProtocol:
        return "任何IP协议类型";
      default:
        return "未知的协议类型";
     }
}

// 4. 查找指定域名的IP地址
void TestHostInformationQuery::on_btnLookup_clicked()
{
    QString hostname=ui->editHost->text(); // 要查找的域名
    ui->plainTextEdit->appendPlainText("正在查找指定的域名IP地址信息："+hostname);
    QHostInfo::lookupHost(hostname,this,SLOT(lookedUpHostInfo(QHostInfo)));
}

// 5. 是lookupHost的槽函数,查找域名的IP地址
void TestHostInformationQuery::lookedUpHostInfo(const QHostInfo &host)
{
    QList<QHostAddress> addList=host.addresses();//拿到查询到的所有IP地址
    if (!addList.isEmpty()) // 和on_btnGetHostInfo_clicked()代码类似
        for (int i=0;i<addList.count();i++)
        {
            QHostAddress aHost=addList.at(i);
            bool show=ui->chkOnlyIPv4->isChecked();//只显示IPv4
            if (show)
                show=QAbstractSocket::IPv4Protocol==aHost.protocol();
            else
                show=true;

            if (show) {
                ui->plainTextEdit->appendPlainText(QString::asprintf("第%d个协议类型为：",i+1)+this->protocolName(aHost.protocol()));
                ui->plainTextEdit->appendPlainText("其IP地址为："+aHost.toString());
                ui->plainTextEdit->appendPlainText("----------------------------------------");
            }
        }
}

// 6. 使用QNetworkInterface异步获取本机所有IP地址
void TestHostInformationQuery::on_btnDetail_clicked()
{
    QList<QHostAddress> addList=QNetworkInterface::allAddresses();
    if (!addList.isEmpty())
    for (int i=0;i<addList.count();i++)
    {
        QHostAddress aHost=addList.at(i);
        bool show=ui->chkOnlyIPv4->isChecked();//只显示IPv4
        if (show)
            show=QAbstractSocket::IPv4Protocol==aHost.protocol();
        else
            show=true;

        if (show)
        {
            ui->plainTextEdit->appendPlainText(QString::asprintf("第%d个协议类型为：",i+1)+this->protocolName(aHost.protocol()));//协议类型
            ui->plainTextEdit->appendPlainText("其IP地址为："+aHost.toString()); // IP地址转为字符串显示
            ui->plainTextEdit->appendPlainText("----------------------------------------");
        }
    }
}

// 7. 使用QNetworkInterface异步获取本机所有网络接口列表
void TestHostInformationQuery::on_btnALLInterface_clicked()
{

    QList<QNetworkInterface>    list=QNetworkInterface::allInterfaces();
    for(int i=0;i<list.count();i++)
    {
        QNetworkInterface aInterface=list.at(i);
        if (!aInterface.isValid()) // 如果无效跳
           continue;

        ui->plainTextEdit->appendPlainText("设备名称："+aInterface.humanReadableName());
        ui->plainTextEdit->appendPlainText("硬件地址："+aInterface.hardwareAddress());
        QList<QNetworkAddressEntry> entryList=aInterface.addressEntries(); // 某个网络接口的所有关联的网络掩码和广播地址
        for(int j=0;j<entryList.count();j++)
        {
            QNetworkAddressEntry aEntry=entryList.at(j);
            ui->plainTextEdit->appendPlainText("   其IP 地址："+aEntry.ip().toString());
            ui->plainTextEdit->appendPlainText("   其子网掩码："+aEntry.netmask().toString());
            ui->plainTextEdit->appendPlainText("   其广播地址："+aEntry.broadcast().toString()+"\n");
        }
        ui->plainTextEdit->appendPlainText("\n");
    }
}

// 8. 清空文本框
void TestHostInformationQuery::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


