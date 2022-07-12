#ifndef TABLEITEMDIALOG_H
#define TABLEITEMDIALOG_H

#include <QDialog>

namespace Ui {
  class tableItemDialog;
}

class tableItemDialog : public QDialog
{
  Q_OBJECT

public:
  explicit tableItemDialog(QWidget *parent = nullptr);
  ~tableItemDialog();

public:
  void setSpinRange(int row, int column); // 设置表格最大行列数
  void setSpinValue(int row,int column); // 定位当前单元格
private slots:
  void on_btnSetText_clicked();
  void on_btnClose_clicked();
  void on_spinBoxColumn_valueChanged(QString arg1);
  void on_spinBoxRow_valueChanged(QString arg1);
  void statusShow(const QModelIndex & index);
private:
  void initialize_connection();
signals:
  void rowChanged(QString row);
  void columnChanged(QString row);
private:
    void closeEvent(QCloseEvent *) override;
    void showEvent(QShowEvent *event) override;
private:
  Ui::tableItemDialog *ui;
};

#endif // TABLEITEMDIALOG_H
