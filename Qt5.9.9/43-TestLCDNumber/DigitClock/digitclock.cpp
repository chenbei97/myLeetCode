#include "digitclock.h"
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QMouseEvent>

DigitClock::DigitClock(QWidget *parent)
  : QLCDNumber(parent)
{
      QPalette p = this->palette();
      p.setColor(QPalette::Window,Qt::blue);
      this->setPalette(p);

      this->setWindowFlags(Qt::FramelessWindowHint);
      this->setWindowOpacity(0.5);

      QTimer * t = new QTimer(this);
      connect(t,SIGNAL(timeout()),this,SLOT(showTime()));
      t->start(1000);
      this->showTime();//先调用一次
      this->resize(150,60);
      this->showColon = true;
}

DigitClock::~DigitClock()
{

}

void DigitClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm"); // 时分
    qDebug()<<text; //"14:28"
    if (showColon)
    {
        text[2] = ':';
        showColon = false;
    }
    else{
        text[2] = ' ';
        showColon = true;
    }
    display(text);
}

void DigitClock::mouseMoveEvent(QMouseEvent *e)
{
      if (e->buttons() & Qt::LeftButton)
       {
           this->move(e->globalPos() - dragPosition);
           e->accept();
       }
}

void DigitClock::mousePressEvent(QMouseEvent *e)
{
      if (e->button() == Qt::LeftButton)
      {
          dragPosition = e->globalPos()-frameGeometry().topLeft();
          e->accept();
      }
      if (e->button() == Qt::RightButton)
            close();
}
