#include "tableHeaderDialog.h"
#include "ui_tableHeaderDialog.h"
#include <QMessageBox>
#include <QDebug>

tableHeaderDialog::tableHeaderDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::tableHeaderDialog)
{
    ui->setupUi(this);
    this->theModel = new QStringListModel;
    ui->listView->setModel(this->theModel);
}

tableHeaderDialog::~tableHeaderDialog()
{
    if (ui!=nullptr) delete ui;
}
// (1) 2个pushbutton的槽函数
void tableHeaderDialog::on_btnOK_clicked()
{
    int select = QMessageBox::question(this,"Question","请再次确认",QMessageBox::Yes | QMessageBox::Cancel);
    switch (select) { // 注意这个是消息对话框的返回值,不是对话框的返回值
        case QMessageBox::Yes : this->accept(); break; // 隐藏对话框,给exec反馈Accepted
        case QMessageBox::Cancel : break ; // 什么也不做
      }
}

void tableHeaderDialog::on_btnCancel_clicked()
{
    this->reject(); // 隐藏对话框,给exec反馈Rejected
}

// (2)提供给主窗口使用的公开函数用于数据交互
void tableHeaderDialog::setHeader(const QStringList &header)
{
      // 主窗口传入header => 设置对话框的listview数据模型
      this->theModel->setStringList(header);
}

QStringList tableHeaderDialog::getHeader()
{
      // 对话框的listview数据模型 => 主窗口
      return this->theModel->stringList();
}

// (3)借助信号与槽机制来进行数据交互
void tableHeaderDialog::on_listView_doubleClicked(const QModelIndex &index)
{
    // 双击listview后进入此槽函数
   //  qDebug()<<index.data().toString();
   emit headerTitle(index.data().toString());// 传递出正在双击的标题名称
}
