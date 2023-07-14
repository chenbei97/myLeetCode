#include "mainwindow.h"
#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")
#include    <QFileDialog>
#include    <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->splitter);

//   tableView显示属性设置
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    resize(1800,800);
}

// 数据库的字段去填充排序字段
void MainWindow::getFieldNames()
{ //获取所有字段名称
    QSqlRecord  emptyRec=tabModel->record();//获取空记录，只有字段名
    for (int i=0;i<emptyRec.count();i++)
        ui->comboFields->addItem(emptyRec.fieldName(i));
}

// 打开数据库内的数据表
void MainWindow::openTable()
{//打开数据表
    tabModel=new QSqlTableModel(this,DB);//数据表
    tabModel->setTable("employee"); //设置数据表
    tabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//数据保存方式，OnManualSubmit , OnRowChange
    tabModel->setSort(tabModel->fieldIndex("empNo"),Qt::AscendingOrder); //按主键empNo升序,指定列数,先查询所在列

    if (!(tabModel->select()))//查询数据
    {
       QMessageBox::critical(this, "错误信息",
              "打开数据表错误,错误信息\n"+tabModel->lastError().text(),
                 QMessageBox::Ok,QMessageBox::NoButton);
       return;
    }

    // 设置插入时的默认值
    connect(tabModel,&QSqlTableModel::primeInsert,this,[this](int row,QSqlRecord& r){
        Q_UNUSED(row);
            r.setValue("Salary",20000);//设置默认值
             r.setValue("Gender","女");//设置默认值
            //r.setValue("Photo",":/images/images/up.bmp");
             QByteArray data;
             QFile* file=new QFile(":/images/images/up.bmp"); //fileName为二进制数据文件名
             file->open(QIODevice::ReadOnly);
             data = file->readAll();
             file->close();
             r.setValue("Photo",data); // 必须是二进制数据
    });

//字段显示名
//    tabModel->setHeaderData(tabModel->fieldIndex("empNo"),Qt::Horizontal,"工号");
//    tabModel->setHeaderData(tabModel->fieldIndex("Name"),Qt::Horizontal,"姓名");
//    tabModel->setHeaderData(tabModel->fieldIndex("Gender"),Qt::Horizontal,"性别");
//    tabModel->setHeaderData(tabModel->fieldIndex("Height"),Qt::Horizontal,"身高");
//    tabModel->setHeaderData(tabModel->fieldIndex("Birthday"),Qt::Horizontal,"出生日期");
//    tabModel->setHeaderData(tabModel->fieldIndex("Mobile"),Qt::Horizontal,"手机");
//    tabModel->setHeaderData(tabModel->fieldIndex("Province"),Qt::Horizontal,"省份");
//    tabModel->setHeaderData(tabModel->fieldIndex("City"),Qt::Horizontal,"城市");
//    tabModel->setHeaderData(tabModel->fieldIndex("Department"),Qt::Horizontal,"部门");
//    tabModel->setHeaderData(tabModel->fieldIndex("Education"),Qt::Horizontal,"学历");
//    tabModel->setHeaderData(tabModel->fieldIndex("Salary"),Qt::Horizontal,"工资");

//    tabModel->setHeaderData(tabModel->fieldIndex("Memo"),Qt::Horizontal,"备注"); //这两个字段不再tableView中显示
//    tabModel->setHeaderData(tabModel->fieldIndex("Photo"),Qt::Horizontal,"照片");

    QStringList headerlabels = {"工号","姓名","性别","身高","出生日期","手机","省份","城市","部门","学历","工资","照片","备注"};
    for(int c = 0; c<headerlabels.count(); ++c)
        tabModel->setHeaderData(c,Qt::Horizontal,headerlabels[c]);

    theSelection=new QItemSelectionModel(tabModel);//关联选择模型
//theSelection当前项变化时触发currentChanged信号
    connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));
