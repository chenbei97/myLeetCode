#include "initapp.h"

extern LoginSqlReadWrite * LoginSqlReadWritePointer = SqliteVerifyPointer;
extern  SQLType CurrentSqlType = SQLType::Sqlite;

InitAppController::InitAppController(QObject*parent):QObject(parent)
{
    mLoginWin = new LoginMain;
    mSplashWin = new MainSplash(QPixmap(SPLASH_BACK_PATH),SPLASH_LOAD_TIME);;
    mMainWin = nullptr;
    keepCenter(mLoginWin,2);
    keepCenter(mSplashWin,2);
}

void InitAppController::keepCenter(QWidget *w,int gold)
{
    const QRect availableSize = w->screen()->availableGeometry();
    w->move((availableSize.width() - mLoginWin->width()) / gold,
                    (availableSize.height() - mLoginWin->height()) / gold); //(2560-1000)/2=780,(1528-600)/2=464
}

void InitAppController::load()
{
    LOG<<"is load mainwindow!";
    mMainWin = new MainWindow;
    keepCenter(mMainWin);
    mMainWin->setLoginIP(mLoginWin->loginIP());
    mMainWin->setLoginUser(mLoginWin->loginUser());
    mMainWin->setStyle(QSS_PATH);
    mMainWin->show();
}

void InitAppController::apply()
{
    //readConfig();
    int ret = mLoginWin->exec();
    if (ret == QDialog::Accepted)
    {
        mSplashWin->startSplash();
        QCoreApplication::processEvents(QEventLoop::AllEvents);
        QTimer::singleShot(MAIN_LOAD_TIME, this, SLOT(load()));//延时n毫秒执行load函数
        LOG<<"qtimer load main! load time = "<<MAIN_LOAD_TIME<<" ms";
    } else {
        LOG<<""<<"quit app";
        QTimer::singleShot(0,qApp,SLOT(quit())); // 这样才能真正退出应用进程
    }
}

InitAppController::~InitAppController()
{ // 跟这个好像没关系
    delete  mLoginWin;
    delete mMainWin;
    delete  mSplashWin;
}
