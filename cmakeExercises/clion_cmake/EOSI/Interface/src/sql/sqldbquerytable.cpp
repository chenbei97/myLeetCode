#include "../../inc/sql/sqldbquerytable.h"

SqlDBQueryTable::SqlDBQueryTable(QWidget *parent) : QWidget(parent)
{
    initObject();
    initConnections();
    initAttributes();

    QVBoxLayout * lay = new QVBoxLayout(this);
    lay->addWidget(mView);
    INIT_FONT;
}

void SqlDBQueryTable::updateActionEnabled()
{
    auto model = mView->model();
    if (model == mSchemaModel || model == mQueryModel) {
        mDeleteRecord->setEnabled(false);
        mShowContent->setEnabled(false);
        mSubmitAll->setEnabled(false);
        mRevertAll->setEnabled(false);
        mDescOrder->setEnabled(false);
        mAsecOrder->setEnabled(false);
        mRefresh->setEnabled(false);
        // 架构表的话可以使用排序功能,其它功能均不能使用
        if (model == mSchemaModel && mSelection->selectedIndexes().count() != 0) {
            mDescOrder->setEnabled(true);
            mAsecOrder->setEnabled(true);
        }
        return;
    }
    // Sql模型可用全部功能
    if (mSelection->selectedIndexes().count() == 0) { // 选中才能使用删除、显示和排序功能
        mDeleteRecord->setEnabled(false);
        mShowContent->setEnabled(false);
        mDescOrder->setEnabled(false);
        mAsecOrder->setEnabled(false);
    } else {
        mDeleteRecord->setEnabled(true);
        mShowContent->setEnabled(true);
        mDescOrder->setEnabled(true);
        mAsecOrder->setEnabled(true);
    }
    if (mModel->isDirty()) {
        mSubmitAll->setEnabled(true);
        mRevertAll->setEnabled(true);
    } else {
        mSubmitAll->setEnabled(false);
        mRevertAll->setEnabled(false);
    }
}

void SqlDBQueryTable::onAsecOrder()
{
    if (mSelection->selectedIndexes().count() == 0) return ;
    auto col = mSelection->selectedIndexes().at(0).column();
    auto model = mView->model();
    if (model == mModel) {
        mModel->setSort(col,Qt::AscendingOrder);
        mModel->select();
    } else if (model == mSchemaModel) {
        mSchemaModel->sort(col,Qt::AscendingOrder);
    }
}

void SqlDBQueryTable::onDescOrder()
{
    if (mSelection->selectedIndexes().count() == 0) return ;
    auto col = mSelection->selectedIndexes().at(0).column();
    auto model = mView->model();
    if (model == mModel) {
        mModel->setSort(col,Qt::DescendingOrder);
        mModel->select();
    } else if (model == mSchemaModel) {
        mSchemaModel->sort(col,Qt::DescendingOrder);
    }
}

void SqlDBQueryTable::onDeleteRecord()
{
    if (mSelection->selectedIndexes().count() == 0) return ;
    auto row = mSelection->selectedIndexes().at(0).row();
    // 删除记录只能是sql模型可以
    mModel->removeRow(row);
    mModel->select();
}

void SqlDBQueryTable::onShowContent()
{ // 显示文本也是sql模型可以
    if (mSelection->selectedIndexes().count() == 0) return ;
    auto index = mSelection->selectedIndexes().at(0);
    auto content = mModel->data(index,Qt::DisplayRole).toString();
    TextEdit * dlg = new TextEdit;
    dlg->setTitle(mModel->headerData(index.column(),Qt::Horizontal).toString());
    dlg->resize(600,300);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setText(content);
    dlg->show();
}

