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
#include <QDebug>
#include "settings/basic_settings.h"
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
protected:
      void resizeEvent(QResizeEvent * e) override;
      void contextMenuEvent(QContextMenuEvent * e) override;//右键菜单
      void paintEvent(QPaintEvent * e) override;
private: // 存储的各类信息
      BasicSettings::Settings mBasicSettings; // 基本设置窗口不是隐藏在后台的,信息需要在csetting.cpp新建窗口时获取和保存
      Monitor * mainMonitor; // 监控界面是隐藏在后台的,无需使用变量存储信息
      WORKMODE mWorkMode; // 打开监控界面需要的工作模式参数
      Communication * mainCommunication; // 通讯界面设置也是隐藏在后台的,无需使用变量存储信息
private slots: // 获取存储的各类信息需要的槽函数
      void on_MonitorSettingsOkBtn();//监控对话框的确定按钮响应槽函数
      void on_MonitorSettingsCancelBtn();//监控对话框的取消按钮响应槽函数
private: // 初始化操作
      void createToolButtons(); // 创建工具按钮
      void createToolLabels();// 创建工具提示标签
      void createLayout();// 创建布局
      void createActions(); // 创建菜单栏动作
      void createMenus(); // 创建菜单栏

private: // 初始化连接
      void initConnections();//初始化信号连接
      void initToolButtonsConnections();// ToolButton的clicked信号以及triggered信号连接
      void initSettingsActConnections();// settings菜单栏相关动作的triggered信号连接
      void initFunctionsActConnections();// functions菜单栏相关动作的triggered信号连接
      void initAboutActConnections(); // about菜单栏相关动作的triggered信号连接
      void initMonitorActConnections();//monitor菜单栏相关动作的triggered信号连接
      void initCommunicationToMonitorConnections(); // 来自mainCommunication的固定查询数据信号和mainMonitor的槽函数连接
      void initMonitorToCommunicationConnections(); // 来自mainMonitor的设定值信号和mainCommunication的槽函数连接
private: // 主界面的布局组件
      QGridLayout * mainLayout; // 主布局
      QToolButton * SystemSettingsTbn; // 系统设置
      QToolButton * BasicSettingsTbn; // 基本设置
      QToolButton * UserSettingsTbn; // 用户设置
      QToolButton * ProtectiveFunctionTbn; // 保护功能
      QToolButton * FunctionGeneratorTbn; // 函数发生器
      QToolButton * CommunicationTbn; // 通讯功能
      QToolButton * AboutTbn; // 关于功能
      QToolButton * OscilloscopeTbn; // 示波器(未来开发的功能)
      QToolButton * MoreTbn; // 更多功能(未来开发的功能)

      QLabel * SystemSettingsLabel;
      QLabel * BasicSettingsLabel;
      QLabel * UserSettingsLabel;
      QLabel * ProtectiveFunctionLabel;
      QLabel * FunctionGeneratorLabel;
      QLabel * CommunicationLabel;
      QLabel * AboutLabel;
      QLabel * OscilloscopeLabel;
      QLabel * MoreLabel;

      QMenuBar * MenuBar;
      QMenu * MenuSettings;// 设置菜单
      QAction * SystemSettingsAct;
      QAction * BasicSettingsAct;
      QAction * UserSettingsAct;

      QMenu * MenuFunctions;//功能菜单
      QAction * ProtectiveFunctionAct;
      QAction * FunctionGeneratorAct;
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

private: //ToolButton的响应
      void on_SystemSettingsTbn();
      void on_BasicSettingsTbn();
//      void on_UserSettingsTbn();
//      void on_ProtectiveFunctionTbn();
//      void on_FunctionGeneratorTbn();
      void on_CommunicationTbn();
//      void on_AboutTbn();
//      void on_OscilloscopeTbn();
//      void on_MoreTbn();
private://所有动作的响应
      void on_SystemSettingsAct();
      void on_BasicSettingsAct();
      void on_UserSettingsAct();
      void on_ProtectiveFunctionAct();
      void on_FunctionGeneratorAct();
      void on_CommunicationAct();
      void on_AboutHardWareAct();
      void on_AboutSoftWareAct();
      void on_AboutQtAct();
      void on_AboutCNAct();
      void on_AboutENAct();
      void on_MonitorSettingsAct();
      void on_MonitorInterfaceAct();
};
#endif // MAINWINDOW_H
