#ifndef TABLESIZEDIALOG_H
#define TABLESIZEDIALOG_H

#include <QDialog>

namespace Ui {
  class tableSizeDialog;
}

class tableSizeDialog : public QDialog
{
  Q_OBJECT

public:
  explicit tableSizeDialog(QWidget *parent = nullptr);
  ~tableSizeDialog();

  int rowCount(); // 从对话框获取输入的行数
  int columnCount(); // 从对话框获取输入的列数
  void setRowColumn(int row,int column); // 设置对话框的行数和列数

private slots:
  void on_spinBoxColumn_valueChanged(int arg1);
  void on_spinBoxRow_valueChanged(int arg1);
  void on_btnOK_clicked();
  void on_btnCancel_clicked();

signals:
  void rowChanged(int row);
  void columnChanged(int column);
private:
  Ui::tableSizeDialog *ui;
};

#endif // TABLESIZEDIALOG_H
