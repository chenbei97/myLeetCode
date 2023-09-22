#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include "qbrush.h"
#include "qsqltablemodel.h"
#include "../public.h"

class COMPONENT_IMEXPORT SqlTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit SqlTableModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const override;
    QVariant data(int row, int col, int role) const;
    QString data(int row,int col) const;
    void setTable(const QString &tableName) override;
signals:
    void tableSettled(const QString& tableName);
    void tableChanged(const QString& tableName);
};

#endif // SQLTABLEMODEL_H
