#include "mainwindow.h"
#include "communication/communication.h" //在这里避免相互包含

void MainWindow::initConnections()
{
      this->initCommunicationToMonitorConnections();
      this->initMonitorToCommunicationConnections();
      this->initToolButtonsConnections();
      this->initSettingsActConnections();
      this->initFunctionsActConnections();
      this->initAboutActConnections();
      this->initMonitorActConnections();
}

// 工具按钮的点击信号
void MainWindow::initToolButtonsConnections()
{
        // 注意clicked触发和triggered触发是不同的
        connect(SystemSettingsTbn,&QToolButton::clicked,this,&MainWindow::on_SystemSettingsTbn);
        connect(BasicSettingsTbn,&QToolButton::clicked,this,&MainWindow::on_BasicSettingsTbn);
//      connect(UserSettingsTbn,&QToolButton::clicked,this,&MainWindow::on_UserSettingsTbn);
//      connect(ProtectiveFunctionTbn,&QToolButton::clicked,this,&MainWindow::on_ProtectiveFunctionTbn);
//      connect(FunctionGeneratorTbn,&QToolButton::clicked,this,&MainWindow::on_FunctionGeneratorTbn);
        connect(CommunicationTbn,&QToolButton::clicked,this,&MainWindow::on_CommunicationTbn);
//      connect(AboutTbn,&QToolButton::clicked,this,&MainWindow::on_AboutTbn);
//      connect(OscilloscopeTbn,&QToolButton::clicked,this,&MainWindow::on_OscilloscopeTbn);
//      connect(MoreTbn,&QToolButton::clicked,this,&MainWindow::on_MoreTbn);
}

// 系统设置、基本设置和用户设置的动作触发信号
void MainWindow::initSettingsActConnections()
{
      connect(SystemSettingsAct,&QAction::triggered,this,&MainWindow::on_SystemSettingsAct);
      connect(BasicSettingsAct,&QAction::triggered,this,&MainWindow::on_BasicSettingsAct);
      connect(UserSettingsAct,&QAction::triggered,this,&MainWindow::on_UserSettingsAct);
}

// 保护、功能和通讯的动作触发信号
void MainWindow::initFunctionsActConnections()
{
      connect(ProtectiveFunctionAct,&QAction::triggered,this,&MainWindow::on_ProtectiveFunctionAct);
      connect(FunctionGeneratorAct,&QAction::triggered,this,&MainWindow::on_FunctionGeneratorAct);
      connect(CommunicationAct,&QAction::triggered,this,&MainWindow::on_CommunicationAct);
}

// about的动作触发信号
void MainWindow::initAboutActConnections()
{
      connect(AboutQtAct,&QAction::triggered,this,&MainWindow::on_AboutQtAct);
      connect(AboutHardWareAct,&QAction::triggered,this,&MainWindow::on_AboutHardWareAct);
      connect(AboutSoftWareAct,&QAction::triggered,this,&MainWindow::on_AboutSoftWareAct);
      connect(AboutENAct,&QAction::triggered,this,&MainWindow::on_AboutENAct);
      connect(AboutCNAct,&QAction::triggered,this,&MainWindow::on_AboutCNAct);
}

// 菜单栏2个动作调用监控界面和工作模式设置界面
void MainWindow::initMonitorActConnections()
{
        connect(MonitorSettingsAct,&QAction::triggered,this,&MainWindow::on_MonitorSettingsAct);
        connect(MonitorInterfaceAct,&QAction::triggered,this,&MainWindow::on_MonitorInterfaceAct);
}

//  通讯界面的信号到监控界面的槽函数(通信界面传递的固定查询数据VAPR、串口错误码、是否超时、设定查询的角色和设定是否成功)
void MainWindow::initCommunicationToMonitorConnections()
{
       connect(mainCommunication,SIGNAL(availableFixedQueryData(const QList<QByteArray>&)), // 因为mainMonitor会根据模式切换所以连接也要在cmonitoring.cpp设定
                    mainMonitor,SLOT(on_Communication_AvailableFixedQueryData(const QList<QByteArray>&)));
       connect(mainCommunication,SIGNAL(errorCode(TIMEOUTCODE)),
                    mainMonitor,SLOT(on_Communication_ErrorCode(TIMEOUTCODE)));
       connect(mainCommunication,SIGNAL(errorCode(SERIALERROR)),
                    mainMonitor,SLOT(on_Communication_ErrorCode(SERIALERROR)));
       connect(mainCommunication,SIGNAL(errorCode(bool,SETTINGVARIABLE)),
                    mainMonitor,SLOT(on_Communication_ErrorCode(bool,SETTINGVARIABLE)));
}

// 监控界面的信号到通讯界面的槽函数 传递监控界面设定的值
void MainWindow::initMonitorToCommunicationConnections()
{
      // 2+2+3+3 共10个信号,4个信号必定连接,6个信号取决于CC/CV模式来决定
      connect(mainMonitor,SIGNAL(powSourceChanged(QByteArray)),
                    mainCommunication,SLOT(on_Monitor_PowSourceChanged(QByteArray)));
      connect(mainMonitor,SIGNAL(powLoadChanged(QByteArray)),
                    mainCommunication,SLOT(on_Monitor_PowLoadChanged(QByteArray)));

      connect(mainMonitor,SIGNAL(resSourceChanged(QByteArray)),
                    mainCommunication,SLOT(on_Monitor_ResSourceChanged(QByteArray)));
      connect(mainMonitor,SIGNAL(resLoadChanged(QByteArray)),
                    mainCommunication,SLOT(on_Monitor_ResLoadChanged(QByteArray)));

      if (mWorkMode == WORKMODE::CV)
      {
            connect(mainMonitor,SIGNAL(voltChanged(QByteArray)),
                          mainCommunication,SLOT(on_Monitor_VoltChanged(QByteArray)));
            connect(mainMonitor,SIGNAL(currSourceChanged(QByteArray)),
                          mainCommunication,SLOT(on_Monitor_CurrSourceChanged(QByteArray)));
            connect(mainMonitor,SIGNAL(currLoadChanged(QByteArray)),
                          mainCommunication,SLOT(on_Monitor_CurrLoadChanged(QByteArray)));
      }
      else
      {
            connect(mainMonitor,SIGNAL(currChanged(QByteArray)),
                          mainCommunication,SLOT(on_Monitor_CurrChanged(QByteArray)));
            connect(mainMonitor,SIGNAL(voltSourceChanged(QByteArray)),
                          mainCommunication,SLOT(on_Monitor_VoltSourceChanged(QByteArray)));
            connect(mainMonitor,SIGNAL(voltLoadChanged(QByteArray)),
                          mainCommunication,SLOT(on_Monitor_VoltLoadChanged(QByteArray)));
      }

}
