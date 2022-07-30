#include "TestHostInformationQuery.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestHostInformationQuery w;
    w.show();
    return a.exec();
}
