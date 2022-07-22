#include "TestQChartLineSeries.h"
#include "ui_TestQChartLineSeries.h"
#include "setPenDialog.h"

// 1. 设置当前操作的坐标轴(X轴)
void TestQChartLineSeries::on_radioX_clicked()
{
    // 在Qt 5.12.1中编译时提示 QChart::axisX()和QChart::axisY()函数过时，应使用 QChart::axes()函数
    //if (ui->radioX->isChecked())
    //    curAxis=(QValueAxis*)ui->chartView->chart()->axisX();
    //else
    //    curAxis=(QValueAxis*)ui->chartView->chart()->axisY();

    //  下面是针对Qt 5.12.1修改的代码,在Qt5.9.1里编译也没问题
    QList<QAbstractAxis*> axes;
    if (ui->radioX->isChecked())
        axes=ui->chartView->chart()->axes(Qt::Horizontal); // 获取X轴
    else
        axes=ui->chartView->chart()->axes(Qt::Vertical); // 获取Y轴
    this->curAxis=(QValueAxis*)axes[0]; // 因为只有2个轴,所以必然返回列表的元素只有1个[0]

    //获取坐标轴的各种属性显示到界面上,让界面和内部属性保持一致
    ui->spinAxisMin->setValue(this->curAxis->min()); // 坐标轴下限
    ui->spinAxisMax->setValue(this->curAxis->max());// 坐标轴上限

    ui->editAxisTitle->setText(this->curAxis->titleText()); // 坐标轴标题
    ui->chkBoxAxisTitle->setChecked(this->curAxis->isTitleVisible()); // 坐标轴标题可见性

    ui->editAxisLabelFormat->setText(this->curAxis->labelFormat()); // 数值格式
    ui->chkBoxLabelsVisible->setChecked(this->curAxis->labelsVisible()); // 数值可见性

    ui->chkGridLineVisible->setChecked(this->curAxis->isGridLineVisible()); // 网格线可见性
    ui->chkAxisLineVisible->setChecked(this->curAxis->isLineVisible()); // 轴线的可见性

    ui->spinTickCount->setValue(this->curAxis->tickCount()); // 轴刻度数量,默认5,不得小于2
    ui->spinMinorTickCount->setValue(this->curAxis->minorTickCount());//次刻度数量,默认0
    ui->chkMinorTickVisible->setChecked(this->curAxis->isMinorGridLineVisible());// 次网格线是否可见
}

// 2. 设置当前操作的坐标轴(Y轴)
void TestQChartLineSeries::on_radioY_clicked()
{
    this->on_radioX_clicked();
}

// 3.坐标轴是否可见
void TestQChartLineSeries::on_chkBoxVisible_clicked(bool checked)
{
    this->curAxis->setVisible(checked);
}

// 4. 设置轴坐标范围
void TestQChartLineSeries::on_btnSetAxisRange_clicked()
{
    this->curAxis->setRange(ui->spinAxisMin->value(),ui->spinAxisMax->value());
}

// 5.设置轴标题
void TestQChartLineSeries::on_btnAxisSetTitle_clicked()
{
    this->curAxis->setTitleText(ui->editAxisTitle->text());
}

// 6.设置轴标题是否可见
void TestQChartLineSeries::on_chkBoxAxisTitle_clicked(bool checked)
{
    this->curAxis->setTitleVisible(checked);
}

// 7. 设置轴标题文字格式
void TestQChartLineSeries::on_btnAxisSetTitleFont_clicked()
{
    QFont   font=curAxis->titleFont();
    bool    ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        this->curAxis->setTitleFont(font);
}

// 8. 设置轴刻度标签格式
void TestQChartLineSeries::on_pushButton_clicked()
{
    this->curAxis->setLabelFormat(ui->editAxisLabelFormat->text());
}

// 9. 设置轴刻度标签颜色
void TestQChartLineSeries::on_btnAxisLabelColor_clicked()
{
    QColor   color=curAxis->labelsColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
        this->curAxis->setLabelsColor(color);
}

// 10. 设置轴刻度标签字体
void TestQChartLineSeries::on_btnAxisLabelFont_clicked()
{
    QFont   font=curAxis->labelsFont();
    bool    ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        this->curAxis->setLabelsFont(font);
}

// 11. 设置轴刻度标签是否可见
void TestQChartLineSeries::on_chkBoxLabelsVisible_clicked(bool checked)
{
    this->curAxis->setLabelsVisible(checked);
}

// 12. 设置主网格线是否可见
void TestQChartLineSeries::on_chkGridLineVisible_clicked(bool checked)
{
    this->curAxis->setGridLineVisible(checked);
}

// 13. 设置主网格线颜色
void TestQChartLineSeries::on_btnGridLineColor_clicked()
{
    QColor   color=curAxis->gridLineColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
        this->curAxis->setGridLineColor(color);
}

// 14. 设置主网格线画笔
void TestQChartLineSeries::on_pushButton_10_clicked()
{
    QPen    pen;
    pen=curAxis->gridLinePen();
    bool    ok=false;
    pen=setPenDialog::getPen(pen,ok);
    if (ok)
        this->curAxis->setGridLinePen(pen);
}

// 15. 主刻度是否可见
void TestQChartLineSeries::on_chkAxisLineVisible_clicked(bool checked)
{
    this->curAxis->setLineVisible(checked);
}

// 16. 主刻度画笔设置
void TestQChartLineSeries::on_btnAxisLinePen_clicked()
{
     QPen    pen;
    pen=this->curAxis->linePen();
    bool    ok=false;
    pen=setPenDialog::getPen(pen,ok);
    if (ok)
        this->curAxis->setLinePen(pen);
}

// 17. 主刻度颜色设置
void TestQChartLineSeries::on_btnAxisLinePenColor_clicked()
{
    QColor   color=curAxis->linePenColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
        this->curAxis->setLinePenColor(color);
}

// 18. 轴主刻度的个数变化时响应的槽函数
void TestQChartLineSeries::on_spinTickCount_valueChanged(int arg1)
{
    this->curAxis->setTickCount(arg1);
}

// 19. 轴次刻度的个数变化时响应的槽函数
void TestQChartLineSeries::on_spinMinorTickCount_valueChanged(int arg1)
{
    this->curAxis->setMinorTickCount(arg1);
}

// 20. 次网格线是否可见
void TestQChartLineSeries::on_chkMinorTickVisible_clicked(bool checked)
{
    this->curAxis->setMinorGridLineVisible(checked);
}

// 21. 设置次网格线颜色
void TestQChartLineSeries::on_btnMinorColor_clicked()
{
      QColor   color=curAxis->minorGridLineColor();
      color=QColorDialog::getColor(color);
      if (color.isValid())
          this->curAxis->setMinorGridLineColor(color);
}

// 22. 设置次网格线画笔
void TestQChartLineSeries::on_btnMinorPen_clicked()
{
    QPen    pen;
    pen=curAxis->minorGridLinePen();
    bool    ok=false;
    pen=setPenDialog::getPen(pen,ok);
    if (ok)
        this->curAxis->setMinorGridLinePen(pen);
}
