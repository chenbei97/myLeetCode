#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class TCPClient; }
QT_END_NAMESPACE

class TCPClient : public QMainWindow
{
  Q_OBJECT
private:
    QTcpSocket  *tcpClient;  // 客户端套接字,会在服务器端的nextPendingConnection被服务器拿到
    QLabel  *LabSocketState;  //状态栏显示标签
    QString getLocalIP();//获取本机IP地址
protected:
    void closeEvent(QCloseEvent *event);
public:
  explicit TCPClient(QWidget *parent = nullptr);
  ~TCPClient();
private slots:
  void on_actConnect_triggered();
  void on_actDisconnect_triggered();
  void on_actClear_triggered();
  void on_btnSend_clicked();
private slots: // 自定义槽函数
  void onConnected();
  void onDisconnected();
  void onSocketStateChange(QAbstractSocket::SocketState socketState);
  void onSocketReadyRead();//读取服务端传入的数据
  void on_comboServer_currentIndexChanged(const QString &arg1);
  void on_spinPort_valueChanged(const QString &arg1);
private:
  Ui::TCPClient *ui;
};
#endif // TCPCLIENT_H
