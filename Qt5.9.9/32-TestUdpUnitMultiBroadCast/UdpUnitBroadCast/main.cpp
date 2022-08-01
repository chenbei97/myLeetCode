#include "UdpUnitBroadCast.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  UdpUnitBroadCast w;
  w.show();
  return a.exec();
}
