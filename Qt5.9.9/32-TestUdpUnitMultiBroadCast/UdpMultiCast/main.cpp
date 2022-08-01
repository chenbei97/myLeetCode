#include "UdpMultiCast.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  UdpMultiCast w;
  w.show();
  return a.exec();
}
