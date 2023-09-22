#include "../../inc/login/logintool.h"

LoginTool::LoginTool(QWidget *parent) : QWidget(parent)
{
    initObject();

    initSize();

    initStyle();

    initEffect();

    initChildWin();

    initConfig();

    initLayout();

    setLayout(mLay);

    initConnections();

    INIT_FONT;
}

void LoginTool::initEffect()
{
    // 4个button开启显示和隐藏的渐变效果
    mIdentifyMachineBtn->enableEffect();
    mUserNameBtn->enableEffect();
    mPassWordBtn->enableEffect();
    mDbDirBtn->enableEffect();

    // 用户名和密码核验过数据库后才能解用
    mUserNameBtn->setEnabled(false);
    mPassWordBtn->setEnabled(false);
    mUserCreateBtn->setEnabled(false);
    mPwdModifyBtn->setEnabled(false);

    // IP地址的输入形式
    mIPEdit->setClearButtonEnabled(true);
    mIPEdit->setToolTip(tr("请输入正确的IP地址..."));
    mIPEdit->setValidator(new QRegExpValidator(QRegExp(IPLimit)));
    mIPEdit->setInputMask("000.000.000.000"); // 用于占位

    mUserEdit->setClearButtonEnabled(true);

    // 密码非明文
    mPwdEdit->setEchoMode(QLineEdit::Password);
    mPwdEdit->setClearButtonEnabled(true);

    mDbTypeCombo->addItems(QStringList()<<SqliteOption<<MySqlOption);
    mDbTypeCombo->setAlignment(Qt::AlignCenter);
    mDbTypeCombo->setToolTip(tr("数据库类型,默认Sqlite,Mysql需配置软件"));
    mDbDirShowLab->setToolTip(tr("Sqlite支持设置保存目录,Mysql需自行修改,目录一般在\n"
                                 "C:/ProgramData/MySQL/MySQL Server 8.0/Data,可在my.ini的datadir字段修改"));

    // 目录label可以打开文件选择框
    mDbDirShowLab->setEnabled(true); // 默认sqlite启用
    mDbDirShowLab->enablePressEvent(); // 启用鼠标事件
    mDbDirShowLab->setWaringInfo(tr("Sqlite更改目录,请把.db3文件也移动到新目录,"
                                    "否则无法检索原有用户信息!"));
    mDbDirShowLab->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    mDbDirShowLab->setFrameShape(QFrame::Box);

    // 组件框和图标一开始不显示
    mConnectBox->hide();
    mUserBox->hide();
    mPwdBox->hide();
    mDbDirBox->hide();
    mValidateFlagSocket->hide();
    mValidateFlagUser->hide();
    mValidateFlagPwd->hide();
    mValidateFlagDir->hide();

    // 组件框开启隐藏和显示效果
    mConnectBox->enableEffect();
    mUserBox->enableEffect();
    mPwdBox->enableEffect();
    mDbDirBox->enableEffect();

    // 初始化显示的图标
    mValidateFlagSocket->setPixmap(*mNotOkPix);
    mValidateFlagUser->setPixmap(*mNotOkPix);
    mValidateFlagPwd->setPixmap(*mNotOkPix);
    mValidateFlagDir->setPixmap(*mNotOkPix);
}

void LoginTool::initSize()
{
    // groupox和button的宽度一致,不能使用默认size, 另外尽量不写死size,使用setMinimumSize更好
    mConnectBox->setMinimumSize(LoginGroupboxWidth,LoginGroupboxHeight);
    mUserBox->setMinimumSize(LoginGroupboxWidth,LoginGroupboxHeight);
    mPwdBox->setMinimumSize(LoginGroupboxWidth,LoginGroupboxHeight);
    mDbDirBox->setMinimumSize(LoginGroupboxWidth,LoginGroupboxHeight);

    // 图片的label尺寸要写死,因为图片大小就这么大,而且不写死,groupbox-icon的gap会变大
    mValidateFlagSocket->setFixedSize(LoginIconSize,LoginIconSize);
    mValidateFlagUser->setFixedSize(LoginIconSize,LoginIconSize);
    mValidateFlagPwd->setFixedSize(LoginIconSize,LoginIconSize);
    mValidateFlagDir->setFixedSize(LoginIconSize,LoginIconSize);
}

