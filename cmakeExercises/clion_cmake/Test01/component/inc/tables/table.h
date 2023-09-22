#ifndef TABLE_H
#define TABLE_H

#include "../widgets/standarditemmodel.h"
#include "tableviewdelegatelabel.h"
#include "tableview.h"

enum DelegateType {DefaultDelegate,LabelDelegate,Widget2x2Delegate};

class COMPONENT_IMEXPORT Table : public QWidget
{
    Q_OBJECT
protected:
    TableView * mView;
    QItemSelectionModel * mSelection;
    StandardItemModel * mModel;
    QStyledItemDelegate  * mDelegate;
    DelegateType mDelegateType;
public:
    explicit Table(QWidget *parent = nullptr);
    explicit Table(int rows,int cols,QWidget *parent = nullptr);

    void setItemCount(int rows,int cols);
    void setDelegate(QStyledItemDelegate*delegate);

    void setDelegateType(DelegateType type);
    DelegateType delegateType() const;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QVariant data(int row,int col, int role = Qt::DisplayRole) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual bool setData(int row,int col, const QVariant &value, int role = Qt::EditRole);

    virtual  bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles);
    virtual  bool setItemData(int row,int col, const QMap<int, QVariant> &roles);

    virtual  QMap<int, QVariant> itemData(const QModelIndex &index) const;
    virtual  QMap<int, QVariant> itemData(int row,int col) const;

    void setHeaderData(const QStringList&labels,Qt::Orientation oriention = Qt::Horizontal);

    void setRowData(int row,const QVariantList& rowValues,int role = Qt::EditRole);
    void setRowData(int row,const QStringList& rowValues);

    QModelIndex index(int row,int col) const;

    /*定义一些常用的快捷函数*/
    // 1. 代理是Label
    virtual bool setPixmap(int row,int col,QPixmap*pix);
    virtual bool setPixmap(int row,int col,const QPixmap&pix);
    virtual QPixmap* pixmap(int row,int col) const;
    virtual bool setCurrentItem(int row,int col,bool isCurrent = true);
    virtual bool setSelectedItem(int row,int col, bool isSelected = true);
    // 2. 代理是Widget2x2
    virtual bool setPixmap(int row,int col,int pos,QPixmap*pix);
    virtual bool setPixmap(int row,int col,int pos,const QPixmap&pix);
    virtual QPixmap* pixmap(int row,int col,int pos) const;
    virtual bool setCurrentItems(int row,int col,uint32_t info);
    virtual bool setSelectedItems(int row,int col, uint32_t info);
    virtual bool setPixmaps(int row,int col, const QVector<QPixmap*> &pixs);
    virtual bool setPixmaps(int row,int col, const QVector<QPair<int,QPixmap*>> &pixs);
    virtual QVector<QPixmap*> pixmaps(int row,int col) const;

private:
    void initLayout();
    void initObject();
    void initConnections();
signals:
    void currentItemChanged(int row,int col);
protected slots:
    void onCurrentItemChanged(int row,int col);
};

#endif // TABLE_H
