#include "settings/basic_parallel_settings.h"

ParallelSettings::ParallelSettings(QWidget * parent):QDialog(parent)
  , masterSlaveModeLabel(new QLabel(tr("主从模式：")))
  , masterModeStateLabel(new QLabel(tr("主模式状态：")))
  , masterModbusAddressLabel(new QLabel(tr("本机/Modbus地址：")))
  , slaveCountLabel(new QLabel(tr("从机个数")))
{
      this->initUI();
      this->initConnections();
}


void ParallelSettings::initUI()
{
      masterSlaveMode = new QComboBox;
      masterModeState = new QComboBox;
      masterModbusAddress = new QSpinBox;
      slaveCount = new QSpinBox;
      rebootSystem = new QPushButton(tr("重启系统"));

      QStringList modelist = {tr("关闭"),tr("主机"),tr("从机")};
      this->masterSlaveMode->addItems(modelist);
      setComboBoxAlignCenter(masterSlaveMode);
      QStringList statelist = {tr("未初始化"),tr("已初始化")};
      masterModeState->addItems(statelist);
      this->setComboBoxAlignCenter(masterModeState);
      masterModeState->setEnabled(false);//状态只用于显示
      masterModeState->setToolTip(tr("请在电源关闭输出后操作"));
      masterModbusAddress->setMinimum(1);
      masterModbusAddress->setAlignment(Qt::AlignCenter);
      masterModbusAddress->setToolTip(tr("主机至少1个"));
      slaveCount->setMinimum(0);
      slaveCount->setAlignment(Qt::AlignCenter);
      slaveCount->setToolTip(tr("从机可以是0个,注意从机的数量不能过多"));

      masterSlaveMode->setFixedSize(200,30);
      masterModeState->setFixedSize(200,30);
      masterModbusAddress->setFixedSize(200,30);
      slaveCount->setFixedSize(200,30);
      rebootSystem->setFixedSize(200,30);

      mainLayout = new QGridLayout;
      mainLayout->addWidget(masterSlaveModeLabel,0,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(masterSlaveMode,0,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(masterModeStateLabel,1,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(masterModeState,1,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(masterModbusAddressLabel,2,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(masterModbusAddress,2,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(slaveCountLabel,3,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(slaveCount,3,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(rebootSystem,4,1,1,1,Qt::AlignCenter);

      mainLayout->setMargin(10);
      mainLayout->setSpacing(10);
      mainLayout->setColumnStretch(0,1);
      mainLayout->setColumnStretch(1,1);
      mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

      this->setLayout(mainLayout);
      this->setFont(QFont("Times New Roman",12));
}

void ParallelSettings::initConnections()
{
      connect(masterSlaveMode,SIGNAL(currentIndexChanged(int)),this,SLOT(on_masterSlaveMode(int)));
      connect(masterModeState,SIGNAL(currentIndexChanged(int)),this,SLOT(on_masterModeState(int)));//不过这条可能没有实际意义,因为状态是不可编辑的
      connect(masterModbusAddress,SIGNAL(valueChanged(int)),this,SLOT(on_masterModbusAddress(int)));
      connect(slaveCount,SIGNAL(valueChanged(int)),this,SLOT(on_slaveCount(int)));
      connect(rebootSystem,SIGNAL(clicked()),this,SLOT(on_rebootSystem()));
}

ParallelSettings::Settings ParallelSettings::settings() const
{
      return mSettings;
}

void ParallelSettings::setSettings(const ParallelSettings::Settings &settings)
{
      mSettings = settings;
      this->updateSettings();
}

void ParallelSettings::updateSettings()
{
      masterSlaveMode->setCurrentIndex(mSettings.masterSlaveMode); // 0=off,1=master,2=slave
      masterModeState->setCurrentIndex(mSettings.masterModeState); // 0 = uninitialized 1= initialized
      masterModbusAddress->setValue(mSettings.masterModbusAddress);
      slaveCount->setValue(mSettings.slaveCount);
}


void ParallelSettings::setComboBoxAlignCenter(QComboBox *combo)
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

void ParallelSettings::on_masterSlaveMode(int index)
{
      switch (index)
      {
             case 1:
                  mSettings.masterSlaveMode = MasterSlaveMode::MASTER;
                  mSettings.masterSlaveModeString = tr("主机");
                  break;
            case 2:
                  mSettings.masterSlaveMode = MasterSlaveMode::SLAVE;
                  mSettings.masterSlaveModeString = tr("从机");
                  break;
            default:
                  mSettings.masterSlaveMode = MasterSlaveMode::OFF;
                  mSettings.masterSlaveModeString = tr("关闭");
                  break;
      }
}

void ParallelSettings::on_masterModeState(int index)
{
      if (index == 0)
      {
            mSettings.masterModeState = MasterSlaveState::UNINITIALIZED;
            mSettings.masterModeStateString = tr("未初始化");
      }
      else{
            mSettings.masterModeState = MasterSlaveState::INITIALIZED;
            mSettings.masterModeStateString = tr("已初始化");
      }
}

void ParallelSettings::on_masterModbusAddress(int value)
{
      mSettings.masterModbusAddress = value;
      mSettings.masterModbusAddressString = QString::number(value);
}

void ParallelSettings::on_slaveCount(int value)
{
    mSettings.slaveCount = value;
    mSettings.slaveCountString = QString::number(value);
}

void ParallelSettings::on_rebootSystem()
{
      QMessageBox question(QMessageBox::Icon::Question,tr(" "),tr("确定要重启吗?"));
      question.addButton(tr("确定"),QMessageBox::ButtonRole::YesRole);
      question.addButton(tr("取消"),QMessageBox::ButtonRole::RejectRole);
      //question.setIconPixmap(QPixmap(":/images/question.png")); //这个是在文字左边的
      question.setWindowIcon(QIcon(":/images/question.png"));
      int ret = question.exec();
      if (ret == QMessageBox::ButtonRole::RejectRole)
      {
           // dosomething
      }

}
