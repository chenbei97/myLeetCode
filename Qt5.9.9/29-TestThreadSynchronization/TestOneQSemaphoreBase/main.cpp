#include "TestOneQSemaphoreBase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestOneQSemaphoreBase w;
    w.show();
    return a.exec();
}
