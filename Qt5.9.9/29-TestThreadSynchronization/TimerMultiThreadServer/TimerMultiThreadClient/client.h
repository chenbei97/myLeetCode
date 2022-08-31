#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QtNetwork/QTcpSocket>

class Client : public QDialog
{
      Q_OBJECT
public:
      explicit Client(QWidget *parent = nullptr);
public slots:
      void on_GetBtn_Enable();
      void on_GetBtn_Time();
      void on_ReadTime();
      void on_showError(QAbstractSocket::SocketError socketError);
private:
    QLabel * serverNameLabel; QLineEdit * serverNameEdit;
    QLabel * portLabel; QLineEdit * portEdit;
    QDateTimeEdit * dateTimeEdit;
    QLabel * stateLabel;
    QPushButton * GetBtn;
    QPushButton * quitBtn;
    uint currentTime;
    QTcpSocket * tcpSocket;
};
#endif // CLIENT_H
