#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWidget>

class customGraphicsView :public QGraphicsView
{
  Q_OBJECT
public:
  customGraphicsView(QWidget *parent = 0);

protected: // 定义自己的鼠标事件,然后把鼠标坐标的2个信号发射出去,因为QGraphicsView本身没有这样的信号
  void mouseMoveEvent(QMouseEvent *event);
  void mousePressEvent(QMouseEvent *event);
signals:
  void mouseMovePoint(QPoint point);
  void mouseClicked(QPoint point);
};

#endif // CUSTOMGRAPHICSVIEW_H
