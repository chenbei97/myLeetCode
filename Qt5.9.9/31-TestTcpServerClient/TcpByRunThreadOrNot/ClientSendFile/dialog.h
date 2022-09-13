#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QTcpSocket>
#include <QProgressBar>

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = nullptr);
private:
    QGridLayout * mainLayout;
    QLabel * PortLabel;
    QLineEdit * PortEdit;
    QLabel * IPLabel;
    QLineEdit * IPEdit;
    QLineEdit * SelectFileEdit;
    QPushButton * SelectFileBtn;
    QProgressBar * PBar;
    QPushButton * ConnectBtn;
    QPushButton * SendFileBtn;
signals:
    void readyConnect(QString ip, ushort port);
    void sendFile(QString path);
};
#endif // DIALOG_H
