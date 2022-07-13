#include "serialPortCommunication.h"

#include <QApplication>
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  SerialPortCommunication w;
  w.show();
  return a.exec();
}
