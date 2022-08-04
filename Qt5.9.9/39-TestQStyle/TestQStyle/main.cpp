#include "TestQStyle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestQStyle w;
  w.show();
  return a.exec();
}
