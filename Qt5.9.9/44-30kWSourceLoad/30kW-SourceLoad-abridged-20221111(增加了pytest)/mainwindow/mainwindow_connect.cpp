#include <mainwindow.h>
#include <communication/communication.h> //头文件在这里而不是在mainwindow.h中是避免相互包含
extern QTranslator * translator;

void MainWindow::initConnections()
{
    // 工具按钮的点击信号 => 注意clicked触发和triggered触发是不同的
    connect(BasicSettingsTbn,&QToolButton::clicked,this,[=]{BasicSettingsAct->trigger();}); // 工具按钮的代执行函数
    connect(CommunicationTbn,&QToolButton::clicked,this,[=]{CommunicationAct->trigger();});

    // 菜单栏的基本设置、通讯、关于和监控界面的动作触发信号
    connect(MonitorSettingsAct,&QAction::triggered,this,&MainWindow::on_MonitorSettingsAct);
    connect(MonitorInterfaceAct,&QAction::triggered,this,&MainWindow::on_MonitorInterfaceAct);
    connect(CommunicationAct,&QAction::triggered,this,[=]{mainCommunication->showNormal();});
    connect(BasicSettingsAct,&QAction::triggered,this,[=]{

    });
    connect(AboutQtAct,&QAction::triggered,this,[=]{QMessageBox::aboutQt(this,tr("关于Qt"));});
    connect(AboutHardWareAct,&QAction::triggered,this,[=]{

    });
    connect(AboutSoftWareAct,&QAction::triggered,this,[=]{

    });
    connect(AboutENAct,&QAction::triggered,this,[=]{changeLanguage(Lanuage::EN);});
    connect(AboutCNAct,&QAction::triggered,this,[=]{changeLanguage(Lanuage::CN);});


    // 通讯界面的信号到监控界面的槽函数(通信界面传递的固定查询数据VAPR、串口错误码、是否超时、设定查询的角色和设定是否成功)
    // 通讯数据信号 => 监控槽函数
     connect(mainCommunication,&Communication::fixedQueryData, mainMonitor,&Monitor::showMeasureState);
     connect(mainCommunication,&Communication::setQueryData,mainMonitor,&Monitor::showSetState);
     // 通讯错误码信号 => 监控槽函数
     connect(mainCommunication,static_cast<void (Communication::*)(TIMEOUTCODE)>(&Communication::errorCode),
                  mainMonitor,&Monitor::setMessageState);
     connect(mainCommunication,static_cast<void (Communication::*)(SERIALERROR)>(&Communication::errorCode),
                  mainMonitor,static_cast<void (Monitor::*)(SERIALERROR)>(&Monitor::setConnectState));
     connect(mainCommunication,static_cast<void (Communication::*)(TCPERRORSTATE)>(&Communication::errorCode),
                  mainMonitor,static_cast<void (Monitor::*)(TCPERRORSTATE)>(&Monitor::setConnectState));
   // 监控信号 => 通讯信号
   connect(mainMonitor,&Monitor::setRoleValue,mainCommunication,&Communication::getRoleValue); // 电压电流电阻功率的spinbox设置信号
}

// 切换语言
void MainWindow::changeLanguage(Lanuage lan)
{
     QString a = (lan == Lanuage::CN ? "cn":"en");
     QString path = QStringLiteral(":/%1.qm").arg(a);

     qApp->removeTranslator(translator);
     delete translator;
     translator=new QTranslator;
     translator->load(path);
     qApp->installTranslator(translator);
     QSettings settings("WWB-Qt",QCoreApplication::applicationName()); //注册组织和应用程序
     settings.setValue("language",a);

     qApp->exit(773); // 重启程序,773是约定的退出指令,main.cpp会收到他并重启
}
