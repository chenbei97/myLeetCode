#include "../../inc/login/loginverifydb.h"

extern LoginSqlReadWrite * LoginSqlReadWritePointer = SqliteVerifyPointer;
extern  SQLType CurrentSqlType = SQLType::Sqlite;

LoginVerifyDB::LoginVerifyDB(QWidget*parent):QDialog(parent)
{
    mLay = new QVBoxLayout;

    mVerifyBtn = new PushButton(tr("验证"));
    mCancelBtn = new PushButton(tr("取消"));

    mDatabaseName = new LineEdit(DataBaseName);
    mUserName = new LineEdit("root");
    mPassWord = new LineEdit("199791");
    mPassWord->setEchoMode(LineEdit::Password);
    mIPAddress = new LineEdit("127.0.0.1");
    mIPAddress->setValidator(new QRegExpValidator(QRegExp(IPLimit)));
    mIPAddress->setInputMask("000.000.000.000"); // 用于占位
    mPort = new LineEdit("3306");

    mDatabaseName->setClearButtonEnabled(true);
    mUserName->setClearButtonEnabled(true);
    mPassWord->setClearButtonEnabled(true);
    mIPAddress->setClearButtonEnabled(true);
    mPort->setClearButtonEnabled(true);

    QFormLayout * toplay = new QFormLayout;
    toplay->addRow(tr("数据源: "),mDatabaseName);
    toplay->addRow(tr("用户名: "),mUserName);
    toplay->addRow(tr("源密码: "),mPassWord);
    toplay->addRow(tr("IP地址: "),mIPAddress);
    toplay->addRow(tr("端口号: "),mPort);

    QHBoxLayout * blay = new QHBoxLayout;
    blay->addStretch();
    blay->addWidget(mVerifyBtn);
    blay->addWidget(mCancelBtn);

    mLay->addLayout(toplay);
    mLay->addLayout(blay);
    setLayout(mLay);
    INIT_FONT;
    INIT_VERIFYDB_MINSIZE;
    setWindowState(Qt::WindowNoState);
    connect(mCancelBtn,&PushButton::clicked,this,&LoginVerifyDB::reject);
    connect(mVerifyBtn,&PushButton::clicked,this,&LoginVerifyDB::onVerifyBtn);
}

void LoginVerifyDB::onVerifyBtn()
{
        if (mDatabaseName->text().simplified().isEmpty()){
            QMessageBox::critical(this,tr("错误"),tr("数据源名称不允许为空!"));
             reject();
             return;
        }

        bool res = false ;
        QVariant param;
        if (CurrentSqliteType){
            param =  mDatabaseName->text().simplified()+".db3"; // 只创建指定路径的db3
        }
        else {
            param.setValue(DBConfig{mDatabaseName->text(),mUserName->text(),
                              mPassWord->text(),mIPAddress->text(),mPort->text()});
        }
        //LOG<<"sql type = "<<((LoginSqlReadWritePointer->type() == SQLType::Mysql)?"mysql":"sqlite");
        auto dlg = getWaitDialog();
        connect(LoginSqlReadWritePointer,&LoginSqlReadWrite::validateDBStarted,
                this,[&]{dlg->show();qApp->processEvents();});//可能不能正常显示文本,repaint也可以试试
        connect(LoginSqlReadWritePointer,&LoginSqlReadWrite::validateDBFinished,
                this,[&](){dlg->accept();});
        res = LoginSqlReadWritePointer->validateDB(param);
        res? accept():reject();
}

QString LoginVerifyDB::dbName() const
{
    return mDatabaseName->text().simplified();
}

void LoginVerifyDB::updateState()
{ // LoginSqlReadWritePointer是全局指针,切换数据库类型时会改变
    // 这样不需要使用一个私有变量放在LoginVerifyDB来切换使用，而且其他任何类都可以使用
    bool r1 = true, r2 = false;

    if (CurrentSqlType == SQLType::Mysql){ // LoginSqlReadWritePointer->type()不要用这个判断,读取配置时没更改这个
        mUserName->setEnabled(r1);
        mPassWord->setEnabled(r1);
        mIPAddress->setEnabled(r1);
        mPort->setEnabled(r1);
    }
    else{
        mUserName->setEnabled(r2);
        mPassWord->setEnabled(r2);
        mIPAddress->setEnabled(r2);
        mPort->setEnabled(r2);
    }
    mDatabaseName->setEnabled(true);
}
