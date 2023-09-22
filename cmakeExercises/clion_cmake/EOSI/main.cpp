
#include "qapplication.h"
#include "qprocess.h"
#include "initapp.h"

//#define onlymain 0
#define nottcp 0
#define loadpython 0
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<QSqlDatabase::drivers();
    qDebug()<<QImageReader::supportedImageFormats();
    a.setFont(QFont(DefaultFontFamily,DefaultFontSize));
    qRegisterMetaType<QList<int>>("QList<int>");
    qRegisterMetaType<TcpErrorCode>("TcpErrorCode");
    a.setWindowIcon(QApplication::style()->standardIcon(QStyle::SP_DesktopIcon));
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    //LOG<<"main thread is "<<QThread::currentThread();
    LOG<<"current path = "<<CURRENT_PATH;
#ifdef loadpython
    QProcess * process = new QProcess;
    QObject::connect(&a, &QCoreApplication::aboutToQuit, [process]() {
        process->close();
        process->waitForFinished();
        //    delete process; // 等价于kill()
        //    process = nullptr;
        process->kill();
        // QTimer::singleShot(0,process,SLOT(kill()));
        LOG<<"python process is kill? "<<!process->isOpen();
        //process->destroyed();
    });
    QObject::connect(process, &QProcess::readyReadStandardOutput,[&](){
        //qDebug()<<process.readAll();
        auto output = QString(process->readAllStandardOutput()); // 直接读读不到
        auto res = output.split("\r\n",QString::SkipEmptyParts);// 必须槽函数内才能读到
        //qDebug()<<res;
        //qDebug()<<process.readAll(); // 读完就没了
    });

    process->start("python",QStringList()<<(PYTHON_SCRIPT_PATH));
    process->waitForStarted();
    //QProcess::execute(QString("python %1 ").arg(PYTHON_SCRIPT_PATH));
#endif
#ifdef nottcp
#ifdef onlymain
     QFile f(QSS_PATH);
     f.open(QFile::ReadOnly | QFile::Text);
     QTextStream ts(&f);
     qApp->setStyleSheet(ts.readAll());
#endif

#ifdef onlymain
    MainWindow w;
    w.show();
#else
    InitAppController controller;
    controller.apply();
#endif
#else
    TestTcp w;
    w.show();

#endif
    return a.exec();
}
