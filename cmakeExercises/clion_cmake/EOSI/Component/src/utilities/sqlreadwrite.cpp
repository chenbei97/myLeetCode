#include "../../inc/utilities/sqlreadwrite.h"

SqlReadWrite::SqlReadWrite(QObject *parent) : QObject(parent)
{
}

void SqlReadWrite::setType(SQLType type)
{ // 如果不使用子类,需要设置类型,这样可以使用haveTable,createEmptyTable等函数
    mType = type;
}

SQLType SqlReadWrite::type() const
{
    return mType;
}

void SqlReadWrite::close()
{
    mDB.close();
}

bool SqlReadWrite::isValid() const
{
    return mDB.isValid();
}

bool SqlReadWrite::isOpen() const
{
    return mDB.isOpen();
}

QString SqlReadWrite::dbName() const
{
    return mDB.databaseName();
}

QString SqlReadWrite::ip() const
{
    return mDB.hostName();
}

QString SqlReadWrite::username() const
{
    return mDB.userName();
}

QString SqlReadWrite::password() const
{
    return mDB.password();
}

int SqlReadWrite::port() const
{
    return mDB.port();
}

bool SqlReadWrite::dropTable(QCString table)
{
    if (!haveTable(table)) {
        LOG<<table<<" table is not existed, can't drop!";
        return true;
    }
    auto statement = QString(DropTable).arg(table);
    mQuery.exec(statement);
    if (mQuery.isActive()) {
        LOG<<"drop table "<<table<<" successful!";
        return true;
    } else {
        SqlExecFailedLOG<<lastError();
    }
    LOG<<"drop table "<<table<<" failed!";
    return false;
}

bool SqlReadWrite::haveTable(QCString table)
{
    QString statement;
    if (mType==SQLType::Sqlite)
        statement = QString(SelectTableExistedFromSqliteMaster).arg(table);
    else if (mType == SQLType::Mysql)
        statement = QString(ShowTablesLike).arg(table);
    else return false;

    mQuery.exec(statement);
    if (mQuery.isActive()){ // 执行语句成功前提下
        mQuery.first();
        auto rec = lastRecord();
        if (mQuery.isValid() && rec.count() == 1) { // 查询有效时只会有1条记录
            auto t = rec.value(0).toString(); // 会返回这个表名称
            if (t == table) {
                LOG<<"table"<<t<<" is already exist!";
                return true;
            }
        }
    } else { // 语句没执行成功
        SqlExecFailedLOG<<lastError();
    }
    LOG<<"table"<<table<<" is not exist!";
    return false;
    return false;
}

bool SqlReadWrite::createTable(QCString statement)
{
    mQuery.exec(statement);
    if (!mQuery.isActive()) {
        SqlExecFailedLOG<<lastError();
        return false;
    }
    LOG<<"create table is successful";
    return true;
}

bool SqlReadWrite::createTable(QCString create,QCString init)
{ // 表名，创建表的语句，表的初始化语句
    auto statement = QString(create).arg(init);
    return createTable(statement);
}

bool  SqlReadWrite::createEmptyTable(QCString table)
{
    //空表至少有id和datetime
    QString statement;
    if (mType == SQLType::Mysql)
        statement = QString(CreateEmptyTableMySql).arg(table);
    else if (mType == SQLType::Sqlite)
        statement = QString(CreateEmptyTableSqlite).arg(table);
    else return false;

    mQuery.exec(statement);
    if (!mQuery.isActive()) {
        SqlExecFailedLOG<<lastError();
        return false;
    }
    LOG<<"create empty table is successful";
    return true;
}

bool SqlReadWrite::containTable(QCString table)
{
    return mDB.tables().contains(table);
}

const QSqlDatabase SqlReadWrite::database() const
{
    return mDB;
}

QString SqlReadWrite::currentDataSource()
{
    QString statement;
    if (mType == SQLType::Mysql)
        statement = CurrentDataSourceMysql;
    else if ( mType == SQLType::Sqlite)
        statement = CurrentDataSourceSqlite;
    else return "";

    mQuery.exec(statement);
    if (!mQuery.isActive()){
        SqlExecFailedLOG<<lastError();
        return "";
    }

    mQuery.first();
    if (!mQuery.isValid())
        return "";

    if (mType == SQLType::Mysql)
        return mQuery.value(0).toString();
    else return mQuery.value(2).toString();

}

