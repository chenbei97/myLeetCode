#include "../../inc/utilities/loginsqlitereadwrite.h"

//extern LoginSqlReadWrite * LoginSqlReadWritePointer = SqliteVerifyPointer;

LoginSqliteReadWrite::LoginSqliteReadWrite()
{

}

LoginSqliteReadWrite& LoginSqliteReadWrite::instance()
{
    static LoginSqliteReadWrite instance;
    return instance;
}

SQLType LoginSqliteReadWrite::type() const
{
    return SQLType::Sqlite;
}

bool LoginSqliteReadWrite::dbExisted(QCVariant param)
{ // createDataSource和haveDataSource是文本路径判断
        LOG<<"drivername = "<<SqliteReadWritePointer->database().driverName();
        auto dbname = param.toString();

#ifndef UseSqlcipher // 没有使用加密创建db文件使用纯文本文件创建
        SqliteReadWritePointer->createDataSource(dbname,mSqliteDir); // 创建.db3文件
        if (SqliteReadWritePointer->haveDataSource(dbname,mSqliteDir)) { // 创建后的检查
#endif
            SqliteReadWritePointer->open(dbname,mSqliteDir); // 打开,检查表
            auto user= encry_color(LoginInfoDefaultUser);
            auto pwd = encry_color(LoginInfoDefaultPwd);
            auto defaultRecord = QString("('%1','%2','%3')").arg(user).arg(pwd)
                    .arg(QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1));
            if (!SqliteReadWritePointer->haveTable(LoginInfoTableName)) {// 不存在创建表,并添加1条记录 admin,123456
                SqliteReadWritePointer->createTable(CreateLoginInfoConfigTable);
                SqliteReadWritePointer->addRecord(LoginInfoTableName,LoginInfoConfigFields,defaultRecord);
            }
            else { // 存在表,审查表字段是否正确,不正确删除表
                if (!SqliteReadWritePointer->fieldsRight(LoginInfoTableName,LoginInfoConfigFields)) {
                    SqliteReadWritePointer->dropTable(LoginInfoTableName); // 删除并重新创建表
                    SqliteReadWritePointer->createTable(CreateLoginInfoConfigTable);  //并添加1条记录 admin,123456
                    SqliteReadWritePointer->addRecord(LoginInfoTableName,LoginInfoConfigFields,defaultRecord);
                } else {// 表存在的且字段是正确的,审查是否有默认记录"('admin','123456')"
                    //if (!SqliteReadWritePointer->haveRecord(LoginInfoTableName,FilterAdmin)) // "user = 'admin' and pwd = '123456' " 可能用户修改管理员密码
                    if (!haveUser(LoginInfoDefaultUser))
                        SqliteReadWritePointer->addRecord(LoginInfoTableName,LoginInfoConfigFields,defaultRecord);
                }
            }

#ifndef UseSqlcipher
        } else { // 创建后还没有说明创建失败!
            return false;
        }
#endif
        // 最后统一检查数据源,表和记录
        bool r1 =  SqliteReadWritePointer->haveDataSource(dbname,mSqliteDir);
        bool r2 = SqliteReadWritePointer->haveTable(LoginInfoTableName);
        //bool r3 = SqliteReadWritePointer->haveRecord(LoginInfoTableName,FilterAdmin);
        bool r3 = haveUser(LoginInfoDefaultUser);
        LOG<<"have data source? "<<r1<<" have table? "<<r2<<" have record? "<<r3;
        return r1&&r2&&r3;
}

bool LoginSqliteReadWrite::userExisted(QCString user)
{ // 验证用户的时候更新
    auto encry_user = encryUser(user); // 找到加密形式
    if (!encry_user.isEmpty())
    SqliteReadWritePointer->updateRecord(LoginInfoTableName,LoginInfoPLoginField,
                                            QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1),
                                            QString(FilterUser).arg(encry_user));
    //return SqliteReadWritePointer->haveRecord(LoginInfoTableName,QString(FilterUser).arg(user));
    return haveUser(user);
}

bool LoginSqliteReadWrite::pwdExisted(QCString pwd)
{
#ifdef pwd
    return havePwd(mCurrentUser,pwd);
#else // 2种写法都可以
    auto encryuser = encryUser(mCurrentUser);
    SqliteReadWritePointer->updateRecord(LoginInfoTableName,LoginInfoPLoginField,
                                            QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1),
                                            QString(FilterUser).arg(encryuser));
    bool r = SqliteReadWritePointer->haveRecord(LoginInfoTableName,LoginInfoPwdField,
                                                QString(FilterUser).arg(encryuser));
    if (r) {
        auto query = SqliteReadWritePointer->lastQuery();
        if (decry_color(query.value(LoginInfoPwdField).toString()) == pwd)
            // pwd是非加密形式,解密结果来比较,不要加密结果来比较,因为是随机的
            return true;
    }
    return false;

