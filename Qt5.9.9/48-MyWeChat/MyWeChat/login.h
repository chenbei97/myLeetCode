#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <mainwindow.h>
#include <QDir>

namespace Ui {
  class Login;
}

class Login : public QDialog
{

  Q_OBJECT

public:
  explicit Login(QWidget *parent = nullptr); 
private:
  Ui::Login *ui;
  MainWindow * mMainWindow;
  QDomDocument mXmlDoc;
};

#endif // LOGIN_H
