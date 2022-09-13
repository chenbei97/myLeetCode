#ifndef NEWDIALOG_H
#define NEWDIALOG_H
#include <QDialog>
#include <QTcpSocket>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include "newtcpserver.h" // 区别1：使用自定义的服务器

class NewDialog : public QDialog
{
  Q_OBJECT

public:
  explicit NewDialog(QWidget *parent = nullptr);
private:
    QHBoxLayout * mainLayout;
    QLabel  * PortLabel;
    QLineEdit * PortEdit;
    QPushButton * ConnectBtn;
private:
    NewTcpServer * mTcpServer;
};

#endif // NEWDIALOG_H
