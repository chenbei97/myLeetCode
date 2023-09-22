#include "../../inc/login/loginnewuser.h"

LoginNewUser::LoginNewUser(QWidget*parent):QDialog(parent)
{
    init();
    INIT_FONT;
    INIT_MODIFYPWD_MINSIZE;
}

void LoginNewUser::updateState()
{
    pwdIsRight = false;
    userIsRight = false;
    pwdIsSame = false;
    mUserEdit->clear();
    mPwdEdit->clear();
    mVerifyPwdEdit->clear();
}

void LoginNewUser::onNewBtn()
{
    if (!userIsRight){
        QMessageBox::warning(this,tr("警告"),tr("用户名已存在!"));
        mUserEdit->clear();
        return;
    }

    if (!pwdIsRight){
        QMessageBox::warning(this,tr("警告"),tr("密码设置不符合要求!"));
        mPwdEdit->clear();
        mVerifyPwdEdit->clear();
        return;
    }

    if (!pwdIsSame){
        QMessageBox::warning(this,tr("警告"),tr("密码两次输入不一致!"));
        mVerifyPwdEdit->clear();
        return;
    }

    bool n = LoginSqlReadWritePointer->createUser(mUserEdit->text().simplified(),mPwdEdit->text().simplified());

    if (n) {
        QMessageBox::information(this,tr("消息"),tr("创建用户成功!"));
        updateState();
        accept();
    }
    else reject();
}

void LoginNewUser::onVerifyPwdEditFinished()
{
    auto pwd = mVerifyPwdEdit->text().simplified();
    if (pwd.isEmpty()) {
        QMessageBox::warning(this,tr("警告"),tr("密码不允许为空!"));
        return;
    }

    if (pwd != mPwdEdit->text().simplified()) {
        QMessageBox::warning(this,tr("警告"),tr("密码两次输入不一致!"));
        return;
    }
    pwdIsSame = true;
}

void LoginNewUser::onPwdEditFinished()
{
    auto pwd = mPwdEdit->text().simplified();
    if (pwd.isEmpty()) {
        QMessageBox::warning(this,tr("警告"),tr("密码不允许为空!"));
        return;
    }
    // 新密码是否符合8位带字母数字和特殊字符
    QRegExpValidator v;
    v.setRegExp(QRegExp(PWDLimit));
    int pos = 0;
    pwdIsRight =  (v.validate(pwd,pos) == QValidator::Acceptable);
}

void LoginNewUser::onUserEditFinished()
{
    auto user = mUserEdit->text().simplified();
    if (user.isEmpty()) {
        QMessageBox::warning(this,tr("警告"),tr("用户名不允许为空!"));
        return;
    }
    // 检查用户名不能重复
    userIsRight = !LoginSqlReadWritePointer->validateUser(user);
}

void LoginNewUser::init()
{
    mUserEdit = new LineEdit;
    mPwdEdit = new LineEdit;
    mVerifyPwdEdit = new LineEdit;
    mUserEdit->setClearButtonEnabled(true);
    mPwdEdit->setClearButtonEnabled(true);
    mPwdEdit->setClearButtonEnabled(true);
    mPwdEdit->setEchoMode(LineEdit::Password);
    mVerifyPwdEdit->setEchoMode(LineEdit::Password);
    mPwdEdit->setToolTip(tr("要求大于8位,且必须是大写字母,数字和特殊字符的组合!"));

    QFormLayout * flay = new QFormLayout;
    flay->addRow(tr("请输入用户名: "),mUserEdit);
    flay->addRow(tr("请输入密码: "),mPwdEdit);
    flay->addRow(tr("请再次输入密码: "),mVerifyPwdEdit);
    connect(mUserEdit,&LineEdit::editingFinished,this,&LoginNewUser::onUserEditFinished);
    connect(mPwdEdit,&LineEdit::editingFinished,this,&LoginNewUser::onPwdEditFinished);
    connect(mVerifyPwdEdit,&LineEdit::editingFinished,this,&LoginNewUser::onVerifyPwdEditFinished);
    connect(mUserEdit,&LineEdit::textChanged,this,[this]{userIsRight=false;}); // 一旦重新编辑就修改
    connect(mPwdEdit,&LineEdit::textChanged,this,[this]{pwdIsRight=false;});
    connect(mVerifyPwdEdit,&LineEdit::textChanged,this,[this]{pwdIsSame=false;});

    flay->labelForField(mUserEdit)->setFont(QFont(DefaultFontFamily,DefaultFontSize));
    flay->labelForField(mPwdEdit)->setFont(QFont(DefaultFontFamily,DefaultFontSize));
    flay->labelForField(mVerifyPwdEdit)->setFont(QFont(DefaultFontFamily,DefaultFontSize));

    mNewBtn = new PushButton(tr("新建"));
    connect(mNewBtn,&PushButton::clicked,this,&LoginNewUser::onNewBtn);
    QHBoxLayout * blay = new QHBoxLayout;
    blay->addStretch();
    blay->addWidget(mNewBtn);

    mLay = new QVBoxLayout;
    mLay->addLayout(flay);
    mLay->addLayout(blay);

    setLayout(mLay);
}

