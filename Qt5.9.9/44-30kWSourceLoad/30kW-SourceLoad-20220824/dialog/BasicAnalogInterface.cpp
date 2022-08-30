#include "dialog/BasicAnalogInterface.h"

AnalogInterface::AnalogInterface(QWidget * parent) : QDialog(parent)
  , remoteControlLabel(new QLabel(tr("允许接口远程控制：")))
  , voltageRangeLabel(new QLabel(tr("允许接口电压范围：")))
  , pinSixLabel(new QLabel(tr("引脚 6：")))
  , pinFourteenLabel(new QLabel(tr("引脚 14：")))
  , pinFifteenLabel(new QLabel(tr("引脚 15：")))
  , vcMonLabel(new QLabel(tr("VMON/CMON：")))
  , remSBStateLabel(new QLabel(tr("模拟接口Rem-SB状态：")))
  , remSBActionLabel(new QLabel(tr("模拟接口Rem-SB动作：")))
{
        this->initUI();
        this->initConnections();
}

void AnalogInterface::initUI()
{
        remoteControl = new QCheckBox;
        voltageRange = new QComboBox;
        pinSix = new QComboBox;
        pinFourteen = new QComboBox;
        pinFifteen = new QComboBox;
        vcMon = new QComboBox;
        remSBState = new QComboBox;
        remSBAction = new QComboBox;

        remoteControl->setCheckState(Qt::CheckState::Unchecked);//默认禁止
        QStringList voltage_list = {QStringLiteral("0.1 V"),QStringLiteral("0.5 V")};
        voltageRange->addItems(voltage_list);
        QStringList pinsix_list = {QStringLiteral("OT"),QStringLiteral("PF"),QStringLiteral("OT&PF")};
        pinSix->addItems(pinsix_list);
        QStringList pinfourteen_list = {QStringLiteral("OVP"),QStringLiteral("OCP"),QStringLiteral("OPP"),
                                                           QStringLiteral("OVP&OCP"),QStringLiteral("OVP&OPP"),QStringLiteral("OCP&OPP"),
                                                           QStringLiteral("OVP&OCP&OPP")};
        pinFourteen->addItems(pinfourteen_list);
        QStringList pinfifteen_list = {tr("调整模式"),tr("直流状况")};
        pinFifteen->addItems(pinfifteen_list);
        QStringList vcmon_list = {tr("默认"),tr("实际电流EL"),tr("实际电流PS"),tr("实际电流EL&PS"),tr("A模式"),tr("B模式")};
        vcMon->addItems(vcmon_list);
        QStringList remstate_list = {tr("正常"),tr("已翻转")};
        remSBState->addItems(remstate_list);
        QStringList remaction_list = {tr("直流开&关"),tr("直流关")};
        remSBAction->addItems(remaction_list);

        // remoteControl->setFixedSize(300,30); //checkBox是正方形无法调整也不需要调整
        voltageRange->setFixedSize(300,30);
        pinSix->setFixedSize(300,30);
        pinFourteen->setFixedSize(300,30);
        pinFifteen->setFixedSize(300,30);
        vcMon->setFixedSize(300,30);
        remSBState->setFixedSize(300,30);
        remSBAction->setFixedSize(300,30);

        setComboBoxAlignCenter(voltageRange);
        setComboBoxAlignCenter(pinSix);
        setComboBoxAlignCenter(pinFourteen);
        setComboBoxAlignCenter(pinFifteen);
        setComboBoxAlignCenter(vcMon);
        setComboBoxAlignCenter(remSBState);
        setComboBoxAlignCenter(remSBAction);

        mainLayout = new QGridLayout(this);
        mainLayout->addWidget(remoteControlLabel,0,0,1,1,Qt::AlignCenter);
        mainLayout->addWidget(remoteControl,0,1,1,1,Qt::AlignCenter);
        mainLayout->addWidget(voltageRangeLabel,1,0,1,1,Qt::AlignCenter);
        mainLayout->addWidget(voltageRange,1,1,1,1,Qt::AlignCenter);
        mainLayout->addWidget(pinSixLabel,2,0,1,1,Qt::AlignCenter);
        mainLayout->addWidget(pinSix,2,1,1,1,Qt::AlignCenter);
        mainLayout->addWidget(pinFourteenLabel,3,0,1,1,Qt::AlignCenter);
        mainLayout->addWidget(pinFourteen,3,1,1,1,Qt::AlignCenter);
        mainLayout->addWidget(pinFifteenLabel,4,0,1,1,Qt::AlignCenter);
        mainLayout->addWidget(pinFifteen,4,1,1,1,Qt::AlignCenter);
        mainLayout->addWidget(vcMonLabel,5,0,1,1,Qt::AlignCenter);
        mainLayout->addWidget(vcMon,5,1,1,1,Qt::AlignCenter);
        mainLayout->addWidget(remSBStateLabel,6,0,1,1,Qt::AlignCenter);
        mainLayout->addWidget(remSBState,6,1,1,1,Qt::AlignCenter);
        mainLayout->addWidget(remSBActionLabel,7,0,1,1,Qt::AlignCenter);
        mainLayout->addWidget(remSBAction,7,1,1,1,Qt::AlignCenter);

        mainLayout->setMargin(5);
        mainLayout->setSpacing(5);
        mainLayout->setColumnStretch(0,1);
        mainLayout->setColumnStretch(1,2);
        mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        this->setFont(QFont("Times New Roman",12));
}

