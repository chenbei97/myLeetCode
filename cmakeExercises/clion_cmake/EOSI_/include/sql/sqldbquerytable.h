#ifndef SQLDBQUERYTABLE_H
#define SQLDBQUERYTABLE_H

#include "../../../include/tables/tableview.h"
#include "../../../include/tables/tableviewdelegatetextedit.h"
#include "../../../include/tables/tableviewdelegatereadonly.h"
#include "../../../include/widgets/sqltablemodel.h"
#include "../../../include/widgets/standarditemmodel.h"
#include "../../../include/widgets/sqlquerymodel.h"
#include "../../../include/utilities/sqlstatements.h"
#include "../../../include/utilities/sqlitereadwrite.h"
#include "../../../include/utilities/mysqlreadwrite.h"
#include "../../../include/utilities/encry.h"
#include "qheaderview.h"
#include "qitemselectionmodel.h"

class SqlDBQueryTable : public QWidget
{
    Q_OBJECT
public:
    explicit SqlDBQueryTable(QWidget *parent = nullptr);
public slots:
    void setCurrentUser(const QString& user);
    void showTable(const QString& table);
    void showSchema(const QString& table);
    void execQuery(const QString& command);
    void filterTableByTime(const QString& start,const QString& end);
    void filterTableByField(const QString& field,const QString& key);
private:
    void initObject();
    void initAttributes();
    void initConnections();
    int columnIndex(const QString& name);
    void updateActionEnabled();
    void onDescOrder();
    void onAsecOrder();
    void onDeleteRecord();
    void onShowContent();
    void onModelSettled(QAbstractItemModel*m);
    void onTableSettled(const QString& table);
    QStringList getEncryUser(QCString table);
private:
    QString mUser;
    SqlTableModel * mModel;
    StandardItemModel * mSchemaModel;
    SqlQueryModel * mQueryModel;
    TableView * mView;
    QAction * mDeleteRecord;
    QAction * mSubmitAll;
    QAction * mRevertAll;
    QAction * mRefresh;
    QAction * mShowContent;
    QAction * mDescOrder;
    QAction * mAsecOrder;
    QItemSelectionModel * mSelection;
    QSqlDatabase db;
signals:
    void queryResult(const QString& msg);
    void tableNameFields(const QString& table,const QStringList& fields);
};

#endif // SQLDBQUERYTABLE_H
