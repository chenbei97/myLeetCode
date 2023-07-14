#include "TestStandardDialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestStandardDialog w;
  w.show();
  return a.exec();
}
