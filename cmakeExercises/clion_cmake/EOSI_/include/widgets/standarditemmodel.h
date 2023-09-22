#ifndef STANDARDITEMMODEL_H
#define STANDARDITEMMODEL_H

#include"qstandarditemmodel.h"
#include "../public.h"

class COMPONENT_IMEXPORT StandardItemModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit StandardItemModel(QObject *parent = nullptr);
    explicit StandardItemModel(int rows, int columns, QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // STANDARDITEMMODEL_H