int SqlReadWrite::tableRows(QCString table)
{
    auto statements = QString(SelectTableRows).arg(table);
    mQuery.exec(statements);
    mQuery.first();
    if (!mQuery.isValid()) return 0; // 可能是无效的没有查到结果
    auto rows = mQuery.value(0).toInt();
    LOG<<"table's rows = "<<rows;
    return rows;
}

int SqlReadWrite::tableColumns(QCString table)
{ // 默认实现通过查询表后,record本身提供的功能返回
    // 对于mysql可以使用其他命令得到
    auto statements = QString(SelectXFromTable).arg(table);
    mQuery.exec(statements);
    auto cols = lastRecord().count();
    LOG<<"table's cols = "<<cols;
    return cols;
}

bool SqlReadWrite::haveField(QCString table,QCString field)
{ // 直接使用查询字段的sql命令
    auto statements = QString(SelectFieldFromTable).arg(field).arg(table);
    mQuery.exec(statements);

    if (mQuery.isActive()) { // 查询字段只要没执行失败就说明有这个字段
       LOG<<"field ["<<field<<"] is exist!";
       return true;
    } else {
        SqlExecFailedLOG<<lastError();
    }
    LOG<<"field ["<<field<<"] is not exist!";
    return false;
}

bool SqlReadWrite::containField(QCString table,QCString field)
{ // 不直接查询字段,查表后利用record实现
    auto statements = QString(SelectXFromTable).arg(table);
    mQuery.exec(statements);
    if (lastRecord().contains(field)) {
        LOG<<"field ["<<field<<"] is contains!";
        return true;
    }
    LOG<<"field ["<<field<<"] is not contains!";
    return false;
}

bool SqlReadWrite::fieldsRight(QCString table,QCFieldsList fields)
{ // 查询表中的字段,和事先规定的字段是否匹配,fields来自sqlstatements.h
    auto tableFields = fieldNames(table);
    // 1.检查数量
    if (tableFields.count() != fields.count()) {
        LOG<<"field's count not right, expect count = "<<fields.count()
          <<" infact count = "<<tableFields.count();
        return false;
    }
    // 2.逐顺序比较字段是否对应正确
    auto count = tableFields.count();
    LOG<<"field's count is right, count = "<<count;
    for (int i = 0; i < count; ++i ) {
        if (tableFields.at(i) != fields.at(i)) {
             LOG<<"field's count is right, but field "
               <<tableFields.at(i)<<" "<<fields.at(i) <<" dismatch";
            return false;
        }
    }
    LOG<<"field's count and order and name is right";
    return true;
}

QString SqlReadWrite::fieldName(QCString table,int index)
{
    auto statements = QString(SelectXFromTable).arg(table);
    mQuery.exec(statements);
    auto name = lastRecord().fieldName(index);
    LOG<<"the "<<index<<" field is "<<name;
    return name;
}

QFieldsList SqlReadWrite::fieldNames(QCString table)
{
    auto statements = QString(SelectXFromTable).arg(table);
    mQuery.exec(statements);
    QStringList ret;
    auto rec = lastRecord();
    for (int i = 0; i < rec.count(); ++i)
        ret.append(rec.fieldName(i));
    LOG<<table<<"'s fields is "<<ret;
    return ret;
}

int SqlReadWrite::fieldIndex(QCString table,QCString field)
{
    auto statements = QString(SelectXFromTable).arg(table);
    mQuery.exec(statements);
    auto idx = lastRecord().indexOf(field);
    LOG<<"the "<<field<<"'s index  is "<<idx;
    return idx;
}

QString SqlReadWrite::fieldValue(QCString table,int row, int col)
{ // 查询指定行指定列的值,要求必须查询返回的表是有序的,id是主键
    if (row<0 || row > tableRows(table)-1) {
        LOG<<"row is out of range";
        return "row is out of range";
    }
    if (col<0 || col > tableColumns(table) -1) {
        LOG<<"column is out of range";
        return "column is out of range";
    }

    auto statements = QString(SelectXFromTableOrderById).arg(table);
    mQuery.exec(statements);
    int r = row;
    mQuery.first();
    while (row-- && mQuery.next()) {}; // 移动到指定行
    auto var = mQuery.value(col); // 拿到指定列的值
    LOG<<"["<<r<<","<<col<<"] 's value = "<<var.toString();
    return var.toString();
}

