#include "mainwindow.h"

void MainWindow::createToolButtons()
{
      SystemSettingsTbn = new QToolButton; // 系统设置
      BasicSettingsTbn = new QToolButton; // 基本设置
      UserSettingsTbn = new QToolButton; // 用户设置
      ProtectiveFunctionTbn = new QToolButton; // 保护功能
      FunctionGeneratorTbn = new QToolButton; // 函数发生器
      CommunicationTbn = new QToolButton; // 通讯功能
      AboutTbn = new QToolButton;// 关于功能
      OscilloscopeTbn = new QToolButton; // 示波器(未来开发的功能)
      MoreTbn = new QToolButton; // 更多功能(未来开发的功能)

       // 使用clicked信号触发动作,就不添加默认动作了,这样点击ToolButton时不会弹出菜单
      //SystemSettingsTbn->addAction(SystemSettingsAct);
      //BasicSettingsTbn->addAction(BasicSettingsAct);
      //UserSettingsTbn->addAction(UserSettingsAct);
      //ProtectiveFunctionTbn->addAction(ProtectiveFunctionAct);
      //FunctionGeneratorTbn->addAction(FunctionGeneratorAct);
      //CommunicationTbn->addAction(CommunicationAct);
      AboutTbn->addAction(AboutHardWareAct); // 5个动作同时包含
      AboutTbn->addAction(AboutSoftWareAct);
      AboutTbn->addAction(AboutQtAct);
      AboutTbn->addAction(AboutCNAct);
      AboutTbn->addAction(AboutENAct);

      //SystemSettingsTbn->setPopupMode(QToolButton::InstantPopup); //既然没有菜单设不设置都可以
      //BasicSettingsTbn->setPopupMode(QToolButton::InstantPopup);
      //UserSettingsTbn->setPopupMode(QToolButton::InstantPopup);
      //ProtectiveFunctionTbn->setPopupMode(QToolButton::InstantPopup);
      //FunctionGeneratorTbn->setPopupMode(QToolButton::InstantPopup);
      //CommunicationTbn->setPopupMode(QToolButton::InstantPopup);
      AboutTbn->setPopupMode(QToolButton::InstantPopup); //只有关于ToolButton设置了多个下拉菜单
      //OscilloscopeTbn->setPopupMode(QToolButton::InstantPopup);
      //MoreTbn->setPopupMode(QToolButton::InstantPopup);

      // 使用clicked触发信号的QToolButton去除掉右下角的小三角样式
      SystemSettingsTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");
      BasicSettingsTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");
      CommunicationTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");
      ProtectiveFunctionTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");
      FunctionGeneratorTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");
      CommunicationTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");
      OscilloscopeTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");
      MoreTbn->setStyleSheet("QToolButton::menu-indicator{image:none;}");

      SystemSettingsTbn->setAutoRaise(true);
      BasicSettingsTbn->setAutoRaise(true);
      UserSettingsTbn->setAutoRaise(true);
      ProtectiveFunctionTbn->setAutoRaise(true);
      FunctionGeneratorTbn->setAutoRaise(true);
      CommunicationTbn->setAutoRaise(true);
      AboutTbn->setAutoRaise(true);
      OscilloscopeTbn->setAutoRaise(true);
      MoreTbn->setAutoRaise(true);

      QString pathPrefix = QStringLiteral(":/images/");
      QString pathSuffix = QStringLiteral(".png");
      SystemSettingsTbn->setIcon(QIcon(pathPrefix+QStringLiteral("systemSettings")+pathSuffix));
      BasicSettingsTbn->setIcon(QIcon(pathPrefix+QStringLiteral("basicSettings")+pathSuffix));
      UserSettingsTbn->setIcon(QIcon(pathPrefix+QStringLiteral("userSettings")+pathSuffix));
      ProtectiveFunctionTbn->setIcon(QIcon(pathPrefix+QStringLiteral("protectiveFunction")+pathSuffix));
      FunctionGeneratorTbn->setIcon(QIcon(pathPrefix+QStringLiteral("functionGenerator")+pathSuffix));
      CommunicationTbn->setIcon(QIcon(pathPrefix+QStringLiteral("communication")+pathSuffix));
      AboutTbn->setIcon(QIcon(pathPrefix+QStringLiteral("about")+pathSuffix));
      OscilloscopeTbn->setIcon(QIcon(pathPrefix+QStringLiteral("scope")+pathSuffix));
      MoreTbn->setIcon(QIcon(pathPrefix+QStringLiteral("more")+pathSuffix));

      SystemSettingsTbn->setIconSize(QSize(64,64));
      BasicSettingsTbn->setIconSize(QSize(64,64));
      UserSettingsTbn->setIconSize(QSize(64,64));
      ProtectiveFunctionTbn->setIconSize(QSize(64,64));
      FunctionGeneratorTbn->setIconSize(QSize(64,64));
      CommunicationTbn->setIconSize(QSize(64,64));
      AboutTbn->setIconSize(QSize(64,64));
      OscilloscopeTbn->setIconSize(QSize(64,64));
      MoreTbn->setIconSize(QSize(64,64));

      // 2个功能暂时禁用
      OscilloscopeTbn->setEnabled(false);
      MoreTbn->setEnabled(false);
}

