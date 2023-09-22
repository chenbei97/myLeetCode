#ifndef TABLE_384_H
#define TABLE_384_H

#include "qitemselectionmodel.h"
#include "tableview.h"
#include "tablemodel.h"
#include "tableviewdelegate2x2.h"

class COMPONENT_IMEXPORT Table_384 : public QWidget
{
    Q_OBJECT
    TableViewDelegate2x2 * mDelegate;
    TableModel * mModel;
    TableView * mView;
    QItemSelectionModel * mSelection;
public:
    explicit Table_384(QWidget *parent = nullptr);

    inline QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
    {return mModel->data(index,role);};
    inline QVariant data(int row,int col, int role = Qt::DisplayRole) const
    {return mModel->data(index(row,col),role);};
    inline bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) // 不要使用setData来设置而应该使用下方的setPixmap
    {if (role == Qt::DecorationRole) return false; return mModel->setData(index,value,role);}; // 这里设置无法保证数量一定是4还不知道位置信息,会出现越界问题
    inline bool setData(int row,int col, const QVariant &value, int role = Qt::EditRole)
    {if (role == Qt::DecorationRole) return false;return mModel->setData(index(row,col),value,role);};

    inline bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles) //setItemData同理
    {if (roles.keys().contains(Qt::DecorationRole)) return false; return mModel->setItemData(index,roles);};
    inline bool setItemData(int row,int col, const QMap<int, QVariant> &roles)
    {if (roles.keys().contains(Qt::DecorationRole)) return false;return mModel->setItemData(index(row,col),roles);};
    inline QMap<int, QVariant>	itemData(const QModelIndex &index) const
    {return mModel->itemData(index);};
    inline QMap<int, QVariant>	itemData(int row,int col) const
    {return mModel->itemData(index(row,col));};

    inline QModelIndex index(int row,int col) const
    {return mModel->index(row,col);}

    /*定义一些常用的快捷函数*/
    bool setPixmap(int row,int col,int pos,QPixmap*pix);
    bool setPixmap(int row,int col,int pos,const QPixmap&pix);
    bool setPixmaps(int row,int col, const QVector<QPixmap*> &pixs);
    bool setPixmaps(int row,int col, const QVector<QPair<int,QPixmap*>> &pixs);
    QVector<QPixmap*> pixmaps(int row,int col) const;
    QPixmap* pixmap(int row,int col,int pos) const;

    bool setCurrentItem(int row,int col,uint32_t info);
    bool setSelectedItems(int row,int col, uint32_t info);

signals:
    void currentItemChanged(int row,int col);

private slots:
    void onCurrentItemChanged(int row,int col);
};

#endif // TABLE_384_H
