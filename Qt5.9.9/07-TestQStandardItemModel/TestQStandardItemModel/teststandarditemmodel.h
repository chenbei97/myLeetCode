/*
 * @Author: chenbei
 * @Date: 2022-07-02 23:04:38
 * @LastEditTime: 2022-07-03 11:59:30
 * @FilePath: \\myLeetCode\\Qt5.9.9\\07-TestQStandardItemModel\\TestQStandardItemModel\\teststandarditemmodel.h
 * @Description: teststandarditemmodel.h
 * @Signature: A boy without dreams
 */
#ifndef TESTSTANDARDITEMMODEL_H
#define TESTSTANDARDITEMMODEL_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#define     FixedColumnCount    6       //test.txt只有6列
QT_BEGIN_NAMESPACE
namespace Ui { class TestStandardItemModel; }
QT_END_NAMESPACE

class TestStandardItemModel : public QMainWindow
{
    Q_OBJECT

public:
    TestStandardItemModel(QWidget *parent = nullptr);
    ~TestStandardItemModel();

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
private:
    Ui::TestStandardItemModel *ui;
};
#endif // TESTSTANDARDITEMMODEL_H
