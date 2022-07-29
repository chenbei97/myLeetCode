#include "TestOneQWaitConditionBase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestOneQWaitConditionBase w;
    w.show();
    return a.exec();
}
