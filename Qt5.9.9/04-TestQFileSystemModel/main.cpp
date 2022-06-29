#include "testqfilesystemmodel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestQFileSystemModel w;
    w.show();
    return a.exec();
}
