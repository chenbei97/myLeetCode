#include "TestFileDirOpera.h"
#include "ui_TestFileDirOpera.h"
#include <QDir>
#include <QFileDialog>

// 《1》静态函数
// 1. tempPath 临时目录
void TestFileDirOpera::on_pushButton_10_clicked()
{
    showBtnInfo(sender());
    QString  str=QDir::tempPath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 2. 根目录
void TestFileDirOpera::on_pushButton_9_clicked()
{
    showBtnInfo(sender());
    QString  str=QDir::rootPath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 3. home目录
void TestFileDirOpera::on_pushButton_8_clicked()
{
    showBtnInfo(sender());
    QString  str=QDir::homePath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 4. 磁盘目录
void TestFileDirOpera::on_pushButton_7_clicked()
{
    showBtnInfo(sender());
    QFileInfoList  strList=QDir::drives();
    for(int i=0;i<strList.count();i++)
        ui->plainTextEdit->appendPlainText(strList.at(i).path());
    ui->plainTextEdit->appendPlainText("\n");
}

// 5. 当前目录
void TestFileDirOpera::on_pushButton_6_clicked()
{
    showBtnInfo(sender());
    QString  str=QDir::currentPath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 6. 设置当前目录
void TestFileDirOpera::on_pushButton_60_clicked()
{
    showBtnInfo(sender());
    QDir::setCurrent(ui->editDir->text());
    QString  str=QDir::currentPath();
    ui->editDir->setText(str);
    ui->plainTextEdit->appendPlainText("设置当前路径为："+str+"\n");
}

// 《2》文件或目录操作
// 1.  创建目录
void TestFileDirOpera::on_pushButton_20_clicked()
{
     showBtnInfo(sender());
    QString subDir="subdir1";
    QDir    dir(ui->editDir->text());
    bool   ok=dir.mkdir(subDir);
    if (ok)
        ui->plainTextEdit->appendPlainText("所选目录下成功新建一个目录 "+subDir+"\n");
    else
        ui->plainTextEdit->appendPlainText("创建目录失败\n");
}

// 2. 删除目录
void TestFileDirOpera::on_pushButton_24_clicked()
{
    showBtnInfo(sender());
    QString sous(ui->editDir->text());
    QDir    dir(sous);
    bool   ok=dir.rmdir(sous);
    if (ok)
        ui->plainTextEdit->appendPlainText("成功删除所选目录\n"+sous+"\n");
    else
        ui->plainTextEdit->appendPlainText("删除失败\n");
}

// 3. 删除文件
void TestFileDirOpera::on_pushButton_22_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    QString sous(ui->editFile->text());
    bool ok= dir.remove(sous);
    if (ok)
        ui->plainTextEdit->appendPlainText("删除文件:"+sous+"\n");
    else
        ui->plainTextEdit->appendPlainText("删除文件失败\n");
}

// 4.  重命名文件
void TestFileDirOpera::on_pushButton_23_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    QString sous=ui->editFile->text(); //源文件
    QFileInfo   fileInfo(sous);//
    QString newFile=fileInfo.path()+"/"+fileInfo.baseName()+".XYZ";
    dir.rename(sous,newFile);

    ui->plainTextEdit->appendPlainText("源文件："+sous);
    ui->plainTextEdit->appendPlainText("重命名为："+newFile+"\n");
}

// 5. 将目录的路径设置为path
void TestFileDirOpera::on_pushButton_26_clicked()
{
    showBtnInfo(sender());
    QString curDir=QDir::currentPath();
    QDir    lastDir(curDir);
    ui->plainTextEdit->appendPlainText("选择目录之前："+lastDir.absolutePath());

    QString aDir=QFileDialog::getExistingDirectory(this,"选择一个目录",curDir,QFileDialog::ShowDirsOnly);
    if (aDir.isEmpty())
       return;

    ui->editDir->setText(aDir);
    lastDir.setPath(aDir);
    ui->plainTextEdit->appendPlainText("选择目录之后："+lastDir.absolutePath()+"\n");
}

// 6.  删除目录及下属文件
void TestFileDirOpera::on_pushButton_12_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    bool ok= dir.removeRecursively();
    if (ok)
        ui->plainTextEdit->appendPlainText("删除目录及文件成功\n");
    else
        ui->plainTextEdit->appendPlainText("删除目录及文件失败\n");
}

// 《3》文件或目录信息
// 1. 绝对文件路径
void TestFileDirOpera::on_pushButton_13_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    QString  str=dir.absoluteFilePath(ui->editFile->text());
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 2. 绝对路径
void TestFileDirOpera::on_pushButton_14_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    QString  str=dir.absolutePath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 3. 规范路径
void TestFileDirOpera::on_pushButton_15_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    QString  str=dir.canonicalPath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 4.返回目录中文件的路径名
void TestFileDirOpera::on_pushButton_19_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    QString  str=dir.filePath(ui->editFile->text());
    ui->plainTextEdit->appendPlainText(str+"\n");

}

// 5. 是否存在
void TestFileDirOpera::on_pushButton_18_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    bool  the=dir.exists();
    if (the)
        ui->plainTextEdit->appendPlainText("true \n");
    else
        ui->plainTextEdit->appendPlainText("false \n");
}

// 6. 返回目录的名称
void TestFileDirOpera::on_pushButton_16_clicked()
{
    showBtnInfo(sender());
    QDir    dir(ui->editDir->text());
    QString  str=dir.dirName();
    ui->plainTextEdit->appendPlainText(str+"\n");
}
