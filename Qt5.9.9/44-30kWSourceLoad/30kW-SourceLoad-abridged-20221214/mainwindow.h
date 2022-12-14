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
#include <QTranslator>
#include <QSettings>
#include <QDebug>
#include <setting/setting.h>
#include <setting/workmodedialog.h>
#include <monitor/monitor.h>

class Communication; // communication.h包含了mainwindow.h,为了避免相互包含故这里只能是声明
class MainWindow : public QDialog
{
      Q_OBJECT
public:
      explicit MainWindow(QWidget *parent = Q_NULLPTR,LANUAGE  lan = LANUAGE ::CN);
      void openMonitor();// 打开监控界面,提供给外部使用
      void closeMonitor(); // 隐藏监控界面,提供给外部使用
      WORKMODE mWorkMode; // 打开监控界面需要的工作模式参数
      LANUAGE  mLanuage; // 主窗口需要的参数
private: // 存储的各类信息
      Monitor * mainMonitor; // 监控界面
      Communication * mainCommunication; // 通讯界面
      Setting * mainSettings; // 设置界面
      WorkModeDialog * mainWorkMode; // 工作模式设置界面
      void createToolButtons(); // 创建工具按钮
      void createLayout();// 创建布局
      void createActions(); // 创建菜单栏动作
      void createMenus(); // 创建菜单栏
      void resizeEvent(QResizeEvent * e) override;
      void contextMenuEvent(QContextMenuEvent * e) override;//右键菜单
      void paintEvent(QPaintEvent * e) override;
      void initConnections();//初始化信号连接
      void changeLanguage(LANUAGE  lan);
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
      QAction * WorkModeAct;// 工作模式设置
      QAction * MonitorInterfaceAct; // 监控界面
};
#endif // MAINWINDOW_H
