#include <table/tableview.h>

TableView::TableView(QWidget *parent): QMainWindow(parent),mLogEnabled(false),
    mTableView(new QTableView),mTable(new Table(mTableView,12,5)),mTableSizeDlg(new TableSizeDialog),mTableSPDlg(new TableSamplePeriod),
    mCellLoc(new QLabel(tr("位置: 未知"))), mCellContent(new QLabel(tr("文本: 未知"))),mToolTip(new QLabel(tr("工具提示: 未知"))),
    ActAppendRow(new QAction(tr("添加行"))),ActAppendCol(new QAction(tr("添加列"))),
    ActInsertRow(new QAction(tr("插入行"))),ActInsertCol(new QAction(tr("插入列"))),
    ActRemoveRow(new QAction(tr("删除行"))),ActRemoveCol(new QAction(tr("删除列"))),
    ActSetBold(new QAction(tr("加粗"))),ActSetItalic(new QAction(tr("斜体"))),ActClearTable(new QAction(tr("清空"))),ActSetColor(new QAction(tr("画笔"))),
    ActSetAlignLeft(new QAction(tr("居左"))),ActSetAlignCenter(new QAction(tr("居中"))),ActSetAlignRight(new QAction(tr("居右"))),
    ActImportTxt(new QAction(tr("导入Txt"))),ActExportTxt(new QAction(tr("导出Txt"))),
    ActImportCsv(new QAction(tr("导入Csv"))),ActExportCsv(new QAction(tr("导出Csv"))),
    ActConfigTable(new QAction(tr("设置"))),ActSetSamplePeriod(new QAction(tr("日志周期")))
{
        setMouseTracking(true);
        initUI();
        initConnections();
}

void TableView::initUI()
{
    QStatusBar * bar = new QStatusBar(this);
    mCellLoc->setMinimumWidth(100);
    mCellContent->setMinimumWidth(200);
    mToolTip->setMinimumWidth(100);
    bar->addWidget(mCellLoc);
    bar->addWidget(mCellContent);
    bar->addWidget(mToolTip);
    setStatusBar(bar);

    //ActSetSamplePeriod->setEnabled(false); // 设置采样周期只能在启用日志记录后使用

    ActSetBold->setCheckable(true); // 这里为了让单元格对齐/加粗/斜体的状态和当前动作保持一致
    ActSetItalic->setCheckable(true);
    ActSetAlignLeft->setCheckable(true);
    ActSetAlignCenter->setCheckable(true);
    ActSetAlignRight->setCheckable(true);
    QActionGroup *alignGroup = new QActionGroup(this);
    alignGroup->addAction(ActSetAlignLeft);
    alignGroup->addAction(ActSetAlignCenter);
    alignGroup->addAction(ActSetAlignRight);
    ActSetAlignCenter->setChecked(true); // 默认居中对齐

    QToolBar * topbar = new QToolBar;
    topbar->setMovable(true);
    topbar->setFloatable(true);
    topbar->addAction(ActAppendRow);
    topbar->addAction(ActAppendCol);
    topbar->addAction(ActInsertRow);
    topbar->addAction(ActInsertCol);
    topbar->addAction(ActRemoveRow);
    topbar->addAction(ActRemoveCol);
    topbar->addSeparator();
    topbar->addAction(ActSetAlignLeft);
    topbar->addAction(ActSetAlignCenter);
    topbar->addAction(ActSetAlignRight);
    topbar->addAction(ActSetBold);
    topbar->addAction(ActSetItalic);
    addToolBar(Qt::TopToolBarArea,topbar);

    QToolBar * bottombar = new QToolBar;
    bottombar->setMovable(true);
    bottombar->setFloatable(true);
    bottombar->addAction(ActClearTable);
    bottombar->addAction(ActSetColor);
    bottombar->addSeparator();
    bottombar->addAction(ActImportTxt);
    bottombar->addAction(ActExportTxt);
    bottombar->addAction(ActImportCsv);
    bottombar->addAction(ActExportCsv);
    bottombar->addSeparator();
    bottombar->addAction(ActConfigTable);
    bottombar->addAction(ActSetSamplePeriod);
    addToolBar(Qt::BottomToolBarArea,bottombar);

    setCentralWidget(mTableView);
    setFont(QFont("Times New Roman",12));
    resize(1350,700);
}

