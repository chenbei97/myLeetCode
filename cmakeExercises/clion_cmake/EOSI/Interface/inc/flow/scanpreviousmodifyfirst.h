#ifndef SCANPREVIOUSMODIFYFIRST_H
#define SCANPREVIOUSMODIFYFIRST_H

#include "widgets/combobox.h"
#include "widgets/label.h"
#include "widgets/spinbox.h"
#include "widgets/lineedit.h"
#include "widgets/datetimeedit.h"
#include "widgets/gradienthiddenwidget.h"
#include "widgets/doubletextedit.h"
#include "scanconfigdata.h"

class ScanPreviousModifyFirst : public GradientHiddenWidget
{
    Q_OBJECT
    ScanConfigData data;
public:
    explicit ScanPreviousModifyFirst(QWidget *parent = nullptr);
    void mapDataToUi(const ScanConfigData& d);
    bool checkTime();
    ScanConfigData modifyData() const;
private:
    void initObject();
    void initLayout();
    void initConnections();
    void updateView(int index);
private:
    QGridLayout * gridlay;
    ComboBox * mChannels;
    ComboBox * mObjectives;
    ComboBox * mViews;
    ComboBox * mAnaType;
    ComboBox * mAnaDefine;
    SpinBox * mSpec1;
    SpinBox * mSpec2;
    LineEdit * mExperName;
    LineEdit * mExperPerson;
    LineEdit * mExperCellType;
    ComboBox * mExperType;
    ComboBox * mExperTimeType;
    SpinBox * mTotalTime;
    SpinBox * mDurationTime;
    DateTimeEdit * mStartDateTime;
    DoubleTextEdit * mTextEdit;
    QString currentUser;
signals:

};

#endif // SCANPREVIOUSMODIFYFIRST_H
