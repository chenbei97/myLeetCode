#include <serial/serial_config.h>

SerialConfig::SerialConfig(QWidget * parent) :QDialog(parent)
{
        setWindowIcon(QIcon(":/images/portsettings.png"));
        setFont(QFont("Times New Roman",12));
        setWindowTitle(tr("串口配置"));
        resize(QSize(650,300));
        initUI();
        initConnections();
}

void SerialConfig::initConnections()
{
      // 串口
      connect(AvailPortsCombo,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                                     this,&SerialConfig::on_PortChanged); // 切换串口展示对应的信息,并更新设置
      // 波特率
      connect(PortBaudRateCombo,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                             this,&SerialConfig::on_BaudRateChanged); // 切换波特率更改保存的设置
      // 确定按钮
      connect(okBtn,&QPushButton::clicked,this, &SerialConfig::on_OkBtn);
}

void SerialConfig::paintEvent(QPaintEvent *e)
{
    QPainter p;
    p.begin(this);
    p.setOpacity(0.5);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    QPixmap pix(":/images/serial.jpg");
    p.drawPixmap(QPoint(0,0),pix);
    p.end();
    Q_UNUSED(e);
}

SerialConfig::Settings SerialConfig::settings() const
{
        return mSettings;
}

void SerialConfig :: setSettings(const SerialConfig::Settings &settings)
{
      mSettings = settings;
      updateSettings();
}

void SerialConfig::updateSettings()
{
          AvailPortsCombo->setCurrentText(mSettings.Name);
          PortParityCombo->setCurrentText(mSettings.ParityString);
          PortDataBitCombo->setCurrentText(mSettings.DataBitString);
          PortStopBitCombo->setCurrentText(mSettings.StopBitString);
          PortFlowControlCombo->setCurrentText(mSettings.FlowControlString);


          QList<qint32> baudrates = QSerialPortInfo::standardBaudRates();
          if (!baudrates.contains(mSettings.BaudRate)) // 如果不是常见的值,说明是自定义的值,此时必须设为可编辑的才能成功赋值
              PortBaudRateCombo->setEditable(true);
          else PortBaudRateCombo->setEditable(false);
          PortBaudRateCombo->setCurrentText(mSettings.BaudRateString);

}
