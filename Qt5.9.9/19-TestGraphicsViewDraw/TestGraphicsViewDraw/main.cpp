#include "TestGraphicsViewDraw.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestGraphicsViewDraw w;
  w.show();
  return a.exec();
}
