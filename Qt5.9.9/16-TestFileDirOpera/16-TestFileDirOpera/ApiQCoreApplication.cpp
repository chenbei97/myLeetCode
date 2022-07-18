#include "TestFileDirOpera.h"
#include "ui_TestFileDirOpera.h"

// 1. applicationDirPath 返回包含应用程序可执行文件的目录
void TestFileDirOpera::on_pushButton_clicked()
{
    showBtnInfo(sender());
    QString str=QCoreApplication::applicationDirPath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 2. applicationFilePath 返回应用程序可执行文件的文件路径
void TestFileDirOpera::on_pushButton_2_clicked()
{
    showBtnInfo(sender());
    QString str=QCoreApplication::applicationFilePath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 3. applicationName 此属性包含此应用程序的名称
void TestFileDirOpera::on_pushButton_3_clicked()
{
    showBtnInfo(sender());
    QString str=QCoreApplication::applicationName();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 4. libraryPaths 返回应用程序在动态加载库时将搜索的路径列表
void TestFileDirOpera::on_pushButton_4_clicked()
{
    showBtnInfo(sender());
    QStringList strList=QCoreApplication::libraryPaths();
    for (int i=0;i<strList.count();i++)
        ui->plainTextEdit->appendPlainText(strList.at(i));
    ui->plainTextEdit->appendPlainText("");
}

// 5. organizationName 此属性包含编写此应用程序的组织的名称
void TestFileDirOpera::on_pushButton_61_clicked()
{
   showBtnInfo(sender());
   QString str=QCoreApplication::organizationName();
   ui->plainTextEdit->appendPlainText(str+"\n");

}

// 6. exit 告诉应用程序退出并返回代码
void TestFileDirOpera::on_pushButton_40_clicked()
{
    QCoreApplication::exit();
}
