#include "TestTRTranslation.h"
#include <QApplication>
#include <QTranslator>
#include <QSettings>
#include <QDebug>
QTranslator *trans=Q_NULLPTR;
QString readSetting();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    trans=new QTranslator;
    QString curLang=readSetting(); //读取语言设置
    qDebug()<<curLang;
    if (curLang=="EN")
          trans->load(":/TestTRTranslation_en.qm");
    else
         trans->load(":/TestTRTranslation_cn.qm");
     if (!trans) qDebug()<<"load failed";
    a.installTranslator(trans);
    TestTRTranslation w;
    w.show();
    return a.exec();
}

QString readSetting()
{//从注册表读取上次设置的语言
    QString organization="WWB-Qt";//用于注册表，
    QString appName= QCoreApplication::applicationName(); //HKEY_CURRENT_USER/WWB-Qt/appName
    QSettings settings(organization,appName);//创建
    QString Language=settings.value("Language","EN").toString();//读取 saved键的值
    return  Language;
}
