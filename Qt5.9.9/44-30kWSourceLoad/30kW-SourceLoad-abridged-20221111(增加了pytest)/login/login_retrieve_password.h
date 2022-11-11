#ifndef RETRIEVEPASSWORD_H
#define RETRIEVEPASSWORD_H

#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QRegExp>
#include <QPaintEvent>
#include <QPainter>
#include <QDir>
#include <QDebug>

class RetrieveFirst;
class RetrieveSecond;
class RetrieveThird;

class RetrievePassword : public QObject
{
      Q_OBJECT
public:
      explicit RetrievePassword(QObject * parent = Q_NULLPTR);
      void process();
private:
      RetrieveFirst * FirstWindow;
      RetrieveSecond * SecondWindow;
      RetrieveThird * ThirdWindow;
signals:
      void createAccount(); //这个需要通知login界面才定义的
};

class RetrieveFirst: public QDialog
{
      Q_OBJECT
public:
      explicit RetrieveFirst(QWidget*parent = Q_NULLPTR);
protected:
      void paintEvent(QPaintEvent*e) override;
private:
      void initUI();
      void initConnections();
      bool usernameIsExist(const QString & username);
      QString findPassword();
      QLabel * TipLabel;
      QLabel * UserNameLabel;
      QLineEdit * UserNameEdit;
      QPushButton * NextBtn;
      QPushButton * CancelBtn;
signals:
      void next(const QString& username,const QString& password); // 传递给二级窗口的用户和密码
      void createAccount(); // 传递给登录窗口的信息
};

class RetrieveSecond: public QDialog
{
      Q_OBJECT
public:
      explicit RetrieveSecond(QWidget*parent = Q_NULLPTR);
      void getUser(const QString& username,const QString& password); // 拿到第一步传递的用户信息
protected:
      void paintEvent(QPaintEvent*e) override;
private:
      void initUI();
      void initConnections();
      QString mUserName;
      QLabel * TipLabel;
      QLabel * PassWordLabel;
      QPushButton * ResetBtn;
      QPushButton * EndBtn;
signals:
      void next(const QString &username);// 传递给三级窗口的用户名信息
};

class RetrieveThird: public QDialog
{
      Q_OBJECT
public:
      explicit RetrieveThird(QWidget*parent = Q_NULLPTR);
      void getUseName(const QString& username); // 拿到第二步传递的用户信息
protected:
      void paintEvent(QPaintEvent*e) override;
private:
      void initUI();
      void initConnections();
      QString mUserName;
      QLabel * TipLabel;
      QLabel * NewPwdLabel;
      QLineEdit * NewPwdEdit;
      QPushButton * OkBtn;
      QPushButton * CancelBtn;
signals:
      void back(); // 返回第二步的窗口/取消重置密码
};
#endif // RETRIEVEPASSWORD_H
