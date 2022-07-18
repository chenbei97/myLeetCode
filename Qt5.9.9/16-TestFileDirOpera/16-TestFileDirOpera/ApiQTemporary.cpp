#include "TestFileDirOpera.h"
#include "ui_TestFileDirOpera.h"
#include <QTemporaryDir>
#include <QTemporaryFile>

// 临时文件夹
void TestFileDirOpera::on_pushButton_21_clicked()
{
    showBtnInfo(sender());
    QTemporaryDir    dir;
    dir.setAutoRemove(true);
    ui->plainTextEdit->appendPlainText(dir.path()+"\n");
}

// 临时文件
void TestFileDirOpera::on_pushButton_25_clicked()
{
    showBtnInfo(sender());
    QTemporaryFile    aFile;
    aFile.setAutoRemove(true);
    aFile.open();
    ui->plainTextEdit->appendPlainText(aFile.fileName()+"\n");
    aFile.close();
}
