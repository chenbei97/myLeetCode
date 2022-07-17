#include "TestDataStream.h"
#include "ui_TestDataStream.h"

// 1. 表格复位
void TestDataStream::on_actTabReset_triggered()
{
        this->resetTable(10); // 如果不是读取文件导致的,统一初始化为10行6列
}

// 2. 添加行
void TestDataStream::on_actAppend_triggered()
{
        QList<QStandardItem*>    aItemList; //容器类
        QStandardItem   *aItem;
        QString str;

        for(int i=0;i<FixedColumnCount-2;i++) // 第1,2,3,4列因为是数字,设置为0就可以
        {
            aItem=new QStandardItem("0"); //创建Item
            aItemList<<aItem;   //添加到容器
        }
        aItem=new QStandardItem("优"); //第5列是固定的选项,从"优","良","一般"3个选项进行选择,设置为"优"
        aItemList<<aItem;   //添加到容器

        str=theModel->headerData(theModel->columnCount()-1,Qt::Horizontal,Qt::DisplayRole).toString(); // "测井取样"w文字
        aItem=new QStandardItem(str); //创建Item
        aItem->setCheckable(true); // 设置为true
        aItem->setEditable(false);
        aItemList<<aItem;   //添加到容器

        theModel->insertRow(theModel->rowCount(),aItemList); //插入一整行到末尾行后边
        QModelIndex curIndex=theModel->index(theModel->rowCount()-1,0);//创建最后一行的ModelIndex
        theSelection->clearSelection(); // 清除当前鼠标选中的行
        theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);// 鼠标选中刚插入的行
}

// 3. 插入行
void TestDataStream::on_actInsert_triggered()
{
        QList<QStandardItem*>    aItemList;  //QStandardItem的容器类
        QStandardItem   *aItem;
        QString str;
        for(int i=0;i<FixedColumnCount-2;i++)
        {
            aItem=new QStandardItem("0"); // 同理数字统一设为0
            aItemList<<aItem;//添加到容器类
        }
        aItem=new QStandardItem("优"); // 统一设为"优"
        aItemList<<aItem;//添加到容器类

        str=theModel->headerData(theModel->columnCount()-1,Qt::Horizontal,Qt::DisplayRole).toString();
        aItem=new QStandardItem(str);
        aItem->setCheckable(true); // 统一设为true
        aItem->setEditable(false);
        aItemList<<aItem;//添加到容器类

        QModelIndex curIndex=theSelection->currentIndex();
        theModel->insertRow(curIndex.row(),aItemList); // 插入到当前鼠标选中行的前1行
        theSelection->clearSelection();
        theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}

// 4. 删除行
void TestDataStream::on_actDelete_triggered()
{
        QModelIndex curIndex=theSelection->currentIndex(); // 获取当前鼠标选中的行
        if (curIndex.row()==theModel->rowCount()-1)//使用curIndex.isValid()也可以判断
            theModel->removeRow(curIndex.row()); // 如果是最后1行直接删除,鼠标选中位置没了
        else
        {
            theModel->removeRow(curIndex.row()); // 如果不是最后1行,删除后还得把鼠标选中的行保持之前的位置
            theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
        }
}

// 5. 表格复位实际调用的函数,同时还在打开dat文件和打开stm文件中调用
void TestDataStream::resetTable(int rowCount)
{
        // 表格复位,先删除所有行,再设置新的行数,表头不变

        // 因为表头不变.所以下方代码可以注释掉
        // QStringList     headerList;
        // headerList<<"测深(m)"<<"垂深(m)"<<"方位(°)"<<"总位移(m)"<<"固井质量"<<"测井取样";
        // theModel->setHorizontalHeaderLabels(headerList); //设置表头文字

        theModel->removeRows(0,theModel->rowCount()); //删除所有行
        theModel->setRowCount(rowCount);//设置新的行数

       QString str=theModel->headerData(theModel->columnCount()-1,
                        Qt::Horizontal,Qt::DisplayRole).toString(); // 获取最后1列的列标题"测井取样",因为最后1列比较特殊,文字是固定的"测井取样"

       for (int i=0;i<theModel->rowCount();i++) //设置最后一列
       {
           QModelIndex index=theModel->index(i,FixedColumnCount-1); //获取模型索引
           QStandardItem* aItem=theModel->itemFromIndex(index); //获取item
           aItem->setCheckable(true);
           aItem->setData(str,Qt::DisplayRole); // 都设置文字为"测井取样"
           aItem->setEditable(false); //不可编辑
       }

       ui->plainTextEdit->clear();
       ui->actModelData->setEnabled(false);//表格复位以后不能显示文本
}
