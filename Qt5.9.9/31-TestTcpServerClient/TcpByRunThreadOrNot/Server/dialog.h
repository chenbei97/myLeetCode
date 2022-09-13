#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QTcpServer>
#include <QTcpSocket>

class MainWindow : public QDialog
{
  Q_OBJECT

public:
      explicit MainWindow(QWidget *parent = nullptr);
private:
      QGridLayout * mainLayout;
      QLabel * PortLabel;
      QLineEdit * PortEdit;
      QPushButton * StartConnectBtn;
      QGroupBox * HistoryMsgBox;
      QPlainTextEdit * HistoryMsgEdit;
      QVBoxLayout * HistoryLayout;
      QGroupBox * SendMsgBox;
      QPlainTextEdit * SendMsgEdit;
      QVBoxLayout * SendMsgLayout;
      QPushButton * SendBtn;
private:
      QTcpServer * mTcpServer; // 服务器需要1个服务器对象+1个套接字对象
      QTcpSocket * mTcpSocket; // 服务器监听newConnection信号,然后通过nextPendingConnection获取和客户端通信的套接字
};
#endif // MAINWINDOW_H
