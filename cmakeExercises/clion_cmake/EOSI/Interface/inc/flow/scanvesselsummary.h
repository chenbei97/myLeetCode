#ifndef SCANVESSELSUMMARY_H
#define SCANVESSELSUMMARY_H

#include "widgets/gradienthiddenwidget.h"
#include "widgets/textedit.h"
#include "widgets/pattern.h"
#include "utilities/randomcolor.h"
#include "utilities/path.h"

#include "scanconfigdata.h"
#include "qcheckbox.h"
#include "scandatasave.h"

class ScanVesselSummary : public GradientHiddenWidget
{
    Q_OBJECT
public:
    typedef  const QVector<QPoint> QPointList;
    explicit ScanVesselSummary(QWidget *parent = nullptr);
    void translate(const ScanConfigData&d);
    bool saveToSql();
    bool saveToJson();
    bool sendToSocket();
    QString flag() const;
private:
    QString scanWellsize() const;
    QString scanTrajectory();
    QHBoxLayout * toplay();
private:
    QTextEdit * mPannel;
    Pattern * mPattern;
    QCheckBox * mCheckBox;
    Label * mCountdown;
    LineEdit * mNameEdit;
    QTimer timer;
    ScanConfigData data;
signals:
    void started();
    void finished();
};

#endif // SCANVESSELSUMMARY_H
