#include "../../inc/flow/scanpreviousfromsql.h"

ScanPreviousFromSql::ScanPreviousFromSql(QWidget *parent) : QWidget(parent)
{
    initObject();
    initConnections();
    initAttributes();
    initLayout();
}

int ScanPreviousFromSql::exec()
{
    //QApplication::setOverrideCursor(Qt::WaitCursor);
    show();
    loop.exec(); //阻塞等待quitstate更改,和异步信号
    //QApplication::restoreOverrideCursor();
    return quitstate;
}

QVariantMap ScanPreviousFromSql::configdata() const
{ // =>ScanPreviousFlow::parseData()=>ScanVesselConfig::onNextPrevious()
// 传播出去, 对于group是通过"group"来设置GroupVectorPair的
    QVariantMap m;
    int c = 4; // id,datetime,user,flag都不需要,从4开始
    auto row = mSelection->selectedIndexes().at(0).row();
    for(; c < mModel->columnCount(); ++c) {
          auto key = mModel->headerData(c,Qt::Horizontal).toString();
          auto value = mModel->data(row,c);
          if (key == ExperConfigTableFields.group_names ) { // 单独处理
              continue;
          }
          m[key] = value;
    }
    // 处理group
    GroupVectorPair groupdata;
    PointVectorPair pointdata;
    QGroupPointVector pointlist;
    QGroupPointNameVector namelist;
    // (1) 拿到组列表
    auto groups = mModel->data(row,ExperTableGroupColumn);
    QGroupNameVector groupNames = groups.split(",",QString::SkipEmptyParts).toVector();

    // (2) 根据组列表查询groupPoint表,把point_pos和point_pos拿出来
    /*select point_pos,point_name from grouppoint where flag == "230912133001" and group_name == "A组"*/
    auto flag = mModel->data(row,ExperTableFlagColumn);
    foreach(auto group,groupNames) {
        auto statement = QString(QueryGroupPointAndName).arg(flag).arg(group);

        SqlReadWrite* pointer = nullptr;
        if (CurrentSqliteType) pointer  = SqliteReadWritePointer;
        else pointer = MysqlReadWritePointer;

        QVector<QPoint> grouppoints; // 某个组的所有点位置和名称
        QVector<QString> groupnames;
        if (pointer->query(statement)) {
            auto query = pointer->lastQuery();// 只会查到2列,1行记录 或者不存在这条记录
            query.first();
            if (query.isValid()) { // 有这个记录
                auto str = query.value(0).toString(); // (12,2),(13,23),(3,23),(0,3)
                str.remove("(");
                str.remove(")");
                auto s = str.split(",",QString::SkipEmptyParts);
                for(int i = 0; i < s.count()-1; i+=2) {
                    auto x = s.at(i).toUInt();
                    auto y = s.at(i+1).toUInt();
                    grouppoints.append(QPoint(x,y));
                }
                groupnames = query.value(1).toString()
                        .split(",",QString::SkipEmptyParts).toVector(); // A1,A2,A3,A4

            }
        }
        pointlist.append(grouppoints);
        namelist.append(groupnames);
    }
    pointdata.first = pointlist;
    pointdata.second = namelist;

    groupdata.first = groupNames;
    groupdata.second = pointdata;
    //qDebug()<<pointdata;

    QVariant v;
    v.setValue(groupdata);
    m[ExperConfigTableFields.other_fields.group] = v;

    return m;
}

void ScanPreviousFromSql::onShowContent()
{
    if (mSelection->selectedIndexes().count() == 0) return ;
    auto row= mSelection->selectedIndexes().at(0).row();
    //setWindowModality(Qt::NonModal);
    auto dlg = contentDialog();

    dlg->setTitle(tr("第%1行主要信息").arg(row+1));

    auto total_time = mModel->data(row,ExperTableTotalColumn).toUInt();
    auto total = tr("%1 s = %2 min = %3 h").arg(total_time).arg(total_time/60.0).arg(total_time/3600.0);

    auto duration_time = mModel->data(row,ExperTableDurationColumn).toUInt();
    auto duration = tr("%1 s = %2 min = %3 h").arg(duration_time).arg(duration_time/60.0).arg(duration_time/3600.0);

    auto is_schedule = mModel->data(row,ExperTableScheduleColumn).toUInt();
    auto scan_count = mModel->data(row,ExperTableCountColumn);

    auto count = tr("%1 / %2 = %3 次").arg(total_time).arg(duration_time)
            .arg(duration_time?total_time/duration_time: 0); // 除数不能为0,是个隐患

    dlg->append(tr("孔板规格"),mModel->data(row,ExperTableWellSizeColumn),"#00AEFA");
    dlg->append(tr("物镜倍数"),mModel->data(row,ExperTableObjectiveColumn),"#F08784");
    dlg->append(tr("视野数量"),mModel->data(row,ExperTableViewColumn),"#73FBFD");
    dlg->append(tr("成像模式"),mModel->data(row,ExperTableChannelColumn),"#F08650");
    dlg->append(tr("实验类型"),mModel->data(row,ExperTableExperTypeColumn),"#EA3680");
    dlg->append(tr("扫描类型"),is_schedule?tr("计划扫描"):tr("立即扫描"),"#EA3FF7");
    dlg->append(tr("扫描时间"),total,"#367E7F");
    dlg->append(tr("间隔时间"),duration,"#7B7EB5");
    dlg->append(tr("扫描次数"),count,"#377D22");
    if (is_schedule) {
        dlg->append(tr("开始时间"),mModel->data(row,ExperTableStartTimeColumn),"#EB3324");
        dlg->append(tr("结束时间"),mModel->data(row,ExperTableEndTimeColumn),"#741B7C");
    }
}

