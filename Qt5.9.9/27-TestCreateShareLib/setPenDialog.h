#ifndef SETPENDIALOG_H
#define SETPENDIALOG_H
#include "TestCreateShareLib_global.h" // 第1个区别
#include <QDialog>
#include    <QPen>

namespace Ui {
  class setPenDialog;
}

class TESTCREATESHARELIB_EXPORT setPenDialog : public QDialog // 第2个区别,宏修饰类名称
{
  Q_OBJECT
private:
    QPen    m_pen; // 对话框设置的pen属性保存在此变量中
public:
  explicit setPenDialog(QWidget *parent = nullptr);
  ~setPenDialog();
  void    setPen(QPen pen); //设置QPen,用于对话框的界面显示
  QPen  getPen(); //获取对话框设置的QPen的属性
  static  QPen getPen(QPen  iniPen, bool &ok);  //静态函数
private slots:
  void on_btnColor_clicked();

private:
  Ui::setPenDialog *ui;
};

#endif // SETPENDIALOG_H
