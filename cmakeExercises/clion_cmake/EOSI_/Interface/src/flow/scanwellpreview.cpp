#include "../../inc/flow/scanwellpreview.h"

ScanWellPreview::ScanWellPreview(QWidget *parent) : GradientHiddenWidget(parent)
{
    initObject();
    initAttributes();
    initConnections();
    initLeftLayout();
    initRightLayout();

    QHBoxLayout * lay = new QHBoxLayout;
    lay->addWidget(mLeftBox);
    //lay->addStretch();
    lay->addWidget(mRightBox);
    header->setText(tr("预览成像轨迹"));
    mainlay->addWidget(mPattern);
    mainlay->addStretch();
    mainlay->addLayout(lay);
    mainlay->addStretch();
    //setFakeData();
}

void ScanWellPreview::onDeletePoint()
{ // 删除不想要的孔
    int ret = QMessageBox::warning(this,tr("警告"),tr("确定要删除吗?"),
                                   QMessageBox::Yes|QMessageBox::No);
    if (ret == QMessageBox::No)
        return;

    auto pos = mPattern->currentMousePoint();
    if (pos.x() < 0 || pos.y() < 0) {
        QMessageBox::information(this,tr("消息"),tr("请先选择一个孔!"));
        return;
    }

    if (!mPattern->isGroupPoint(pos)) {
        QMessageBox::information(this,tr("消息"),tr("请选择一个有效的孔!"));
        return;
    }

    // 重新更新mSortPointDatas和mGroupData就可以
    // 然后调用setGroupDatas更新UI信息，以及分好的mGroupNames、mPointVector、mPointNameVector，还有排序数据
    // 删除孔=>坐标信息=>遍历组遍历点列表得到索引信息=>删除这个点坐标和名称=>如果点没了继续删除这个组
    auto groupIndex = getPointIndexInGroupDatas(pos);
    LOG<<"index = "<<groupIndex.second<<" group = "<<groupIndex.first;
    auto groupPoints = mGroupData.at(groupIndex.first).points;
    groupPoints.remove(groupIndex.second);


    if (groupPoints.isEmpty()) { // 这个组的点都没了,直接删除组就可以了
        mGroupData.remove(groupIndex.first);
    } else {
        auto groupData = mGroupData.at(groupIndex.first); // 这个组的数据
        auto groupNames = groupData.pointNames;
        groupNames.remove(groupIndex.second);

        groupData.points = groupPoints; // 移除点后的新数据
        groupData.pointNames = groupNames;
        mGroupData[groupIndex.first] = groupData;
    }

    if (mGroupData.isEmpty() || pos == mPattern->signedPoint())
        mPattern->clearSignedPoint();

    mPicture->clearHistoryPixmaps();
    setGroupDatas(mGroupData); // 更新信息

    //

}

QPair<int,int>  ScanWellPreview::getPointIndexInGroupDatas(QCPoint point) const
{ // 根据坐标信息拿到所在组和所在组点列表的索引
    QPair<int,int>  groupIndex = qMakePair(-1,-1);
    for(int group = 0; group < mGroupNames.count(); ++ group) {
        auto groupPoints = points(group);
        for(int i = 0; i < groupPoints.count(); ++i) {
            if (groupPoints.at(i) == point ) {
                groupIndex.first = group;
                groupIndex.second = i;
                break;
            }
        }
    }

    return groupIndex;
}

void ScanWellPreview::onPreview()
{
    updateInfo();
}

void ScanWellPreview::getSortPointDatas()
{ // 预览是从左到右从上到下依次预览的，所以需要根据点位置从新排序
    // 不过要把点的所有数据一块带上，所以定义了PointData结构体
    PointData d;
    mSortPointDatas.clear();
    for(int i = 0 ; i < mPointVector.count();++i)
        for(int j = 0 ; j < mPointVector.at(i).count();++j) {
            d.group = mGroupNames.at(i);
            d.pos = mPointVector.at(i).at(j);
            d.name = mPointNameVector.at(i).at(j);
            d.order = j+1; // 本组内的次序
            mSortPointDatas.append(d);
    }
    auto func = [=](const PointData&d1,const PointData&d2)->bool{
        auto p1 = d1.pos;
        auto p2 = d2.pos;
        if (p1.x() == p2.x()) {
            return p1.y()<= p2.y();
        } else if (p1.x() < p2.x()) return true;
        else return false;
    };

    std::sort(mSortPointDatas.begin(),mSortPointDatas.end(),func);
}

void ScanWellPreview::printSortPointDatas()
{
    for(int i = 0 ; i < mSortPointDatas.count();++i) {
        auto p = mSortPointDatas.at(i);
        LOG<<"group = "<<p.group<<" pos = "<<p.pos
          <<" name = "<<p.name<<" order = "<<p.order;
    }
}