void MainWindow::createToolLabels()
{
      SystemSettingsLabel = new QLabel(tr("系统设置"));
      BasicSettingsLabel = new QLabel(tr("基本设置"));
      UserSettingsLabel = new QLabel(tr("用户设置"));
      ProtectiveFunctionLabel = new QLabel(tr("保护设置"));
      FunctionGeneratorLabel = new QLabel(tr("函数发生器"));
      CommunicationLabel = new QLabel(tr("通讯"));
      AboutLabel = new QLabel(tr("关于"));
      OscilloscopeLabel = new QLabel(tr("示波器"));
      MoreLabel = new QLabel(tr("更多"));
}

void MainWindow::createLayout()
{
      mainLayout = new QGridLayout;

      mainLayout->addWidget(SystemSettingsTbn,0,0,4,1,Qt::AlignCenter);
      mainLayout->addWidget(BasicSettingsTbn,0,1,4,1,Qt::AlignCenter);
      mainLayout->addWidget(UserSettingsTbn,0,2,4,1,Qt::AlignCenter);
      mainLayout->addWidget(SystemSettingsLabel,3,0,Qt::AlignCenter);
      mainLayout->addWidget(BasicSettingsLabel,3,1,Qt::AlignCenter);
      mainLayout->addWidget(UserSettingsLabel,3,2,Qt::AlignCenter);

      mainLayout->addWidget(ProtectiveFunctionTbn,4,0,4,1,Qt::AlignCenter);
      mainLayout->addWidget(FunctionGeneratorTbn,4,1,4,1,Qt::AlignCenter);
      mainLayout->addWidget(CommunicationTbn,4,2,4,1,Qt::AlignCenter);
      mainLayout->addWidget(ProtectiveFunctionLabel,7,0,Qt::AlignCenter);
      mainLayout->addWidget(FunctionGeneratorLabel,7,1,Qt::AlignCenter);
      mainLayout->addWidget(CommunicationLabel,7,2,Qt::AlignCenter);

      mainLayout->addWidget(AboutTbn,8,0,4,1,Qt::AlignCenter);
      mainLayout->addWidget(OscilloscopeTbn,8,1,4,1,Qt::AlignCenter);
      mainLayout->addWidget(MoreTbn,8,2,4,1,Qt::AlignCenter);
      mainLayout->addWidget(AboutLabel,11,0,Qt::AlignCenter);
      mainLayout->addWidget(OscilloscopeLabel,11,1,Qt::AlignCenter);
      mainLayout->addWidget(MoreLabel,11,2,Qt::AlignCenter);

      mainLayout->setMargin(10);
      mainLayout->setSpacing(10);
      this->setLayout(mainLayout);
}

