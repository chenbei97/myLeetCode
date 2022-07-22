#ifndef TESTQCHARTDRAWALLCHARTS_H
#define TESTQCHARTDRAWALLCHARTS_H

#include <QMainWindow>
#include    <QStandardItemModel>
#include    <QItemSelectionModel>
#include    <QtCharts>  //必须这么设置
QT_CHARTS_USE_NAMESPACE

#define     fixedColumnCount   5    //数据模型的列数
#define     iniDataRowCount    100   //学生个数
#define     colNoName       0   //姓名的列编号
#define     colNoMath       1   //数学的列编号
#define     colNoChinese    2   //语文的列编号
#define     colNoEnglish    3   //英语的列编号
#define     colNoAverage    4   //平均分的列编号

QT_BEGIN_NAMESPACE
namespace Ui { class TestQChartDrawAllCharts; }
QT_END_NAMESPACE

class TestQChartDrawAllCharts : public QMainWindow
{
  Q_OBJECT

public:
  TestQChartDrawAllCharts(QWidget *parent = nullptr);
  ~TestQChartDrawAllCharts();

private:
  QStandardItemModel  *theModel;//数据模型
  void initData();//初始化数据
  void statisticalData(); // 统计数据
  void initBarChart();//初始化柱状图
  void initStackBarChart();//初始化堆叠柱状图
  void initPercentBarChart(); // 初始化百分比柱状图
  void initPieChart();//初始化饼图
  void initScatterChart();// 初始化散点图
private slots:
  // 数据模型的 itemChanged信号与自定义的槽函数关联，用于自动计算平均分
  void on_itemChanged(QStandardItem * item);
  // 曲线和图例的标记关联
  void on_chartBarLegendMarkerClicked();
  // 饼图鼠标点击时弹出分块的槽函数
  void on_PieSliceHighlight(bool show);
  // 初始化数据和统计的act槽函数
  void on_actGenData_triggered();
  void on_actTongJi_triggered();


  void on_btnScatter_clicked();

  void on_btnBuildBarChart_clicked();

  void on_btnDrawPieChart_clicked();

  void on_btnBuildStackedBar_clicked();

  void on_btnPercentBar_clicked();

  void on_spinHoleSize_valueChanged(double arg1);

  void on_spinPieSize_valueChanged(double arg1);

  void on_cBoxTheme_currentIndexChanged(int index);

private:
  Ui::TestQChartDrawAllCharts *ui;
};
#endif // TESTQCHARTDRAWALLCHARTS_H
