#include "../../inc/flow/scanwellconfig.h"

ScanWellConfig::ScanWellConfig(QWidget *parent) : GradientHiddenWidget(parent)
{
    initObject();
    initAttributes();
    initLeftLayout();
    initRightLayout();
    initConnections();

    auto bottomlay = new QHBoxLayout;
    bottomlay->addWidget(mLeftBox);
    bottomlay->addWidget(mRightBox);
    mainlay->addWidget(mPattern);
    mainlay->addStretch();
    mainlay->addLayout(bottomlay);
}

void ScanWellConfig::initLeftLayout()
{
    QHBoxLayout * lay = new QHBoxLayout;

    QVBoxLayout * rlay = new QVBoxLayout;
    QGridLayout * glay = new QGridLayout;
    glay->addWidget(mAddGroup,0,0);
    glay->addWidget(mGroupName,0,1);
    glay->addWidget(mRemoveGroup,1,0);
    glay->addWidget(mRemoveAllGroups,1,1);
    rlay->addStretch();
    rlay->addLayout(glay);

    lay->addWidget(mGroupList);
    lay->addLayout(rlay);
    mLeftBox->setLayout(lay);
}

void ScanWellConfig::initRightLayout()
{
    QHBoxLayout * lay = new QHBoxLayout;

    QHBoxLayout * rlay = new QHBoxLayout;
    QGridLayout * glay = new QGridLayout;
    glay->addWidget(mCurrentGroup,0,0);
    glay->addWidget(mAddPoint,1,0);
    glay->addWidget(mPointName,1,1);
    glay->addWidget(mRemovePoint,2,0);
    glay->addWidget(mRemoveAllPoints,2,1);
    rlay->addStretch();
    rlay->addLayout(glay);
    rlay->addStretch();

    lay->addWidget(mPointList);
    lay->addLayout(rlay);
    mRightBox->setLayout(lay);
}

void ScanWellConfig::initAttributes()
{
    mPattern->toggleState(Pattern::BlankState);
    mPattern->setPatternSize(2,3);

    mRightBox->setEnabled(false);

    mGroupList->setEditTriggers(QListWidget::NoEditTriggers);
    mPointList->setEditTriggers(QListWidget::NoEditTriggers);

//    mGroupList->addItems(QStringList()<<"A"<<"B"<<"C");
//    mGroupData->addGroup(0,QPointList()<<QPoint(1,1)<<QPoint(3,4)<<QPoint(2,5),
//                         QStringList()<<"A1"<<"A2"<<"A3");
//    mGroupData->addGroup(1,QPointList()<<QPoint(6,1)<<QPoint(3,7)<<QPoint(3,9),
//                         QStringList()<<"B1"<<"B2"<<"B3");
//    mGroupData->addGroup(2,QPointList()<<QPoint(7,6)<<QPoint(4,4)<<QPoint(5,11),
//                         QStringList()<<"C1"<<"C2"<<"C3");
//    mGroupData->setGroupName(0,"A");
//    mGroupData->setGroupName(1,"B");
//    mGroupData->setGroupName(2,"C");
//    mPattern->setSelectedPoint(1,1);
//    mPattern->setSelectedPoint(3,4);
//    mPattern->setSelectedPoint(2,5);
//    mPattern->setSelectedPoint(6,1);
//    mPattern->setSelectedPoint(3,7);
//    mPattern->setSelectedPoint(3,9);
//    mPattern->setSelectedPoint(7,6);
//    mPattern->setSelectedPoint(4,4);
//    mPattern->setSelectedPoint(5,11);

    //mPointList->addItems(QStringList()<<"A1"<<"A2"<<"A3");

    mCurrentGroup->setAlignment(Qt::AlignLeft);

    header->setText(tr("选择成像轨迹"));
}

void ScanWellConfig::initObject()
{
    mGroupData = new ScanGroupData;

    mPattern = new Pattern;
    mLeftBox = new GroupBox(tr("添加组"));
    mRightBox = new GroupBox(tr("添加点"));

    mGroupList = new QListWidget;
    mAddGroup = new PushButton(tr("添加"));
    mGroupName = new LineEdit(tr("请指定组的名称"));
    mRemoveGroup = new PushButton(tr("移除"));
    mRemoveAllGroups = new PushButton(tr("移除全部"));

    mCurrentGroup = new Label(tr("当前组: "));
    mAddPoint = new PushButton(tr("添加"));
    mPointName = new LineEdit(tr("请指定点的名称"));
    mRemovePoint = new PushButton(tr("移除"));
    mRemoveAllPoints = new PushButton(tr("移除全部"));
    mPointList = new QListWidget;
}

