#include "TestQChartDrawAllCharts.h"
#include "ui_TestQChartDrawAllCharts.h"

// 1. 刷新柱状图
void TestQChartDrawAllCharts::on_btnBuildBarChart_clicked()
{
    QChart *chart =ui->chartViewBar->chart(); //获取ChartView关联的chart
    chart->removeAllSeries(); //删除所有序列
    if (chart->axisX() != nullptr) chart->removeAxis(chart->axisX()); //删除坐标轴
    if (chart->axisY()!=nullptr) chart->removeAxis(chart->axisY()); //删除坐标轴

    //创建三个QBarSet数据集,从数据模型的表头获取Name
    QBarSet *setMath = new QBarSet(theModel->horizontalHeaderItem(colNoMath)->text());
    QBarSet *setChinese = new QBarSet(theModel->horizontalHeaderItem(colNoChinese)->text());
    QBarSet *setEnglish= new QBarSet(theModel->horizontalHeaderItem(colNoEnglish)->text());

    QLineSeries *line = new QLineSeries(); //创建一个QLineSeries序列用于显示平均分
    line->setName(theModel->horizontalHeaderItem(colNoAverage)->text()); // 平均分

    QPen    pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    line->setPen(pen);
    line->setPointLabelsVisible(false);
    // line->setPointLabelsFormat("@yPoint");

    for(int i=0;i<theModel->rowCount();i++)
    {//从数据模型获取数据
        setMath->append(theModel->item(i,colNoMath)->text().toInt()); //数学
        setChinese->append(theModel->item(i,colNoChinese)->text().toInt()); //语文
        setEnglish->append(theModel->item(i,colNoEnglish)->text().toInt()); //英语
        line->append(QPointF(i,theModel->item(i,colNoAverage)->text().toFloat()));  //平均分
    }

    //创建一个柱状图序列 QBarSeries, 并添加三个数据集
    QBarSeries *series = new QBarSeries();
    series->append(setMath);
    series->append(setChinese);
    series->append(setEnglish);
    series->setLabelsVisible(true);
    // series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);// LabelsCenter
    series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);// LabelsCenter

    chart->addSeries(series); //添加柱状图序列
    chart->addSeries(line); //添加折线图序列

    //用于横坐标在字符串列表,即学生姓名
    QStringList categories;
    for (int i=0;i<theModel->rowCount();i++)
        categories <<theModel->item(i,colNoName)->text();

    //用于柱状图的坐标轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories); //添加横坐标文字列表
    chart->setAxisX(axisX, series); //设置横坐标
    chart->setAxisX(axisX, line);//设置横坐标
    axisX->setRange(categories.at(0),categories.at(categories.count()-1)); //坐标轴范围,函数使用字符串表示的(因为不是数值型)

    //数值型坐标作为纵轴
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 100);
    axisY->setTitleText("分数");
    axisY->setTickCount(6);//11
    axisY->setLabelFormat("%.1f"); //标签格式
    axisY->setGridLineVisible(false); // 主垂直网格线
    axisY->setMinorTickCount(4);
    chart->setAxisY(axisY, series);
    chart->setAxisY(axisY, line);

    chart->legend()->setVisible(true); //显示图例
    chart->legend()->setAlignment(Qt::AlignBottom); //图例显示在下方
}

