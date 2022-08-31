#ifndef AREA_H
#define AREA_H
#include <QObject>

class Area: public QObject
{
      Q_OBJECT
public:
      Area(){}
      Area(const Area& area)
      {
            radius = area.radius;
      }
      Area(double r)
      {
          radius = r;
      }
      double countArea()
      {
          return 3.14 * radius * radius;
      }
private:
      double radius;
};
Q_DECLARE_METATYPE(Area) //解释为元对象类型
#endif // AREA_H
