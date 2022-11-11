#include <mainwindow.h>

void MainWindow::createToolButtons()
{
      BasicSettingsTbn = new QToolButton; // 基本设置
      CommunicationTbn = new QToolButton; // 通讯功能
      AboutTbn = new QToolButton;// 关于功能

       // 使用clicked信号触发动作,就不添加默认动作了,这样点击ToolButton时不会弹出菜单
      //BasicSettingsTbn->addAction(BasicSettingsAct);
      //CommunicationTbn->addAction(CommunicationAct);
      AboutTbn->addAction(AboutHardWareAct); // 5个动作同时包含
      AboutTbn->addAction(AboutSoftWareAct);
      AboutTbn->addAction(AboutQtAct);
      AboutTbn->addAction(AboutCNAct);
      AboutTbn->addAction(AboutENAct);

      //BasicSettingsTbn->setPopupMode(QToolButton::InstantPopup);
      //CommunicationTbn->setPopupMode(QToolButton::InstantPopup);
      AboutTbn->setPopupMode(QToolButton::InstantPopup); //只有关于ToolButton设置了多个下拉菜单

      // 使用clicked触发信号的QToolButton去除掉右下角的小三角样式
      BasicSettingsTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");
      CommunicationTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");

      BasicSettingsTbn->setAutoRaise(true);
      CommunicationTbn->setAutoRaise(true);
      AboutTbn->setAutoRaise(true);

      QString pathPrefix = QStringLiteral(":/images/");
      QString pathSuffix = QStringLiteral(".png");
      BasicSettingsTbn->setIcon(QIcon(pathPrefix+QStringLiteral("basicSettings")+pathSuffix));
      CommunicationTbn->setIcon(QIcon(pathPrefix+QStringLiteral("communication")+pathSuffix));
      AboutTbn->setIcon(QIcon(pathPrefix+QStringLiteral("about")+pathSuffix));

      BasicSettingsTbn->setIconSize(QSize(64,64));
      CommunicationTbn->setIconSize(QSize(64,64));
      AboutTbn->setIconSize(QSize(64,64));
}

void MainWindow::createLayout()
{
      mainLayout = new QGridLayout;

      mainLayout->addWidget(BasicSettingsTbn,0,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(CommunicationTbn,0,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(AboutTbn,0,2,1,1,Qt::AlignCenter);

      mainLayout->setMargin(5);
      mainLayout->setSpacing(5);
      this->setLayout(mainLayout);
}

void MainWindow::createActions()
{
      BasicSettingsAct = new QAction(tr("基本设置"));
      CommunicationAct = new QAction(tr("通讯"));
      AboutHardWareAct = new QAction(tr("硬件"));
      AboutSoftWareAct = new QAction(tr("软件"));
      AboutQtAct = new QAction(tr("qt"));
      AboutCNAct = new QAction(tr("中文"));
      AboutENAct = new QAction(tr("英文"));
      MonitorInterfaceAct = new QAction(tr("监控界面"));
      MonitorSettingsAct = new QAction(tr("电源模式"));

      BasicSettingsAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_1));
      CommunicationAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_2));
      AboutHardWareAct->setShortcut(QKeySequence(Qt::CTRL+Qt::SHIFT+Qt::Key_H));
      AboutSoftWareAct->setShortcut(QKeySequence(Qt::CTRL+Qt::SHIFT+Qt::Key_S));
      AboutQtAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_Q));
      AboutCNAct->setShortcut(QKeySequence(Qt::SHIFT+Qt::Key_C));
      AboutENAct->setShortcut(QKeySequence(Qt::SHIFT+Qt::Key_E));
      MonitorSettingsAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_M));
      MonitorInterfaceAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_N));


      QString pathPrefix = QStringLiteral(":/images/");
      QString pathSuffix = QStringLiteral(".png");
      BasicSettingsAct->setIcon(QIcon(pathPrefix+QStringLiteral("basicSettings")+pathSuffix));
      CommunicationAct->setIcon(QIcon(pathPrefix+QStringLiteral("communication")+pathSuffix));
      AboutHardWareAct->setIcon(QIcon(pathPrefix+QStringLiteral("aboutHardware")+pathSuffix));
      AboutSoftWareAct->setIcon(QIcon(pathPrefix+QStringLiteral("aboutSoftware")+pathSuffix));
      AboutQtAct->setIcon(QIcon(pathPrefix+QStringLiteral("aboutQt")+pathSuffix));
      //AboutCNAct->setIcon(QIcon(pathPrefix+QStringLiteral("CN")+pathSuffix)); // 加图标的话就看不到互斥动作标记了
      //AboutENAct->setIcon(QIcon(pathPrefix+QStringLiteral("EN")+pathSuffix));
      MonitorSettingsAct->setIcon(QIcon(pathPrefix+QStringLiteral("monitorSettings")+pathSuffix));
      MonitorInterfaceAct->setIcon(QIcon(pathPrefix+QStringLiteral("monitorInterface")+pathSuffix));
}

void MainWindow::createMenus()
{
        MenuBar = new QMenuBar(this);
        MenuBar->setGeometry(QRect(0,0,this->width(),30));
        //MenuBar->setStatusTip(tr("菜单栏"));
        MenuBar->setToolTip(tr("菜单栏"));
        MenuBar->setMouseTracking(true);
        MenuBar->setToolTipDuration(1000);

        MenuSettings = new QMenu(tr("设置"));
        MenuAbout = new QMenu(tr("关于"));
        MenuLanguage = new QMenu(tr("语言"));
        MenuMonitor = new QMenu(tr("监控"));
        MenuLanguage->setIcon(QIcon(":/images/aboutLanguage.png"));

        MenuSettings->addAction(BasicSettingsAct);
        MenuSettings->addAction(CommunicationAct);
        MenuSettings->addMenu(MenuLanguage);//设置菜单添加语言菜单

        QActionGroup * LanguageGroup = new QActionGroup(this);
        AboutCNAct->setCheckable(true); // 默认是false先设为true
        AboutENAct->setCheckable(true);
//        LanguageGroup->addAction(AboutCNAct);
//        LanguageGroup->addAction(AboutENAct);
//        MenuLanguage->addAction(AboutCNAct);
//        MenuLanguage->addAction(AboutENAct);
        MenuLanguage->addAction(LanguageGroup->addAction(AboutCNAct)); //直接这样更简洁
        MenuLanguage->addAction(LanguageGroup->addAction(AboutENAct));
        AboutCNAct->setChecked(mLanuage==Lanuage::CN); // 应用启动可能是英文界面,让checked的状态跟随
        AboutENAct->setChecked(mLanuage==Lanuage::EN);

        MenuAbout->addAction(AboutHardWareAct);
        MenuAbout->addSeparator();
        MenuAbout->addAction(AboutSoftWareAct);
        MenuAbout->addSeparator();
        MenuAbout->addAction(AboutQtAct);

        MenuMonitor->addAction(MonitorSettingsAct);
        MenuMonitor->addSeparator();
        MenuMonitor->addAction(MonitorInterfaceAct);

        MenuBar->addMenu(MenuSettings);
        MenuBar->addSeparator();
        MenuBar->addMenu(MenuAbout);
        MenuBar->addSeparator();
        MenuBar->addMenu(MenuMonitor);
}
