#include "mainwindow.h"

void MainWindow::initConnections()
{
      this->initToolButtonsConnections();
      this->initSettingsActConnections();
      this->initFunctionsActConnections();
      this->initAboutActConnections();
}

void MainWindow::initToolButtonsConnections()
{
        // 注意clicked触发和triggered触发是不同的
        connect(SystemSettingsTbn,&QToolButton::clicked,this,&MainWindow::on_SystemSettingsTbn);
        connect(BasicSettingsTbn,&QToolButton::clicked,this,&MainWindow::on_BasicSettingsTbn);
//      connect(UserSettingsTbn,&QToolButton::triggered,this,&MainWindow::on_UserSettingsTbn);
//      connect(ProtectiveFunctionTbn,&QToolButton::triggered,this,&MainWindow::on_ProtectiveFunctionTbn);
//      connect(FunctionGeneratorTbn,&QToolButton::triggered,this,&MainWindow::on_FunctionGeneratorTbn);
//      connect(CommunicationTbn,&QToolButton::triggered,this,&MainWindow::on_CommunicationTbn);
//      connect(AboutTbn,&QToolButton::triggered,this,&MainWindow::on_AboutTbn);
//      connect(OscilloscopeTbn,&QToolButton::triggered,this,&MainWindow::on_OscilloscopeTbn);
//      connect(MoreTbn,&QToolButton::triggered,this,&MainWindow::on_MoreTbn);
}

void MainWindow::initSettingsActConnections()
{
      connect(SystemSettingsAct,&QAction::triggered,this,&MainWindow::on_SystemSettingsAct);
      connect(BasicSettingsAct,&QAction::triggered,this,&MainWindow::on_BasicSettingsAct);
      connect(UserSettingsAct,&QAction::triggered,this,&MainWindow::on_UserSettingsAct);
}

void MainWindow::initFunctionsActConnections()
{
      connect(ProtectiveFunctionAct,&QAction::triggered,this,&MainWindow::on_ProtectiveFunctionAct);
      connect(FunctionGeneratorAct,&QAction::triggered,this,&MainWindow::on_FunctionGeneratorAct);
      connect(CommunicationAct,&QAction::triggered,this,&MainWindow::on_CommunicationAct);
}

void MainWindow::initAboutActConnections()
{
      connect(AboutQtAct,&QAction::triggered,this,&MainWindow::on_AboutQtAct);
      connect(AboutHardWareAct,&QAction::triggered,this,&MainWindow::on_AboutHardWareAct);
      connect(AboutSoftWareAct,&QAction::triggered,this,&MainWindow::on_AboutSoftWareAct);
      connect(AboutENAct,&QAction::triggered,this,&MainWindow::on_AboutENAct);
      connect(AboutCNAct,&QAction::triggered,this,&MainWindow::on_AboutCNAct);
}

