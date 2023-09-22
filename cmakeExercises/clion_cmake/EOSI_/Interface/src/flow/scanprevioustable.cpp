#include "../../inc/flow/scanprevioustable.h"

ScanPreviousTable::ScanPreviousTable(QWidget *parent):QWidget(parent)
{
    init();
}

ScanPreviousTable::ScanPreviousTable(int rows,int cols,QWidget *parent):QWidget(parent)
{ 
    init();
    mModel->setRowCount(rows);
    mModel->setColumnCount(cols);
}

void ScanPreviousTable::init()
{
    mView = new TableView;
    mModel = new ScanPreviousTableModel(mView);
    mSelection = new QItemSelectionModel(mModel);

    mAppendRow = new QAction(tr("添加行"));
    mDeleteRow = new QAction(tr("删除行"));
    mClearData = new QAction(tr("清空"));
    mRefresh = new QAction(tr("刷新"));

    setHeaderData(QStringList()<<"group"<<"point.x"<<"point.y"<<"point.name"<<"point.order");
    mView->setEditTriggers(QTableView::DoubleClicked);
    mView->setItemDelegateForColumn(PointXColumn,new TableViewDelegateInt(0,384));
    mView->setItemDelegateForColumn(PointYColumn,new TableViewDelegateInt(0,384));
    mView->setItemDelegateForColumn(PointOrderColumn,new TableViewDelegateInt(0,384));
    mView->setContextMenuPolicy(Qt::ActionsContextMenu);
    mView->addAction(mAppendRow);
    mView->addAction(mDeleteRow);
    mView->addAction(mClearData);
    mView->addAction(mRefresh);

    setSectionBackgroundColor();

    mView->setModel(mModel);
    mView->setSelectionModel(mSelection);

    QVBoxLayout * lay = new QVBoxLayout(this);
    lay->setMargin(0);
    lay->setSpacing(0);
    lay->addWidget(mView);

    resize(mView->size());
    INIT_FONT;

    connect(mSelection,&QItemSelectionModel::currentRowChanged,this,&ScanPreviousTable::onCurrentRowChanged);
    connect(mAppendRow,&QAction::triggered,this,&ScanPreviousTable::onAppendRow);
    connect(mDeleteRow,&QAction::triggered,this,&ScanPreviousTable::onDeleteRow);
    connect(mRefresh,&QAction::triggered,this,&
            ScanPreviousTable::onRefresh);
    connect(mClearData,&QAction::triggered,this,&ScanPreviousTable::clearData);
    connect(mClearData,&QAction::triggered,this,&ScanPreviousTable::dataCleared); // 通知外部把Pattern更新
    connect(mModel,&ScanPreviousTableModel::itemChanged,this,&ScanPreviousTable::onItemChanged);

}


QVariant ScanPreviousTable::data(const QModelIndex &index, int role) const
{
    if (!mModel) return QVariant();
    return mModel->data(index,role);
}

QVariant ScanPreviousTable::data(int row, int col, int role) const
{
    if (!mModel) return QVariant();
    return mModel->data(index(row,col),role);
};

bool ScanPreviousTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mModel) return false;
    return mModel->setData(index,value,role);
};

bool ScanPreviousTable::setData(int row, int col, const QVariant &value, int role)
 {
    if (!mModel) return false;
    return mModel->setData(index(row,col),value,role);
};

void ScanPreviousTable::setHeaderData(const QStringList&labels,Qt::Orientation oriention)
{
    if (oriention == Qt::Horizontal)
        mModel->setHorizontalHeaderLabels(labels);
    else mModel->setVerticalHeaderLabels(labels);
}

void ScanPreviousTable::setRowData(int row,const QVariantList& rowValues,int role)
{
    auto c = rowValues.count();
    if (c > mModel->columnCount()) return; // 数量不能超过实际列数,否则越界
    for(int col = 0; col < c; ++col) {
        setData(row,col,rowValues.at(col),role);
    }
}

void ScanPreviousTable::setRowData(int row,const QStringList& rowValues)
{ // 一个便捷方法只设置文本
    QVariantList list;
    foreach(auto val, rowValues)
        list.append(val);
    setRowData(row,list,Qt::EditRole);
}

QModelIndex ScanPreviousTable::index(int row, int col) const
{
    if (!mModel) return QModelIndex();
    return mModel->index(row,col);
}

void ScanPreviousTable::onItemChanged(QStandardItem * item)
{
//    auto row = item->row();
//    auto group = data(row,GroupNameColumn).toString();
//    auto p_x = data(row,PointXColumn).toString();
//    auto p_y = data(row,PointYColumn).toString();
//    if (isNumeric(p_x) && isNumeric(p_y) && !group.isEmpty()) {
//        auto x = p_x.toUInt()-1; // 表格的索引起点和实际索引起点不一样
//        auto y = p_y.toUInt()-1;
//        //LOG<<"row["<<row<<"] group{"<<group<<"} ("<<x<<","<<y<<")";
//        emit itemDataChanged(group,x,y);
//    }
    // 不用传递了,因为更新图案状态只需要组的数量和点列表,这个通过其他函数可以重新拿出来
    emit itemDataChanged();
    Q_UNUSED(item);
}

