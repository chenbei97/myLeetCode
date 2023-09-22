#include <QApplication>
#include <QPushButton>
#include "inc/component/label.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Label label("hello world");
    label.show();
    return QApplication::exec();
}
