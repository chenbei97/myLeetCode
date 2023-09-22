#include "../../inc/login/loginmodifypwd.h"

LoginModifyPwd::LoginModifyPwd(QWidget*parent):QDialog(parent)
{
    init();
    INIT_FONT;
    INIT_MODIFYPWD_MINSIZE;
}

void LoginModifyPwd::setShowInfo()
{
    auto e = tr("不存在");
    auto r = tr("存在");
    auto k = tr("正确");
    auto h = tr("错误");
    auto y = tr("符合要求");
    auto n = tr("不符合要求");
    mShowInfo->setText(QString("用户名: %1  旧密码: %2  新密码: %3")
                       .arg(userIsRight?r:e).arg(oldpwdIsRight?k:h).arg(newpwdIsRight?y:n));
}

void LoginModifyPwd::updateState()
{
    oldpwdIsRight = false;// 防止下次打开显示的消息还是正确
    newpwdIsRight = false;
    userIsRight = false;
    mUserEdit->clear();
    mOldPwdEdit->clear();
    mNewPwdEdit->clear();
}

QString LoginModifyPwd::lastModifiedUser() const
{
    return mModifyUser;
}

void LoginModifyPwd::setCurrentUser(const QString& user)
{
    mUserEdit->clear();
    if (user == LoginInfoDefaultUser) { // 是管理员账户登录
        mUserEdit->setEnabled(true);
    } else { // 是普通用户登录，只有更改自己密码的权限
        mUserEdit->setText(user);
        mUserEdit->setEnabled(false);
        onUserEditFinished(); // 手动触发1次
    }
}


void LoginModifyPwd::onModifyBtn()
{
    // 还要检查是否成功修改用户名对应的密码
    auto r = userIsRight && oldpwdIsRight && newpwdIsRight;
    if (r)  {  // 在用户名,新旧密码都正确的前提下去更新
        bool n = LoginSqlReadWritePointer->updatePwd(mUserEdit->text().simplified(),mNewPwdEdit->text().simplified());
        if (n) {
            QMessageBox::information(this,tr("消息"),tr("更改密码成功!"));
            mModifyUser = mUserEdit->text().simplified(); // 额外保留上次修改的用户名称信息
            updateState();
            accept();
        }
    }
    else {
        QMessageBox::warning(this,tr("警告"),tr("请检查提示的信息!"));
    }
    //close();//改用close不用reject
}

void LoginModifyPwd::onUserEditFinished()
{
    auto user = mUserEdit->text().simplified();
    if (user.isEmpty()) {
        QMessageBox::warning(this,tr("警告"),tr("用户名不允许为空!"));
        return;
    }
    userIsRight = LoginSqlReadWritePointer->validateUser(user); // 核验user,内部mCurrentUser被设置,用于下方密码使用
    setShowInfo();
}

void LoginModifyPwd::onOldPwdEditFinished()
{
    auto pwd = mOldPwdEdit->text().simplified();
    if (pwd.isEmpty()) {
        QMessageBox::warning(this,tr("警告"),tr("密码不允许为空!"));
        return;
    }
    oldpwdIsRight = LoginSqlReadWritePointer->validatePwd(pwd); // 在匹配user的基础上继续核验pwd
    setShowInfo();
}

void LoginModifyPwd::onNewPwdEditFinished()
{
    auto pwd = mNewPwdEdit->text().simplified();
    if (pwd.isEmpty()) {
        QMessageBox::warning(this,tr("警告"),tr("密码不允许为空!"));
        return;
    }
    if (pwd == mOldPwdEdit->text().simplified())
    {
        QMessageBox::warning(this,tr("警告"),tr("新密码与旧密码相同!"));
        mNewPwdEdit->clear();
        return;
    }
    // 新密码是否符合8位带字母数字和特殊字符
    QRegExpValidator v;
    v.setRegExp(QRegExp(PWDLimit));
    int pos = 0;
    newpwdIsRight =  (v.validate(pwd,pos) == QValidator::Acceptable);
    setShowInfo();
}

void LoginModifyPwd::init()
{
    userIsRight = false;
    oldpwdIsRight = false;
    newpwdIsRight = false;
    mUserEdit = new LineEdit;
    mOldPwdEdit = new LineEdit;
    mNewPwdEdit = new LineEdit;
    mUserEdit->setClearButtonEnabled(true);
    mOldPwdEdit->setClearButtonEnabled(true);
    mNewPwdEdit->setClearButtonEnabled(true);
    mOldPwdEdit->setEchoMode(LineEdit::Password);
    mNewPwdEdit->setEchoMode(LineEdit::Password);
    mNewPwdEdit->setToolTip(tr("要求8位,大写字母,数字和特殊字符的组合!"));

    QFormLayout * flay = new QFormLayout;
    flay->addRow(tr("请输入用户名: "),mUserEdit);
    flay->addRow(tr("请输入原密码: "),mOldPwdEdit);
    flay->addRow(tr("请输入新密码: "),mNewPwdEdit);
    connect(mUserEdit,&LineEdit::editingFinished,this,&LoginModifyPwd::onUserEditFinished);
    connect(mOldPwdEdit,&LineEdit::editingFinished,this,&LoginModifyPwd::onOldPwdEditFinished);
    connect(mNewPwdEdit,&LineEdit::editingFinished,this,&LoginModifyPwd::onNewPwdEditFinished);
    connect(mUserEdit,&LineEdit::textChanged,this,[this]{userIsRight=false;setShowInfo();}); // 一旦重新编辑就修改
    connect(mOldPwdEdit,&LineEdit::textChanged,this,[this]{oldpwdIsRight=false;setShowInfo();});
    connect(mNewPwdEdit,&LineEdit::textChanged,this,[this]{newpwdIsRight=false;setShowInfo();});

    flay->labelForField(mUserEdit)->setFont(QFont(DefaultFontFamily,DefaultFontSize));
    flay->labelForField(mOldPwdEdit)->setFont(QFont(DefaultFontFamily,DefaultFontSize));
    flay->labelForField(mNewPwdEdit)->setFont(QFont(DefaultFontFamily,DefaultFontSize));

    mShowInfo = new Label;
    setShowInfo();
    mShowInfo->setAlignment(Qt::AlignVCenter|Qt::AlignLeft);
    mShowInfo->setMinimumWidth(550);
    mModifyBtn = new PushButton(tr("确认修改"));
    connect(mModifyBtn,&PushButton::clicked,this,&LoginModifyPwd::onModifyBtn);
    QHBoxLayout * blay = new QHBoxLayout;
    blay->addWidget(mShowInfo);
    blay->addStretch();
    blay->addWidget(mModifyBtn);

    mLay = new QVBoxLayout;
    mLay->addLayout(flay);
    mLay->addLayout(blay);

    setLayout(mLay);
}
