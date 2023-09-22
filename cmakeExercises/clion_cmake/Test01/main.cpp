#include <QApplication>
#include <QPushButton>
//#include "component/inc/label.h"
#include "widgets/label.h"
#include "hello.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Label label("太厉害啦");
    label.show();
    qDebug()<<getStrings();
    return QApplication::exec();
}
