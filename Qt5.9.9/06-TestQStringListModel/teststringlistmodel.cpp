#include "teststringlistmodel.h"
#include "ui_teststringlistmodel.h"
#include <QDebug>
TestStringListModel::TestStringListModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestStringListModel)
{
    ui->setupUi(this);
    this->initilize();
    this->test();
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

void TestStringListModel::test()
{
     // 初始化列表构造测试
    QStringList list = {"123","456","readme.txt","789",
                        "sTR","12sS","r*.txt","123"};
    qDebug()<<list;

    // contains,是否包含指定字符串,默认区分大小写
    // 关联的枚举类型枚举 Qt::CaseSensitivity
    qDebug()<<list.contains("str",Qt::CaseInsensitive); //设置大小写不敏感

    // filters 返回包含指定字符串的字符串列表
    // 还可以返回与正则表达式匹配的字符串
    // 2个重载版本 filter(const QRegExp &rx) const,filter(const QRegularExpression &re)
    qDebug()<<list.filter("12");

    // indexOf(const QRegExp &amp;rx, int from = 0) const
    // 返回列表中第一个精确匹配的正则表达式 rx的索引位置
    //从索引位置from开始向前搜索,如果没有匹配的项目,则返回 -1。
    // lastIndexOf是返回最后1个匹配的字符串,默认从from=-1开始寻找
    qDebug()<<list.indexOf("123",0);
    qDebug()<<list.lastIndexOf("123",-1);

    // join,将所有字符串列表的字符串连接成一个字符串,每个元素由给定的分隔符分隔,可以是空字符串
    QStringList lst = {"python","C++"} ;
    QString h = lst.join(",");
    qDebug()<<h;//"python,C++"

    // 删除重复项
    int num = list.removeDuplicates();
    qDebug()<<list<<"  "<<num;

    // 替换指定字符为指定字符
    QStringList list1;
     list1 << "alpha" << "betA" << "gamma" << "epsilon";
     list1.replaceInStrings("a", "o",Qt::CaseInsensitive);
     qDebug()<<list1;

      // sort 按升序对字符串列表进行排序,借助STL::sort完成
     list1.sort(Qt::CaseInsensitive);
     qDebug()<<list1;

     // index获取指定行的父目录下的
     for(int i = 0; i <9;i++)
        qDebug()<<this->viewModel->index(i,0,QModelIndex()).data()<<" "<<this->viewModel->index(i).row();

}
