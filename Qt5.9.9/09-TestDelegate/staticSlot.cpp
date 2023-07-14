#include "testDelegate.h"
#include "ui_testdelegate.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

// 1. 鼠标选中单元格变化时的响应槽函数
void TestDelegate::on_currentItemIndexChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);

    if (current.isValid()) //单元格有效的话
    {
        LabCellPos->setText(QString::asprintf("cellPos:(%d , %d)",
                                   current.row(),current.column()));
        QStandardItem   *aItem;
        aItem=this->theModel->itemFromIndex(current); //根据索引获取项指针
        this->LabCellText->setText("cellText: "+aItem->text());

        // 根据项文字的格式更新加粗动作的显示状态
        QFont  font=aItem->font();
        ui->actFontBold->setChecked(font.bold());
    }
}

// 2. 打开文件
void TestDelegate::on_actOpen_triggered()
{
        QString appName = QCoreApplication::applicationName(); // 获取应用的名称
        QDir curDir=QDir::current();//应用程序所在的目录
        curDir.cdUp();//回到上一级
        bool exist = curDir.cd(appName);//进入应用的工作目录所在文件夹
        QString curPath;
        if (exist)
             curPath=curDir.path(); // 如果存在就返回工作路径
        else {
            QMessageBox::information(this,"Error", // 否则提示错误
                    QString("Failed to open file directory, please check ")+appName+QString(" if this folder exists"));
            return;
        }
        // 设置文件过滤器格式的例子: tr("Images (*.png *.xpm *.jpg)")
        // "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"
        this->aFileName=QFileDialog::getOpenFileName(this,"Open File",curPath,
                     "txt(*.txt);;all files(*.*)");
        if (this->aFileName.isEmpty())
            return; //文件为空返回

        this->LabCurFile->setText("filePath: "+aFileName);//状态栏显示文本路径
        ui->actAppend->setEnabled(true); // 恢复动作使能
        ui->actInsert->setEnabled(true);
        ui->actDelete->setEnabled(true);
        ui->actSave->setEnabled(true);

        QStringList fFileContent;//用于存储读取的test.txt的文本

        QFile aFile(this->aFileName);  // 绑定QFile到当前文件路径
        if (aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //打开文件
        {
            QTextStream aStream(&aFile); //文本流
            ui->plainTextEdit->clear();//清空该组件内容
            while (!aStream.atEnd()) //文本流没读完就继续
            {
                QString str=aStream.readLine();//读取1行
                ui->plainTextEdit->appendPlainText(str); //就设置1行
                fFileContent.append(str); //并保存1行
            }
            aFile.close();//关闭
       }

        this->initTableView(fFileContent); // 初始化theModel和tableView
}

// 3. 添加项
void TestDelegate::on_actAppend_triggered()
{
    QList<QStandardItem*>    aItemList; //为了方便使用QList<<的功能
    QStandardItem   *aItem;
    QStringList text;
    text<<"425"<<"424.99"<<"238.72"<<"1.93";
    for(int i=0;i<FixedColumnCount-2;i++) //设置1-4列
    {
        aItem=new QStandardItem(text.at(i));
        aItemList<<aItem;
    }
    aItem=new QStandardItem(QString("优")); // 第5列
    aItemList << aItem ;

    //第6列
    QString str2=this->theModel->headerData(theModel->columnCount()-1,Qt::Horizontal,Qt::DisplayRole).toString();
    aItem=new QStandardItem(str2);
    aItem->setCheckable(true);
    aItemList<<aItem;

    this->theModel->insertRow(this->theModel->rowCount(),aItemList); //插入的位置是最后1行位置
    QModelIndex curIndex=theModel->index(this->theModel->rowCount()-1,0);//获取最后1行的索引,实际位置要-1
    this->theSelection->clearSelection();//清除鼠标选中状态
    this->theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);//设置鼠标选中的单元格为新增的单元格
}

// 4.保存文本
void TestDelegate::on_actSave_triggered()
{

    QString appName = QCoreApplication::applicationName(); // 获取应用的名称
    QDir curDir=QDir::current();//应用程序所在的目录
    curDir.cdUp();//回到上一级
    bool exist = curDir.cd(appName);//进入应用的工作目录所在文件夹
    QString curPath;
    if (exist)
            curPath=curDir.path(); // 如果存在就返回工作路径
    else {
        QMessageBox::information(this,"Error", // 否则提示错误
                QString("Failed to open file directory, please check ")+appName+QString(" if this folder exists"));
        return;
    }
    // 打开文本对话框
    this->aFileName=QFileDialog::getSaveFileName(this,tr("Select File"),curPath,
                 "txt(*.txt);;all files(*.*)");

    if (this->aFileName.isEmpty())
        return;

    QFile aFile(this->aFileName);
    if (!(aFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)))
        return;

    QTextStream aStream(&aFile);
    QStandardItem   *aItem;
    int i,j;
    QString str;
    ui->plainTextEdit->clear();

    //读取数据模型的标题内容
    for (i=0;i<this->theModel->columnCount();i++)
    {
        aItem=this->theModel->horizontalHeaderItem(i);
        str=str+aItem->text()+"\t\t";  //使用Tab作为分隔符
    }
    aStream<<str<<"\n";  //换行
    ui->plainTextEdit->appendPlainText(str); //在视图组件显示

    //读取数据模型的数据内容
    for ( i=0;i<this->theModel->rowCount();i++) // 行
    {
        str="";
        for( j=0;j<this->theModel->columnCount()-1;j++) // 列
        {
            aItem=this->theModel->item(i,j);
            str=str+aItem->text()+QString::asprintf("\t\t");
        }

        aItem=this->theModel->item(i,j); //最后1列单独设置
        if (aItem->checkState()==Qt::Checked)
            str=str+"1";
        else
            str=str+"0";

         ui->plainTextEdit->appendPlainText(str);
         aStream<<str<<"\n";
    }
}

