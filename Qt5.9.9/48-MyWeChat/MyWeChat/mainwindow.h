#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QFile>
#include <QFileDialog>
#include <QCloseEvent>
#include <QDomNode>
#include <QDateTime>
#include <QDebug>
#include <filereceive.h>
#include <filesend.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  enum ChatMsgType  {ChatLine, OnLine,OffLine,FileName,Refuse}; //广播消息类型:聊天内容,用户上线和离线,传输的文件名和拒收文件

private:
  void init();
  void onLine(const QString& name,const QString &time);
  void offLine(const QString& name,const QString &time);
  void chatLine(ChatMsgType type,QString name = "");
  void recvAndProcessChatMsg(); // 接收并处理UDP数据报
  void recvFileName(QString name, QString hostip, QString rmtname, QString filename);
  QString getLocalHostIP(); // 本地IP
  QString getLocalMsg(); // 本地消息
  Ui::MainWindow *ui;
  QString mName; // 本地用户名
  QUdpSocket * mUdpSocket; // 套接字
  quint16 mUdpPort; // 端口号
  QDomDocument mDomDoc; // XML文档
  QString mFileName; // 本地文件名
  FileSend * mFileSend;
protected:
  void closeEvent(QCloseEvent * e);
};
#endif // MAINWINDOW_H
