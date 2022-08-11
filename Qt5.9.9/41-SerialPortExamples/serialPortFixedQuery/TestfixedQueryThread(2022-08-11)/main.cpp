#include "TestfixedQueryThread.h"
#include "Log.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  myLOG::logInit();
  QApplication a(argc, argv);
  TestfixedQueryThread w;
  w.show();
  return a.exec();
}
