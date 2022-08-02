#include "TestQMediaPlayer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestQMediaPlayer w;
  w.show();
  return a.exec();
}
