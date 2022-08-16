#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QStackedWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"
class MainWindow : public QFrame // 这里修改继承框架而不是窗口
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
    QStackedWidget * stackWindow; // 用于存放3个堆叠窗口,来自3个头文件
    QPushButton * AmendBtn; // 修改
    QPushButton * CloseBtn; // 关闭
private:
    BaseInfo * baseinfo; // 基本信息堆叠窗口
    Contact * concact; // 联系方式堆叠窗口
    Detail * detail; // 显示用户详细资料堆叠窗口
    QHBoxLayout * HLayout; // 2个按钮的水平布局
    QVBoxLayout * mainLayout; // 主布局
};
#endif // MAINWINDOW_H
