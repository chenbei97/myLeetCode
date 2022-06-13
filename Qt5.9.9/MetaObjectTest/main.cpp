#include "qmetaobjecttest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QMetaObjectTest w;
  w.show();
  return a.exec();
}
