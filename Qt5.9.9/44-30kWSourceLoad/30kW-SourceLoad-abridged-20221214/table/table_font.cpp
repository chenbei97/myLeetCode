#include <table/table.h>


void Table::setBold(bool checked)
{
    if (!mSelectionModel->hasSelection()) return; // 没有选中任何项
    QModelIndexList idxs = mSelectionModel->selectedIndexes();
    QModelIndex idx;
    foreach (idx, idxs){
        QStandardItem * item = mStandardModel->itemFromIndex(idx);
        QFont font = item->font();
        font.setBold(checked);
        item->setFont(font);
    }
}

void Table::setItalic(bool checked)
{
    if (!mSelectionModel->hasSelection()) return; // 没有选中任何项
    QModelIndexList idxs = mSelectionModel->selectedIndexes();
    QModelIndex idx;
    foreach (idx, idxs){
        QStandardItem * item = mStandardModel->itemFromIndex(idx);
        QFont font = item->font();
        font.setItalic(checked);
        item->setFont(font);
    }
}

void Table::setAlign(AlignType type)
{
    Qt::Alignment m = Qt::AlignCenter;
    switch (type) {
        case AlignType::Left: m = Qt::AlignLeft | Qt::AlignVCenter; break;
        case AlignType::Right: m = Qt::AlignRight | Qt::AlignVCenter; break;
        default:break;
    }

    if (!mSelectionModel->hasSelection()) return; // 没有选中任何项
    QModelIndexList idxs = mSelectionModel->selectedIndexes();
    QModelIndex idx;
    foreach (idx, idxs){
        QStandardItem * item = mStandardModel->itemFromIndex(idx);
        item->setTextAlignment(m);
    }
}

void Table::clear()
{ // 清空表格文本,但是不清除表格结构
    // 方法1,这个会清除表格结构,所以要重新初始化模型并构建连接
//    mStandardModel->clear();
//    delete mStandardModel;
//    initModels(mTableSize.row,mTableSize.col);
//    initConnections();

    // 方法2,选中的区域才能清除文本
//    QModelIndexList idxs = mSelectionModel->selectedIndexes();
//    if (idxs.empty()) return;
//    QModelIndex idx;
//    QStandardItem * item;
//    foreach(idx ,idxs)
//    {
//        item = mStandardModel->itemFromIndex(idx);
//        if (item->text()!="")
//        {
//            QStandardItem * olditem = mStandardModel->takeItem(idx.row(),idx.column());
//            delete olditem;
//            QStandardItem * newitem = new QStandardItem;
//            mStandardModel->setItem(idx.row(),idx.column(),newitem);
//        }
//    }
    // 方法3,不需要选中区域
    QTime t;
    t.start();
    for (int row = 0 ; row < mTableSize.row ; ++row)
    {
            QModelIndex idx;
            QStandardItem * item;
            for (int col = 0; col < mTableSize.col; ++col)
            {
                 idx = mStandardModel->index(row,col); // 使用item/takeItem获得的item访问text会异常
                 item = mStandardModel->itemFromIndex(idx);
                 if (item->text()!="") // 不为空的单元格清除
                 {
                     QStandardItem * olditem = mStandardModel->takeItem(row,col);
                     delete olditem;
                     QStandardItem * newitem = new QStandardItem;
                     newitem->setTextAlignment(Qt::AlignCenter);
                     mStandardModel->setItem(row,col,newitem);
                 }
            }
    }

    // 表头也要清理,变为默认的1,2,3,4..编号
    QStringList newHeader;
    for(int col = 1; col <= mTableSize.col; ++ col) newHeader<<QString::number(col);
    mStandardModel->setHorizontalHeaderLabels(newHeader);//没有啥好方法只能覆盖处理
    qDebug()<<"clear cost time = "<<t.elapsed()/1000.0 <<"s"; //114.496s
}

void Table::clearConcurrent()
{
    QTime t;
    t.start();
    QFuture<void> future = QtConcurrent::run(this,&Table::clear);
    while (!future.isFinished()) QApplication::processEvents(QEventLoop::AllEvents, 5);
    if (future.isFinished() ) {
        qDebug()<<"clearConcurrent cost time = "<<t.elapsed()/1000.0 <<"s"; //
    }
}

void Table::reset(int row, int col)
{
    if (row < 0 || col <0 ) {
        QMessageBox::critical(Q_NULLPTR,tr("错误"),tr("表格行列数不能为0!"));
        return;
    }
    bool isEmpty = true;
    for (int r = 0 ; r < mTableSize.row ; ++r)
    {
            for (int c = 0; c < mTableSize.col; ++c)
            {
                 QModelIndex idx = mStandardModel->index(r,c);
                 QStandardItem *item = mStandardModel->itemFromIndex(idx);
                 if (item->text()!="") // 存在不为空的单元格
                 {
                    isEmpty = false;
                    break;
                 }
            }
    }
    if (!isEmpty)
    {
        int ret = QMessageBox::warning(Q_NULLPTR,tr("警告"),
                             tr("表格不为空,重置丢失内容,是否要继续?"),
                             QMessageBox::Yes,QMessageBox::Cancel);
        if (ret == QMessageBox::No) return; // 不为空,取消重置直接返回
    }

    // 其它情况: 为空或者不为空但是仍然重置
    mStandardModel->clear();
    delete mStandardModel;
    initModels(row,col);
    initConnections();

}

void Table::reset(const TableSize & size)
{
        reset(size.row,size.col);
}

void Table::setColor(QColor fore, QColor back)
{
        mForeColor = fore;
        mBackColor = back;
}

void Table::setHeader(const QStringList & headers)
{
    mStandardModel->setHorizontalHeaderLabels(headers);
}

QStringList Table::header() const
{
        QStringList headers;
        QStandardItem * item;
        for(int col = 0 ; col < mStandardModel->columnCount(); ++col)
        {
            item = mStandardModel->horizontalHeaderItem(col);
            headers << item->text();
        }
        return  headers;
}

void Table::setDelegate(DelegateType type)
{

}
