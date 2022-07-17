#include "TestDataStream.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{

    QTextCodec *codec = QTextCodec::codecForName("GB18030"); //GBK,GB2312
    QTextCodec::setCodecForLocale(codec); //解决汉字乱码问题

    QApplication a(argc, argv);
    TestDataStream w;
    w.show();
    return a.exec();
}
