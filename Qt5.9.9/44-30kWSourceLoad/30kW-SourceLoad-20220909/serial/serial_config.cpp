#include "serial_config.h"

SerialConfig::SerialConfig(QWidget * parent) :QDialog(parent)
{
        setWindowIcon(QIcon(":/images/portsettings.png"));
        setFont(QFont("Times New Roman",12));
        setWindowTitle(tr("串口配置"));
        resize(QSize(650,300));
        initUI();
        initConnections();
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
