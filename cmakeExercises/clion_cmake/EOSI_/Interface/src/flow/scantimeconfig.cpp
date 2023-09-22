#include "../../inc/flow/scantimeconfig.h"

ScanTimeConfig::ScanTimeConfig(QWidget *parent) : GradientHiddenWidget(parent)
{
    mCheckBox = new QCheckBox(tr("计划执行?"));
    mCheckBox->setChecked(true);

    mStartDate = new QDateEdit;
    mStartTime = new QTimeEdit;
    mTotalScheduleTime = new SpinBox;
    mScheduleUnit = new ComboBox(QStringList()<<"hour"<<"minute");
    mScheduleUnit->setObjectName("schedule");
    mScheduleDuration = new SpinBox;
    mScheduleDurationUnit = new ComboBox(QStringList()<<"hour"<<"minute");
    mScheduleDurationUnit->setObjectName("sduration");
    mInfo = new Label(tr("预计结束时间: %1  总扫描次数: %2").arg(0).arg(0));

    mStartDate->setMinimumDate(QDate::currentDate());
    mStartDate->setDisplayFormat("MM/dd");
    mStartTime->setMinimumTime(QTime::currentTime());
    mStartTime->setDisplayFormat("hh::mm");
    mTotalScheduleTime->setRange(1,LONG_MAX);
    mTotalScheduleTime->setSuffix(" hours");
    mScheduleDuration->setRange(1,LONG_MAX);
    mScheduleDuration->setSuffix(" hours");

    QFormLayout * flay = new QFormLayout;
    flay->addRow(tr("开始日期: "),mStartDate);
    flay->addRow(tr("开始时间: "),mStartTime);
    flay->addRow(tr("扫描时间: "),mTotalScheduleTime);
    flay->addRow(tr("扫描单位: "),mScheduleUnit);
    flay->addRow(tr("间隔时间: "),mScheduleDuration);
    flay->addRow(tr("间隔单位: "),mScheduleDurationUnit);
    auto box1 = new GroupBox(tr("计划执行"));
    box1->setLayout(flay);

    mTotalOnceTime = new SpinBox;
    mOnceUnit = new ComboBox(QStringList()<<"hour"<<"minute");
    mOnceUnit->setObjectName("once");
    mOnceDurationTime = new SpinBox;
    mOnceDurationUnit = new ComboBox(QStringList()<<"hour"<<"minute");
    mOnceDurationUnit->setObjectName("oduration");
    mTotalOnceTime->setSuffix(" hours");
    mOnceDurationTime->setSuffix(" hours");
    mTotalOnceTime->setRange(1,LONG_MAX);
    mOnceDurationTime->setRange(1,LONG_MAX);

    QFormLayout * blay = new QFormLayout;
    blay->addRow(tr("扫描时间: "),mTotalOnceTime);
    blay->addRow(tr("扫描单位: "),mOnceUnit);
    blay->addRow(tr("间隔时间"),mOnceDurationTime);
    blay->addRow(tr("间隔单位"),mOnceDurationUnit);
    auto box2 = new GroupBox(tr("立即执行"));
    box2->setLayout(blay);
    box2->setEnabled(false);

    header->setText(tr("扫描时间和周期设置"));
    mainlay->addWidget(mCheckBox);
    mainlay->addSpacing(10);
    mainlay->addWidget(box1);
    mainlay->addSpacing(10);
    mainlay->addWidget(box2);
    mainlay->addSpacing(10);
    mainlay->addWidget(mInfo);
    mainlay->addStretch();

    connect(mCheckBox,&QCheckBox::stateChanged,this,[=](int state){
        auto r = state==Qt::Checked?true:false;
        box1->setEnabled(r);
        box2->setEnabled(!r);
    });

    connect(mStartDate,&QDateEdit::dateChanged,this,&ScanTimeConfig::onDateChanged);
    connect(mStartTime,SIGNAL(timeChanged(QTime)),this,SLOT(onTimeChanged(QTime)));
    connect(mTotalScheduleTime,SIGNAL(valueChanged(double)),this,SLOT(onTimeChanged(double)));
    connect(mScheduleDuration,SIGNAL(valueChanged(double)),this,SLOT(onTimeChanged(double)));
    connect(mScheduleUnit,QOverload<const QString&>::of(&ComboBox::currentIndexChanged),this,&ScanTimeConfig::onUnitChanged);
    connect(mScheduleDurationUnit,QOverload<const QString&>::of(&ComboBox::currentIndexChanged),this,&ScanTimeConfig::onUnitChanged);


    connect(mTotalOnceTime,QOverload<double>::of(&SpinBox::valueChanged),this,&ScanTimeConfig::onTotalScanChanged);
    connect(mTotalOnceTime,QOverload<double>::of(&SpinBox::valueChanged),this,&ScanTimeConfig::onTotalScanChanged);
    connect(mOnceUnit,QOverload<const QString&>::of(&ComboBox::currentIndexChanged),this,&ScanTimeConfig::onUnitChanged);
    connect(mOnceDurationUnit,QOverload<const QString&>::of(&ComboBox::currentIndexChanged),this,&ScanTimeConfig::onUnitChanged);
    connect(&timer1,&QTimer::timeout,this,&ScanTimeConfig::onTimer);
    connect(&timer2,&QTimer::timeout,this,&ScanTimeConfig::onTimer);
    timer1.setObjectName("timer1");
    timer2.setObjectName("timer2");
    timer1.start(1000*60*60*24-1);
    timer2.start(1000);
}