// 2. 刷新堆叠柱状图
void TestQChartDrawAllCharts::on_btnBuildStackedBar_clicked()
{
    QChart *chart =ui->chartViewStackedBar->chart(); //获取QChart对象
    chart->removeAllSeries();//删除所有序列
    chart->removeAxis(chart->axisX()); //删除坐标轴
    chart->removeAxis(chart->axisY());

    //创建三门课程的数据集
    QBarSet *setMath = new QBarSet(theModel->horizontalHeaderItem(colNoMath)->text());
    QBarSet *setChinese = new QBarSet(theModel->horizontalHeaderItem(colNoChinese)->text());
    QBarSet *setEnglish= new QBarSet(theModel->horizontalHeaderItem(colNoEnglish)->text());

    for(int i=0;i<theModel->rowCount();i++)
    { //添加分数数据到数据集
        setMath->append(theModel->item(i,colNoMath)->text().toInt());
        setChinese->append(theModel->item(i,colNoChinese)->text().toInt());
        setEnglish->append(theModel->item(i,colNoEnglish)->text().toInt());
    }

    //创建   QStackedBarSeries对象并添加数据集
    QStackedBarSeries *series = new QStackedBarSeries();
    series->append(setMath);
    series->append(setChinese);
    series->append(setEnglish);
    series->setLabelsVisible(true);//显示每段的标签
    series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);// LabelsCenter

    chart->addSeries(series); //添加序列到图表

    QStringList categories;
    for (int i=0;i<theModel->rowCount();i++)
        categories <<theModel->item(i,colNoName)->text();

    QBarCategoryAxis *axisX = new QBarCategoryAxis(); //类别坐标轴，作为横轴
    axisX->append(categories);
    chart->setAxisX(axisX, series);
    axisX->setRange(categories.at(0), categories.at(categories.count()-1));

    QValueAxis *axisY = new QValueAxis; //数值坐标轴，作为纵轴
    axisY->setRange(0, 300);
    axisY->setTitleText("总分");
    axisY->setTickCount(6);
    axisY->setLabelFormat("%.1f"); //标签格式
    chart->setAxisY(axisY, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
}

// 3. 刷新百分比柱状图
void TestQChartDrawAllCharts::on_btnPercentBar_clicked()
{
    QChart *chart =ui->chartViewPercentBar->chart();
    chart->removeAllSeries();
    chart->removeAxis(chart->axisX());
    chart->removeAxis(chart->axisY());

    //创建数据集
    QBarSet *setMath = new QBarSet(theModel->horizontalHeaderItem(colNoMath)->text());
    QBarSet *setChinese = new QBarSet(theModel->horizontalHeaderItem(colNoChinese)->text());
    QBarSet *setEnglish= new QBarSet(theModel->horizontalHeaderItem(colNoEnglish)->text());

    QTreeWidgetItem *item; //节点
    QStringList categories;

    for (int i=0;i<=4;i++)
    {//从分数段统计数据表里获取数据，添加到数据集
        item=ui->treeWidget->topLevelItem(i);
        categories<<item->text(0);//用作横坐标的标签
        setMath->append(item->text(colNoMath).toFloat());
        setChinese->append(item->text(colNoChinese).toFloat());
        setEnglish->append(item->text(colNoEnglish).toFloat());
    }

    QPercentBarSeries *series = new QPercentBarSeries(); //序列
    series->append(setMath);
    series->append(setChinese);
    series->append(setEnglish);
    series->setLabelsVisible(true);//显示百分比
    series->setLabelsFormat("@value人");

    chart->addSeries(series);

    QBarCategoryAxis *axisX = new QBarCategoryAxis(); //横坐标
    axisX->append(categories);
    chart->setAxisX(axisX, series);
    axisX->setRange(categories.at(0), categories.at(categories.count()-1));

    QValueAxis *axisY = new QValueAxis;//纵坐标
    axisY->setRange(0, 100);
    axisY->setTitleText("百分比");
    axisY->setTickCount(6);
    axisY->setLabelFormat("%.1f"); //标签格式
    chart->setAxisY(axisY, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight); //AlignBottom
}

