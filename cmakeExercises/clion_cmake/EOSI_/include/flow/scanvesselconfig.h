#ifndef SCANVESSELCONFIG_H
#define SCANVESSELCONFIG_H

#include "../../../include/widgets/progressbar.h"
#include "../../../include/utilities/dialog.h"
#include "qstackedwidget.h"

#include "scanconfigdata.h"
#include "scansettingconfig.h"
#include "scanwellconfig.h"
#include "scanwellpreview.h"
#include "scanexperimentconfig.h"
#include "scandescriptionconfig.h"
#include "scananalysisconfig.h"
#include "scantimeconfig.h"
#include "scanvesselsummary.h"

#include "scanpreviousflow.h"
#include "scanpreviousmodifyfirst.h"
#include "scanpreviousmodifysecond.h"

typedef ScanCreateConfig::ScanCreateMode ScanCreateMode;

class ScanVesselConfig : public QWidget
{
    Q_OBJECT
public:
    enum FirstStep {ModeConfig = 1};
    enum NewFlowSteps { ExperConfig = 2,SettingConfig = 3,PatternConfig=4,PatternPreview=5,
       DescConfig = 6,AnaConfig = 7,TimeConfig = 8, SummaryConfig = 9
   };

    enum PreviousFlowSteps {
        FromSqlJsonConfig = 2,
        AdjustConfigFirstStep = 3,
        AdjustConfigSecondStep = 4
    };

    explicit ScanVesselConfig(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent*e) override;
    void setCurrentUser(QCString user);
private:
    void setProgressBar();
    void addStackedWidgets();
    QHBoxLayout* setButton();
    void onProgressValue(int value);
    void onNext();
    void onNextNew();
    void onNextPrevious();
    void onNextCurrent();
    void onPrevious();
private slots:
    void setCreateMode(ScanCreateMode mode);
private:
    ProgressBar * mProgressBar;
    QStackedWidget * mStack;
    PushButton * mNext;
    PushButton * mPrevious;
    ScanCreateConfig * mCreateConfig;

    ScanExperimentConfig * mExperConfig = nullptr;
    ScanSettingConfig * mSettingConfig = nullptr;
    ScanWellConfig * mWellConfig = nullptr;
    ScanWellPreview * mWellPreview = nullptr;
    ScanDescriptionConfig * mDescConfig = nullptr;
    ScanAnalysisConfig * mAnaConfig = nullptr;
    ScanTimeConfig * mTimeConfig = nullptr;
    ScanVesselSummary * mSummary = nullptr;

    ScanPreviousFlow * mCopyPrevious = nullptr;
    ScanPreviousModifyFirst * mModifyPreviousFirst = nullptr;
    ScanPreviousModifySecond * mModifyPreviousSecond = nullptr;
private:
    ScanConfigData data;
};
#endif // SCANVESSELCONFIG_H
