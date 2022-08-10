#include "serialServer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serialServer w;
    w.show();
    return a.exec();
}
