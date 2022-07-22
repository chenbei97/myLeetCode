#include "TestQChartDrawAllCharts.h"
#include "ui_TestQChartDrawAllCharts.h"

// 1. 初始化柱状图
void TestQChartDrawAllCharts::initBarChart()
{
    QChart *chart = new QChart(); //创建chart
    chart->setTitle("Barchart演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewBar->setChart(chart); //为ChartView设置chart
    ui->chartViewBar->setRenderHint(QPainter::Antialiasing);
}

// 2. 初始化堆叠柱状图
void TestQChartDrawAllCharts::initStackBarChart()
{
    QChart *chart = new QChart();
    chart->setTitle("StackedBar 演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewStackedBar->setChart(chart);
    ui->chartViewStackedBar->setRenderHint(QPainter::Antialiasing);
}

// 3. 初始化百分比柱状图
void TestQChartDrawAllCharts::initPercentBarChart()
{
    QChart *chart = new QChart();
    chart->setTitle("PercentBar 演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewPercentBar->setChart(chart);
    ui->chartViewPercentBar->setRenderHint(QPainter::Antialiasing);
}

// 4. 初始化饼图
void TestQChartDrawAllCharts::initPieChart()
{
    QChart *chart = new QChart();
    chart->setTitle("Piechart演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewPie->setChart(chart);
    ui->chartViewPie->setRenderHint(QPainter::Antialiasing);
}

// 5. 初始化散点图
void TestQChartDrawAllCharts::initScatterChart()
{
    QChart *chart = new QChart();
    chart->setTitle("QScatterSeries 和 QSplineSeries 演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewScatter->setChart(chart);
    ui->chartViewScatter->setRenderHint(QPainter::Antialiasing);
}
