#include "../../inc/flow/scanpreviousmodifysecond.h"

ScanPreviousModifySecond::ScanPreviousModifySecond(QWidget *parent)
    :GradientHiddenWidget(parent)
{
    initObject();
    initLayout();
    initConnections();

    header->setText(tr("配置信息核对与调整(2)"));
    mainlay->addLayout(patternlay);
    //mainlay->addStretch();
    mainlay->addSpacing(10);
}

void ScanPreviousModifySecond::mapDataToUi(const ScanConfigData& d)
{
    mWellSize->setCurrentText(QString::number(d.wellsize));
    mTable->clear();
    auto gc = d.groupNames.count();
    //auto colors = getUniqueRandomColors(gc,200);
    auto colors = getClassicColors(gc);
    mPattern->setGroupColors(colors);
    for(int i = 0; i <gc; ++i ) // 把所有组的所有点设置进去,标记按组分隔
        mPattern->setGroupPoint(d.groupPointLists.at(i),i);

    for(int group = 0; group < gc; ++group) {
        auto gname = d.groupNames.at(group);
        for(int p = 0; p < d.groupPointLists.at(group).count(); ++p) {
            QStringList rowValues;
            auto point =  d.groupPointLists.at(group).at(p);
            auto pname = d.groupNameLists.at(group).at(p);
            rowValues.append(gname);
            rowValues.append(QString::number(point.x()+1));
            rowValues.append(QString::number(point.y()+1));
            rowValues.append(pname);
            rowValues.append(QString::number(p+1)); // 次序
            mTable->appendRowData(rowValues,colors.at(group),Qt::BackgroundRole);
        }
    }
}

void ScanPreviousModifySecond::setModifyData(const ScanConfigData& d)
{
    modifydata = d;
}

ScanConfigData ScanPreviousModifySecond::modifyData()
{
    return modifydata;
}

void ScanPreviousModifySecond::initObject()
{
    mWellSize = new ComboBox(QStringList()<<"6"<<"24"<<"96"<<"384");
    mSaveConfig = new QCheckBox(tr("是否保存为常用设置?"));
    mSaveConfig->setChecked(false);
    mSavePath = new LineEdit;
    mSavePath->setToolTip(tr("请给本配置设定一个名称,方便下次调用"));
    mSavePath->hide();
    mPattern = new Pattern;
    mTable = new ScanPreviousTable(0,5);
    mPattern->toggleState(Pattern::GroupWithoutClickState);
}

void ScanPreviousModifySecond::initLayout()
{
    auto toplay = new QHBoxLayout;
    toplay->addWidget(new QLabel("wellsize: "));
    toplay->addWidget(mWellSize);
    toplay->addWidget(mSaveConfig);
    toplay->addSpacing(10);
    toplay->addWidget(mSavePath);
    toplay->addStretch();

    patternlay = new QVBoxLayout;
    patternlay->addLayout(toplay);
    patternlay->addWidget(mPattern);
    patternlay->addWidget(mTable);
}

void ScanPreviousModifySecond::initConnections()
{
    connect(mWellSize,QOverload<int>::of(&ComboBox::currentIndexChanged),
            this,&ScanPreviousModifySecond::wellsizeChanged);
    connect(mSaveConfig,&QCheckBox::stateChanged,this,[=](int state){
        state==Qt::Checked? mSavePath->show():mSavePath->hide();
    });
    connect(mTable,&ScanPreviousTable::currentPoint, // 表格当前行
            this,&ScanPreviousModifySecond::signPatternPoint);
    connect(mTable,&ScanPreviousTable::dataCleared, // 表格清空的动作更新Pattern
            mPattern,&Pattern::clearGroupPoints);
    connect(mTable,&ScanPreviousTable::dataCleared, // 表格清空的动作更新Pattern
            mPattern,&Pattern::clearSignedPoint);
    connect(mTable,&ScanPreviousTable::itemDataChanged, // 表格更新单元格数据
            this,&ScanPreviousModifySecond::updatePatternGroupState);
    connect(mTable,&ScanPreviousTable::tableRefreshed, // 表格-刷新动作
            this,&ScanPreviousModifySecond::updatePatternGroupState);
    connect(this,&ScanPreviousModifySecond::currentWellSize, // 切换孔板尺寸
            mTable,&ScanPreviousTable::updateDelegateIntRange);

}

