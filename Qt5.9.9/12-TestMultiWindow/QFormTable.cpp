#include "QFormTable.h"
#include "ui_QFormTable.h"

QFormTable::QFormTable(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::QFormTable)
{
      ui->setupUi(this);
      theModel = new QStandardItemModel(12,6,this); //数据模型
      theSelection = new QItemSelectionModel(theModel);//Item选择模型
      //为tableView设置数据模型
      ui->tableView->setModel(theModel); //设置数据模型
      ui->tableView->setSelectionModel(theSelection);//设置选择模型
}

QFormTable::~QFormTable()
{
  delete ui;
}

void QFormTable::on_actSize_triggered()
{
    tableSizeDialog    *tableSize=new tableSizeDialog(this); // 动态创建的对话框

    Qt::WindowFlags    flags=tableSize->windowFlags();
    tableSize->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint); //设置对话框固定大小

    tableSize->setRowColumn(theModel->rowCount(),theModel->columnCount()); //对话框数据初始化

    int ret=tableSize->exec();// 以模态方式显示对话框，用户关闭对话框时返回 DialogCode值
    if (ret==QDialog::Accepted) //OK键被按下,对话框关闭，若设置了setAttribute(Qt::WA_DeleteOnClose)，对话框被释放，无法获得返回值
    { //OK键被按下，获取对话框上的输入，设置行数和列数
        int cols=tableSize->columnCount();
        theModel->setColumnCount(cols);

        int rows=tableSize->rowCount();
        theModel->setRowCount(rows);
    }
    delete tableSize; //删除对话框,用完就扔
}

void QFormTable::on_actSetHeader_triggered()
{
      if (this->tableHeader == nullptr) //如果对象没有被创建过，就创建对象
        tableHeader = new tableHeaderDialog(this); // 有父窗口属性

    if (tableHeader->getHeader().count()!=theModel->columnCount()) // 如果模型存储的信息和表格设置的不一致
    {
        QStringList strList;
        for (int i=0;i<theModel->columnCount();i++)//获取现有的表头标题
            strList.append(theModel->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString());
        tableHeader->setHeader(strList);//用于对话框初始化显示
    }

    int ret=tableHeader->exec();// 以模态方式显示对话框
    if (ret==QDialog::Accepted) //OK键被按下
    {
        QStringList strList=tableHeader->getHeader();//获取对话框上修改后的StringList
        theModel->setHorizontalHeaderLabels(strList);// 设置模型的表头标题
    }
}
