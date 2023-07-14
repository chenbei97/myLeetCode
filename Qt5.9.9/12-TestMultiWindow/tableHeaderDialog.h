#ifndef TABLEHEADERDIALOG_H
#define TABLEHEADERDIALOG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
  class tableHeaderDialog;
}

class tableHeaderDialog : public QDialog
{
  Q_OBJECT

public:
  explicit tableHeaderDialog(QWidget *parent = nullptr);
  ~tableHeaderDialog();

  void setHeader(const QStringList & header); // 设置表头
  QStringList getHeader();// 返回表头

private slots:
  void on_btnOK_clicked();
  void on_btnCancel_clicked();
  void on_listView_doubleClicked(const QModelIndex &index);
private:
  Ui::tableHeaderDialog *ui;
  QStringListModel * theModel;
signals:
  void headerTitle(QString title);
};

#endif // TABLEHEADERDIALOG_H
