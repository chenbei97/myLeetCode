#include "serialClient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  serialClient w;
  w.show();
  return a.exec();
}
