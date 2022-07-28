#include "TestQMutexBased.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestQMutexBased w;
    w.show();
    return a.exec();
}
