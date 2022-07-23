#ifndef TESTQCHARTZOOM_H
#define TESTQCHARTZOOM_H

#include <QMainWindow>
#include <QtCharts>
#include <QLabel>
#include "TestQChartZoom.h"
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class TestQChartZoom; }
QT_END_NAMESPACE

class TestQChartZoom : public QMainWindow
{
    Q_OBJECT
private:
    QLabel  *labXYValue; //状态栏显示文字标签
    void    createChart(); //创建图表
    void    prepareData();  //准备数据
public:
    explicit TestQChartZoom(QWidget *parent = nullptr);
    ~TestQChartZoom();

private slots:
    void on_mouseMovePoint(QPoint point); //鼠标移动事件，自定义槽函数
    void on_LegendMarkerClicked();// 曲线和图例标记的关联槽函数
    void on_actZoomReset_triggered();//复位
    void on_actZoomIn_triggered();//放大
    void on_actZoomOut_triggered();//缩小
private:
    Ui::TestQChartZoom *ui;
};
#endif // TESTQCHARTZOOM_H