QString SqlReadWrite::fieldValue(QCString table,int row, const QString&field)
{
    if (row<0 || row > tableRows(table)-1) {
        LOG<<"row is out of range";
        return "row is out of range";
    }
    if (!haveField(table,field)) {
        LOG<<field<<" is not exists!";
        return field+" is not exists!";
    }

    auto statements = QString(SelectXFromTableOrderById).arg(table);
    mQuery.exec(statements);
    mQuery.first();
    int r = row;
    while (row-- && mQuery.next()) {}; // 移动到指定行
    auto var = mQuery.value(field);
    LOG<<"["<<r<<","<<field<<"] 's value = "<<var.toString();
    return var.toString();
}

bool SqlReadWrite::query(QCString q)
{
    auto r = mQuery.exec(q);
    if (!r) SqlExecFailedLOG<<lastError();
    return r;
}

QString SqlReadWrite::dbError() const
{
    return mDB.lastError().text();
}

QString SqlReadWrite::lastError() const
{
    return  mQuery.lastError().text();
}

QSqlRecord SqlReadWrite::lastRecord() const
{
    return mQuery.record();
}

QSqlQuery SqlReadWrite::lastQuery() const
{
    return mQuery;
}

bool SqlReadWrite::addRecord(QCString table,QCFieldsList fieldList, QCValuesList values)
{/*
    * values是个列表,每个元素都是小括号包裹起来逗号分隔的字符串,需要单引号
    * fieldList是所有字段的列表,要拆成逗号分隔的,不需要单引号
    * QFieldsList fields = {"ana_spec1","ana_spec2","exper_name"};
    * QFieldsList values = {"('0.5','0.6','chenbei')","('0.86','0.34','chbi')","('0.98','0.16','cb')"};
    * instance->addRecord(ExperGeneralConfigTableName,fields,values);
    * 本函数可以插入多组值，字段数量和值的元素包含的值个数要一致
*/
    QString field;
    foreach(auto f,fieldList){
        field.append(f);
        field.append(',');
    }
    field.chop(1);

    QString value;
    foreach(auto v,values) {
        value.append(v);
        value.append(',');
    }
    value.chop(1);

    auto statement = QString(InsertRecord).arg(table).arg(field).arg(value);
    mQuery.exec(statement);
    if (mQuery.isActive()) {
        LOG<<statement<<" successful!";
        return true;
    } else {
        SqlExecFailedLOG<<lastError();
    }
    LOG<<statement<<" failed!";
    return false;
}

bool SqlReadWrite::addRecord(QCString table,QCFieldsList fieldList, QCString value)
{ // 本函数只插入一组值，是字符串包含单引号的形式，要求输入是"('0.5','0.6','chenbei')"的形式
    QCValuesList values = {value};
    return addRecord(table,fieldList,values);
}

bool SqlReadWrite::addRecord(QCString table,QCFieldsList fieldList, QCValueVector values)
{ // 本函数只插入一组值,但不是字符串包含单引号的形式,就是和fueldList对应的值
    //注意是QCValuelist ,不是QCValuesList
    if (fieldList.count() != values.count()){
        LOG<<"values'count = "<<values.count()<<" fields'count = "<<fieldList.count()<<" dismatch!";
        return false;
    }

    QString value = "("; // 要自己加括号
    foreach(auto v,values) {
        value.append("\'"); // 自己加单引号
        value.append(v);
        value.append("\'");
        value.append(',');
    }
    value.chop(1);
    value.append(")");
    LOG<<"values = "<<value;
    return addRecord(table,fieldList,value);
}

QBoolVector SqlReadWrite::addRecord(QCString table,QCFieldsList fieldList, QCValuemap map)
{ // 也是添加多组值,二维列表，每行是一组值
    auto count = map.count(); // 组的数量
    QBoolVector list(count);
    for(int i = 0 ; i < count;++i) {
        QValueVector vals = map.at(i); // 组的数据列表
        if (vals.count() != fieldList.count()){ // 组的点个数
            list[i] = false; // 键值对个数必须匹配
            continue;
        }
        else {
            list[i] = addRecord(table,fieldList,vals);
        }
    }
    LOG<<"the addRecord's ret is "<<list;
    return list;
}

