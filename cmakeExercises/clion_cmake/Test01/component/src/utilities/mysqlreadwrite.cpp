#include "../../inc/utilities/mysqlreadwrite.h"

MySqlReadWrite::MySqlReadWrite(QObject*parent):SqlReadWrite(parent)
{
    mType = SQLType::Mysql;
    mDB = QSqlDatabase::addDatabase("QMYSQL",MysqlDriver);
    mDB.setConnectOptions(MysqlDataBaseConnections);
    mQuery = QSqlQuery(mDB);
}

MySqlReadWrite::~MySqlReadWrite()
{
    QSqlDatabase::removeDatabase(MysqlDriver);
}

MySqlReadWrite& MySqlReadWrite::instance()
{
        static MySqlReadWrite instance;
        return instance;
}

MySqlLoginError MySqlReadWrite::open(QCString db, QCString user, QCString pwd,QCString ip, int port)
{ // open就完成了检查数据源的功能,如果是DataSourceUnFinded
    if (isValid() && isOpen()) {
        LOG<<"mysql is valid and open!";
        return MySqlLoginError::NoError;
    }
    mDB.setDatabaseName(db);
    mDB.setUserName(user);
    mDB.setPassword(pwd);
    mDB.setHostName(ip);
    mDB.setPort(port);
    mDB.open();

    if (!isOpen()) {
        auto error = dbError();
        LOG<<"mysql not open! error is "<<error;
        if (error.contains("Unknown database"))
            return MySqlLoginError::DataSourceUnFinded;
        if (error.contains("Access denied for user"))
            return MySqlLoginError::UserOrPwdError;
        if (error.contains("Can't connect to MySQL server on"))
            return MySqlLoginError::IPOrPortError;
    }
    LOG<<"mysql is init and open!";
    return MySqlLoginError::NoError;
}

bool MySqlReadWrite::haveRecordCaseSensitive(QCString table,QCString condition)
{ // 大小写敏感 select * from %1 where binary %2
    // 本函数不适用于user已经加密后的查找,因为condition是根据user来查找,但是加密是随机的,不能在这里做匹配查找
    auto statement = QString(SelectXFromTableWhereBinary).arg(table).arg(condition);
    mQuery.exec(statement);
    if (!mQuery.isActive()) {
        SqlExecFailedLOG<<lastError();
    } else {
        mQuery.first();
        if (mQuery.isValid()) { // 记录有效就说明找到了
            LOG<<"have record where "<<condition;
            return true;
        }
    }
    LOG<<"don't have record where "<<condition;
    return false;
}

bool MySqlReadWrite::haveDataSource(QCString source)
{ // QSqlQueryModel和QSqlQuery都是已经连接数据源执行的查询
    // 需要尚未连接去查询数据源是否存在，没有找到合适的方法只能借助open反馈的错误
    // 例如: mysql not open! error is  "Unknown database 'eosi' QMYSQL: Unable to connect"
    auto statements = QString(SelectDataSourceExistedFromInformationSchema).arg(source);
    //QSqlQueryModel model;
    //model.setQuery(statements);
    mQuery.exec(statements);
    if (mQuery.isActive()) {
         mQuery.first();
         if (mQuery.isValid() && mQuery.record().count() == 1) {
             if (mQuery.value(0).toInt()  == 1) { // 查询结果有效数量为1且值为1
                 LOG<<"datasource is exist! source is "<<source;
                 return true;
             }
         }
    } else {
        SqlExecFailedLOG<<lastError();
    }
    LOG<<"datasource is not exist! source is "<<source;
    return false;
}

bool MySqlReadWrite::createDataSource(QCString source)
{ // 必须连接上mysql才能使用本函数
    if (haveDataSource(source)) return true;
    auto statements = QString(CreateDataSource).arg(source);
    mQuery.exec(statements);
    if (mQuery.isActive()) {
        LOG<<"create datasource successful! source is "<<source;
        return true;
    }else {
        SqlExecFailedLOG<<lastError();
    }
    LOG<<"create datasource failed! source is "<<source;
    return false;
}

bool MySqlReadWrite::dropDataSource(QCString source)
{
    auto statements = QString(DropDataSource).arg(source);
    mQuery.exec(statements);
    if (mQuery.isActive()) {
        LOG<<"drop datasource successful! source is "<<source;
        return true;
    }else {
        SqlExecFailedLOG<<lastError();
        // "Can't drop database 'eosi'; database doesn't exist QMYSQL: Unable to execute query"
    }
    LOG<<"drop datasource failed! source is "<<source;
    return false;
}

int MySqlReadWrite::tableColumns(QCString table)
{ // 对于mysql可以用自己的方法查询
    auto statements = QString(SelectTableColumnsFromInformationSchema).arg(table);
    mQuery.exec(statements);
    mQuery.first();
    auto cols = mQuery.value(0).toInt();
    return cols;
}

bool MySqlReadWrite::primaryKeyReorder(QCString table)
{
   return query(QString(PrimaryKeyReorderMysql).arg(table));
}

QString  MySqlReadWrite::globaldir()
{ // 全局存储目录
    mQuery.exec(SelectDataDir);
    mQuery.first();
    auto dir = mQuery.value(0).toString();
    return dir;
}

QString MySqlReadWrite::datadir()
{ // 数据源存储的目录 C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Data\\eosi
    auto dir = globaldir();
    return dir+mDB.databaseName();
}

QStringList MySqlReadWrite::tablePaths()
{    // "C:\\ProgramData\\MySQL\\MySQL Server 8.0\\Data\\eosi\\experconfig.ibd"
    QStringList paths;
    auto dir = datadir();
    foreach(auto table, mDB.tables()) {
        QString path = dir + "\\"+table+".ibd"; // 会有ibd文件
        paths.append(path);
    }
    //LOG<<"tablePaths = "<<paths;
    return paths;
}

QDateTime MySqlReadWrite::lastVisitTime(QCString table)
{ // 上次访问时间mysql没有相应代码查询,用info的方法
    QString path;
    foreach(auto p,tablePaths())
        if (p.contains(table))
            path = p; // 最后1个路径,一般只会1个,不会重名或者有重复
    if (path.isEmpty()) return QDateTime();

    QFileInfo info(path);
    return info.lastRead();
}

QDateTime MySqlReadWrite::lastUpdateTime(QCString table)
{
    auto statement = QString(UpdateTime).arg(dbName()).arg(table);
    mQuery.exec(statement);
    mQuery.first();
    if (mQuery.isValid()) {
        auto datetime = mQuery.value(0).toString();
        return QDateTime::fromString(datetime,Qt::ISODate);
    }
    return QDateTime();
}

QDateTime MySqlReadWrite::createTime(QCString table)
{
    auto statement = QString(CreateTime).arg(dbName()).arg(table);
    mQuery.exec(statement);
    mQuery.first();
    if (mQuery.isValid()) {
        auto datetime = mQuery.value(0).toString();
        return QDateTime::fromString(datetime,Qt::ISODate);
    }
    return QDateTime();
}
