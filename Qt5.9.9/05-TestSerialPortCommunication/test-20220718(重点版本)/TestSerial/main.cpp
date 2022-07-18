#include "TestSerial.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestSerial w;
  w.show();
  return a.exec();
}
