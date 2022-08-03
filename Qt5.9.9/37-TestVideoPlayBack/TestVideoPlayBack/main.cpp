#include "TestVideoPlayBack.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestVideoPlayBack w;
  w.show();
  return a.exec();
}
