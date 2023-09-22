#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include "qheaderview.h"
#include "qtableview.h"
#include "../public.h"

class COMPONENT_IMEXPORT TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent*e) override;
    void updateGeometries() override;
    void updateCellSize();
    void setModel(QAbstractItemModel *model) override;
private:
    void initGeneralConfig();
private slots:
    void onClicked(const QModelIndex &index);
    void onDoubleClicked(const QModelIndex &index);
    void onPressed(const QModelIndex &index);
signals:
    void mouseRightButtonPressed();
    void modelSettled(QAbstractItemModel * model);
    void modelChanged(QAbstractItemModel * model);
};

#endif // TABLEVIEW_H
