#include "../../inc/widgets/inisettings.h"

IniSettings::IniSettings(const QString & filename,QObject*parent):QObject(parent),
    mSettings(new QSettings(filename,QSettings::IniFormat,parent))
{
    mSettings->setIniCodec("utf-8");
    mSettings->setAtomicSyncRequired(true);
}

QVariant IniSettings::value(const QString &key, const QVariant &defaultValue) const
{
    return mSettings->value(key,defaultValue);
}

void IniSettings::setValue(const QString &key, const QVariant &value)
{
    mSettings->setValue(key,value);
    mSettings->sync();
}

//void IniSettings::sync()
//{
//    mSettings->sync();
//}

QStringList IniSettings::allKeys() const
{
    return mSettings->allKeys();
}

void IniSettings::setAtomicSyncRequired(bool enable)
{
     mSettings->setAtomicSyncRequired(enable);
}

void IniSettings::setIniCodec(const char *codecName)
{
    mSettings->setIniCodec(codecName);
}

void IniSettings::setIniCodec(QTextCodec *codec)
{
    mSettings->setIniCodec(codec);
}
