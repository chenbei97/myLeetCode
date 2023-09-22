#ifndef INITAPPCONTROLLER_H
#define INITAPPCONTROLLER_H

#include "qscreen.h"
#include "login/loginmain.h"
#include "main/mainsplash.h"
#include "main/mainwindow.h"

class InitAppController : public QObject
{
    Q_OBJECT
protected:
    LoginMain * mLoginWin;
    MainSplash * mSplashWin;
    MainWindow * mMainWin;
public:
    explicit InitAppController(QObject*parent = nullptr);
    ~InitAppController();
    void keepCenter(QWidget *w,int gold = 2);
    void apply() ;
private slots:
    Q_INVOKABLE void load();

};

#endif // INITAPPCONTROLLER_H
