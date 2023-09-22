#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include "qcolor.h"
#include "qabstractitemmodel.h"
#include "tablemodelitem.h"

class COMPONENT_IMEXPORT TableModelSize
{
public:
    inline TableModelSize(): rows(0),cols(0) {}
    inline bool operator==(const TableModelSize &other) const
    {return rows == other.rows && cols == other.cols;};
    int rows;
    int cols;
};
Q_DECLARE_METATYPE(TableModelSize)

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    QList<QVector<TableModelItem>> mItems;
public:
    explicit TableModel(QObject *parent = nullptr);

    void setItemCount(int rows,int cols);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

//    bool	setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool	insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool	insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles) override;
    QMap<int, QVariant>	itemData(const QModelIndex &index) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
private:

};

#endif // TABLEMODEL_H