void ScanWellPreview::onPatternClicked(const QPoint &point)
{ // 找到指定point的所属组名,名称和次序,因为点是独一无二的,point在排序后的位置
    QString groupname;
    QString pname;
    int order = 0;
    for(int i = 0; i < mGroupNames.count();++i) {
        auto ppos  = points(i); // 该组的点列表
        for(int j = 0; j < ppos.count(); ++j) {
            auto pos = ppos.at(j);
            if (pos == point) { // 匹配到了
                groupname = mGroupNames.at(i);
                pname = pointNames(i).at(j);
                order = j+1;
            }
        }
    }
    mGroupName->setText(tr("%1").arg(groupname));
    mPointPos->setText(tr("[%1,%2]").arg((QChar)(point.x()+65)).arg(point.y()+1));
    mPointName->setText(tr("%1").arg(pname));
    mPointOrder->setText(tr("%1").arg(order));

    int index = -1;
    if (mSortPointDatas.isEmpty()) getSortPointDatas();
    for(int i = 0 ;i < mSortPointDatas.count(); ++i) {
        auto sd = mSortPointDatas.at(i);
        if (sd.pos == point) {
            index = i; // 根据点击的坐标找到顺序点列表所在的位置,也是图片的索引位置
            break;
        }
    }
    mPicture->setPixmap(index);
}

void ScanWellPreview::updatePatternSignedPoint(int index)
{ // 图片前后返回图片的索引,根据索引得到点,渲染点
    auto point = mSortPointDatas.at(index).pos;
    //mPattern->setSignedColor(Qt::blue);
    mPattern->setSignedPoint(point);
}

void ScanWellPreview::setGroupDatas(const GroupDataVector &d)
{
    //LOG<<"set groupDatas";
    mGroupData = d;
    splitGroupDatas();
    getSortPointDatas();
    //printSortPointDatas();
    drawGroupPoints();
    showAllInfo();
}

void ScanWellPreview::splitGroupDatas()
{ // 把传进来的数据分出来
    GroupData gd;
    mGroupNames.clear();
    mPointVector.clear();
    mPointNameVector.clear();

    for(int i = 0 ;i < mGroupData.count(); ++i) {
        gd = mGroupData.at(i);
        mGroupNames.append(gd.groupName);
        mPointVector.append(gd.points);
        mPointNameVector.append(gd.pointNames);
    }
    //LOG<<"split groupDatas";
}

void ScanWellPreview::drawGroupPoints()
{
    // 如果不启用分组绘制这样做即可,前提是state为SelectedState
    //mPattern->setSelectedPoints(points(0));
    //mPattern->setSelectedPoints(points(1));
    //mPattern->setSelectedPoints(points(2));

    // 启用分组绘制
    //mPattern->setGroupColors(QColorlist()<<Qt::red<<Qt::blue<<Qt::green);
    auto gc = mGroupData.count();
    mPattern->clearGroupPoints();
    mPattern->setGroupColors(getClassicColors(gc));
    for(int i = 0; i <gc; ++i ) // 每组的
        mPattern->setGroupPoint(points((i)),i); // 拿到指定组的点列表然后绘制
    //LOG<<"draw group points";
}

void ScanWellPreview::updateInfo()
{ // 遍历所有点，点的信息都已经存好了
    mPicture->clearHistoryPixmaps(); // 清除缓存图片
    mPattern->blockSignals(true); // 预览过程阻塞鼠标信号不允许点击

    QEventLoop loop;
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &loop,&QEventLoop::quit); // 超时就停止
    timer.start(1100);
    for(int i = 0; i < mSortPointDatas.count(); ++i){
        auto p = mSortPointDatas[i];
        auto x = (QChar)(p.pos.x()+65);
        mPattern->setSignedPoint(p.pos);
        //mPattern->drawRandomPoints(mViews);
        mGroupName->setText(tr("%1").arg(p.group));
        mPointPos->setText(tr("[%1,%2]").arg(x).arg(p.pos.y()+1));
        mPointName->setText(tr("%1").arg(p.name));
        mPointOrder->setText(tr("%1").arg(p.order));
        auto path = tr(PREVIEW_TEST_PATH).arg(i+1); // 添加的图片是缩放图片,path是原始图片路径
        mPicture->appendPixmap(*loadPixmapPointerByImageReader(path,mPicture->size()),path);
        loop.exec();
    }
    timer.stop();
    if (mSortPointDatas.count()>1) // 2张及以上才可以有返回
        mPicture->setBackwardEnabled(true);
    mPattern->blockSignals(false);
}

void ScanWellPreview::showAllInfo()
{
    QString all = tr("信息总览: \n\n"); // all
    for(int i = 0; i < mGroupNames.count();++i) {
            all += mGroupNames.at(i)+":\t";
            auto ppos  = points(i);
            auto pname = pointNames(i);
            for(int j = 0; j < ppos.count(); ++j) {
                  auto pos = ppos.at(j);
                  auto name = pname.at(j);
                  all += tr("[%1,%2,%3,%4] =>").arg(QChar(pos.x()+65)).arg(pos.y()+1).arg(name).arg(j+1);
            }
            all.chop(2);
            all+="\n\n";
    }
    all += tr("每孔视野数: %1").arg(mViews);
    mAllInfo->setText(all);
    LOG<<"show all info";
}

