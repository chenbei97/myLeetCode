#include "TestQChartLineSeries.h"
#include "ui_TestQChartLineSeries.h"
#include "setPenDialog.h"

// 1. 设置当前操作序列为sin
void TestQChartLineSeries::on_radioSeries0_clicked(bool checked)
{
     if (checked)
        this->curSeries=(QLineSeries *)ui->chartView->chart()->series().at(0); // sin
    else
        this->curSeries=(QLineSeries *)ui->chartView->chart()->series().at(1);

    //获取当前序列的属性值，并显示到界面上
    ui->editSeriesName->setText(this->curSeries->name()); // 序列名称
    ui->chkSeriesVisible->setChecked(this->curSeries->isVisible()); // 序列是否可见
    ui->chkPointVisible->setChecked(this->curSeries->pointsVisible());// 序列点是否可见
    ui->sliderSeriesOpacity->setValue(this->curSeries->opacity()*10); // 序列透明度
    ui->chkPointLabelVisible->setChecked(this->curSeries->pointLabelsVisible()); // 序列标签是否可见
}

// 2. 设置当前操作序列为cos
void TestQChartLineSeries::on_radioSeries1_clicked(bool checked)
{
    this->on_radioSeries0_clicked(!checked); // 一样的操作,但传递给sin的checked是相反的,因为2个按钮互斥
}

// 3. 设置当前序列名称
void TestQChartLineSeries::on_btnSeriesName_clicked()
{
     this->curSeries->setName(ui->editSeriesName->text()); // 依据操作的序列来设置名称
    if (ui->radioSeries0->isChecked())
        ui->radioSeries0->setText(ui->editSeriesName->text());
    else
        ui->radioSeries1->setText(ui->editSeriesName->text());
}

// 4. 设置当前序列是否可见
void TestQChartLineSeries::on_chkSeriesVisible_clicked(bool checked)
{
    this->curSeries->setVisible(checked);
}

// 5. 设置当前序列点是否可见
void TestQChartLineSeries::on_chkPointVisible_clicked(bool checked)
{
    this->curSeries->setPointsVisible(checked);
}

// 6. 设置当前序列点数值是否可见
void TestQChartLineSeries::on_chkPointLabelVisible_clicked(bool checked)
{
    this->curSeries->setPointLabelsVisible(checked);
}

// 7. 设置曲线颜色
void TestQChartLineSeries::on_btnSeriesColor_clicked()
{
    QColor  color=this->curSeries->color();
    color=QColorDialog::getColor(color);
    if (color.isValid())
        curSeries->setColor(color);
}

// 8. 设置曲线的画笔
void TestQChartLineSeries::on_btnSeriesPen_clicked()
{
    bool    ok=false;
    QPen    pen;
    pen=this->curSeries->pen(); // 获取当前曲线的画笔
    pen=setPenDialog::getPen(pen,ok); // 打开画笔对话框
    if (ok)
       this->curSeries->setPen(pen);
}

// 9. 设置曲线的透明度
void TestQChartLineSeries::on_sliderSeriesOpacity_valueChanged(int value)
{
    curSeries->setOpacity(value/10.0); //滑动条在UI已经设置了范围[0,10],单步1,当前位置5
    // 因为透明度在[0,1]内,所以÷10
}

// 10. 曲线点的数值显示颜色
void TestQChartLineSeries::on_btnSeriesLabColor_clicked()
{
    QColor  color=this->curSeries->pointLabelsColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
        this->curSeries->setPointLabelsColor(color);
}

// 11. 曲线点的数值字体格式
void TestQChartLineSeries::on_btnSeriesLabFont_clicked()
{
    QFont   font;
    font=this->curSeries->pointLabelsFont();
    bool    ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
          this->curSeries->setPointLabelsFont(font);
}

// 12. 曲线点的数值显示格式(@yPoint)
void TestQChartLineSeries::on_radioSeriesLabFormat0_clicked()
{
      this->curSeries->setPointLabelsFormat("@yPoint");
}

// 13. 曲线点的数值显示格式 (@xPoint, @yPoint)
void TestQChartLineSeries::on_radioSeriesLabFormat1_clicked()
{
    this->curSeries->setPointLabelsFormat("(@xPoint,@yPoint)");
}

