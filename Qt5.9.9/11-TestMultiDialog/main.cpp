#include "customDialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  customDialog w;
  w.show();
  return a.exec();
}