void ScanWellConfig::initConnections()
{
    connect(mAddGroup,&PushButton::clicked,this,&ScanWellConfig::onAddGroup);
    connect(mRemoveGroup,&PushButton::clicked,this,&ScanWellConfig::onRemoveGroup);
    connect(mRemoveAllGroups,&PushButton::clicked,this,&ScanWellConfig::onRemoveAllGroups);
    connect(mAddPoint,&PushButton::clicked,this,&ScanWellConfig::onAddPoint);
    connect(mRemovePoint,&PushButton::clicked,this,&ScanWellConfig::onRemovePoint);
    connect(mRemoveAllPoints,&PushButton::clicked,this,&ScanWellConfig::onRemoveAllPoints);
    connect(mGroupList,&QListWidget::currentRowChanged,this,&ScanWellConfig::onGroupCurrentRowChanged);
}

void ScanWellConfig::onAddGroup()
{
    auto name = mGroupName->text().simplified();
    if (name.isEmpty()){
        QMessageBox::critical(this,tr("错误"),tr("组名称不应为空!"));
        return;
    }
    if (!mGroupList->findItems(name,Qt::MatchCaseSensitive).isEmpty()){
        QMessageBox::critical(this,tr("错误"),tr("组不允许重名!"));
        return;
    }

    static int group = 0;
    ListWidgetItem * item = new ListWidgetItem(name);
    item->setData(GroupRole,group); // 把所属组别存入方便当前行切换时使用
    mGroupList->addItem(item);
    mGroupList->setCurrentItem(item); // 添加1个就选中它,为了后面使用currentItem不异常
    mGroupData->setGroupName(group,name);
    group++; // 保证每个组索引都不会重复

    mRightBox->setEnabled(true); // 有一个组才能选择点
    mPattern->toggleState(Pattern::TickState); // 切为可选状态
    mCurrentGroup->setText(tr("当前组: %1").arg(name));

    // 每添加一个组,上限组数变化,为pattern尺寸减去所有组数已选择的点数
}

void ScanWellConfig::onRemoveGroup()
{
    auto row = mGroupList->currentRow();
    if (row<0) return;

     // row<0返回了,所以拿到组别用currentItem不会异常
    auto group = mGroupList->currentItem()->data(GroupRole).toUInt();
    mGroupData->removeGroup(group); // 把这个组所有的数据都清除
    mPointList->clear();
    mPattern->clearAllPoints();// 还要把pattern的当前组效果清除
    mPattern->clearMousePoint();
    auto item = mGroupList->takeItem(row); // 触发索引变化,当前行改变触发槽函数
    delete item;
    item = nullptr;

    if (mGroupList->count() < 1) {
        mRightBox->setEnabled(false); // 有一个组才能选择点
        mPattern->toggleState(Pattern::BlankState);
        mCurrentGroup->setText(tr("当前组: 无"));
        mPointList->clear();
        mPointName->clear();
    } else {
        mCurrentGroup->setText(tr("当前组: %1").arg(mGroupList->currentItem()->text()));
    }
}

void ScanWellConfig::onRemoveAllGroups()
{
    mGroupList->clear();
    mGroupData->clear();
    mPointList->clear();
    mPointName->clear();
    mGroupName->clear();
    mPattern->clearAllPoints();// 还要把pattern的所有组效果清除,选中的所有点清除
    mPattern->clearMousePoint(); // 鼠标选中的点也清除
    mRightBox->setEnabled(false); // 有一个组才能选择点
    mPattern->toggleState(Pattern::BlankState);
    mCurrentGroup->setText(tr("当前组: 无"));
}

void ScanWellConfig::onAddPoint()
{
    auto name = mPointName->text().simplified();
    if (name.isEmpty()){
        QMessageBox::critical(this,tr("错误"),tr("点名称不应为空!"));
        return;
    }
    if (!mPointList->findItems(name,Qt::MatchCaseSensitive).isEmpty() ){
        QMessageBox::critical(this,tr("错误"),tr("点不允许重名!"));
        return;
    }
    auto point = mPattern->currentMousePoint();
    if ( point.x()<0 || point.y() <0)
    {
        QMessageBox::critical(this,tr("错误"),tr("没有选择一个区域"));
        return;
    }
    auto points = mPattern->selectedPoints();
    if (points.contains(point))
    {
        QMessageBox::critical(this,tr("错误"),tr("不能选择重复的区域"));
        return;
    }
    // UI的判断已保证组内点和名称不重复
    // 但是除了组内不能重复,所有组的点位置都不能重复,名称可以重复
    if (mGroupData->pointInGroups(point)) {
        QMessageBox::critical(this,tr("错误"),tr("不能选择和其它组重复的区域"));
        return;
    }

    ListWidgetItem * item = new ListWidgetItem(name);
    mPointList->addItem(item);
    mPointList->setCurrentItem(item);//避免移除时访问异常
     // 当前组,用currentItem()可能没选过,所以onAddGroup内添加时就设定了currentItem保证不异常
    int group = mGroupList->currentItem()->data(GroupRole).toUInt();
    item->setData(GroupRole,group); // 存储组别信息
    item->setData(PointRole,point); // 存储位置信息

    // 组清除后没有组名数据,但是mGroupList还存在,用它的信息把组名重新赋值,不然丢失信息
    mGroupData->setGroupName(group,mGroupList->currentItem()->text());
    mGroupData->addPoint(group,point,name); // 给对应组添加点,数据保存好
    mPattern->setSelectedPoint(point); // 启动图案效果
    //LOG<<"points => "<<mGroupData->points(group) <<"\n"<<mPattern->selectedPoints(); // 后者不保证顺序
}

