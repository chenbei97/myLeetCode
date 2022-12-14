#include <table/table.h>

int Table::row() const
{
    return mTableSize.row;
}

int Table::col() const
{
    return mTableSize.col;
}

void Table::appendRow()
{
    QList<QStandardItem*> itemList;
    QStandardItem * curr;
    for(int i = 0; i < mTableSize.col; ++i)
    {
        curr = new QStandardItem;
        curr->setTextAlignment(Qt::AlignCenter);
        itemList << curr;
    }
    mStandardModel->appendRow(itemList); // 添加工作完成

    // 下边只是为了选中新添加行的效果
    QModelIndex topLeft = mStandardModel->index(mTableSize.row,0); // 左下角
    QModelIndex bottomRight = mStandardModel->index(mTableSize.row,mTableSize.col-1);// 右下角
    QItemSelection selection(topLeft,bottomRight);

    mSelectionModel->clear();
    mSelectionModel->select(selection,QItemSelectionModel::Select);

    ++mTableSize.row; // 记得更新

    //qDebug()<<"mrow = "<<mStandardModel->rowCount()<<"  mcol = "<<mStandardModel->columnCount();
    //qDebug()<<"trow = "<<mTableSize.row<<"  tcol = "<<mTableSize.col;
}

void Table::appendRow(const QStringList & colData)
{
    QList<QStandardItem*> itemList;
    QStandardItem * curr;
    for(int i = 0; i < mTableSize.col; ++i)
    {
        curr = new QStandardItem(colData.at(i));
        curr->setTextAlignment(Qt::AlignCenter);
        itemList << curr;
    }
    mStandardModel->appendRow(itemList);
    QModelIndex topLeft = mStandardModel->index(mTableSize.row,0);
    QModelIndex bottomRight = mStandardModel->index(mTableSize.row,mTableSize.col-1);
    QItemSelection selection(topLeft,bottomRight);
    mSelectionModel->clear();
    mSelectionModel->select(selection,QItemSelectionModel::Select);
    ++mTableSize.row;
}

void Table::appendCol()
{
    QList<QStandardItem*> itemList;
    QStandardItem * curr;
    for(int i = 0; i < mTableSize.row; ++i)
    {
        curr = new QStandardItem;
        curr->setTextAlignment(Qt::AlignCenter);
        itemList << curr;
    }
    mStandardModel->appendColumn(itemList); // 添加工作完成

    // 下边只是为了选中新添加列的效果
    QModelIndex topLeft = mStandardModel->index(0,mTableSize.col); // 右上角
    QModelIndex bottomRight = mStandardModel->index(mTableSize.row-1,mTableSize.col);// 右下角
    QItemSelection selection(topLeft,bottomRight);

    mSelectionModel->clear();
    mSelectionModel->select(selection,QItemSelectionModel::Select);

    ++mTableSize.col; // 记得更新
}

void Table::insertRow()
{
    QModelIndex idx = mSelectionModel->currentIndex(); // 当前选中项的索引
    if (idx.row()<0 && idx.column() <0) return;// 没有选中任何项不能插入

    //if (!mSelectionModel->hasSelection()) return; // 不能用这条语句代替
    // 首次进入默认没选中任何项,选择1个项或者2个项或者1行点击插入行后mrow和trow是正常相等的
    // 此时再次点击插入行,表格虽然在上次插入选中了新插入的行,但是下方的idx却返回(-1,-1),好像是假选中
    // 这样mStandardModel->insertRow插入失败,但是++mTableSize.row就导致2个值不相等了

    QList<QStandardItem*> itemList;
    QStandardItem * curr;
    for(int i = 0; i < mTableSize.col; ++i)
    {
        curr = new QStandardItem;
        curr->setTextAlignment(Qt::AlignCenter);
        itemList << curr;
    }
    //QModelIndex idx = mSelectionModel->currentIndex();
    //qDebug()<<"idx = "<<idx;
    mStandardModel->insertRow(idx.row(),itemList); // 指定行位置插入工作完成

    // 下边只是为了选中新插入行的效果
    QModelIndex topLeft = mStandardModel->index(idx.row(),0); // 左边
    QModelIndex bottomRight = mStandardModel->index(idx.row(),mTableSize.col-1);// 右边
    QItemSelection selection(topLeft,bottomRight);

    mSelectionModel->clear();
    mSelectionModel->select(selection,QItemSelectionModel::Select);

    ++mTableSize.row; // 记得更新
}