TextEdit * ScanPreviousFromSql::contentDialog() const
{
    TextEdit * dlg = new TextEdit;
    dlg->clearText();
    dlg->setReadOnly(true);
    dlg->resize(600,300);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->show();

    return dlg;
}

void ScanPreviousFromSql::onLastRecord()
{
    if (mSelection->selectedIndexes().count() == 0) return ;
    auto current = mSelection->selectedIndexes().at(0).row();
    //qDebug()<<current<<"  "<<mSelection->selectedRows().at(0).row(); // 相同
    if (current == 0 ) return;

    current--;
    QModelIndex start = mModel->index(current,0);
    QModelIndex end = mModel->index(current,mModel->columnCount()-1);
    QItemSelection selection (start,end);
    mSelection->select(selection,QItemSelectionModel::ClearAndSelect);

    if (current == 0) { // 可能是通过按钮操作的,没有触发onChangeRow
        mLastAct->setEnabled(false);
        mLastBtn->setEnabled(false);
    } else {
        mLastAct->setEnabled(true);
        mLastBtn->setEnabled(true);
    }
    mNextAct->setEnabled(true);
    mNextBtn->setEnabled(true);
}

void ScanPreviousFromSql::onChangeRow(const QModelIndex &current, const QModelIndex &previous)
{ // 选中的索引行更改
    Q_UNUSED(previous);
    auto row = current.row();

    if (row == 0) {
        mLastAct->setEnabled(false);
        mLastBtn->setEnabled(false);
        mNextAct->setEnabled(true);
        mNextBtn->setEnabled(true);
    }
    else if (row == mModel->rowCount()-1) {
        mLastAct->setEnabled(true);
        mLastBtn->setEnabled(true);
        mNextAct->setEnabled(false);
        mNextBtn->setEnabled(false);
    } else {
        mLastAct->setEnabled(true);
        mLastBtn->setEnabled(true);
        mNextAct->setEnabled(true);
        mNextBtn->setEnabled(true);
    }
    //mView->repaint();
    qApp->processEvents();
}

void ScanPreviousFromSql::onNextRecord()
{
    if (mSelection->selectedIndexes().count() == 0) return ;
    auto current = mSelection->selectedRows().at(0).row();
    if (current == mModel->rowCount()-1 ) return;

    current++;
    QModelIndex start = mModel->index(current,0);
    QModelIndex end = mModel->index(current,mModel->columnCount()-1);
    QItemSelection selection (start,end);
    mSelection->select(selection,QItemSelectionModel::ClearAndSelect);

    if (current == mModel->rowCount() - 1) {
        mNextAct->setEnabled(false);
        mNextBtn->setEnabled(false);
    } else {
        mNextAct->setEnabled(true);
        mNextBtn->setEnabled(true);
    }
    mLastAct->setEnabled(true);
    mLastBtn->setEnabled(true);
}

void ScanPreviousFromSql::onAccept()
{
    quitstate = QuitState::Accepted;
    close(); // closevent重载
}

void ScanPreviousFromSql::onReject()
{
    quitstate = QuitState::Rejected;
    close();
}

void ScanPreviousFromSql::initObject()
{
    if (CurrentSqliteType)
        db = SqliteReadWritePointer->database();
    else db = MysqlReadWritePointer->database();

    mView = new TableView(this);
    mLastAct = new QAction(tr("上一条"));
    mNextAct = new QAction(tr("下一条"));
    mShowContent = new QAction(tr("主要信息"));
    mView->addAction(mLastAct);
    mView->addAction(mNextAct);
    mView->addAction(mShowContent);

    mLastBtn = new PushButton(tr("上一条"));
    mNextBtn = new PushButton(tr("下一条"));
    mOkBtn = new PushButton(tr("确定"));
    mNotOkBtn = new PushButton(tr("取消"));

    mModel = new SqlTableModel(mView,db);
    mSelection = new QItemSelectionModel(mModel);
}

