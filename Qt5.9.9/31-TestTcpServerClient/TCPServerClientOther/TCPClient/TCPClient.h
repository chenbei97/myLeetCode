#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>

class TCPClient : public QDialog
{
      Q_OBJECT
public:
      explicit TCPClient(QWidget *parent = nullptr);
private:
      bool state;
      int port;
      QHostAddress * serverAddr;
      QString  userName;
      QTcpSocket * tcpSocket;
public slots:
      void onChatBtn();
      void onConnected();
      void onDisConnected();
      void onReadyRead();
      void onSendBtn();
private:
      QListWidget * Content; // 模拟聊天室
      QLineEdit * SendMsgEdit; // 发送的信息
      QPushButton * SendBtn; // 发送信息
      QLabel * UserNameLabel;
      QLineEdit * UserNameEdit; // 用户名
      QLabel * ServerAddrLabel;
      QLineEdit * ServerAddrEdit; // 连接的IP地址
      QLabel * PortLabel;
      QLineEdit * PortEdit; // 连接的端口号
      QPushButton * ChatBtn; // 进入聊天室
      QGridLayout * mainLayout; // 布局
};
#endif // TCPCLIENT_H
