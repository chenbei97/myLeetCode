#include "core/Monitor.h"

Monitor::Monitor(QWidget *parent,WORKMODE  workmode) : QMainWindow(parent)
{
        this->resize(1000,600);
        this->setFont(QFont("Times New Roman",12)); //格式和字体要先初始化,然后基于此时窗口初始化布局,放在后头就会错误

        this->mWorkMode = workmode;
        QString title;
        if (workmode == WORKMODE::CV)
        {
              this->initCVUI();
              title = tr("监控界面(CV模式)");
        }
        else {
              this->initCCUI();
              title = tr("监控界面(CC模式)");
        }
        this->initConnections();
        this->setWindowTitle(title);
}

void Monitor::initCommonUI() // 布局初始化的公共部分
{
      mainLayout = new QSplitter(Qt::Vertical,this);
      mainLayout->setOpaqueResize(true);
      mainLayout->setHandleWidth(5);
      mainLayout->setChildrenCollapsible(false);
      this->setCentralWidget(mainLayout);

      VoltageGroupBox = new QGroupBox(tr("电压"));
      CurrentGroupBox = new QGroupBox(tr("电流"));

      // （1）功率面板设置
      PowerGroupBox = new QGroupBox(tr("功率"));//功率的容器
      ShowPower = new QLabel(tr("00.000 W"));  // 功率的组件
      ShowPower->setAlignment(Qt::AlignCenter);
      ShowPower->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}");
      ShowPower->setFixedWidth(this->width()/2);// 因为使用的是QSplitter,故固定宽度即可
      ShowPower->setFrameStyle(QFrame::Sunken | QFrame::Panel);
      SetPowerSourceLabel = new QLabel(tr("源功率设置："));
      SetPowerSource = new QDoubleSpinBox;
      SetPowerLoadLabel = new QLabel(tr("载功率设置："));
      SetPowerLoad = new QDoubleSpinBox;
      SetPowerSource->setSuffix((" W"));
      SetPowerLoad->setSuffix((" W"));
      SetPowerSource->setFixedSize(this->width()/3,30);
      SetPowerLoad->setFixedSize(this->width()/3,30);
      SetPowerSource->setAlignment(Qt::AlignCenter);
      SetPowerLoad->setAlignment(Qt::AlignCenter);

      QGridLayout * PowerLayout = new QGridLayout; // 功率的布局
      PowerLayout->addWidget(ShowPower,0,0,4,1);
      PowerLayout->addWidget(SetPowerSourceLabel,0,1);
      PowerLayout->addWidget(SetPowerSource,1,1);
      PowerLayout->addWidget(SetPowerLoadLabel,2,1);
      PowerLayout->addWidget(SetPowerLoad,3,1);
      PowerGroupBox->setLayout(PowerLayout); // 功率容器设置布局
