#ifndef SORTPOINT_H
#define SORTPOINT_H

#include "qpoint.h"
#include "qvector.h"

typedef  QVector<QPoint> QPointlist;
typedef  const QPointlist& QCPointlist;

static bool pointAscendFunc(const QPoint&p1,const QPoint&p2)
{
    if (p1.x()<p2.x()) return true;
    else if (p1.x() == p2.x()) return p1.y()<=p2.y();
    else return false;
}

static void sortPointAscending(QPointlist& points)
{
    qSort(points.begin(), points.end(), pointAscendFunc);
}

static bool pointDescendFunc(const QPoint&p1,const QPoint&p2)
{
    if (p1.x()<p2.x()) return false;
    else if (p1.x() == p2.x()) return p1.y()>=p2.y();
    else return true;
}

static void sortPointDescending(QPointlist& points)
{
    qSort(points.begin(), points.end(), pointDescendFunc);
}
#endif // SORTPOINT_H