//选择行变化时
    connect(theSelection,SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentRowChanged(QModelIndex,QModelIndex)));

    ui->tableView->setModel(tabModel);//设置数据模型
    ui->tableView->setSelectionModel(theSelection); //设置选择模型
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Memo"),true);//隐藏列
    ui->tableView->setColumnHidden(tabModel->fieldIndex("Photo"),true);//隐藏列

//tableView上为“性别”和“部门”两个字段设置自定义代理组件
    QStringList strList;
    strList<<"男"<<"女";
    bool isEditable=false;
    delegateSex.setItems(strList,isEditable); // 初始化代理组件的项
//    ui->tableView->setItemDelegateForColumn(
//       tabModel->fieldIndex("Gender"),&delegateSex); //Combbox选择型
    ui->tableView->setItemDelegateForColumn(2,&delegateSex); //第2列是sex

    strList.clear();
    strList<<"销售部"<<"技术部"<<"生产部"<<"行政部";
    isEditable=true;
    delegateDepart.setItems(strList,isEditable);
    //ui->tableView->setItemDelegateForColumn(tabModel->fieldIndex("Department"),&delegateDepart); //Combbox选择型
    ui->tableView->setItemDelegateForColumn(8,&delegateDepart); //Combbox选择型

//创建界面组件与数据模型的字段之间的数据映射
    dataMapper= new QDataWidgetMapper();
    dataMapper->setModel(tabModel);//设置数据模型
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);//自动提交

//    connect(theSelection,SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
//            dataMapper,SLOT(setCurrentModelIndex(QModelIndex)));
//    connect(theSelection, &QItemSelectionModel::currentRowChanged,
//            dataMapper, &QDataWidgetMapper::setCurrentModelIndex); // 如果没有图片，直接绑定此信号就可以自动更新映射小部件的内容

//    dataMapper->setItemDelegate(new QSqlRelationalDelegate(this)); //含有外键的可以继续设置这个代理
    //界面组件与tabModel的具体字段之间的联系
    // 把每列和小部件联系起来,小部件去显示这列的任何行数据
    dataMapper->addMapping(ui->dbSpinEmpNo,tabModel->fieldIndex("empNo"));
    dataMapper->addMapping(ui->dbEditName,tabModel->fieldIndex("Name"));
    dataMapper->addMapping(ui->dbComboSex,tabModel->fieldIndex("Gender"));

    dataMapper->addMapping(ui->dbSpinHeight,tabModel->fieldIndex("Height"));
    dataMapper->addMapping(ui->dbEditBirth,tabModel->fieldIndex("Birthday"));
    dataMapper->addMapping(ui->dbEditMobile,tabModel->fieldIndex("Mobile"));

    dataMapper->addMapping(ui->dbComboProvince,tabModel->fieldIndex("Province"));
    dataMapper->addMapping(ui->dbEditCity,tabModel->fieldIndex("City"));
    dataMapper->addMapping(ui->dbComboDep,tabModel->fieldIndex("Department"));

    dataMapper->addMapping(ui->dbComboEdu,tabModel->fieldIndex("Education"));
    dataMapper->addMapping(ui->dbSpinSalary,tabModel->fieldIndex("Salary"));

    dataMapper->addMapping(ui->dbEditMemo,tabModel->fieldIndex("Memo"));

//    dataMapper->addMapping(ui->dbPhoto,tabModel->fieldIndex("Photo")); //图片无法直接映射

    dataMapper->toFirst();//移动到首记录，就是用表格的第1行来更新部件

    getFieldNames();//获取字段名称列表，填充ui->groupBoxSort组件

//更新actions和界面组件的使能状态
    ui->actOpenDB->setEnabled(false);

    ui->actRecAppend->setEnabled(true);
    ui->actRecInsert->setEnabled(true);
    ui->actRecDelete->setEnabled(true);
    ui->actScan->setEnabled(true); //涨工资

    ui->groupBoxSort->setEnabled(true);
    ui->groupBoxFilter->setEnabled(true);
}

