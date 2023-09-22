#ifndef SCANCONFIGDATA_H
#define SCANCONFIGDATA_H

#include "tcp/tcpprotocol.h"
#include "utilities/sqlstatements.h"
#include "utilities/encry.h"
#include "scancreateconfig.h"

class ScanConfigData : public QObject
{
    Q_OBJECT
    void copy(const ScanConfigData&d);
public:
    typedef ScanCreateConfig::ScanCreateMode ScanCreateMode;

    ScanConfigData(QObject *parent = nullptr);
    ScanConfigData(const ScanConfigData&d);
    ScanConfigData& operator=(const ScanConfigData&d);

    void reset();
    void resetExcludeProgressAndMode();

    QJsonObject valuesForJson() const;
    QValueVector valuesForSql() const;
    QValuemap groupValuesForSql() const;
    QVariantMap valuesForSocket() const;
public:
    int progress = 1;

    QString currentUser;

    ScanCreateMode create_mode = ScanCreateMode::EmptyMode;
    int wellsize = 0;
    QString channel;
    int view  = 0;
    QString objective;

    QGroupNameVector groupNames;
    QGroupPointVector groupPointLists;
    QGroupPointNameVector groupNameLists;

    QString experiment_name;
    QString experiment_person;
    QString experiment_celltype;
    QString experiment_description;
    QString experiment_type;

    QString analysis_type;
    QString analysis_definition;
    double analysis_spec_1;
    double analysis_spec_2;
    QString analysis_notes;

    QDateTime schedule_start_datetime;
    QDateTime schedule_end_datetime;
    long long schedule_total_time = 0;
    long long  schedule_duration_time = 0;
    int schedule_total_count = 0;

    long long  once_total_time = 0;
    long long  once_duration_time = 0;
    int once_total_count = 0;
    int is_schedule = 1;

    QDateTime save_time;

signals:

};

#endif // SCANCONFIGDATA_H