AnalogInterface::Settings AnalogInterface::settings() const
{
      return mSettings;
}

void AnalogInterface::setSettings(const AnalogInterface::Settings &settings)
{
    mSettings = settings;
    this->updateSettings();
}

void AnalogInterface::updateSettings()
{
      // 枚举值和项索引对应的
      remoteControl->setChecked(mSettings.remoteControl); // 0=prohibit,1=allow和项索引是对应的
      voltageRange->setCurrentIndex(mSettings.voltageRange);
      pinSix->setCurrentIndex(mSettings.pinSix);
      pinFourteen->setCurrentIndex(mSettings.pinFourteen);
      pinFifteen->setCurrentIndex(mSettings.pinFifteen);
      vcMon->setCurrentIndex(mSettings.vcMon);
      remSBState->setCurrentIndex(mSettings.remSBState);
      remSBAction->setCurrentIndex(mSettings.remSBAction);
}

void AnalogInterface::initConnections()
{
      connect(remoteControl,SIGNAL(stateChanged(int)),this,SLOT(on_remoteControl(int)));
      connect(voltageRange,SIGNAL(currentIndexChanged(int)),this,SLOT(on_voltageRange(int)));
      connect(pinSix,SIGNAL(currentIndexChanged(int)),this,SLOT(on_pinSix(int)));
      connect(pinFourteen,SIGNAL(currentIndexChanged(int)),this,SLOT(on_pinFourteen(int)));
      connect(pinFifteen,SIGNAL(currentIndexChanged(int)),this,SLOT(on_pinFifteen(int)));
      connect(vcMon,SIGNAL(currentIndexChanged(int)),this,SLOT(on_vcMon(int)));
      connect(remSBState,SIGNAL(currentIndexChanged(int)),this,SLOT(on_remSBState(int)));
      connect(remSBAction,SIGNAL(currentIndexChanged(int)),this,SLOT(on_remSBAction(int)));
}

void AnalogInterface::setComboBoxAlignCenter(QComboBox *combo)
{
        // 项居中
        QStandardItemModel * model = qobject_cast<QStandardItemModel*>(combo->model());
        for (int i = 0; i < model->rowCount(); ++ i)
        {
              QStandardItem * item = model->item(i);
              item->setTextAlignment(Qt::AlignCenter);
        }

        // 文本框居中
        QLineEdit * line = new QLineEdit;
        line->setAlignment(Qt::AlignCenter);
        combo->setLineEdit(line);
}


void AnalogInterface::on_remoteControl(int checked)
{
    if (checked == 0)
    {
        mSettings.remoteControl = RemoteControl::PROHIBT;
        mSettings.remoteControlString = tr("禁止");
    }
    else {
        mSettings.remoteControl = RemoteControl::ALLOW;
        mSettings.remoteControlString = tr("允许");
    }
}