// 5.插入项
void TestDelegate::on_actInsert_triggered()
{
    // 和添加项代码类似
    QList<QStandardItem*>    aItemList;
    QStandardItem   *aItem;
    QStringList text;
    text<<"425"<<"424.99"<<"238.72"<<"1.93"<<"优";
    for(int i=0;i<FixedColumnCount-1;i++)
    {
        aItem=new QStandardItem(text.at(i));
        aItemList<<aItem;
    }

    // 获取标题行的最后1个标题"测井取样"
    QString str;
    str=this->theModel->headerData(theModel->columnCount()-1,
        Qt::Horizontal,Qt::DisplayRole).toString();
    aItem=new QStandardItem(str);
    aItem->setCheckable(true);
    aItemList<<aItem;

    // 插入项后鼠标指向新插入的项
    QModelIndex curIndex=this->theSelection->currentIndex();
    this->theModel->insertRow(curIndex.row(),aItemList);
    this->theSelection->clearSelection();
    this->theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}

// 6.删除项
void TestDelegate::on_actDelete_triggered()
{
    QModelIndex curIndex=this->theSelection->currentIndex();

    // 如果删除的是最后1行,鼠标无需设置选中的单元格,否则选中删除后相同的位置单元格
    // 也就是会选中删除该行后下1行递补上来的那个单元格
    if (curIndex.row()==this->theModel->rowCount()-1)
        this->theModel->removeRow(curIndex.row());
    else
    {
        this->theModel->removeRow(curIndex.row());//移除该行
        this->theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
    }
}


// 7.导入theModel数据到plainTextEdit
void TestDelegate::on_actModelData_triggered()
{
    if (this->aFileName.isEmpty()) {
        QMessageBox::information(this,"Information","Please import the file first!");
        return;
    }
    ui->plainTextEdit->clear();
    QStandardItem   *aItem;
    QString str;

    //导入标题行
    int i,j;
    for (i=0;i<this->theModel->columnCount();i++)
    {
        aItem=this->theModel->horizontalHeaderItem(i);
        str=str+aItem->text()+"\t";
    }
    ui->plainTextEdit->appendPlainText(str);

    //导入数据行
    for (i=0;i<this->theModel->rowCount();i++)
    {
        str=""; // ???????""
        for(j=0;j<this->theModel->columnCount()-1;j++)
        {
            aItem=this->theModel->item(i,j);
            str=str+aItem->text()+QString::asprintf("\t");
        }

        aItem=this->theModel->item(i,j);
        if (aItem->checkState()==Qt::Checked)
            str=str+"1";
        else
            str=str+"0";

         ui->plainTextEdit->appendPlainText(str);
    }
}

// 8. 左对齐
void TestDelegate::on_actAlignLeft_triggered()
{
    if (!this->theSelection->hasSelection()) //没选中任何区域退出
        return;

    //列出选中的区域的所有项索引
    QModelIndexList selectedIndex=this->theSelection->selectedIndexes();

    for (int i=0;i<selectedIndex.count();i++)
    {
        QModelIndex aIndex=selectedIndex.at(i); // 索引
        QStandardItem* aItem=this->theModel->itemFromIndex(aIndex);//获取索引指向的项
        aItem->setTextAlignment(Qt::AlignLeft);//设置对齐方式
    }
}

// 9.居中对齐
void TestDelegate::on_actAlignCenter_triggered()
{
    // 代码类似左对齐
    if (!this->theSelection->hasSelection())
        return;

    QModelIndexList selectedIndex=this->theSelection->selectedIndexes();

    QModelIndex aIndex;
    QStandardItem   *aItem;

    for (int i=0;i<selectedIndex.count();i++)
    {
        aIndex=selectedIndex.at(i);
        aItem=this->theModel->itemFromIndex(aIndex);
        aItem->setTextAlignment(Qt::AlignHCenter);
    }
}

// 10. 右对齐
void TestDelegate::on_actAlignRight_triggered()
{
    // 代码类似左对齐
    if (!this->theSelection->hasSelection())
        return;

    QModelIndexList selectedIndex=this->theSelection->selectedIndexes();

    QModelIndex aIndex;
    QStandardItem   *aItem;

    for (int i=0;i<selectedIndex.count();i++)
    {
        aIndex=selectedIndex.at(i);
        aItem=this->theModel->itemFromIndex(aIndex);
        aItem->setTextAlignment(Qt::AlignRight);
    }
}

// 11. 加粗
void TestDelegate::on_actFontBold_triggered(bool checked)
{
    // 代码类似左对齐
    if (!this->theSelection->hasSelection())
        return;

    QModelIndexList selectedIndex=this->theSelection->selectedIndexes();

    for (int i=0;i<selectedIndex.count();i++)
    {
        QModelIndex aIndex=selectedIndex.at(i);
        QStandardItem* aItem=this->theModel->itemFromIndex(aIndex);
        QFont font=aItem->font();
        font.setBold(checked); //依据加粗动作的checked状态来设置
        aItem->setFont(font);
    }
}
