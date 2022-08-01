#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include    <QTcpServer>
#include <QTcpSocket>
#include    <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class TCPServer; }
QT_END_NAMESPACE

class TCPServer : public QMainWindow
{
  Q_OBJECT
public:
  explicit TCPServer(QWidget *parent = nullptr);
  ~TCPServer();
protected:
  void closeEvent(QCloseEvent *event);
private slots:
  void on_actStart_triggered();
  void on_actStop_triggered();
  void on_actHostInfo_triggered();
  void on_actClear_triggered();
  void on_btnSend_clicked();
private:
  Ui::TCPServer *ui;
  QLabel * LabListen;
  QLabel * LabSocketState;
  QTcpServer *tcpServer; //TCP服务器
  QTcpSocket *tcpSocket;//TCP通讯的Socket
  QString getLocalIP();//获取本机IP地址
private slots: // 自定义槽函数
  void onNewConnection(); // 响应QTcpServer的newConnection信号
  void onSocketStateChange(QAbstractSocket::SocketState socketState); // 响应stateChanged信号
  void onClientConnected(); // 响应客户端连接信号
  void onClientDisconnected();// 响应客户端断开连接信号
  void onSocketReadyRead();// 读取客户端传入的数据
  void on_comboIP_currentTextChanged(const QString &arg1);
  void on_spinPort_valueChanged(const QString &arg1);
};
#endif // TCPSERVER_H
