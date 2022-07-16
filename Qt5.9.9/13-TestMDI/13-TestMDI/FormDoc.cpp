#include "FormDoc.h"
#include "ui_FormDoc.h"
#include <QTextStream>
#include <QFileInfo>
#include <QFontDialog>

FormDoc::FormDoc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDoc)
{
    ui->setupUi(this);
}

FormDoc::~FormDoc()
{
    delete ui;
}

// 1. 打开文件
void FormDoc::loadFromFile(QString &aFileName)
{
    QFile aFile(aFileName);  //以文件方式读出
    if (aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //以只读文本方式打开文件
    {
        QTextStream aStream(&aFile); //用文本流读取文件
        ui->plainTextEdit->clear();//清空
        ui->plainTextEdit->setPlainText(aStream.readAll()); //读取文本文件
        aFile.close();//关闭文件

        mCurrentFile=aFileName;//保存当前文件名
        QFileInfo   fileInfo(aFileName); //文件信息
        QString str=fileInfo.fileName(); //去除路径后的文件名
        this->setWindowTitle(str); // 文件名用于设置窗口标题
        mFileOpened=true;
    }
    else{
        mFileOpened = false; // 打开文本失败
    }
}

// 2. 返回文件名
QString FormDoc::currentFileName() const
{
        return  mCurrentFile;
}

// 3. 文件是否已打开
bool FormDoc::isFileOpened() const
{
    return mFileOpened;
}

// 3. 设置字体
void FormDoc::setEditFont()
{
    QFont   font;
    font=ui->plainTextEdit->font(); // 获取文字字体

    bool    ok;
    font = QFontDialog::getFont(&ok,font); // 字体对话框
    if (ok) ui->plainTextEdit->setFont(font); // 选择有效
}

// 4. copy,封装槽函数copy()
void FormDoc::textCopy()
{
    ui->plainTextEdit->copy();
}

// paste,封装槽函数paste()
void FormDoc::textPaste()
{
    ui->plainTextEdit->paste();
}

// cut,封装槽函数cut)
void FormDoc::textCut()
{
    ui->plainTextEdit->cut();
}
