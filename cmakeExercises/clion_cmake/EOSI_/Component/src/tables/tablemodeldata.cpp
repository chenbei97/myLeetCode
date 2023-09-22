#include "../../inc/tables/tablemodeldata.h"

TableModelData::TableModelData(): role(-1)
{

}

TableModelData::TableModelData(int r,const QVariant&v): role(r),value(v)
{

}

bool TableModelData::operator==(const TableModelData &other) const
{
    return role == other.role && value == other.value;
}

#ifndef QT_NO_DATASTREAM

inline QDataStream &operator>>(QDataStream &in, TableModelData &data)
{
    in >> data.role;
    in >> data.value;
    return in;
}

inline QDataStream &operator<<(QDataStream &out, const TableModelData &data)
{
    out << data.role;
    out << data.value;
    return out;
}

#endif // QT_NO_DATASTREAM
