#include "TestQPainter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestQPainter w;
  w.show();
  return a.exec();
}
