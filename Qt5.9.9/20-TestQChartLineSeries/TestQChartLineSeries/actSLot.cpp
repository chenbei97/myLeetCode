#include "TestQChartLineSeries.h"
#include "ui_TestQChartLineSeries.h"

// 1. 更新
void TestQChartLineSeries::on_actDraw_triggered()
{
      this->prepareData(); // 重新生成数据
}

// 2. 放大
void TestQChartLineSeries::on_actZoomIn_triggered()
{
    ui->chartView->chart()->zoom(1.2);// 也可以使用zoomIn(),但是会放大2倍
}

// 3. 缩小
void TestQChartLineSeries::on_actZoomOut_triggered()
{
    ui->chartView->chart()->zoom(0.8);// 也可以使用zoomOut(),但是会缩小到1/2
}

// 4. 复位
void TestQChartLineSeries::on_actZoomReset_triggered()
{
    ui->chartView->chart()->zoomReset();
}
