#include "TestTwoQSemaphoreBase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestTwoQSemaphoreBase w;
    w.show();
    return a.exec();
}
