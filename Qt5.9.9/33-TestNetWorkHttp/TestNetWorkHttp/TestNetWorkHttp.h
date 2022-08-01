#ifndef TESTNETWORKHTTP_H
#define TESTNETWORKHTTP_H

#include <QMainWindow>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class TestNetWorkHttp; }
QT_END_NAMESPACE

class TestNetWorkHttp : public QMainWindow
{
  Q_OBJECT
private:
    QNetworkAccessManager networkManager;//网络管理,用于发送网络请求
    QNetworkReply *reply;   //网络响应
    QFile *downloadedFile;//下载保存的临时文件
private slots://自定义槽函数,对QNetworkReply的3个信号响应
    void on_finished();
    void on_readyRead();
    void on_downloadProgress(qint64 bytesRead, qint64 totalBytes);
public:
  explicit TestNetWorkHttp(QWidget *parent = nullptr);
  ~TestNetWorkHttp();
private slots:
  void on_btnDownload_clicked();
  void on_btnDefaultPath_clicked();
  void on_editURL_textChanged(const QString &arg1);

private:
  Ui::TestNetWorkHttp *ui;
};
#endif // TESTNETWORKHTTP_H
