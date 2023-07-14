#include "customDialog.h"
#include "ui_customDialog.h"
#include    <QMessageBox>
#include    <QCloseEvent>

customDialog::customDialog(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::customDialog)
{
  ui->setupUi(this);
  this->initialize();
}

customDialog::~customDialog()
{
  delete ui;
}

// 1. 初始化函数
void customDialog::initialize()
{
      this->sizeDialog = nullptr;
      this->headerDialog = nullptr;
      this->itemDialog = nullptr;

      theModel = new QStandardItemModel(15,6,this); //创建数据模型
      theSelection = new QItemSelectionModel(theModel);//Item选择模型
      connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
              this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

      //为tableView设置数据模型
      ui->tableView->setModel(theModel); //设置数据模型
      ui->tableView->setSelectionModel(theSelection);//设置选择模型
      setCentralWidget(ui->tableView); // 设置为中心组件

      //创建状态栏组件
      LabCellPos = new QLabel("当前单元格: ",this);
      LabCellPos->setMinimumWidth(180);
      LabCellPos->setAlignment(Qt::AlignHCenter);
      LabCellText = new QLabel("单元格内容: ",this);
      LabCellText->setMinimumWidth(200);
      ui->statusbar->addWidget(LabCellPos);
      ui->statusbar->addWidget(LabCellText);
}

// 2. 窗口关闭时询问是否退出
void customDialog::closeEvent(QCloseEvent *event)
{
   QMessageBox::StandardButton result=QMessageBox::question(this, "Question", "确定要退出本窗口吗?",
                      QMessageBox::Yes|QMessageBox::No |QMessageBox::Cancel,
                      QMessageBox::No);

    if (result==QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}

//  3. UI的tableview槽函数响应clicked信号用于设置状态栏
void customDialog::on_tableView_clicked(const QModelIndex &index)
{
    // 单击单元格时，将单元格的行号、列号设置到对话框上
    if (this->itemDialog!=nullptr) //对话框存在
        this->itemDialog->setSpinValue(index.row()+1,index.column()+1); // 从(0,0)开始变成(1,1)进行显示
}

// 4. UI的tableview槽函数响应doubleClicked信号传递信息
void customDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    // 只是单纯发射信号,主窗口传递信息=>对话框使用(这里让itemDialog来接收)
    emit doubleClickedIndex(index);
}

// 5. 自定义槽函数响应currentChanged信号用于设置状态栏
void customDialog::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if (current.isValid()) //当前模型索引有效
    {
        LabCellPos->setText(QString::asprintf("当前单元格：%d行，%d列",
                                  current.row()+1,current.column()+1)); //显示模型索引的行和列号,变成(1,1)进行显示
        QStandardItem   *aItem; // 标准项模型的项
        aItem=theModel->itemFromIndex(current); //从模型索引获得Item
        this->LabCellText->setText("单元格内容："+aItem->text()); //显示item的文字内容
    }
    Q_UNUSED(previous);
}



