#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
// 希望设计一个SPlash特点的无边框对话框,如何用鼠标拖动无边框对话框
// 使用QSettings存储用户名、密码等信息
// 使用QCryptographicHash对字符串加密

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    bool    m_moving=false;//表示窗口是否在鼠标操作下移动
    QPoint  m_lastPos;  //上一次的鼠标位置

    QString m_user="cb"; //初始化用户名
    QString m_pswd="123";//初始化密码

    int m_tryCount=0; //试错次数

    void    readSettings(); //读取设置,从注册表
    void    writeSettings();//写入设置,从注册表

    QString encrypt(const QString& str);//字符串加密

protected:
     // 用于鼠标拖动窗口的鼠标事件操作,SPlash没有窗口不能像普通窗口那样拖动标题栏实现拖动
    // 所以必须定义自己的鼠标拖动事件
     void mousePressEvent(QMouseEvent *event);
     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::LoginDialog *ui;

private slots:
    void on_btnOK_clicked(); //OK按键
    void on_btnCancel_clicked(); // 取消按键
};

#endif // LOGINDIALOG_H
