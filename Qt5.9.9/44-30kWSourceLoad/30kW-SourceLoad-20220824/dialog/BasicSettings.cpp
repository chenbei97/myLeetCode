#include "dialog/BasicSettings.h"

BasicSettings::BasicSettings(QWidget*parent):QDialog(parent)
{
      this->initUI();
      this->initConnections();
}

void BasicSettings::initUI()
{
      // (1) 顶部水平布局
      topLayout = new QHBoxLayout;
      listwidget = new QListWidget;
      QStringList  basicSettings;
      basicSettings <<tr("常用设置")<<tr("模拟接口")<<tr("并联设置")
            <<tr("直流终端")<<tr("USB日志记录")<<tr("重设/重启");
      listwidget->addItems(basicSettings);

      stackwidget = new QStackedWidget; // 堆叠界面
      mCommonSettings = new CommonSettings;
      mAnalogInterface = new AnalogInterface;
      mParallelSettings = new ParallelSettings;
      stackwidget->addWidget(mCommonSettings); // 按照顺序添加
      stackwidget->addWidget(mAnalogInterface);
      stackwidget->addWidget(mParallelSettings);

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

      this->setLayout(mainLayout);
      this->resize(800,400);
      this->setFont(QFont("Times New Roman",12));
      this->setWindowTitle(tr("基本设置"));
      this->setWindowIcon(QIcon(":/images/basicSettings.png"));
}

void BasicSettings::initConnections()
{
      connect(listwidget,SIGNAL(currentRowChanged(int)),stackwidget,SLOT(setCurrentIndex(int)));
      connect(okBtn,SIGNAL(clicked()),this,SLOT(on_okBtn()));
      connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
}

BasicSettings::Settings BasicSettings::settings() const
{
        return mSettings;
}

void BasicSettings::setSettings(const BasicSettings::Settings &settings)
{
        mSettings = settings;

      // 把之前已设置的参数传递给新建的窗口,符合用户习惯,保持上次设置的状态
      // 必须在这里写而不是构造函数,因为在主窗口中先调用的构造函数再调用的基本设置窗口的setSettings函数,故在这里更新信息传递
      // 然后常用设置窗口的setSettings函数内部更新信息

       // 反向传递：主窗口->基本设置窗口->堆叠窗口
      mCommonSettings->setSettings(mSettings.commonSettings);
      mAnalogInterface->setSettings(mSettings.analogInterfaceSettings);
      mParallelSettings->setSettings(mSettings.parallelSettings);
}

void BasicSettings::on_okBtn()
{
      // 前向传递：点击确定后传递给堆叠窗口->基本设置窗口->主窗口
      mSettings.commonSettings = mCommonSettings->settings();
      mSettings.analogInterfaceSettings = mAnalogInterface->settings();
      mSettings.parallelSettings = mParallelSettings->settings();
      emit basicSettings(mSettings); // 把基本设置的所有内部设置的信息发送出去
      this->accept();
}
