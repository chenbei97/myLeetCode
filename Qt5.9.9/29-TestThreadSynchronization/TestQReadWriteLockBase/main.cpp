#include "TestQReadWriteLockBase.h"

#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec * c = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(c);
    QApplication a(argc, argv);
    TestQReadWriteLockBase w;
    w.show();
    return a.exec();
}
