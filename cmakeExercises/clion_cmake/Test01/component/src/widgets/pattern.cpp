#include "../../inc/widgets/pattern.h"

Pattern::Pattern() :mRow(1),mCol(1)
{
    init();
}

Pattern::Pattern(int rows, int cols):mRow(rows),mCol(cols)
{
  init();
}

Pattern::Pattern(const QSize&size):mRow(size.width()),mCol(size.height())
{
    init();
}

Pattern& Pattern::operator=(const Pattern&pattern)
{
    copy(pattern);
    return *this;
}

Pattern::Pattern(const Pattern&pattern)
{
    copy(pattern);
}

Pattern::Pattern(const Pattern*pattern)
{
    copy(*pattern);
}

void Pattern::toggleState(PatternState state)
{
    mState = state;
    switch (mState) {
        case BlankState:
            disableClick();
            disableZoom();
            disableSelect();
            disableGroup();
            break;
    case TickState:
            enableClick();
            enableZoom();
            enableSelect();
            disableGroup();
            break;
    case SelectedState:
            disableClick();
            disableZoom();
            enableSelect();
            disableGroup();
            break;
    case GroupState:
            enableClick();
            disableZoom();
            disableSelect();
            enableGroup();
            break;
    case GroupWithoutClickState:
            disableClick();
            disableZoom();
            disableSelect();
            enableGroup();
            break;
    }
}

Pattern::PatternState Pattern::state() const
{
    return mState;
}

void Pattern::setPatternSize(int rows,int cols)
{
    mRow = rows;
    mCol = cols;
    mSelectedPoints.clear();
    mGroupmap.clear();
    for(int row = 0 ; row < mRow; ++ row) {
        QVector<bool> var1;
        QVector<int> var2;
        for (int col = 0; col < mCol; ++col) {
            var1.append(false);
            var2.append(-1);
        }
        mSelectedPoints.append(var1);
        mGroupmap.append(var2);
   }
    updateMinSize();
    update();
}

void Pattern::setPatternSize(const QSize& size)
{
    setPatternSize(size.width(),size.height());
}

void Pattern::copy(const Pattern&pattern)
{
    mRow = pattern.mRow;
    mCol = pattern.mCol;

    mGap = pattern.mGap;
    mSpace = pattern.mSpace;
    mZoom = pattern.mZoom;
    mIsZoom = pattern.mIsZoom;
    mIsDrawRandomPoints = pattern.mIsDrawRandomPoints;
    mIsGroup = pattern.mIsGroup;
    mDrawPointsCount = pattern.mDrawPointsCount;
    mIsSelect = pattern.mIsSelect;
    mMouseEvent = pattern.mMouseEvent;
    mWheelEvent = pattern.mWheelEvent;
    mMousePos = pattern.mMousePos;
    mSignedPos = pattern.mSignedPos;

    mSelectedPoints = pattern.mSelectedPoints;
    mGroupmap = pattern.mGroupmap;
    mState = pattern.mState;

    mDefaultColor = pattern.mDefaultColor;
    mSelectedColor = pattern.mSelectedColor;
    mSignedColor = pattern.mSignedColor;
    mCurrentColor = pattern.mCurrentColor;
    mGroupColors = pattern.mGroupColors;

    INIT_FONT;
    updateMinSize();
    update();
    //LOG<<"pattern copy constructor is called, rows= "<<mRow<<" cols = "<<mCol;
}

void Pattern::init()
{
    for(int row = 0 ; row < mRow; ++ row) {
        QVector<bool> var1;
        QVector<int> var2;
        for (int col = 0; col < mCol; ++col){
            var1.append(false);
            var2.append(-1);
        }
        mSelectedPoints.append(var1);
        mGroupmap.append(var2);
   }
   mGap = 30;
   mSpace = 10;
   mZoom = 1.0;
   mIsSelect = false;
   mIsDrawRandomPoints = false;
   mIsGroup = false;
   mDrawPointsCount = 0;
   mMouseEvent = false;
   mWheelEvent = false;
   mState = BlankState;
   mMousePos = {-1,-1};
   mSignedPos = {-1,-1};
   mSelectedColor.setAlpha(PatternColorAlpha);
   mDefaultColor.setAlpha(PatternColorAlpha);
   mCurrentColor.setAlpha(PatternColorAlpha);
   mSignedColor.setAlpha(PatternColorAlpha);
   INIT_FONT;
   updateMinSize();
}