void LoginTool::initStyle()
{
    mIdentifyMachineBtn->setStyleSheet(LoginMain_ButtonStyle);
    mUserNameBtn->setStyleSheet(LoginMain_ButtonStyle);
    mPassWordBtn->setStyleSheet(LoginMain_ButtonStyle);
    mDbDirBtn->setStyleSheet(LoginMain_ButtonStyle);

    mUserCreateBtn->setObjectName("createuser");
    mPwdModifyBtn->setObjectName("forgetpwd");
    mUserCreateBtn->setStyleSheet(LoginMain_CreateUserForgetPwdStyle);
    mPwdModifyBtn->setStyleSheet(LoginMain_CreateUserForgetPwdStyle);

    mDbDirShowLab->setObjectName("mDbDirShowLab");
    mDbDirShowLab->setStyleSheet("QLabel#mDbDirShowLab{color:white}");//防止对话框的颜色也变成白色

}

void LoginTool::initConfig()
{
    // 读取config.ini的参数初始化窗口
    auto ip = readConfig(LoginConfigParamType::IP);
    mIPEdit->setText(ip.remove('.')); // 移除,否则显示错误

    auto username = readConfig(LoginConfigParamType::USERNAME);
    auto user = decry_color(username);
    mUserEdit->setText(username.isEmpty()?tr("请输入用户名..."):user);

    auto  password= readConfig(LoginConfigParamType::PASSWORD);
    auto pwd = decry_color(password);
    mPwdEdit->setText(password.isEmpty()?tr("请输入密码..."):pwd);

    auto dbtype = readConfig(LoginConfigParamType::DBTYPE);
    //mDbTypeCombo->setCurrentText(dbtype); // 不能用setCurrentText,索引其实不会有变化
    mDbTypeCombo->setCurrentIndex(dbtype==MySqlOption?1:0); //这里要设置,如果读取的MYSQL但是显示的还是0,就导致验证用户时没有进入正确的判断
    dbtype==MySqlOption?mDbDirShowLab->setEnabled(false):mDbDirShowLab->setEnabled(true);
    dbtype==MySqlOption?CurrentSqlType = SQLType::Mysql:SQLType::Sqlite;
    dbtype==MySqlOption?LoginSqlReadWritePointer = MysqlVerifyPointer : LoginSqlReadWritePointer = SqliteVerifyPointer;
    mVerifyDB->updateState();

    QString dbdir = readConfig(LoginConfigParamType::DBDIR);
    QDir dir; // 没有目录就创建默认目录
    if (dbdir.isEmpty() || (dbdir =="0") || (dbdir == "null") || (!dir.exists(dbdir)))
    {
        dbdir = QStandardPaths::standardLocations(QStandardPaths::DataLocation).at(0);
        if (!dir.exists(dbdir)) dir.mkpath(dbdir); // 自动创建项目名称的文件夹并返回路径
    }
    mDbDirShowLab->setText(tr("目录: %1").arg(dbdir));

    LOG<< "read config: ip = "<<ip<<" user = "<<username
           <<" pwd = ["<<password <<","<<pwd<<"] dir = "<<dbdir << " dbtype = "<<dbtype;
}

void LoginTool::initChildWin()
{
    mVerifyDB = new LoginVerifyDB;
    mModifyPwd = new LoginModifyPwd;
    mNewUser = new LoginNewUser;
}