//      PowerLayout->setColumnStretch(0,4);
//      PowerLayout->setColumnStretch(1,1);

      // （2） 电阻面板设置
      IsShowResistanceLabel = new QLabel(tr("是否显示内阻设置："));
      IsShowResistance = new QCheckBox;
      IsShowResistance->setChecked(true);// 默认显示电阻面板

      ResistanceGroupBox = new QGroupBox(tr("内阻")); // 电阻容器
      ShowResistance = new QLabel(tr("00.000 Ω"));  // 功率的组件
      ShowResistance->setAlignment(Qt::AlignCenter);
      ShowResistance->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}");
      ShowResistance->setFixedWidth(this->width()/2);// 因为使用的是QSplitter,故固定宽度即可
      ShowResistance->setFrameStyle(QFrame::Sunken | QFrame::Panel);
      SetResistanceSourceLabel = new QLabel(tr("源内阻设置："));
      SetResistanceSource = new QDoubleSpinBox;
      SetResistanceLoadLabel = new QLabel(tr("载内阻设置："));
      SetResistanceLoad = new QDoubleSpinBox;
      SetResistanceSource->setSuffix((" Ω"));
      SetResistanceLoad->setSuffix((" Ω"));
      SetResistanceSource->setFixedSize(this->width()/3,30);
      SetResistanceLoad->setFixedSize(this->width()/3,30);
      SetResistanceSource->setAlignment(Qt::AlignCenter);
      SetResistanceLoad->setAlignment(Qt::AlignCenter);

      QGridLayout * ResistanceLayout = new QGridLayout; // 功率的布局
      ResistanceLayout->addWidget(ShowResistance,0,0,4,1);
      ResistanceLayout->addWidget(SetResistanceSourceLabel,0,1);
      ResistanceLayout->addWidget(SetResistanceSource,1,1);
      ResistanceLayout->addWidget(SetResistanceLoadLabel,2,1);
      ResistanceLayout->addWidget(SetResistanceLoad,3,1);
      ResistanceGroupBox->setLayout(ResistanceLayout); // 功率容器设置布局
}
void Monitor::initCVUI()
{
      this->initCommonUI();
      // （1）面板组件设置
      // （1.1）电压面板组件设置
       // QPalette VolatgePalette = ShowVoltage->palette();VolatgePalette.setColor(QPalette::Background,Qt::red);howVoltage->setPalette(VolatgePalette);
      // setPalette不能控制颜色,setFont不能控制大小
      QLabel * ShowVoltage = new QLabel(tr("00.000 V")); // 电压读取1个
      QLabel * SetVoltageLabel = new QLabel(tr("电压设置："));
      QDoubleSpinBox * SetVoltage = new QDoubleSpinBox;// 电压设置1个
      ShowVoltage->setAlignment(Qt::AlignCenter);
      ShowVoltage->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}"); // 只能使用setStyleSheet控制
      ShowVoltage->setFixedWidth(this->width()/2);// 因为使用的是QSplitter,故固定宽度即可
      ShowVoltage->setFrameStyle(QFrame::Sunken | QFrame::Panel);
      SetVoltage->setSuffix(tr(" V"));
      SetVoltage->setAlignment(Qt::AlignCenter);
      SetVoltage->setFixedSize(this->width()/3,30);

      // （1.2） 电流面板组件设置
      QLabel * ShowCurrent = new QLabel(tr("00.000 A")); // 电流读取1个
      QLabel * SetCurrentSourceLabel = new QLabel(tr("源电流设置：")); // 电流设置2个,源和载
      QDoubleSpinBox * SetCurrentSource = new QDoubleSpinBox;
      QLabel * SetCurrentLoadLabel = new QLabel(tr("载电流设置："));
      QDoubleSpinBox * SetCurrentLoad = new QDoubleSpinBox;
      ShowCurrent->setAlignment(Qt::AlignCenter);
      ShowCurrent->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}");
      ShowCurrent->setFixedWidth(this->width()/2);
      ShowCurrent->setFrameStyle(QFrame::Sunken | QFrame::Panel);
      SetCurrentSource->setSuffix(" A");
      SetCurrentLoad->setSuffix(" A");
      SetCurrentSource->setAlignment(Qt::AlignCenter);
      SetCurrentLoad->setAlignment(Qt::AlignCenter);
      SetCurrentSource->setFixedSize(this->width()/3,30);
      SetCurrentLoad->setFixedSize(this->width()/3,30);

      //*********************************************************************************
      // （2）布局设置
      // （2.1）电压布局设置
      QGridLayout * VoltageLayout = new QGridLayout;
      VoltageLayout->addWidget(ShowVoltage,0,0,4,1);
      VoltageLayout->addWidget(SetVoltageLabel,0,1);
      VoltageLayout->addWidget(SetVoltage,1,1);
      VoltageLayout->addWidget(IsShowResistanceLabel,2,1);
      VoltageLayout->addWidget(IsShowResistance,3,1,Qt::AlignRight);
      VoltageGroupBox->setLayout(VoltageLayout);
      // （2.2）电流布局设置
      QGridLayout * CurrentLayout = new QGridLayout; // 电流的布局
      CurrentLayout->addWidget(ShowCurrent,0,0,4,1);
      CurrentLayout->addWidget(SetCurrentSourceLabel,0,1);
      CurrentLayout->addWidget(SetCurrentSource,1,1);
      CurrentLayout->addWidget(SetCurrentLoadLabel,2,1);
      CurrentLayout->addWidget(SetCurrentLoad,3,1);
      CurrentGroupBox->setLayout(CurrentLayout); // 电流容器设置布局

      mainLayout->addWidget(VoltageGroupBox);
      mainLayout->addWidget(CurrentGroupBox);
      mainLayout->addWidget(PowerGroupBox);
      mainLayout->addWidget(ResistanceGroupBox);//默认初始化加电阻面板
}