void MainWindow::createActions()
{
      SystemSettingsAct = new QAction(tr("系统设置"));
      BasicSettingsAct = new QAction(tr("基本设置"));
      UserSettingsAct = new QAction(tr("用户设置"));
      ProtectiveFunctionAct = new QAction(tr("保护设置"));
      FunctionGeneratorAct = new QAction(tr("函数发生器"));
      CommunicationAct = new QAction(tr("通讯"));
      AboutHardWareAct = new QAction(tr("硬件"));
      AboutSoftWareAct = new QAction(tr("软件"));
      AboutQtAct = new QAction(tr("Qt"));
      AboutCNAct = new QAction(tr("中文"));
      AboutENAct = new QAction(tr("英文"));
      AboutCNAct->setEnabled(false); // 默认中文

      SystemSettingsAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_1));
      BasicSettingsAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_2));
      UserSettingsAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_3));
      ProtectiveFunctionAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_4));
      FunctionGeneratorAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_5));
      CommunicationAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_6));
      AboutHardWareAct->setShortcut(QKeySequence(Qt::CTRL+Qt::SHIFT+Qt::Key_H));
      AboutSoftWareAct->setShortcut(QKeySequence(Qt::CTRL+Qt::SHIFT+Qt::Key_S));
      AboutQtAct->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_Q));
      AboutCNAct->setShortcut(QKeySequence(Qt::SHIFT+Qt::Key_C));
      AboutENAct->setShortcut(QKeySequence(Qt::SHIFT+Qt::Key_E));

      QString pathPrefix = QStringLiteral(":/images/");
      QString pathSuffix = QStringLiteral(".png");
      SystemSettingsAct->setIcon(QIcon(pathPrefix+QStringLiteral("systemSettings")+pathSuffix));
      BasicSettingsAct->setIcon(QIcon(pathPrefix+QStringLiteral("basicSettings")+pathSuffix));
      UserSettingsAct->setIcon(QIcon(pathPrefix+QStringLiteral("userSettings")+pathSuffix));
      ProtectiveFunctionAct->setIcon(QIcon(pathPrefix+QStringLiteral("protectiveFunction")+pathSuffix));
      FunctionGeneratorAct->setIcon(QIcon(pathPrefix+QStringLiteral("functionGenerator")+pathSuffix));
      CommunicationAct->setIcon(QIcon(pathPrefix+QStringLiteral("communication")+pathSuffix));
      AboutHardWareAct->setIcon(QIcon(pathPrefix+QStringLiteral("aboutHardware")+pathSuffix));
      AboutSoftWareAct->setIcon(QIcon(pathPrefix+QStringLiteral("aboutSoftware")+pathSuffix));
      AboutQtAct->setIcon(QIcon(pathPrefix+QStringLiteral("aboutQt")+pathSuffix));
      AboutCNAct->setIcon(QIcon(pathPrefix+QStringLiteral("CN")+pathSuffix));
      AboutENAct->setIcon(QIcon(pathPrefix+QStringLiteral("EN")+pathSuffix));
}

void MainWindow::createMenus()
{
       MenuBar = new QMenuBar(this);
       MenuBar->setGeometry(QRect(0,0,this->width(),30));

       MenuSettings = new QMenu(tr("设置"));
       MenuFunctions = new QMenu(tr("功能"));
       MenuAbout = new QMenu(tr("关于"));
       MenuLanguage = new QMenu(tr("语言"));
       MenuLanguage->setIcon(QIcon(":/images/aboutLanguage.png"));

       MenuSettings->addAction(SystemSettingsAct);
       MenuSettings->addSeparator();
       MenuSettings->addAction(BasicSettingsAct);
       MenuSettings->addSeparator();
       MenuSettings->addAction(UserSettingsAct);

       MenuFunctions->addAction(ProtectiveFunctionAct);
       MenuFunctions->addSeparator();
       MenuFunctions->addAction(FunctionGeneratorAct);
       MenuFunctions->addSeparator();
       MenuFunctions->addAction(CommunicationAct);

       MenuLanguage->addAction(AboutCNAct);
       MenuLanguage->addAction(AboutENAct);

       MenuAbout->addAction(AboutHardWareAct);
       MenuAbout->addSeparator();
       MenuAbout->addAction(AboutSoftWareAct);
       MenuAbout->addSeparator();
       MenuAbout->addAction(AboutQtAct);
       MenuAbout->addSeparator();
       MenuAbout->addMenu(MenuLanguage);//about菜单添加language菜单

       MenuBar->addMenu(MenuSettings);
       MenuBar->addSeparator();
       MenuBar->addMenu(MenuFunctions);
       MenuBar->addSeparator();
       MenuBar->addMenu(MenuAbout);
}
