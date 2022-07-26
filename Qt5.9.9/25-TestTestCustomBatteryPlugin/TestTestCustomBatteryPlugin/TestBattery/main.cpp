#include "TestBattery.h"

#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec * c = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(c);
    QApplication a(argc, argv);
    TestBattery w;
    w.show();
    return a.exec();
}
