#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWidget>

class customGraphicsView :public QGraphicsView
{
  Q_OBJECT
public:
  customGraphicsView(QWidget *parent = 0);

protected: // 定义自己的鼠标事件,然后把鼠标坐标的4个信号发射出去,因为QGraphicsView本身没有这样的信号
  void mouseMoveEvent(QMouseEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseDoubleClickEvent(QMouseEvent *event);
  void keyPressEvent(QKeyEvent *event);
signals:
  void mouseMovePoint(QPoint point); // 鼠标移动事件
  void mouseClicked(QPoint point); // 单击事件
  void mouseDoubleClick(QPoint point); //双击事件
  void keyPress(QKeyEvent *event); //按键事件
};

#endif // CUSTOMGRAPHICSVIEW_H
