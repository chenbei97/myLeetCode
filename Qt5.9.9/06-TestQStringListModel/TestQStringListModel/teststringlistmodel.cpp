#include "teststringlistmodel.h"
#include "ui_teststringlistmodel.h"

TestStringListModel::TestStringListModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestStringListModel)
{
    ui->setupUi(this);
    this->initilize();
}

TestStringListModel::~TestStringListModel()
{
    delete ui;
    delete this->viewModel;
}

// 初始化列表
void TestStringListModel::on_btnIniList_clicked()
{
    QStringList   theStrList; //保存初始 StringList
    // theStrList<<"北京"<<"上海"<<"天津"<<"河北"<<"山东"<<"四川"<<"重庆"<<"广东"<<"河南"; //初始化 StringList
    theStrList<<"BeiJing"<<"ShangHai"<<"TianJin"<<"HeBei"
             <<"HeNan"<<"SiChuan"<<"GuangDong"<<"Chongqing"<<"JiangXi";
    this->viewModel->setStringList(theStrList);//初始化列表时就把这个字符串赋给模型
}

void TestStringListModel::initilize()
{
        QStringList         theStrList; //保存初始 StringList
        theStrList<<"北京"<<"上海"<<"天津"<<"河北"<<"山东"<<"四川"<<"重庆"<<"广东"<<"河南"; //初始化 StringList

        this->viewModel=new QStringListModel(this); //创建数据模型
        this->viewModel->setStringList(theStrList); //为模型设置StringList，会导入StringList的内容
        ui->listView->setModel(this->viewModel); //为listView设置数据模型

         // 设定启动每个项的编辑需要执行的操作，这里是双击或者选中单击
        // 也可以设置不允许编辑
        ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);

        this->displayModelIndex(); // 显示当前鼠标的索引
}
void TestStringListModel::displayModelIndex()
{
    QModelIndex index = ui->listView->currentIndex();
    ui->LabInfo->setText(QString::asprintf("row=%d, column=%d",
                        index.row(),index.column()));
}
// 添加1个项
void TestStringListModel::on_btnListAppend_clicked()
{
    // 涉及insertRow方法和rowCount()方法
    this->viewModel->insertRow(this->viewModel->rowCount()); //在尾部插入一空行
    // 因为返回的索引总是实际索引的后1位,所以索引需要减去1才是真正的索引
    QModelIndex index=this->viewModel->index(this->viewModel->rowCount()-1,0);//获取最后一行索引
    this->viewModel->setData(index,"chenbei",Qt::DisplayRole);//设置显示文字,这行用index标识,文字是chenbei,角色就是展示
    ui->listView->setCurrentIndex(index); //设置当前鼠标的索引跟随新创建的行
    this->displayModelIndex(); // 显示当前鼠标的索引
}
// 插入1个项
void TestStringListModel::on_btnListInsert_clicked()
{
    QModelIndex  index;
    index=ui->listView->currentIndex(); //获取当前鼠标选中的项 modelIndex
    this->viewModel->insertRow(index.row()); //在当前行的前面插入一行
    this->viewModel->setData(index,"inserted item",Qt::DisplayRole); //设置显示文字
    this->viewModel->setData(index,Qt::AlignRight,Qt::TextAlignmentRole); //设置对齐方式
    ui->listView->setCurrentIndex(index); //设置当前鼠标的索引跟随新创建的行
    this->displayModelIndex(); // 显示当前鼠标的索引
}
// 删除当前项
void TestStringListModel::on_btnListDelete_clicked()
{
    QModelIndex  index;
    index=ui->listView->currentIndex(); //获取当前鼠标选中的项modelIndex
    this->viewModel->removeRow(index.row()); //删除当前行
    this->displayModelIndex(); // 显示当前鼠标的索引
}

// 清除列表
void TestStringListModel::on_btnListClear_clicked()
{
    // removeRows(int row, int count, const QModelIndex &parent = QModelIndex())
      this->viewModel->removeRows(0,this->viewModel->rowCount());
     this->displayModelIndex(); // 显示当前鼠标的索引
}
// 清空文本
void TestStringListModel::on_btnTextClear_clicked()
{
    ui->plainTextEdit->clear();
}
// 显示文本
void TestStringListModel::on_btnTextImport_clicked()
{
    // 用于观察Model是否和View同步
    QStringList tmpList;
    tmpList=this->viewModel->stringList();//获取数据模型的StringList

    ui->plainTextEdit->clear(); //文本框清空
    for (int i=0; i<tmpList.count();i++)
        ui->plainTextEdit->appendPlainText(tmpList.at(i)); //显示数据模型的StringList()返回的内容
}
// 鼠标点击项的时候可以显示索引
void TestStringListModel::on_listView_clicked(const QModelIndex &index)
{
    this->displayModelIndex(); // 显示当前鼠标的索引
}
