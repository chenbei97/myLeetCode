#ifndef CUSTOMCHARTVIEW_H
#define CUSTOMCHARTVIEW_H

#include <QObject>
#include <QtCharts>
#include    <QChartView>

// QCharView自身是没有鼠标事件的信号和保护继承函数的
// 所以一方面为了使用QChartView的特性,一方面还要自定义鼠标事件,所以需要定义子类
// 再就是希望实现的这个视图类能够对图形项进行一个缩放
// 之前的例子只能对图形项进行移动、选中，或者使用整体视觉的一个放大缩小
// 这里唯一的改进是通过绘制矩形框就可以实现放大
QT_CHARTS_USE_NAMESPACE

class customChartView :public QChartView
{
    Q_OBJECT
private:
    QPoint  beginPoint; //选择矩形区的起点
    QPoint  endPoint;  //选择矩形区的终点
protected:
    void mousePressEvent(QMouseEvent *event); //鼠标左键按下
    void mouseMoveEvent(QMouseEvent *event); //鼠标移动
    void mouseReleaseEvent(QMouseEvent *event); //鼠标释放左键
    void keyPressEvent(QKeyEvent *event); //按键事件
public:
    explicit customChartView(QWidget* parent=0);
signals:
    void mouseMovePoint(QPoint point); //鼠标移动信号，在mouseMoveEvent()事件中触发
};

#endif // CUSTOMCHARTVIEW_H
