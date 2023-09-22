#ifndef VIEWCIRCLE_H
#define VIEWCIRCLE_H

#include "../public.h"

class COMPONENT_IMEXPORT ViewCircle : public QWidget
{
    Q_OBJECT
public:
    explicit ViewCircle(int views = 1);

    int view() const;
    void setView(int view);
    bool viewValid(int view) const;


    double getRadius() const;
    double getLength() const;

    QPointF getCenter() const;
    QPointF getTopLeft() const;
    QPointF getTopRight() const;
    QPointF getBottomLeft() const;
    QPointF getBottomRight() const;

    QPointFVector verticalLineTopPoints() const ;
    QPointFVector verticalLineBottomPoints() const ;
    QPointFVector horizonalLineLeftPoints() const ;
    QPointFVector horizonalLineRightPoints() const ;

    double getChildLength() const;
    QRectmap getChildRects() const;
    QPointmap getChildCenterPoints() const;

    QPoint currentMousePoint() const;// 这个是鼠标选中的点
    void clearMousePoint();
    void setMouseEvent(bool enable);

    void setRect(int row,int col,bool selected);
    void selectRects(QCPointVector points);
    void clearRect(int row,int col);
    void clearRects();
    void setSelectEvent(bool enable);

    void enableEvent();
    void disableEvent();
private:
    void init();
    void drawBorder(QPainter &painter);
    void drawLine(QPainter &painter);
    void drawMousePoint(QPainter &painter);
    void drawSelectedPoints(QPainter &painter);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    int mView;
    bool mViewIsSquare;
    bool mMouseEvent;
    bool mSelectEvent;
    QPoint mMousePos;
    QColor mMouseColor;
    QColor mSelectedColor;
    QMaskmap mSelectedRects;

signals:
    void mouseClicked(const QPointF&point);
signals:

};

#endif // VIEWCIRCLE_H
