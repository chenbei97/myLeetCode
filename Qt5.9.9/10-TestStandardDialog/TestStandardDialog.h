#ifndef TESTSTANDARDDIALOG_H
#define TESTSTANDARDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class TestStandardDialog; }
QT_END_NAMESPACE

class TestStandardDialog : public QDialog
{
  Q_OBJECT

public:
  TestStandardDialog(QWidget *parent = nullptr);
  ~TestStandardDialog();

private slots:
  // 文件对话框
  void on_btnOpen_clicked(); // 打开1个文件
  void on_btnOpenMulti_clicked();// 打开多个文件
  void on_btnSelDir_clicked();// 选择已有目录
  void on_btnSave_clicked(); // 保存1个文件
  // 颜色和字体对话框
  void on_btnColor_clicked();
  void on_btnFont_clicked();

  // 清空文本
  void on_btnClearText_clicked();


  // 输入对话框,分别输入字符串、整数、浮点数和下拉列表框
  void on_btnInputString_clicked();
  void on_btnInputInt_clicked();
  void on_btnInputFloat_clicked();
  void on_btnInputItem_clicked();

  void on_btnMsgQuestion_clicked();

  void on_btnMsgInformation_clicked();

  void on_btnMsgWarning_clicked();

  void on_btnMsgCritical_clicked();

  void on_btnMsgAbout_clicked();

  void on_btnMsgAboutQt_clicked();

private:
  Ui::TestStandardDialog *ui;
};
#endif // TESTSTANDARDDIALOG_H
