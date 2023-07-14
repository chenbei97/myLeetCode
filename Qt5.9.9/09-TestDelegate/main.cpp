#include "testDelegate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestDelegate w;
  w.show();
  return a.exec();
}
