#include "../../inc/widgets/viewcircle.h"

ViewCircle::ViewCircle(int view):mView(view)
{ // view是实际视野数的平方根
    init();
}

void ViewCircle::mousePressEvent(QMouseEvent *event)
{
    if (mMouseEvent) {
        auto pos = event->pos();
        auto rects = getChildRects();

        bool posValid = false;
        for(int row = 0; row < mView; ++row)
             for(int col = 0; col < mView; ++col)
                 if (rects[row][col].contains(pos)) {
                     mMousePos = {row,col};
                     posValid = true;
                     break;
                 }
        if (!posValid) {
            mMousePos = {-1,-1};
        }
        emit mouseClicked(mMousePos);
        update();
    }
    event->accept();
}

void ViewCircle::drawBorder(QPainter &painter)
{
    auto radius = getRadius();
    auto center = getCenter();
    painter.drawEllipse(center,radius,radius);
    painter.drawRect(QRectF(getTopLeft(),getBottomRight()));
}

void ViewCircle::drawLine(QPainter &painter)
{
    if (mView == 1) return;

    auto tops = verticalLineTopPoints();
    auto bottoms = verticalLineBottomPoints();
    auto lefts = horizonalLineLeftPoints();
    auto rights = horizonalLineRightPoints();

    for(int i = 0; i < mView - 1; i++) {
        painter.drawLine(tops.at(i),bottoms.at(i));
        painter.drawLine(lefts.at(i),rights.at(i));
    }
}

void ViewCircle::drawMousePoint(QPainter &painter)
{
    auto rects = getChildRects();
    for(int row = 0 ; row < mView; ++ row) {
        for(int col = 0; col < mView; ++ col ) {
            if (mMousePos.x() == row && mMousePos.y() == col){
                auto rect = rects[row][col];
                painter.fillRect(rect,mMouseColor);
            }
        }
    }
}

void ViewCircle::drawSelectedPoints(QPainter &painter)
{
    auto rects = getChildRects();
    for(int row = 0 ; row < mView; ++ row) {
        for(int col = 0; col < mView; ++ col ) {
            if (mSelectEvent &&mSelectedRects[row][col]){
                auto rect = rects[row][col];
                painter.fillRect(rect,mSelectedColor);
            }
        }
    }
}

void ViewCircle::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    auto pen = painter.pen();
    pen.setWidth(3);
    painter.setPen(pen);

    drawBorder(painter);
    if (mViewIsSquare){
        drawLine(painter);
        //drawMousePoint(painter); // 视野的位置不需要选,所以这里不再需要了注释掉
        //drawSelectedPoints(painter);
    } else {
        if (mView == 2) {
            auto topleft = getTopLeft();
            auto left = topleft + QPointF(0,getLength()/2);
            auto right = left + QPointF(getLength(),0);
            painter.drawLine(left,right);
        }
    }

//    pen = painter.pen();
//    pen.setColor(Qt::red);
//    painter.setPen(pen);
//    foreach(auto pts, getChildCenterPoints()) {
//        foreach(auto pt,pts)
//            painter.drawPoint(pt);
//    }
    event->accept();
}

void ViewCircle::init()
{
    mViewIsSquare = true;
    mMouseEvent = false;
    mSelectEvent = false;
    mMousePos = {-1,-1};
    mMouseColor = Qt::green;
    mSelectedColor = QColor("#F241FF");

    mMouseColor.setAlpha(100);
    mSelectedColor.setAlpha(100);
    clearRects();

}

double ViewCircle::getRadius() const
{
    int diameter = width()<=height()? width():height();
    return diameter / 2.0; // 较短边
}

double ViewCircle::getLength() const
{ // 边长为半径的根号2
    return getRadius() * 1.414213562373;
}

QPointF ViewCircle::getCenter() const
{
    return  QPointF(width()/2,height()/2);
}

QPointF ViewCircle::getTopLeft() const
{
    double offset = getRadius() * 0.70710678;
    return getCenter()+QPointF(-offset,-offset);
}

QPointF ViewCircle::getTopRight() const
{
    double offset = getRadius() * 0.70710678;
    return getCenter()+QPointF(offset,-offset);
}

QPointF ViewCircle::getBottomLeft() const
{
    double offset = getRadius() * 0.70710678;
    return getCenter()+QPointF(-offset,offset);
}

QPointF ViewCircle::getBottomRight() const
{
    double offset = getRadius() * 0.70710678;
    return getCenter()+QPointF(offset,offset);
}

