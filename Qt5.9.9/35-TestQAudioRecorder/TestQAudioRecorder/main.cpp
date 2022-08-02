#include "TestQAudioRecorder.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  TestQAudioRecorder w;
  w.show();
  return a.exec();
}
