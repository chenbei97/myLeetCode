#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QTcpSocket>

class Dialog : public QDialog
{
  Q_OBJECT
public:
   explicit Dialog(QWidget *parent = nullptr);
private:
    QGridLayout * mainLayout;
    QLabel * ServerPortLabel;
    QLineEdit * ServerPort;
    QLabel * ServerIPLabel;
    QLineEdit * ServerIP;
    QGroupBox * HistoryMsgBox;
    QPlainTextEdit * HistoryMsgEdit;
    QVBoxLayout * HistoryMsgLayout;
    QGroupBox * SendMsgBox;
    QPlainTextEdit * SendMsgEdit;
    QVBoxLayout * SendMsgLayout;
    QPushButton * ConnectBtn;
    QPushButton * DisconnectBtn;
    QPushButton * SendBtn;
private:
     QTcpSocket * mTcpSocket;
};
#endif // DIALOG_H
