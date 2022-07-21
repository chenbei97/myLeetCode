#include "customGraphicsView.h"
#include    <QMouseEvent>
#include    <QPoint>

customGraphicsView::customGraphicsView(QWidget*parent):QGraphicsView(parent)
{

}

//鼠标移动事件
void customGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point=event->pos(); // 获取鼠标的坐标
    emit mouseMovePoint(point); //释放信号
    QGraphicsView::mouseMoveEvent(event);// 事件转交给基类QGraphicsView
}

//鼠标左键按下事件
void customGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton) // 左键被按下
    {
        QPoint point=event->pos(); //获取鼠标坐标
        emit mouseClicked(point);//释放信号
    }
    QGraphicsView::mousePressEvent(event);// 事件转交给基类QGraphicsView
}
