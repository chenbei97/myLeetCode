#include "../../inc/widgets/sqltablemodel.h"

SqlTableModel::SqlTableModel(QObject *parent, QSqlDatabase db):QSqlTableModel(parent,db)
{

}

QVariant SqlTableModel::data(const QModelIndex &idx, int role) const
{
    if (role == Qt::BackgroundRole && isDirty(idx))
        return QBrush(QColor(Qt::yellow)); // 修改过数据
    if (role == Qt::TextAlignmentRole)
        return  Qt::AlignCenter;
    return QSqlTableModel::data(idx, role);
}

QVariant SqlTableModel::data(int row,int col, int role) const
{
    auto idx = index(row,col);
    return data(idx,role);
}

QString SqlTableModel::data(int row,int col) const
{
    return data(row,col,Qt::DisplayRole).toString();
}

void SqlTableModel::setTable(const QString &tableName)
{
//    if (this->tableName() != tableName) {
//        QSqlTableModel::setTable(tableName);
//        emit tableChanged(tableName);
//    }
    auto old = this->tableName();
    QSqlTableModel::setTable(tableName);
    emit tableSettled(tableName);
    if (tableName != old)
        emit tableChanged(tableName);

}