// 打开数据库的动作
void MainWindow::on_actOpenDB_triggered()
{//打开数据表
    QString aFile=QFileDialog::getOpenFileName(this,tr("selec db files"),"",
                             tr("SQL Lite(*.db *.db3)"));
    if (aFile.isEmpty())  //选择SQL Lite数据库文件
       return;

//打开数据库
    DB=QSqlDatabase::addDatabase("QSQLITE"); //添加 SQL LITE数据库驱动
    DB.setDatabaseName(aFile); //设置数据库名称
//    DB.setHostName();
//    DB.setUserName();
//    DB.setPassword();
    if (!DB.open())   //打开数据库
    {
        QMessageBox::warning(this, "错误", "打开数据库失败",
                                 QMessageBox::Ok,QMessageBox::NoButton);
        return;
    }

//打开数据表
    openTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 选择模型的信号
void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{//更新actPost和actCancel 的状态
    Q_UNUSED(current);
    Q_UNUSED(previous);
    ui->actSubmit->setEnabled(tabModel->isDirty()); //view有修改数据但是没提交
    ui->actRevert->setEnabled(tabModel->isDirty());
}

// 选择模型的信号
void MainWindow::on_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
// 行切换时的状态控制
    ui->actRecDelete->setEnabled(current.isValid());// 删除记录
    ui->actPhoto->setEnabled(current.isValid()); // 设置照片
    ui->actPhotoClear->setEnabled(current.isValid()); // 清除照片

    if (!current.isValid())
    {
        ui->dbLabPhoto->clear(); //清除图片显示
        return;
    }

    int curRecNo=current.row();//获取行号
    // 点击表格的行更新小部件的显示
    dataMapper->setCurrentIndex(curRecNo); //更细数据映射的行号

    // 图片数据需要自己手动更新
    QSqlRecord  curRec=tabModel->record(curRecNo); //获取当前记录

    if (curRec.isNull("Photo"))  //图片字段内容为空
       ui->dbLabPhoto->clear();
    else
    {
        QByteArray data=curRec.value("Photo").toByteArray(); // 数据库blob数据类型可以存图片
        QPixmap pic;
        pic.loadFromData(data);
        ui->dbLabPhoto->setPixmap(pic.scaledToWidth(ui->dbLabPhoto->size().width()));
    }
}

void MainWindow::on_actRecAppend_triggered()
{//添加记录
    tabModel->insertRow(tabModel->rowCount(),QModelIndex()); //在末尾添加一个记录

    QModelIndex curIndex=tabModel->index(tabModel->rowCount()-1,1);//创建最后一行的ModelIndex
    theSelection->clearSelection();//清空选择项
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);//设置刚插入的行为当前选择行，将选择所有指定的索引

    int currow=curIndex.row(); //获得当前行
    tabModel->setData(tabModel->index(currow,0),2000+tabModel->rowCount()); //自动生成编号
    //tabModel->setData(tabModel->index(currow,2),"男"); // 默认值中primeInsert信号已经处理
    // 插入行时设置缺省值，需要在primeInsert()信号里去处理
    /*
        当在当前活动数据库表的给定行中启动插入时，insertRows（）会发出此信号。
        记录参数可以被写入（因为它是一个引用），例如用默认值填充一些字段，并设置字段的生成标志。
        在处理此信号时，不要试图通过其他方式编辑记录，如setData（）或setRecord（）
    */
}

void MainWindow::on_actRecInsert_triggered()
{//插入记录
    QModelIndex curIndex=ui->tableView->currentIndex(); // 唯一的区别是插入在当前行不是末尾

    tabModel->insertRow(curIndex.row(),QModelIndex());

    theSelection->clearSelection();//清除已有选择
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
}

void MainWindow::on_actRevert_triggered()
{//取消修改
    tabModel->revertAll(); // 是个槽函数取消全部修改
    ui->actSubmit->setEnabled(false);
    ui->actRevert->setEnabled(false);
}

