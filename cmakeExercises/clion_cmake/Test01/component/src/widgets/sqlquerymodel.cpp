#include "../../inc/widgets/sqlquerymodel.h"

SqlQueryModel::SqlQueryModel(QObject*parent):QSqlQueryModel(parent)
{

}

QVariant SqlQueryModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole)
        return  Qt::AlignCenter;
    return QSqlQueryModel::data(index, role);
}

void SqlQueryModel::sort(int column, Qt::SortOrder order)
{ // QAbstractItemModel 默认什么也没做这里也是
    Q_UNUSED(column);
    Q_UNUSED(order);
}
