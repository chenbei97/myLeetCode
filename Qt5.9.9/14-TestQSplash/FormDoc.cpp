#include "FormDoc.h"
#include "ui_FormDoc.h"
#include <QTextStream>
#include <QFileInfo>
#include <QFontDialog>
#include <QVBoxLayout>

FormDoc::FormDoc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDoc)
{
    ui->setupUi(this);

       //设置plainTextEdit填充满工作区
        QVBoxLayout *Layout = new QVBoxLayout();
        Layout->addWidget(ui->plainTextEdit); // 放进布局区
        Layout->setContentsMargins(2,2,2,2); // 设置要在布局周围使用的左、上、右和下边距。
        Layout->setSpacing(2); // 此属性保存布局内小部件之间的间距
        this->setLayout(Layout);

        this->setAttribute(Qt::WA_DeleteOnClose); //关闭时自动删除
        this->setAutoFillBackground(true); //避免工具栏显示背景图片
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
        // mFileOpened=true;
        emit  fileOpended(aFileName); // 改用信号传递打开的文本文件路径
    }
}

// 2. 返回文件名
QString FormDoc::currentFileName() const
{
        return  mCurrentFile;
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

// 5. paste,封装槽函数paste()
void FormDoc::textPaste()
{
    ui->plainTextEdit->paste();
}

// 6. cut,封装槽函数cut)
void FormDoc::textCut()
{
    ui->plainTextEdit->cut();
}
