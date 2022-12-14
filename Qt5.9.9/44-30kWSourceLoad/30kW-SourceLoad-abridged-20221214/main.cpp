#include <test/test.h>
#include <mainwindow.h>
#include <login/login.h>
#include <QApplication>
#include <QTextCodec>
#include <QProcess>

QTranslator *translator=Q_NULLPTR;

int main(int argc, char *argv[])
{

      QApplication a(argc, argv);
      qRegisterMetaType<LANUAGE>("LANUAGE");
      qRegisterMetaType<WORKMODE>("WORKMODE");
      qRegisterMetaType<TIMEOUTCODE>("TIMEOUTCODE");
      qRegisterMetaType<SERIALERROR>("SERIALERROR");
      qRegisterMetaType<SETTINGVARIABLE>("SETTINGVARIABLE");
      qRegisterMetaType<TCPERRORSTATE>("TCPERRORSTATE");

      QTextCodec * codec = QTextCodec::codecForName("GBK");
      QTextCodec::setCodecForLocale(codec);

      translator = new QTranslator;
      QSettings settings(QStringLiteral("WWB-Qt"),QCoreApplication::applicationName());//创建设置
      QString Language=settings.value(QStringLiteral("language"),QStringLiteral("cn")).toString();//读取language键的值,如果为空首次进入默认使用cn
       Language == QStringLiteral("cn")? translator->load(QStringLiteral(":/cn.qm")):translator->load(QStringLiteral(":/en.qm"));
       a.installTranslator(translator);

//      Login * login = new Login; // 带登录模块
//      if (login->exec() == QDialog::Accepted)
//      {
//          MainWindow w(Q_NULLPTR,Language==QStringLiteral("cn")?LANUAGE ::CN:LANUAGE ::EN);
//          w.show();
//          int ret = a.exec();
//          if (ret == 773) { // exit(773)时重启,这个在切换语言中使用
//              QProcess::startDetached(qApp->applicationFilePath(), QStringList());
//          }
//          return ret;
//      }
//      else return 0;

        //AllTest::pytest();
        //AllTest::csv_test();
        AllTest::concurrent_test();
        //AllTest::listFiles_test();
        return 0;
        // 不带登录模块
//        MainWindow w(Q_NULLPTR,Language==QStringLiteral("cn")?LANUAGE ::CN:LANUAGE ::EN);
//        w.show();
//        int ret = a.exec();
//        if (ret == 773) { // exit(773)时重启,这个在切换语言中使用
//            QProcess::startDetached(qApp->applicationFilePath(), QStringList());
//        }
//        return ret;
}