// 4. 刷新饼图
void TestQChartDrawAllCharts::on_btnDrawPieChart_clicked()
{
      QChart *chart =ui->chartViewPie->chart(); //获取chart对象
    chart->removeAllSeries(); //删除所有序列

    int colNo=1+ui->cBoxCourse->currentIndex(); //获取分析对象，数学、英语、语文或平均分

    QPieSeries *series = new QPieSeries(); //创建饼图序列
    series->setHoleSize(ui->spinHoleSize->value()); //饼图中间空心的大小

    for (int i=0;i<=4;i++) //添加分块数据
    {
        QTreeWidgetItem*  item=ui->treeWidget->topLevelItem(i); //获得QTreeWidgetItem的item
        series->append(item->text(0),item->text(colNo).toFloat()); //添加一个饼图分块数据,(i,j)
    }

    QPieSlice *slice; //饼图分块
    for(int i=0;i<=4;i++) //设置每个分块的标签文字
    {
        slice =series->slices().at(i);  //获取分块
        slice->setLabel(slice->label()+QString::asprintf(": %.0f人, %.1f%%",    //设置分块的标签
                        slice->value(),slice->percentage()*100));

        //信号与槽函数关联，鼠标落在某个分块上时，此分块弹出
        connect(slice, SIGNAL(hovered(bool)), this, SLOT(on_PieSliceHighlight(bool)));
    }

    slice->setExploded(true); //最后一个设置为exploded
    series->setLabelsVisible(true); //只影响当前的slices，必须添加完slice之后再设置
    chart->addSeries(series); //添加饼图序列
    chart->setTitle("Piechart----"+ui->cBoxCourse->currentText());

    chart->legend()->setVisible(true); //图例
    chart->legend()->setAlignment(Qt::AlignRight);//Qt::AlignRight
}

// 5. 刷新散点图
void TestQChartDrawAllCharts::on_btnScatter_clicked()
{
    //绘制 QScatterSeries和QSplineSeries图
    QChart *chart =ui->chartViewScatter->chart(); // 这个初始化的时候赋值了
    chart->removeAllSeries();
    chart->removeAxis(chart->axisX());
    chart->removeAxis(chart->axisY());

    QSplineSeries *seriesLine = new QSplineSeries(); //光滑曲线序列
    seriesLine->setName("光滑曲线图");
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    seriesLine->setPen(pen);

    QScatterSeries *series0 = new QScatterSeries(); //散点序列
    series0->setName("散点图");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);//MarkerShapeRectangle,MarkerShapeCircle
    series0->setBorderColor(Qt::black);
    series0->setBrush(QBrush(Qt::red));
    series0->setMarkerSize(12);

    qsrand(QTime::currentTime().second());//随机数种子

    for (int i=0;i<10;i++)
    {
        int x=(qrand() % 20);//0到20之间的随机数
        int y=(qrand() % 20);
        series0->append(x,y); //散点序列
        seriesLine->append(x,y); //光滑曲线序列
    }

    chart->addSeries(series0);
    chart->addSeries(seriesLine);

      // 2种做法创建坐标轴
//    QValueAxis *axisY = new QValueAxis;
//    axisY->setRange(0, 20);
//    axisY->setTitleText("Y");
//    axisY->setTickCount(11);
//    axisY->setLabelFormat("%.0f"); //标签格式
//    axisY->setGridLineVisible(true);
//    chart->setAxisY(axisY, series0);
//    chart->setAxisY(axisY, seriesLine);

//    QValueAxis *axisX = new QValueAxis;
//    axisX->setRange(0, 20);
//    axisX->setTitleText("X");
//    axisX->setTickCount(11);
//    axisX->setLabelFormat("%.0f"); //标签格式
//    axisX->setGridLineVisible(true);
//    chart->setAxisX(axisX, series0);
//    chart->setAxisX(axisX, seriesLine);

     // 使用第2种方法创建坐标轴
    chart->createDefaultAxes(); //创建缺省的坐标轴
    chart->axisX()->setTitleText("X 轴");
    chart->axisX()->setRange(-2,22);
    chart->axisY()->setTitleText("Y 轴");
    chart->axisY()->setRange(-2,22);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight); //AlignBottom

    foreach (QLegendMarker* marker, chart->legend()->markers()) {
        QObject::connect(marker, SIGNAL(clicked()), this, SLOT(on_chartBarLegendMarkerClicked()));//曲线和图例标记关联
    }
}
