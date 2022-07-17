#ifndef TESTDATASTREAM_H
#define TESTDATASTREAM_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "comboboxdelegate.h"
#include "doubleSpinBoxDelegate.h"
#include "spinBoxDelegate.h"
#define     FixedColumnCount    6       //文件固定6行

QT_BEGIN_NAMESPACE
namespace Ui { class TestDataStream; }
QT_END_NAMESPACE

class TestDataStream : public QMainWindow
{
    Q_OBJECT

public:
    TestDataStream(QWidget *parent = nullptr);
    ~TestDataStream();
private:
    QLabel  *LabCellPos;    //当前单元格行列号(状态栏显示)
    QLabel  *LabCellText;   //当前单元格内容(状态栏显示)
    QStandardItemModel  *theModel;// tableView的数据模型
    QItemSelectionModel *theSelection;//tableView的项选择模型
    comboBoxDelegate * comboProxy; // 下拉列表代理类
    spinBoxDelegate * spinBoxProxy; // 整型数下拉代理类
    doubleSpinBoxDelegate * doubleSpinBoxProxy; // 浮点数下拉代理类
private:
     void  initialize_proxy();
     void  initialize_model();
     void  initialize_qlabel();
     void  initialize_toolbar_enable(bool enable);
private slots:
    void on_actOpen_triggered(); // 打开stm文件
    void on_actSave_triggered(); // 保存stm文件
    void on_actOpenBin_triggered(); // 打开dat文件
    void on_actSaveBin_triggered();// 保存dat文件
    void on_actOpenTxt_triggered();// 打开txt文件
    void on_actSaveTxt_triggered(); // 保存txt文件

    void on_actTabReset_triggered();  // 表格复位
    void on_actAppend_triggered(); // 添加行
    void on_actInsert_triggered(); // 插入行
    void on_actDelete_triggered(); // 删除行

    void on_actModelData_triggered(); // 模型数据文本框显示
    void on_actAlignLeft_triggered(); // 居左
    void on_actAlignCenter_triggered();// 居中
    void on_actAlignRight_triggered();// 居右
    void on_actFontBold_triggered(bool checked);// 加粗

    void on_currentItemChanged(const QModelIndex &current, const QModelIndex &previous);
private:
        bool saveDatFile(QString & aFileName); // 保存dat文件实际调用的函数
        bool openDatFile(QString & aFileName); // 打开dat文件实际调用的函数
        bool saveStmFile(QString & aFileName); // 保存stm文件实际调用的函数
        bool openStmFile(QString & aFileName); // 打开stm文件实际调用的函数
        void resetTable(int rowCount);// 表格复位实际调用的函数,同时还在打开dat文件和打开stm文件中调用
private:
    Ui::TestDataStream *ui;
};
#endif // TESTDATASTREAM_H
