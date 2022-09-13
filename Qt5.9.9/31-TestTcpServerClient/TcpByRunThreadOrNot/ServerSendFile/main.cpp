//#include "dialog.h"
#include "newdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Dialog w;
    NewDialog w;
    w.show();
    return a.exec();
}
