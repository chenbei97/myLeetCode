#ifndef SCANGROUPDATA_H
#define SCANGROUPDATA_H

#include "../../../include/public.h"

#define GroupRole (Qt::UserRole+1)
#define PointRole (Qt::UserRole+2)

typedef struct  {
    QString groupName;
    QPointVector points;
    QStringVector pointNames;
} GroupData;
typedef QVector<GroupData>  GroupDataVector;

static bool isGroupDataEmpty(const GroupData&data){
    if (data.groupName.isEmpty() ||
            data.points.isEmpty() ||
            data.pointNames.isEmpty())
        return true;
    return false;
}

class ScanGroupData : public QObject
{
    Q_OBJECT
public:
    explicit ScanGroupData(QObject *parent = nullptr);

    void addGroup(int group,QCPointVector points,QCStringVector pointNames);
    void removeGroup(int group);
    void removeGroup(QCString name);
    void clear();

    void addPoint(int group,QCPoint point,QCString name);
    void removePoint(int group,QCPoint point);
    void removePoint(int group,QCString name);

    bool pointInGroup(int group,QCPoint point) const;
    bool pointInGroup(int group,QCString name) const;
    bool pointInGroups(QCPoint point) const;
    bool pointInGroups(QCString name) const;

    void setGroupName(int group,QCString name);
    bool setPoints(int group,QCPointVector points);
    bool setPointNames(int group,QCStringVector points);

    int groupCount() const;
    int groupPointCount(int group) const;
    QList<int> groups() const;

    QString groupName(int group) const;
    QStringVector groupNames() const;
    QPointVector points(int group) const ;
    QStringVector pointNames(int group) const;
    GroupData groupData(int group) const;
    GroupDataVector groupDatas() const;

private:
    QGroupData mData;
    QGroupName mName;
signals:

};

#endif // SCANGROUPDATA_H
