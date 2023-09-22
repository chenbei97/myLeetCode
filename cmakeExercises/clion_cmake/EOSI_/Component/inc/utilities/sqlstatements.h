#ifndef SQLSTATEMENTS_H
#define SQLSTATEMENTS_H

#include "qdebug.h"
#include "qdatetime.h"
#include "../alias.h"
#define LOG (qDebug()<<"["<<QTime::currentTime().toString("h:mm:ss:zzz")<<__FUNCTION__<<"] ")
#define SqlExecFailedLOG (qDebug()<<"[" \
    <<QTime::currentTime().toString("h:mm:ss:zzz")<<__FUNCTION__<<"] sql exec failed! error is ")

#include "qsqlindex.h"
#include "qsqlrecord.h"
#include "qsqlerror.h"
#include "qsqlfield.h"
#include "qsqlquery.h"
#include "qsqldatabase.h"
//#include <QtSql/QSqlIndex>

class LoginSqlReadWrite;
class LoginSqliteReadWrite;
class LoginMysqlReadWrite;
class SqliteReadWrite;
class MySqlReadWrite;

enum class SQLType {Mysql,Sqlite};
Q_ENUMS(SQLType)

extern  SQLType CurrentSqlType; // 定义在sqlreadwrite.cpp
extern  LoginSqlReadWrite * LoginSqlReadWritePointer; // LoginSqliteReadWrite.cpp定义,登陆界面切换sql时更改

#define CurrentSqliteType (CurrentSqlType==SQLType::Sqlite)
// 登录窗口读写的指针
#define SqliteVerifyPointer (&LoginSqliteReadWrite::instance())
#define MysqlVerifyPointer (&LoginMysqlReadWrite::instance())
// 读写的指针
#define SqliteReadWritePointer (&SqliteReadWrite::instance())
#define MysqlReadWritePointer (&MySqlReadWrite::instance())
//#define SqlReadWritePointer (CurrentSqliteType?SqliteReadWritePointer:MysqlReadWritePointer)

// 驱动的相关设置
static const char* SqliteDriver = "sqlite";
static const char* SqlcipherDriver = "sqlcipher";
static const char* MysqlDriver = "mysql";
//#define UseSqlcipher true
static const char*  SqliteDataBasePassword = "cb199791";
static const char*  MysqlDataBaseConnections = "MYSQL_OPT_CONNECT_TIMEOUT=1;";
static const char*  SqliteDataBaseConnectionsFirst =
                            "QSQLITE_USE_CIPHER=sqlcipher; ""SQLCIPHER_LEGACY=1; "
                            "SQLCIPHER_LEGACY_PAGE_SIZE=4096;QSQLITE_CREATE_KEY";
static const char*  SqliteDataBaseConnectionsAgain =
                            "QSQLITE_USE_CIPHER=sqlcipher; ""SQLCIPHER_LEGACY=1; "
                            "SQLCIPHER_LEGACY_PAGE_SIZE=4096";

// （1）表信息，表架构等
// （1.1）数据源固定名称
static const char*  DataBaseName = "eosi";
// （1.2）表的名称
static const char * LoginInfoTableName = "logininfo";
static const char* ExperGeneralConfigTableName = "experconfig";
static const char* GroupPointTableName = "grouppoint";
// （1.3）每张表的所有字段，按照顺序存储
static const char * LoginInfoUserField = "user";
static const char * LoginInfoPwdField = "pwd";
static const char * LoginInfoPLoginField = "last_login";
static const char * LoginInfoDefaultUser = "admin";
static const char * LoginInfoDefaultPwd = "123456";

static const QFieldsList LoginInfoConfigFields = {
    "user","pwd","last_login"
};
static const QFieldsList ExperGeneralConfigFields = {
        "id", "datetime",
        "user","flag",
        "ana_type","ana_definition","ana_notes","ana_spec1","ana_spec2",
        "channel",
        "exper_celltype","exper_description","exper_name","exper_person","exper_type",
        "group_names",
        "objective",
        "count","duration","end_time","is_schedule","start_time","total",
        "view","wellsize"
};

struct ExperConfigTableField {
    const QString id = "id";
    const QString datetime = "datetime";
    const QString user = "user";
    const QString flag = "flag";
    const QString ana_type = "ana_type";
    const QString ana_definition = "ana_definition";
    const QString ana_notes = "ana_notes";
    const QString ana_spec1 = "ana_spec1";
    const QString ana_spec2 = "ana_spec2";
    const QString channel = "channel";
    const QString exper_celltype = "exper_celltype";
    const QString exper_description = "exper_description";
    const QString exper_name = "exper_name";
    const QString exper_person = "exper_person";
    const QString exper_type = "exper_type";
    const QString group_names = "group_names";
    const QString objective = "objective";
    const QString count = "count";
    const QString duration = "duration";
    const QString end_time = "end_time";
    const QString is_schedule = "is_schedule";
    const QString start_time = "start_time";
    const QString total = "total";
    const QString view = "view";
    const QString wellsize = "wellsize";
    struct OtherField {
        const QString experiment = "experiment"; // 4个json用的组字段
        const QString analysis = "analysis";
        const QString time = "time";
        const QString group = "group";
        const QString x = "x";
        const QString y = "y";
        const QString order = "order";
        const QString pname = "pname";
        const QString datetime_iso1 = "yyyy/MM/dd hh:mm:ss";
        const QString datetime_iso2 = "yyyy/MM/dd hh:mm"; // 用于start_time和end_time
        const QString datetime_num = "yyMMddhhmmss";
    };
    OtherField other_fields;
};

