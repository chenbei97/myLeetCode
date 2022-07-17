#include "TestDataStream.h"
#include "ui_TestDataStream.h"

TestDataStream::TestDataStream(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestDataStream)
{
        ui->setupUi(this);
        setCentralWidget(ui->tabWidget);
        this->initialize_model();
        this->initialize_proxy();
        this->initialize_qlabel();
        this->initialize_toolbar_enable(false);
}

TestDataStream::~TestDataStream()
{
        delete ui;
}


// 1. 初始化模型
void TestDataStream::initialize_model()
{
        const int rowCounts = 10;
        this->theModel = new QStandardItemModel(rowCounts,FixedColumnCount,this); //创建数据模型
        QStringList     headerList;
        headerList<<"测深"<<"垂深"<<"方位"<<"位移"<<"质量"<<"测井取样";
        this->theModel->setHorizontalHeaderLabels(headerList); //设置表头文字

        this->theSelection = new QItemSelectionModel(this->theModel);//Item选择模型
        connect(this->theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)), // tableView鼠标选中的项变化执行的槽函数关联
                this,SLOT(on_currentItemChanged(QModelIndex,QModelIndex)));

        ui->tableView->setModel(this->theModel); // 给tableView设置数据模型
        ui->tableView->setSelectionModel(this->theSelection);// 给tableView设置选择模型

        this->resetTable(rowCounts); // 10×6的表格
}

// 2. 初始化代理
void TestDataStream::initialize_proxy()
{
        this->comboProxy = new comboBoxDelegate(this);
        this->spinBoxProxy = new spinBoxDelegate(this);
        this->doubleSpinBoxProxy = new doubleSpinBoxDelegate(this);

        ui->tableView->setItemDelegateForColumn(0,spinBoxProxy);  //测深整数
        ui->tableView->setItemDelegateForColumn(1,spinBoxProxy);  //垂深整数
        ui->tableView->setItemDelegateForColumn(2,doubleSpinBoxProxy); // 方位浮点数
        ui->tableView->setItemDelegateForColumn(3,doubleSpinBoxProxy); // 位移浮点数
        ui->tableView->setItemDelegateForColumn(4,comboProxy); // 质量是选项型
}

// 3. 初始化QLabel和状态栏
void TestDataStream::initialize_qlabel()
{
    this->LabCellPos = new QLabel("当前单元格：",this);
    this->LabCellPos->setMinimumWidth(180);
    this->LabCellPos->setAlignment(Qt::AlignHCenter);

    this->LabCellText = new QLabel("单元格内容：",this);
    this->LabCellText->setMinimumWidth(200);

    ui->statusbar->addWidget(LabCellPos);
    ui->statusbar->addWidget(LabCellText);
}

// 4. tableView的currentChanged信号对应的槽函数
void TestDataStream::on_currentItemChanged(const QModelIndex &current, const QModelIndex &previous)
{
        Q_UNUSED(previous);
        if (current.isValid())
        {
            this->LabCellPos->setText(QString::asprintf("当前单元格：%d行，%d列",
                                      current.row(),current.column()));
            QStandardItem   *aItem;
            aItem=theModel->itemFromIndex(current); //从模型索引获得Item
            this->LabCellText->setText("单元格内容："+aItem->text());

            QFont   font=aItem->font();
            ui->actFontBold->setChecked(font.bold()); // 组件要跟随表格项文字是否加粗的状态
        }
}

// 5. 初始化使能
void TestDataStream::initialize_toolbar_enable(bool enable)
{
        // 初始时候必须打开dat、stm或者txt三者之一来初始化表格,以下功能设为false
       // 打开任意一种文件成功后使能才设为true

        ui->actSaveBin->setEnabled(enable); // 保存dat
        ui->actSave->setEnabled(enable); // 保存stm
        ui->actSaveTxt->setEnabled(enable); // 保存txt

        ui->actTabReset->setEnabled(enable); // 表格复位
        ui->actAppend->setEnabled(enable); // 添加行
        ui->actInsert->setEnabled(enable); // 插入行
        ui->actDelete->setEnabled(enable); // 删除行

        ui->actAlignLeft->setEnabled(enable); // 居左
        ui->actAlignCenter->setEnabled(enable);// 居中
        ui->actAlignRight->setEnabled(enable); // 居右
        ui->actFontBold->setEnabled(enable); // 粗体

        ui->actModelData->setEnabled(enable); // 文本显示
}


