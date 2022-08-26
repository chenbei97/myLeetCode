#include "UDPServer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDPServer w;
    w.show();
    return a.exec();
}
