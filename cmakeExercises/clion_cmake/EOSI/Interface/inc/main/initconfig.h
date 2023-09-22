#ifndef INIT_CONFIG_H
#define INIT_CONFIG_H

#include "widgets/inisettings.h"
#include "qtextcodec.h"
#include "qcryptographichash.h"

enum class LoginConfigParamType {IP,USERNAME,PASSWORD,DBDIR,DBTYPE};

const QMap<LoginConfigParamType,QString> LoginConfigToString ={ // 一个枚举-字符串转换函数，值用于写入.ini
    {LoginConfigParamType::IP, "system/equipment"},
    {LoginConfigParamType::USERNAME, "system/username"},
    {LoginConfigParamType::PASSWORD, "system/password"},
    {LoginConfigParamType::DBDIR, "system/dbdir"},
    {LoginConfigParamType::DBTYPE, "system/dbtype"},
};

struct LoginInitConfig{
    QStringPair ip;
    QStringPair username;
    QStringPair password;
    QStringPair dbdir;
    QStringPair dbtype;
};


static void readConfig()
{
    IniSettings * settings = new IniSettings (CONFIG_PATH);
    foreach(auto key, LoginConfigToString.values())
        LOG<<key<<": "<<settings->value(key).toString();
};

static QString readConfig(LoginConfigParamType key)
{
    QString res;
    IniSettings * settings = new IniSettings (CONFIG_PATH);
    res = settings->value(LoginConfigToString[key]).toString();
    return  res;
}

static void writeConfig(LoginConfigParamType key,const QVariant &value )
{
    QString res;
    IniSettings * settings = new IniSettings (CONFIG_PATH);
    settings->setValue(LoginConfigToString[key],value);
}

static void updateConfig(LoginInitConfig*config)
{
    IniSettings * settings = new IniSettings (CONFIG_PATH);
    settings->setValue(config->ip.first,config->ip.second);
    settings->setValue(config->username.first,config->username.second);
    settings->setValue(config->password.first,config->password.second);
    settings->setValue(config->dbdir.first,config->dbdir.second);
    settings->setValue(config->dbtype.first,config->dbtype.second);
};

static void updateConfig(const LoginInitConfig&config)
{
    IniSettings * settings = new IniSettings (CONFIG_PATH);
    settings->setValue(config.ip.first,config.ip.second);
    settings->setValue(config.username.first,config.username.second);
    settings->setValue(config.password.first,config.password.second);
    settings->setValue(config.dbdir.first,config.dbdir.second);
    settings->setValue(config.dbtype.first,config.dbtype.second);
};

#endif
