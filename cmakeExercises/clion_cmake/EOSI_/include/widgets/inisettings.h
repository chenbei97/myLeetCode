#ifndef INISETTINGS_H
#define INISETTINGS_H

#include "qsettings.h"
#include "../public.h"

class COMPONENT_IMEXPORT IniSettings : public QObject
{
private:
    QSettings * mSettings;
public:
    explicit IniSettings(const QString & filename,QObject*parent = nullptr);

    QStringList  allKeys() const;

    void setAtomicSyncRequired(bool enable);

    void setIniCodec(QTextCodec *codec);
    void setIniCodec(const char *codecName);

    void setValue(const QString &key, const QVariant &value);

    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;

    //void sync();

    ~ IniSettings(){mSettings->deleteLater();}
};

#endif // INISETTINGS_H
