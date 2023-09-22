#include "../../inc/tables/tablemodel.h"

TableModel::TableModel(QObject *parent ):QAbstractTableModel(parent)
{

}

void TableModel::setItemCount(int rows,int cols)
{
    mItems.clear();

    QMap<int,QVariant> m;
    auto c1 = TableViewMouseHighlightColor;
    auto c2 = TableViewSelectedHighlightColor;
    auto c3 = TableViewCurrentHighlightColor;
    c1.setAlpha(TableViewHighlightColorAlpha);
    c2.setAlpha(TableViewHighlightColorAlpha);
    c3.setAlpha(TableViewHighlightColorAlpha);

    m[TableModelDataRole::CurrentItem] = 0;
    m[TableModelDataRole::SelectedItems] = 0;
    m[TableModelDataRole::HighlightColor] = c1;
    m[TableModelDataRole::SelectedColor] = c2;
    m[TableModelDataRole::CurrentColor] = c3;

    for(int r = 0; r < rows; ++r)
    {
        QVector<TableModelItem> items;
        for (int c = 0; c < cols; ++c)
            items.append(TableModelItem(m));
        mItems.append(items);
    }
}

int TableModel::rowCount(const QModelIndex&) const
{
    return mItems.count();
}

int TableModel::columnCount(const QModelIndex&) const
{
    if (rowCount() == 0)
        return 0;

    return mItems[0].count();
}

bool TableModel::setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles)
{
    if (rowCount() <= 0 || columnCount() <= 0) return false;

    if (index.row()+1 > rowCount() || index.column()+1 > columnCount())
        return false;

    auto item = mItems[index.row()].at(index.column());
    int role;
    QMapIterator<int, QVariant> iter(roles);
    while (iter.hasNext()) {
        iter.next();
        //LOG<<"iter  value = "<<iter.value()<<" key = "<<iter.key() <<" valid? "<<iter.value().isValid();
        if ( !iter.value().isValid())
            return false;
        role = (iter.key() == Qt::EditRole) ? Qt::DisplayRole : iter.key();
        item.setData(iter.value(),role);
    }
    mItems[index.row()].replace(index.column(),item);
    return true;
}

QMap<int, QVariant>	TableModel::itemData(const QModelIndex &index) const
{
    if (rowCount() <= 0 || columnCount() <= 0) return QMap<int, QVariant>();

    if (index.row()+1 > rowCount() || index.column()+1 > columnCount())
        return QMap<int, QVariant>();

    return mItems[index.row()].at(index.column()).itemData();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (rowCount() <= 0 || columnCount() <= 0) return QVariant();

    if (index.row()+1 > rowCount() || index.column()+1 > columnCount())
        return QVariant();

    return mItems[index.row()].at(index.column()).data(role);
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (rowCount() <= 0 || columnCount() <= 0) return false;

    if (index.row()+1 > rowCount() || index.column()+1 > columnCount())
        return false;

    if (!value.isValid() )
      return  false;

    role = (role == Qt::EditRole) ? Qt::DisplayRole : role;
    auto item = mItems[index.row()].at(index.column());

    item.setData(value,role);
    //LOG<<"item.data("<<role<<") = "<<item.data(role);
    mItems[index.row()].replace(index.column(),item);

    emit dataChanged(index, index);
    return true;
}

bool	TableModel::insertRows(int row, int count, const QModelIndex&parent)
{
    // [a,b]的元素是b-a+1个, [row,row+count-1]=count个
    beginInsertRows(parent, row, row+count-1);// row,row+1,..,row+count-1
    for(int c = 0;  c< count; ++c) // 指定位置row开始插入count行
    {
        mItems.insert(row,QVector<TableModelItem>(columnCount())); // 插入1行项,项的个数是列数
    }
    endInsertRows();
    return true;
}

bool	TableModel::insertColumns(int column, int count, const QModelIndex&parent)
{
    beginInsertColumns(parent,column,column+count-1);
    for(int row = 0; row < rowCount(); ++ row) // 每一行从指定列开始插入count个item
    {
        auto rowitems = mItems[row];
        auto iter = rowitems.begin() + column; // column=2,第3个(包含)开始插
        rowitems.insert(iter,count,TableModelItem());
        mItems[row] = rowitems; // 因为不是指针所以更新后替换
    }

    endInsertColumns();
    return true;
}

bool TableModel::removeRows(int row, int count, const QModelIndex&parent)
{
    if (row+count>rowCount()) // row=9,count=1,共10行,可以移除成功
        return false;
    beginRemoveRows(parent, row, row+count-1);
    for (int c = 0; c < count; ++c) {
        mItems.removeAt(row);
    }
    endRemoveRows();
    return true;
}

bool TableModel::removeColumns(int column, int count, const QModelIndex&parent)
{
    if (column+count>columnCount())
        return false;
    beginRemoveColumns(parent,column,column+count-1);
    for(int row = 0; row < rowCount(); ++ row)
    {
        auto rowitems = mItems[row];
        rowitems.remove(column,count);
        mItems[row] = rowitems;
    }

    endRemoveColumns();
    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    //return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // 展示图片不需要编辑
    // ItemIsEnabled and ItemIsSelectable 是默认行为
    return QAbstractItemModel::flags(index);
}

