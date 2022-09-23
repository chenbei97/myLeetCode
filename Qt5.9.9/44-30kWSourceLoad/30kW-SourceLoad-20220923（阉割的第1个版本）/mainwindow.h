#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QToolButton>
#include <QGridLayout>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QContextMenuEvent>
#include <QPainter>
#include <QDialog>
#include <QRadioButton>
#include <QMessageBox>
#include <QActionGroup>
#include <QDebug>
#include "monitor/monitor.h"
//#include "communication/communication.h"
#include "core/enum.h"
class Communication; // communication.h包含了mainwindow.h,故这里只能是声明
class MainWindow : public QDialog
{
      Q_OBJECT
public:
      explicit MainWindow(QWidget *parent = nullptr);
      void openMonitor();// 打开监控界面,提供给外部使用
      void closeMonitor(); // 隐藏监控界面,提供给外部使用
private: // 存储的各类信息
      Monitor * mainMonitor; // 监控界面是隐藏在后台的,无需使用变量存储信息
      WORKMODE mWorkMode; // 打开监控界面需要的工作模式参数
      Communication * mainCommunication; // 通讯界面设置也是隐藏在后台的,无需使用变量存储信息
private: // 初始化操作
      void createToolButtons(); // 创建工具按钮
      void createLayout();// 创建布局
      void createActions(); // 创建菜单栏动作
      void createMenus(); // 创建菜单栏
      void resizeEvent(QResizeEvent * e) override;
      void contextMenuEvent(QContextMenuEvent * e) override;//右键菜单
      void paintEvent(QPaintEvent * e) override;
      void initConnections();//初始化信号连接
      void initToolButtonsConnections();// ToolButton的clicked信号以及triggered信号连接
      void initMenuActConnections();// settings菜单栏相关动作的triggered信号连接
      void initCommunicationMonitorConnections(); // 监控设置信号=>通讯信号,通讯回复数据信号=>监控界面槽函数
private: // 主界面的布局组件
      QGridLayout * mainLayout; // 主布局
      QToolButton * BasicSettingsTbn; // 基本设置
      QToolButton * CommunicationTbn; // 通讯功能
      QToolButton * AboutTbn; // 关于功能

      QMenuBar * MenuBar;
      QMenu * MenuSettings;// 设置菜单
      QAction * BasicSettingsAct;
      QAction * CommunicationAct;
      QMenu * MenuAbout;//关于菜单
      QAction * AboutHardWareAct; // 关于硬件
      QAction * AboutSoftWareAct; // 关于软件
      QAction * AboutQtAct; // 关于Qt版本
      QMenu * MenuLanguage; // 切换语言
      QAction * AboutCNAct; // 中文
      QAction * AboutENAct; // 英文

      QMenu * MenuMonitor; // 监控菜单
      QAction * MonitorSettingsAct;// 监控模式设置
      QAction * MonitorInterfaceAct; // 监控主界面
private:
      //所有动作的响应
      void on_MonitorSettingsAct();
      void on_MonitorInterfaceAct();
};
#endif // MAINWINDOW_H
