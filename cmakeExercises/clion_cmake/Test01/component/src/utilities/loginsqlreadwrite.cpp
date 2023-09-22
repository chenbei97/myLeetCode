#include "../../inc/utilities/loginsqlreadwrite.h"

LoginSqlReadWrite::LoginSqlReadWrite(QObject*parent):QObject(parent)
{

}

// 打开数据库
bool LoginSqlReadWrite::open(QCVariant param)
{
    return openDB(param);
}

//验证数据库
bool LoginSqlReadWrite::validateDB(QCVariant param)
{ // 验证数据库时会确保存在数据源,表和打开数据库
    emit validateDBStarted();
    if (!open(param)) {
        emit validateDBFinished();
        return false;
    } // messagebox在open->openDB里调用
    bool r = dbExisted(param);
    emit validateDBFinished();
    return r;
}

// 验证用户
bool  LoginSqlReadWrite::validateUser(QCString user)
{// 进入本函数之前已经验证过目录,可以保证数据源,表都存在且正确,数据库已处于打开状态
    mCurrentUser.clear();
    if (!userExisted(user)) {
        return false;
    }
    mCurrentUser = user;  // 给验证密码时用的
    return true;
}

// 验证密码
bool LoginSqlReadWrite::validatePwd(QCString pwd)
{ // 和验证用户同理
    mCurrentPwd.clear();
    mCurrentPwd = pwd;
    LOG<<"current user is "<<mCurrentUser<<" the queryed pwd is "<<pwd;
    if (!pwdExisted(pwd)) {
        return false;
    }
    return true;
}

// 新建用户
bool LoginSqlReadWrite::createUser(QCString user, QCString pwd)
{
    if (userExisted(user)) {
        QMessageBox::warning(nullptr,QObject::tr("警告"),QObject::tr("用户已经存在!"));
        return true;
    }

    if (!userCreated(user,pwd)) {
        QMessageBox::critical(nullptr,QObject::tr("错误"),QObject::tr("创建用户失败!"));
        return false;
    }
    return  true;
}

// 更改密码使用
bool LoginSqlReadWrite::updatePwd(QCString user,QCString pwd) {
    if (!userExisted(user)) {
        QMessageBox::critical(nullptr,QObject::tr("错误"),QObject::tr("用户不存在无法修改!"));
        return true;
    }
    if (!pwdUpdated(user,pwd)) {
        QMessageBox::critical(nullptr,QObject::tr("错误"),QObject::tr("更改密码失败!"));
        return false;
    }
    return  true;
}

