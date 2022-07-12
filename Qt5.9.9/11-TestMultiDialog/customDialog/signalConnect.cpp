#include "customDialog.h"
#include "ui_customDialog.h"

// 对话框提供信号,主窗口获取这个信号进行数据交互

// 1. 初始化设置表格行列数对话框的信号连接
void customDialog::initialize_sizeDialog_connection()
{
    connect(this->sizeDialog,SIGNAL(columnChanged(int)),this,SLOT(on_sizeColumn(int)));
    connect(this->sizeDialog,SIGNAL(rowChanged(int)),this,SLOT(on_sizeRow(int)));
}

// 2. 初始化设置表格标题对话框的信号连接
void customDialog::initialize_headerDialog_connection()
{
      connect(this->headerDialog,SIGNAL(headerTitle(QString)),this,SLOT(on_tableHeader(QString)));
}

// 3.初始化设置单元格内容对话框的信号连接
void customDialog::initialize_itemDialog_connection()
{
    // 连接对话框的2个信号和主窗口的2个槽函数
    connect(this->itemDialog,SIGNAL(columnChanged(QString)),this,SLOT(on_cellColumn(QString)));
    connect(this->itemDialog,SIGNAL(rowChanged(QString)),this,SLOT(on_cellRow(QString)));

    // 连接主窗口的1个信号和对话框的1个槽函数
    connect(this,SIGNAL(doubleClickedIndex(QModelIndex)),this->itemDialog,SLOT(statusShow(QModelIndex)));
}