void SqlDBQueryTable::showTable(const QString& table)
{
    //qDebug()<<table;
    //mModel->setTable(db.driver()->escapeIdentifier(table,QSqlDriver::TableName));
    mModel->setTable(table);
    auto encryusers = getEncryUser(table);

    if (encryusers.isEmpty()) // 也可能为空,没有这个用户的记录,直接不显示即可
        mModel->setFilter(QString(FilterUser).arg(mUser));  // user = 'xx'都可以肯定没有
    else if (encryusers.count() == 1 )
        mModel->setFilter(QString(FilterUser).arg(encryusers.first()));
    else { // grouppoint/experconfig可能有多条记录
        QString statement;
        foreach(auto encryuser,encryusers) {
            statement.append(QString(FilterUser).arg(encryuser));
            statement.append(" or ");
        }
        statement.chop(QString(" or ").count());
        mModel->setFilter(statement);
    }
    mModel->select(); // 重新查询一下

    mView->setModel(mModel);
    // 查询是否成功的消息
    if (mModel->lastError().type() != QSqlError::NoError)
        emit queryResult(mModel->lastError().text());
    else emit queryResult(QString("[%1] query successful!")
                          .arg(QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1)));

    // 拿到表的字段,用于更新查询面板的字段下拉框组件
    QStringList fields;
    auto record  = mModel->record();
    for(int i = 0; i < record.count(); ++i) {
        auto field = record.fieldName(i);
        if (field != ExperConfigTableFields.user) // user字段不要提供给用户
            fields.append(field);
    }
    // 此信号会更新字段列表,导致过滤按钮再次触发，双击没有变为mModel
    emit tableNameFields(table,fields);
}

void SqlDBQueryTable::showSchema(const QString& table)
{
    auto record = db.record(table);
    mSchemaModel->setRowCount(record.count());
    for (int i = 0; i < record.count(); ++i) {
        QSqlField fld = record.field(i);
        QString value;
        if (!fld.value().isValid() || fld.value().toString().isEmpty()) value ="null";
        else value = fld.value().toString();
        QString defaultValue;
        if (!fld.defaultValue().isValid() || fld.defaultValue().toString().isEmpty()) defaultValue ="null";
        else defaultValue = fld.defaultValue().toString();

        mSchemaModel->setData(mSchemaModel->index(i, 0), fld.name());
        mSchemaModel->setData(mSchemaModel->index(i, 1),QMetaType::typeName(fld.type()));
        mSchemaModel->setData(mSchemaModel->index(i, 2), fld.length());
        mSchemaModel->setData(mSchemaModel->index(i, 3), fld.precision());
        mSchemaModel->setData(mSchemaModel->index(i, 4), value);
        mSchemaModel->setData(mSchemaModel->index(i, 5), defaultValue);
        mSchemaModel->setData(mSchemaModel->index(i, 6), fld.requiredStatus() == -1 ? QVariant("?"): QVariant(bool(fld.requiredStatus())));
        mSchemaModel->setData(mSchemaModel->index(i, 7), fld.isGenerated());
        mSchemaModel->setData(mSchemaModel->index(i, 8), fld.isAutoValue());
        mSchemaModel->setData(mSchemaModel->index(i, 9), fld.isReadOnly());
    }
    mView->setModel(mSchemaModel);
    mSelection->setModel(mSchemaModel); // 选择模型的基于模型要更新
    mView->setEditTriggers(TableView::NoEditTriggers);
    mView->setSelectionModel(mSelection); // 选择模型也要更新
}

void SqlDBQueryTable::execQuery(const QString& command)
{// 查询模型
    mQueryModel->setQuery(QSqlQuery(command, db));
    mView->setModel(mQueryModel);
//    mSelection->setModel(mQueryModel); // 选择模型的基于模型要更新
//    mView->setEditTriggers(TableView::NoEditTriggers);
//    mView->setSelectionModel(mSelection); // 选择模型也要更新

    // 查询的消息
    if (mQueryModel->lastError().type() != QSqlError::NoError)
        emit queryResult(mQueryModel->lastError().text());
    else if (mQueryModel->query().isSelect())
        emit queryResult(QString("[%1] query successful!")
                                  .arg(QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1)));
}

//#define UseSetFilter 0
void SqlDBQueryTable::filterTableByField(const QString& field,const QString& key)
{ // sqlquerypanel发出的过滤查询字段
    //LOG<<"field= "<<field<<" key = "<<key;
#ifdef UseSetFilter
    // 原来的参数只有const QString& filter
    //mModel->setFilter("datetime > 2023/04/02 and datetime < 20230602");
    mModel->setFilter(filter);// 使用setFilter的过滤效果不好,不是%s%去匹配
    mModel->select();
    mView->setModel(mModel);
    mView->setEditTriggers(TableView::NoEditTriggers);
    mSelection->setModel(mModel); // 选择模型的基于模型要更新
    mView->setSelectionModel(mSelection); // 选择模型也要更新

    if (mModel->lastError().type() != QSqlError::NoError)
        emit queryResult(mModel->lastError().text());
    else if (mModel->query().isSelect())
        emit queryResult(QString("[%1] query successful!")
                                  .arg(QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1)));
