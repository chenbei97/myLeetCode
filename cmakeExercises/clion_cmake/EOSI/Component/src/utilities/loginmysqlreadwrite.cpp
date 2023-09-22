#include "../../inc/utilities/loginmysqlreadwrite.h"

LoginMysqlReadWrite::LoginMysqlReadWrite()
{
}

LoginMysqlReadWrite& LoginMysqlReadWrite::instance()
{
    static LoginMysqlReadWrite instance;
    return instance;
}

 SQLType LoginMysqlReadWrite::type() const
{
     return SQLType::Mysql;
}

bool LoginMysqlReadWrite::dbExisted(QCVariant param)
{ // 验证DB时如果不存在表或者不存在默认记录添加
    LOG<<"drivername = "<<MysqlReadWritePointer->database().driverName();
    auto pwd = encry_color(LoginInfoDefaultPwd);
    auto user = encry_color(LoginInfoDefaultUser);
    auto defaultRecord = QString("('%1','%2','%3')").arg(user).arg(pwd)
            .arg(QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1));
    if (!MysqlReadWritePointer->haveTable(LoginInfoTableName)) {//检查表,不存在创建表
        MysqlReadWritePointer->createTable(CreateLoginInfoConfigTable);
        MysqlReadWritePointer->addRecord(LoginInfoTableName,LoginInfoConfigFields,defaultRecord);
    }
    else { // 存在表,审查表字段是否正确,不正确删除表
        if (!MysqlReadWritePointer->fieldsRight(LoginInfoTableName,LoginInfoConfigFields)) {
            MysqlReadWritePointer->dropTable(LoginInfoTableName); // 删除并重新创建
            MysqlReadWritePointer->createTable(CreateLoginInfoConfigTable);
            MysqlReadWritePointer->addRecord(LoginInfoTableName,LoginInfoConfigFields,defaultRecord);
        } else { // 表存在的且字段是正确的,审查是否有默认记录"('admin','123456')"
            // 1. 非加密写法
            //if (!MysqlReadWritePointer->haveRecordCaseSensitive(LoginInfoTableName,FilterAdmin)) // "user = 'admin' and pwd = '123456' ",k可能用户会修改管理员密码
            // 2. 加密写法
            if (!haveUser(LoginInfoDefaultUser)) // 改用本函数来检测是否有默认记录
                    MysqlReadWritePointer->addRecord(LoginInfoTableName,LoginInfoConfigFields,defaultRecord);
        }
    }
    // 最后统一检查数据源,表和记录
    auto dbname = param.value<DBConfig>().dbname;
    bool r1 = MysqlReadWritePointer->haveDataSource(dbname); // 不要用DataBaseName,用户可能指定自己的名称
    bool r2 = MysqlReadWritePointer->haveTable(LoginInfoTableName);
    //bool r3 = MysqlReadWritePointer->haveRecordCaseSensitive(LoginInfoTableName,FilterAdmin);
    bool r3 = haveUser(LoginInfoDefaultUser);
    LOG<<"match data source? "<<r1<<" match table? "<<r2<<" match record? "<<r3;
    return r1&&r2&&r3;
}

bool LoginMysqlReadWrite::userExisted(QCString user)
{// 不能直接根据user检索然后更新last_login,应该找到user在数据库内的形式
    auto encry_user = encryUser(user); // 找到加密形式
    if (!encry_user.isEmpty())
    MysqlReadWritePointer->updateRecord(LoginInfoTableName,LoginInfoPLoginField,
                                            QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1),
                                            QString(FilterUser).arg(encry_user));// 验证用户的时候更新登陆时间
    return haveUser(user);
}

bool LoginMysqlReadWrite::pwdExisted(QCString pwd)
{ // 更新记录要根据加密形式的user去更新
    auto encryuser = encryUser(mCurrentUser);
    MysqlReadWritePointer->updateRecord(LoginInfoTableName,LoginInfoPLoginField,
                                            QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1),
                                            QString(FilterUser).arg(encryuser));
    return havePwd(mCurrentUser,pwd);
}

