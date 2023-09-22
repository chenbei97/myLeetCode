#include "../../inc/flow/scanjsonreadwrite.h"

ScanJsonReadWrite::ScanJsonReadWrite(QObject *parent):JsonReadWrite(parent)
{ // 特殊处理
    specialObjectKeys<<"group";
}

void ScanJsonReadWrite::parseSpecialObject(const QJsonValue &key,const QJsonValue &value)
{
    if (key == "group") {
        auto arr = value.toArray(); // group的值本身是个大列表
        QGroupNameVector groupNames;
        QGroupPointVector groupPoints;
        QGroupPointNameVector groupPointNames;
        foreach (auto ele, arr) // 遍历列表,每个列表是个组对象,对象的值是个列表
        {
            auto obj = ele.toObject(); // 组对象{"A":[]},只包含一个对象"A",其值是个列表
            Q_ASSERT(obj.keys().count() == 1);
            auto groupname = obj.keys().at(0); // 组对象的键值是用户取的组名称
            groupNames.append(groupname);
            auto garr  = obj.value(groupname).toArray() ; // 根据组名称获取组的值列表
            QPointVector pointlist(garr.count());
            QStringVector pointname(garr.count());
            for(int i = 0 ; i <garr.count(); ++ i ) {
                auto gobj = garr.at(i).toObject(); // 数组内都是点对象
                auto x = gobj.value("x").toInt(); // 点的取值
                auto y = gobj.value("y").toInt();
                auto n = gobj.value("pname").toString();
                auto o = gobj.value("order").toInt();
                pointlist[o] = QPoint(x,y);
                pointname[o] = n;
                //qDebug()<<groupname<<x<<y<<n<<o;
            }
            groupPoints.append(pointlist);
            groupPointNames.append(pointname);
        }
        QVariant var;
        PointVectorPair v1 = qMakePair(groupPoints,groupPointNames);
        GroupVectorPair v2 = qMakePair(groupNames,v1);
        var.setValue(v2);
        parseData["group"] = var;
    }
}
