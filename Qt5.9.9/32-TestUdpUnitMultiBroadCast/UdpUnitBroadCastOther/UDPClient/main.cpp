#include "UDPClient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
      QApplication a(argc, argv);
      UDPClient w;
      w.show();
      return a.exec();
}
