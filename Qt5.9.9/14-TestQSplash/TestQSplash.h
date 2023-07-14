#ifndef TESYQSPLASH_H
#define TESYQSPLASH_H

#include <QMainWindow>
#include "FormDoc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TesyQSplash; }
QT_END_NAMESPACE

class TestQSplash : public QMainWindow
{
    Q_OBJECT
private:
    void    paintEvent(QPaintEvent *event);//绘制背景
public:
    TestQSplash(QWidget *parent = nullptr);
    ~TestQSplash();

private slots:
    // 7个工具栏的槽函数
    void on_actDoc_New_triggered();
    void on_actDoc_Open_triggered();
    void on_actFont_triggered();
    void on_actCut_triggered();
    void on_actCopy_triggered();
    void on_actPaste_triggered();
    void on_actCloseALL_triggered();
    // tabWidget切换页的槽函数
    void on_tabWidget_currentChanged(int index);
public  slots:
    // 自定义槽函数
    void  afterFileOpened(QString&aFileName); //主窗口打开文件后触发
private:
    Ui::TesyQSplash *ui;
};
#endif // TESYQSPLASH_H
