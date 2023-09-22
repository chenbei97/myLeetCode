#include "../../inc/flow/scanpreviousmodifyfirst.h"

ScanPreviousModifyFirst::ScanPreviousModifyFirst(QWidget *parent) : GradientHiddenWidget(parent)
{

    initObject();
    initLayout();
    initConnections();

    auto lay = new QHBoxLayout;
    lay->addStretch();
    lay->addLayout(gridlay);
    lay->addStretch();

    header->setText(tr("配置信息核对与调整(1)"));
    //mainlay->addStretch();
    mainlay->addLayout(lay);
    mainlay->addWidget(mTextEdit);
    mainlay->addSpacing(10);
}

void ScanPreviousModifyFirst::mapDataToUi(const ScanConfigData &d)
{
       currentUser = d.currentUser; // 这个信息要保存下来
       mChannels->setCurrentText(d.channel);
       mObjectives->setCurrentText(d.objective);
       mViews->setCurrentText(QString::number(d.view));
       mAnaType->setCurrentText(d.analysis_type);
       mAnaDefine->setCurrentText(d.analysis_definition);
       mSpec1->setValue(d.analysis_spec_1);
       mSpec2->setValue(d.analysis_spec_2);
       mExperType->setCurrentText(d.experiment_type);
       mExperName->setText(d.experiment_name);
       mExperPerson->setText(d.experiment_person);
       mExperCellType->setText(d.experiment_celltype);
       mExperTimeType->setCurrentText(d.is_schedule?"schedule":"once");
       if (d.is_schedule) {
           mTotalTime->setValue(d.schedule_total_time/60.0);
           mDurationTime->setValue(d.schedule_duration_time/60.0);
       } else {
           mTotalTime->setValue(d.once_total_time/60.0);
           mDurationTime->setValue(d.once_duration_time/60.0);
       }
       mTextEdit->setLeftText(d.experiment_description);
       mTextEdit->setRightText(d.analysis_notes);
}

bool ScanPreviousModifyFirst::checkTime()
{// 如果是计划执行检查开始时间不能超过
    auto total = mTotalTime->value(); // minutes
    auto duration = mDurationTime->value(); // minutes
    if (total< duration) {
        QMessageBox::critical(this,tr("错误"),tr("总时间必须大于等于间隔时间!"));
        return false;
    }
    if (duration<30) {
        QMessageBox::critical(this,tr("错误"),tr("总间隔时间不能低于30分钟!"));
        return false;
    }
    if (mExperTimeType->currentIndex() == 0) {
        auto start = mStartDateTime->dateTime();
        if (start <= QDateTime::currentDateTime()) {
            QMessageBox::critical(this,tr("错误"),tr("开始时间不能早于当前时间!"));
            return false;
        }
    }
    return true;
}

static QStringList getSquareNumber(int count)
{
    QStringList list;

    for(int i = 1; i <= count; ++i)
        list<<QString::number(i*i);

    return list;
}

void ScanPreviousModifyFirst::updateView(int index)
{
    mViews->clear();
    switch (index) {
        case 0: mViews->addItems(QStringList()<<"1"<<"2"); break;// 2不是平方数
        case 1: mViews->addItems(getSquareNumber(4));break;
        case 2: mViews->addItems(getSquareNumber(8));break;
        case 3: mViews->addItems(getSquareNumber(17));break;
        default:break;
    }
    mViews->setCurrentIndex(0); // 不要设为-1,否则就要除了checktime还要检查这个不能为空,直接避免
}

ScanConfigData ScanPreviousModifyFirst::modifyData() const
{
    ScanConfigData d;
    d.currentUser = currentUser;
    d.channel = mChannels->currentText();
    d.objective = mObjectives->currentText();
    d.view = mViews->currentText().toUInt();
    d.analysis_type = mAnaType->currentText();
    d.analysis_notes = mTextEdit->rightText();
    d.analysis_definition = mAnaDefine->currentText();
    d.analysis_spec_1 = mSpec1->value();
    d.analysis_spec_2 = mSpec2->value();
    d.experiment_name = mExperName->text();
    d.experiment_person = mExperPerson->text();
    d.experiment_celltype = mExperCellType->text();
    d.experiment_description = mTextEdit->leftText();
    d.experiment_type = mExperType->currentText();
    d.is_schedule = !mExperTimeType->currentIndex(); // 0是schedule
    if (d.is_schedule) {
        d.schedule_total_time = mTotalTime->value() * 60;
        d.schedule_duration_time = mDurationTime->value() * 60;
        d.schedule_start_datetime = mStartDateTime->dateTime();
        d.schedule_end_datetime = d.schedule_start_datetime.addSecs(d.schedule_total_time);
        d.schedule_total_count = d.schedule_total_time / d.schedule_duration_time;
    } else {
        d.once_total_time = mTotalTime->value() * 60;
        d.once_duration_time = mDurationTime->value() * 60;
        d.once_total_count = d.once_total_time / d.once_duration_time;
    }
    return d;
}

