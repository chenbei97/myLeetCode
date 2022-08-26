#include "TCPServer.h"
#include <QTextCodec>
#include <QApplication>

int main(int argc, char *argv[])
{
    QTextCodec * codec = QTextCodec::codecForName("GBK");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
    TCPServer w;
    w.show();
    return a.exec();
}
