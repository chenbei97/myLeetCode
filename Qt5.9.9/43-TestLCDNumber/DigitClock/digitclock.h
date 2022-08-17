#ifndef DIGITCLOCK_H
#define DIGITCLOCK_H

#include <QDialog>
#include <QLCDNumber>
class DigitClock : public QLCDNumber
{
  Q_OBJECT
public:
  DigitClock(QWidget *parent = nullptr);
  ~DigitClock();
protected:
  void mousePressEvent(QMouseEvent*e);
  void mouseMoveEvent(QMouseEvent*e);
public slots:
  void showTime();
private:
  QPoint dragPosition;
  bool showColon;// 时分之间的冒号每秒显示1次,有嘀嗒的效果
};
#endif // DIGITCLOCK_H
