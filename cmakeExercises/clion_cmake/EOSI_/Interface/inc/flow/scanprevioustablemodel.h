#ifndef SCANPREVIOUSTABLEMODEL_H
#define SCANPREVIOUSTABLEMODEL_H

#include "qstandarditemmodel.h"

#define GroupNameColumn 0
#define PointXColumn 1
#define PointYColumn 2
#define PointNameColumn 3
#define PointOrderColumn 4

class ScanPreviousTableModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit ScanPreviousTableModel(QObject *parent = nullptr);
    explicit ScanPreviousTableModel(int rows, int columns, QObject *parent = nullptr);
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // SCANPREVIOUSTABLEMODEL_H
