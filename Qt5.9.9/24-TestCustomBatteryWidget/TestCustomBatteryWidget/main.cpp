#include "TestCustomBatteryWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestCustomBatteryWidget w;
    w.show();
    return a.exec();
}
