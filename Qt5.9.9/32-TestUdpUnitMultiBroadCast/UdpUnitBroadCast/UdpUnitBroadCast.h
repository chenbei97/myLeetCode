#ifndef UDPUNITBROADCAST_H
#define UDPUNITBROADCAST_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class UdpUnitBroadCast; }
QT_END_NAMESPACE

class UdpUnitBroadCast : public QMainWindow
{
  Q_OBJECT
private:
  QLabel  *LabSocketState;//状态栏显示
  QUdpSocket  *udpSocket;// udp客户端
  QString getLocalIP();//获取本机IP地址
public:
  explicit UdpUnitBroadCast(QWidget *parent = nullptr);
  ~UdpUnitBroadCast();
private slots://自定义槽函数
  void onSocketStateChange(QAbstractSocket::SocketState socketState);
  void onSocketReadyRead();//接收来自其它udp客户端的信息
private slots:
  void on_actStart_triggered();
  void on_actStop_triggered();
  void on_actHostInfo_triggered();
  void on_actClear_triggered();
  void on_btnSend_clicked();
  void on_btnBroadcast_clicked();
private:
  Ui::UdpUnitBroadCast *ui;
};
#endif // UDPUNITBROADCAST_H