void ScanPreviousModifyFirst::initObject()
{
    mChannels = new ComboBox;
    mObjectives = new ComboBox;
    mViews = new ComboBox;
    mAnaType = new ComboBox;
    mAnaDefine = new ComboBox;
    mSpec1 = new SpinBox;
    mSpec2 = new SpinBox;
    mExperName = new LineEdit;
    mExperPerson = new LineEdit;
    mExperCellType = new LineEdit;
    mExperType = new ComboBox;
    mExperTimeType = new ComboBox;
    mTotalTime = new SpinBox;
    mDurationTime = new SpinBox;
    mStartDateTime = new DateTimeEdit;
    mTextEdit = new DoubleTextEdit;

    mChannels->addItems(QStringList()<<"bright"<<"phase"<<"red"<<"green"<<"blue");
    mObjectives->addItems(QStringList()<<"4x"<<"10x"<<"20x"<<"40x");
    QStringList expertypes = {tr("细胞增殖"),tr("划痕"),tr("类器官"),
                              tr("药效和细胞毒性"),tr("侵袭"),tr("形态学"),tr("转染")};
    mExperType->addItems(expertypes);
    mExperTimeType->addItems(QStringList()<<"schedule"<<"once");
    mSpec1->setRange(0.0,1.0);
    mSpec1->setSuffix(" %");
    mSpec1->setValue(0.0);
    mSpec1->setSingleStep(0.01);
    mSpec1->setDecimals(2);
    mSpec2->setRange(0.0,1.0);
    mSpec2->setSuffix(" %");
    mSpec2->setValue(0.0);
    mSpec2->setSingleStep(0.01);
    mSpec2->setDecimals(2);

    //mStartDateTime->setEnabled(false);
    mStartDateTime->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Minimum);
    mStartDateTime->setMinimumDateTime(QDateTime::currentDateTime());
    mStartDateTime->setDisplayFormat("MM/dd hh:mm");
    mTotalTime->setDecimals(0);
    mTotalTime->setSingleStep(1);
    mTotalTime->setRange(1,LONG_MAX);
    mTotalTime->setSuffix(" minutes");
    mDurationTime->setRange(1,LONG_MAX);
    mDurationTime->setSuffix(" minutes");
    mDurationTime->setDecimals(0);
    mDurationTime->setSingleStep(1);
    mTextEdit->setLeftTitle(tr("实验描述"));
    mTextEdit->setRightTitle(tr("分析日志"));
    mTextEdit->setReadonly(false);
}

void ScanPreviousModifyFirst::initConnections()
{
    connect(mExperTimeType,QOverload<int>::of(&ComboBox::currentIndexChanged),
            this,[=](int index){index? mStartDateTime->setEnabled(false):mStartDateTime->setEnabled(true);});
    connect(mObjectives,QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,&ScanPreviousModifyFirst::updateView);
}

void  ScanPreviousModifyFirst::initLayout()
{
    gridlay = new QGridLayout;
    gridlay->setHorizontalSpacing(160);
    gridlay->setVerticalSpacing(20);
    gridlay->addWidget(new QLabel("scan type: "),0,0,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("channel: "),0,1,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("objective: "),0,2,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("views: "),0,3,Qt::AlignLeft);
    gridlay->addWidget(new Label,1,0,Qt::AlignLeft);
    gridlay->addWidget(mChannels,1,1,Qt::AlignLeft);
    gridlay->addWidget(mObjectives,1,2,Qt::AlignLeft);
    gridlay->addWidget(mViews,1,3,Qt::AlignLeft);

    gridlay->addWidget(new QLabel("analysis type: "),2,0,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("analysis definition: "),2,1,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("analysis spec1: "),2,2,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("analysis spec2: "),2,3,Qt::AlignLeft);
    gridlay->addWidget(mAnaType,3,0,Qt::AlignLeft);
    gridlay->addWidget(mAnaDefine,3,1,Qt::AlignLeft);
    gridlay->addWidget(mSpec1,3,2,Qt::AlignLeft);
    gridlay->addWidget(mSpec2,3,3,Qt::AlignLeft);

    gridlay->addWidget(new QLabel("experiment type: "),4,0,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("experiment name: "),4,1,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("experiment person: "),4,2,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("experiment cell: "),4,3,Qt::AlignLeft);
    gridlay->addWidget(mExperType,5,0,Qt::AlignLeft);
    gridlay->addWidget(mExperName,5,1,Qt::AlignLeft);
    gridlay->addWidget(mExperPerson,5,2,Qt::AlignLeft);
    gridlay->addWidget(mExperCellType,5,3,Qt::AlignLeft);

    gridlay->addWidget(new QLabel("exec type: "),6,0,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("total time: "),6,1,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("duration time: "),6,2,Qt::AlignLeft);
    gridlay->addWidget(new QLabel("start time: "),6,3,Qt::AlignLeft);
    gridlay->addWidget(mExperTimeType,7,0,Qt::AlignLeft);
    gridlay->addWidget(mTotalTime,7,1,Qt::AlignLeft);
    gridlay->addWidget(mDurationTime,7,2,Qt::AlignLeft);
    gridlay->addWidget(mStartDateTime,7,3,Qt::AlignLeft);


    //gridlay->addWidget(mTextEdit,8,0,1,8,Qt::AlignCenter);
}
