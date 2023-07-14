#include "teststringlistmodel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestStringListModel w;
    w.show();
    return a.exec();
}