bool LoginMysqlReadWrite::openDB(QCVariant param)
{// 必须先连接才能执行以下操作,和sqlite不一样
    auto params = param.value<DBConfig>(); // LoginVerifyDB窗口传入的参数是DBConfig
    MysqlReadWritePointer->open(params.dbname,params.username,params.password,params.ip,params.port.toInt());
    if (!MysqlReadWritePointer->isOpen()) { // 第一次没打开数据源成功,给用户自动创建1个,登录一定有的数据库
        MysqlReadWritePointer->open(InformationSchema,params.username,params.password,params.ip,params.port.toInt());
        MysqlReadWritePointer->query(QString(ShowDataBaseLike).arg(params.dbname));
        auto query = MysqlReadWritePointer->lastQuery();
        query.first();
        if (!query.isValid() || query.value(0).toString() != params.dbname) {// 确实没有这个数据源
            LOG<<DataBaseName<<" is not exists, create it!";
            MysqlReadWritePointer->query(QString(CreateDataBase).arg(params.dbname)); // 创建
            //MysqlReadWritePointer->query(QString("use %1").arg(params.dbname)); // 这个切换貌似不起作用
            MysqlReadWritePointer->close();
            MysqlReadWritePointer->open(params.dbname,params.username,params.password,params.ip,params.port.toInt()); // 重新打开
        } else LOG<<DataBaseName<<" data source is already exists!";
        if (!MysqlReadWritePointer->isOpen())  {// 此时检查,如果还没打开(不可能发生一般)
            QMessageBox::critical(nullptr,QObject::tr("错误"),MysqlReadWritePointer->dbError(),QMessageBox::Ok);
            return false;
        }
    }
    LOG<<"mysql pointer is open? "<<MysqlReadWritePointer->isOpen();
    return  true;
}

bool LoginMysqlReadWrite::userCreated(QCString user, QCString pwd)
{ // 创建用户就是增加一条记录
    auto encrypwd = encry_color(pwd);
    auto encryuser = encry_color(user);
    return MysqlReadWritePointer->addRecord(LoginInfoTableName,LoginInfoConfigFields,
         QValueVector()<<encryuser<<encrypwd<<QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1));
}

bool LoginMysqlReadWrite::pwdUpdated(QCString user, QCString pwd)
{ // 调用 update logininfo set pwd = 'pwd'  where user = 'user' UpdateRecord = "update %1 set %2 where %3";
    // 注意user要依据加密形式,pwd更新要先加密
    auto encry_user = encryUser(user);
    MysqlReadWritePointer->updateRecord(LoginInfoTableName,LoginInfoPLoginField,
                                        QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1),
                                        QString(FilterUser).arg(encry_user));// 更新登录时间
    auto encry_pwd = encry_color(pwd);
    return  MysqlReadWritePointer->updateRecord(LoginInfoTableName,LoginInfoPwdField,encry_pwd,
                                                QString(FilterUser).arg(encry_user));// 更新登录密码
}

bool LoginMysqlReadWrite::havePwd(QCString user,QCString pwd)
{ // 先找到user的加密形式,再根据这个user查找pwd
        auto encryuser = encryUser(user);
        auto statement = QString(SelectFieldFromTableWhere).arg(LoginInfoPwdField).arg(LoginInfoTableName)
                .arg(QString(FilterUser).arg(encryuser)); // 条件查找用户等于encryuser的密码

        if (MysqlReadWritePointer->query(statement)) // 查询成功
        {
            auto query = MysqlReadWritePointer->lastQuery();
            query.first(); //因为user是唯一的,只会查询到0或1条
            auto encrypwd = query.value(LoginInfoPwdField).toString();

            if (decry_color(encrypwd) == pwd)// pwd是非加密形式,解密结果来比较,不要加密结果来比较,因为是随机的
            {
                LOG<<pwd<<"'s encry is "<<encrypwd;
                return true;
            }
        }
        LOG<<"dont have pwd = "<<pwd <<" when user = "<<user;
        return false;
}

bool LoginMysqlReadWrite::haveUser(QCString user)
{ //  检查是否有这个用户就可以,不需要同时匹配用户和密码,密码可以修改过
    auto statement = QString(SelectFieldFromTable).arg(LoginInfoUserField).arg(LoginInfoTableName);
    if (MysqlReadWritePointer->query(statement)) // 查询成功
    {
        auto query = MysqlReadWritePointer->lastQuery();
        while (query.next()) {
            auto encryuser = query.value(0).toString();
            if (decry_color(encryuser) == user) {
                LOG<<user<<"'user encry is "<<encryuser;
                 return true;
            }
        }
    }
    LOG<<"dont have user "<<user;
    return false;
}

QString LoginMysqlReadWrite::encryUser(QCString user)
{ // 查询指定用户在数据库的加密字符串形式
    auto statement = QString(SelectFieldFromTable).arg(LoginInfoUserField).arg(LoginInfoTableName);
    if (MysqlReadWritePointer->query(statement)) // 查询成功
    {
        auto query = MysqlReadWritePointer->lastQuery();
        while (query.next()) {
            auto encryuser = query.value(0).toString();
            if (decry_color(encryuser) == user) {
                LOG<<user<<"'s encry is "<<encryuser;
                return encryuser; // 如果匹配到了返回这个记录
            }
        }
    }
    LOG<<"dont have user "<<user;
    return  "";
}




















