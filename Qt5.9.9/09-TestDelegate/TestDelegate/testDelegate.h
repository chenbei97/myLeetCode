#ifndef TESTDELEGATE_H
#define TESTDELEGATE_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "comboBoxDelegate.h"
#include "doubleSpinBoxDelegate.h"
#include "spinBoxDelegate.h"

#define     FixedColumnCount    6       //test.txt只有6列
QT_BEGIN_NAMESPACE
namespace Ui { class TestDelegate; }
QT_END_NAMESPACE

class TestDelegate : public QMainWindow
{
  Q_OBJECT

public:
  TestDelegate(QWidget *parent = nullptr);
  ~TestDelegate();
private slots:
    void on_actOpen_triggered();//打开文件
    void on_actAppend_triggered();//添加项
    void on_actSave_triggered(); // 保存文件
    void on_actInsert_triggered();//插入项
    void on_actDelete_triggered();//删除项
    void on_actExit_triggered();// 退出
    void on_actModelData_triggered();//更新文本显示
    void on_actAlignLeft_triggered(); //左对齐
    void on_actAlignCenter_triggered();//居中对齐
    void on_actAlignRight_triggered();//右对齐
    void on_actFontBold_triggered(bool checked);//文本加粗
    void on_currentItemIndexChanged(const QModelIndex &current,
        const QModelIndex &previous); // tableView鼠标选中状态的槽函数
private:
    QLabel  *LabCurFile;  //当前打开文本路径
    QLabel  *LabCellPos; //当前鼠标单元格位置
    QLabel * LabCellText; // 当前鼠标单元格内容
    QStandardItemModel  *theModel;//数据模型
    QItemSelectionModel *theSelection;//鼠标选中模型
    QString aFileName; // 存放打开的文本路径
    void initilize(); // 初始化资源
    void initTableView(QStringList&aFileContent); //初始化theModel

    void initDelegate(); // 唯一的变化
    comboBoxDelegate * comboProxy;
    doubleSpinBoxDelegate * doubleSpinProxy;
    spinBoxDelegate * spinProxy;
private:
  Ui::TestDelegate *ui;
};
#endif // TESTDELEGATE_H
