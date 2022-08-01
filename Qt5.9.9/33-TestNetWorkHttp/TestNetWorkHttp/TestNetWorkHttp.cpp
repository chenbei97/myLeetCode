#include "TestNetWorkHttp.h"
#include "ui_TestNetWorkHttp.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QDebug>

TestNetWorkHttp::TestNetWorkHttp(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestNetWorkHttp)
{
      ui->setupUi(this);
      ui->editURL->setClearButtonEnabled(true);// 行编辑是否在非空时显示清除按钮
}

TestNetWorkHttp::~TestNetWorkHttp()
{
  delete ui;
}

// 1. 开始下载
void TestNetWorkHttp::on_btnDownload_clicked()
{
    QString urlSpec = ui->editURL->text().trimmed(); // 去掉左右可能存在的空格
    if (urlSpec.isEmpty())
    {
        QMessageBox::information(this, "错误","请指定需要下载的URL");
        return;
    }

    QUrl newUrl = QUrl::fromUserInput(urlSpec);//文本转为真正的URL地址
    if (!newUrl.isValid())
    {
        QMessageBox::information(this, "错误",
          QString("无效URL: %1 \n 错误信息: %2").arg(urlSpec, newUrl.errorString()));
        return;
    }

    QString tempDir =ui->editPath->text().trimmed();//存放的临时目录
    if (tempDir.isEmpty())
    {
        QMessageBox::information(this, tr("错误"), "请指定保存下载文件的目录");
        return;
    }

    QString fullFileName =tempDir+newUrl.fileName(); // 完整的文件路径

    if (QFile::exists(fullFileName)) // 如果存在就把这个路径先移除
        QFile::remove(fullFileName);

    this->downloadedFile =new QFile(fullFileName);//创建临时文件
    if (!downloadedFile->open(QIODevice::WriteOnly)) // 如果不是以只写打开的
    {
        QMessageBox::information(this, tr("错误"),"临时文件打开错误");
        return;
    }

    ui->btnDownload->setEnabled(false); // 现在处于下载状态不能再点击下载

    // 对要下载的地址发起网络请求,并接收响应,响应的3个信号绑定
    this->reply = networkManager.get(QNetworkRequest(newUrl));
    connect(reply, SIGNAL(finished()), this, SLOT(on_finished()));
    connect(reply, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),this, SLOT(on_downloadProgress(qint64,qint64)));
}

// 2. 设置缺省路径
void TestNetWorkHttp::on_btnDefaultPath_clicked()
{
    QDir curPath=QDir::current(); // exe所在路径
    curPath.cdUp();
    curPath.cd("TestNetworkHttp");
    QString dir = QFileDialog::getExistingDirectory(this,"打开目录",curPath.path());
    // qDebug()<<dir;
    if (dir.isEmpty()) return;
    ui->editPath->setText(dir+"/");//把路径显示出来,多加1个"/"是为了后边好直接加上文件名
}

// 3. QNetworkReply的finish信号响应
void TestNetWorkHttp::on_finished()
{
    QFileInfo fileInfo;
    fileInfo.setFile(this->downloadedFile->fileName()); // 获取下载的文件信息
    this->downloadedFile->close();
    delete downloadedFile; // 释放对象
    downloadedFile = Q_NULLPTR;

    this->reply->deleteLater(); //网络响应也释放
    this->reply = Q_NULLPTR;

    if (ui->checkOpen->isChecked())// 如果勾选了打开下载的文件,fileInfo存储了这个绝对路径信息进行打开
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.absoluteFilePath()));

    ui->btnDownload->setEnabled(true); // 下载使能
}

// 4. QNetworkReply的readyRead信号响应
void TestNetWorkHttp::on_readyRead()
{
    this->downloadedFile->write(reply->readAll()); //把下载的数据写入downloadedFile
}

// 5. QNetworkReply的downloadProgress信号
void TestNetWorkHttp::on_downloadProgress(qint64 bytesRead, qint64 totalBytes)
{
    // 下载进程,totalBytes表示总的文件大小
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead); //bytesRead表示已读取的字节数
}

// 6.如果文本编辑框变化就设置到进度条初始值为0最大100
void TestNetWorkHttp::on_editURL_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
}