bool SqlReadWrite::haveRecord(QCString table,QCString condition)
{
    auto statement = QString(SelectXFromTableWhere).arg(table).arg(condition);
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

bool SqlReadWrite::haveRecord(QCString table,QCString field,QCString condition)
{
    auto statement = QString(SelectFieldFromTableWhere).arg(field).arg(table).arg(condition);
    mQuery.exec(statement);
    if (!mQuery.isActive()) {
        SqlExecFailedLOG<<lastError();
    } else {
        mQuery.first();
        if (mQuery.isValid()) {
            return true;
        }
    }
    return false;
}

bool SqlReadWrite::haveRecord(QCString table,int row)
{// 一个快捷方法检查是否存在指定行记录
       auto condition = QString("id = %1").arg(row);
       return haveRecord(table,condition);
}

bool SqlReadWrite::removeRecord(QCString table, QCString condition)
{ // condition 如果有特殊字符例如逗号可能需要加引号
    if (!haveRecord(table,condition)) return true;

    auto statement = QString(RemoveRecord).arg(table).arg(condition);
    mQuery.exec(statement);
    if (!mQuery.isActive()) {
        SqlExecFailedLOG<<lastError();
        return false;
    }
    LOG<<statement<<" successful!";
    return true;
}

bool SqlReadWrite::removeRecord(QCString table, int row)
{ // 一个快捷方法删除指定行的
    auto condition = QString("id = %1").arg(row);
    return removeRecord(table,condition);
}

bool SqlReadWrite::updateRecord(QCString table,QCString dict, QCString condition)
{/*
    dict = "ana_spec1 = '0.55', ana_spec2 = '0.01', exper_name = 'hbnfjhsdbf' "
    condition = "id = 3" 像这样使用, 更新多对值
*/
    auto statement = QString(UpdateRecord).arg(table).arg(dict).arg(condition);
    mQuery.exec(statement);
    if (!mQuery.isActive()) {
        SqlExecFailedLOG<<lastError();
        return false;
    }
     LOG<<statement<<" successful!";
    return true;
}

bool SqlReadWrite::rollback(QCString flag)
{
    removeRecord(ExperGeneralConfigTableName,QString(FilterFlag).arg(flag));
    bool r1 = haveRecord(ExperGeneralConfigTableName,QString(FilterFlag).arg(flag));
    LOG<<"rollback table1? "<<!r1; // 确实不存在这条记录回滚成功
    removeRecord(GroupPointTableName,QString(FilterFlag).arg(flag));
    bool r2 = haveRecord(GroupPointTableName,QString(FilterFlag).arg(flag));
    LOG<<"rollback table2? "<<!r2;
    return r1&&r2;
}

bool SqlReadWrite::updateRecord(QCString table,QCString dict, int row)
{// 一个快捷方法更新指定行的记录
       if (!haveRecord(table,row)) return false;
       auto condition = QString("id = %1").arg(row);
       return updateRecord(table,dict,condition);
}

bool SqlReadWrite::updateRecord(QCString table,QCString key, QCString value,QCString condition)
{ // instance->updateRecord(ExperGeneralConfigTableName,"ana_spec1","100","id = 5"); 这样用
    // 只更新一对值 update logininfo set key = 'value' where ..
    auto dict = QString("%1 = '%2' ").arg(key).arg(value);
    return updateRecord(table,dict,condition);
}

bool SqlReadWrite::updateRecord(QCString table,QCString key, QCString value,int row)
{// 一个快捷方法更新指定行的记录
       if (!haveRecord(table,row)) return false;
       auto condition = QString("id = %1").arg(row);
       return updateRecord(table,key,value,condition);
}

bool SqlReadWrite::updateRecord(QCString table,QFieldsList keys, QValuesList values,QCString condition)
{//  QFieldsList fields = {"channel","view","wellsize"}; QValuesList vals = {"channel","view","wellsize"};
    if (keys.count() != values.count()) return false;
    QString dict;
    auto count = keys.count();
    for(int i = 0; i < count; ++i) {
        auto key = keys.at(i);
        auto val = values.at(i);
        dict += key + " = " + "\'" +val + "\'"+','; // A='1',B='1',...
    }
    dict.chop(1);//去掉逗号
    return updateRecord(table,dict,condition);
}

bool SqlReadWrite::updateRecord(QCString table,QFieldsList keys, QValuesList values,int row)
{ // 更新指定行的字段值
    if (!haveRecord(table,row)) return false;
    auto condition = QString("id = %1").arg(row);
    return updateRecord(table,keys,values,condition);
}

QDateTime SqlReadWrite::lastVisitTime(QCString)
{
    return QDateTime();
}

QDateTime SqlReadWrite::lastUpdateTime(QCString)
{
    return QDateTime();
}

QDateTime SqlReadWrite::createTime(QCString)
{
    return QDateTime();
}



