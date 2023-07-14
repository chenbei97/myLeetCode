#include "customDialog.h"
#include "ui_customDialog.h"

// 为了对话框可以操作主窗口而定义的公共函数用于数据交互

// 1. 对话框设置单元格使能
void customDialog::setTableItemEnable(bool enable)
{
    ui->actTab_Locate->setEnabled(enable);
}

// 2. 对话框设置单元格内容
void customDialog::setTableItemText(int row,int column,QString text)
{
    // 得到的row和column是从1计算的,所以要减去1
    QModelIndex index=theModel->index(row-1,column-1);//获取模型索引
    theSelection->clearSelection(); //清除现有选择
    theSelection->setCurrentIndex(index,QItemSelectionModel::Select); //定位到单元格
    theModel->setData(index,text,Qt::DisplayRole);//设置单元格字符串
}

// 3.对话框获取单元格内容
QString customDialog::getTableItemText(int row,int column)
{
    // 得到的row和column是从1计算的,所以要减去1
    QModelIndex index=theModel->index(row-1,column-1);//获取模型索引
    return index.data().toString();
}

// 4. 对话框释放自己
void customDialog::setItemDialogNullptr()
{
      this->itemDialog=nullptr;
}
