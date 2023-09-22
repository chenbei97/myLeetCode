#include "../../inc/utilities/sqlitereadwrite.h"

SqliteReadWrite::SqliteReadWrite(QObject*parent):SqlReadWrite(parent)
{
    mType = SQLType::Sqlite;
#ifdef UseSqlcipher
    mDB = QSqlDatabase::addDatabase("SQLITECIPHER", SqlcipherDriver);
#else
    mDB = QSqlDatabase::addDatabase("QSQLITE",SqliteDriver);
#endif
    mQuery = QSqlQuery(mDB);
    mStandardPath = QStandardPaths::standardLocations(QStandardPaths::DataLocation).at(0);
    auto dir = QDir();
    if (!dir.exists(mStandardPath)) QDir().mkpath(mStandardPath); // 创建项目名称的文件夹路径 作为标准路径
}

SqliteReadWrite& SqliteReadWrite::instance()
{
        static SqliteReadWrite instance;
        return instance;
}

SqliteReadWrite::~SqliteReadWrite()
{
#ifdef UseSqlcipher
    QSqlDatabase::removeDatabase(SqlcipherDriver);
#else
    QSqlDatabase::removeDatabase(SqliteDriver);
#endif
}

bool SqliteReadWrite::open(QCString db,QCString path)
{ // db必须带后缀,path不指定时使用标准路径,相比mysql不要检查重复打开的问题
    // sqlite的open机制就是安全的打开文件,即使打开过重复打开不会出问题
    QString fullPath;

    if (!path.isEmpty()) { // 传递了指定路径
        if (!pathExisted(path)) { // 传递的路径不存在
            LOG<<path<<" is not exists!";
            return false;
        } // 传递的路径存在.拼接为全路径
        fullPath = path +"/"+db;
        LOG<<path<<" is exists!";
    } else { // 使用标准路径
        fullPath = mStandardPath+"/"+db;
    }

    mDB.setDatabaseName(fullPath);
    mDB.setPassword(SqliteDataBasePassword);
    mDB.setConnectOptions(SqliteDataBaseConnectionsFirst);

    mDB.open(); // 首次创建文件不会打开失败,已存在会打开失败重新设置选项再打开就行
    if (!isOpen()) {
        LOG<<"sqlite not open! error is "<<dbError();
        mDB.setConnectOptions(SqliteDataBaseConnectionsAgain);
        mDB.open();
        if (!isOpen())  {
            LOG<<"sqlite open failed again! error is "<<dbError(); // 一般不会发生
            return false;
        }
    }
    LOG<<"sqlite is init and open! path is "<<mDB.databaseName();
    return true;
}

bool SqliteReadWrite::haveDataSource(QCString source,QCString path)
{ // 相对于mysql没有相关命令,只能是文件操作: 检查是否有这个文件
    if (!source.endsWith(".db3")) return false;

    auto dir = QDir();
    QString fullpath;

    if (!path.isEmpty())  // 传递了指定路径
        fullpath = path+"/"+source;
    else  // 检查标准路径
        fullpath = mStandardPath+"/"+source;

    if (!dir.exists(fullpath)) { // 完整路径不存在
        LOG<<fullpath<<" data source is not exists!";
        return false;
    }
    LOG<<fullpath<<" data source is exists!";
    return true;
}

bool SqliteReadWrite::createDataSource(QCString source,QCString path)
{ // 相对于mysql没有相关命令,只能是文件操作: 创建这个文件
    if (!source.endsWith(".db3")) return false;
    if (haveDataSource(source,path)) {
        LOG<<"data source is already exist!";
        return true;
    }
    QString fullpath;
    auto dir = QDir();
    if (path.isEmpty()) // 标准路径下创建数据源
        fullpath = mStandardPath+"/"+source;
    else {
        if (!dir.exists(path)) {// 指定路径不存在不能创建
            LOG<<path<<" is not exist! create data source failed!";
            return false;
        }
        fullpath = path + "/" + source;
    }
    QFile file(fullpath);
    file.open(QIODevice::ReadWrite);// 利用open创建文件,必须s 读写模式才能不存在创建
    file.close();
    LOG<<"create data source successful!";
    return true;
}

bool SqliteReadWrite::dropDataSource(QCString source,QCString path)
{ // 相对于mysql没有相关命令,只能是文件操作: 删除这个文件
    QString fullpath;
    auto dir = QDir();

    if (path.isEmpty()) // 标准路径下创建数据源
        fullpath = mStandardPath+"/"+source;
    else
        fullpath = path + "/" + source;

    bool ok = QFile::remove(fullpath); // 路径不存在时不能删除
    if (ok)
        LOG<<"remove data source successful!";
    else LOG<<"remove data source failed!"; // 失败可能发生在文件占用时不能删除
    return ok;
}

QDateTime SqliteReadWrite::lastVisitTime(QCString table)
{
    Q_UNUSED(table);// sqlite没有特定表路径
    QFileInfo info(mDB.databaseName());
    return info.lastRead();
}

QDateTime SqliteReadWrite::lastUpdateTime(QCString table)
{
    Q_UNUSED(table);// sqlite没有特定表路径
    QFileInfo info(mDB.databaseName());
    return info.lastModified();
}

QDateTime SqliteReadWrite::createTime(QCString table)
{
    Q_UNUSED(table);// sqlite没有特定表路径
    QFileInfo info(mDB.databaseName());
    return info.birthTime();
}
