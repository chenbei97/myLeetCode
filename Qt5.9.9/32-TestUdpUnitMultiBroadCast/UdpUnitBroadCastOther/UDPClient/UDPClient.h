#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>
#include <QMessageBox>
#include <QHostAddress>

class UDPClient : public QDialog
{
      Q_OBJECT
public:
      explicit UDPClient(QWidget *parent = nullptr,Qt::WindowFlags f = 0);
private:
      QTextEdit * textEdit;
      QPushButton * closedBtn;
      QVBoxLayout * mainLayout;
private:
      int portId;
      QUdpSocket * udpSocket;
public slots:
      void ReceiveDatagram();
};
#endif // UDPCLIENT_H