void ScanWellConfig::onRemovePoint()
{
    auto row = mPointList->currentRow();
    if (row<0) return;

    // 拿到事先存好的组别,这个组别和点在切换行时也要重新赋值
   auto group = mPointList->currentItem()->data(GroupRole).toUInt();
   auto point = mPointList->currentItem()->data(PointRole).toPoint();
   //LOG<<"group = "<<group<<" point = "<<point;
   mGroupData->removePoint(group,point); // 把这个组的点和名称移除
   mPattern->setSelectedPoint(point,false); // 移除的点取消效果
   mPattern->clearMousePoint();
   auto item = mPointList->takeItem(row); // 触发索引变化,当前行改变触发槽函数
   delete item;
   item = nullptr;
}

void ScanWellConfig::onRemoveAllPoints()
{
    mPointList->clear();
    int group = mGroupList->currentItem()->data(GroupRole).toUInt();
    mGroupData->removeGroup(group); // 把这个组所有的数据都清除
    mPattern->clearAllPoints();// 还要把pattern的当前组效果清除
    mPattern->clearMousePoint();
    mPointName->clear();
}

void ScanWellConfig::onGroupCurrentRowChanged(int row)
{
    //LOG<<(mGroupList->item(row) == nullptr); // takeItem时触发此函数,导致当前item=mullptr
    if (!mGroupList->item(row)){ // 必须判断
        mCurrentGroup->setText(tr("当前组: 无"));
        return;
    }

    mCurrentGroup->setText(tr("当前组: %1").arg(mGroupList->item(row)->text()));
    //auto group = mGroupList->currentItem()->data(GroupRole).toUInt(); // 拿到组别,currentItem()可能没选中
    auto group = mGroupList->item(row)->data(GroupRole).toUInt(); // 拿到组别,这样不会异常
    auto points = mGroupData->points(group);
    auto names = mGroupData->pointNames(group);
    mPointList->clear();// 清除pointlist
    mPointList->addItems(names.toList());  // 把当前组的点名称显示出来
    for (int r = 0; r < mPointList->count();++r) { // pointlist item的信息要重新存储
        mPointList->item(r)->setData(GroupRole,group); // mPointList组别信息和mGroupList当前项组别是一致的
        mPointList->item(r)->setData(PointRole,points.at(r));
    }
    mPattern->clearAllPoints(); // 清除原来的效果
    mPattern->clearMousePoint();
    mPattern->setSelectedPoints(points);//点效果显示出来
}

void ScanWellConfig::setPatternSize(int rows, int cols)
{
    mPattern->setPatternSize(rows,cols);
}

bool ScanWellConfig::hasEmptyGroup() const
{
    foreach(auto group,mGroupData->groups()) {
        if (!mGroupData->groupPointCount(group))
            return true;
    }
    // 可能出现组确实不存在,但是mGroupList还有列表项的情况,这样也是空组
    // 检测mGroupList的组名是否存在
    auto groupNames = mGroupData->groupNames();
    for(int i = 0; i < mGroupList->count(); ++ i) {
        if (!groupNames.contains(mGroupList->item(i)->text()))
            return true;
    }
    return false;
}

bool ScanWellConfig::allEmptyGroup()
{
    if (!mGroupList->count()) return false; // 还没有列表项的留给下一级判断,弹出至少添加一个组

    // 只判断列表项存在时是不是都是空组
    auto groupNames = mGroupData->groupNames(); // 添加组和添加点时都要更新它
    //LOG<<"groupNames = "<<groupNames;
    for(int i = 0; i < mGroupList->count(); ++ i) {
        if (groupNames.contains(mGroupList->item(i)->text()))
            return false; // 有一个包含就不是全员空组
    }
    return true;
}

int ScanWellConfig::groupCount() const
{
    // 如果一个组添加了几个点再移除全部点,这个组被remove了,但是列表项没有变
    //Q_ASSERT(mGroupData->groupCount() == mGroupList->count());
    return mGroupData->groupCount();// 所以以实际为准
}

int ScanWellConfig::groupPointCount(int group) const
{
    return mGroupData->groupPointCount(group);
}

int ScanWellConfig::pointCount() const
{
    int count = 0;
    foreach(auto group,mGroupData->groups()) {
        count += mGroupData->groupPointCount(group);
    }
    //LOG<<"point's count = "<<count;
    return count;
}

GroupDataVector ScanWellConfig::groupDatas() const
{
    LOG<<"get groupDatas";
    return mGroupData->groupDatas();
}

void ScanWellConfig::clearState()
{
    // 清除ui信息
    mGroupList->clear();
    mPointList->clear();
    mGroupName->clear();
    mPointName->clear();
    mRightBox->setEnabled(false);
    // 清除存储的数据
   mGroupData->clear();
}
