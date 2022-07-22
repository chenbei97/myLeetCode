#include "TestQChartDrawAllCharts.h"
#include "ui_TestQChartDrawAllCharts.h"

// 1. 初始化数据动作
void TestQChartDrawAllCharts::on_actGenData_triggered()
{
    this->initData();
    this->statisticalData();
}

// 2. 统计数据动作
void TestQChartDrawAllCharts::on_actTongJi_triggered()
{
    this->statisticalData();
}


