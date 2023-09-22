#include "../../inc/flow/scanconfigdata.h"

ScanConfigData::ScanConfigData(QObject *parent) : QObject(parent)
{
    reset();
}

ScanConfigData::ScanConfigData(const ScanConfigData&d)
{
    copy(d);
}

ScanConfigData& ScanConfigData::operator=(const ScanConfigData&d)
{
   copy(d);
    return *this;
}

void ScanConfigData::reset()
{
    progress = 1;
    create_mode = ScanCreateMode::EmptyMode;
    resetExcludeProgressAndMode();
}

void ScanConfigData::resetExcludeProgressAndMode()
{
    //currentUser.clear(); // 不要清除
    wellsize = 0;
    channel.clear();
    view = 0;
    objective.clear();
    groupNames.clear();
    groupPointLists.clear();
    groupNameLists.clear();

    experiment_name.clear();
    experiment_person.clear();
    experiment_celltype.clear();
    experiment_description.clear();
    experiment_type.clear();

    analysis_type.clear();
    analysis_notes.clear();
    analysis_definition.clear();
    analysis_spec_1 = 0.0;
    analysis_spec_2 = 0.0;

    schedule_total_time = 0;
    schedule_duration_time = 0;
    schedule_total_count = 0;
    schedule_start_datetime = QDateTime();
    schedule_end_datetime = QDateTime();

    once_total_time = 0;
    once_duration_time = 0;
    once_total_count = 0;
    is_schedule = 1;

    save_time = QDateTime();
}

void ScanConfigData::copy(const ScanConfigData &d)
{
    currentUser = d.currentUser;
    progress = d.progress;

    create_mode = d.create_mode;
    wellsize = d.wellsize;
    channel = d.channel;
    view = d.view;
    objective = d.objective;

    groupNames = d.groupNames;
    groupPointLists = d.groupPointLists;
    groupNameLists = d.groupNameLists;

    experiment_name = d.experiment_name;
    experiment_person = d.experiment_person;
    experiment_celltype = d.experiment_celltype;
    experiment_description = d.experiment_description;
    experiment_type = d.experiment_type;

    analysis_type = d.analysis_type;
    analysis_definition = d.analysis_definition;
    analysis_spec_1 = d.analysis_spec_1;
    analysis_spec_2 = d.analysis_spec_2;
    analysis_notes= d.analysis_notes;

    schedule_start_datetime = d.schedule_start_datetime;
    schedule_end_datetime = d.schedule_end_datetime;
    schedule_total_time = d.schedule_total_time;
    schedule_duration_time = d.schedule_duration_time;
    schedule_total_count = d.schedule_total_count;

    once_total_time = d.once_total_time;
    once_duration_time = d.once_duration_time;
    once_total_count = d.once_total_count;
    is_schedule = d.is_schedule;

    save_time = d.save_time;
}

QVariantMap ScanConfigData::valuesForSocket() const
{ // 不同于sql和json,传给socket的信息只需要部分关键信息
    QVariantMap m;
    QVariant v1,v2;
    v1.setValue(groupNames);
    v2.setValue(groupPointLists);

    m[Field0x0000.objective] = objective;
    m[Field0x0000.channel] = channel;
    m[Field0x0000.view] = view;
    m[Field0x0000.wellsize] = wellsize;
    m[Field0x0000.groupNames] = v1;
    m[Field0x0000.groupPointLists] = v2;

    m[Field0x0000.is_schedule] = is_schedule;
    if (is_schedule) {
        m[Field0x0000.total] = schedule_total_time;
        m[Field0x0000.duration] = schedule_duration_time;
        m[Field0x0000.count] = schedule_total_count;
        m[Field0x0000.start] = schedule_start_datetime;
        m[Field0x0000.end] = schedule_end_datetime;
    } else {
        m[Field0x0000.total] = once_total_time;
        m[Field0x0000.duration] = once_duration_time;
        m[Field0x0000.count] = once_total_count;
        m[Field0x0000.start] = QDateTime();
        m[Field0x0000.end] = QDateTime();
    }
    return m;
}

QValueVector ScanConfigData::valuesForSql() const
{ //  ExperGeneralConfigFields规定的顺序,注意id是自动增长无需规定
    QValueVector list;
    list << save_time.toString(ExperConfigTableFields.other_fields.datetime_iso1); // datetime
    list << encry_color(currentUser); // 当前用户,登陆界面传过来的,要加密
    list << save_time.toString(ExperConfigTableFields.other_fields.datetime_num); // flag具备唯一性
    list << analysis_type;
    list << analysis_definition;
    list << analysis_notes;
    list << QString::number(analysis_spec_1);
    list << QString::number(analysis_spec_2);
    list << channel;
    list << experiment_celltype;
    list << experiment_description;
    list << experiment_name;
    list << experiment_person;
    list << experiment_type;
    QString groups;
    foreach(auto n, groupNames) groups += n + ',';
    groups.chop(1);
    list << groups; // 组名组合成"groupA,groupB,..."的形式 按照顺序
    QString pointpos;
    list << objective;
    if (is_schedule) {
        list << QString::number(schedule_total_count);
        list << QString::number(schedule_duration_time);
        list << schedule_end_datetime.toString(ExperConfigTableFields.other_fields.datetime_iso2);
        list << "1";
        list << schedule_start_datetime.toString(ExperConfigTableFields.other_fields.datetime_iso2);
        list << QString::number(schedule_total_time);
    } else {
        list << QString::number(once_total_count);
        list << QString::number(once_duration_time);
        list << "";
        list << "0";
        list << "";
        list << QString::number(once_total_time);
    }
    list << QString::number(view);
    list << QString::number(wellsize);

    return list;
}

