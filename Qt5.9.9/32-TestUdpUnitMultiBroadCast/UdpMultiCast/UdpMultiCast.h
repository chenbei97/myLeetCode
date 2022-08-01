#ifndef UDPMULTICAST_H
#define UDPMULTICAST_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class UdpMultiCast; }
QT_END_NAMESPACE

class UdpMultiCast : public QMainWindow
{
  Q_OBJECT
private:
  QLabel  *LabSocketState;
  QUdpSocket  *udpSocket;//ud客户端
  QHostAddress groupAddress;//组播地址
  QString getLocalIP();//获取本机IP地址
public:
  explicit UdpMultiCast(QWidget *parent = nullptr);
  ~UdpMultiCast();
private slots://自定义槽函数
  void onSocketStateChange(QAbstractSocket::SocketState socketState);
  void onSocketReadyRead();
private slots:
  void on_actStart_triggered();
  void on_actStop_triggered();
  void on_actHostInfo_triggered();
  void on_actClear_triggered();
  void on_btnMulticast_clicked();
private:
  Ui::UdpMultiCast *ui;
};
#endif // UDPMULTICAST_H
