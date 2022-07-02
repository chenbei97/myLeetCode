#ifndef TESTSTRINGLISTMODEL_H
#define TESTSTRINGLISTMODEL_H

#include <QMainWindow>
#include <QStringListModel>
QT_BEGIN_NAMESPACE
namespace Ui { class TestStringListModel; }
QT_END_NAMESPACE

class TestStringListModel : public QMainWindow
{
    Q_OBJECT

public:
    TestStringListModel(QWidget *parent = nullptr);
    ~TestStringListModel();

private:
    void initilize();
    void displayModelIndex();//显示项索引
private slots:
    void on_btnIniList_clicked(); // 初始化列表
    void on_btnListAppend_clicked(); // 追加项
    void on_btnListInsert_clicked(); //插入项
    void on_btnListDelete_clicked();//删除项
    void on_btnListClear_clicked();//清除列表
    void on_btnTextClear_clicked();//清除文本
    void on_btnTextImport_clicked();//显示文本
    void on_listView_clicked(const QModelIndex &index); //显示项索引

private:
    Ui::TestStringListModel *ui;
    QStringListModel   *viewModel; //数据模型是字符串列表模型
};
#endif // TESTSTRINGLISTMODEL_H
