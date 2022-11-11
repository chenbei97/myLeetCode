#include <pytest/pytest_intro_test.h> // 引入python和package测试
#include <pytest/pytest_useful_macro_test.h> // Python.h提供的宏测试
#include <pytest/pytest_tool_test.h> // 工具层测试:导入模块+解析参数并构建值变量+字符串转换与格式化
#include <pytest/pytest_agreement_test.h> // 协议层测试: 对象协议+数字协议+序列协议+映射协议+迭代器协议
#include <pytest/pytest_spec_objlayer_test.h> // 具体对象层测试
#include <mainwindow.h>
#include <QApplication>
#include <QTextCodec>
#include <QProcess>
#include <login/login.h>

QTranslator *translator=Q_NULLPTR;

int main(int argc, char *argv[])
{
        //test_intro(INTRO_TEST::PackageTest);
        //test_useful_macro(USEFULLMACRO_TEST::UsefullMacroTest);
        test_tool(TOOL_TEST::ArgTest);
        //test_agreement(AGREEMENT_TEST::IterAgreement);
        //test_specobj_layer(DATATYPE_TEST::TupleTest);

//      QApplication a(argc, argv);

//      qRegisterMetaType<WORKMODE>("WORKMODE");
//      qRegisterMetaType<TIMEOUTCODE>("TIMEOUTCODE");
//      qRegisterMetaType<SERIALERROR>("SERIALERROR");
//      qRegisterMetaType<SETTINGVARIABLE>("SETTINGVARIABLE");
//      qRegisterMetaType<TCPERRORSTATE>("TCPERRORSTATE");

//      QTextCodec * codec = QTextCodec::codecForName("GBK");
//      QTextCodec::setCodecForLocale(codec);

//      translator = new QTranslator;
//      QSettings settings(QStringLiteral("WWB-Qt"),QCoreApplication::applicationName());//创建设置
//      QString Language=settings.value(QStringLiteral("language"),QStringLiteral("cn")).toString();//读取language键的值,如果为空首次进入默认使用cn
//       Language == QStringLiteral("cn")? translator->load(QStringLiteral(":/cn.qm")):translator->load(QStringLiteral(":/en.qm"));
//       a.installTranslator(translator);

//      Login * login = new Login; // 带登录模块
//      if (login->exec() == QDialog::Accepted)
//      {
//          MainWindow w(Q_NULLPTR,Language==QStringLiteral("cn")?MainWindow::Lanuage::CN:MainWindow::Lanuage::EN);
//          w.show();
//          int ret = a.exec();
//          if (ret == 773) { // exit(773)时重启,这个在切换语言中使用
//              QProcess::startDetached(qApp->applicationFilePath(), QStringList());
//          }
//          return ret;
//      }
//      else return 0;

        // 不带登录模块
//        MainWindow w(Q_NULLPTR,Language==QStringLiteral("cn")?MainWindow::Lanuage::CN:MainWindow::Lanuage::EN);
//        w.show();
//        int ret = a.exec();
//        if (ret == 773) { // exit(773)时重启,这个在切换语言中使用
//            QProcess::startDetached(qApp->applicationFilePath(), QStringList());
//        }
//        return ret;

}

