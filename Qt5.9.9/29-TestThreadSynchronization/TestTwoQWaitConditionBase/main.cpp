#include "TestTwoQWaitConditionBase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestTwoQWaitConditionBase w;
    w.show();
    return a.exec();
}
