#include "../../inc/sql/sqlqueryconsole.h"

SqlQueryConsole::SqlQueryConsole(QWidget *parent) : QWidget(parent)
{
    status1 = new QStatusBar;
    status2 = new QStatusBar;
    initStatus();

    tree = new SqlDBQueryTree; // 不要指定this 否则会出问题
    table = new SqlDBQueryTable;
    panel = new SqlDBQueryPanel;
    auto act1 = new QAction(tr("启动分析"));
    auto act2 = new QAction(tr("启动拍照"));

    connect(tree,&SqlDBQueryTree::tableShowed,table,&SqlDBQueryTable::showTable); //双击
    connect(tree,&SqlDBQueryTree::tableShowed,this,&SqlQueryConsole::updateStatus); //双击
    connect(tree,&SqlDBQueryTree::schemaShowed,table,&SqlDBQueryTable::showSchema);
    connect(table,&SqlDBQueryTable::queryResult,panel,&SqlDBQueryPanel::showQueryResult);
    connect(table,&SqlDBQueryTable::tableNameFields,panel,&SqlDBQueryPanel::updateCommand); //tableNameFields是showTable发出
    connect(table,&SqlDBQueryTable::tableNameFields,panel,&SqlDBQueryPanel::updateKeywords);
    connect(panel,&SqlDBQueryPanel::queryCommand,table,&SqlDBQueryTable::execQuery);
    connect(panel,&SqlDBQueryPanel::filterField,table,&SqlDBQueryTable::filterTableByField);
    connect(panel,&SqlDBQueryPanel::dateChanged,table,&SqlDBQueryTable::filterTableByTime);
    connect(act1,&QAction::triggered,this,&SqlQueryConsole::launchAnalysisDlg);
    connect(act2,&QAction::triggered,this,&SqlQueryConsole::launchPhotograph);

    tree->setMaximumWidth(300);
    addAction(act1);
    addAction(act2);
    setContextMenuPolicy(Qt::ActionsContextMenu);

    QHBoxLayout * s = new QHBoxLayout;
    s->addWidget(tree);
    s->addWidget(table);

    QVBoxLayout * lay = new QVBoxLayout(this);
    lay->addWidget(status1);
    lay->addWidget(status2);
    lay->addLayout(s);
    lay->addWidget(panel);
    INIT_FONT;
}

void SqlQueryConsole::initStatus()
{
    QString s1,s2;
    QSqlDatabase db;
    QFileInfo info;

    if (CurrentSqliteType) {
        db = SqliteReadWritePointer->database();
        info = QFileInfo(db.databaseName()); // databaseName是全路径
    } else {
        db = MysqlReadWritePointer->database();
        info = QFileInfo(MysqlReadWritePointer->datadir()); // 表所在的文件夹路径
    }

    s1 += tr("路径: %1\t").arg(info.filePath());
    s1 += tr("创建时间: %1").arg(info.birthTime().toString("yyyy//MM//dd hh:mm:ss"));
    s2 += tr("上次访问时间: %1\t").arg(info.lastRead().toString("yyyy//MM//dd hh:mm:ss"));
    s2 += tr("上次更新时间: %1").arg(info.lastModified().toString("yyyy//MM//dd hh:mm:ss"));

    status1->showMessage(s1);
    status2->showMessage(s2);
}

void SqlQueryConsole::updateStatus(const QString& table)
{
    QString s1,s2;
    QSqlDatabase db;
    QFileInfo info;
    QString path;

    if (CurrentSqliteType) {
        db = SqliteReadWritePointer->database();
        info = QFileInfo(db.databaseName()); // databaseName是全路径
    } else {
        db = MysqlReadWritePointer->database();
        foreach(auto p, MysqlReadWritePointer->tablePaths()) //防止不存在表路径的情况
            if (p.contains(table))
                path = p;
        if (path.isEmpty())
            info = QFileInfo(MysqlReadWritePointer->datadir()); // 表所在的文件夹路径
        else info = QFileInfo(path);
    }

    s1 += tr("路径: %1\t").arg(info.filePath());
    s1 += tr("创建时间: %1").arg(info.birthTime().toString("yyyy//MM//dd hh:mm:ss"));
    s2 += tr("上次访问时间: %1\t").arg(info.lastRead().toString("yyyy//MM//dd hh:mm:ss"));
    s2 += tr("上次更新时间: %1").arg(info.lastModified().toString("yyyy//MM//dd hh:mm:ss"));
    status1->showMessage(s1);
    status2->showMessage(s2);
}

void SqlQueryConsole::launchAnalysisDlg()
{ // 启动实验数据分析窗口

}

void SqlQueryConsole::launchPhotograph()
{ // 立即启动拍照一次,无需设置间隔和开始时间

}

void SqlQueryConsole::setCurrentUser(QCString user)
{
    table->setCurrentUser(user);
}
