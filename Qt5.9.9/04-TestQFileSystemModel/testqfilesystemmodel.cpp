#include "testqfilesystemmodel.h"
#include "ui_testqfilesystemmodel.h"

TestQFileSystemModel::TestQFileSystemModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestQFileSystemModel)
{
    ui->setupUi(this);
    this->initialize();
}
void TestQFileSystemModel::initialize() { // 一些初始化操作
    this->fileModel = new QFileSystemModel(this); // new1个
    this->fileModel->setRootPath(QDir::currentPath()); // 设置根目录为当前工作路径,这个目录一般是你的C盘的父节点

    // // 设置3个视图组件关联的数据模型
    ui->treeView->setModel(this->fileModel);
    ui->listView->setModel(this->fileModel);
    ui->tableView->setModel(this->fileModel);

    // 关联槽函数treeView的clicked信号和自定义槽函数,直接转到槽用on_xxx规则命名的函数也可以
    // connect(ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(&this->treeView_slotFunction(QModelIndex)));
    connect(ui->treeView,&QTreeView::clicked,this,&TestQFileSystemModel::treeView_slotFunction); //这样写才能触发,必须使用函数指针的写法

    // 让listView和tableView同步treeView的变化,有利于观察它们之间的区别
    // 当treeView点击索引时,就会触发2个视图组件的设置根节点的槽函数
    connect(ui->treeView,SIGNAL(clicked(QModelIndex)),
            ui->listView,SLOT(setRootIndex(QModelIndex)));

    connect(ui->treeView,SIGNAL(clicked(QModelIndex)),
            ui->tableView,SLOT(setRootIndex(QModelIndex)));
}
TestQFileSystemModel::~TestQFileSystemModel()
{
    delete ui;
}
void TestQFileSystemModel::treeView_slotFunction(const QModelIndex& index) // 自定义槽函数
{
        ui->chkIsDir->setChecked(this->fileModel->isDir(index)); // QCheckBox类型,根据模型索引指向的文件是否为目录来设置
        ui->LabPath->setText(this->fileModel->filePath(index)); // QLabel类型,显示文件路径
        ui->LabType->setText(this->fileModel->type(index)); // QLabel,显示文件类型
        ui->LabFileName->setText(this->fileModel->fileName(index)); //QLabel,显示文件名称

        int sz=this->fileModel->size(index)/1024; // 用于计算文件大小,sz的单位是KB
        if (sz<1024)
            ui->LabFileSize->setText(QString("%1 KB").arg(sz)); // 第1个参数占位符,其实就是sz
        else
            ui->LabFileSize->setText(QString::asprintf("%.1f MB",sz/1024.0)); // 转换为MB
}

void TestQFileSystemModel::on_treeView_clicked(const QModelIndex &index)
{
    Q_UNUSED(index); // 使用这种写法也可以
}