void LoginTool::initConnections()
{
    // 1. 4个button的显示隐藏效果
    connect(mIdentifyMachineBtn,&QPushButton::clicked,this,&LoginTool::onIdentifyMachine);
    connect(mUserNameBtn,&QPushButton::clicked,this,&LoginTool::onUserName);
    connect(mPassWordBtn,&QPushButton::clicked,this,&LoginTool::onPassWord);
    connect(mDbDirBtn,&QPushButton::clicked,this,&LoginTool::onDbDir);

    // 2. 自动连接和手动连接
    connect(mAutoConnectBtn,SIGNAL(clicked()),this,SLOT(onAutoConnection()));
    connect(&mCheckConnectedTimer,&QTimer::timeout,this,&LoginTool::onCheckConnectedState);
    mAutoConnectBtn->click(); // 执行1次自动连接
    mCheckConnectedTimer.start(SocketCheckFrequency); // 然后开始定时检测连接状态
    connect(mManualConnectBtn,SIGNAL(clicked()),this,SLOT(onManualConnection()));

    // 3. 验证用户,创建用户,验证密码,修改密码,验证目录
    connect(mUserValidateBtn,SIGNAL(clicked()),this,SLOT(onValidateUser()));
    connect(mUserCreateBtn,SIGNAL(clicked()),this,SLOT(onCreateUser()));
    connect(mPwdValidateBtn,SIGNAL(clicked()),this,SLOT(onValidatePwd()));
    connect(mPwdModifyBtn,SIGNAL(clicked()),this,SLOT(onModifyPwd()));
    connect(mDbDirValidateBtn,SIGNAL(clicked()),this,SLOT(onValidateDir()));

    // 4. 使能关系的处理
    connect(mDbTypeCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(changeSqlType(int)));//数据库类型切换时禁止用户名和密码编辑
    connect(mUserEdit,SIGNAL(textChanged(QString)),this,SLOT(onUserTextChanged(QString))); // 用户名一旦更改就禁止密码编辑
}

void LoginTool::onCheckConnectedState()
{ // 后台定时检查套接字的连接状态
    static bool isFirstUnConnected = true; // 初始化只会执行1次，首次未连接
    if (TcpLoaderPointer->isConnected())
    {
        mValidateFlagSocket->setPixmap(*mOkPix);
        mCanLoadMain[0] = true;
        emit socketConnectedState(true);
    }
    else {
        mValidateFlagSocket->setPixmap(*mNotOkPix);
        mCanLoadMain[0] = false;
        emit socketConnectedState(false);
        if (isFirstUnConnected) // 第1次进入定时程序走此判断
        {
            QMessageBox::information(this,tr("消息"),tr("检测到主机处于未连接状态!"),QMessageBox::Ok);
            isFirstUnConnected = false; // 赋值以后,这个值一直是false了
            isUnexpectedExit = false; // 首次未连接,不属于意外退出要声明,不然连着弹2个对话框
        } else { // 这里为了区分开首次定时检测和手动连接的逻辑
            if (isUnexpectedExit) { // 这个变量外部手动重新连接上会对其赋值变成true
                QMessageBox::information(this,tr("消息"),tr("主机意外退出!"),QMessageBox::Ok);
                reconnect(this); // 尝试重连
                isUnexpectedExit = false; // 处理完这次错误将其恢复,不是意外退出
            }
        } 
    }
}

void LoginTool::sendEquipmentNumberToSocket()
{
    TcpQuery query;
    TcpAssemblerController assembler;
    QVariantMap map;
    map[Field0x0001.equipment_number] = ip();
    assembler.assemble(TcpFramePool.frame0x0001,map);// 组装数据
    auto command = assembler.message();
    //qDebug()<<"command = "<<command;
    query.setAutoConnect(false); // 不要自动重连,连接失败提早返回(仅限于本函数)
    query.exec(TcpFramePool.frame0x0001,command);
    if (!query.haveError()) {
        auto result = query.result(); // 假设回复 {"equipment_number": 1,"frame": "0x0002","result": 1}
        if (result.toString() == "1") {
                LOG<<"equipment number is right"; // 设备号验证成功
                mValidateFlagSocket->setPixmap(*mOkPix);
                mCanLoadMain[0] = true;
                emit socketConnectedState(true);
        }
    } else LOG<<"send equipum error = "<<query.errorString();
}

void LoginTool::onAutoConnection()
{ // 以后的代码改为连接上套接字后发一条设备号验证,
    //mCheckConnectedTimer.blockSignals(true);
    LOG<<"is try to auto connect server!";
    if (!TcpLoaderPointer->isConnected()) // 防止重复打开
        TcpLoaderPointer->connectToHost(SocketLocalHost,SocketPort); // 192.168.31.36 127.0.0.1 192.168.1.168
    bool r = TcpLoaderPointer->waitForConnected(SocketWaitTime);

    if (r) {
        mValidateFlagSocket->setPixmap(*mOkPix);
        mCanLoadMain[0] = true;
        emit socketConnectedState(true);
        sendEquipmentNumberToSocket();
    }
    else {
        mValidateFlagSocket->setPixmap(*mNotOkPix);
        mCanLoadMain[0] = false;
        emit socketConnectedState(false);
    }
    //mCheckConnectedTimer.blockSignals(false);
}