void Pattern::setSpacing(uint32_t space)
{
    mSpace = (double)space;
}

uint32_t Pattern::spacing() const
{
    return (uint32_t)mSpace;
}

void Pattern::setGap(uint32_t gap)
{
    mGap = (double)gap;
}

uint32_t Pattern::gap() const
{
    return (uint32_t)mGap;
}

void Pattern::mousePressEvent(QMouseEvent *event)
{
    if (mMouseEvent) {
        auto pos = event->pos();
        auto rects = getChildRects();

        for(int row = 0; row < mRow; ++row)
             for(int col = 0; col < mCol; ++col)
                 if (rects[row][col].contains(pos))
                     mMousePos = {row,col};
        //LOG<<"mMousePos = "<<mMousePos;
        update();
        emit mouseClicked(mMousePos);
    }
    event->accept();
}

QPoint Pattern::currentMousePoint() const
{
    return mMousePos;
}

void Pattern::clearMousePoint()
{
    mMousePos = QPoint(-1,-1);
    update();
}

void Pattern::wheelEvent(QWheelEvent *event)
{
        if (mWheelEvent) {
            if (event->angleDelta().y() > 0) mGap *= 0.9;
            else mGap *= 1.1;
    //        if (mGap < 1.0) mGap = 10.0;
            update();
        }
        event->accept();
}

void Pattern::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    auto pen = painter.pen();
    pen.setWidth(2);
    painter.setPen(pen);

    //drawBorder(painter);
    drawLine(painter);
    drawHeader(painter);
    drawHighlight(painter);
    drawSignedPoints(painter);
    drawRandomPoints(painter);

    event->accept();
}

void Pattern::drawHeader(QPainter &painter)
{
    auto pointSize = mRow>10? 8:DefaultFontSize;

    auto font = painter.font();
    font.setPointSize(pointSize);
    font.setFamily(DefaultFontFamily);
    painter.setFont(font);

    auto rowpts = getRowHeaderPoints();
    for(int col = 0 ; col < mCol; ++ col)
    {
        auto center = rowpts[col];
        painter.drawText(center,QString::number(col+1));
    }

    auto colpts = getColHeaderPoints();
    for(int row = 0 ; row < mRow; ++ row)
    {
        auto center = colpts[row];
        painter.drawText(center,QChar(row+65));
    }
}

void Pattern::drawSignedPoints(QPainter &painter)
{
    auto cell_size = getChildSize();
    int cell_w = cell_size.width();
    int cell_h = cell_size.height();
    int radius = cell_w>=cell_h? cell_h/2: cell_w/2;
    radius *= 0.75;

    auto pen = painter.pen();
    if (mRow > 12) pen.setWidth(1);
    else pen.setWidth(4);
    pen.setColor(mSignedColor);
    painter.setPen(pen);

    auto  centerPts = getCenterPoints();
    for(int row = 0 ; row < mRow; ++ row)
    {
        for(int col = 0; col < mCol; ++ col)
        {
            if (row == mSignedPos.x() && col == mSignedPos.y())
            {
                auto center = centerPts[row][col];
                auto top = center+QPointF(0,-radius);
                auto bottom = center+QPointF(0,radius);
                auto left = center+QPointF(-radius,0);
                auto right = center+QPointF(radius,0);
                auto topleft = center + QPointF(-radius*cos(RadianRate*45),-radius*cos(RadianRate*45));
                auto topright= center + QPointF(radius*cos(RadianRate*45),-radius*cos(RadianRate*45));
                auto bottomleft = center + QPointF(-radius*cos(RadianRate*45),radius*cos(RadianRate*45));
                auto bottomright = center + QPointF(radius*cos(RadianRate*45),radius*cos(RadianRate*45));

                painter.drawLine(top,bottom);
                painter.drawLine(left,right);
                painter.drawLine(topleft,bottomright);
                painter.drawLine(topright,bottomleft);
                painter.drawEllipse(center,radius,radius);
            }
        }
    }
}

void Pattern::drawRandomPoints( int count)
{
    mDrawPointsCount= count;
    mIsDrawRandomPoints = true;
    update();
}

void Pattern::disableDrawRandomPoints()
{
    mDrawPointsCount = 0;
    mIsDrawRandomPoints = false;
    update();
}

