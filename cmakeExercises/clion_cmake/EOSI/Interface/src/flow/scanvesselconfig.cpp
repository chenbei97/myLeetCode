#include "../../inc/flow/scanvesselconfig.h"

ScanVesselConfig::ScanVesselConfig(QWidget *parent) : QWidget(parent)
{
        setProgressBar();
        mStack = new QStackedWidget;
        mCreateConfig = new ScanCreateConfig;
        mStack->addWidget(mCreateConfig); // 创建模式-第一步
        auto btnlay = setButton();
\
        auto lay = new QVBoxLayout(this);
        lay->addWidget(mProgressBar);
        lay->addWidget(mStack);
        lay->addLayout(btnlay);

        connect(mCreateConfig,&ScanCreateConfig::createMode,this,&ScanVesselConfig::setCreateMode);
        connect(mProgressBar,&QProgressBar::valueChanged,this,&ScanVesselConfig::onProgressValue);
        mProgressBar->setValue(data.progress);
        connect(mNext,&QPushButton::clicked,this,&ScanVesselConfig::onNext);
        connect(mPrevious,&QPushButton::clicked,this,&ScanVesselConfig::onPrevious);

        INIT_FONT;
        INIT_WINDOW_MINSIZE;
}

void ScanVesselConfig::addStackedWidgets()
{ // 重新进入本函数之前,onPrevious保证已经删除了之前指针指向的对象并将其置nullptr
    switch (data.create_mode) {
        case ScanCreateMode::New:
            mProgressBar->setRange(0,SummaryConfig);
            mExperConfig = new ScanExperimentConfig;
            mSettingConfig = new ScanSettingConfig;
            mWellConfig = new ScanWellConfig;
            mWellPreview = new ScanWellPreview;
            mDescConfig = new ScanDescriptionConfig;
            mAnaConfig = new ScanAnalysisConfig;
            mTimeConfig = new ScanTimeConfig;
            mSummary = new ScanVesselSummary;

            //mStack->addWidget(mWellPreview); // 孔的预览
            mStack->addWidget(mExperConfig);// 实验类型
            mStack->addWidget(mSettingConfig); // 物镜、通道、孔板尺寸
            mStack->addWidget(mWellConfig);// 选孔
            mStack->addWidget(mWellPreview); // 孔的预览
            mStack->addWidget(mDescConfig); // 实验描述
            mStack->addWidget(mAnaConfig); // 分析类型
            mStack->addWidget(mTimeConfig); // 实验时间
            mStack->addWidget(mSummary); // 面板总结
            break;
        case ScanCreateMode::Previous:
            mProgressBar->setRange(0,AdjustConfigSecondStep);
            mCopyPrevious = new ScanPreviousFlow;
            mCopyPrevious->setCurrentUser(data.currentUser);
            mCopyPrevious->setStyle(styleSheet());
            mModifyPreviousFirst = new ScanPreviousModifyFirst;
            mModifyPreviousSecond = new ScanPreviousModifySecond;
            mStack->addWidget(mCopyPrevious);
            mStack->addWidget(mModifyPreviousFirst);
            mStack->addWidget(mModifyPreviousSecond);
            break;
        case ScanCreateMode::Current:
            break;
        default:break;
    }
}

void ScanVesselConfig::onNext()
{
    if (data.progress == ModeConfig) { // 创建模式,data.create_mode在信号连接内已被赋值

        if (data.create_mode == ScanCreateMode::EmptyMode)
        {
            QMessageBox::critical(this,tr("错误"),tr("至少选择一个创建模式!"));
            return;
        }
        addStackedWidgets();
    }

    switch (data.create_mode) { // 不同的进度判断逻辑
        case ScanCreateMode::New:onNextNew();break;
        case ScanCreateMode::Previous:onNextPrevious();break;
        case ScanCreateMode::Current:onNextCurrent();break;
        default:break;
    }

}

