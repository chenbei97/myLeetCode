#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H

#include "qsqlquerymodel.h"
#include "../public.h"

class COMPONENT_IMEXPORT SqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit SqlQueryModel(QObject*parent = 0);
    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override; // 查询模型什么也没做

};

#endif // SQLQUERYMODEL_H
