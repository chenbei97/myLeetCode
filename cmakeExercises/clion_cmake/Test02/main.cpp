#include <QApplication>
#include "label/label.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    label l("123");

    l.show();
    return QApplication::exec();
}
