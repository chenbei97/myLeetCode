#ifndef QFORMTABLE_H
#define QFORMTABLE_H

#include <QMainWindow>
#include    <QStandardItemModel>
#include    <QItemSelectionModel>

#include "tableHeaderDialog.h" // 11-TestMultiDialog例子中定义过的直接拿来用
#include "tableSizeDialog.h"
namespace Ui {
  class QFormTable;
}

class QFormTable : public QMainWindow
{
  Q_OBJECT

public:
  explicit QFormTable(QWidget *parent = nullptr);
  ~QFormTable();

private slots:
  // 这2个槽函数会调用2个自定义的对话框
  void on_actSize_triggered();
  void on_actSetHeader_triggered();

private:
  Ui::QFormTable *ui;
  tableHeaderDialog * tableHeader=nullptr;//设置表头文字对话框, 一次创建，exec()重复调用
  QStandardItemModel  *theModel;//数据模型
  QItemSelectionModel *theSelection;//Item选择模型
};

#endif // QFORMTABLE_H
