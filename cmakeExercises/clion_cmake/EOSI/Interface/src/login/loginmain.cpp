#include "../../inc/login/loginmain.h"

LoginMain::LoginMain(QWidget* parent) :QDialog(parent)
{
        setObjectName("LoginMain");
        mLogo = new LoginLogo;
        mTool = new LoginTool;
        mNext = new LoginNext;

        mMainLay = new QVBoxLayout;

        mMainLay->addLayout(mLogo);
        mMainLay->addWidget(mTool);
        mMainLay->addLayout(mNext);

        mMainLay->setStretchFactor(mLogo,1);
        mMainLay->setStretchFactor(mTool,8);
        mMainLay->setStretchFactor(mNext,1);

        setLayout(mMainLay);
        INIT_FONT;
        INIT_WINDOW_MINSIZE;
//        setAttribute(Qt::WA_QuitOnClose);
//        setAttribute(Qt::WA_DeleteOnClose);
        setStyleSheet(LoginMain_Style);
        setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMinMaxButtonsHint);

        connect(mNext,&LoginNext::clicked,this,&LoginMain::onShowMainWindow);
        connect(mTool,&LoginTool::socketConnectedState,mNext,&LoginNext::updateMachineInfo);
}

QString LoginMain::loginIP() const
{
    return mTool->ip().remove(' ');
}

QString LoginMain::loginUser() const
{
    return mTool->username();
}

void LoginMain::onShowMainWindow()
{
     // 进入主界面要做的一些事
    // 1. 连接成功、用户名密码正确、数据库目录正确

    // 2.更新初始化配置 写成system/ip: ip这样的键值对
    QSharedPointer<LoginInitConfig> config = QSharedPointer<LoginInitConfig>(new LoginInitConfig);

    config->ip = qMakePair(LoginConfigToString[LoginConfigParamType::IP],mTool->ip());

    auto encryuser = encry_color(mTool->username());
    config->username = qMakePair(LoginConfigToString[LoginConfigParamType::USERNAME],encryuser);

    auto encrypwd = encry_color(mTool->password());
    config->password = qMakePair(LoginConfigToString[LoginConfigParamType::PASSWORD],encrypwd);

    config->dbdir = qMakePair(LoginConfigToString[LoginConfigParamType::DBDIR],mTool->dbdir());
    config->dbtype = qMakePair(LoginConfigToString[LoginConfigParamType::DBTYPE],mTool->dbtype());

    //LOG<<"encryuser = "<<encryuser<<" encrypwd = "<<encrypwd;
    LOG<<"updateConfig: "<<config->ip<<config->username<<config->password<<config->dbdir<<config->dbtype;
    updateConfig(config.get()); // 进入主界面的时候要把用户更新的登录信息重新写入

    if (CurrentSqliteType) // 确保只能有1个数据库连接
        QSqlDatabase::removeDatabase(MysqlDriver);
    else {
        #ifdef UseSqlcipher
            QSqlDatabase::removeDatabase(SqlcipherDriver);
        #else
            QSqlDatabase::removeDatabase(SqliteDriver);
        #endif
    }
#ifdef UseSqlcipher
    LOG<<"mysql is open?"<<QSqlDatabase::database(MysqlDriver).isOpen()
      <<" sqlcipher is open?"<<QSqlDatabase::database(SqlcipherDriver).isOpen();
#else
    LOG<<"mysql is open?"<<QSqlDatabase::database(MysqlDriver).isOpen()
      <<" sqlite is open?"<<QSqlDatabase::database(SqliteDriver).isOpen();
#endif

    if (mTool->canLoadMain()){
        mTool->closeCheckConnectedTimer(); // 主界面的定时器来接替其功能
        accept();
    }
    else {
        QMessageBox::critical(this,tr("错误"),tr("请完成所有验证步骤!"),QMessageBox::Ok);
    }
}

void LoginMain::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(LOGIN_BACK_PATH));
    event->accept();
}

