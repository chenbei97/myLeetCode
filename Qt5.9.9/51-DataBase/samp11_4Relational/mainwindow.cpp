﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")
#include    <QFileDialog>
#include    <QMessageBox>


void MainWindow::openTable()
{//打开数据表
    tabModel=new QSqlRelationalTableModel(this,DB);
    tabModel->setTable("studInfo"); //设置数据表
    tabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);  //OnManualSubmit , OnRowChange
    tabModel->setSort(0,Qt::AscendingOrder);

    // 学号是主键，学院和专业是外键，他们2个都是整型，不同的编号代表不同的学院，会映射到2个表对应的name列
    // 学生查找学院编号，然后就知道学院的名字
    // 学生可以查找专业编号，知道专业名称，专业表也绑定了学院编号，自然知道所属学院名
    tabModel->setHeaderData(0,Qt::Horizontal,"学号");
    tabModel->setHeaderData(1,Qt::Horizontal,"姓名");
    tabModel->setHeaderData(2,Qt::Horizontal,"性别");
    tabModel->setHeaderData(3,Qt::Horizontal,"学院");
    tabModel->setHeaderData(4,Qt::Horizontal,"专业");

    //设置代码字段的查询关系数据表
    // stuInfo的第3列是departID,第4列是majorID
    // 设置QSqlRelation时，要指定表名、索引列和展示列

    //设置代码字段的查询关系数据表，需要指定表名，索引列和展示的列
    // 第几列应用这个关系表，那么view这列就会自动变成combobox代理的单元格，可以下拉选项
    // 第3列每个单元格显示有哪些学院，第4列显示有什么专业
    tabModel->setRelation(3,QSqlRelation("departments","departID","department")); //学院
    tabModel->setRelation(4,QSqlRelation("majors","majorID","major"));//专业

    theSelection=new QItemSelectionModel(tabModel);
    connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    ui->tableView->setModel(tabModel);
    ui->tableView->setSelectionModel(theSelection);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView)); //为关系型字段设置缺省代理组件

    tabModel->select(); //打开数据表

    ui->actOpenDB->setEnabled(false);
    ui->actRecAppend->setEnabled(true);
    ui->actRecInsert->setEnabled(true);
    ui->actRecDelete->setEnabled(true);
    ui->actFields->setEnabled(true);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->tableView);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);

    resize(1000,800);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{//更新actPost和actCancel 的状态
    Q_UNUSED(current);
    Q_UNUSED(previous);
    ui->actSubmit->setEnabled(tabModel->isDirty()); //有未保存修改时可用
    ui->actRevert->setEnabled(tabModel->isDirty());
}

void MainWindow::on_actOpenDB_triggered()
{
    QString aFile=QFileDialog::getOpenFileName(this,"选择数据库文件","",
                             "SQL Lite数据库(*.db *.db3)");
    if (aFile.isEmpty())
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

// 添加和插入都是利用insertRow插入空白行
void MainWindow::on_actRecAppend_triggered()
{//添加记录
    tabModel->insertRow(tabModel->rowCount(),QModelIndex()); //在末尾添加一个记录
    QModelIndex curIndex=tabModel->index(tabModel->rowCount()-1,1);//创建最后一行的ModelIndex
    theSelection->clearSelection();//清空选择项
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);//设置刚插入的行为当前选择行

}

void MainWindow::on_actRecInsert_triggered()
{//插入记录
    QModelIndex curIndex=ui->tableView->currentIndex();
    tabModel->insertRow(curIndex.row(),QModelIndex());

    theSelection->clearSelection();//清除已有选择
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);

}

void MainWindow::on_actRevert_triggered()
{//取消修改
    tabModel->revertAll();
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
        //tabModel->select();
    }

}

void MainWindow::on_actRecDelete_triggered()
{//删除当前记录
    tabModel->removeRow(theSelection->currentIndex().row());
    tabModel->submitAll(); //立即更新
     tabModel->select();
}

void MainWindow::on_actFields_triggered()
{//获取字段列表
    QSqlRecord  emptyRec=tabModel->record();//获取空记录，只有字段名
    QString  str;
    for (int i=0;i<emptyRec.count();i++)
        str=str+emptyRec.fieldName(i)+'\n';

    QMessageBox::information(this, "所有字段名", str,
                             QMessageBox::Ok,QMessageBox::NoButton);
}
