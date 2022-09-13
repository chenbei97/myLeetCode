#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QTcpServer>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = nullptr);
private:
    QHBoxLayout * mainLayout;
    QLabel  * PortLabel;
    QLineEdit * PortEdit;
    QPushButton * ConnectBtn;
private:
    QTcpServer * mTcpServer;
};
#endif // DIALOG_H