void Pattern::drawRandomPoints(QPainter &painter)
{
    if (!mIsDrawRandomPoints) return;

    auto pen = painter.pen();
    if (mRow > 12) pen.setWidth(1);
    else pen.setWidth(8);
    pen.setColor(Qt::white);//"#782DFF"
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    auto cell = getChildSize();
    int radius = cell.width()>=cell.height()? cell.height()/2: cell.width()/2;
    auto centers = getCenterPoints();
    radius *= 0.5;
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    for(int row = 0 ; row < mRow; ++ row){
        for(int col = 0; col < mCol; ++ col) {
            if (mState == SelectedState)
                if (mSelectedPoints[row][col]) {
                    for(int i = 0; i< mDrawPointsCount; ++i) {
                        auto center = centers[row][col];
                        painter.drawPoint(QPoint(qrand()%(2*radius)-radius,
                                                 qrand()%(2*radius)-radius)+center);
                    }
            }
            if (mState == GroupState)
                if (mGroupmap[row][col] > -1) {
                    for(int i = 0; i< mDrawPointsCount; ++i) {
                        auto center = centers[row][col];
                        painter.drawPoint(QPoint(qrand()%(2*radius)-radius,
                                                 qrand()%(2*radius)-radius)+center);
                    }
            }
        }
    }
}

void Pattern::drawHighlight(QPainter&painter)
{
    auto cell_size = getChildSize();
    int cell_w = cell_size.width();
    int cell_h = cell_size.height();

    int radius = cell_w>=cell_h? cell_h/2: cell_w/2; // 选较小的确保圆在矩形内

    auto  centerPts = getCenterPoints();
    QPainterPath path;
    for(int row = 0 ; row < mRow; ++ row)
    {
        for(int col = 0; col < mCol; ++ col)
        {// 内圆和外圆一定会绘制
            auto center = centerPts[row][col];
            painter.drawEllipse(center,radius,radius);
            painter.drawEllipse(center,radius*0.75,radius*0.75);

            if (mState != BlankState) // 不是black，还会让内圆填充灰色
            {
                path.clear();
                path.addEllipse(center,radius*0.75,radius*0.75);
                painter.fillPath(path,mDefaultColor);
            }

            if (mMousePos.x() == row && mMousePos.y() == col)
            { // 启用鼠标事件mMouseEvent 才会传递mMousePos,默认其是{-1,-1}
                path.clear();
                path.moveTo(center);
                path.addEllipse(center,radius*0.75,radius*0.75);
                painter.fillPath(path,mCurrentColor);
            }

            if (mIsSelect &&mSelectedPoints[row][col]) // 如果不启用高亮mIsSelect,这个变量不会存在true的情况
            {// 启用高亮前提,且指定区域掩码是true才会绘制
                path.clear();
                path.moveTo(center);
                path.addEllipse(center,radius*0.75,radius*0.75);
                painter.fillPath(path,mSelectedColor);
            }

            if (mIsGroup) { // 启用分组绘制
                int colorFlag = mGroupmap[row][col]; // 颜色标记就是指用哪个颜色,索引要在范围内
                if (colorFlag >= 0 && colorFlag<= mGroupColors.count()-1) {
                    path.clear();
                    path.moveTo(center);
                    path.addEllipse(center,radius*0.75,radius*0.75);
                    painter.fillPath(path,mGroupColors.at(colorFlag));
                }

            }
        }
    }
}

void Pattern::drawLine(QPainter&painter)
{
    auto points = getBorderPoints();
    for(int row = 1; row < mRow; ++row) // 首尾2个边的线不再绘制
        painter.drawLine(points[row][0],
                points[row][mCol]);
    for(int col = 1; col < mCol; ++col)
        painter.drawLine(points[0][col],points[mRow][col]);
}

void Pattern::drawBorder(QPainter &painter)
{
    QPointF topleft(mGap,mGap);
    QPointF bottomright(width()-mGap,height()-mGap);
    painter.drawRect(QRectF(topleft,bottomright));
}

QSize Pattern::getChildSize() const
{
    int w = width() ;
    int h = height() ;
     // 总宽度-2个到边界的gap-圆之间留出的mSpace,边界sapce留出2个,共(mCol-1+2)个
    int cell_w = (w-2*mGap-mSpace*(mCol+1))/mCol;
    int cell_h = (h-2*mGap-mSpace*(mRow+1)) / mRow;
    return  QSize(cell_w,cell_h);
}