void ScanTimeConfig::onTimer()
{
        auto w = sender();
        if (w->objectName() == "timer1") // 定时器1负责更新开始日期的最小日期
            mStartDate->setMinimumDate(QDate::currentDate());
        else if (w->objectName() == "timer2") {
            if (isSchedule()) { // 定时器2每秒执行1次，在方式为计划执行时
                    if (mStartDate->date() == QDate::currentDate()) // 如果还是今天
                        mStartTime->setMinimumTime(QTime::currentTime()); // 开始时间要更新最小时间
                    else mStartTime->setMinimumTime(QTime(0,0,0)); // 日期不是今天的话不需要设置时间范围了
            } else { // 如果是立即执行，定时器2借助下方函数手动更新预计结束时间和总扫描次数
                onTotalScanChanged(); // 上方时间日期的设置会自动触发onTimeChanged更新refreshInfo
            }
        }
}

void ScanTimeConfig::refreshInfo()
{
    // 计算总时间
    auto datetime = QDateTime(mStartDate->date(),mStartTime->time());
    long long total = 0;
    if (mScheduleUnit->currentText()=="hour")
       total = mTotalScheduleTime->value() * 60 * 60;
    else total = mTotalScheduleTime->value()  * 60;  // 转为秒
    // 计算间隔时间
    long long duration = 0;
    if (mScheduleDurationUnit->currentText()=="hour")
       duration = mScheduleDuration->value() * 60 * 60;
    else duration = mScheduleDuration->value()  * 60;  // 转为秒

    // 间隔时间不能小于拍图时间，这个拍图时间是后端给定的，例如30mins
    if (duration<1800) {
        mInfo->setText(tr("警告:间隔时间不能低于30分钟!"));
        return;
    }

    // 总时间要大于间隔时间
    if (total<duration) {
        mInfo->setText(tr("警告:总时间至少大于等于一个间隔时间!"));
        return;
    }
    // 总的拍照次数
    auto count = total / duration; // 向下取整
    auto end = datetime.addSecs(total).toString("yyyy/MM/dd hh::mm");

    if (mStartDate->date() == QDate::currentDate())
    { // 如果开始时间是当天, 还要检查开始时间不能超过当前时间
           auto min1 = mStartTime->time().hour() * 60 + mStartTime->time().minute();
           auto min2 = QTime::currentTime().hour() * 60 + QTime::currentTime().minute();
           if (min1 < min2) // 不要直接比时间,因为 秒的存在会总是开始小于当前时间,比较到分钟即可
               mInfo->setText(tr("警告:开始时间不能小于当前时间!"));
            else {
               mInfo->setText(tr("预计结束时间: %1  总扫描次数: %2").arg(end).arg(count));
           }
    }
    else mInfo->setText(tr("预计结束时间: %1  总扫描次数: %2").arg(end).arg(count));
}

bool ScanTimeConfig::checkScheduledTime()
{
    // 计算总时长
    long long total = 0;
    if (mScheduleUnit->currentText()=="hour")
       total = mTotalScheduleTime->value() * 60 * 60;
    else total = mTotalScheduleTime->value()  * 60;  // 转为秒

    // 计算间隔时长
    long long duration = 0;
    if (mScheduleDurationUnit->currentText()=="hour")
       duration = mScheduleDuration->value() * 60 * 60;
    else duration = mScheduleDuration->value()  * 60;  // 转为秒

    bool r1 = total>=duration; // 总时长要大于间隔时长
    bool r2 = duration >= 1800; // 间隔时长要大于一个时间如30分钟
    bool r3 = true;

   if (mStartDate->date() == QDate::currentDate() )
   { // 如果是今天还要检查开始时间不能晚于当前时间
       auto min1 = mStartTime->time().hour() * 60 + mStartTime->time().minute();
       auto min2 = QTime::currentTime().hour() * 60 + QTime::currentTime().minute();
       r3 = min1>=min2;
   }
    if (r1 && r2 && r3) // 其实不检查当前时间也可以,定时器已经做了这部分工作
    //if (r1)
       return true;
    QMessageBox::critical(this,tr("错误"),tr("扫描时间设置不正确!"));
    return false;
}

QDateTime ScanTimeConfig::startScheduledTime()
{
    if (!checkScheduledTime()) return QDateTime();
    return QDateTime(mStartDate->date(),mStartTime->time());
}

QDateTime ScanTimeConfig::endScheduledTime()
{
    if (!checkScheduledTime()) return QDateTime();
    long long total = 0;
    if (mScheduleUnit->currentText()=="hour")
       total = mTotalScheduleTime->value() * 60 * 60;
    else total = mTotalScheduleTime->value()  * 60;  // 转为秒
    return startScheduledTime().addSecs(total);
}