QPointFVector ViewCircle::verticalLineTopPoints() const
{ // 垂直线顶部的等分点,即topLeft右侧的mViews-1个
    QPointFVector vec;
    auto offset = getChildLength();
    auto topleft = getTopLeft();
    for (int i = 1; i <= mView-1; ++i)
        vec.append(topleft+ QPointF(i*offset,0));
    return vec;
}

QPointFVector ViewCircle::verticalLineBottomPoints() const
{
    QPointFVector vec;
    auto offset = getChildLength();
    auto bottomleft = getBottomLeft();
    for (int i = 1; i <= mView-1; ++i)
        vec.append(bottomleft+ QPointF(i*offset,0));
    return vec;
}

QPointFVector ViewCircle::horizonalLineLeftPoints() const
{
    QPointFVector vec;
    auto offset = getChildLength();
    auto topleft = getTopLeft();
    for (int i = 1; i <= mView-1; ++i)
        vec.append(topleft+ QPointF(0,i*offset));
    return vec;
}

QPointFVector ViewCircle::horizonalLineRightPoints() const
{
    QPointFVector vec;
    auto offset = getChildLength();
    auto topright = getTopRight();
    for (int i = 1; i <= mView-1; ++i)
        vec.append(topright+ QPointF(0,i*offset));
    return vec;
}

double ViewCircle::getChildLength() const
{ // = 内接正方形边长等分后的长度
    return getLength()/ mView;
}

QRectmap ViewCircle::getChildRects() const
{
    if (mView == 1) return  {{QRectF(getTopLeft(),getBottomRight())}};

    QRectmap map;
    auto offset = getChildLength();
    auto start = getTopLeft();

    for(int i = 0 ; i < mView; ++i) {
        QRectVector vec;
        for(int j = 0; j < mView; ++j) { // j*offset加在x坐标也就是水平方向
            auto topleft = start + QPointF(j*offset,i*offset); // x, x+d，j依次取0,1; y先不变在后
            auto bottomright = topleft + QPointF(offset,offset);
            vec.append(QRectF(topleft,bottomright));
        }
        map.append(vec);
    }
    /*
        topleft (x,y) ,(x+d,y)              bottomright (x+d,y+d) ,(x+2d,y+d)
                    (x,y+d), (x+d,y+d)                       (x+d,y+2d), (x+2d,y+2d)
    */
    return map;
}

QPointmap ViewCircle::getChildCenterPoints() const
{
    if (mView == 1) return {{getCenter()}};

    QPointmap map;
    auto offset = getChildLength();
    auto start = getTopLeft();

    for(int i = 0 ; i < mView; ++i) {
        QPointFVector vec;
        for(int j = 0; j < mView; ++j) {
            auto topleft = start + QPointF(j*offset,i*offset);
            auto bottomright = topleft + QPointF(offset,offset);
            auto center = (topleft+bottomright)/2;
            vec.append(center);
        }
        map.append(vec);
    }

    return map;
}

int ViewCircle::view() const
{
    return mView;
}

static bool isSquare(unsigned int n) {
    unsigned int root = sqrt(n);
    return root * root == n;
}

void ViewCircle::setView(int view)
{
//    if (!viewValid(view)) return;
    if (isSquare(view)){
        mView = sqrt(view);
        mViewIsSquare = true;
    } else {
        mView = view;
        mViewIsSquare = false;
    }

    //LOG<<"view = "<<mView;
    clearMousePoint();
    clearRects();
    update();
}

QPoint ViewCircle::currentMousePoint() const
{
    return mMousePos;
}

void ViewCircle::clearMousePoint()
{
    mMousePos = QPoint(-1,-1);
    update();
}

void ViewCircle::setMouseEvent(bool enable)
{
    mMouseEvent = enable;
}

void ViewCircle::setRect(int row,int col,bool selected)
{
    if (!mSelectEvent) return;
    if (row < 0 || row > mView-1) return;
    if (col < 0 || col > mView-1) return;
    mSelectedRects[row][col] = selected;
    update();
}

void ViewCircle::selectRects(QCPointVector points)
{
    foreach(auto point,points)
        setRect(point.x(),point.y(),true);
}

void ViewCircle::clearRect(int row,int col)
{
    setRect(row,col,false);
}

void ViewCircle::clearRects()
{
    mSelectedRects.clear();
    for(int row = 0 ; row < mView; ++ row) {
        QVector<bool> var;
        for (int col = 0; col < mView; ++col){
            var.append(false);
        }
        mSelectedRects.append(var);
   }
}

void ViewCircle::setSelectEvent(bool enable)
{
    mSelectEvent = enable;
}

void ViewCircle::enableEvent()
{
    mMouseEvent = true;
    mSelectEvent = true;
}

void ViewCircle::disableEvent()
{
    mMouseEvent = false;
    mSelectEvent = false;
}

