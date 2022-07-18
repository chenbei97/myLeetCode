#include "TestFileDirOpera.h"
#include "ui_TestFileDirOpera.h"
#include <QDir>
#include <QFileDialog>

TestFileDirOpera::TestFileDirOpera(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::TestFileDirOpera)
{
      ui->setupUi(this);
      this->setWindowFlags(Qt::Window);
      this->fileWatcher = new QFileSystemWatcher;
       ui->pushButton_47->setEnabled(false); // 停止监听
}

TestFileDirOpera::~TestFileDirOpera()
{
  delete ui;
}
// 1. 用于显示btn的信息
void TestFileDirOpera::showBtnInfo(QObject *btn)
{
    // btn有2个属性text和toolTip,在ui的组件信息可以找到
    QPushButton *theBtn =static_cast<QPushButton*>(btn);
    ui->plainTextEdit->appendPlainText(theBtn->text());
    ui->plainTextEdit->appendPlainText(theBtn->toolTip()+"\n");
}

// 2. 打开文件
void TestFileDirOpera::on_pushButton_41_clicked()
{
        // QString curDir=QDir::currentPath();
        QDir curPath = QDir::current();
        curPath.cdUp();
        curPath.cd(QCoreApplication::applicationName());
        QString aFile=QFileDialog::getOpenFileName(this,"打开一个文件",curPath.path(),"所有文件(*.*)");
        ui->editFile->setText(aFile);
}

// 3. 打开目录
void TestFileDirOpera::on_pushButton_45_clicked()
{
        // QString curDir=QDir::currentPath();
        QDir curPath = QDir::current();
        curPath.cdUp();
        curPath.cd(QCoreApplication::applicationName());
        QString aDir=QFileDialog::getExistingDirectory(this,"选择一个目录",curPath.path(),QFileDialog::ShowDirsOnly);
        ui->editDir->setText(aDir);
}

// 4. 清除文本框
void TestFileDirOpera::on_pushButton_5_clicked()
{
       ui->plainTextEdit->clear();
}