QValuemap ScanConfigData::groupValuesForSql() const
{ // 返回同一条记录多个组的值
    QValuemap vals;
    auto count = groupNames.count();
    for(int i = 0; i < count; ++i) {
        QValueVector list;
        auto gname = groupNames.at(i);
        QString gpos;
        for(int j = 0; j < groupPointLists.at(i).count(); ++j) {
            auto pos = groupPointLists.at(i).at(j); // 第i组的第j个点
            gpos += QString("(%1,%2),").arg(pos.x()).arg(pos.y());
        }
        gpos.chop(1);
        QString pname;
        for(int j = 0; j < groupNameLists.at(i).count(); ++j) {
            auto pn = groupNameLists.at(i).at(j); // 第i组的第j个名字
            pname += pn+",";
        }
        pname.chop(1);
        list.append(encry_color(currentUser));
        list.append(save_time.toString(ExperConfigTableFields.other_fields.datetime_num)); // 作为flag
        list.append(gname);
        list.append(gpos);
        list.append(pname);// 一组list值是"groupA" ,"(),(),()", "a1,a2,a3"
        vals.append(list);
    }
    return vals;
}

QJsonObject ScanConfigData::valuesForJson() const
{
    QJsonObject object;
    object.insert(ExperConfigTableFields.wellsize,wellsize);
    object.insert(ExperConfigTableFields.channel,channel);
    object.insert(ExperConfigTableFields.view,view);
    object.insert(ExperConfigTableFields.objective,objective);

    QJsonArray parr; // 组列表
    for(int i = 0; i < groupNames.count(); ++i) { // 列表下边设计为多个组对象
        QJsonObject gobj; // 组对象
        auto groupName = groupNames.at(i);  // 每个组对象是一个点列表,存了多个点
        QJsonArray garr; // 组对象的值是个列表
        for (int j = 0; j < groupNameLists.at(i).count(); ++j) { // 不同组的点不一样
            QJsonObject pobj; // 点对象存到列表  {"order": 2,"pname": "111","x": 3,"y": 4}是个点对象
            auto point = groupPointLists.at(i).at(j);
            auto pointName = groupNameLists.at(i).at(j);
            pobj[ExperConfigTableFields.other_fields.x] = point.x();
            pobj[ExperConfigTableFields.other_fields.y] = point.y();
            pobj[ExperConfigTableFields.other_fields.pname] = pointName;
            pobj[ExperConfigTableFields.other_fields.order] = j;
            garr.append(pobj); // 把点对象存到点列表,下方点列表又作为组对象的值
        }
        gobj[groupName] = garr;  // "groupA" : [] 作为组对象的值
        parr.append(gobj); // 组列表添加组对象
    }
    object.insert(ExperConfigTableFields.other_fields.group,parr);

    QJsonObject eobj;
    eobj[ExperConfigTableFields.exper_name] = experiment_name;
    eobj[ExperConfigTableFields.exper_person] = experiment_person;
    eobj[ExperConfigTableFields.exper_type] = experiment_type;
    eobj[ExperConfigTableFields.exper_celltype] = experiment_celltype;
    eobj[ExperConfigTableFields.exper_description] = experiment_description;
    object.insert(ExperConfigTableFields.other_fields.experiment,eobj);

    QJsonObject aobj;
    aobj[ExperConfigTableFields.ana_type] = analysis_type;
    aobj[ExperConfigTableFields.ana_definition] = analysis_definition;
    aobj[ExperConfigTableFields.ana_spec1] = analysis_spec_1;
    aobj[ExperConfigTableFields.ana_spec2] = analysis_spec_2;
    aobj[ExperConfigTableFields.ana_notes] = analysis_notes;
    object.insert(ExperConfigTableFields.other_fields.analysis,aobj);


    QJsonObject tobj;
    if (!is_schedule) {
        tobj[ExperConfigTableFields.is_schedule] = false;
        tobj[ExperConfigTableFields.total] = once_total_time;
        tobj[ExperConfigTableFields.duration] = once_duration_time;
        tobj[ExperConfigTableFields.count] = once_total_count;
    }
    else {
        tobj[ExperConfigTableFields.is_schedule] = true;
        tobj[ExperConfigTableFields.total] = schedule_total_time;
        tobj[ExperConfigTableFields.duration] = schedule_duration_time;
        tobj[ExperConfigTableFields.count] = schedule_total_count;
        tobj[ExperConfigTableFields.start_time] = schedule_start_datetime
                .toString(ExperConfigTableFields.other_fields.datetime_iso2);
        tobj[ExperConfigTableFields.end_time] = schedule_end_datetime
                .toString(ExperConfigTableFields.other_fields.datetime_iso2);
    }
    object.insert(ExperConfigTableFields.other_fields.time,tobj);

    return object;

}