void AnalogInterface::on_voltageRange(int index)
{
    if (index == 0)
    {
          mSettings.voltageRange = VoltageRange::ZERO_ONE;
          mSettings.voltageRangeString = QStringLiteral("0.1 V");
    }
    else{
          mSettings.voltageRange = VoltageRange::ZERO_FIVE;
          mSettings.voltageRangeString = QStringLiteral("0.5 V");
    }
}

void AnalogInterface::on_pinSix(int index)
{
    switch (index)
    {
          case 1:
                  mSettings.pinSix = PinSix::PF;
                  mSettings.pinSixString = QStringLiteral("PF");
                  break;
          case 2:
                  mSettings.pinSix = PinSix::OT_PF;
                  mSettings.pinSixString = QStringLiteral("OT&PF");
                  break;
          default:
                  mSettings.pinSix = PinSix::OT;
                  mSettings.pinSixString = QStringLiteral("OT");
                  break;
    }
}

void AnalogInterface::on_pinFourteen(int index)
{
      switch (index)
      {
            case 1:
                    mSettings.pinFourteen = PinFourteen::OCP;
                    mSettings.pinFourteenString = QStringLiteral("OCP");
                    break;
            case 2:
                    mSettings.pinFourteen = PinFourteen::OPP;
                    mSettings.pinFourteenString = QStringLiteral("OPP");
                    break;
            case 3:
                    mSettings.pinFourteen = PinFourteen::OVP_OCP;
                    mSettings.pinFourteenString = QStringLiteral("OVP&OCP");
                    break;
            case 4:
                    mSettings.pinFourteen = PinFourteen::OVP_OPP;
                    mSettings.pinFourteenString = QStringLiteral("OVP&OPP");
                    break;
            case 5:
                    mSettings.pinFourteen = PinFourteen::OCP_OPP;
                    mSettings.pinFourteenString = QStringLiteral("OCP&OPP");
                    break;
           case 6:
                    mSettings.pinFourteen = PinFourteen::OVP_OCP_OPP;
                    mSettings.pinFourteenString = QStringLiteral("OVP&OCP&OPP");
                    break;
           default:
                    mSettings.pinFourteen = PinFourteen::OVP;
                    mSettings.pinFourteenString = QStringLiteral("OVP");
                    break;
      }
}

void AnalogInterface::on_pinFifteen(int index)
{
      if (index == 0)
      {
            mSettings.pinFifteen = PinFifteen::ADJUSTED_MODE;
            mSettings.pinFifteenString = tr("调整模式");
      }
      else{
            mSettings.pinFifteen = PinFifteen::DC_CONDITION;
            mSettings.pinFifteenString = tr("直流状况");
      }
}

void AnalogInterface::on_vcMon(int index)
{
      switch (index)
      {
            case 1:
                    mSettings.vcMon = VCMon::EL;
                    mSettings.vcMonString = tr("实际电流EL");
                    break;
            case 2:
                    mSettings.vcMon = VCMon::PS;
                    mSettings.vcMonString = tr("实际电流PS");
                    break;
            case 3:
                    mSettings.vcMon = VCMon::EL_PS;
                    mSettings.vcMonString = tr("实际电流EL&PS");
                    break;
            case 4:
                    mSettings.vcMon = VCMon::AMODE;
                    mSettings.vcMonString = tr("A模式");
                    break;
            case 5:
                    mSettings.vcMon = VCMon::BMODE;
                    mSettings.vcMonString = tr("B模式");
                    break;
           default:
                    mSettings.vcMon = VCMon::DEFAULT;
                    mSettings.vcMonString = tr("默认");
                    break;
      }
}

void AnalogInterface::on_remSBState(int index)
{
      if (index == 0)
      {
            mSettings.remSBState = RemSBState::NORMAL;
            mSettings.remSBStateString = tr("正常");
      }
      else{
            mSettings.remSBState = RemSBState::FLIPPED;
            mSettings.remSBStateString = tr("已翻转");
      }
}

void AnalogInterface::on_remSBAction(int index)
{
      if (index == 0)
      {
            mSettings.remSBAction = RemSBAction::DC_ON_OFF;
            mSettings.remSBActionString = tr("直流开&关");
      }
      else{
            mSettings.remSBAction = RemSBAction::DC_OFF;
            mSettings.remSBActionString = tr("直流关");
      }
}