#else
    // select * from experconfig where datetime like '%%3%';
    auto statement = QString(FilterTable).arg(mModel->tableName(),field,key);

    mQueryModel->setQuery(statement,db);

    mView->setModel(mQueryModel);
//    mSelection->setModel(mQueryModel); // 选择模型的基于模型要更新
//    mView->setEditTriggers(TableView::NoEditTriggers);
//    mView->setSelectionModel(mSelection); // 选择模型也要更新

    if (mQueryModel->lastError().type() != QSqlError::NoError)
        emit queryResult(mQueryModel->lastError().text());
    else if (mQueryModel->query().isSelect())
        emit queryResult(QString("[%1] filter by %2 successful!")
                         .arg(QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1))
                         .arg(field));
#endif
}

void SqlDBQueryTable::filterTableByTime(const QString& start,const QString& end)
{
    if (mModel->tableName().isEmpty()) return; // 防止还没双击显示表用户就点了时间控件
    auto statement = QString(FilterTableByTime).arg(mModel->tableName()).arg(start).arg(end);
    mQueryModel->setQuery(QSqlQuery(statement, db));

    mView->setModel(mQueryModel);
//    mSelection->setModel(mQueryModel); // 选择模型的基于模型要更新
//    mView->setEditTriggers(TableView::NoEditTriggers);
//    mView->setSelectionModel(mSelection); // 选择模型也要更新

    if (mQueryModel->lastError().type() != QSqlError::NoError)
        emit queryResult(mQueryModel->lastError().text());
    else if (mQueryModel->query().isSelect())
        emit queryResult(QString("[%1] filter by datetime successful!")
                         .arg(QDateTime::currentDateTime().toString(ExperConfigTableFields.other_fields.datetime_iso1)));
}

void SqlDBQueryTable::initConnections()
{
    connect(mView,&TableView::mouseRightButtonPressed,this,&SqlDBQueryTable::updateActionEnabled);
    connect(mView,&TableView::modelSettled,this,&SqlDBQueryTable::onModelSettled);
    connect(mModel,&SqlTableModel::tableSettled,this,&SqlDBQueryTable::onTableSettled);
    connect(mDescOrder,&QAction::triggered,this,&SqlDBQueryTable::onDescOrder);
    connect(mAsecOrder,&QAction::triggered,this,&SqlDBQueryTable::onAsecOrder);
    connect(mShowContent,&QAction::triggered,this,&SqlDBQueryTable::onShowContent);
    connect(mDeleteRecord,&QAction::triggered,this,&SqlDBQueryTable::onDeleteRecord);
    connect(mSubmitAll,&QAction::triggered,this,[=]{mModel->submitAll();});
    connect(mRevertAll,&QAction::triggered,this,[=]{mModel->revertAll();});
    connect(mRefresh,&QAction::triggered,this,[=]{mModel->select();});

}

void SqlDBQueryTable::initAttributes()
{
    mView->setEditTriggers(TableView::DoubleClicked);
    mView->setTextElideMode(Qt::ElideRight);
    mView->setContextMenuPolicy(Qt::ActionsContextMenu);

    mModel->setEditStrategy(SqlTableModel::OnManualSubmit);
    mView->setModel(mModel);

    mSchemaModel->insertColumns(0, 10);
    mSchemaModel->setHeaderData(0, Qt::Horizontal, "name"); // "id"
    mSchemaModel->setHeaderData(1, Qt::Horizontal, "type"); // QVariant::QDateTime
    mSchemaModel->setHeaderData(2, Qt::Horizontal, "length"); // 11
    mSchemaModel->setHeaderData(3, Qt::Horizontal, "precision"); // 0
    mSchemaModel->setHeaderData(4, Qt::Horizontal, "value"); // ""
    mSchemaModel->setHeaderData(5, Qt::Horizontal, "defaultValue"); // ""
    mSchemaModel->setHeaderData(6, Qt::Horizontal, "isRequired"); // 1=requierd,0=optional,-1=unknow
    mSchemaModel->setHeaderData(7, Qt::Horizontal, "isGenerated"); // true
    mSchemaModel->setHeaderData(8, Qt::Horizontal, "isAutoValue"); // true
    mSchemaModel->setHeaderData(9, Qt::Horizontal, "isReadOnly"); // false
}