void ScanPreviousFromSql::initAttributes()
{
    quitstate = QuitState::Rejected;
    mModel->setTable(ExperGeneralConfigTableName);
    mView->setEditTriggers(TableView::NoEditTriggers);
    mView->setSelectionBehavior(QAbstractItemView::SelectRows);
    mView->setAlternatingRowColors(true);
    mView->setTextElideMode(Qt::ElideRight);
    mView->setContextMenuPolicy(Qt::ActionsContextMenu);
    mView->setModel(mModel);
    mSelection->setModel(mModel);
    mView->setSelectionModel(mSelection);
    auto userCol = columnIndex(ExperConfigTableFields.user);
    mView->hideColumn(userCol); // 用户列隐藏起来
}

void ScanPreviousFromSql::initConnections()
{
    connect(mShowContent,&QAction::triggered,this,&ScanPreviousFromSql::onShowContent);
    connect(mLastAct,&QAction::triggered,this,&ScanPreviousFromSql::onLastRecord);
    connect(mNextAct,&QAction::triggered,this,&ScanPreviousFromSql::onNextRecord);
    connect(mLastBtn,&PushButton::clicked,this,&ScanPreviousFromSql::onLastRecord);
    connect(mNextBtn,&PushButton::clicked,this,&ScanPreviousFromSql::onNextRecord);
    connect(mOkBtn,&PushButton::clicked,this,&ScanPreviousFromSql::onAccept);
    connect(mNotOkBtn,&PushButton::clicked,this,&ScanPreviousFromSql::onReject);
    connect(this, &ScanPreviousFromSql::accept, &loop, &QEventLoop::quit);
    connect(this, &ScanPreviousFromSql::reject, &loop, &QEventLoop::quit);
    connect(mSelection,&QItemSelectionModel::currentRowChanged,this,&ScanPreviousFromSql::onChangeRow);
}

void ScanPreviousFromSql::initLayout()
{
    QVBoxLayout * lay = new QVBoxLayout(this);

    QHBoxLayout * blay = new QHBoxLayout;
//    blay->addStretch();
//    blay->addWidget(mLastBtn);
//    blay->addStretch();
//    blay->addWidget(mNextBtn);
    blay->addStretch();
    blay->addWidget(mOkBtn);
    blay->addStretch();
    blay->addWidget(mNotOkBtn);
    blay->addStretch();
    lay->addWidget(mView);

    lay->addLayout(blay);
    INIT_FONT;
    INIT_WINDOW_MINSIZE;

    //setWindowModality(Qt::ApplicationModal); // 应用模态才能阻塞其他窗口显示
}

void ScanPreviousFromSql::setCurrentUser(const QString& user)
{
    QStringList encryusers;
    auto statement = QString(SelectFieldFromTable).arg(ExperConfigTableFields.user).
            arg(ExperGeneralConfigTableName);

    SqlReadWrite * pointer = nullptr;
    if (CurrentSqliteType) pointer = SqliteReadWritePointer;
    else pointer = MysqlReadWritePointer;
    pointer->query(statement);
    auto query = pointer->lastQuery();
    while (query.next()) {
        auto encryuser = query.value(0).toString();
        if (decry_color(encryuser) == user)
            encryusers.append(encryuser);// 要在这里重新筛选,注意是找到数据库内的加密形式(可能多条)
    }

    if (encryusers.isEmpty()) // 也可能为空,没有这个用户的记录,直接不显示即可
        mModel->setFilter(QString(FilterUser).arg(user));  // user = 'xx'都可以肯定没有
    else if (encryusers.count() == 1)
        mModel->setFilter(QString(FilterUser).arg(encryusers.first()));
    else {
        QString statement;
        foreach(auto encryuser,encryusers) {
            statement.append(QString(FilterUser).arg(encryuser));
            statement.append(" or ");
        }
        statement.chop(QString(" or ").count());
        mModel->setFilter(statement);
    }
    mModel->select(); //只显示当前用户的记录

    QModelIndex start = mModel->index(0,0);
    QModelIndex end = mModel->index(0,mModel->columnCount()-1);
    QItemSelection selection (start,end);
    mSelection->select(selection,QItemSelectionModel::ClearAndSelect);
}

int ScanPreviousFromSql::columnIndex(const QString &name)
{
    for(int col = 0; col < mModel->columnCount(); ++col) {
        auto field = mModel->headerData(col,Qt::Horizontal).toString();
        if (name == field)
            return col;
    }
    return -1;
}

void ScanPreviousFromSql::closeEvent(QCloseEvent *event)
{
    if (quitstate == QuitState::Accepted) emit accept();
    else emit reject(); // 点取消或者没点过确实直接关闭的都是reject
    event->accept();
}
