#include <mainwindow.h>
#include <communication/communication.h> //头文件在这里而不是在mainwindow.h中是避免相互包含
extern QTranslator * translator;

void MainWindow::initConnections()
{
    // 工具按钮的点击信号 => 注意clicked触发和triggered触发是不同的
    // "设置"和"通讯"按钮触发得到1个界面,而"关于"按钮是菜单弹出模式,所以无需设置clicked信号的连接,act已经代执行
    connect(BasicSettingsTbn,&QToolButton::clicked,this,[=]{BasicSettingsAct->trigger();});
    connect(CommunicationTbn,&QToolButton::clicked,this,[=]{CommunicationAct->trigger();});

    // 工作模式设置
    connect(WorkModeAct,&QAction::triggered,this,[=]{
        int ret = mainWorkMode->exec();
        if (ret == QDialog::Accepted)// 如果点击的是确定按钮
        {
             bool checked = mainWorkMode->isCVMode; // 工作模式点击确定后isCVMode更新过可以用
             mWorkMode = checked?WORKMODE::CV: WORKMODE::CC; // 更新模式
        }
        // 如果是取消按钮,保持原有的状态即可
    });
    // 监控界面依据工作模式启动
    connect(MonitorInterfaceAct,&QAction::triggered,this,[=]{openMonitor();});
    connect(mainMonitor,&Monitor::workModeEnable,this,[=]{WorkModeAct->setEnabled(true);}); // 关闭监控时恢复使能
    // 通讯、基本设置、关于界面的启动
    connect(CommunicationAct,&QAction::triggered,this,[=]{mainCommunication->showNormal();});
    connect(BasicSettingsAct,&QAction::triggered,this,[=]{mainSettings->showNormal();});
    connect(AboutQtAct,&QAction::triggered,this,[=]{QMessageBox::aboutQt(this,tr("关于Qt"));});
    connect(AboutHardWareAct,&QAction::triggered,this,[=]{

    });
    connect(AboutSoftWareAct,&QAction::triggered,this,[=]{

    });
    connect(AboutENAct,&QAction::triggered,this,[=]{changeLanguage(LANUAGE ::EN);});
    connect(AboutCNAct,&QAction::triggered,this,[=]{changeLanguage(LANUAGE ::CN);});


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
    // 工作模式设置信号 => 基本设置 => 表格 => 表格设置
   connect(mainWorkMode,&WorkModeDialog::workModeChanged,mainSettings,&Setting::workModeChanged);
   // 日志周期 => 表格设置 => 表格 => 基本设置 =>通讯
   connect(mainSettings,&Setting::selectedPeriod,mainCommunication,&Communication::selectedPeriod);
   // 通讯截取的日志数据 => 基本设置 => 表格
   connect(mainCommunication,&Communication::log,mainSettings,&Setting::log);
}

// 切换语言
void MainWindow::changeLanguage(LANUAGE  lan)
{
     QString a = (lan == LANUAGE ::CN ? "cn":"en");
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