long long ScanTimeConfig::totalScheduledTime()
{
     if (!checkScheduledTime()) return 0;
     long long total = 0;
     if (mScheduleUnit->currentText()=="hour")
        total = mTotalScheduleTime->value() * 60 * 60;
     else total = mTotalScheduleTime->value()  * 60;  // 转为秒
     return  total;
}

long long ScanTimeConfig::durationScheduledTime()
{
    if (!checkScheduledTime()) return 0;
    long long duration = 0;
    if (mScheduleDurationUnit->currentText()=="hour")
       duration = mScheduleDuration->value() * 60 * 60;
    else duration = mScheduleDuration->value()  * 60;  // 转为秒
    return  duration;
}

int ScanTimeConfig::totcalScheduledCount()
{
   return totalScheduledTime() / durationScheduledTime(); // 会整除
}

// -------------------------- 立即扫描 ------------------------------------------
void ScanTimeConfig::onTotalScanChanged()
{ // 总时间要大于等于扫描时间
    // 计算总时间
    long long total = 0;
    if (mOnceUnit->currentText()=="hour")
       total = mTotalOnceTime->value() * 60 * 60;
    else total = mTotalOnceTime->value()  * 60;  // 转为秒
    // 计算结束时间
    long long duration = 0;
    if (mOnceDurationUnit->currentText()=="hour")
       duration = mOnceDurationTime->value() * 60 * 60;
    else duration = mOnceDurationTime->value()  * 60;  // 转为秒
    // 计算拍图次数
    auto count = total / duration;
    auto end = QDateTime::currentDateTime().addSecs(total).toString("yyyy/MM/dd hh::mm");

    if (duration<1800) {
        mInfo->setText(tr("警告:间隔时间不能低于30分钟!"));
        return;
    }

    if (total<duration) {
        mInfo->setText(tr("警告:总时间至少大于等于一个间隔时间!"));
        return;
    }

    mInfo->setText(tr("预计结束时间: %1  总扫描次数: %2").arg(end).arg(count));
}

bool ScanTimeConfig::checkOnceTime()
{
    long long total = 0;
    if (mOnceUnit->currentText()=="hour")
       total = mTotalOnceTime->value() * 60 * 60;
    else total = mTotalOnceTime->value()  * 60;  // 转为秒

    long long duration = 0;
    if (mOnceDurationUnit->currentText()=="hour")
       duration = mOnceDurationTime->value() * 60 * 60;
    else duration = mOnceDurationTime->value()  * 60;  // 转为秒

    if (total>=duration && duration>=1800)
        return true;
    QMessageBox::critical(this,tr("错误"),tr("扫描时间设置不正确!"));
    return  false;
}

long long ScanTimeConfig::totalOnceTime()
{
    if (!checkOnceTime()) return 0;
    long long total = 0;
    if (mOnceUnit->currentText()=="hour")
       total = mTotalOnceTime->value() * 60 * 60;
    else total = mTotalOnceTime->value()  * 60;  // 转为秒
    return total;
}

long long ScanTimeConfig::durationOnceTime()
{
    if (!checkOnceTime()) return  0;
    long long duration = 0;
    if (mOnceDurationUnit->currentText()=="hour")
       duration = mOnceDurationTime->value() * 60 * 60;
    else duration = mOnceDurationTime->value()  * 60;  // 转为秒
    return  duration;
}

int ScanTimeConfig::totcalOnceCount()
{
   return totalOnceTime() / durationOnceTime(); // 会整除
}

void ScanTimeConfig::onDateChanged(const QDate&date)
{
   if (date != QDate::currentDate())
       mStartTime->setMinimumTime(QTime(0,0,0));
   else mStartTime->setMinimumTime(QTime::currentTime());
   refreshInfo();
}

void ScanTimeConfig::onTimeChanged(const QTime&time)
{
   Q_UNUSED(time);
   refreshInfo();
}

void ScanTimeConfig::onTimeChanged(double time)
{
    Q_UNUSED(time);
    refreshInfo();
}

void ScanTimeConfig::onUnitChanged(const QString& text)
{
    auto suffix = " "+text+"s";
    auto w = sender();
    if (w->objectName() == "schedule")
        mTotalScheduleTime->setSuffix(suffix);
    else if (w->objectName() == "sduration")
        mScheduleDuration->setSuffix(suffix);
    else if (w->objectName() == "once")
        mTotalOnceTime->setSuffix(suffix);
    else if (w->objectName() == "oduration")
        mOnceDurationTime->setSuffix(suffix);

    if (w->objectName() == "schedule" || w->objectName() == "sduration")
        refreshInfo();
    else if (w->objectName() == "once" || w->objectName() == "oduration")
        onTotalScanChanged();
}

bool ScanTimeConfig::isOnce() const
{
    return !mCheckBox->isChecked();
}

bool ScanTimeConfig::isSchedule() const
{
    return !isOnce();
}
