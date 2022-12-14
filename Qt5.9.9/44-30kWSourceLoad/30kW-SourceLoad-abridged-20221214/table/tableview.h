#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QMainWindow>
#include <QTableView>
#include <QDockWidget>
#include <QToolBar>
#include <QLabel>
#include <QActionGroup>
#include <QAction>
#include <QStatusBar>
#include <QSignalMapper>
#include <table/table.h>
#include <table/tablesizedialog.h>
#include <table/tablecolordialog.h>
#include <table/tablesampleperiod.h>
#include <core/enum.h>

class TableView : public QMainWindow
{
    Q_OBJECT
public:
    explicit TableView(QWidget * parent = Q_NULLPTR);
private:
    void initUI();
    void initActConnections();
    void initConnections();
    void updateCellTextFont(const QModelIndex&);
    void setActColEnabled(bool checked);

    struct CellTextFont { //默认左对齐/不加粗/不斜体,白底黑字
        bool bold = false;
        bool italic = false;
        Table::AlignType align = Table::AlignType::Left;
        QColor mForeColor = Qt::black;
        QColor mBackColor = Qt::white;
    } mCellFont;

private:
    bool mLogEnabled;
    QTableView * mTableView;
    Table * mTable;
    TableSizeDialog * mTableSizeDlg;
    TableSamplePeriod * mTableSPDlg;
    QLabel * mCellLoc;
    QLabel * mCellContent;
    QLabel * mToolTip;
    QAction * ActAppendRow;
    QAction * ActAppendCol;
    QAction * ActInsertRow;
    QAction * ActInsertCol;
    QAction * ActRemoveRow;
    QAction * ActRemoveCol;
    QAction * ActSetBold;
    QAction * ActSetItalic;
    QAction * ActClearTable;
    QAction * ActSetColor;
    QAction * ActSetAlignLeft;
    QAction * ActSetAlignCenter;
    QAction * ActSetAlignRight;
    QAction * ActImportTxt;
    QAction * ActExportTxt;
    QAction * ActImportCsv;
    QAction * ActExportCsv;
    QAction * ActConfigTable;
    QAction * ActSetSamplePeriod;
signals:
    void workModeChanged(WORKMODE);
    void selectedPeriod(quint32 ms, quint32 s = 0,quint32 m = 0, quint32 h = 0);
    void log(const QList<QByteArray>&);
};

#endif // TABLEVIEW_H
