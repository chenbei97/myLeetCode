#include "../../inc/tables/tableview.h"

TableView::TableView(QWidget *parent) :QTableView(parent)
{
    initGeneralConfig();
    connect(this,&TableView::clicked,this,&TableView::onClicked);
    connect(this,&TableView::doubleClicked,this,&TableView::onDoubleClicked);
    connect(this,&TableView::pressed,this,&TableView::onPressed);
    INIT_FONT;
}


void TableView::initGeneralConfig()
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setSelectionBehavior(QAbstractItemView::SelectItems);//选中时只选中1个项
    setSelectionMode(QAbstractItemView::SingleSelection); // 选择项只能选中1个,再点另一个会取消选中之前的
    setEditTriggers(QTableView::NoEditTriggers);

    setShowGrid(true);
    setGridStyle(Qt::DashLine);
    setWordWrap(false);//取消自动换行
    setSortingEnabled(false); // 不启用排序
    setCornerButtonEnabled(false);
    setTabKeyNavigation(true);
    setAlternatingRowColors(false);
    setDragEnabled(false);
    setAcceptDrops(false);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel); // 按像素或者按项进行滚动
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);// 取消滚动条
    setTextElideMode(Qt::ElideNone); //防止文本超过宽度出现省略号

    //verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader()->setHighlightSections(true);//选中一列表头是否加粗,选false就不能连续选中表头
    verticalHeader()->setStretchLastSection(false);//最后一列拉伸填充,设为false,否则2×2的格子就显示2列了
    //verticalHeader()->setMinimumSectionSize(TableWidgetItemMinWidth);//列标题最大高度
    //verticalHeader()->setDefaultSectionSize(TableWidgetItemMinWidth);//默认列宽

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setHighlightSections(true);
    horizontalHeader()->setStretchLastSection(false);//最后一列自适应宽度，让表头初始显示时占满行
//    horizontalHeader()->setMinimumSectionSize(TableWidgetItemMinWidth);
//    horizontalHeader()->setDefaultSectionSize(TableWidgetItemHeight);

}

void TableView::updateCellSize()
{
    if (model())
    {
        for(int r = 0; r <model()->rowCount(); ++ r)
            setRowHeight(r,TableViewRowHeight);

        for(int c = 0; c <model()->columnCount(); ++ c)
            setColumnWidth(c,TableViewColumnWidth);
    }
}

void TableView::setModel(QAbstractItemModel *model)
{
    //    if (model == this->model()) {
    //        QTableView::setModel(model);
    //        emit modelChanged(model);
    //    }
    auto old = this->model();
    QTableView::setModel(model); // 先设置好
    emit modelSettled(model); // 否则信号连接的先执行用到尚未设置的model会导致异常
    if (model != old)
        emit modelChanged(model);
}

void TableView::updateGeometries()
{
    //LOG<<"is called";
    return QTableView::updateGeometries();
}

void TableView::onClicked(const QModelIndex &index)
{
    //LOG<<"onClicked";
    Q_UNUSED(index);
}

void TableView::onDoubleClicked(const QModelIndex &index)
{
    //LOG<<"onDoubleClicked";
    Q_UNUSED(index);
}

void TableView::onPressed(const QModelIndex &index)
{
    //LOG<<"onPressed";
    Q_UNUSED(index);
}

void TableView::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton) {
        emit mouseRightButtonPressed();
    }
    return QTableView::mousePressEvent(e);
}




