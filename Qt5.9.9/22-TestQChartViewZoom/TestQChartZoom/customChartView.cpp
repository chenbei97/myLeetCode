#include "customChartView.h"

customChartView::customChartView(QWidget*parent):QChartView(parent)
{
        this->setDragMode(QGraphicsView::RubberBandDrag); // 拖动时出现的是虚线矩形框样式
        this->setMouseTracking(true);//必须设为true,否则鼠标移动时响应不出来
}

// 1. 鼠标左键点击事件
void customChartView::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
         this->beginPoint=event->pos(); // 记录位置
    QChartView::mousePressEvent(event);
}

// 2. 鼠标左键释放事件
void customChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    { //鼠标左键释放，获取矩形框的endPoint,进行缩放
        this->endPoint=event->pos();
        QRectF  rectF;
        rectF.setTopLeft(this->beginPoint);
        rectF.setBottomRight(this->endPoint);
        this->chart()->zoomIn(rectF);//扩大至选中的范围
    }
    else if (event->button()==Qt::RightButton)
        this->chart()->zoomReset(); //鼠标右键释放，resetZoom
    QChartView::mouseReleaseEvent(event);
}

// 3. 鼠标移动事件
void customChartView::mouseMoveEvent(QMouseEvent*event)
{
    QPoint  point;
    point=event->pos();

    emit mouseMovePoint(point);
    QChartView::mouseMoveEvent(event);
}

// 4. 键盘按键事件
void customChartView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
       case Qt::Key_Plus:  //+
           chart()->zoom(1.2);
           break;
       case Qt::Key_Minus:
           chart()->zoom(0.8);
           break;
       case Qt::Key_Left:
           chart()->scroll(10, 0); //滚动dx距离
           break;
       case Qt::Key_Right:
           chart()->scroll(-10, 0);
           break;
       case Qt::Key_Up:
           chart()->scroll(0, -10);
           break;
       case Qt::Key_Down:
           chart()->scroll(0, 10);
           break;
       case Qt::Key_PageUp:
           chart()->scroll(0, 50);
           break;
       case Qt::Key_PageDown:
           chart()->scroll(0, -50);
           break;
       case Qt::Key_Home:
           chart()->zoomReset();
           break;
       default:
           QGraphicsView::keyPressEvent(event);
       }
}