QPointVector ScanWellPreview::points(int group) const
{// 拿到指定组的点列表
    return mPointVector.at(group);
}

QStringVector ScanWellPreview::pointNames(int group) const
{
    return mPointNameVector.at(group);
}

void ScanWellPreview::clearState()
{
    // 清除数据信息
    mGroupData.clear();
    mGroupNames.clear();
    mPointVector.clear();
    mPointNameVector.clear();
    mSortPointDatas.clear();
    // 清除UI信息
    mPattern->clearAllPoints();
    mPattern->clearMousePoint();
    mPattern->clearSignedPoint();
    //mPattern->disableDrawRandomPoints();
}

void ScanWellPreview::initObject()
{
    mPattern = new Pattern;
    mDeletePoint = new QAction(tr("删除孔"));
    mLeftBox = new GroupBox(tr("信息"));
    mRightBox = new GroupBox(tr("图片"));
    mGroupName = new Label;
    mPointPos = new Label;
    mPointName = new Label;
    mPointOrder = new Label;
    mAllInfo = new TextEdit;
    mPreviewBtn = new PushButton(tr("预览"));
    mPicture = new ImageViewer;
}

void ScanWellPreview::initAttributes()
{
    mViews = 4;

    mPattern->toggleState(Pattern::GroupState);
    mPattern->setPatternSize(8,12);
    mPattern->addAction(mDeletePoint);
    mPattern->setContextMenuPolicy(Qt::ActionsContextMenu);

    mGroupName->setAlignment(Qt::AlignLeft);
    mPointPos->setAlignment(Qt::AlignLeft);
    mPointName->setAlignment(Qt::AlignLeft);
    mPointOrder->setAlignment(Qt::AlignLeft);

    mAllInfo->hideTitle();
    mAllInfo->clearText();
    mAllInfo->setReadOnly(true);

    mRightBox->setMaximumWidth(400);
}

void ScanWellPreview::initConnections()
{
    connect(mPreviewBtn,&PushButton::clicked,this,&ScanWellPreview::onPreview);
    connect(mPattern,&Pattern::mouseClicked,this,&ScanWellPreview::onPatternClicked);
    connect(mPicture,&ImageViewer::indexChanged,this,&ScanWellPreview::updatePatternSignedPoint);
    connect(mDeletePoint,&QAction::triggered,this,&ScanWellPreview::onDeletePoint);
}

void ScanWellPreview::initLeftLayout()
{
    QFormLayout * gridlay = new QFormLayout;
    gridlay->setSpacing(5);
    gridlay->addRow(tr("组名: "),mGroupName);
    gridlay->addRow(tr("坐标: "),mPointPos);
    gridlay->addRow(tr("名称: "),mPointName);
    gridlay->addRow(tr("次序: "),mPointOrder);

    QVBoxLayout * vlay = new QVBoxLayout;
    vlay->addStretch();
    vlay->addLayout(gridlay);
    vlay->addWidget(mPreviewBtn);
    vlay->addStretch();

    QHBoxLayout * lay = new QHBoxLayout;
    lay->addLayout(vlay);
    lay->addWidget(mAllInfo);
    //lay->addStretch();
    mLeftBox->setLayout(lay);
}

void ScanWellPreview::initRightLayout()
{
    QHBoxLayout * lay = new QHBoxLayout;
    lay->addWidget(mPicture);
    mRightBox->setLayout(lay);
}

void ScanWellPreview::setPatternSize(int rows, int cols)
{
    mPattern->setPatternSize(rows,cols);
}

void ScanWellPreview::setViews(int views)
{
    mViews = views;
}

void ScanWellPreview::setFakeData()
{
    GroupDataVector data;
    GroupData d;
    d.groupName = "A";
    d.points = QPointVector()<<QPoint(5,4)<<QPoint(2,3)<<QPoint(3,5);
    d.pointNames = QStringVector()<<"a1"<<"a2"<<"a3";
    data.append(d);
    d.groupName = "B";
    d.points = QPointVector()<<QPoint(6,4)<<QPoint(7,1)<<QPoint(1,2);
    d.pointNames = QStringVector()<<"b1"<<"b2"<<"b3";
    data.append(d);
    d.groupName = "C";
    d.points = QPointVector()<<QPoint(6,2)<<QPoint(1,11)<<QPoint(3,9)<<QPoint(7,10);
    d.pointNames = QStringVector()<<"c1"<<"c2"<<"c3"<<"c4";
    data.append(d);
    setGroupDatas(data);
}