void ScanVesselConfig::onNextNew()
{
    if (data.progress == ExperConfig) {  // 实验类型
        data.experiment_type = mExperConfig->experimentType();
        if (data.experiment_type.isEmpty()) return;
    }

    if (data.progress == SettingConfig) {
        data.channel = mSettingConfig->channel();
        if (data.channel.isEmpty()) return;
        data.objective = mSettingConfig->objective();
        if (data.objective.isEmpty())  return;
        auto oldview = data.view;
        data.view= mSettingConfig->views();
        if (!data.view) return;
        if (data.view != oldview) {
            mWellPreview->clearState();// 信息改变时再清除原来的点信息/UI信息
            mWellPreview->setViews(data.view); // 视野数传给预览
        }
        auto oldsize = data.wellsize;
        data.wellsize = mSettingConfig->wellsize();
        if (!data.wellsize) return;
        if (data.wellsize != oldsize) {
            mWellConfig->clearState();// 信息改变时再清除原来的点信息/UI信息
            mWellPreview->clearState();
        }

        switch (data.wellsize) {// 孔板尺寸要传递给选孔和预览
            case 6: mWellConfig->setPatternSize(2,3);
                        mWellPreview->setPatternSize(2,3);
                        break;
            case 24:
                        mWellConfig->setPatternSize(4,6);
                        mWellPreview->setPatternSize(4,6);
                        break;
            case 96: mWellConfig->setPatternSize(8,12);
                        mWellPreview->setPatternSize(8,12);
                        break;
            case 384: mWellConfig->setPatternSize(16,24);
                        mWellPreview->setPatternSize(16,24);
                        break;
            default:break;
        }
    }

    if (data.progress == PatternConfig) { // 选择完成像轨迹,要把轨迹的组/位置/孔名传递给预览界面
            // 视野数和规格尺寸在updateWellsize传递完毕,不需要再设置
        if (mWellConfig->allEmptyGroup()) {
            QMessageBox::critical(this,tr("错误"),tr("不能全为空组!"));
            return;
        }

        auto gc = mWellConfig->groupCount();
            if (!gc) {
                QMessageBox::critical(this,tr("错误"),tr("至少添加一个组!"));
                return;
            }
            auto pc = mWellConfig->pointCount();
            if (!pc) {
                QMessageBox::critical(this,tr("错误"),tr("至少添加一个孔!"));
                return;
            }
            if (mWellConfig->hasEmptyGroup()) {
                QMessageBox::warning(this,tr("警告"),tr("存在一个组没有添加孔,该组将被忽略!"));
            }
             // 把组数据(组名,点位置和点名存到data以及传递给preview窗口)
           auto groupdatas = mWellConfig->groupDatas();
           mWellPreview->setGroupDatas(groupdatas);
           data.groupNames.clear();
           data.groupNameLists.clear();
           data.groupPointLists.clear();
           foreach(auto groupdata,groupdatas)
           {
               data.groupNames.append(groupdata.groupName);
               data.groupPointLists.append(groupdata.points);
               data.groupNameLists.append(groupdata.pointNames);
           }
           //LOG<<data.groupNames<<"\n"<<data.groupPointLists<<"\n"<<data.groupNameLists;
    }

    if (data.progress == PatternPreview) {

    }

    if (data.progress == DescConfig) { // 实验的各类信息更新
        auto experName = mDescConfig->experName();
        auto experPerson = mDescConfig->personName();
        if (experName.isEmpty() || experPerson.isEmpty()) return;

        data.experiment_name = experName;
        data.experiment_person = experPerson;
        data.experiment_celltype = mDescConfig->cellType();
        data.experiment_description = mDescConfig->description();
    }

    if (data.progress == AnaConfig) // 分析类型
    {
        data.analysis_type = mAnaConfig->analysisType();
        data.analysis_notes = mAnaConfig->analysisNotes();
        data.analysis_definition = mAnaConfig->analysisDefinition();
        data.analysis_spec_1 = mAnaConfig->spectralUnmixPercentOf1();
        data.analysis_spec_2 = mAnaConfig->spectralUnmixPercentOf2();
    }

    if (data.progress == TimeConfig) { // 实验时间设置
        data.is_schedule = mTimeConfig->isSchedule();

        if (!mTimeConfig->isOnce()) {
            if (!mTimeConfig->checkScheduledTime()) return;
            data.schedule_start_datetime = mTimeConfig->startScheduledTime();
            data.schedule_end_datetime = mTimeConfig->endScheduledTime();
            data.schedule_total_time = mTimeConfig->totalScheduledTime();
            data.schedule_duration_time = mTimeConfig->durationScheduledTime();
            data.schedule_total_count = mTimeConfig->totcalScheduledCount();
        } else {
            if (!mTimeConfig->checkOnceTime()) return;
            data.once_total_time = mTimeConfig->totalOnceTime();
            data.once_duration_time = mTimeConfig->durationOnceTime();
            data.once_total_count = mTimeConfig->totcalOnceCount();
        }
        mSummary->translate(data);
    }

    if (data.progress == SummaryConfig) { // 面板信息总览
        auto dlg = getWaitDialog(this);
        connect(mSummary,&ScanVesselSummary::started,dlg,[&]{dlg->show();});//不要用exec,全部信号阻塞
        connect(mSummary,&ScanVesselSummary::finished,dlg,[&]{dlg->accept();});//不要用close,关不掉
        connect(dlg,&QMessageBox::rejected,this,[=]{QMessageBox::critical(this,tr("消息"),tr("启动实验失败,请重试重试/重启或联系售后!"));});
        if (!mSummary->saveToSql()) {dlg->reject();return;}
        //auto flag = data.save_time.toString(ExperConfigTableFields.other_fields.datetime_num);
        auto flag = mSummary->flag(); // 这里的data.savetime没有赋值,只能从summary拿到
        if (!mSummary->saveToJson()) {
            // 万一失败,数据库的记录需要回滚
            rollback(flag);
            dlg->reject();
            return;
        }
        if (!mSummary->sendToSocket()) {
            // json就不管了,只考虑数据库
            rollback(flag);
            dlg->reject();
            return;
        }
        QMessageBox::information(this,tr("消息"),tr("启动实验成功!"));
    }

    // LOG<<"the current progress = "<<data.progress;
    if (data.progress== SummaryConfig) {
        close();
    } else{
        data.progress++;
        mProgressBar->setValue(data.progress);
    }
}

