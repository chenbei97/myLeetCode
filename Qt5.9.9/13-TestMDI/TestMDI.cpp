#include "TestMDI.h"
#include "ui_TestMDI.h"
#include <QCloseEvent>
#include <QDir>
#include <QFileDialog>
#include <QDebug>

TestMDI::TestMDI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestMDI)
{
        ui->setupUi(this);
        this->setCentralWidget(ui->mdiArea);
        // this->setWindowState(Qt::WindowFullScreen); //窗口全屏显示
        this->setAutoFillBackground(true);
}

TestMDI::~TestMDI()
{
    delete ui;
}
// 1. 窗口关闭事件
void TestMDI::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows(); //关闭mdiArea区域的所有子窗口
    event->accept();
}

// 2. mdiArea的槽函数,响应窗口切换的信号
void TestMDI::on_mdiArea_subWindowActivated(QMdiSubWindow *arg1)
{
    // 当前活动子窗口切换时
    Q_UNUSED(arg1);
    if (ui->mdiArea->subWindowList().count()==0){ //若子窗口个数为零
        ui->actCut->setEnabled(false); // 禁止文本操作
        ui->actCopy->setEnabled(false);
        ui->actPaste->setEnabled(false);
        ui->actFont->setEnabled(false);
        ui->statusbar->clearMessage();
    }
    else
    {
        FormDoc *formDoc=static_cast<FormDoc*>(ui->mdiArea->activeSubWindow()->widget()); // 使用显式静态转换
        ui->statusbar->showMessage(formDoc->currentFileName()); //显示主窗口的文件名
    }
}

// 3. 新建文档
void TestMDI::on_actDoc_New_triggered()
{
        FormDoc *formDoc = new FormDoc(this); //
        ui->mdiArea->addSubWindow(formDoc); //文档窗口添加到MDI
        formDoc->show(); //在单独的窗口中显示

        ui->actCut->setEnabled(true);
        ui->actCopy->setEnabled(true);
        ui->actPaste->setEnabled(true);
        ui->actFont->setEnabled(true);

}

// 4. 打开文件
void TestMDI::on_actDoc_Open_triggered()
{
        FormDoc    *formDoc; // 如果已有活动窗口且没使用过不需要再创建
        bool needNew=false;// 默认不需要新建窗口
        int count = ui->mdiArea->subWindowList().count();

        if (count > 0)
        {
            qDebug()<<ui->mdiArea->activeSubWindow()->winId() ; // 当前活动窗口的ID
            formDoc=(FormDoc*)ui->mdiArea->activeSubWindow()->widget(); // 获取当前活动窗口
            needNew=formDoc->isFileOpened();//判断这个活动窗口有没有使用过用来打开文件,没用过返回false
        }
        else {
            needNew = true; // 没有过子窗口或者之前的子窗口已被使用过都是true
        }

        if (needNew) //需要新建子窗口,说明之前打开的用过需要创建新的
        {
            qDebug()<<"需要创建新窗口";
            formDoc = new FormDoc(this);//指定父窗口，必须在父窗口为Widget窗口提供一个显示区域
            ui->mdiArea->addSubWindow(formDoc);
        }
        else {
            // 否则的话直接用之前的formDoc即可
            qDebug()<<"不需要创建新窗口";
        }

        QString curPath=QDir::currentPath();
        QString aFileName=QFileDialog::getOpenFileName(this,tr("打开一个文件"),curPath,
                     "C++文件(*.h *cpp);;文本文件(*.txt);;所有文件(*.*)");
        if (aFileName.isEmpty()){
            return; //如果未选择文件，退出
        }

        formDoc->loadFromFile(aFileName); //打开文件
        formDoc->show();
        ui->actCut->setEnabled(true);
        ui->actCopy->setEnabled(true);
        ui->actPaste->setEnabled(true);
        ui->actFont->setEnabled(true);
}

// 5. MDI显示模式
void TestMDI::on_actViewMode_triggered(bool checked)
{
    if (checked) //Tab多页显示模式
    {
        ui->mdiArea->setViewMode(QMdiArea::TabbedView); //Tab多页显示模式
        ui->mdiArea->setTabsClosable(true); //页面可关闭
        ui->actCascade->setEnabled(false); // 禁止级联展开
        ui->actTile->setEnabled(false); // 禁止平铺展开
    }
    else //子窗口模式
    {
        ui->mdiArea->setViewMode(QMdiArea::SubWindowView); //子窗口模式
        ui->actCascade->setEnabled(true); // 子窗口模式可以选择级联展开或者平铺展开
        ui->actTile->setEnabled(true); //
    }
}

// 6. 级联展开
void TestMDI::on_actCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

// 7. 平铺展开
void TestMDI::on_actTile_triggered()
{
    ui->mdiArea->tileSubWindows();
}

// 8. 关闭所有子窗口
void TestMDI::on_actCloseALL_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

// 9. 设置字体
void TestMDI::on_actFont_triggered()
{
    FormDoc* formDoc=(FormDoc*)ui->mdiArea->activeSubWindow()->widget();
    formDoc->setEditFont(); // 调用设置字体
}

// 10. 复制
void TestMDI::on_actCopy_triggered()
{
    FormDoc* formDoc=(FormDoc*)ui->mdiArea->activeSubWindow()->widget();
    formDoc->textCopy();//调用复制操作
}

// 11. 剪切
void TestMDI::on_actCut_triggered()
{
    FormDoc* formDoc=(FormDoc*)ui->mdiArea->activeSubWindow()->widget();
    formDoc->textCut(); // 调用剪切操作
}

// 12. 粘贴
void TestMDI::on_actPaste_triggered()
{
    FormDoc* formDoc=(FormDoc*)ui->mdiArea->activeSubWindow()->widget();
    formDoc->textPaste(); // 调用粘贴操作
}