void ScanPreviousTable::onAppendRow()
{
    appendRowData(QStringList());
    // 不需要更新代理,自动对新增行生效
}

void ScanPreviousTable::onDeleteRow()
{
    auto row = mSelection->selectedIndexes().at(0).row();
    mModel->removeRow(row);
}

void ScanPreviousTable::onRefresh()
{
   // 1. 不为空的行,但是又存在空单元格,提示信息(对于x,y,order是因为更换size后会为空)
    if (!rowCompeled()) {
        QMessageBox::warning(this,tr("警告"),tr("行的信息不完整!"));
        return;
    }

    // 2.次序还必须保证从1-n，例如1,2,3,5或 4,5,6,7都是不合法的
    if (!orderValid()) {
        QMessageBox::warning(this,tr("警告"),tr("次序有误,必须从1开始且不重复!"));
        return;
    }

    // 3. 符合条件后 更新表格颜色和图案颜色,交给外部
    emit tableRefreshed();
}

bool ScanPreviousTable::rowCompeled()
{
    for (int row = 0; row < mModel->rowCount(); ++ row) {
        auto group = data(row,GroupNameColumn).toString();
        auto x = data(row,PointXColumn).toUInt();
        auto y = data(row,PointYColumn).toUInt();
        auto name = data(row,PointNameColumn).toString();
        auto order = data(row,PointOrderColumn).toUInt();
        bool r1 = group.isEmpty() && (!x) && (!y) && name.isEmpty() && (!order);//空行
        bool r2 = (!group.isEmpty()) && x && y && (!name.isEmpty()) && order; // 满行
        //qDebug()<<group<<x<<y<<name<<order<<r1<<r2;
        if (!(r1||r2)) return false;// 是空行或者满行都可以,否则直接返回不完整
    }
    return true;
}

bool ScanPreviousTable::orderValid()
{
    foreach(auto orders ,groupPointOrders()) {
        std::sort(orders.begin(),orders.end()); // 排序后必须从1开始对应相等
        //qDebug()<<orders;
        for(int i = 1; i <= orders.count(); ++i) {
            if (orders.at(i-1) != i)
                return false;
        }
    }
    return true;
}

void ScanPreviousTable::onCurrentRowChanged(const QModelIndex & current)
{ // 当前选择的行变化时把坐标发出去用于更新Pattern的signed标记位置
    auto row = current.row();
    auto x = data(row,1).toUInt()-1;
    auto y = data(row,2).toUInt()-1;
    emit currentPoint(x,y); //选择行时把对应的坐标发出去
}

void ScanPreviousTable::appendRowData(const QStringList& rowValues)
{
    auto c = rowValues.count();
    if (c == 0) {
        QList<QStandardItem*> items;
        for(int i = 0; i < c; ++i) {
            items.append(new QStandardItem());
        }
        mModel->appendRow(items);
        return;
    }

    if (c > mModel->columnCount()) return; // 数量不能超过实际列数,否则越界

    QList<QStandardItem*> items;
    for(int i = 0; i < c; ++i) {
        items.append(new QStandardItem(rowValues.at(i)));
    }

    mModel->appendRow(items);
}

void ScanPreviousTable::appendRowData(const QStringList& rowValues,const QColor& color,int colorRole)
{ // 指定这行的颜色
    auto c = rowValues.count();
    if (c > mModel->columnCount()) return; // 数量不能超过实际列数,否则越界

    if (colorRole != Qt::ForegroundRole && colorRole != Qt::BackgroundRole)
        colorRole = Qt::ForegroundRole;

    QList<QStandardItem*> items;
    for(int i = 0; i < c; ++i) {
        auto item = new QStandardItem(rowValues.at(i));
        item->setData(color,colorRole);
        items.append(item);
    }

    mModel->appendRow(items);
}

void ScanPreviousTable::clearData()
{
    mModel->blockSignals(true); // 会触发itemChanged造成死锁
    for(int i = 0; i < mModel->rowCount(); ++ i) {
        for(int j = 0; j < mModel->columnCount(); ++j)
            mModel->clearItemData(index(i,j));
    }
    mModel->blockSignals(false);
    //mModel->clear(); // 这样会把表结构整个清除,只需要清除数据即可
}

void ScanPreviousTable::clear()
{
    mModel->blockSignals(true);
    mModel->clear(); // 表头数据要恢复
    setHeaderData(QStringList()<<"group"<<"point.x"<<"point.y"<<"point.name"<<"point.order");
    mModel->blockSignals(false);
}

void ScanPreviousTable::setSectionBackgroundColor(QCColor color)
{
    mView->setStyleSheet(QString("QTableView {selection-color : %1; selection-background-color : %1;}")
                         .arg(color.name()));
}