void LoginTool::onManualConnection()
{
    LOG<<"is try to manual connect server!";
    if (TcpLoaderPointer->isConnected()) {
        QMessageBox::information(this,tr("消息"),tr("套接字已连接"),QMessageBox::Ok);
        emit socketConnectedState(true);
        sendEquipmentNumberToSocket();
        return;
    }
     emit socketConnectedState(false);
     reconnect(this);

    if (TcpLoaderPointer->isConnected()){
        mValidateFlagSocket->setPixmap(*mOkPix);
        isUnexpectedExit = true; // 已经连接刷新这个值用于下次定时,如果还有意外退出
        mCanLoadMain[0] = true;
        emit socketConnectedState(true);
        sendEquipmentNumberToSocket();
    }
    else {
        mValidateFlagSocket->setPixmap(*mNotOkPix);
       // isUnexpectedExit = false;
        mCanLoadMain[0] = false;
        emit socketConnectedState(false);
    }
}

void LoginTool::onValidateUser()
{
     auto username = mUserEdit->text().simplified(); // 用户名不允许为空
     if (username.isEmpty()) {
         mValidateFlagUser->setPixmap(*mNotOkPix);
         mCanLoadMain[1] = false;
         mPwdModifyBtn->setEnabled(false);
         return;
     }

    bool r = LoginSqlReadWritePointer->validateUser(username);
    if (r){
         mValidateFlagUser->setPixmap(*mOkPix); // 验证用户名正确
         mCanLoadMain[1] = true;

         mPassWordBtn->setEnabled(true);
         mPwdBox->setEnabled(true); // 启用,内含部件不会都启用
         mPwdEdit->setEnabled(true); // 需要继续单独设置
         mPwdValidateBtn->setEnabled(true);

         mPassWordBtn->clearFocus(); // 先清除焦点才行
         mPwdBox->setFocus();
         mPwdValidateBtn->setFocus(); // 设置验证密码是焦点
    }
    else {
        QMessageBox::critical(this,QObject::tr("错误"),QObject::tr("用户不存在!"));
        mValidateFlagUser->setPixmap(*mNotOkPix); // 用户验证失败,密码也跟着不能设置
        mValidateFlagPwd->setPixmap(*mNotOkPix);
        mCanLoadMain[1] = false;
        mCanLoadMain[2] = false;

        mPassWordBtn->setEnabled(false);//禁用,其内含部件也会禁用
        mPwdBox->setEnabled(false);
        mPwdModifyBtn->setEnabled(false);
    }
}

void LoginTool::onCreateUser()
{
    int ret = mNewUser->exec();
    if (ret == QDialog::Accepted)
    {

    }
}

void LoginTool::onValidatePwd()
{
    auto pwd = mPwdEdit->text().simplified(); // 要验证的密码不允许为空
    if (pwd.isEmpty()){
        mValidateFlagPwd->setPixmap(*mNotOkPix);
        mCanLoadMain[2] = false;
        mPwdModifyBtn->setEnabled(false); // 验证密码成功后才能修改密码
        return;
    }

    bool r = LoginSqlReadWritePointer->validatePwd(pwd);

   if (r) {
       mValidateFlagPwd->setPixmap(*mOkPix);
       mCanLoadMain[2] = true;
       mPwdModifyBtn->setEnabled(true);
       mModifyPwd->setCurrentUser(username());
   }
   else {
       QMessageBox::critical(this,QObject::tr("错误"),QObject::tr("密码不正确!"));
       mValidateFlagPwd->setPixmap(*mNotOkPix);
       mCanLoadMain[2] = false;
       mPwdModifyBtn->setEnabled(false);
   }

}

