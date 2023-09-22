#include "../../inc/sql/sqldbquerytree.h"

void SqlDBQueryTree::refreshTree()
{
    mTreeView->clear();

    LOG<<"sql's connectionNames() = "<<QSqlDatabase::connectionNames()<<" "
      <<SqliteReadWritePointer->database()<<" "<<MysqlReadWritePointer->database();
    QSqlDatabase db;
    if (CurrentSqliteType)
        db = SqliteReadWritePointer->database();
    else db = MysqlReadWritePointer->database();
    //LOG<<db<<"  "<<db.isOpen();
    if (!db.open()) return;

    auto drivername = "driver@"+db.driverName();
    auto dbname = "source@"+db.databaseName();
    if (CurrentSqliteType)
        dbname = "source@"+QFileInfo(db.databaseName()).fileName().remove(".db3"); // sqlite可能传递的是路径信息
    auto user = "user@"+db.userName();
    auto ip = "ip@" + db.hostName();
    auto port = "port@" + QString::number(db.port());
    auto tables = db.tables();
    auto table = "tables@count: "+QString::number(tables.count()-1); // 密码表不显示

    QTreeWidgetItem * driveritem = new QTreeWidgetItem(mTreeView,QStringList()<<drivername);
    QTreeWidgetItem * sourceitem = new QTreeWidgetItem(mTreeView,QStringList()<<dbname);
    QTreeWidgetItem * useritem = new QTreeWidgetItem(mTreeView,QStringList()<<user);
    QTreeWidgetItem * ipitem = new QTreeWidgetItem(mTreeView,QStringList()<<ip);
    QTreeWidgetItem * portitem = new QTreeWidgetItem(mTreeView,QStringList()<<port);
    QTreeWidgetItem * tableitem = new QTreeWidgetItem(mTreeView,QStringList()<<table);
    int j = 0;
    for (int i = 0 ; i < tables.count(); ++i) {
        if (tables.at(i) == LoginInfoTableName)
            continue; // 密码表不能显示
        auto text = "table"+QString::number(++j)+"@" + tables[i];
        tableitem->addChild(new QTreeWidgetItem(QStringList()<<text));
    }
    mTreeView->addTopLevelItem(driveritem);
    mTreeView->addTopLevelItem(sourceitem);
    mTreeView->addTopLevelItem(useritem);
    mTreeView->addTopLevelItem(ipitem);
    mTreeView->addTopLevelItem(portitem);
    mTreeView->addTopLevelItem(tableitem);
}

void SqlDBQueryTree::showSchema()
{
    QTreeWidgetItem *item = mTreeView->currentItem();
    if (!item || !item->parent()) // 多做一些判断总是没错的,表节点有父类,均不能为空
        return;
    setBold(item->parent());
    setBold(item);
    auto text = item->text(0); // table1@a
    auto idx = text.indexOf("@");
    text.remove(0,idx+1);
    emit schemaShowed(text);
}

SqlDBQueryTree::SqlDBQueryTree(QWidget *parent) : QWidget(parent)
{
    mTreeView = new QTreeWidget;
    mTreeView->setHeaderLabel("DataBase");
    mTreeView->setEditTriggers(QTreeView::NoEditTriggers);
    mTreeView->setSelectionMode(QTreeView::SingleSelection);
    mTreeView->setSelectionBehavior(QTreeView::SelectRows);

    mRefresh = new QAction(tr("刷新"),mTreeView);
    mSchema = new QAction(tr("表架构"),mTreeView);

    mTreeView->addAction(mRefresh);
    mTreeView->addAction(mSchema);
    mTreeView->setContextMenuPolicy(Qt::ActionsContextMenu);

    connect(mRefresh,&QAction::triggered,this,&SqlDBQueryTree::refreshTree);
    connect(mSchema,&QAction::triggered,this,&SqlDBQueryTree::showSchema);
    connect(mTreeView,&QTreeWidget::itemActivated,this,&SqlDBQueryTree::onItemActivated);
    connect(mTreeView,&QTreeWidget::currentItemChanged,this,&SqlDBQueryTree::onCurrentItemChanged);

    QVBoxLayout * lay = new QVBoxLayout(this);
    lay->addWidget(mTreeView);

    refreshTree();
    INIT_FONT;
}

void SqlDBQueryTree::setBold(QTreeWidgetItem *item, bool bold)
{
    for (int i = 0; i < mTreeView->topLevelItemCount(); ++i) {
        setTreeItemBold(mTreeView->topLevelItem(i),false);
    }
    if (item->childCount() > 0) {
        for(int j = 0; j < item->childCount(); ++j)
            setTreeItemBold(item->child(j),false);
    }
    if (item->parent()) setTreeItemBold(item->parent(),bold);
    setTreeItemBold(item,bold);
}

void SqlDBQueryTree::onItemActivated(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    if (item->parent()) setBold(item->parent());
    setBold(item,true); // 这2行不要调换顺序
    if (!item->parent()) return; // 没有父类的不要发送
    auto text = item->text(0); // table1@a
    auto idx = text.indexOf("@");
    text.remove(0,idx+1);
    emit tableShowed(text);
}

void SqlDBQueryTree::onCurrentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    Q_UNUSED(previous);
    if (current &&current->parent()) // 这里current可能是nullptr,refresh的时候
        mSchema->setEnabled(true);
    else mSchema->setEnabled(false);
}