QPointFVector Pattern::getRowHeaderPoints()
{
    auto cell_size = getChildSize();
    int cell_w = cell_size.width();
    QVector<QPointF> points;
    for(int col = 0; col < mCol; ++col)
        points.append(QPointF(mGap+mSpace/2+cell_w/2+(cell_w+mSpace)*col,
                              mGap-mSpace/2));
    return points;
}

QPointFVector Pattern::getColHeaderPoints()
{
    auto cell_size = getChildSize();
    int cell_h = cell_size.height();
    QVector<QPointF> points;
    for(int row = 0; row < mRow; ++row)
        points.append(QPointF(mGap-mSpace,
                              mGap+mSpace+cell_h/2+(cell_h+mSpace)*row));
    return points;
}

QPointmap Pattern::getBorderPoints() const
{
    auto cell_size = getChildSize();
    int cell_w = cell_size.width();
    int cell_h = cell_size.height();

   QPointmap points;
    for(int row = 0; row < mRow+1; ++row) // 4x6,4行5条边
    {
        QVector<QPointF> p;
        for(int col = 0; col < mCol+1; ++col)
            p.append(QPointF(mGap+mSpace/2+(cell_w+mSpace)*col,
                             mGap+mSpace/2+(cell_h+mSpace)*row));
        points.append(p);
    }

    return points;
}

QPointmap Pattern::getCenterPoints() const
{
    auto cell_size = getChildSize();
    int cell_w = cell_size.width();
    int cell_h = cell_size.height();

    QPointmap centerPts;
    for(int row = 0; row < mRow; ++row)
    {
        QVector<QPointF> p;
        for(int col = 0; col < mCol; ++col)
            // 中心位置相对起点左上角多了cell_w和cell_h的一半,还多了mSpace
            p.append(QPointF(mGap+cell_w/2+mSpace+(cell_w+mSpace)*col,
                             mGap+cell_h/2+mSpace+(cell_h+mSpace)*row));
        centerPts.append(p);
    }

    return centerPts;
}

QRectmap Pattern::getChildRects() const
{
    auto points = getBorderPoints();

    QRectmap rects;
    for(int row = 0; row < mRow; ++row)
    {
        QRectVector r;
        for(int col = 0; col < mCol; ++col)
        {
            auto topleft = points[row][col];
            auto bottomright = points[row+1][col+1];
            r.append(QRectF(topleft,bottomright));
        }
        rects.append(r);
    }
    return rects;
}

void Pattern::setSelectedPoint(int row,int col, bool isSelected)
{
    if (!mIsSelect) return;
    if (row <0 || row >= mRow) return ;
    if (col <0 || col >= mCol) return ;

    mSelectedPoints[row][col] = isSelected;
    update();
}

void Pattern::setSelectedPoint(QCPoint point,bool isSelected)
{
    return setSelectedPoint(point.x(),point.y(),isSelected);
}

void Pattern::setSelectedPoints(bool isSelected)
{
    for(int row = 0 ; row < mRow; ++ row) {
        for (int col = 0; col < mCol; ++col)
            mSelectedPoints[row][col]=isSelected;
    }
    update();
}

void Pattern::setSelectedPoints(QCPointVector points, bool isSelected)
{
    foreach (auto p ,points) {
        setSelectedPoint(p,isSelected);
    }
}

void Pattern::clearAllPoints()
{
    setSelectedPoints(false);
}

void Pattern::selectAllPoints()
{
    setSelectedPoints(true);
}

bool Pattern::isPointSelected(int row,int col) const
{ // 如果没启用选择区域事件直接返回false
    if (!mIsSelect) return false;
    if (row <0 || row >= mRow) return false ;
    if (col <0 || col >= mCol) return false;

    return mSelectedPoints[row][col];
}

bool Pattern::isPointSelected(QCPoint point) const
{
    return isPointSelected(point.x(),point.y());
}

QPointVector Pattern::selectedPoints() const
{ // 不会按照顺序返回
    QVector<QPoint> points;
    for(int row = 0; row < mRow; ++row)
         for(int col = 0; col < mCol; ++col)
             if (mSelectedPoints[row][col])
                 points.append(QPoint(row,col));
    return points;
}

