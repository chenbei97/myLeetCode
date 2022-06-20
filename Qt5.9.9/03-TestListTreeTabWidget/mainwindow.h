#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actListIni_triggered(); // 列表初始化toolBar
    void on_actionlistInit_triggered();// 列表初始化menuBar

    void on_actListClear_triggered(); // 列表清除toolBar
    void on_actionListClear_triggered();// 列表清除menuBar

    void on_actListInsert_triggered();// 插入项toolBar
    void on_actionListInsert_triggered();// 插入项menuBar

    void on_actListAppend_triggered(); // 添加项toolBar
    void on_actionListAppend_triggered();// 添加项menuBar

    void on_actListDelete_triggered();// 删除项toolBar
    void on_actionListDelete_triggered();// 删除项menuBar

    void on_actSelALL_triggered(); // 全选
    void on_actSelNone_triggered(); // 全不选
    void on_actSelInvs_triggered(); // 反选
    void on_actSelPopMenu_triggered(); // 弹出菜单的默认选项

    void on_actQuit_triggered(); // 关闭窗口 toolBar
    void on_actionClose_triggered(); // 关闭窗口 menuBar
    void on_actionReboot_triggered(); // 重启 menuBar

    void on_actioninitText_triggered(); // 初始化文本 menuBar
    void on_actionclearText_triggered(); // 清除文本 menuBar
    void on_actionsaveText_triggered(); // 保存文本 menuBar

    void on_toolBox_currentChanged(int index); // toolBox的联动槽函数
    void on_listWidget_customContextMenuRequested(const QPoint &pos); // listWidget的右键快捷菜单槽函数
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous); //  listWidget当前项槽函数
    void on_chkBoxListEditable_clicked(); // 可编辑的checkbox复选框擦函数
    void on_btnclose_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_btnRecoveryDate_clicked();

    void on_dial_sliderMoved(int position);

private:
    void    initialize(); // 初始化函数
    void    setAllActionsForToolButtons(); // 初始化QAction和QToolButton的联系
    void    setTwoDynamicToolButtonForToolBar(); // 动态创建2个QToolButton
    void    setPopMenuForBtnSelectItem(); // 设置动态弹出式菜单
    void    actListIniCommon();  // 公共函数用于节省重复代码 - 列表初始化
    void    actListInsertCommon();// 公共函数用于节省重复代码 - 列表插入项
    void    actListAppendCommon();// 公共函数用于节省重复代码 - 列表添加项
    void    actListDeleteCommon();// 公共函数用于节省重复代码 - 列表删除当前项
    bool   openFileDialog(); // 用于保存文件打开的窗口
private:
    Ui::MainWindow *ui;
    QString filePath;
};
#endif // MAINWINDOW_H
