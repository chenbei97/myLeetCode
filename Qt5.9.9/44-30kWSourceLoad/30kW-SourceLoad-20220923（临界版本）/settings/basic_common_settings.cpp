#include "settings/basic_common_settings.h"


CommonSettings::CommonSettings(QWidget*parent):QDialog(parent)
      ,workModeLabel(new QLabel(tr("CC/CV优先：")))
      ,voltageRisingSlopeLabel(new QLabel(tr("电压上升斜率：")))
      ,voltageDropingSlopeLabel(new QLabel(tr("电压下降斜率：")))
      ,currentRisingSlopeLabel(new QLabel(tr("电流上升斜率：")))
      ,currentDropingSlopeLabel(new QLabel(tr("电流下降斜率：")))
      ,DcOutputDelayOnLabel(new QLabel(tr("直流输出延时开：")))
      ,DcOutputDelayOffLabel(new QLabel(tr("直流输出延时关：")))
{
      this->initUI();
      this->initConnections();
}

void CommonSettings::initUI()
{
      workMode = new QComboBox;
      voltageRisingSlope = new QDoubleSpinBox;
      voltageDropingSlope = new QDoubleSpinBox;
      currentRisingSlope = new QDoubleSpinBox;
      currentDropingSlope = new QDoubleSpinBox;
      DcOutputDelayOn = new QDoubleSpinBox;
      DcOutputDelayOff = new QDoubleSpinBox;

      // 禁用向上和向下的三角按钮
      voltageRisingSlope->setButtonSymbols(QAbstractSpinBox::NoButtons);
      voltageDropingSlope->setButtonSymbols(QAbstractSpinBox::NoButtons);
      currentRisingSlope->setButtonSymbols(QAbstractSpinBox::NoButtons);
      currentDropingSlope->setButtonSymbols(QAbstractSpinBox::NoButtons);
      DcOutputDelayOn->setButtonSymbols(QAbstractSpinBox::NoButtons);
      DcOutputDelayOff->setButtonSymbols(QAbstractSpinBox::NoButtons);

      workMode->addItem(tr("CV"));
      workMode->addItem(tr("CC"));
      voltageRisingSlope->setSuffix(tr(" V/ms"));
      voltageDropingSlope->setSuffix(tr(" V/ms"));
      currentRisingSlope->setSuffix(tr(" A/ms"));
      currentDropingSlope->setSuffix(tr(" A/ms"));
      DcOutputDelayOn->setSuffix(tr(" /s"));
      DcOutputDelayOff->setSuffix(tr(" /s"));

      voltageRisingSlope->setSingleStep(0.1);
      voltageDropingSlope->setSingleStep(0.1);
      currentRisingSlope->setSingleStep(0.1);
      currentDropingSlope->setSingleStep(0.1);
      DcOutputDelayOn->setSingleStep(0.01);
      DcOutputDelayOff->setSingleStep(0.01);

      workMode->setFixedSize(300,30);
      voltageRisingSlope->setFixedSize(300,30);
      voltageDropingSlope->setFixedSize(300,30);
      currentRisingSlope->setFixedSize(300,30);
      currentDropingSlope->setFixedSize(300,30);
      DcOutputDelayOn->setFixedSize(300,30);
      DcOutputDelayOff->setFixedSize(300,30);

      QStandardItemModel * model = qobject_cast<QStandardItemModel*>(workMode->model());
      for(int i = 0; i < model->rowCount(); ++i)
      {
          QStandardItem * item = model->item(i);
          item->setTextAlignment(Qt::AlignCenter); //让项居中
      }
      QLineEdit * lineEdit = new QLineEdit;
      lineEdit->setAlignment(Qt::AlignCenter); // 文本框也要居中
      workMode->setLineEdit(lineEdit);
      voltageRisingSlope->setAlignment(Qt::AlignCenter);
      voltageDropingSlope->setAlignment(Qt::AlignCenter);
      currentRisingSlope->setAlignment(Qt::AlignCenter);
      currentDropingSlope->setAlignment(Qt::AlignCenter);
      DcOutputDelayOn->setAlignment(Qt::AlignCenter);
      DcOutputDelayOff->setAlignment(Qt::AlignCenter);

      DcOutputDelayOn->setDecimals(3); //调整精度为3位
      DcOutputDelayOff->setDecimals(3); //调整精度为3位

      mainLayout = new QGridLayout(this);
      mainLayout->addWidget(workModeLabel,0,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(workMode,0,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(voltageRisingSlopeLabel,1,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(voltageRisingSlope,1,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(voltageDropingSlopeLabel,2,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(voltageDropingSlope,2,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(currentRisingSlopeLabel,3,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(currentRisingSlope,3,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(currentDropingSlopeLabel,4,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(currentDropingSlope,4,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(DcOutputDelayOnLabel,5,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(DcOutputDelayOn,5,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(DcOutputDelayOffLabel,6,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(DcOutputDelayOff,6,1,1,1,Qt::AlignCenter);

      mainLayout->setMargin(5);
      mainLayout->setSpacing(5);
      mainLayout->setColumnStretch(0,1);
      mainLayout->setColumnStretch(1,2);
      mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
      this->setFont(QFont("Times New Roman",12));
}

CommonSettings::Settings CommonSettings::settings() const
{
      return mSettings;
}

void CommonSettings::setSettings(const CommonSettings::Settings &settings)
{
      mSettings = settings;
      this->updateSettings();//一旦传递进来就更新信息
}

void CommonSettings::updateSettings()
{
      workMode->setCurrentIndex(mSettings.workmode);
      voltageRisingSlope->setValue(mSettings.voltageRisingSlope);
      voltageDropingSlope->setValue(mSettings.voltageDropingSlope);
      currentRisingSlope->setValue(mSettings.currentRisingSlope);
      currentDropingSlope->setValue(mSettings.currentDropingSlope);
      DcOutputDelayOn->setValue(mSettings.DcOutputDelayOn);
      DcOutputDelayOff->setValue(mSettings.DcOutputDelayOff);
}

void CommonSettings::initConnections()
{
      connect(workMode,SIGNAL(currentIndexChanged(int)),this,SLOT(on_workMode(int)));
      connect(voltageRisingSlope,SIGNAL(valueChanged(double)),this,SLOT(on_voltageRisingSlope(double)));
      connect(voltageDropingSlope,SIGNAL(valueChanged(double)),this,SLOT(on_voltageDropingSlope(double)));
      connect(currentRisingSlope,SIGNAL(valueChanged(double)),this,SLOT(on_currentRisingSlope(double)));
      connect(currentDropingSlope,SIGNAL(valueChanged(double)),this,SLOT(on_currentDropingSlope(double)));
      connect(DcOutputDelayOn,SIGNAL(valueChanged(double)),this,SLOT(on_DcOutputDelayOn(double)));
      connect(DcOutputDelayOff,SIGNAL(valueChanged(double)),this,SLOT(on_DcOutputDelayOff(double)));
}

void CommonSettings::on_workMode(int index)
{
      if (index == 0)
      {
           mSettings.workmode = WorkMode::CV;
           mSettings.workmodeString = QStringLiteral("CV");
      }
      else{
          mSettings.workmode = WorkMode::CC;
          mSettings.workmodeString = QStringLiteral("CC");
      }
}

void CommonSettings::on_voltageRisingSlope(double d)
{
      mSettings.voltageRisingSlope = d;
      mSettings.voltageRisingSlopeString  = QString::number(d,'f',2); // 非科学计数法按2位保留
}

void CommonSettings::on_voltageDropingSlope(double d)
{
     mSettings.voltageDropingSlope = d;
     mSettings.voltageDropingSlopeString = QString::number(d,'f',2);//非科学计数法按2位保留
}

void CommonSettings::on_currentRisingSlope(double d)
{
      mSettings.currentRisingSlope = d;
      mSettings.currentRisingSlopeString = QString::number(d,'f',2);//非科学计数法按2位保留
}

void CommonSettings::on_currentDropingSlope(double d)
{
      mSettings.currentDropingSlope = d;
      mSettings.currentDropingSlopeString = QString::number(d,'f',2);//非科学计数法按2位保留
}

void CommonSettings::on_DcOutputDelayOn(double d)
{
      mSettings.DcOutputDelayOn = d;
      mSettings.DcOutputDelayOnString = QString::number(d,'f',3);//非科学计数法按3位保留
}

void CommonSettings::on_DcOutputDelayOff(double d)
{
      mSettings.DcOutputDelayOff = d;
      mSettings.DcOutputDelayOffString = QString::number(d,'f',3);//非科学计数法按3位保留
}
