#include "testserialport.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestSerialPort w;
  w.show();
  return a.exec();
}
