#ifndef TESTQFILESYSTEMMODEL_H
#define TESTQFILESYSTEMMODEL_H

#include <QMainWindow>
#include    <QFileSystemModel> // 文件系统数据模型需要包含的头文件
QT_BEGIN_NAMESPACE
namespace Ui { class TestQFileSystemModel; }
QT_END_NAMESPACE

class TestQFileSystemModel : public QMainWindow
{
    Q_OBJECT

public:
    TestQFileSystemModel(QWidget *parent = nullptr);
    ~TestQFileSystemModel();
private slots:
    void treeView_slotFunction(const QModelIndex &index); // treeViewd的自定义槽函数,如果想带参数,需要在这里声明为slot函数
    void on_treeView_clicked(const QModelIndex &index); // 或者直接使用转到槽函数

private:
    void initialize(); // 初始化操作

    Ui::TestQFileSystemModel *ui;
    QFileSystemModel    *fileModel; // 定义文件数据模型
};
#endif // TESTQFILESYSTEMMODEL_H