void ScanVesselConfig::onNextPrevious()
{
    if (data.progress == FromSqlJsonConfig) { // 选择来自数据库还是文件
        auto parse = mCopyPrevious->parseData(); // 拿到sql或json解析后的数据
        if (parse.isEmpty()) return;

        data.resetExcludeProgressAndMode(); // 进度值不能清除否则不能正常显示,创建模式也不需要修改
        // 把需要解析而来的数据保存下来
        data.analysis_definition = parse[ExperConfigTableFields.ana_definition].toString();
        data.analysis_notes = parse[ExperConfigTableFields.ana_notes].toString();
        data.analysis_spec_1 = parse[ExperConfigTableFields.ana_spec1].toDouble();
        data.analysis_spec_2 = parse[ExperConfigTableFields.ana_spec2].toDouble();
        data.analysis_type = parse[ExperConfigTableFields.ana_type].toString();

        data.experiment_celltype = parse[ExperConfigTableFields.exper_celltype].toString();
        data.experiment_description = parse[ExperConfigTableFields.exper_description].toString();
        data.experiment_name = parse[ExperConfigTableFields.exper_name].toString();
        data.experiment_person = parse[ExperConfigTableFields.exper_person].toString();
        data.experiment_type = parse[ExperConfigTableFields.exper_type].toString();

        GroupVectorPair gdatas = parse[ExperConfigTableFields.other_fields.group].value<GroupVectorPair>();
        data.groupNames = gdatas.first ;
        data.groupPointLists = gdatas.second.first;
        data.groupNameLists = gdatas.second.second;

        data.channel = parse[ExperConfigTableFields.channel].toString();
        data.objective = parse[ExperConfigTableFields.objective].toString();
        data.view = parse[ExperConfigTableFields.view].toUInt();
        data.wellsize = parse[ExperConfigTableFields.wellsize].toUInt();

        data.is_schedule = parse[ExperConfigTableFields.is_schedule].toInt();
        if (!data.is_schedule) {
            data.once_total_time = parse[ExperConfigTableFields.total].toDouble();
            data.once_duration_time = parse[ExperConfigTableFields.duration].toDouble();
            data.once_total_count = parse[ExperConfigTableFields.count].toDouble();
        } else {
            data.schedule_total_time = parse[ExperConfigTableFields.total].toDouble();
            data.schedule_duration_time = parse[ExperConfigTableFields.duration].toDouble();
            data.schedule_total_count = parse[ExperConfigTableFields.count].toDouble();
            data.schedule_start_datetime =QDateTime::fromString(parse[ExperConfigTableFields.start_time].toString(),Qt::ISODate);
            data.schedule_end_datetime =QDateTime::fromString(parse[ExperConfigTableFields.end_time].toString(),Qt::ISODate);
        }

        mModifyPreviousFirst->mapDataToUi(data);
        mModifyPreviousSecond->mapDataToUi(data);
    }

    if (data.progress == AdjustConfigFirstStep) {
        if (!mModifyPreviousFirst->checkTime()) return;
        mModifyPreviousSecond->setModifyData(mModifyPreviousFirst->modifyData());
    }

    if (data.progress == AdjustConfigSecondStep) {
        auto dlg = getWaitDialog(this);
        connect(mModifyPreviousSecond,&ScanPreviousModifySecond::started,dlg,[&]{dlg->show();qApp->processEvents();});//不要用exec
        connect(mModifyPreviousSecond,&ScanPreviousModifySecond::finished,dlg,[&]{dlg->accept();});//不要用close
        connect(dlg,&QMessageBox::rejected,this,[=]{QMessageBox::critical(this,tr("消息"),tr("启动实验失败,请重试/重启或联系售后!"));});
        if (!mModifyPreviousSecond->dataValid()) {dlg->reject();return;}
        if (!mModifyPreviousSecond->saveToSql()) {dlg->reject();return;}
        //auto flag = data.save_time.toString(ExperConfigTableFields.other_fields.datetime_num);
        auto flag = mModifyPreviousSecond->flag(); // 这里的data.savetime没有赋值,只能从second拿到
        if (!mModifyPreviousSecond->saveToJson()) {
            dlg->reject();
            rollback(flag);
            return;
        }
        if (!mModifyPreviousSecond->sendToSocket()) {
            dlg->reject();
            rollback(flag);
            return;}
        QMessageBox::information(this,tr("消息"),tr("启动实验成功!"));
        close();
    }
    else {
        data.progress++;
        mProgressBar->setValue(data.progress);
    }
}

