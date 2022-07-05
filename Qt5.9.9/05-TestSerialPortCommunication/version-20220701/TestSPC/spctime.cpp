#include "spctime.h"
SPCTime::SPCTime() : now(QTime::currentTime())
{
  // qDebug()<<now.toString("hh mm ss zzz");
}
