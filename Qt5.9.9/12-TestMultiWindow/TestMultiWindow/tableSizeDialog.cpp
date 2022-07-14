#include "tableSizeDialog.h"
#include "ui_tableSizeDialog.h"
#include <QMessageBox>

tableSizeDialog::tableSizeDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::tableSizeDialog)
{
  ui->setupUi(this);
}

tableSizeDialog::~tableSizeDialog()
{
      if (ui!=nullptr) delete ui;
}

// (1) 2个pushbutton的槽函数
void tableSizeDialog::on_btnOK_clicked()
{
    int select = QMessageBox::question(this,"Question","请再次确认",QMessageBox::Yes | QMessageBox::Cancel);
    switch (select) { // 注意这个是消息对话框的返回值,不是对话框的返回值
        case QMessageBox::Yes : this->accept(); break; // 隐藏模式对话框并将结果代码设置为 Accepted,本质上调用done(Accepted),对话框会退出
        case QMessageBox::Cancel : break ; // 什么也不做,如果是这里,对话框不会退出,还存在
      }
}
void tableSizeDialog::on_btnCancel_clicked()
{
    this->reject();// 隐藏模式对话框并将结果代码设置为 Rejected,,本质上调用done(Rejected),对话框会退出
}

// (2)提供给主窗口使用的公开函数用于数据交互
int tableSizeDialog::rowCount()
{
    return ui->spinBoxRow->value();
}

int tableSizeDialog::columnCount()
{
    return ui->spinBoxColumn->value();
}

void tableSizeDialog::setRowColumn(int row, int column)
{
    ui->spinBoxRow->setValue(row);
    ui->spinBoxColumn->setValue(column);
}

// (3)借助信号与槽机制来进行数据交互
// 借助2个信号把信息传递出去,这2个信号需要在主窗口被连接到槽函数作出一些响应
void tableSizeDialog::on_spinBoxColumn_valueChanged(int arg1)
{
     // 对话框spinbox的值发生变化以后,传递到此槽函数
     // 此槽函数负责把信号再直接转发出去即可
     emit columnChanged(arg1); // 直接转发传递出信息
}

void tableSizeDialog::on_spinBoxRow_valueChanged(int arg1)
{
    emit rowChanged(arg1); // 同理
}




