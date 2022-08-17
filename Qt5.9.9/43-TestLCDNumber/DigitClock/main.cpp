#include "digitclock.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  DigitClock w;
  w.show();
  return a.exec();
}
