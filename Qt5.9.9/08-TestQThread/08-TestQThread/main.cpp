#include "testQThread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestQThread w;
    w.show();
    return a.exec();
}
