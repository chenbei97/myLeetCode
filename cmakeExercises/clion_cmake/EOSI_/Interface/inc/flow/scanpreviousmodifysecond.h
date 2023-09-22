#ifndef SCANPREVIOUSMODIFYSECOND_H
#define SCANPREVIOUSMODIFYSECOND_H

#include "../../../include/widgets/pattern.h"
#include "../../../include/widgets/combobox.h"
#include "../../../include/widgets/label.h"
#include "../../../include/widgets/spinbox.h"
#include "../../../include/widgets/lineedit.h"
#include "../../../include/widgets/gradienthiddenwidget.h"
#include "../../../include/utilities/randomcolor.h"
#include "scanconfigdata.h"
#include "scanprevioustable.h"
#include "qcheckbox.h"
#include "scandatasave.h"

class ScanPreviousModifySecond : public GradientHiddenWidget
{
    Q_OBJECT
    ScanConfigData data;
    ScanConfigData modifydata;
public:
    ScanPreviousModifySecond(QWidget *parent = nullptr);
    void mapDataToUi(const ScanConfigData& d);
    void setModifyData(const ScanConfigData& d);
    ScanConfigData modifyData();
    bool saveToSql();
    bool saveToJson();
    bool sendToSocket();
    bool dataValid();
    QString flag() const;
private:
    void initObject();
    void initLayout();
    void initConnections();
private:
    void wellsizeChanged(int index);
    void signPatternPoint(int row,int col);
    void updatePatternGroupState();
private:
    ComboBox * mWellSize;
    QCheckBox * mSaveConfig;
    LineEdit * mSavePath;
    Pattern * mPattern;
    ScanPreviousTable * mTable;
    QVBoxLayout * patternlay;
signals:
    void currentWellSize(int row,int col);
    void started();
    void finished();
};

#endif // SCANPREVIOUSMODIFYSECOND_H
