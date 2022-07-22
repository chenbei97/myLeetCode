#include "TestQChartLineSeries.h"
#include "ui_TestQChartLineSeries.h"

// 1. 设置图表标题
void TestQChartLineSeries::on_btnSetTitle_clicked()
{
    QString str=ui->editTitle->text();
    ui->chartView->chart()->setTitle(str);
}

// 2. 设置图表标题字体
void TestQChartLineSeries::on_btnSetTitleFont_clicked()
{
    QFont font=ui->chartView->chart()->titleFont();
    bool  ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        ui->chartView->chart()->setTitleFont(font);
}

// 3. 设置图表边距
void TestQChartLineSeries::on_btnSetMargin_clicked()
{
    QMargins    mgs; // 获取ui界面4个spinbox的值进行设置
    mgs.setLeft(ui->spinMarginLeft->value());
    mgs.setRight(ui->spinMarginRight->value());
    mgs.setTop(ui->spinMarginTop->value());
    mgs.setBottom(ui->spinMarginBottom->value());
    ui->chartView->chart()->setMargins(mgs);
}

// 4. 设置图表图例可见性
void TestQChartLineSeries::on_chkLegendVisible_clicked(bool checked)
{
    ui->chartView->chart()->legend()->setVisible(checked);
}

// 5. 设置图表图例的背景是否可见
void TestQChartLineSeries::on_chkBoxLegendBackground_clicked(bool checked)
{
    ui->chartView->chart()->legend()->setBackgroundVisible(checked);
}

// 注：图例的4个radioButton在同一个GroupBox中会自动互斥
// 6. 设置图表图例在上方
void TestQChartLineSeries::on_radioButton_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignTop);
}

// 7. 设置图表图例在下方
void TestQChartLineSeries::on_radioButton_2_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
}

// 8. 设置图表图例在左侧
void TestQChartLineSeries::on_radioButton_3_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignLeft);
}

// 9. 设置图表图例在右侧
void TestQChartLineSeries::on_radioButton_4_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignRight);
}

// 10. 设置图表图例的字体
void TestQChartLineSeries::on_btnLegendFont_clicked()
{
    QFont font=ui->chartView->chart()->legend()->font();
    bool  ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        ui->chartView->chart()->legend()->setFont(font);
}

// 11.设置图表图例的文字颜色
void TestQChartLineSeries::on_btnLegendlabelColor_clicked()
{
    QColor  color=ui->chartView->chart()->legend()->labelColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
        ui->chartView->chart()->legend()->setLabelColor(color);
}

// 12. 设置图表动画效果
void TestQChartLineSeries::on_cBoxAnimation_currentIndexChanged(int index)
{
        ui->chartView->chart()->setAnimationOptions(QChart::AnimationOptions(index));
        // 表示无动画效果、背景网格有动画效果、序列有动画效果、都有动画效果
        // QChart::NoAnimation动画禁用;QChart::GridAxisAnimations 启用网格轴动画
        // QChart::SeriesAnimations 启用系列动画;QChart::AllAnimations 启用所有动画类型
        // ui->chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
        // ui->chartView->chart()->setAnimationOptions(QChart::AllAnimations);
}

// 13. 设置图表主题
void TestQChartLineSeries::on_cBoxTheme_currentIndexChanged(int index)
{
    /*
        QChart::ChartThemeLight
        QChart::ChartThemeBlueCerulean
        QChart::ChartThemeDark
        QChart::ChartThemeBrownSand
        QChart::ChartThemeBlueNcs
        QChart::ChartThemeHighContrast
        QChart::ChartThemeBlueIcy
        QChart::ChartThemeQt
        主题是应用于图表所有视觉元素的 UI 样式相关设置的内置集合
        例如颜色、钢笔、画笔和系列字体以及轴、标题和图例
        注意：更改主题将覆盖以前应用于该系列的所有自定义
    */
    ui->chartView->chart()->setTheme(QChart::ChartTheme(index));
}
