#include "qbattery.h"
#include "qbatteryplugin.h"

#include <QtPlugin>

QBatteryPlugin::QBatteryPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QBatteryPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QBatteryPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QBatteryPlugin::createWidget(QWidget *parent)
{
    return new QBattery(parent);
}

QString QBatteryPlugin::name() const
{
    return QLatin1String("QBattery");
}

QString QBatteryPlugin::group() const
{
    return QLatin1String("customWidget");
}

QIcon QBatteryPlugin::icon() const
{
    return QIcon(":/icons/Battery.ico");
}

QString QBatteryPlugin::toolTip() const
{
    return QLatin1String("battery indicator");
}

QString QBatteryPlugin::whatsThis() const
{
    return QLatin1String("one battery indicator");
}

bool QBatteryPlugin::isContainer() const
{
    return false;
}

QString QBatteryPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QBattery\" name=\"qBattery\">\n</widget>\n");
}

QString QBatteryPlugin::includeFile() const
{
    return QLatin1String("qbattery.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qbatteryplugin, QBatteryPlugin)
#endif // QT_VERSION < 0x050000
