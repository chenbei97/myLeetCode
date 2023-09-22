#ifndef SCANTIMECONFIG_H
#define SCANTIMECONFIG_H

#include "widgets/gradienthiddenwidget.h"
#include "widgets/spinbox.h"
#include "widgets/combobox.h"
#include "widgets/groupbox.h"
#include "qcheckbox.h"
#include "qdatetimeedit.h"

class ScanTimeConfig : public GradientHiddenWidget
{
    Q_OBJECT
public:
    explicit ScanTimeConfig(QWidget *parent = nullptr);
    QDateTime startScheduledTime();
    QDateTime endScheduledTime();
    long long totalScheduledTime();
    long long durationScheduledTime();
    int totcalScheduledCount();

    long long totalOnceTime();
    long long durationOnceTime();
    int totcalOnceCount();

    bool checkScheduledTime();
    bool checkOnceTime();

    bool isSchedule() const;
    bool isOnce() const;
private:
    QCheckBox * mCheckBox;

    QDateEdit * mStartDate; // 计划扫描
    QTimeEdit * mStartTime;
    SpinBox * mTotalScheduleTime;
    ComboBox * mScheduleUnit;
    SpinBox * mScheduleDuration;
    ComboBox * mScheduleDurationUnit;

    SpinBox * mTotalOnceTime; // 立即扫描
    ComboBox * mOnceUnit;
    SpinBox * mOnceDurationTime;
    ComboBox * mOnceDurationUnit;

    Label * mInfo;
    QTimer timer1;
    QTimer timer2;

private slots:
    void onTimer();
    void onDateChanged(const QDate&date);
    void onTimeChanged(const QTime&time);
    void onTimeChanged(double time);
    void onUnitChanged(const QString&text);
    void refreshInfo();
    void onTotalScanChanged();
signals:

};

#endif // SCANTIMECONFIG_H
