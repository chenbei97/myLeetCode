#ifndef SCANPREVIOUSTABLE_H
#define SCANPREVIOUSTABLE_H

#include "../../../include/tables/tableviewdelegateint.h"
#include "../../../include/utilities/number.h"
#include "../../../include/tables/tableview.h"
#include "scanprevioustablemodel.h"

class ScanPreviousTable : public QWidget
{
    Q_OBJECT
public:
    explicit ScanPreviousTable(QWidget *parent = nullptr);
    explicit ScanPreviousTable(int rows,int cols,QWidget *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant data(int row,int col, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool setData(int row,int col, const QVariant &value, int role = Qt::EditRole);

    void setHeaderData(const QStringList&labels,Qt::Orientation oriention = Qt::Horizontal);

    void setRowData(int row,const QVariantList& rowValues,int role = Qt::EditRole);
    void setRowData(int row,const QStringList& rowValues);

    QModelIndex index(int row,int col) const;

    void appendRowData(const QStringList& rowValues);
    void appendRowData(const QStringList& rowValues,const QColor& color,int colorRole);

    void clearData();
    void clear();

    void setSectionBackgroundColor(QCColor color = Qt::white);
    void updateDelegateIntRange(int row,int col);

    QGroupNameVector groupNames() const;
    int groupCount() const;

    QPointVector groupPoints(QCString group) const;
    QPointNameVector groupPointNames(QCString group) const;
    QVector<int> groupPointOrders(QCString group) const;

    QGroupPointVector groupPoints() const;
    QGroupPointNameVector groupPointNames() const;
    QVector<QVector<int>> groupPointOrders() const;

    void updateBackgroundColor(QCColorVector colors);

    bool rowCompeled();
    bool orderValid();
private:
    void init();
    QAction * mAppendRow;
    QAction * mDeleteRow;
    QAction * mClearData;
    QAction * mRefresh;

    TableView * mView;
    QItemSelectionModel * mSelection;
    ScanPreviousTableModel * mModel;
private slots:
    void onCurrentRowChanged(const QModelIndex & current);
    void onAppendRow();
    void onDeleteRow();
    void onRefresh();
    void onItemChanged(QStandardItem*item);
signals:
    void currentPoint(int row,int col);
    void dataCleared();
    void itemDataChanged();
    void tableRefreshed();
};

#endif // SCANPREVIOUSTABLE_H
