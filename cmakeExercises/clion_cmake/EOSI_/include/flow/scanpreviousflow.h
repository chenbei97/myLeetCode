#ifndef SCANPREVIOUSFLOW_H
#define SCANPREVIOUSFLOW_H

#include "../../../include/widgets/pushbutton.h"
#include "../../../include/widgets/gradienthiddenwidget.h"
#include "../../../include/utilities/jsonreadwrite.h"

#include "scanvesselsummary.h"
#include "qprogressdialog.h"
#include "scanjsonreadwrite.h"
#include "scanpreviousfromsql.h"

class ScanPreviousFlow : public GradientHiddenWidget
{
    Q_OBJECT
public:
    explicit ScanPreviousFlow(QWidget *parent = nullptr);
    void setCurrentUser(const QString& user);
    void setStyle(QCString style);
    QVariantMap parseData();
private:
    PushButton * mFromSql;
    PushButton * mFromJson;
    bool wasCanceled = false;
    QVariantMap config;
    ScanPreviousFromSql * mSqlDlalog;
private slots:
    void onFromSql();
    void onFromJson();
signals:

};

#endif // SCANPREVIOUSFLOW_H