void MainWindow::on_actSubmit_triggered()
{//保存修改
    bool res=tabModel->submitAll();

    if (!res)
        QMessageBox::information(this, "消息", "数据保存错误,错误信息\n"+tabModel->lastError().text(),
                                 QMessageBox::Ok,QMessageBox::NoButton);
    else
    {
        ui->actSubmit->setEnabled(false);
        ui->actRevert->setEnabled(false);
    }
}

void MainWindow::on_actRecDelete_triggered()
{//删除当前记录
    QModelIndex curIndex=theSelection->currentIndex();//获取当前选择单元格的模型索引
    tabModel->removeRow(curIndex.row()); //view删除此行数据
}

void MainWindow::on_actPhoto_triggered()
{
//设置照片
    QString aFile=QFileDialog::getOpenFileName(this,"选择图片文件","","照片(*.jpg)");
    if (aFile.isEmpty())
       return;

    QByteArray data;
    QFile* file=new QFile(aFile); //fileName为二进制数据文件名
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    file->close();

    int curRecNo=theSelection->currentIndex().row(); // 当前行
    QSqlRecord  curRec=tabModel->record(curRecNo); //获取当前记录
    curRec.setValue("Photo",data); //设置字段数据 是二进制数据
    tabModel->setRecord(curRecNo,curRec);

    QPixmap pic;
    pic.load(aFile);  //在界面上显示
    ui->dbLabPhoto->setPixmap(pic.scaledToWidth(ui->dbLabPhoto->width()));
}

void MainWindow::on_actPhotoClear_triggered()
{
    int curRecNo=theSelection->currentIndex().row();
    QSqlRecord  curRec=tabModel->record(curRecNo); //获取当前记录

    curRec.setNull("Photo");//设置为空值
    tabModel->setRecord(curRecNo,curRec);

    ui->dbLabPhoto->clear();
}

void MainWindow::on_radioBtnAscend_clicked()
{//升序
    tabModel->setSort(ui->comboFields->currentIndex(),Qt::AscendingOrder);
    tabModel->select(); // 排序字段索引,要select更新
}

void MainWindow::on_radioBtnDescend_clicked()
{//降序
    tabModel->setSort(ui->comboFields->currentIndex(),Qt::DescendingOrder);
    tabModel->select();
}

void MainWindow::on_radioBtnMan_clicked()
{
    tabModel->setFilter(" Gender='男' ");
//    tabModel->select(); // 设置过滤不需重新select
}

void MainWindow::on_radioBtnWoman_clicked()
{
    tabModel->setFilter(" Gender='女' ");
//    tabModel->select();
}

void MainWindow::on_radioBtnBoth_clicked()
{
    tabModel->setFilter("");
}

// QCombobox排序字段的信号
void MainWindow::on_comboFields_currentIndexChanged(int index)
{//选择字段进行排序
    if (ui->radioBtnAscend->isChecked()) // 如果是降序..
        tabModel->setSort(index,Qt::AscendingOrder);
    else
        tabModel->setSort(index,Qt::DescendingOrder);

    tabModel->select();
}

void MainWindow::on_actScan_triggered()
{//涨工资，记录遍历
    if (tabModel->rowCount()==0)
        return;

    for (int i=0;i<tabModel->rowCount();i++)
    {
        QSqlRecord aRec=tabModel->record(i); //获取当前记录
        float salary=aRec.value("Salary").toFloat(); // 工资这里涨
        salary=salary*1.1;
        aRec.setValue("Salary",salary);
        tabModel->setRecord(i,aRec); // 赋值回去
    }

// 索引方式刷新记录,速度一样 setData需要制定行和列,setRecord只需要知道行更方便
//    float   salary;
//    for (int i=0;i<tabModel->rowCount();i++)
//    {
//        salary=tabModel->data(tabModel->index(i,10)).toFloat();
//        salary=salary*1.1;
//        tabModel->setData(tabModel->index(i,10),salary);
//    }

    if (tabModel->submitAll()) // 然后自动提交
        QMessageBox::information(this, "消息", "涨工资计算完毕",
                             QMessageBox::Ok,QMessageBox::NoButton);
}
