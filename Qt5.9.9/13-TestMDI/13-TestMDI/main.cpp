#include "TestMDI.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestMDI w;
    w.show();
    return a.exec();
}
