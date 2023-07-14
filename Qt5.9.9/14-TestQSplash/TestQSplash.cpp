#include "TestQSplash.h"
#include "ui_TesyQSplash.h"
#include <QCloseEvent>
#include <QPainter>
#include <QDir>
#include <QFileDialog>

TestQSplash::TestQSplash(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TesyQSplash)
{
    ui->setupUi(this);

    ui->tabWidget->setVisible(false); //tabWidget初始设置为不可见,因为背景图片原因即使设置为true也默认不可见
    ui->tabWidget->setDocumentMode(true); //设置为文档模式
    ui->tabWidget->setTabsClosable(true);//设置为单页可关闭
    this->setCentralWidget(ui->tabWidget); //tabWidget填充工作区
    // this->setWindowState(Qt::WindowMaximized); //窗口最大化显示
}

TestQSplash::~TestQSplash()
{
    delete ui;
}

// 1. 绘制背景图片
void TestQSplash::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    int x = 0, y = ui->toolBar->height();
    int width = this->width(), height = this->height()-ui->toolBar->height()-ui->statusbar->height();
    painter.drawPixmap(x,y,width,height,QPixmap(":/images/back.jpg"));
}

// 2. 响应文件打开的槽函数
void TestQSplash::afterFileOpened(QString& aFileName)
{
    ui->statusbar->showMessage(aFileName); //状态栏上显示文件名
    QFileInfo   fileInfo(aFileName); //文件信息
    QString shortname=fileInfo.fileName(); //去掉路径的文件名
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),shortname); //显示为tab标签
}

// 3. 新建文档
void TestQSplash::on_actDoc_New_triggered()
{
        FormDoc *formDoc = new FormDoc(); //不指定父窗口，可以单独用show()方法显示

        // tabWidget新增一个页面
        int cur=ui->tabWidget->addTab(formDoc,QString::asprintf("Doc %d",ui->tabWidget->count()));
        ui->tabWidget->setCurrentIndex(cur);

        //文件打开信号与槽关联,如果打开成功就给当前Tab页设置名称为打开的文件名
        connect(formDoc,SIGNAL(fileOpended(QString&)),this,SLOT(afterFileOpened(QString&)));

        ui->tabWidget->setVisible(true);
        ui->actCut->setEnabled(true);
        ui->actCopy->setEnabled(true);
        ui->actPaste->setEnabled(true);
        ui->actFont->setEnabled(true);
}

// 4. 打开文档
void TestQSplash::on_actDoc_Open_triggered()
{
        QString curPath=QDir::currentPath();
        QString aFileName=QFileDialog::getOpenFileName(this,tr("打开一个文件"),curPath,
                     "C++文件(*.h *cpp);;文本文件(*.txt);;所有文件(*.*)");
        if (aFileName.isEmpty())
            return; //如果未选择文件，退出

        FormDoc    *formDoc;
        int cur;
        if (ui->tabWidget->count()==0) //一个页面都没有,自然需要新建1个
        {
            formDoc = new FormDoc();//指定父窗口，必须在父窗口为Widget窗口提供一个显示区域
            cur=ui->tabWidget->addTab(formDoc,QString::asprintf("Doc %d",ui->tabWidget->count()));
            // 连接FormDoc定义的信号fileOpended和本窗口定义的响应槽函数afterFileOpened
            // 如果打开成功就给当前Tab页设置名称为打开的文件名
            connect(formDoc,SIGNAL(fileOpended(QString&)),this,SLOT(afterFileOpened(QString&)));
        }
        else //否则在已有的当前Tab文档窗口里打开
        {
            cur=ui->tabWidget->currentIndex();
            formDoc=(FormDoc*)ui->tabWidget->widget(cur); // 获取当前Tab文档的窗口指针
         }

        formDoc->loadFromFile(aFileName); //调用文档窗口的函数打开文件

        ui->actCut->setEnabled(true);
        ui->actCopy->setEnabled(true);
        ui->actPaste->setEnabled(true);
        ui->actFont->setEnabled(true);
}

// 5. 设置字体
void TestQSplash::on_actFont_triggered()
{
    FormDoc    *formDoc;
    formDoc=(FormDoc*)ui->tabWidget->widget(ui->tabWidget->currentIndex());
    formDoc->setEditFont();
}

// 6. 剪切功能
void TestQSplash::on_actCut_triggered()
{
    FormDoc    *formDoc;
    formDoc=(FormDoc*)ui->tabWidget->widget(ui->tabWidget->currentIndex());
    formDoc->textCut();
}

// 7. 复制功能
void TestQSplash::on_actCopy_triggered()
{
    FormDoc    *formDoc;
    formDoc=(FormDoc*)ui->tabWidget->widget(ui->tabWidget->currentIndex());
    formDoc->textCopy();
}

// 8. 粘贴功能
void TestQSplash::on_actPaste_triggered()
{
    FormDoc    *formDoc;
    formDoc=(FormDoc*)ui->tabWidget->widget(ui->tabWidget->currentIndex());
    formDoc->textPaste();
}

// 9. 关闭所有打开的Tab页
void TestQSplash::on_actCloseALL_triggered()
{
    // tabWidget没有类似mdiArea的关闭所有子窗口的功能,只能遍历拿到原始指针关闭它
    FormDoc    *formDoc;
    for(int i=0;i<ui->tabWidget->count();i++)
    {
        formDoc= static_cast<FormDoc*>(ui->tabWidget->widget(i));
        formDoc->close(); //子窗口关闭时自动释放
    }
    ui->tabWidget->clear(); //清除所有tab
    ui->statusbar->clearMessage(); //清除状态栏消息
}

// 10. tabWidget的当前页切换的槽函数(更新状态栏显示信息)
void TestQSplash::on_tabWidget_currentChanged(int index)
{
    if (ui->tabWidget->count()>0)
    {
        FormDoc    *formDoc;
        formDoc=(FormDoc*)ui->tabWidget->widget(index);
        ui->statusbar->showMessage(formDoc->currentFileName());
    }
}