void LoginTool::onModifyPwd()
{
    int ret = mModifyPwd->exec();
    if (ret == QDialog::Accepted)
    { // 修改密码成功时要重新输入密码，前提是改的用户名是当前要登录的用户名
        if (mModifyPwd->lastModifiedUser() == username())
         mPwdEdit->clear();
        mValidateFlagPwd->setPixmap(*mNotOkPix);
    }
}

void LoginTool::onValidateDir()
{ // 数据库是否能够连接上
    if (CurrentSqliteType) // sqlite的目录需要完整提供,mysql不需要会自动检测
        SqliteVerifyPointer->mSqliteDir = mDbDirShowLab->text().remove(tr("目录: "));

    int ret = mVerifyDB->exec();

    if (ret == QDialog::Accepted)
    { // 验证成功开启用户名设置使能
        mValidateFlagDir->setPixmap(*mOkPix); //验证数据库的图标
        mCanLoadMain[3] = true;

        mUserNameBtn->setEnabled(true); // 输入用户的button
        mUserBox->setEnabled(true); // 用户验证内的edit和pushbutton

        mUserCreateBtn->setEnabled(true); // 新建用户
        //mPwdModifyBtn->setEnabled(true); // 修改密码只能在验证密码成功后修改

        mUserNameBtn->clearFocus();
        mUserBox->setFocus();
        mUserValidateBtn->setFocus(); //用户名验证是焦点

        mDbDirShowLab->setEnabled(false); // 数据库验证成功后用户不能再更改目录
    } else {
        mValidateFlagDir->setPixmap(*mNotOkPix); // 数据库验证失败,用户和密码也要设置NotOk
        mValidateFlagPwd->setPixmap(*mNotOkPix);
        mValidateFlagUser->setPixmap(*mNotOkPix);
        mCanLoadMain[3] = false;
        mCanLoadMain[2] = false;
        mCanLoadMain[1] = false;

        // 验证数据库失败，用户密码，创建用户和更改密码都不能使用
        mUserNameBtn->setEnabled(false); // 用户验证
        mUserBox->setEnabled(false);

         mUserCreateBtn->setEnabled(false); // 创建用户
         mPwdModifyBtn->setEnabled(false); // 更改密码

        mPassWordBtn->setEnabled(false); // 密码验证
        mPwdBox->setEnabled(false);

         mDbDirShowLab->setEnabled(true); // 数据库目录可以调整
    }
}

void LoginTool::onUserTextChanged(const QString&text)
{
     mValidateFlagUser->setPixmap(*mNotOkPix); // 用户名重新编辑那么用户和密码都要重新设置notok
     mValidateFlagPwd->setPixmap(*mNotOkPix);
     mCanLoadMain[1] = false;
     mCanLoadMain[2] = false;
     mPassWordBtn->setEnabled(false);
     mPwdEdit->setEnabled(false);
     mPwdBox->setEnabled(false);
     mPwdValidateBtn->setEnabled(false);
     mPwdModifyBtn->setEnabled(false);
     Q_UNUSED(text);
}

void LoginTool::changeSqlType(int idx)
{ // 切换数据库类型就要重新验证
    bool res = false;
    // 1. 图标
    mValidateFlagUser->setPixmap(*mNotOkPix);
    mValidateFlagPwd->setPixmap(*mNotOkPix);
    mValidateFlagDir->setPixmap(*mNotOkPix);
    // 2.是否可以启动主窗口
    mCanLoadMain[1] = res;
    mCanLoadMain[2] = res;
    mCanLoadMain[3] = res;
    // 3. 验证用户和密码禁用
    mUserNameBtn->setEnabled(res);
    mPassWordBtn->setEnabled(res);
    mUserBox->setEnabled(res);
    mPwdBox->setEnabled(res);
    mUserCreateBtn->setEnabled(res);
    mPwdModifyBtn->setEnabled(res);

    if (idx == 1)
    {
        mDbDirShowLab->setEnabled(false); // 对于mysql来说不需要设置保存目录,是软件固定设置的
        LOG<<"SQL Type is Changed Mysql";
        CurrentSqlType = SQLType::Mysql;
        LoginSqlReadWritePointer = MysqlVerifyPointer;

    }
    else {
         mDbDirShowLab->setEnabled(true);
         LOG<< "SQL Type is Changed Sqlite";
         CurrentSqlType = SQLType::Sqlite;
         LoginSqlReadWritePointer = SqliteVerifyPointer;
    }
    mVerifyDB->updateState();
    mNewUser->updateState();
    mModifyPwd->updateState();
}