#endif
}

bool LoginSqliteReadWrite::openDB(QCVariant param)
{
    SqliteReadWritePointer->open(param.toString());
    if (!SqliteReadWritePointer->isOpen()) {
        QMessageBox::critical(nullptr,QObject::tr("错误"),SqliteReadWritePointer->dbError(),QMessageBox::Ok);
        return false;// sqlite打开机制不会失败,这里只是统一写法和mysql一致
    }
    return true;
}

bool LoginSqliteReadWrite::userCreated(QCString user, QCString pwd)
{// 创建用户就是增加一条记录
    auto encrtuser = encry_color(user);
    auto encrypwd = encry_color(pwd);// 加密
    return SqliteReadWritePointer->addRecord(LoginInfoTableName,LoginInfoConfigFields,
                                 QValueVector()<<encrtuser<<encrypwd<<QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1));
}

bool LoginSqliteReadWrite::pwdUpdated(QCString user, QCString pwd)
{
    // 调用 update logininfo set pwd = 'pwd'  where user = 'user'
    // UpdateRecord = "update %1 set %2 where %3";
    auto encry_user = encryUser(user);
    SqliteReadWritePointer->updateRecord(LoginInfoTableName,LoginInfoPLoginField,
                                            QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1),
                                            QString(FilterUser).arg(encry_user)); // 更新登陆时间
    auto encrypwd = encry_color(pwd);
    return  SqliteReadWritePointer->updateRecord(LoginInfoTableName,LoginInfoPwdField,encrypwd,
                                                 QString(FilterUser).arg(encry_user)); // 更新登录密码
}

bool LoginSqliteReadWrite::havePwd(QCString user,QCString pwd)
{ // 先找到user的加密形式,再根据这个user查找pwd
        auto encryuser = encryUser(user);
        auto statement = QString(SelectFieldFromTableWhere).arg(LoginInfoPwdField).arg(LoginInfoTableName)
                .arg(QString(FilterUser).arg(encryuser)); // 条件查找用户等于encryuser的密码

        if (SqliteReadWritePointer->query(statement)) // 查询成功
        {
            auto query = SqliteReadWritePointer->lastQuery();
            query.first(); //因为user是唯一的,只会查询到0或1条
            auto encrypwd = query.value(LoginInfoPwdField).toString();

            if (decry_color(encrypwd) == pwd) {// pwd是非加密形式,解密结果来比较,不要加密结果来比较,因为是随机的
                 LOG<<pwd<<"'s encry is "<<encrypwd;
                return true;
            }
        }
        LOG<<"dont have pwd = "<<pwd <<" when user = "<<user;
        return false;
}

bool LoginSqliteReadWrite::haveUser(QCString user)
{ //  检查是否有这个用户就可以,不需要同时匹配用户和密码,密码可以修改过
    auto statement = QString(SelectFieldFromTable).arg(LoginInfoUserField).arg(LoginInfoTableName);
    if (SqliteReadWritePointer->query(statement)) // 查询成功
    {
        auto query = SqliteReadWritePointer->lastQuery();
        while (query.next()) {
            auto encryuser = query.value(0).toString();
            if (decry_color(encryuser) == user) {
                LOG<<user<<"'s encry is "<<encryuser;
                return true;
            }
        }
    }
    LOG<<"dont have user "<<user;
    return false;
}

QString LoginSqliteReadWrite::encryUser(QCString user)
{ // 查询指定用户在数据库的加密字符串形式
    auto statement = QString(SelectFieldFromTable).arg(LoginInfoUserField).arg(LoginInfoTableName);
    if (SqliteReadWritePointer->query(statement)) // 查询成功
    {
        auto query = SqliteReadWritePointer->lastQuery();
        while (query.next()) {
            auto encryuser = query.value(0).toString();
            if (decry_color(encryuser) == user) {
                LOG<<user<<"'user encry is "<<encryuser;
                return encryuser; // 如果匹配到了返回这个记录
            }
        }
    }
    LOG<<"dont have user "<<user;
    return  "";
}


