#ifndef SCANSETTINGCONFIG_H
#define SCANSETTINGCONFIG_H

#include "../../../include/widgets/gradienthiddenwidget.h"
#include "../../../include/widgets/pattern.h"
#include "../../../include/widgets/combobox.h"
#include "../../../include/widgets/viewcircle.h"

class ScanSettingConfig : public GradientHiddenWidget
{
    Q_OBJECT
public:
    explicit ScanSettingConfig(QWidget *parent = nullptr);
    QString channel();
    int views();
    QString objective();
    int wellsize();
private:
    ComboBox * mChannels;
    ComboBox * mObjectives;
    ComboBox * mViews;
    ComboBox * mWells;
    ViewCircle * mViewCircle;
    Pattern * mPattern;
private slots:
    void toggleWellsize(int index);
    void toggleView(const QString& views);
    void updateView(int index);
signals:
};

#endif // SCANSETTINGCONFIG_H
