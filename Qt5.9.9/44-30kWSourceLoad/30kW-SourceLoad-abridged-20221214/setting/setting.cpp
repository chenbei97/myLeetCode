#include <setting/setting.h>

Setting::Setting(QWidget * parent):QDialog(parent)
{
    initUI();
    initConnections();
}

void Setting::initUI()
{

    // (1) 顶部水平布局
    topLayout = new QHBoxLayout;
    listwidget = new QListWidget;
    QStringList  settings;
    settings <<tr("日志设置")<<tr("模拟接口")<<tr("并联设置")
          <<tr("直流终端")<<tr("USB日志记录")<<tr("重设/重启");
    listwidget->addItems(settings);

    stackwidget = new QStackedWidget; // 堆叠界面
    mTableView = new TableView;
    stackwidget->addWidget(mTableView); // 按照顺序添加

    topLayout->addWidget(listwidget,Qt::AlignCenter);
    topLayout->addWidget(stackwidget,Qt::AlignCenter);
    topLayout->setMargin(10);
    topLayout->setSpacing(10);
    topLayout->setStretch(0,1);
    topLayout->setStretch(1,4);// 1:4的比例

    // (2) 底部水平布局
    bottomLayout = new QHBoxLayout;
    okBtn = new QPushButton(tr("确定"));
    cancelBtn = new QPushButton(tr("取消"));
    bottomLayout->addStretch();
    bottomLayout->addWidget(okBtn);
    bottomLayout->addWidget(cancelBtn);

    // (3) 全局布局
    mainLayout = new QGridLayout;
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(topLayout,0,0);
    mainLayout->addLayout(bottomLayout,1,0);

    setLayout(mainLayout);
    resize(1150,400);
    setFont(QFont("Times New Roman",12));
    setWindowTitle(tr("基本设置"));
    setWindowIcon(QIcon(":/images/basicSettings.png"));
    setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);//添加最大最小化和关闭按钮
    setWindowFlag(Qt::Window); // 设置window属性就不会总是让界面在前或者在后
    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags^Qt::WindowContextHelpButtonHint); // 去除帮助按钮
}

void Setting::initConnections()
{
    // mainwindow's monitorSetting emit = > mainSetting => mTableView => mTableSizeDlg
    connect(this,&Setting::workModeChanged,mTableView,&TableView::workModeChanged);
    // mTableSPDlg's pushbutton emit => mTableView => mainSetting => mainWindow => communication => tcp/usb
    connect(mTableView,&TableView::selectedPeriod,this,&Setting::selectedPeriod);
    // mainCommunication's log => mainSetting => mTableView
    connect(this,&Setting::log,mTableView,&TableView::log);

    connect(okBtn,&QPushButton::clicked,this,[=]{accept();});
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
}