void ScanPreviousModifySecond::wellsizeChanged(int index)
{
    switch (index) {
        case 0: mPattern->setPatternSize(2,3);break;
        case 1: mPattern->setPatternSize(4,6);break;
        case 2: mPattern->setPatternSize(8,12);break;
        case 3: mPattern->setPatternSize(16,24);break;
        default:break;
    }
    mTable->clearData(); // 重新选孔版要清除表格数据
    mPattern->clearGroupPoints(); // 清除Pattern的状态
    mPattern->clearSignedPoint();
    emit currentWellSize(mPattern->patternSize().width(),mPattern->patternSize().height());
}

void ScanPreviousModifySecond::signPatternPoint(int row, int col)
{
    mPattern->setSignedPoint(row,col);
}

void ScanPreviousModifySecond::updatePatternGroupState()
{// 表格-刷新动作,要拿到组的数量和点重新设置图案,然后更新颜色
    auto groupNames = mTable->groupNames();
    //auto pointNames = mTable->groupPointNames();
    auto points = mTable->groupPoints();
    auto gc = groupNames.count();
    //auto colors = getUniqueRandomColors(gc,200);
    auto colors = getClassicColors(gc);
    mPattern->clearGroupPoints();
    mPattern->setGroupColors(colors);
    for(int i = 0; i <gc; ++i ) // 新的组更新
        mPattern->setGroupPoint(points.at(i),i);
    // 更新颜色
    mTable->blockSignals(true);
    mTable->updateBackgroundColor(colors); // 内部调用setData又会触发本函数先屏蔽信号
    mTable->blockSignals(false);

}

QString ScanPreviousModifySecond::flag() const
{ // saveToSql调用后才有意义,定义这个函数是为了rollback使用
    // 能够拿到保存时唯一的flag,也就是saveToSql内对savetime的赋值
    return modifydata.save_time.toString(ExperConfigTableFields.other_fields.datetime_num);
}

bool ScanPreviousModifySecond::saveToSql()
{ // sql先保存
    modifydata.save_time = QDateTime::currentDateTime(); // 保存之前赋值
    modifydata.wellsize = mWellSize->currentText().toUInt();
    modifydata.groupNames = mTable->groupNames();
    modifydata.groupPointLists = mTable->groupPoints();
    modifydata.groupNameLists = mTable->groupPointNames();
    // 第1张表是主表
    bool r1 = saveExperConfigToSql(modifydata.valuesForSql());
    // 第2张表是组的点轨迹表
    bool r2 = saveGroupPointConfigToSql(modifydata.groupValuesForSql());
    if (!(r1 && r2)){
        QMessageBox::critical(this,tr("错误"),tr("保存配置到数据库失败!"));
    }
    return r1&&r2;
}

bool ScanPreviousModifySecond::saveToJson()
{
    if (!mSaveConfig->isChecked())
        return true;
    auto name = mSavePath->text().simplified();
    if (name.isEmpty()) {
        QMessageBox::critical(this,tr("错误"),tr("请给要保存的配置命名!"));
        return false;
    }
    // 下方将所有配置写入json文件
    bool r =  saveExperConfigToJson(name,modifydata.valuesForJson(),this);
    if (!r){
        QMessageBox::critical(this,tr("错误"),tr("保存配置到Json文件失败!"));
    }
    //else QMessageBox::information(this,tr("消息"),tr("保存配置到Json文件成功!"));
    return r;
}

bool ScanPreviousModifySecond::sendToSocket()
{
    bool r = sendExperConfigToSocket(modifydata.valuesForSocket());
    if (!r)
        QMessageBox::critical(this,tr("错误"),tr("执行启动命令错误![%1]").arg(TcpLoaderPointer->lastError()));
    emit finished();
    return r;
}

bool ScanPreviousModifySecond::dataValid()
{
    // 1. 不为空的行,但是又存在空单元格,提示信息(对于x,y,order是因为更换size后会为空)
    emit started();
     if (!mTable->rowCompeled()) {
         QMessageBox::warning(this,tr("警告"),tr("行的信息不完整!"));
         return false;
     }

     // 2.次序还必须保证从1-n，例如1,2,3,5或 4,5,6,7都是不合法的
     if (!mTable->orderValid()) {
         QMessageBox::warning(this,tr("警告"),tr("次序有误,必须从1开始且不重复!"));
         return false;
     }

     // 3. 其他数据的检验(不需要了)

     return true;
}