void Monitor::initCCUI()
{
      this->initCommonUI();
        // （1）面板组件设置
      // （1.1）电流面板组件设置
      QLabel * ShowCurrent = new QLabel(tr("00.000 V")); // 电流读取1个
      QLabel * SetCurrentLabel = new QLabel(tr("电流设置："));
      QDoubleSpinBox * SetCurrent = new QDoubleSpinBox;// 电流设置1个
      ShowCurrent->setAlignment(Qt::AlignCenter);
      ShowCurrent->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}"); // 只能使用setStyleSheet控制
      ShowCurrent->setFixedWidth(this->width()/2);// 因为使用的是QSplitter,故固定宽度即可
      ShowCurrent->setFrameStyle(QFrame::Sunken | QFrame::Panel);
      SetCurrent->setSuffix(tr(" A"));
      SetCurrent->setAlignment(Qt::AlignCenter);
      SetCurrent->setFixedSize(this->width()/3,30);

      // （1.2） 电压面板组件设置
      QLabel * ShowVoltage = new QLabel(tr("00.000 A")); // 电压读取1个
      QLabel * SetVoltageSourceLabel = new QLabel(tr("源电压设置：")); // 电压设置2个,源和载
      QDoubleSpinBox * SetVoltageSource = new QDoubleSpinBox;
      QLabel * SetVoltageLoadLabel = new QLabel(tr("载电压设置："));
      QDoubleSpinBox * SetVoltageLoad = new QDoubleSpinBox;
      ShowVoltage->setAlignment(Qt::AlignCenter);
      ShowVoltage->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}");
      ShowVoltage->setFixedWidth(this->width()/2);
      ShowVoltage->setFrameStyle(QFrame::Sunken | QFrame::Panel);
      SetVoltageSource->setSuffix(" V");
      SetVoltageLoad->setSuffix(" V");
      SetVoltageSource->setAlignment(Qt::AlignCenter);
      SetVoltageLoad->setAlignment(Qt::AlignCenter);
      SetVoltageSource->setFixedSize(this->width()/3,30);
      SetVoltageLoad->setFixedSize(this->width()/3,30);

      //*********************************************************************************
      // （2）布局设置
      // （2.1）电流布局设置
      QGridLayout * CurrentLayout = new QGridLayout;
      CurrentLayout->addWidget(ShowCurrent,0,0,4,1);
      CurrentLayout->addWidget(SetCurrentLabel,0,1);
      CurrentLayout->addWidget(SetCurrent,1,1);
      CurrentLayout->addWidget(IsShowResistanceLabel,2,1);
      CurrentLayout->addWidget(IsShowResistance,3,1,Qt::AlignRight);
      CurrentGroupBox->setLayout(CurrentLayout);
      // （2.2）电压布局设置
      QGridLayout * VoltageLayout = new QGridLayout; // 电压的布局
      VoltageLayout->addWidget(ShowVoltage,0,0,4,1);
      VoltageLayout->addWidget(SetVoltageSourceLabel,0,1);
      VoltageLayout->addWidget(SetVoltageSource,1,1);
      VoltageLayout->addWidget(SetVoltageLoadLabel,2,1);
      VoltageLayout->addWidget(SetVoltageLoad,3,1);
      VoltageGroupBox->setLayout(VoltageLayout); // 电压容器设置布局

      mainLayout->addWidget(CurrentGroupBox);
      mainLayout->addWidget(VoltageGroupBox);
      mainLayout->addWidget(PowerGroupBox);
      mainLayout->addWidget(ResistanceGroupBox);//默认初始化加电阻面板
}

void Monitor::initConnections()
{
      connect(IsShowResistance,&QCheckBox::stateChanged,this,&Monitor::on_IsShowResistance);
}

void Monitor::on_IsShowResistance(bool checked)
{
       if (checked)
       {
            ResistanceGroupBox->show();
       }
       else {
            ResistanceGroupBox->hide();
       }
}

WORKMODE Monitor::workMode() const
{
      return this->mWorkMode;
}
