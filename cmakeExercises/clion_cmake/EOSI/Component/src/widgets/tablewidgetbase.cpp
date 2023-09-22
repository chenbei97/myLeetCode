#include "../../inc/widgets/tablewidgetbase.h"

TableWidgetBase::TableWidgetBase(int rows,int cols,QWidget * parent):QTableWidget(parent)
{
    setRowCount(rows);
    setColumnCount(cols);

    //setColumnWidth前必须先setColumnCount
    //包括setHorizontalHeaderLabels设置列标题集合也是，前提都要先有列
    for(int row = 0; row < rowCount();++row)
        setRowHeight(row,TableWidgetItemHeight);
    for(int col = 0; col < columnCount(); ++col)
        setColumnWidth(col,TableWidgetItemWidth);

    //setSelectionBehavior(QAbstractItemView::SelectItems);//选中时只选中1个项
    //setSelectionMode(QAbstractItemView::SingleSelection); // 选择项只能选中1个,再点另一个会取消选中之前的
    setEditTriggers(QTableWidget::EditTrigger::NoEditTriggers);
    setAcceptDrops(false); // 不允许接收拖动事件
    setCornerButtonEnabled(false);
    setTabKeyNavigation(true);
    setAlternatingRowColors(false);//奇数偶数行颜色交替
    setShowGrid(true);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel); // 按像素或者按项进行滚动
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 取消滚动条
    setWordWrap(false);//取消自动换行
    setTextElideMode(Qt::ElideNone); //防止文本超过宽度出现省略号
    //setMouseTracking(true);// 不要启用鼠标事件追踪,否则鼠标选中表格出现奇怪的漂移

    //setFrameShape(QFrame::VLine);
    //setStyleSheet("border:1px solid black;"); // "selection-background-color:yellow;"

    verticalHeader()->hide();//表头是否可见
    verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader()->setHighlightSections(true);//选中一列表头是否加粗,选false就不能连续选中表头
    verticalHeader()->setStretchLastSection(false);//最后一列拉伸填充,设为false,否则2×2的格子就显示2列了
    //verticalHeader()->setMinimumSectionSize(TableWidgetItemMinWidth);//列标题最大高度
    //verticalHeader()->setDefaultSectionSize(TableWidgetItemMinWidth);//默认列宽

    horizontalHeader()->hide();
    horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    horizontalHeader()->setHighlightSections(true);
    horizontalHeader()->setStretchLastSection(false);
    horizontalHeader()->setMinimumSectionSize(TableWidgetItemMinWidth);
    horizontalHeader()->setDefaultSectionSize(TableWidgetItemHeight);


    resize(TableWidgetItemWidth*columnCount(),TableWidgetItemHeight*rowCount());
    INIT_FONT;
}

TableWidgetBase*  TableWidgetBase::clone()
{
    return new TableWidgetBase(rowCount(),columnCount());
}

