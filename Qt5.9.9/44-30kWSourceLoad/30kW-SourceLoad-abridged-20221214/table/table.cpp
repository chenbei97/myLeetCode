#include <table/table.h>

Table::Table(QTableView* tableview,int row, int col,QObject * parent) : QObject(parent)
{
        if (tableview == Q_NULLPTR) {
            qCritical()<<"QTableView's pointer cant not be nullptr!";
            return;
        }
        mBackColor = Qt::white; // 要初始化一下不然刚开始点击是黑色
        mForeColor = Qt::black;
        mTableView = tableview;
        initModels(row,col); // 先初始化model,最后初始化connect,不要改变顺序
        initConnections();
}

Table::Table(QTableView* tableview,TableSize size,QObject * parent) : QObject(parent)
{
    Table(tableview,size.row,size.col,parent); // 委托构造
}

void Table::initModels(int row,int col)
{
    mStandardModel = new QStandardItemModel(row,col,this);
    mSelectionModel = new QItemSelectionModel(mStandardModel);

    QStringList headerList;
    for (int j = 1; j <= col; ++j) headerList<<QString::number(j); // 不要用QString(j),乱码
    mStandardModel->setHorizontalHeaderLabels(headerList); // 默认表头是datetime,1,2,3..col的名称
    QtConcurrent::run([=]{ // 并行加速
    QStandardItem * item; // 创建空白项,这是防止用户导出个空表导致程序异常
    for (int r = 0 ; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            item = new QStandardItem;
            item->setTextAlignment(Qt::AlignCenter);
            mStandardModel->setItem(r,c,item);
        }
    }
    });
    mTableView->setModel(mStandardModel);
    mTableView->setSelectionModel(mSelectionModel);//必须先设置选择模型再设置模式和行为
    mTableView->setSelectionMode(QAbstractItemView::ExtendedSelection); // 可以使用ctrl和shift控制选择多个项
    mTableView->setSelectionBehavior(QAbstractItemView::SelectItems); // 点击时选择单个项而不是一列/行
//    mTableView->setSelectionMode(QAbstractItemView::NoSelection);// 不起作用
//    mTableView->clearSelection();
//    mSelectionModel->clearSelection();
    mTableSize = {row,col}; // 这里可能被reset调用,所以要更新mTableSize

}

QStandardItem* Table::takeItem(const QModelIndex & index) const
{
    return mStandardModel->itemFromIndex(index);
}

void Table::initConnections()
{
    // 项选择模型的5个信号: currentChanged,currentColumnChanged,currentRowChanged,modelChanged和selectionChanged
    connect(mSelectionModel,static_cast<void (QItemSelectionModel::*)(const QModelIndex&,const QModelIndex&)>(&QItemSelectionModel::currentChanged),
            this,[=](const QModelIndex& current,const QModelIndex& previous){
            Q_UNUSED(previous);
            if (current.isValid()) //单元格有效的话
            {
                emit cellCurrentIndex(current);
                QStandardItem * item = mStandardModel->itemFromIndex(current);
                QString content = tr("无");
                if (item->text()!="") content = item->text();
                emit cellCurrentContent(content);

                // 存在的问题是,首次进入时单元格总会选中(0,0),这样该单元格就会呈现颜色
                // 而且mTableView->clearSelection()和mSelectionModel->clearSelection()初始化模型时不起作用
                //item->setBackground(QBrush(mBackColor,Qt::SolidPattern));
                //item->setForeground(QBrush(mForeColor));
                // 所以格式的变化改为在mTableView的pressed信号下触发执行
            }
    });

    connect(mTableView,static_cast<void (QTableView::*)(const QModelIndex&)>(&QTableView::pressed),this,
            [=](const QModelIndex&idx){
            QStandardItem * item = mStandardModel->itemFromIndex(idx);
            item->setBackground(QBrush(mBackColor,Qt::SolidPattern));// 这时就不再出现上述问题
            item->setForeground(QBrush(mForeColor));
    });
//    connect(mSelectionModel,static_cast<void (QItemSelectionModel::*)(const QModelIndex&,const QModelIndex&)>(&QItemSelectionModel::currentColumnChanged),
//            this,[=](const QModelIndex& current,const QModelIndex& previous){});
//    connect(mSelectionModel,static_cast<void (QItemSelectionModel::*)(const QModelIndex&,const QModelIndex&)>(&QItemSelectionModel::currentRowChanged),
//            this,[=](const QModelIndex& current,const QModelIndex& previous){});

}