void ScanPreviousTable::updateDelegateIntRange(int row, int col)
{ // 更新代理的范围
    auto delegate1 = static_cast<TableViewDelegateInt*>(mView->itemDelegateForColumn(PointXColumn));
    auto delegate2 = static_cast<TableViewDelegateInt*>(mView->itemDelegateForColumn(PointYColumn));
    auto delegate4 = static_cast<TableViewDelegateInt*>(mView->itemDelegateForColumn(PointOrderColumn));
    delegate1->setRange(1,row); // col是行数,point.x的范围是行数
    delegate2->setRange(1,col);
    delegate4->setRange(1,row*col);
}

QGroupNameVector ScanPreviousTable::groupNames() const
{
    QGroupNameVector groupVector;
    for(int row = 0; row < mModel->rowCount(); ++row) {
        auto group = data(row,GroupNameColumn).toString();
        if (!group.isEmpty())
            if (!groupVector.contains(group)) {
                groupVector.append(group);
            }
    }
    //LOG<<"table's groupnames = "<<groupVector;
    return groupVector;
}

int ScanPreviousTable::groupCount() const
{
    int count = 0;
    count = groupNames().count();
    return count;
}

QPointVector ScanPreviousTable::groupPoints(QCString group) const
{
    QPointVector pointVector;

    auto groups = groupNames();
    if (!groups.contains(group))
        return pointVector;

    for(int row = 0; row < mModel->rowCount(); ++row) {
        auto g = data(row,0).toString();
        if (group == g) { // 只要这组的
            auto px = data(row,PointXColumn).toString();
            auto py = data(row,PointYColumn).toString();
            if (isNumeric(px) && isNumeric(py)) { // 是数字保证此时的x,y都是数字
                auto x = px.toUInt()-1;
                auto y = py.toUInt()-1;
                pointVector.append(QPoint(x,y));
            }
        }
    }
    //LOG<<"table's points = "<<pointVector<<" with "<<group;
    return  pointVector;
}

QPointNameVector ScanPreviousTable::groupPointNames(QCString group) const
{
    QPointNameVector nameVector;

    auto groups = groupNames();
    if (!groups.contains(group))
        return nameVector;

    for(int row = 0; row < mModel->rowCount(); ++row) {
        auto g = data(row,GroupNameColumn).toString();
        if (group == g) { // 只要这组的
            auto pname = data(row,PointNameColumn).toString();
            nameVector.append(pname);
        }
    }

    //LOG<<"table's pointNames = "<<nameVector<<" with "<<group;
    return nameVector;
}

QVector<int> ScanPreviousTable::groupPointOrders(QCString group) const
{
    QVector<int> orderVector;

    auto groups = groupNames();
    if (!groups.contains(group))
        return orderVector;

    for(int row = 0; row < mModel->rowCount(); ++row) {
        auto g = data(row,GroupNameColumn).toString();
        if (group == g) { // 只要这组的
            auto o = data(row,PointOrderColumn).toUInt();
            orderVector.append(o);
        }
    }
    return orderVector;
}

QGroupPointVector ScanPreviousTable::groupPoints() const
{
    QGroupPointVector vec;
    auto groups = groupNames();
    foreach(auto g, groups) {
        vec.append(groupPoints(g)); // group不为空,但是point.x,point.y可能为空
    }
    //LOG<<"table's points = "<<vec;
    return vec;
}

QGroupPointNameVector ScanPreviousTable::groupPointNames() const
{
    QGroupPointNameVector vec;
    auto groups = groupNames();
    foreach(auto g, groups) {
        vec.append(groupPointNames(g)); // group不为空但是point.name可能为空
    }
    //LOG<<"table's pointNames = "<<vec;
    return vec;
}

QVector<QVector<int>> ScanPreviousTable::groupPointOrders() const
{
    QVector<QVector<int>> vec;
    auto groups = groupNames();
    foreach(auto g, groups) {
        vec.append(groupPointOrders(g)); // group不为空但是point.name可能为空
    }
    return vec;
}

void ScanPreviousTable::updateBackgroundColor(QCColorVector colors)
{ // 把不同组的颜色赋值,这个颜色和组对应
//    for(int row = 0; row < mModel->rowCount(); ++row) {
//        for(int col = 0; col < mModel->columnCount(); ++col) {
//           setData(row,col,QVariant(),Qt::BackgroundRole);
//        }
//    }
    auto groups = groupNames();
    auto count = colors.count();

    for(int row = 0; row < mModel->rowCount(); ++row) {
        auto g = data(row,GroupNameColumn).toString(); // 某个组
        auto idx = groups.indexOf(g); // 这个组在所有组中的位置
        if (idx > -1 && idx < count) {
            auto color = colors.at(idx); // 组对应的颜色
            for(int col = 0; col < mModel->columnCount(); ++col) {
               setData(row,col,color,Qt::BackgroundRole);
            }
        }
    }
}