void Table::insertRow(const QStringList & colData)
{
    QList<QStandardItem*> itemList;
    QStandardItem * curr;
    for(int i = 0; i < mTableSize.col; ++i)
    {
        curr = new QStandardItem(colData.at(i));
        curr->setTextAlignment(Qt::AlignCenter);
        itemList << curr;
    }
    mStandardModel->insertRow(0,itemList); // 指定插入第1行,本版本函数是给logData插入使用的
    QModelIndex topLeft = mStandardModel->index(0,0);
    QModelIndex bottomRight = mStandardModel->index(0,mTableSize.col-1);
    QItemSelection selection(topLeft,bottomRight);
    mSelectionModel->clear();
    mSelectionModel->select(selection,QItemSelectionModel::Select);
    ++mTableSize.row;
}

void Table::insertCol()
{
    QModelIndex idx = mSelectionModel->currentIndex(); // 当前选中项的索引
    if (idx.row()<0 && idx.column() <0) return; // 没有选中任何项不能插入

    QList<QStandardItem*> itemList;
    QStandardItem * curr;
    for(int i = 0; i < mTableSize.col; ++i)
    {
        curr = new QStandardItem;
        curr->setTextAlignment(Qt::AlignCenter);
        itemList << curr;
    }

    mStandardModel->insertColumn(idx.column(),itemList); // 指定列位置插入工作完成

    // 下边只是为了选中新插入列的效果
    QModelIndex topLeft = mStandardModel->index(0,idx.column()); // 上边
    QModelIndex bottomRight = mStandardModel->index(mTableSize.row-1,idx.column());// 下边
    QItemSelection selection(topLeft,bottomRight);

    mSelectionModel->clear();
    mSelectionModel->select(selection,QItemSelectionModel::Select);

    ++mTableSize.col; // 记得更新
}

void Table::removeRow()
{
    QModelIndex idx = mSelectionModel->currentIndex(); // 当前选中项的索引
    if (idx.row()<0 && idx.column() <0) return; // 没有选中任何项不能删除
    mStandardModel->removeRow(idx.row()); // 移除该行
    --mTableSize.row;

    // 下边只是为了选中删除行后替代行的效果
    if  (idx.row() != mTableSize.row - 1) // 如果删除的不是最后1行
    {// 如果删除的是最后1行不会有任何项被选中
        QModelIndex topLeft = mStandardModel->index(idx.row(),0); // 左边
        QModelIndex bottomRight = mStandardModel->index(idx.row(),mTableSize.col-1);// 右边
        QItemSelection selection(topLeft,bottomRight);// 仍然选中相同位置的行
        mSelectionModel->clear();
        mSelectionModel->select(selection,QItemSelectionModel::Select);
    }
}

void Table::removeCol()
{
    QModelIndex idx = mSelectionModel->currentIndex(); // 当前选中项的索引
    if (idx.row()<0 && idx.column() <0) return; // 没有选中任何项不能删除
    mStandardModel->removeColumn(idx.column()); // 移除该列
    --mTableSize.col;

    // 下边只是为了选中删除行后替代列的效果
    if  (idx.column() != mTableSize.col - 1) // 如果删除的不是最后1列
    {// 如果删除的是最后1列不会有任何项被选中
        QModelIndex topLeft = mStandardModel->index(0,idx.column()); // 上边
        QModelIndex bottomRight = mStandardModel->index(mTableSize.row-1,idx.column());// 下边
        QItemSelection selection(topLeft,bottomRight);// 仍然选中相同位置的列
        mSelectionModel->clear();
        mSelectionModel->select(selection,QItemSelectionModel::Select);
    }
}
