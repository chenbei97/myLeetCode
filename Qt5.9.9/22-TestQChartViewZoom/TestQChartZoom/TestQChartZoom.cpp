#include "TestQChartZoom.h"
#include "ui_TestQChartZoom.h"

TestQChartZoom::TestQChartZoom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestQChartZoom)
{
        ui->setupUi(this);
        this->setCentralWidget(ui->graphicsView);
        this->labXYValue = new QLabel; //状态栏显示鼠标点的坐标
        this->labXYValue->setMinimumWidth(200);
        ui->statusbar->addWidget(this->labXYValue);
        this->createChart();
        this->prepareData();
        QObject::connect(ui->graphicsView,SIGNAL(mouseMovePoint(QPoint)),
                         this, SLOT(on_mouseMovePoint(QPoint)));  //鼠标移动事件
}

TestQChartZoom::~TestQChartZoom()
{
    delete ui;
}

// 1. 鼠标移动事件(显示坐标到状态栏)
void TestQChartZoom::on_mouseMovePoint(QPoint point){
    QPointF pt=ui->graphicsView->chart()->mapToValue(point); //转换为图表的数值,point是物理坐标,图表属于视图的图形项,局部逻辑坐标
    this->labXYValue->setText(QString::asprintf("坐标(%.2f,%.2f)",pt.x(),pt.y())); //状态栏显示
}

// 2. 恢复
void TestQChartZoom::on_actZoomReset_triggered()
{
    ui->graphicsView->chart()->zoomReset();
}

// 3. 放大
void TestQChartZoom::on_actZoomIn_triggered()
{
        ui->graphicsView->chart()->zoom(1.2);
}

// 4. 缩小
void TestQChartZoom::on_actZoomOut_triggered()
{
    ui->graphicsView->chart()->zoom(0.8);
}

// 5. 创建图表
void TestQChartZoom::createChart()
{
        QChart *chart = new QChart();
       ui->graphicsView->setChart(chart);
       ui->graphicsView->setRenderHint(QPainter::Antialiasing);//开启渲染提示
       ui->graphicsView->setCursor(Qt::CrossCursor); //设置鼠标指针为十字星

       QLineSeries *series0 = new QLineSeries();
       QLineSeries *series1 = new QLineSeries();
       series0->setName("Sin曲线");
       series1->setName("Cos曲线");

       QPen    pen;
       pen.setStyle(Qt::DotLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
       pen.setWidth(2);
       pen.setColor(Qt::red);
       series0->setPen(pen);

       pen.setStyle(Qt::SolidLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
       pen.setColor(Qt::blue);
       series1->setPen(pen);

       chart->addSeries(series0);
       chart->addSeries(series1);

       QValueAxis *axisX = new QValueAxis;
       axisX->setRange(0, 10); //设置坐标轴范围
       axisX->setLabelFormat("%.1f"); //标签格式
       axisX->setTickCount(11); //主分隔个数
       axisX->setMinorTickCount(2);//4
       axisX->setTitleText("time(secs)"); //标题
       axisX->setGridLineVisible(true);

       QValueAxis *axisY = new QValueAxis;
       axisY->setRange(-2, 2);
       axisY->setTitleText("value");
       axisY->setTickCount(5);
       axisY->setLabelFormat("%.2f"); //标签格式
       axisY->setGridLineVisible(false);
       axisY->setMinorTickCount(2);//4

       chart->setAxisX(axisX, series0); //添加X坐标轴
       chart->setAxisX(axisX, series1); //添加X坐标轴
       chart->setAxisY(axisY, series0); //添加Y坐标轴
       chart->setAxisY(axisY, series1); //添加Y坐标轴

       chart->legend()->setAlignment(Qt::AlignBottom);
       foreach (QLegendMarker* marker, chart->legend()->markers())
       {
           // 点击图例标记和曲线关联,控制曲线的显示操作
           connect(marker, SIGNAL(clicked()), this, SLOT(on_LegendMarkerClicked()));
       }
}

// 6. 图例标记和曲线关联的槽函数
void TestQChartZoom::on_LegendMarkerClicked()
{
        // 获取发送信号的图例标记
       QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());
       switch (marker->type()) //marker的类型
       {
           case QLegendMarker::LegendMarkerTypeXY: //QLineSeries序列的图例marker
           {
               marker->series()->setVisible(!marker->series()->isVisible()); //可见性与操作互斥
               marker->setVisible(true);
               qreal alpha = 1.0;
               if (!marker->series()->isVisible())
                   alpha = 0.5; //不可见的透明度0.5

               QColor color;
               QBrush brush = marker->labelBrush();
               color = brush.color();
               color.setAlphaF(alpha); // 设置个透明度
               brush.setColor(color);
               marker->setLabelBrush(brush);// 再送回去

               brush = marker->brush();
               color = brush.color();
               color.setAlphaF(alpha);
               brush.setColor(color);
               marker->setBrush(brush);

               QPen pen = marker->pen();
               color = pen.color();
               color.setAlphaF(alpha);
               pen.setColor(color);
               marker->setPen(pen);
               break;
           }
           default:
               break;
       }
}

// 7.生成序列
void TestQChartZoom::prepareData()
{
    QLineSeries *series0=(QLineSeries *)ui->graphicsView->chart()->series().at(0);
    QLineSeries *series1=(QLineSeries *)ui->graphicsView->chart()->series().at(1);

    series0->clear();
    series1->clear();

    qsrand(QTime::currentTime().second());//随机数初始化
    qreal   t=0,y1,y2,intv=0.1;
    qreal   rd;
    int cnt=100;
    for(int i=0;i<cnt;i++)
    {
        rd=(qrand() % 10)-5; //随机数,-5~+5
        y1=qSin(t)+rd/50;//+qrand();
        *series0<<QPointF(t,y1);

        rd=(qrand() % 10)-5; //随机数,-5~+5
        y2=qSin(t+20)+rd/50;
        series1->append(t,y2);

        t+=intv;
    }
}
