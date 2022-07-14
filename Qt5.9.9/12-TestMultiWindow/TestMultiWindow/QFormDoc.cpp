#include "QFormDoc.h"
#include "ui_QFormDoc.h"
#include "TestMultiWindow.h"
#include <QDir>
#include <QFileDialog>
#include <QFontDialog>
#include <QTextStream>
#include <QToolBar>
#include <QVBoxLayout>

QFormDoc::QFormDoc(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QFormDoc)
{
    ui->setupUi(this);
    this->initActionToolBar();
}

QFormDoc::~QFormDoc()
{
  delete ui;
}
// 初始化工具栏的动作
void QFormDoc::initActionToolBar()
{
    QToolBar* locToolBar = new QToolBar(tr("文档"),this); //创建工具栏
    locToolBar->addAction(ui->actOpen); // 动态添加动作
    locToolBar->addAction(ui->actFont);
    locToolBar->addSeparator();
    locToolBar->addAction(ui->actCut);
    locToolBar->addAction(ui->actCopy);
    locToolBar->addAction(ui->actPaste);
    locToolBar->addAction(ui->actUndo);
    locToolBar->addAction(ui->actRedo);
    locToolBar->addSeparator();
    locToolBar->addAction(ui->actClose);

    locToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); // 这样可以显示图标和文字
//    locToolBar->setAutoFillBackground(true);

    QVBoxLayout *Layout = new QVBoxLayout();
    Layout->addWidget(locToolBar); //设置工具栏和编辑器上下布局
    Layout->addWidget(ui->plainTextEdit);
    Layout->setContentsMargins(2,2,2,2); //减小边框的宽度
    Layout->setSpacing(2);
    this->setLayout(Layout); //设置布局
    this->setAutoFillBackground(true); //避免工具栏显示背景图片
}
// 打开文件动作的槽函数,加载文件内容转交loadFromFile函数
void QFormDoc::on_actOpen_triggered()
{
    QString curPath=QDir::currentPath(); // 获取当前路径,也就是exe的执行路径
    QString aFileName=QFileDialog::getOpenFileName(this,tr("打开一个文件"),curPath,
                 "C++文件(*.h *cpp);;文本文件(*.txt);;所有文件(*.*)"); // 标准文件对话框

    if (aFileName.isEmpty())
        return; //如果未选择文件，退出
    loadFromFile(aFileName); // 加载文件
}

// 设置字体的动作槽函数
void QFormDoc::on_actFont_triggered()
{
     QFont   font;
    font=ui->plainTextEdit->font();

    bool    ok; // 选择是否有效
    font=QFontDialog::getFont(&ok,font); // 标准字体对话框
    if (ok) ui->plainTextEdit->setFont(font);
}

// 加载文件内容
void QFormDoc::loadFromFile(QString &aFileName)
{
    QString str; // 存放读取的文本内容
    QFile aFile(aFileName);  //以文件方式读出
    if (aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //以只读文本方式打开文件
    {
        QTextStream aStream(&aFile); //用文本流读取文件
        ui->plainTextEdit->clear();//清空
        while (!aStream.atEnd())
        {
            str=aStream.readLine();//读取文件的一行存入str
            ui->plainTextEdit->appendPlainText(str); //添加到文本框显示
        }
        aFile.close();//关闭文件

        this->mCurrentFile=aFileName;
        QFileInfo   fileInfo(aFileName); // 文本信息，例如路径、创建日期等
        QString shorName=fileInfo.fileName(); // 获取文件名称,aFileName是个路径不是文件名称
        this->setWindowTitle(shorName); // 文件名称作为窗口标题
    }
}

void QFormDoc::closeEvent(QCloseEvent *event)
{
//    TestMultiWindow * parentWindow = (TestMultiWindow *)parentWidget(); // 获取主窗口
//    parentWindow->setActWidgetEnable(true);

      // 不能获取主窗口,因为这是个独立的只能使用信号与槽机制了
      // 把setActWidgetEnable从公共函数变成公共槽函数使用
      emit isAboutClosed(true);
      Q_UNUSED(event);
}
