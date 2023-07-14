#include "tableItemDialog.h"
#include "ui_tableItemDialog.h"
#include    <QCloseEvent>
#include    <QMessageBox>
#include    "customDialog.h" // 主窗口的头文件

tableItemDialog::tableItemDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::tableItemDialog)
{
  ui->setupUi(this);
  // this->initialize_connection();
}

tableItemDialog::~tableItemDialog()
{
      if (ui!=nullptr) delete ui;
}

// (1) 显示和关闭窗口事件的自定义
void tableItemDialog::closeEvent(QCloseEvent *event)
{// 窗口关闭事件，关闭时释放本窗口
    customDialog *parent = (customDialog*) parentWidget(); //利用内联函数获取父窗口指针
    parent->setTableItemEnable(true);// 关闭本对话框时主窗口的单元格使能
    parent->setItemDialogNullptr(); //关闭本对话框时指针设置为nullptr
    Q_UNUSED(event);
}
void tableItemDialog::showEvent(QShowEvent *event)
{//窗口显示事件
    customDialog *parent = (customDialog*) parentWidget(); //利用内联函数获取父窗口指针
    parent->setTableItemEnable(true);// 打开本对话框时主窗口的单元格禁止使能,也就是说只能让对话框来控制单元格防止冲突
    Q_UNUSED(event);
}

// (2) 2个pushbutton的槽函数
void tableItemDialog::on_btnSetText_clicked()
{
      int row=ui->spinBoxRow->value(); //行号,但是此行号是从1计算的
      int col=ui->spinBoxColumn->value();//列号,但是此行号是从1计算的

      customDialog *parent = (customDialog*) parentWidget(); //利用内联函数获取父窗口指针
      QString oldText = parent->getTableItemText(row,col); // 原有单元格文字内容用于后续可能需要的恢复原状操作
      parent->setTableItemText(row,col,ui->edtCaption->text()); //设置单元格文字,传递给主窗口

      int select = QMessageBox::question(this,"Question","请再次确认",QMessageBox::Yes | QMessageBox::Cancel);
      if (select == QMessageBox::Yes)
      {
            this->close(); // 隐藏对话框,没有exec反馈
            return;
      }
       // 否则的话恢复原状
       parent->setTableItemText(row,col,oldText);
}

void tableItemDialog::on_btnClose_clicked()
{
    this->close(); // 非模态对话框使用close而不是reject
}

// (2)提供给主窗口使用的公开函数用于数据交互
void tableItemDialog::setSpinRange(int row, int column)
{// 设置表格最大行列数
      ui->spinBoxRow->setMaximum(row);
      ui->spinBoxColumn->setMaximum(column);
}
void tableItemDialog::setSpinValue(int row, int column)
{// 定位当前单元格
      ui->spinBoxRow->setValue(row);
      ui->spinBoxColumn->setValue(column);
}
// (3)借助信号与槽机制来进行数据交互
// (3.1) 传递2个信号给主窗口,主窗口有2个对应的槽函数接收
void tableItemDialog::on_spinBoxColumn_valueChanged(QString arg1)
{
    emit columnChanged(arg1);
}
void tableItemDialog::on_spinBoxRow_valueChanged(QString arg1)
{
    emit rowChanged(arg1);
}
// (3.2) 定义1个槽函数接收来自主窗口的doubleClickedIndex信号
// 由于要连接信号和槽函数,如果在对话框进行连接,必须得到父窗口的指针
// 如果在父窗口进行连接,就必须得到对话框的指针
// 这里两者都进行了尝试,发现都可以
void tableItemDialog::initialize_connection()
{
     customDialog *parent = (customDialog*) parentWidget();
     connect(parent,SIGNAL(doubleClickedIndex(QModelIndex)),this,SLOT(statusShow(QModelIndex)));
}
void tableItemDialog::statusShow(const QModelIndex & index)
{
    QString text = QString::asprintf("主窗口双击的单元格索引为：(%d, %d)\n它的数据为\"%s\"",
              index.row(),index.column(),index.data().toString().toStdString().c_str());
    this->ui->label->setText(text);
}
