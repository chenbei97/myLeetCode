#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QFont>
#include <QFontDatabase>
#include <QSignalMapper>
#include <QDebug>
#include <QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include "mytextedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

public:
        explicit MainWindow(QWidget *parent = Q_NULLPTR);
private:
         void setFileMenuActEnabled(bool enabled); // 设置文件菜单动作使能
         //void setEditMenuActEnabled(bool enabled); // 设置编辑菜单动作使能
         void setFormatMenuActEnabled(bool enabled); // 设置格式菜单动作使能
         void setWindowMenuActEnabled(bool enabled); // 设置窗口菜单动作使能
         MyTextEdit * activateTextWindow(); // 获取当前mdi区域的活动窗口
         void addSubWindowActForWindowMenu(); // 窗口菜单添加子窗口动作按钮,不同动作对应不同的已有窗口
         QMdiSubWindow *findChildWnd(const QString &docName);//根据名称查找文档窗口
private: // 初始化信号槽连接和UI组件
        void init_connections();
        void init_ui();
private slots: // 菜单栏的动作槽函数
        void on_actNew_triggered();
        void on_actOpen_triggered();
        void on_actSave_triggered();
        void on_actSaveAs_triggered();
        void on_actPrint_triggered();
        void on_actPrintPreview_triggered();
        void on_actUndo_triggered();
        void on_actRedo_triggered();
        void on_actCut_triggered();
        void on_actCopy_triggered();
        void on_actPaste_triggered();
        void on_actBold_triggered();
        void on_actItalic_triggered();
        void on_actUnderline_triggered();
        void on_actLeft_triggered();
        void on_actCenter_triggered();
        void on_actRight_triggered();
        void on_actJusitify_triggered();
        void on_actColor_triggered();
        void on_actClose_triggered();
        void on_actCloseAll_triggered();
        void on_actTile_triggered();
        void on_actCascade_triggered();
        void on_actNext_triggered();
        void on_actPrevious_triggered();
        void on_action_triggered();
        void on_action_Qt_triggered();
private:
        Ui::MainWindow *ui;
        QSignalMapper * mSignalMapper; // 信号映射器
};
#endif // MAINWINDOW_H
