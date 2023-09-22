#ifndef SCANDATASAVE_H
#define SCANDATASAVE_H

#include "utilities/sqlitereadwrite.h"
#include "utilities/mysqlreadwrite.h"
#include "utilities/encry.h"
#include "tcp/tcpquery.h"
#include "tcp/tcpassemblercontroller.h"
#include "scanjsonreadwrite.h"

static SqlReadWrite* currentSqlReadWritePointer()
{
    static SqlReadWrite * w = nullptr;
    if (CurrentSqliteType)
        w = SqliteReadWritePointer;
    else w = MysqlReadWritePointer;
    return w;
}

// 保存到json
static bool saveExperConfigToJson(QCString filename,const QJsonObject& object,QWidget*parent = nullptr)
{
    QString name = filename;
    if (!name.endsWith(".json")) name+=".json";

    auto path = getAppDataStandardPath(name);

    if (pathExisted(path))
    {
        int ok = QMessageBox::warning(parent,QObject::tr("警告"),QObject::tr("已存在名称为'%1'的配置,是否覆盖?\n路径: %2").arg(name).arg(path)
                                      ,QMessageBox::Yes|QMessageBox::No);
        if (ok == QMessageBox::No)
            return false;
    }

    // 不存在有义务创建标准路径
   CheckAndCreateStandardPath;

    ScanJsonReadWrite m;
    m.writeJson(path,object);

    return true;
}

static bool rollback(QCString flag)
{
    auto sql = currentSqlReadWritePointer();
    return sql->rollback(flag);
}

// 保存到数据库,分2张表
static bool saveExperConfigToSql(QCValueVector values)
{
    auto sql = currentSqlReadWritePointer();
    auto fields = ExperGeneralConfigFields;
    fields.pop_front(); // 添加新纪录时id不需要指定
    auto rows = sql->tableRows(ExperGeneralConfigTableName);

    if (!sql->haveTable(ExperGeneralConfigTableName)) {// 不存在就创建表
        if (sql->type() == SQLType::Mysql)
            sql->createTable(CreateExperGeneralConfigTableMysql,CreateExperGeneralConfigTableInit);
        else sql->createTable(CreateExperGeneralConfigTableSqlite,CreateExperGeneralConfigTableInit);
    } else {// 存在表
        if (!sql->fieldsRight(ExperGeneralConfigTableName,ExperGeneralConfigFields)) {// 不正确，删除重新创建
            sql->dropTable(ExperGeneralConfigTableName); // 删除并重新创建
            if (sql->type() == SQLType::Mysql)
                sql->createTable(CreateExperGeneralConfigTableMysql,CreateExperGeneralConfigTableInit);
            else sql->createTable(CreateExperGeneralConfigTableSqlite,CreateExperGeneralConfigTableInit);
        }
    }
     sql->addRecord(ExperGeneralConfigTableName,fields,values); // 添加新的记录
     if (sql->type() == SQLType::Mysql)
        MysqlReadWritePointer->primaryKeyReorder(ExperGeneralConfigTableName); // 主键重排

     if (sql->tableRows(ExperGeneralConfigTableName) == rows+1 ) // 确实新增1条记录
         return true;

     return false;
}

static bool saveGroupPointConfigToSql(QCValuemap groupvalues)
{
    auto sql = currentSqlReadWritePointer();
    auto fields =  GroupPointFields;
    fields.pop_front(); // 添加新纪录时id不需要指定
    auto rows = sql->tableRows(GroupPointTableName);

    if (!sql->haveTable(GroupPointTableName)) {// 不存在就创建表
        if (sql->type() == SQLType::Mysql)
            sql->createTable(CreateGroupPointTableMysql);
        else sql->createTable(CreateGroupPointTableSqlite);
    } else {// 存在表
        if (!sql->fieldsRight(GroupPointTableName,GroupPointFields)) {// 不正确，删除重新创建
            sql->dropTable(GroupPointTableName); // 删除并重新创建
            if (sql->type() == SQLType::Mysql)
                sql->createTable(CreateGroupPointTableMysql);
            else sql->createTable(CreateGroupPointTableSqlite);
        }
    }
     sql->addRecord(GroupPointTableName,fields,groupvalues); // 添加新的记录
     if (sql->type() == SQLType::Mysql)
        MysqlReadWritePointer->primaryKeyReorder(GroupPointTableName); // 主键重排

   if (sql->tableRows(GroupPointTableName) == rows+groupvalues.count()) // 组点表会插入多条记录,即总组数
       return true;

    return  false;
}

// 发送给下位机的信息
static bool sendExperConfigToSocket(const QVariantMap&m)
{
    TcpQuery query;
    TcpAssemblerController assembler;

    assembler.assemble(TcpFramePool.frame0x0000,m);
    auto msg = assembler.message();
    query.exec(TcpFramePool.frame0x0000,msg);
    LOG<<"tcp error = "<<query.errorString();
    return !query.haveError();
}
#endif // SCANDATASAVE_H
