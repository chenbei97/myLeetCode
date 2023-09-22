#ifndef PATTERN_H
#define PATTERN_H

#include "qtimeline.h"
#include "../public.h"
/*
 * drawHighlight一直在无条件调用,一定会绘制内外2个圆,然后=>
    * 如果不是BlankState,会填充内圆
    * 如果启用了鼠标事件mMouseEvent =true才会传递mMousePos,其默认是{-1,-1}
    * 启用高亮mIsSelect前提下,指定区域mSelectedPoints掩码是true才会绘制
    * 启用分组mIsGroup前提下,指定区域的mGroupmap颜色标记有效才会绘制,和groupColors()的索引对应
 * drawSignedPoints一直在无条件调用,只是绘制标记点,mSignPos不为{-1,-1}才能绘制
 * drawRandomPoints是有条件调用,如果mIsDrawRandomPoints=false直接返回
    * 是通过外界void drawRandomPoints(int count);函数让mIsDrawRandomPoints=true然后绘制

* blackState
    *  禁用鼠标事件,禁用滚轮缩放事件,禁用不分组绘制点,禁用分组绘制点
 * tickState
    *  启用鼠标事件,启用滚轮缩放事件,启用不分组绘制点,禁用分组绘制点
 * selectedState
    *  禁用鼠标事件,禁用滚轮缩放事件,启用不分组绘制点,禁用分组绘制点
 * groupState
    *  启用鼠标事件,禁用滚轮缩放事件,禁用不分组绘制点,启用分组绘制点
*/

class COMPONENT_IMEXPORT Pattern : public QWidget
{
    Q_OBJECT
public:
    enum PatternState {BlankState,TickState,SelectedState,GroupState,GroupWithoutClickState};
    explicit Pattern();
    explicit Pattern(int rows, int cols);
    explicit Pattern(const QSize&size);
    explicit Pattern(const Pattern& pattern);
    explicit Pattern(const Pattern* pattern);
    Pattern& operator = (const Pattern&pattern);

    void toggleState(PatternState state);
    PatternState state() const;

    void setPatternSize(int rows,int cols);
    void setPatternSize(const QSize& size);
    QSize patternSize() const;

    void setDefaultColor(const QColor&color);
    QColor defaultColor() const;

    void setCurrentColor(const QColor&color);
    QColor currentColor() const;

    void setSelectedColor(const QColor&color);
    QColor selectedColor() const;

    void setSignedColor(const QColor&color);
    QColor signedColor() const;

    void setGroupColors(QCColorVector colors);
    void clearGroupColors();
    QColorVector groupColors() const;

    void setGap(uint32_t gap);
    uint32_t gap() const;

    void setSpacing(uint32_t space);
    uint32_t spacing() const;

    void setZoom(double zoom);
    double zoom() const;

    QPoint currentMousePoint() const;// 这个是鼠标选中的点
    void clearMousePoint();

    void clearAllPoints();// 轨迹选中的点
    void selectAllPoints();
    void setSelectedPoints(bool isSelected);
    void setSelectedPoint(int row, int col, bool isSelected = true) ;
    void setSelectedPoint(QCPoint point,bool isSelected = true);
    void setSelectedPoints(QCPointVector points,bool isSelected = true);
    int selectedPointCount() const;
    bool isPointSelected(int row,int col) const;
    bool isPointSelected(QCPoint point) const;
    QPointVector selectedPoints() const; // 这个不按照顺序返回选中的点位置

    void clearSignedPoint();// 预览标记效果的点
    void setSignedPoint(int row,int col);
    void setSignedPoint(const QPoint& point);
    QPoint signedPoint() const;

    void drawRandomPoints(int count); // 每孔视野数的随机点
    void disableDrawRandomPoints();

    void setGroupPoint(int row,int col,int colorFlag); // 分组颜色,颜色标记对应groupColors的索引
    void setGroupPoint(const QPoint& point,int colorFlag);
    void setGroupPoint(QCPointVector points,int colorFlag);
    bool isGroupPoint(int row,int col) const;
    bool isGroupPoint(QCPoint point) const;
    void clearGroupPoints();

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
private:
    double mGap;
    double mSpace;
    double mZoom;
    bool mIsZoom;
    bool mIsSelect;
    bool mIsDrawRandomPoints;
    bool mIsGroup;
    bool mMouseEvent;
    bool mWheelEvent;
    QPoint mMousePos;
    QPoint mSignedPos;
    QMaskmap mSelectedPoints;
    int mDrawPointsCount;
    int mRow;
    int mCol;
    PatternState mState;
    QColor mDefaultColor = Qt::darkGray;
    QColor mSelectedColor = QColor("#A0FEFF");
    QColor mCurrentColor = Qt::green;
    QColor mSignedColor = Qt::red;
    QColorVector mGroupColors;
    QGroupmap mGroupmap;
private:
    void init();
    void copy(const Pattern&pattern);

    QSize getChildSize() const ;
    QPointFVector getRowHeaderPoints();
    QPointFVector getColHeaderPoints();
    QPointmap getBorderPoints() const;
    QPointmap getCenterPoints() const;
    QRectmap getChildRects() const;

    void drawBorder(QPainter&painter);
    void drawLine(QPainter&painter);
    void drawHeader(QPainter&painter); // 行列表头
    void drawHighlight(QPainter&painter); // 绘制鼠标选中的高亮和已选择区域的高亮
    void drawRandomPoints(QPainter&painter); // 每孔视野数画的点
    void drawSignedPoints(QPainter&painter); // 绘制预览标记的效果

    void enableZoom();
    void disableZoom();
    void enableClick();
    void disableClick();
    void enableSelect();
    void disableSelect();
    void enableGroup();
    void disableGroup();

    void updateMinSize();
signals:
    void mouseClicked(const QPoint&point);
};

#endif // PATTERN_H
