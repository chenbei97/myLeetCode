#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
      qRegisterMetaType<WORKMODE>("WORKMODE");
      qRegisterMetaType<TIMEOUTCODE>("TIMEOUTCODE");
      qRegisterMetaType<SERIALERROR>("SERIALERROR");
      qRegisterMetaType<SETTINGVARIABLE>("SETTINGVARIABLE");
      QTextCodec * codec = QTextCodec::codecForName("GBK");
      QTextCodec::setCodecForLocale(codec);
      QApplication a(argc, argv);
      MainWindow w;
      w.show();
      return a.exec();
}
