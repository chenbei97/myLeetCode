#include "TestStandardDialog.h"
#include "ui_TestStandardDialog.h"
#include <QDir>
#include <QFileDialog>

// 1. 选择单个文件
void TestStandardDialog::on_btnOpen_clicked()
{
    QString curPath=QDir::currentPath();//获取系统当前目录
//  QString  curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
    QString dlgTitle="选择一个文件"; //对话框标题
    QString filter="文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)"; //文件过滤器

    QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter); // 使用打开1个文件的对话框静态函数

    // 只是打印文件名字,不会对打开的文件做什么,这是文本流操作的内容这里不介绍
    if (!aFileName.isEmpty())
        ui->plainTextEdit->appendPlainText(aFileName);
    else
        ui->plainTextEdit->appendPlainText(QString("文件打开失败!"));
}

// 2. 选择多个文件
void TestStandardDialog::on_btnOpenMulti_clicked()
{
//  QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
    QString curPath=QDir::currentPath();//获取系统当前目录
    QString dlgTitle="选择多个文件"; //对话框标题
    QString filter="文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)"; //文件过滤器

    // 使用QStringList接收
    QStringList fileList=QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);
    if (fileList.isEmpty()) {
        ui->plainTextEdit->appendPlainText(QString("文件打开失败!"));
        return;
    }
   // 只是打印文件名字,不会对打开的文件做什么,这是文本流操作的内容这里不介绍
    for (int i=0; i<fileList.count();i++) // 唯一的区别需要遍历每个文件
        ui->plainTextEdit->appendPlainText(fileList.at(i));
}

// 3.选择文件夹
void TestStandardDialog::on_btnSelDir_clicked()
{
    QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
    //  QString curPath=QDir::currentPath();//获取系统当前目录
    //调用打开文件对话框打开一个文件

    QString dlgTitle="选择一个目录"; //对话框标题
    // 仅在文件对话框中显示目录，默认情况下，文件和目录都会显示
    QString selectedDir=QFileDialog::getExistingDirectory(this,dlgTitle,curPath,QFileDialog::ShowDirsOnly);

    // 只是打印文件名字,不会对打开的文件做什么,这是文本流操作的内容这里不介绍
    if (!selectedDir.isEmpty())
        ui->plainTextEdit->appendPlainText(selectedDir);
    else
        ui->plainTextEdit->appendPlainText(QString("选择文件目录失败!"));
}

// 4.保存文件
void TestStandardDialog::on_btnSave_clicked()
{
    QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
    QString dlgTitle="保存文件"; //对话框标题
    QString filter="文本文件(*.txt);;头文件(*.h);;C++文件(.cpp);;所有文件(*.*)"; //文件过滤器
    QString aFileName=QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);

    // 只是打印文件名字,不会对打开的文件做什么,这是文本流操作的内容这里不介绍
    if (!aFileName.isEmpty())
        ui->plainTextEdit->appendPlainText(aFileName);
    else
        ui->plainTextEdit->appendPlainText(QString("保存文本失败!"));
}