QString LoginTool::ip() const
{
    auto ip = mIPEdit->text().simplified(); // 192.168.1.168
    // 192.168.1.168写回config.ini时应该是192.168.1  .168,否则读取的时候会变成192.168.116.8
    // 如果2个'.'之间的数字不够3位要进行空格填充
    auto fields = ip.split('.',QString::SkipEmptyParts);
    //qDebug()<<"fields = "<<fields;
    QString field;
    for (int i = 0 ; i < fields.count()-1; ++i) { // 最后1段不需要管
        field = fields[i];
        if (field.count() < 3) { // i=0,首位索引是0; i =1, 首位4; i = 2 ,首位8；

            if (field.count() == 1) // 插入2个空格
            {
                auto idx = 4*i+1; // +1是指定位置之前插入,所以要在下一位之前
                ip.insert(idx,"  ");
            }

            if (field.count() == 2) // 插入1个空格
            {
                auto idx = 4*i+2; // +2
                ip.insert(idx," ");
            }
        }
    }
   LOG<<"ip is "<<ip;
    return ip;
}

QString LoginTool::username() const
{
    return mUserEdit->text().simplified();
}

QString LoginTool::password() const
{
    return  mPwdEdit->text().simplified();
}

QString LoginTool::dbdir() const
{
    return mDbDirShowLab->text().remove(tr("目录: "));
}

QString LoginTool::dbtype() const
{
    return mDbTypeCombo->currentText();
}

void LoginTool::initObject()
{
    mCanLoadMain = {false,false,false,false};

    mIdentifyMachineBtn = new Button(tr("1.  识别机器"));
    mDbDirBtn = new Button(tr("2.  数据库  "));// 一个汉字2个空格
    mUserNameBtn = new Button(tr("3.  输入用户"));
    mPassWordBtn = new Button(tr("4.  输入密码"));

    mAutoConnectBtn = new PushButton(tr("自动连接"));
    mManualConnectBtn = new PushButton(tr("手动连接"));
    mUserValidateBtn = new PushButton(tr("验证用户"));
    mPwdValidateBtn = new PushButton(tr("验证密码"));
    mDbDirValidateBtn = new PushButton(tr("验证数据库"));
    mUserCreateBtn = new PushButton(tr("新建用户"));
    mPwdModifyBtn = new PushButton(tr("更改密码"));

    mIPEdit = new LineEdit;
    mUserEdit = new LineEdit;
    mPwdEdit = new LineEdit;

    mDbTypeCombo = new ComboBox; // 数据库类型
    mDbDirShowLab = new Label; // 数据库保存目录
    mValidateFlagSocket = new Label; // 4个图标文件显示用
    mValidateFlagUser = new Label;
    mValidateFlagPwd = new Label;
    mValidateFlagDir = new Label;

    mConnectBox = new GroupBox;
    mUserBox = new GroupBox;
    mPwdBox = new GroupBox;
    mDbDirBox = new GroupBox;

#ifdef SCREEN_1920X1080
    mOkPix = new QPixmap(LOGIN_OK_PATH_24x24);
    mNotOkPix = new QPixmap(LOGIN_NOTOK_PATH_24x24);
#elif  SCREEN_1280X800
    mOkPix = new QPixmap(LOGIN_OK_PATH_16x16);
    mNotOkPix = new QPixmap(LOGIN_NOTOK_PATH_16x16);
#else
    mOkPix = new QPixmap(LOGIN_OK_PATH);
    mNotOkPix = new QPixmap(LOGIN_NOTOK_PATH);
#endif
}

