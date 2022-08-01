#include "TestNetWorkHttp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestNetWorkHttp w;
  w.show();
  return a.exec();
}
