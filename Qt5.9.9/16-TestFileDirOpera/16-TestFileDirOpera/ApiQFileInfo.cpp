#include "TestFileDirOpera.h"
#include "ui_TestFileDirOpera.h"
#include <QFileInfo>
#include <QDateTime>
#include <QDir>

// 1.  QFileInfo::absoluteFilePath() 返回包含文件名的绝对路径
void TestFileDirOpera::on_pushButton_28_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.absoluteFilePath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 2. QFileInfo::absolutePath() 返回文件的路径绝对路径。这不包括文件名
void TestFileDirOpera::on_pushButton_29_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.absolutePath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 3. fileName 返回文件名，不包括路径
void TestFileDirOpera::on_pushButton_33_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.fileName();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 4. filePath 返回文件名，包括路径（可以是绝对的或相对的）
void TestFileDirOpera::on_pushButton_34_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.filePath();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 5. size 返回文件大小（以字节为单位）。如果文件不存在或无法获取，则返回 0
void TestFileDirOpera::on_pushButton_38_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    qint64  dt=fileInfo.size();
    QString  str=QString("%1 Bytes").arg(dt);
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 6. path 返回文件的路径。这不包括文件名
void TestFileDirOpera::on_pushButton_37_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.path();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 7. QFileInfo.basename() 返回不带路径的文件的基本名称
void TestFileDirOpera::on_pushButton_30_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.baseName();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 8. completeBaseName 返回不带路径的文件的完整基本名称
void TestFileDirOpera::on_pushButton_31_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.completeBaseName();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 9.  suffix 返回文件的后缀（扩展名）
void TestFileDirOpera::on_pushButton_39_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.suffix();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 10. completeSuffix 返回文件的完整后缀（扩展名）
void TestFileDirOpera::on_pushButton_32_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QString  str=fileInfo.completeSuffix();
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 11. isDir 如果此对象指向目录或指向目录的符号链接，则返回 true；否则返回假
void TestFileDirOpera::on_pushButton_42_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editDir->text());
    bool  the=fileInfo.isDir();
    if(the)
        ui->plainTextEdit->appendPlainText(+"true \n");
    else
        ui->plainTextEdit->appendPlainText(+"false \n");
}

// 12. isFile 如果此对象指向文件或指向文件的符号链接，则返回 true。如果对象指向的不是文件，例如目录，则返回 false
void TestFileDirOpera::on_pushButton_43_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    bool  the=fileInfo.isFile();
    if(the)
        ui->plainTextEdit->appendPlainText(+"true \n");
    else
        ui->plainTextEdit->appendPlainText(+"false \n");
}

// 13. isExecutable 如果文件是可执行的，则返回 true；否则返回假
void TestFileDirOpera::on_pushButton_35_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    bool  the=fileInfo.isExecutable();
    if(the)
        ui->plainTextEdit->appendPlainText(+"true \n");
    else
        ui->plainTextEdit->appendPlainText(+"false \n");
}

// 14. created 返回文件创建时的日期和本地时间
void TestFileDirOpera::on_pushButton_58_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QDateTime  dt=fileInfo.created();
    QString  str=dt.toString("yyyy-MM-dd hh:mm:ss");
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 15. lastModified 返回上次修改文件的日期和本地时间
void TestFileDirOpera::on_pushButton_36_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QDateTime  dt=fileInfo.lastModified();
    QString  str=dt.toString("yyyy-MM-dd hh:mm:ss");
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 16. lastRead 返回上次读取（访问）文件的日期和本地时间
void TestFileDirOpera::on_pushButton_44_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    QDateTime  dt=fileInfo.lastRead();
    QString  str=dt.toString("yyyy-MM-dd hh:mm:ss");
    ui->plainTextEdit->appendPlainText(str+"\n");
}

// 17. static exists 如果文件存在则返回真；否则返回假
void TestFileDirOpera::on_pushButton_59_clicked()
{
    showBtnInfo(sender());
    bool  the=QFileInfo::exists(ui->editFile->text());
    if(the)
        ui->plainTextEdit->appendPlainText(+"true \n");
    else
        ui->plainTextEdit->appendPlainText(+"false \n");
}

// 18. exists 如果文件存在则返回真；否则返回假
void TestFileDirOpera::on_pushButton_27_clicked()
{
    showBtnInfo(sender());
    QFileInfo  fileInfo(ui->editFile->text());
    bool  the=fileInfo.exists();
    if(the)
        ui->plainTextEdit->appendPlainText(+"true \n");
    else
        ui->plainTextEdit->appendPlainText(+"false \n");
}

// 19.  列出所有子目录
void TestFileDirOpera::on_pushButton_11_clicked()
{
      showBtnInfo(sender());
      QDir    dir(ui->editDir->text());
      QStringList strList=dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

      ui->plainTextEdit->appendPlainText("所选目录下的所有目录:");
      for(int i=0;i<strList.count();i++)
      ui->plainTextEdit->appendPlainText(strList.at(i));
      ui->plainTextEdit->appendPlainText("\n");
}

// 20. 列出所有子文件
void TestFileDirOpera::on_pushButton_17_clicked()
{
      showBtnInfo(sender());
      QDir    dir(ui->editDir->text());
      QStringList strList=dir.entryList(QDir::Files);
      ui->plainTextEdit->appendPlainText("所选目录下的所有文件：");
      for(int i=0;i<strList.count();i++)
      ui->plainTextEdit->appendPlainText(strList.at(i));
      ui->plainTextEdit->appendPlainText("\n");
}
