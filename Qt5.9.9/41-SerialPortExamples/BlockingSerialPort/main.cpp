#include "BlockingSerialPort.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  BlockingSerialPort w;
  w.show();
  return a.exec();
}
