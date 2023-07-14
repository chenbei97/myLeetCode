#include "TestStandardDialog.h"
#include "ui_TestStandardDialog.h"
#include <QInputDialog>

// 1. 字符串输入对话框
void TestStandardDialog::on_btnInputString_clicked()
{
    QString dlgTitle="输入文字对话框";
    QString txtLabel="请输入文件名";
    QString defaultInput="hello qt!"; // 弹出窗口默认显示的文字
    QLineEdit::EchoMode echoMode=QLineEdit::Normal;//正常文字输入
//    QLineEdit::EchoMode echoMode=QLineEdit::Password;//密码输入

    bool ok=false;
    QString text = QInputDialog::getText(this, dlgTitle,txtLabel, echoMode,defaultInput, &ok);
    if (ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
    else
        ui->plainTextEdit->appendPlainText("输入字符串失败!");
}

// 2. 整数对话框
void TestStandardDialog::on_btnInputInt_clicked()
{
    QString dlgTitle="输入整数对话框";
    QString txtLabel="设置字体大小";
    int defaultValue=ui->plainTextEdit->font().pointSize(); //现有字体大小
    int minValue=6, maxValue=50,stepValue=1; //规定可以输入的范围，步长
    bool ok=false;
    int inputValue = QInputDialog::getInt(this, dlgTitle,txtLabel,
                               defaultValue, minValue,maxValue,stepValue,&ok);
    if (ok) //是否确认输入
    {
        QFont   font=ui->plainTextEdit->font();
        font.setPointSize(inputValue);
        ui->plainTextEdit->setFont(font);
    }
    else
    ui->plainTextEdit->appendPlainText("输入整型数字失败!");
}

// 3. 浮点数对话框
void TestStandardDialog::on_btnInputFloat_clicked()
{
    QString dlgTitle="输入浮点数对话框";
    QString txtLabel="输入一个浮点数";
    float defaultValue=3.13;

    float minValue=0, maxValue=10000;  //范围
    int decimals=2;//小数点位数

    bool ok=false;
    float inputValue = QInputDialog::getDouble(this, dlgTitle,txtLabel,
                            defaultValue, minValue,maxValue,decimals,&ok);
    if (ok) //确认选择
    {
        QString str=QString::asprintf("输入了一个浮点数:%.2f",inputValue);
        ui->plainTextEdit->appendPlainText(str);
    }
    else
        ui->plainTextEdit->appendPlainText("输入浮点数字失败!");
}

// 4.下拉条目对话框
void TestStandardDialog::on_btnInputItem_clicked()
{
    QStringList items; //ComboBox 列表的内容
    items <<"优秀"<<"良好"<<"合格"<<"不合格";

    QString dlgTitle="条目选择对话框";
    QString txtLabel="请选择级别";
    int     curIndex=0; //初始选择项
    bool    editable=false; //ComboBox是否可编辑
    bool    ok=false;
    QString text = QInputDialog::getItem(this, dlgTitle,txtLabel,items,curIndex,editable,&ok);

    if (ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
    else
        ui->plainTextEdit->appendPlainText("选择下拉条目失败!");
}
