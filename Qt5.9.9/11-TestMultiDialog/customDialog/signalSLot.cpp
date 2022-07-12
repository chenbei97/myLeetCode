#include "customDialog.h"
#include "ui_customDialog.h"

// 1.sizeDialog的rowChanged信号的槽函数
void customDialog::on_sizeRow(int row)
{
    theModel->setRowCount(row);
}
// 2. sizeDialog的columnChanged信号的槽函数
void customDialog::on_sizeColumn(int column)
{
    theModel->setColumnCount(column);
}
// 3. headerDialog的headerTitle信号的槽函数
void customDialog::on_tableHeader(QString title)
{
    this->LabCellText->setText("正在修改表头 \""+title+"\"");
}
// 4. itemDialog的rowChanged信号的槽函数
void customDialog::on_cellRow(QString row)
{
    this->LabCellText->setText("正在操作的单元格所属行数 \""+row+"\"");
}
// 5. itemDialog的columnChanged信号的槽函数
void customDialog::on_cellColumn(QString column)
{
    this->LabCellText->setText("正在操作的单元格所属列数 \""+column+"\"");
}
