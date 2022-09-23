#include "mainwindow.h"

void MainWindow::on_SystemSettingsTbn()
{
    SystemSettingsAct->trigger(); //事先不关联动作,使用手动的方式触发动作
}

void MainWindow::on_BasicSettingsTbn()
{
    BasicSettingsAct->trigger();//事先不关联动作,使用手动的方式触发动作
}

//void MainWindow::on_UserSettingsTbn()
//{
//    qDebug()<<"user";
//}

//void MainWindow::on_ProtectiveFunctionTbn()
//{

//}

//void MainWindow::on_FunctionGeneratorTbn()
//{

//}

void MainWindow::on_CommunicationTbn()
{
    CommunicationAct->trigger();//事先不关联动作,使用手动的方式触发动作
}

//void MainWindow::on_AboutTbn()
//{

//}

//void MainWindow::on_OscilloscopeTbn()
//{

//}

//void MainWindow::on_MoreTbn()
//{

//}
