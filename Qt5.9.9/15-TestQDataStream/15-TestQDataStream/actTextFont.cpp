#include "TestDataStream.h"
#include "ui_TestDataStream.h"

//  1. 模型数据文本框显示
void TestDataStream::on_actModelData_triggered()
{
        ui->plainTextEdit->clear();
        QStandardItem   *aItem;
        QString str;

        // 1. 导入标题行
        int i,j;
        for (i=0;i<this->theModel->columnCount();i++) // 每个列标题
        {
            aItem=this->theModel->horizontalHeaderItem(i);
            str=str+aItem->text()+"\t"; // 使用Tab符号隔开
        }
        ui->plainTextEdit->appendPlainText(str);

        // 2. 导入数据行
        for (i=0;i<this->theModel->rowCount();i++) // 遍历每行
        {
            str=""; // 每行的所有文字
            for(j=0;j<this->theModel->columnCount()-1;j++)
            {
                aItem=this->theModel->item(i,j);
                str=str+aItem->text()+QString::asprintf("\t");
            }

            aItem=this->theModel->item(i,j);
            if (aItem->checkState()==Qt::Checked)
                str=str+"true";
            else
                str=str+"false";

             ui->plainTextEdit->appendPlainText(str);
        }
}

// 2. 居左
void TestDataStream::on_actAlignLeft_triggered()
{
        if (!this->theSelection->hasSelection()) // 鼠标没有选中一个区域
            return;

        QModelIndexList selectedIndix=theSelection->selectedIndexes(); // 获取选中的区域所有索引位置

        QModelIndex aIndex;
        QStandardItem   *aItem;

        for (int i=0;i<selectedIndix.count();i++) // 遍历每个区域内的项
        {
            aIndex=selectedIndix.at(i); // 某个具体项的索引
            aItem=theModel->itemFromIndex(aIndex);
            aItem->setTextAlignment(Qt::AlignLeft); // 设置左对齐
        }
}

// 3. 居中
void TestDataStream::on_actAlignCenter_triggered()
{
        if (!this->theSelection->hasSelection()) // 鼠标没有选中一个区域
            return;

        QModelIndexList selectedIndix=theSelection->selectedIndexes(); // 获取选中的区域所有索引位置

        QModelIndex aIndex;
        QStandardItem   *aItem;

        for (int i=0;i<selectedIndix.count();i++) // 遍历每个区域内的项
        {
            aIndex=selectedIndix.at(i); // 某个具体项的索引
            aItem=theModel->itemFromIndex(aIndex);
            aItem->setTextAlignment(Qt::AlignHCenter); // 设置居中对齐
        }
}

// 4. 居右
void TestDataStream::on_actAlignRight_triggered()
{
        if (!this->theSelection->hasSelection()) // 鼠标没有选中一个区域
            return;

        QModelIndexList selectedIndix=theSelection->selectedIndexes(); // 获取选中的区域所有索引位置

        QModelIndex aIndex;
        QStandardItem   *aItem;

        for (int i=0;i<selectedIndix.count();i++) // 遍历每个区域内的项
        {
            aIndex=selectedIndix.at(i); // 某个具体项的索引
            aItem=theModel->itemFromIndex(aIndex);
            aItem->setTextAlignment(Qt::AlignRight); // 设置右对齐
        }
}

// 5. 粗体
void TestDataStream::on_actFontBold_triggered(bool checked)
{
        if (!this->theSelection->hasSelection()) // 鼠标没有选中一个区域
            return;

        QModelIndexList selectedIndix=theSelection->selectedIndexes(); // 获取选中的区域所有索引位置

        QModelIndex aIndex;
        QStandardItem   *aItem;
        QFont   font;

        for (int i=0;i<selectedIndix.count();i++)  // 遍历每个区域内的项
        {
            aIndex=selectedIndix.at(i); // 某个具体项的索引
            aItem=theModel->itemFromIndex(aIndex);
            font=aItem->font(); // 获取字体
            font.setBold(checked); // 和组件的checked状态保持一致
            aItem->setFont(font);
        }
}
