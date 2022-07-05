#ifndef SPCTIME_H
#define SPCTIME_H
#include <QTime>
#include <QDebug>
class SPCTime
{
public:
  SPCTime();
    friend double operator-(const SPCTime  &lhs,const SPCTime  & rhs);
  private:
    QTime now ;
  };
  inline double operator-(const SPCTime  &lhs,const SPCTime  &rhs)
  {
    // 只需要s和ms的格式即可
    QString t1 = lhs.now.toString("ss zzz"), t2 = rhs.now.toString("ss zzz");
    qDebug()<<t1<<" "<<t2;
    //qDebug()<<t1.right(3).toDouble()<<"  "<<t2.right(3).toDouble();
    double diff = t1.right(3).toDouble() - t2.right(3).toDouble() +  // ms
        (t1.left(2).toDouble()-t2.left(2).toDouble()) * 1000.0 ; // s -> ms
    //qDebug()<<diff;
    return diff;
};

#endif // SPCTIME_H