void LoginTool::initLayout()
{
    // 手动连接和自动连接
    QHBoxLayout * lay11 = new QHBoxLayout;
    lay11->addWidget(mManualConnectBtn);
    //lay11->addWidget(mAutoConnectBtn); // 自动连接不需要显示出来
    QVBoxLayout * lay1 = new QVBoxLayout;
    lay1->addWidget(mIPEdit);
    lay1->addLayout(lay11);
    mConnectBox->setLayout(lay1);

    // 用户名
    QVBoxLayout * lay2 = new QVBoxLayout;
    lay2->addWidget(mUserEdit);
    lay2->addWidget(mUserValidateBtn);
    mUserBox->setLayout(lay2);

    // 密码
    QVBoxLayout * lay3 = new QVBoxLayout;
    lay3->addWidget(mPwdEdit);
    lay3->addWidget(mPwdValidateBtn);
    mPwdBox->setLayout(lay3);

    // 数据库
    QVBoxLayout * lay4 = new QVBoxLayout;
    QHBoxLayout * lay41 = new QHBoxLayout;
    lay41->addWidget(mDbDirValidateBtn);
    lay41->addWidget(mDbTypeCombo);
    lay4->addWidget(mDbDirShowLab);
    //lay4->addStretch();
    lay4->addLayout(lay41);
    mDbDirBox->setLayout(lay4);

    // 新建用户和忘记密码
    QHBoxLayout * lay5 = new QHBoxLayout;
    lay5->addWidget(mUserCreateBtn);
    lay5->addWidget(mPwdModifyBtn);

    // 依次是连接、数据库、用户、密码
    QList<QVector<QWidget*>> widgets;
    widgets << (QVector<QWidget*>()<<mIdentifyMachineBtn<<mConnectBox<<mValidateFlagSocket);
    widgets << (QVector<QWidget*>()<<mDbDirBtn<<mDbDirBox<<mValidateFlagDir);
    widgets << (QVector<QWidget*>()<<mUserNameBtn<<mUserBox<<mValidateFlagUser);
    widgets << (QVector<QWidget*>()<<mPassWordBtn<<mPwdBox<<mValidateFlagPwd);

    // (leftmargin)=>button=>(gap1)=>groupbox=>(gap2)=>icon=>(rightmargin)+layheight
    QMap<MultilineLayout::MarginType,int> margins;
    margins[MultilineLayout::LeftMargin] = LoginLeftMargin;
    margins[MultilineLayout::Gap1] = LoginGap1;
    margins[MultilineLayout::Gap2] = LoginGap2;
    margins[MultilineLayout::RightMarigin] = LoginRightMargin;
    margins[MultilineLayout::Height] = LoginButtonHeight;

    mLay = new MultilineLayout(widgets,margins);
    mLay->addLayout(lay5);
}

void LoginTool::onIdentifyMachine()
{
    mIdentifyMachineBtn->mState = !mIdentifyMachineBtn->mState; // 增加控制变量来实现点击隐藏和显示效果
    mIdentifyMachineBtn->mState? mConnectBox->show(): mConnectBox->hide();
    mIdentifyMachineBtn->mState? mValidateFlagSocket->show(): mValidateFlagSocket->hide();
}

void LoginTool::onUserName()
{
    mUserNameBtn->mState = !mUserNameBtn->mState;
    mUserNameBtn->mState? mUserBox->show(): mUserBox->hide();
    mUserNameBtn->mState? mValidateFlagUser->show(): mValidateFlagUser->hide();
}

void LoginTool::onPassWord()
{
    mPassWordBtn->mState = !mPassWordBtn->mState;
    mPassWordBtn->mState? mPwdBox->show(): mPwdBox->hide();
    mPassWordBtn->mState? mValidateFlagPwd->show(): mValidateFlagPwd->hide();
}

void LoginTool::onDbDir()
{
    mDbDirBtn->mState = !mDbDirBtn->mState;
    mDbDirBtn->mState? mDbDirBox->show():mDbDirBox->hide();
    mDbDirBtn->mState? mValidateFlagDir->show(): mValidateFlagDir->hide();
}

bool LoginTool::canLoadMain() const
{
    // 不能用pixmap判断
    return  mCanLoadMain[0]&&mCanLoadMain[1]
            &&mCanLoadMain[2]&&mCanLoadMain[3];
}

void LoginTool::closeCheckConnectedTimer()
{
    mCheckConnectedTimer.stop();
}
