#include "../../inc/tables/tablemodelitem.h"

TableModelItem::TableModelItem()
{

}

TableModelItem::TableModelItem(const QVariant&value,int role)
{
    setData(value,role);
}

TableModelItem::TableModelItem(const QMap<int, QVariant> &roles)
{
    setItemData(roles);
}

void TableModelItem::setItemData(const QMap<int, QVariant> &roles)
{
    int role;
    QMapIterator<int, QVariant> iter(roles);
    while (iter.hasNext()) {
        iter.next();

        if (!iter.value().isValid())
            continue;

        role = (iter.key() == Qt::EditRole) ? Qt::DisplayRole : iter.key();

        setData(iter.value(),role);
    }
}

QMap<int, QVariant>	TableModelItem::itemData() const
{
    QMap<int, QVariant> map;

    QVector<TableModelData>:: const_iterator it; // const成员函数
    for(it = mRoleData.begin();it != mRoleData.end(); ++it)
        map[ (*it).role] = (*it).value;

    return map;
}

void TableModelItem::setData(const QVariant &value, int role)
{
    role = (role == Qt::EditRole) ? Qt::DisplayRole : role;
    QVector<TableModelData>::iterator it;
    for(it = mRoleData.begin(); it != mRoleData.end(); ++it) {
        if ((*it).role == role) {// 如果已有这样角色的数据,应该覆盖处理
            if (value.isValid()){ // 数据有效
                if ((*it).value.type() == value.type() && (*it).value == value)
                    return; // 如果值的类型和大小和已有的相同,不用赋值
                (*it).value = value; // 覆盖值
            }
            return;
        }//end role
    }// end for

    // mRoleData没有数据,或者已有的数据角色不匹配新角色
    mRoleData.append(TableModelData(role,value));
}

QVariant TableModelItem::data(int role) const
{
    role = (role == Qt::EditRole) ? Qt::DisplayRole : role;
    QVector<TableModelData>::const_iterator it;
    for (it = mRoleData.begin(); it != mRoleData.end(); ++it) {
        if ((*it).role == role) // 返回指定角色对应的值
            return (*it).value;
    }
    return QVariant(); // 可能返回无效值
}