void SqlDBQueryTable::onModelSettled(QAbstractItemModel *m)
{
    if (m == mModel) {
        mView->setEditTriggers(TableView::DoubleClicked); // 允许修改
        if (mModel->tableName() == ExperGeneralConfigTableName){
            auto idx = columnIndex("group_names"); // group_names不允许修改,因为格式可能会导致错误
            mView->setItemDelegate(new QStyledItemDelegate()); // 其它的要恢复成默认,不能用nullptr会看不到
            mView->setItemDelegateForColumn(idx,new TableViewDelegateReadOnly);
        }
        if (mModel->tableName() == GroupPointTableName){
            mView->setItemDelegate(nullptr);
            mView->setItemDelegate(new TableViewDelegateReadOnly); // 组点表不允许编辑
        }

    } else if (m == mQueryModel) {
        mView->setEditTriggers(TableView::NoEditTriggers);
    } else if (m == mSchemaModel) {
        mView->setEditTriggers(TableView::NoEditTriggers);
    }
    auto userCol = columnIndex(ExperConfigTableFields.user);
    mView->hideColumn(userCol); // 用户列隐藏起来
    mSelection->setModel(m);
    mView->setSelectionModel(mSelection);
}

void SqlDBQueryTable::onTableSettled(const QString &table)
{ // model切换要更新,但是SqlTableModel的表变时也要更新

    //mView->setModel(mModel); // 直接利用这个来更新,因为modelChanged信号调用就会发送

   // mView->model()此时还没更新mView, 不要使用mView->model() == mModel,一定是false
    mView->setEditTriggers(TableView::DoubleClicked); // 允许修改

    if (table == ExperGeneralConfigTableName){
        auto idx = columnIndex(ExperConfigTableFields.group_names); // group_names不允许修改,因为格式可能会导致错误
        mView->setItemDelegate(new QStyledItemDelegate());
        mView->setItemDelegateForColumn(idx,new TableViewDelegateReadOnly);
    }
    if (table == GroupPointTableName){
        mView->setItemDelegate(nullptr);
        mView->setItemDelegate(new TableViewDelegateReadOnly); // 组点表不允许编辑
    }
    auto userCol = columnIndex(ExperConfigTableFields.user);
    mView->hideColumn(userCol); // 用户列隐藏起来
}

void SqlDBQueryTable::initObject()
{
    if (CurrentSqliteType)
        db = SqliteReadWritePointer->database();
    else db = MysqlReadWritePointer->database();

    mView = new TableView(this);
    mAsecOrder = new QAction(tr("升序"));
    mDescOrder = new QAction(tr("降序"));
    mDeleteRecord = new QAction(tr("删除"));
    mSubmitAll = new QAction(tr("提交"));
    mRevertAll = new QAction(tr("撤销"));
    mShowContent = new QAction(tr("显示"));
    mRefresh = new QAction(tr("刷新"));
    mView->addAction(mAsecOrder);
    mView->addAction(mDescOrder);
    mView->addAction(mDeleteRecord);
    mView->addAction(mSubmitAll);
    mView->addAction(mRevertAll);
    mView->addAction(mShowContent);
    mView->addAction(mRefresh);

    mModel = new SqlTableModel(mView,db);
    mQueryModel = new SqlQueryModel(mView);
    mSelection = new QItemSelectionModel(mModel);

    mSchemaModel = new StandardItemModel(mView);
}

void SqlDBQueryTable::setCurrentUser(const QString& user)
{
    mUser = user; // 是原始形式
    LOG<<"user = "<<mUser;
}

QStringList SqlDBQueryTable::getEncryUser(QCString table)
{ // 获取指定表,mUser的加密字符串,对于grouppoint表多个组的user都是同一个mUser
    QStringList users;
    auto statement = QString(SelectFieldFromTable).arg(ExperConfigTableFields.user).
            arg(table);

    SqlReadWrite * pointer = nullptr;
    if (CurrentSqliteType) pointer = SqliteReadWritePointer;
    else pointer = MysqlReadWritePointer;

    pointer->query(statement);
    auto query = pointer->lastQuery();
    while (query.next()) {
        auto encryuser = query.value(0).toString();
        if (decry_color(encryuser) == mUser)
            users.append(encryuser);
    }
    //LOG<<mUser<<"'s encry users = "<<users;
    return users;
}

int SqlDBQueryTable::columnIndex(const QString &name)
{
    auto model = mView->model();
    for(int col = 0; col < model->columnCount(); ++col) {
        auto field = model->headerData(col,Qt::Horizontal).toString();
        if (name == field)
            return col;
    }
    return -1;
}
