#include "customChartView.h"

customChartView::customChartView(QWidget*parent):QChartView(parent)
{
        this->setDragMode(QGraphicsView::RubberBandDrag); // �϶�ʱ���ֵ������߾��ο���ʽ
        this->setMouseTracking(true);//������Ϊtrue,��������ƶ�ʱ��Ӧ������
}

// 1. ����������¼�
void customChartView::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
         this->beginPoint=event->pos(); // ��¼λ��
    QChartView::mousePressEvent(event);
}

// 2. �������ͷ��¼�
void customChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    { //�������ͷţ���ȡ���ο��endPoint,��������
        this->endPoint=event->pos();
        QRectF  rectF;
        rectF.setTopLeft(this->beginPoint);
        rectF.setBottomRight(this->endPoint);
        this->chart()->zoomIn(rectF);//������ѡ�еķ�Χ
    }
    else if (event->button()==Qt::RightButton)
        this->chart()->zoomReset(); //����Ҽ��ͷţ�resetZoom
    QChartView::mouseReleaseEvent(event);
}

// 3. ����ƶ��¼�
void customChartView::mouseMoveEvent(QMouseEvent*event)
{
    QPoint  point;
    point=event->pos();

    emit mouseMovePoint(point);
    QChartView::mouseMoveEvent(event);
}

// 4. ���̰����¼�
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
           chart()->scroll(10, 0); //����dx����
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




