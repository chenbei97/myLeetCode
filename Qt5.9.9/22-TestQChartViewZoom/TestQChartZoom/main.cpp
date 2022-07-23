#include "TestQChartZoom.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec * code = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(code);
    QApplication a(argc, argv);
    TestQChartZoom w;
    w.show();
    return a.exec();
}
