#include "../../inc/widgets/standarditemmodel.h"

StandardItemModel::StandardItemModel(QObject *parent) : QStandardItemModel(parent)
{

}

StandardItemModel::StandardItemModel(int rows, int columns, QObject *parent):QStandardItemModel(rows,columns,parent)
{

}

QVariant StandardItemModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole)
        return  Qt::AlignCenter;

    return QStandardItemModel::data(index, role);
}
