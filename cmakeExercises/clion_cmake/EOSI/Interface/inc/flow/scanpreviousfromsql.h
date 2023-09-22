#ifndef SCANPREVIOUSFROMSQL_H
#define SCANPREVIOUSFROMSQL_H

#include "tables/tableview.h"
#include "widgets/pushbutton.h"
#include "widgets/sqltablemodel.h"
#include "widgets/eventloop.h"
#include "widgets/textedit.h"
#include "utilities/sqlstatements.h"
#include "utilities/sqlitereadwrite.h"
#include "utilities/mysqlreadwrite.h"
#include "utilities/encry.h"

class ScanPreviousFromSql : public QWidget
{
    Q_OBJECT
public:
    enum QuitState {Accepted = 1,Rejected = 0};
    explicit ScanPreviousFromSql(QWidget *parent = nullptr);
    QVariantMap configdata() const;
    int exec();
    void setCurrentUser(const QString& user);
    void closeEvent(QCloseEvent *event) override;
private:
    void initObject();
    void initAttributes();
    void initConnections();
    void initLayout();
    void onLastRecord();
    void onNextRecord();
    void onChangeRow(const QModelIndex &current, const QModelIndex &previous);
    void onShowContent();
    void onAccept();
    void onReject();
    int columnIndex(const QString &name);
    TextEdit* contentDialog() const;
private:
    QuitState quitstate ;
    SqlTableModel * mModel;
    TableView * mView;
    QItemSelectionModel * mSelection;
    QSqlDatabase db;
    QAction * mLastAct;
    QAction * mNextAct;
    QAction * mShowContent;
    PushButton * mLastBtn;
    PushButton * mNextBtn;
    PushButton * mOkBtn;
    PushButton * mNotOkBtn;
    QEventLoop loop;
signals:
    void accept();
    void reject();
};

#endif // SCANPREVIOUSFROMSQL_H
