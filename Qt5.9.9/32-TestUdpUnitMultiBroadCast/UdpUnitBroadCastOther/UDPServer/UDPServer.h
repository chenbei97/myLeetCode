#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QTimer>
#include <QHostAddress>

class UDPServer : public QDialog
{
    Q_OBJECT
public:
    explicit UDPServer(QWidget *parent = nullptr,Qt::WindowFlags f = 0);
private:
    QLabel * TimerLabel;
    QLineEdit * TextLineEdit;
    QPushButton * StartBtn;
    QVBoxLayout * mainLayout;
public slots:
    void StartBtnClicked();
    void Timeout();
private:
    int portId;
    bool isStarted;
    QUdpSocket * udpSocket;
    QTimer * timer;
};
#endif // UDPSERVER_H
