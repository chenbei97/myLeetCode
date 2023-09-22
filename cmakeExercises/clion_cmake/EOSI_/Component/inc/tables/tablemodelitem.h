#ifndef TABLEMODELITEM_H
#define TABLEMODELITEM_H

#include "tablemodeldata.h"

class COMPONENT_IMEXPORT TableModelItem
{
private:
    QVector<TableModelData> mRoleData;
public:
    explicit TableModelItem();
    explicit TableModelItem(const QVariant&value,int role);
    explicit TableModelItem(const QMap<int, QVariant> &roles);

    void setData(const QVariant&value,int role = Qt::UserRole+1);
    QVariant data(int role = Qt::UserRole+1) const;

    void setItemData(const QMap<int, QVariant> &roles);
    QMap<int, QVariant>	itemData() const;

};

Q_DECLARE_METATYPE(TableModelItem)

#endif // TABLEMODELITEM_H
