#include "teststandarditemmodel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestStandardItemModel w;
    w.show();
    return a.exec();
}