void ScanVesselConfig::onNextCurrent()
{

}

void ScanVesselConfig::onPrevious()
{
    data.progress--;
    mProgressBar->setValue(data.progress);
}

void ScanVesselConfig::onProgressValue(int value)
{
    mStack->setCurrentIndex(value-1);

    if (value == ModeConfig)
    {
        mPrevious->setEnabled(false); // 上一步禁止
        if (data.create_mode == ScanCreateMode::New) {
            delete mExperConfig;// 不用removeWidget直接delete看log count确实变了
            delete mSettingConfig;
            delete  mWellConfig;
            delete mWellPreview;
            delete mDescConfig;
            delete  mAnaConfig;
            delete  mTimeConfig;
            delete  mSummary;
            // 置空很重要,delete删除的是指针指向的东西但是没删除指针本身,再次删除会出bug
            mExperConfig = nullptr;
            mSettingConfig = nullptr;
            mWellConfig = nullptr;
            mWellPreview = nullptr;
            mDescConfig = nullptr;
            mAnaConfig = nullptr;
            mTimeConfig = nullptr;
            mSummary = nullptr;
        } else if (data.create_mode == ScanCreateMode::Previous) {
            delete mCopyPrevious;
            delete  mModifyPreviousFirst;
            delete mModifyPreviousSecond;
            mCopyPrevious = nullptr;
            mModifyPreviousFirst = nullptr;
            mModifyPreviousSecond = nullptr;
        }
        data.reset(); // 回到第一步需要重置数据,上边的判断结束后再重置,data.create_mode还需要使用一下
        mCreateConfig->clearRadioState(); // radiobutton也要清除掉选中状态
    }
    else mPrevious->setEnabled(true);

    //LOG<<"current progress = "<<value;

    switch (data.create_mode) { // 不同的进度判断逻辑
        case ScanCreateMode::New:
            value == SummaryConfig?mNext->setText(tr("完成")):mNext->setText(tr("下一步"));
            break;
        case ScanCreateMode::Previous:
           value == AdjustConfigSecondStep?mNext->setText(tr("完成")):mNext->setText(tr("下一步"));
            break;
        case ScanCreateMode::Current:
            break;
        default:break;
    }

}

void ScanVesselConfig::setCreateMode(ScanCreateMode mode)
{
    data.create_mode = mode;
}

void ScanVesselConfig::resizeEvent(QResizeEvent *e)
{
    mProgressBar->resize(e->size().width(),40);
    return QWidget::resizeEvent(e);
}

void ScanVesselConfig::setCurrentUser(QCString user)
{
    data.currentUser = user;
    //mCopyPrevious->setCurrentUser(user); // 还没new出来不能赋值
    LOG<<"current user is "<<user;
}

QHBoxLayout* ScanVesselConfig::setButton()
{
        auto lay = new QHBoxLayout;
        mNext = new PushButton(tr("下一步"));
        mPrevious = new PushButton(tr("上一步"));
        lay->addWidget(mPrevious);
        lay->addStretch();
        lay->addWidget(mNext);
        return lay;
}

void ScanVesselConfig::setProgressBar()
{
    mProgressBar = new ProgressBar;
    mProgressBar->setAlignment(Qt::AlignCenter);

    mProgressBar->setFormat("%v/%m");
    mProgressBar->setTextVisible(true);
    mProgressBar->setRange(0,0);

    mProgressBar->setMinimumHeight(40);
}
