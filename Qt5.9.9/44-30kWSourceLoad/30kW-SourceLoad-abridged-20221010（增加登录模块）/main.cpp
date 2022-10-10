#include <mainwindow.h>
#include <QApplication>
#include <QTextCodec>
#include <login/login.h>

int main(int argc, char *argv[])
{
      qRegisterMetaType<WORKMODE>("WORKMODE");
      qRegisterMetaType<TIMEOUTCODE>("TIMEOUTCODE");
      qRegisterMetaType<SERIALERROR>("SERIALERROR");
      qRegisterMetaType<SETTINGVARIABLE>("SETTINGVARIABLE");
      qRegisterMetaType<TCPERRORSTATE>("TCPERRORSTATE");
      QTextCodec * codec = QTextCodec::codecForName("GBK");
      QTextCodec::setCodecForLocale(codec);
      QApplication a(argc, argv);
      Login * login = new Login;
      if (login->exec() == QDialog::Accepted)
      {
            MainWindow w;
            w.show();
            return a.exec();
      }
      else return 0;
}