static const ExperConfigTableField ExperConfigTableFields;

#define ExperTableFlagColumn  (ExperGeneralConfigFields.indexOf("flag"))
#define ExperTableDateTimeColumn  (ExperGeneralConfigFields.indexOf("datetime"))
#define ExperTableChannelColumn  (ExperGeneralConfigFields.indexOf("channel"))
#define ExperTableObjectiveColumn  (ExperGeneralConfigFields.indexOf("objective"))
#define ExperTableChannelColumn  (ExperGeneralConfigFields.indexOf("channel"))
#define ExperTableWellSizeColumn  (ExperGeneralConfigFields.indexOf("wellsize"))
#define ExperTableExperTypeColumn  (ExperGeneralConfigFields.indexOf("exper_type"))
#define ExperTableViewColumn  (ExperGeneralConfigFields.indexOf("view"))
#define ExperTableTotalColumn  (ExperGeneralConfigFields.indexOf("total"))
#define ExperTableDurationColumn  (ExperGeneralConfigFields.indexOf("duration"))
#define ExperTableScheduleColumn  (ExperGeneralConfigFields.indexOf("is_schedule"))
#define ExperTableGroupColumn  (ExperGeneralConfigFields.indexOf("group_names"))

#define ExperTableCountColumn  (ExperGeneralConfigFields.indexOf("count"))
#define ExperTableStartTimeColumn  (ExperGeneralConfigFields.indexOf("start_time"))
#define ExperTableEndTimeColumn  (ExperGeneralConfigFields.indexOf("end_time"))

static const QFieldsList  GroupPointFields = {
    "id","user","flag",
    "group_name","point_pos","point_name"
};

static const char* QueryGroupPointAndName =
        "select point_pos,point_name from grouppoint "
        "where flag = '%1' and group_name = '%2' ";

struct GroupPointTableField {
    const QString id = "id";
    const QString user = "user";
    const QString flag = "flag";
    const QString group_name = "group_name";
    const QString point_pos = "point_pos";
    const QString point_name = "point_name";
};

static const GroupPointTableField GroupPointTableFields;

// （2）通用命令
static const char* SelectUserAndPwd = "select user,pwd from logininfo";
static const char* RollBack = "rollback";
static const char* FilterAdmin = "user = 'admin' ";
static const char* FilterUser = "user = '%1' "; // QSqlTableModel中filter函数使用
static const char* FilterFlag = "flag = '%1' "; // rollback函数使用
static const char* CreateTable = "create table if not exists %1(%2) ";
static const char* SelectXFromTable = "select * from %1 ";
static const char* SelectXFromTableWhere = "select * from %1 where %2 ";
static const char* SelectXFromTableWhereBinary = "select * from %1 where binary %2 "; // 大小写敏感mysql特有,sqlite本身就是大小写敏感无需设置
static const char* SelectTableRows = "select count(*) from %1 "; // 查询行数
static const char* SelectXFromTableOrderById = "select * from %1 order by id"; // id保证都i有
static const char* SelectFieldFromTable = "select %1 from %2";
static const char* SelectDoubleFieldsFromTable = "select %1,%2 from %3";
static const char* SelectFieldFromTableWhere = "select %1 from %2 where %3";
static const char* DropTable = "drop table %1";
static const char* FilterTable = "select * from %1 where %2 like '%%3%';";
static const char* FilterTableByTime = "select * from %1 where datetime between '%2' and '%3';"; // 注意时间必须是2023/01/02
static const char* CreateEmptyTableMySql = "create table if not exists %1( "
        "id integer primary key auto_increment not null unique, "
        "datetime datetime not null default '1899/12/30 00:00:00', "
        "user varchar(100) not null default '' );"; // 空表
static const char* CreateEmptyTableSqlite = "create table if not exists %1( "
        "id integer primary key autoincrement not null unique, "
        "datetime datetime not null default '1899/12/30 00:00:00', "
        "user varchar(100) not null default '' );"; // 空表
//insert into experconfig (channel,view,wellsize)
//values ('phase','2','96'),('red','4','24'),('green','8','384')
// 通用型,%3可以是多个()括起来的值,%2可以是ExperGeneralConfigFields每个表的每个字段逗号隔开
static const char* InsertRecord = "insert into %1 (%2) values %3";
static const char* RemoveRecord = "delete from %1 where %2";
static const char* UpdateRecord = "update %1 set %2 where %3";

