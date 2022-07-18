#include "TestFileDirOpera.h"
#include "ui_TestFileDirOpera.h"
#include <QFileInfo>

// 1. static copy
void TestFileDirOpera::on_pushButton_48_clicked()
{
    showBtnInfo(sender());
    QString sous=ui->editFile->text(); //源文件
    QFileInfo   fileInfo(sous);//获取文件信息
    QString newFile=fileInfo.path()+"/"+fileInfo.baseName()+"--副本."+fileInfo.suffix();
    QFile::copy(sous,newFile);
    ui->plainTextEdit->appendPlainText("源文件："+sous);
    ui->plainTextEdit->appendPlainText("复制为文件："+newFile+"\n");
}

// 2. static exists
void TestFileDirOpera::on_pushButton_51_clicked()
{
    showBtnInfo(sender());
    QString sous=ui->editFile->text(); //源文件
    bool the=QFile::exists(sous);
    if(the)
        ui->plainTextEdit->appendPlainText(+"true \n");
    else
        ui->plainTextEdit->appendPlainText(+"false \n");
}

// 3. static remove
void TestFileDirOpera::on_pushButton_49_clicked()
{
    showBtnInfo(sender());
    QString sous=ui->editFile->text(); //源文件
    QFile::remove(sous);
    ui->plainTextEdit->appendPlainText("删除文件："+sous+"\n");
}

// 4. static rename
void TestFileDirOpera::on_pushButton_50_clicked()
{
    showBtnInfo(sender());
    QString sous=ui->editFile->text(); //源文件
    QFileInfo   fileInfo(sous);//源文件信息
    QString newFile=fileInfo.path()+"/"+fileInfo.baseName()+".XYZ"; //更改文件后缀为".XYZ"
    QFile::rename(sous,newFile); //重命名文件
    ui->plainTextEdit->appendPlainText("源文件："+sous);
    ui->plainTextEdit->appendPlainText("重命名为："+newFile+"\n");
}

// 5. number copy
void TestFileDirOpera::on_pushButton_53_clicked()
{
    showBtnInfo(sender());
    QString sous=ui->editFile->text(); //源文件
    QFile   file(sous);

    QFileInfo   fileInfo(sous);
    QString newFile=fileInfo.path()+"/"+fileInfo.baseName()+"--副本."+fileInfo.suffix();

    file.copy(newFile);
    ui->plainTextEdit->appendPlainText("源文件："+sous);
    ui->plainTextEdit->appendPlainText("复制为文件："+newFile+"\n");
}

// 6. number exists
void TestFileDirOpera::on_pushButton_54_clicked()
{
    showBtnInfo(sender());
    QString sous=ui->editFile->text(); //源文件
    QFile   file(sous);
    bool the=file.exists();
    if(the)
        ui->plainTextEdit->appendPlainText(+"true \n");
    else
        ui->plainTextEdit->appendPlainText(+"false \n");
}

// 7. number remove
void TestFileDirOpera::on_pushButton_55_clicked()
{
    showBtnInfo(sender());
    QString sous=ui->editFile->text(); //源文件
    QFile   file(sous);
    file.remove();
    ui->plainTextEdit->appendPlainText("删除文件："+sous+"\n");
}

// 8. number rename
void TestFileDirOpera::on_pushButton_56_clicked()
{
    showBtnInfo(sender());
    QString sous=ui->editFile->text(); //源文件
    QFile   file(sous); //源文件对象
    QFileInfo   fileInfo(sous);//源文件信息
    QString newFile=fileInfo.path()+"/"+fileInfo.baseName()+".XYZ"; //修改文件后缀为“.XYZ”
    file.rename(newFile); //重命名文件
    ui->plainTextEdit->appendPlainText("源文件："+sous);
    ui->plainTextEdit->appendPlainText("重命名为："+newFile+"\n");
}
