#include "../../inc/flow/scangroupdata.h"

ScanGroupData::ScanGroupData(QObject *parent) : QObject(parent)
{

}

void ScanGroupData::addGroup(int group,QCPointVector points,QCStringVector pointNames)
{
    QGroupPairData pair = qMakePair(points,pointNames);
    mData.insert(group,pair);
}

void ScanGroupData::addPoint(int group,QCPoint point,QCString name)
{
    auto pair = mData[group];
    auto points = pair.first;
    auto names = pair.second;
    points.append(point);
    names.append(name);
    mData[group] = qMakePair(points,names);
}

void ScanGroupData::removePoint(int group,QCPoint point)
{
    auto pair = mData[group];
    auto points = pair.first;
    auto names = pair.second;

    auto idx = points.indexOf(point);
    points.removeAt(idx);
    names.removeAt(idx);
    mData[group] = qMakePair(points,names);
}

void ScanGroupData::removePoint(int group,QCString name)
{
    auto pair = mData[group];
    auto points = pair.first;
    auto names = pair.second;

    auto idx = names.indexOf(name);
    points.removeAt(idx);
    names.removeAt(idx);
    mData[group] = qMakePair(points,names);
}

bool ScanGroupData::pointInGroup(int group,QCPoint point) const
{ // 保证组内位置不重复
    auto pair = mData[group];
    auto points = pair.first;
    if (points.count(point)) return true;
    return false;
}

bool ScanGroupData::pointInGroup(int group,QCString name) const
{ // 保证组内名称不重复
    auto pair = mData[group];
    auto names = pair.second;
    if (names.count(name)) return true;
    return false;
}

bool ScanGroupData::pointInGroups(QCPoint point) const
{ // 保证所有组位置不重复，名称可以重复
    foreach(auto group,mData.keys()) {
        if (pointInGroup(group,point))
            return true;
    }
    return false;
}

void ScanGroupData::setGroupName(int group,QCString name)
{ // 不用检查是否包含
    mName[group] = name;
}

bool ScanGroupData::setPoints(int group,QCPointVector points)
{ // 点和名称必须成对,要检查
    if (!mData.contains(group)) return false;

    auto oldpair = mData[group];
    auto newpair = qMakePair(points,oldpair.second);
    mData[group] = newpair;
    return  true;
}

bool ScanGroupData::setPointNames(int group,QCStringVector pointNames)
{// 点和名称必须成对,要检查
    if (!mData.contains(group)) return false;

    auto oldpair = mData[group];
    auto newpair = qMakePair(oldpair.first,pointNames);
    mData[group] = newpair;
    return  true;
}

void ScanGroupData::removeGroup(int group)
{
    mName.remove(group);
    mData.remove(group);
}

void ScanGroupData::removeGroup(QCString name)
{
    auto group = mName.key(name);
    mName.remove(group);
    mData.remove(group);
}

void ScanGroupData::clear()
{
    mName.clear();
    mData.clear();
}

QPointVector ScanGroupData::points(int group) const
{
    if (!mData.contains(group)) return QPointVector();
    auto d = mData.value(group);
    //LOG<<"group = "<<group<<" points = "<<d.first;
    return d.first;
}

QStringVector ScanGroupData::pointNames(int group) const
{
    if (!mData.contains(group)) return QStringVector();
    auto d = mData.value(group);
    return d.second;
}

QString ScanGroupData::groupName(int group) const
{
    if (!mName.contains(group)) return "";
    return mName.value(group);
}

QStringVector ScanGroupData::groupNames() const
{
    return mName.values().toVector();
}

int ScanGroupData::groupCount() const
{
    //LOG<<"group's count = "<<mData.count()<<"  "<<mName.count();
    //assert(mData.keys().count() == mName.keys().count());
    // 不相等,添加组mName变化,儿添加点后才会给mData扩展
    return mName.count();
}

int ScanGroupData::groupPointCount(int group) const
{
    return points(group).count();
}

QList<int> ScanGroupData::groups() const
{
    return mName.keys();
}

GroupData ScanGroupData::groupData(int group) const
{
    GroupData data;
    data.groupName = groupName(group);
    data.pointNames = pointNames(group);
    data.points = points(group);
    return data; // 可能返回不存在的group数据
}

GroupDataVector ScanGroupData::groupDatas() const
{
    GroupDataVector list;
    foreach(auto group, groups()) { //保证是已存在的keys
        auto data = groupData(group);
        if (!isGroupDataEmpty(data)) // 空组忽略
            list.append(data);
    }
    return list;
}