// （3）数据库特有命令
// （3.1）查询指定表是否存在
static const char*  InformationSchema = "information_schema";// 仅限于mysql
static const char*  ShowDataBaseLike = "show database like '%1' ";// 仅限于mysql
static const char*  CreateDataBase = "create database %1";// 仅限于mysql
static const char*  ShowTablesLike = "show tables like '%1' "; // 仅限于mysql
static const char*  SelectTableExistedFromInformationSchema =
    "select table_name from information_schema.tables where table_schema= '%1' and table_name = '%2' ";// 仅限于mysql
static const char* SelectTableExistedFromSqliteMaster = "select name from sqlite_master where name = '%1' ";// 仅限于sqlite
// （3.2）查询表格列数
static const char* SelectTableColumnsFromInformationSchema =
        "select count(column_name) from information_schema.columns where  table_name = '%1' ";// 仅限于mysql
// （3.2）创建表
//  （3.2.1）登录信息表
static const char * CreateLoginInfoConfigTable =
        "create table if not exists logininfo ("
        "user varchar(100) not null default '', "
        "pwd varchar(100) not null default '',"
        "last_login datetime not null default '1899/12/30 00:00:00' ); ";

// （3.2.2）实验流程通用配置表 时间和ID一定存在
static const char * CreateExperGeneralConfigTableInit =
        "user varchar(100) not null default '', "
        "flag varchar(100) not null default '',"
        "ana_type varchar(100) not null default '', "
        "ana_definition varchar(100) not null default '', "
        "ana_notes varchar(5000) not null default '', "
        "ana_spec1 varchar(20) not null default '', "
        "ana_spec2 varchar(20) not null default '', "
        "channel varchar(100) not null default '', "
        "exper_celltype varchar(100) not null default '', "
        "exper_description varchar(5000) not null default '', "
        "exper_name varchar(100) not null default '', "
        "exper_person varchar(100) not null default '', "
        "exper_type varchar(100) not null default '', "
        "group_names varchar(100) not null default '', "
        "objective varchar(100) not null default '', "
        "count varchar(100) not null default '', "
        "duration varchar(100) not null default '', "
        "end_time varchar(100) not null default '', "
        "is_schedule varchar(100) not null default '', "
        "start_time varchar(100) not null default '', "
        "total varchar(100) not null default '', "
        "view varchar(20) not null default '', "
        "wellsize varchar(20) not null default '' ";

static const char * CreateGroupPointTableMysql =
        "create table if not exists grouppoint ("
        "id integer primary key auto_increment not null unique, "
        "user varchar(100) not null default '', "
        "flag varchar(100) not null default '',"
        "group_name varchar(100) not null default '', "
        "point_pos varchar(100) not null default '', "
        "point_name varchar(100) not null default '' ); ";

static const char * CreateGroupPointTableSqlite =
        "create table if not exists grouppoint ("
        "id integer primary key autoincrement not null unique, "
        "user varchar(100) not null default '', "
        "flag varchar(100) not null default '',"
        "group_name varchar(100) not null default '', "
        "point_pos varchar(100) not null default '', "
        "point_name varchar(100) not null default '' ); ";

static const char* CreateExperGeneralConfigTableMysql = "create table if not exists experconfig ( "
        "id integer primary key auto_increment not null unique, "
        "datetime datetime not null default '1899/12/30 00:00:00',"// now(),不支持.zzz
        "%1 );";
static const char* CreateExperGeneralConfigTableSqlite = "create table if not exists experconfig ( "
        "id integer primary key autoincrement not null unique, "
        "datetime datetime not null default '1899/12/30 00:00:00',"
        "%1 );";

// （3.3）数据源是否存在
static const char* ShowDataSourceLike = "show databases like %1";// 仅限于mysql
static const char* SelectDataSourceExistedFromInformationSchema=
        "select count(1) from information_schema.schemata where schema_name = '%1' ";// 仅限于mysql
// （3.4）创建数据源
static const char*  CreateDataSource = "create database if not exists %1 character set 'utf8mb4'";// 仅限于mysql
// （3.5）删除数据源
static const char*  DropDataSource = "drop database %1";// 仅限于mysql
// （3.6）列出数据源
static const char* CurrentDataSourceMysql = "select database() ";
static const char* CurrentDataSourceSqlite = "PRAGMA database_list";
// （3.7）主键重排序
static const char* PrimaryKeyReorderMysql =
        "alter table %1 drop id;"
        "alter table %1 add id integer not null first;"
        "alter table %1 modify column id integer not null auto_increment, add primary key(id);";
static const char* PrimaryKeyReorderSqlite =
        "update %1 set id=id-1 where id > %2;"; // 删除记录时要拿到删除的行,不过这个方法可能会执行错误
// （3.8）mysql的数据源路径
static const char* ShowDataDir =
    "show global variables like \"%datadir%\";"; // 会返回2列,1个是变量名称一个是值
static const char* SelectDataDir =
    "select @@datadir;"; // 直接返回路径，更快捷
// （3.9）mysql查询创建时间和上次更新时间
static const char*  UpdateTime =
        "select update_time from information_schema.tables where table_schema = '%1' and  table_name = '%2'; ";
static const char*  CreateTime =
        "select create_time from information_schema.tables where table_schema = '%1' and  table_name = '%2'; ";
#endif // SQLSTATEMENTS_H
