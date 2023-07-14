#ifndef TESTMDI_H
#define TESTMDI_H

#include <QMainWindow>
#include <QMdiSubWindow> // MDI子窗口
#include "FormDoc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestMDI; }
QT_END_NAMESPACE

class TestMDI : public QMainWindow
{
    Q_OBJECT
private:
    void closeEvent(QCloseEvent *event); //主窗口关闭时关闭所有子窗口
public:
    TestMDI(QWidget *parent = nullptr);
    ~TestMDI();

private slots:
    // 工具栏的10个槽函数
    void on_actDoc_New_triggered();
    void on_actDoc_Open_triggered();
    void on_actViewMode_triggered(bool checked);
    void on_actCascade_triggered();
    void on_actTile_triggered();
    void on_actCloseALL_triggered();
    void on_actFont_triggered();
    void on_actCopy_triggered();
    void on_actCut_triggered();
    void on_actPaste_triggered();
    // QMdiArea的槽函数,响应窗口切换的信号
    void on_mdiArea_subWindowActivated(QMdiSubWindow *arg1);

private:
    Ui::TestMDI *ui;
};
#endif // TESTMDI_H
