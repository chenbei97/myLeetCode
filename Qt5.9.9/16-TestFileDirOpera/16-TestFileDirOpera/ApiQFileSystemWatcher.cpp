#include "TestFileDirOpera.h"
#include "ui_TestFileDirOpera.h"
#include <QDateTime>

//  1. 开始监听
void TestFileDirOpera::on_pushButton_46_clicked()
{
    ui->plainTextEdit->appendPlainText("监听目录："+ui->editDir->text()+"\n");

    fileWatcher->addPath(ui->editDir->text());//添加监听目录
    fileWatcher->addPath(ui->editFile->text());//添加监听文件

    // 函数指针传递法可以
    QObject::connect(fileWatcher,&QFileSystemWatcher::directoryChanged,
            this,&TestFileDirOpera::on_directoryChanged); //directoryChanged
    // 宏替换传递法也可以
    QObject::connect(fileWatcher,SIGNAL(fileChanged(const QString)),
           this,SLOT(on_fileChanged(const QString)));//fileChanged

     ui->pushButton_47->setEnabled(true); // 设置监听使能禁止
     ui->pushButton_46->setEnabled(false);// 设置停止监听使能
}

// 2. 监听目录变化的响应槽函数
void TestFileDirOpera::on_directoryChanged(const QString path)
{
    ui->plainTextEdit->appendPlainText(path);
    ui->plainTextEdit->appendPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm::ss")+" 目录发生了变化\n");
}

// 3. 监听文件变化的响应槽函数
void TestFileDirOpera::on_fileChanged(const QString path)
{
    ui->plainTextEdit->appendPlainText(path);
    ui->plainTextEdit->appendPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm::ss")+" 文件发生了变化\n");
}

// 4. 停止监听
void TestFileDirOpera::on_pushButton_47_clicked()
{

    showBtnInfo(sender());
    ui->plainTextEdit->appendPlainText("停止监听目录："+ui->editDir->text()+"\n");
    fileWatcher->removePath(ui->editDir->text());//
    fileWatcher->removePath(ui->editFile->text());//

    // 函数指针传递法可以
    QObject::disconnect(fileWatcher,&QFileSystemWatcher::directoryChanged,
            this,&TestFileDirOpera::on_directoryChanged); //directoryChanged
    // 宏替换传递法也可以
    QObject::disconnect(fileWatcher,SIGNAL(fileChanged(const QString)),
           this,SLOT(on_fileChanged(const QString)));//fileChanged

     ui->pushButton_47->setEnabled(false);
     ui->pushButton_46->setEnabled(true);
}

// 5. 显示监听目录
void TestFileDirOpera::on_pushButton_52_clicked()
{
    showBtnInfo(sender());
    QStringList strList=fileWatcher->directories();
    for (int i=0; i<strList.count();i++)
        ui->plainTextEdit->appendPlainText(strList.at(i));
    ui->plainTextEdit->appendPlainText("");

}

//  6. 显示监听文件
void TestFileDirOpera::on_pushButton_57_clicked()
{
    QStringList strList=fileWatcher->files();
    for (int i=0; i<strList.count();i++)
        ui->plainTextEdit->appendPlainText(strList.at(i));
    ui->plainTextEdit->appendPlainText("");
}
