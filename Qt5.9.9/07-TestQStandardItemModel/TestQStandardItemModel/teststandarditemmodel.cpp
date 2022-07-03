#include "teststandarditemmodel.h"
#include "ui_teststandarditemmodel.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

TestStandardItemModel::TestStandardItemModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestStandardItemModel)
{
    ui->setupUi(this);
    this->initilize();
}

TestStandardItemModel::~TestStandardItemModel()
{
    if (!this->ui) delete this->ui;
    if (!this->LabCellPos) delete  this->LabCellPos;
    if(!this->LabCurFile) delete  this->LabCurFile;
    if (!this->LabCellText) delete  this->LabCellText;
    if (!this->theModel) delete  this->theModel;
    if (!this->theSelection) delete  this->theSelection;
}

// 1. 初始化工作
void TestStandardItemModel::initilize()
{
    this->theModel = new QStandardItemModel(10,FixedColumnCount,this); //先初始化10×6空表格
    this->theSelection = new QItemSelectionModel(this->theModel);//构造函数就绑定了数据模型
    //tableView设置数据模型和选择模型
    ui->tableView->setModel(this->theModel); 
    ui->tableView->setSelectionModel(this->theSelection);

    // 鼠标选择单元格发生变化时发送信号连接定义的槽函数,槽函数名称可以不和信号一致,on开头就可以
    connect(this->theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
                this,SLOT(on_currentItemIndexChanged(QModelIndex,QModelIndex))); 


    // 设置可以通过ctrl,shift共同选取连续或者不连续的区域
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    // 设置鼠标点击单元格时选中这单个单元格,而不是1行或者1列
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

    //把QLabel加到状态栏
    this->LabCurFile = new QLabel("filePath: ",this);
    this->LabCurFile->setMinimumWidth(1000);
    this->LabCellPos = new QLabel("cellPos: ",this);
    this->LabCellPos->setMinimumWidth(300);
    this->LabCellPos->setAlignment(Qt::AlignHCenter);
    this->LabCellText = new QLabel("cellText: ",this);
    this->LabCellText->setMinimumWidth(300);
    this->ui->statusBar->addWidget(LabCurFile); 
    this->ui->statusBar->addWidget(LabCellPos);
    this->ui->statusBar->addWidget(LabCellText);
}

// 2. 鼠标选中单元格变化时的响应槽函数
void TestStandardItemModel::on_currentItemIndexChanged(const QModelIndex &current, const QModelIndex &previous)
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

// 3. 打开文件
void TestStandardItemModel::on_actOpen_triggered()
{
        /*
            QCoreApplication::applicationDirPath(); 返回包含应用程序可执行文件的目录
            QCoreApplication::applicationFilePath();返回应用程序可执行文件的文件路径
            QCoreApplication::applicationName();此属性包含此应用程序的名称
            QDir::home();返回用户的主目录
            QDir::homePath();返回用户主目录的绝对路径
            QDir:::current();返回应用程序的当前目录
            QDir::currentPath();返回应用程序当前目录的绝对路径
            QDir::root();返回根目录 
            QDir::rootPath();返回根目录的绝对路径
            QDir::temp();返回系统的临时目录
            QDir::tempPath();返回系统临时目录的绝对路径

            qDebug()<<QCoreApplication::applicationDirPath();
                "C:/Users/chenbei/Documents/build-TestQStandardItemModel-Desktop_Qt_5_9_9_MSVC2017_64bit-Debug/debug"
            qDebug()<<QCoreApplication::applicationFilePath();
                "C:/Users/chenbei/Documents/build-TestQStandardItemModel-Desktop_Qt_5_9_9_MSVC2017_64bit-Debug/debug/TestQStandardItemModel.exe"
            qDebug()<<QCoreApplication::applicationName();
                "TestQStandardItemModel"
            qDebug()<<QDir::currentPath();
                "C:/Users/chenbei/Documents/build-TestQStandardItemModel-Desktop_Qt_5_9_9_MSVC2017_64bit-Debug"
            qDebug()<<QDir::homePath();
                "C:/Users/chenbei"
            qDebug()<<QDir::rootPath();
                "C:/"
            qDebug()<<QDir::tempPath();
                "C:/Users/chenbei/AppData/Local/Temp"     
        */
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

// 4. 初始化theModel和tableView
void TestStandardItemModel::initTableView(QStringList &aFileContent)
{
    int rowCnt=aFileContent.count(); //文本行数
    this->theModel->setRowCount(rowCnt-1); // 标题行占据1行,所以设置表格实际行数-1

    //1.设置标题行
    QString header=aFileContent.at(0);//at访问第1行
    // 把该行分割成多个列标题
    QStringList headerList=header.split(QRegExp("\\s+"),QString::SkipEmptyParts);
    // 设置分割好的标题
    this->theModel->setHorizontalHeaderLabels(headerList);

    //2. 设置数据行
     int j;
     QStandardItem   *aItem; //
    for (int i=1;i<rowCnt;i++) //从第2行开始
    {
        QString aLineText=aFileContent.at(i); //第i行分隔
        QStringList tmpList=aLineText.split(QRegExp("\\s+"),QString::SkipEmptyParts); // ?????????

        // 最后1列单独设置,这里设置第1-5列
        for (j=0;j<FixedColumnCount-1;j++) 
        { 
            aItem=new QStandardItem(tmpList.at(j));// 每个列是1个项
            this->theModel->setItem(i-1,j,aItem); //设置该项
        }

         // 第6列是逻辑列,单独设置
        aItem=new QStandardItem(headerList.at(j));
        aItem->setCheckable(true); 
        // aItem->setEnabled(false); 
        if (tmpList.at(j)=="0") // 是0为不选中
            aItem->setCheckState(Qt::Unchecked); 
        else
            aItem->setCheckState(Qt::Checked); // 1为选中
        this->theModel->setItem(i-1,j,aItem); 
    }
}

// 5. 添加项
void TestStandardItemModel::on_actAppend_triggered()
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

// 6.保存文本
void TestStandardItemModel::on_actSave_triggered()
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

// 7.插入项
void TestStandardItemModel::on_actInsert_triggered()
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

// 8.删除项
void TestStandardItemModel::on_actDelete_triggered()
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

// 9.退出
void TestStandardItemModel::on_actExit_triggered()
{
    this->close();
}

// 10.导入theModel数据到plainTextEdit
void TestStandardItemModel::on_actModelData_triggered()
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

// 11. 左对齐
void TestStandardItemModel::on_actAlignLeft_triggered()
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

// 12.居中对齐
void TestStandardItemModel::on_actAlignCenter_triggered()
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

// 13. 右对齐
void TestStandardItemModel::on_actAlignRight_triggered()
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

// 14. 加粗
void TestStandardItemModel::on_actFontBold_triggered(bool checked)
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