int Pattern::selectedPointCount() const
{
    int count = 0;
    foreach (auto vector, mSelectedPoints)
        count +=vector.count(true);
    return count;
}

void Pattern::clearSignedPoint()
{
    mSignedPos = {-1,-1};
    update();
}

void Pattern::setSignedPoint(int row, int col)
{
    mSignedPos = {row,col};
    update();
}

void Pattern::setSignedPoint(const QPoint& point)
{
    mSignedPos = point;
    update();
}

QPoint Pattern::signedPoint() const
{
    return mSignedPos;
}

void Pattern::setGroupPoint(int row,int col,int colorFlag)
{
        if (!mIsGroup) return;
        if (row <0 || row >= mRow) return ;
        if (col <0 || col >= mCol) return ;

        mGroupmap[row][col] = colorFlag;
        update();
}

void Pattern::setGroupPoint(const QPoint& point,int colorFlag)
{
    return setGroupPoint(point.x(),point.y(),colorFlag);
}

void Pattern::setGroupPoint(QCPointVector points,int colorFlag)
{ // 使用的时候,遍历所有组,遍历的index从0开始,可以自动作为flag
    foreach (auto p ,points) {
        setGroupPoint(p,colorFlag);
    }
}

bool Pattern::isGroupPoint(int row,int col) const
{
    if (!mIsGroup) return false;
    if (row <0 || row >= mRow) return false ;
    if (col <0 || col >= mCol) return false;

    return mGroupmap[row][col]<0? false:true;
}

bool Pattern::isGroupPoint(QCPoint point) const
{
    return isGroupPoint(point.x(),point.y());
}

void Pattern::clearGroupPoints()
{
    mGroupColors.clear();
    for (int row = 0; row < mRow; ++row)
        for (int col = 0; col < mCol; ++col){
            mGroupmap[row][col] = -1;
     }
}

void Pattern::enableZoom()
{
    mWheelEvent = true;
}

void Pattern::disableZoom()
{
    mWheelEvent = false;
}

void Pattern::setZoom(double zoom)
{
    mZoom = zoom;
}

double Pattern::zoom() const
{
    return mZoom;
}

QSize Pattern::patternSize() const
{
    return QSize(mRow,mCol);
}

void Pattern::enableClick()
{
    mMouseEvent = true;
}

void Pattern::disableClick()
{
    mMouseEvent = false;
}

void Pattern::enableSelect()
{
    mIsSelect = true;
}

void Pattern::disableSelect()
{
    mIsSelect = false;
}

void Pattern::enableGroup()
{
    mIsGroup = true;
}

void Pattern::disableGroup()
{
    mIsGroup = false;
}

void Pattern::setDefaultColor(const QColor&color)
{
    mDefaultColor = color;
}

QColor Pattern::defaultColor() const
{
    return mDefaultColor;
}

void Pattern::setCurrentColor(const QColor&color)
{
    mCurrentColor = color;
}

QColor Pattern::currentColor() const
{
    return mCurrentColor;
}

void Pattern::setSelectedColor(const QColor&color)
{
    mSelectedColor = color;
}

QColor Pattern::selectedColor() const
{
    return mSelectedColor;
}

void Pattern::setSignedColor(const QColor&color)
{
    mSignedColor = color;
}

QColor Pattern::signedColor() const
{
    return mSignedColor;
}

void Pattern::setGroupColors(QCColorVector colors)
{
    mGroupColors = colors;
}

void Pattern::clearGroupColors()
{
    mGroupColors.clear();
}

QColorVector Pattern::groupColors() const
{
    return mGroupColors;
}

void Pattern::updateMinSize()
{
#ifdef SCREEN_2560X1600
    if (mRow<8)
        INIT_MINSIZE(600,300);
    else if (mRow >8 && mRow < 16)
        INIT_MINSIZE(600,400);
    else
        INIT_MINSIZE(600,520);
#elif defined (SCREEN_1280X800)
    if (mRow<8)
        INIT_MINSIZE(300,150);
    else if (mRow >8 && mRow < 16)
        INIT_MINSIZE(350,250);
    else
        INIT_MINSIZE(400,380);
#else
    if (mRow<8)
        INIT_MINSIZE(400,150);
    else if (mRow >8 && mRow < 16)
        INIT_MINSIZE(450,300);
    else
        INIT_MINSIZE(500,380);
#endif
}


