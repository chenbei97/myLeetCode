#include "testDelegate.h"
#include "ui_testdelegate.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

// 1.初始化工作
void TestDelegate::initilize()
{
    this->theModel = new QStandardItemModel(10,FixedColumnCount,this); //先初始化10×6空表格
    this->theSelection = new QItemSelectionModel(this->theModel);//构造函数就绑定了数据模型
    //tableView设置数据模型和选择模型
    ui->tableView->setModel(this->theModel);
    ui->tableView->setSelectionModel(this->theSelection);

    this->initDelegate(); // 为tableView初始化代理

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
    this->ui->statusbar->addWidget(LabCurFile);
    this->ui->statusbar->addWidget(LabCellPos);
    this->ui->statusbar->addWidget(LabCellText);
}

// 2. 用于初始化theModel和tableView
void TestDelegate::initTableView(QStringList &aFileContent)
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
        QStringList tmpList=aLineText.split(QRegExp("\\s+"),QString::SkipEmptyParts); // 每行的所有列分开

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

// 3. 初始化代理
void TestDelegate::initDelegate()
{
    //为tableView的各列设置自定义代理组件
    this->spinProxy = new spinBoxDelegate(this);
    this->doubleSpinProxy = new doubleSpinBoxDelegate(this);
    this->comboProxy = new comboBoxDelegate(this);

    ui->tableView->setItemDelegateForColumn(0,this->spinProxy);  //整数
    ui->tableView->setItemDelegateForColumn(1,this->doubleSpinProxy);  //浮点数
    ui->tableView->setItemDelegateForColumn(2,this->doubleSpinProxy); //浮点数
    ui->tableView->setItemDelegateForColumn(3,this->doubleSpinProxy); //浮点数
    ui->tableView->setItemDelegateForColumn(4,this->comboProxy); //combobox选择型
}

// 4.退出
void TestDelegate::on_actExit_triggered()
{
    this->close();
}
