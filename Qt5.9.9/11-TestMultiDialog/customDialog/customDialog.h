#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include    <QMainWindow>
#include    <QStandardItemModel>
#include    <QItemSelectionModel>
#include    <QModelIndex>
#include    <QLabel>
#include    "tableItemDialog.h"
#include    "tableHeaderDialog.h"
#include    "tableSizeDialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class customDialog; }
QT_END_NAMESPACE

class customDialog : public QMainWindow
{
  Q_OBJECT

public:
  explicit customDialog(QWidget *parent = nullptr);
  ~customDialog();

private slots:
  void on_tableView_clicked(const QModelIndex &index);
  void on_actTab_SetSize_triggered();
  void on_actTab_SetHeader_triggered();
  void on_actFile_Quit_triggered();
  void on_actTab_Locate_triggered();
private slots:
  // 自定义槽函数
  void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);
private:
    void initialize();
private:
    void initialize_sizeDialog_connection();
    void initialize_headerDialog_connection();
    void initialize_itemDialog_connection();
private slots:
    void on_sizeRow(int row); // sizeDialog的rowChanged信号的槽函数
    void on_sizeColumn(int column);// sizeDialog的columnChanged信号的槽函数
    void on_tableHeader(QString title);// headerDialog的headerTitle信号的槽函数
    void on_cellRow(QString row); // itemDialog的rowChanged信号的槽函数
    void on_cellColumn(QString column);// itemDialog的columnChanged信号的槽函数
    void on_tableView_doubleClicked(const QModelIndex &index);
signals:
    void doubleClickedIndex(const QModelIndex & index);
private:
    void closeEvent(QCloseEvent *event);//关闭窗口事件,可以询问是否退出
public:
    // 主窗口提供3个公共函数使得itemDialog指针可以控制主窗口的单元格进行交互
    void setTableItemEnable(bool enable);//设置单元格的enabled属性
    void setTableItemText(int row,int column,QString text);//设置单元格的内容
    QString getTableItemText(int row,int column); // 获取单元格内容
    void setItemDialogNullptr();//将itemDialog指针设置为nullptr
private:
    QLabel  *LabCellPos;    //当前单元格行列号(状态栏)
    QLabel  *LabCellText;   //当前单元格内容(状态栏)
    QStandardItemModel  *theModel;//数据模型
    QItemSelectionModel *theSelection;//Item选择模型
    tableSizeDialog * sizeDialog ; // 设置表格行列数的模态对话框
    tableHeaderDialog *headerDialog;// 设置表头的模态对话框
    tableItemDialog  * itemDialog ;// 设置单元格内容的非模态对话框
private:
  Ui::customDialog *ui;
};
#endif // CUSTOMDIALOG_H
