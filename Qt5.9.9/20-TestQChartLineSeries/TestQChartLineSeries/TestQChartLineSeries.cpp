#include "TestQChartLineSeries.h"
#include "ui_TestQChartLineSeries.h"

TestQChartLineSeries::TestQChartLineSeries(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestQChartLineSeries)
{
        ui->setupUi(this);
        this->createChart();//创建图表
        this->prepareData();//生成数据
        this->updateFromChart(); //从图表获得属性值，刷新界面显示
}

TestQChartLineSeries::~TestQChartLineSeries()
{
      delete ui;
}

// 1. 创建图表
void TestQChartLineSeries::createChart()
{
    QChart *chart = new QChart();
    chart->setTitle(tr("简单三角函数曲线")); // 图表标题
    chart->setAcceptHoverEvents(true); // 如果 enabled 为 true,则此项将接受悬停事件,默认不接受悬停事件
    chart->setTheme(QChart::ChartTheme::ChartThemeBlueCerulean);
    // chart->setFont(QFont("Times New Roman",16,-1,false)); // 不管用
    ui->chartView->setChart(chart);
    // ui->chartView->setFont(QFont("Times New Roman",20,-1,false));// 不管用
    ui->chartView->setRenderHint(QPainter::Antialiasing);//启用渲染提示

    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    series0->setName("Sin曲线");
    series1->setName("Cos曲线");

    this->curSeries=series0; //当前序列

    QPen    pen;
    pen.setStyle(Qt::DotLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
    pen.setWidth(2);
    pen.setColor(Qt::red);
    series0->setPen(pen); //Sin序列设置
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::blue);
    series1->setPen(pen);//cos序列设置

    // 把设置的曲线添加进来
    chart->addSeries(series0);
    chart->addSeries(series1);

    // 设置2个坐标轴
    QValueAxis *axisX = new QValueAxis;
    this->curAxis=axisX; //当前坐标轴
    axisX->setRange(0, 10); //设置坐标轴范围
    axisX->setLabelFormat("%.1f"); //标签格式
    axisX->setTickCount(11); //主分隔个数
    axisX->setMinorTickCount(4); // 最小刻度
    axisX->setTitleText("time(secs)"); //坐标轴标题
    axisX->setGridLineVisible(true); // 水平网格线可见

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-1.5, 1.5); // 在prepareData中y的范围-1.1~1.1之间
    axisY->setTitleText("value");
    axisY->setTickCount(5);
    axisY->setLabelFormat("%.2f"); //标签格式
    axisY->setGridLineVisible(false); // 竖直网格线不可见
    axisY->setMinorTickCount(4);// 最小刻度

    // setAxis系列函数过时,应改用addAxis,之所以过时这里认为只有X,Y2个轴
    // 实际上4个方向都可以设置轴,例如双y轴双x轴都是可能的
    // chart->setAxisX(axisX, series0); //sin添加X坐标轴
    // chart->setAxisX(axisX, series1); //sin添加X坐标轴
    // chart->setAxisY(axisY, series0); //cos添加Y坐标轴
    // chart->setAxisY(axisY, series1); //cos添加Y坐标轴

    // 使用setAxis系列为序列指定坐标轴后还会加入到图表中,无需调用attachAxis函数
    // 如果分别单独设置也是可以,使用addAxis

    // 图表加入这2个坐标轴
    chart->addAxis(axisX,Qt::AlignBottom); //底侧X轴
    chart->addAxis(axisY,Qt::AlignLeft);// 左侧Y轴
    // 序列也要加入2个坐标轴
    series0->attachAxis(axisX);
    series0->attachAxis(axisY);
    series1->attachAxis(axisX);
    series1->attachAxis(axisY);

     // 创建图例的每个marker的信号clicked与槽函数的关联
     // 这样图例可以通过点击marker来控制对应的序列是否显示
    foreach (QLegendMarker* marker, chart->legend()->markers()) {
        // QObject::disconnect(marker, SIGNAL(clicked()), this, SLOT(on_LegendMarkerClicked()));
        QObject::connect(marker, SIGNAL(clicked()), this, SLOT(on_LegendMarkerClicked()));
    }
}

// 2. 准备数据
void TestQChartLineSeries::prepareData()
{
    QLineSeries *series0=(QLineSeries *)ui->chartView->chart()->series().at(0); // 获取2个序列的第1个
    QLineSeries *series1=(QLineSeries *)ui->chartView->chart()->series().at(1);// 获取2个序列的第2个

    series0->clear(); //清除数据
    series1->clear();

    qsrand(QTime::currentTime().second());//随机数初始化
    qreal   t=0,y1,y2,intv=0.1;
    qreal   rd; // 随机数值
    int cnt=100;
    for(int i=0;i<cnt;i++) // 100个点
    {
        rd=((qrand() % 10)-5)/50; //随机数,-0.1~+0.1
        y1=qSin(t)+rd; // 计算当前t的y值sin(t)+rd
        *series0<<QPointF(t,y1);  //序列添加数据点,使用<<流
        // series0->append(t,y1);  //序列添加数据点,使用append

        rd=((qrand() % 10)-5)/50; //随机数,-0.1~+0.1
        y2=qCos(t)+rd;
        series1->append(t,y2); //序列添加数据点
        // *series1<<QPointF(t,y2); //序列添加数据点

        t+=intv; // t的范围是[0,10],100步,每步0.1
    }
}

// 3. 根据新设置的属性更新界面显示
void TestQChartLineSeries::updateFromChart()
{
    QChart  *aChart;
    aChart=ui->chartView->chart();  //获取chart,因为chart被设置以后,只能从ui的chartView找到它
    ui->editTitle->setText(aChart->title()); // 获取图表标题更新到图表设置的QLineEdit组件

    QMargins mg=aChart->margins(); // 获取图表边距
    ui->spinMarginLeft->setValue(mg.left()); // 更新到图表设置的4个QSpinBox组件
    ui->spinMarginRight->setValue(mg.right());
    ui->spinMarginTop->setValue(mg.top());
    ui->spinMarginBottom->setValue(mg.bottom());
}

// 4. 图例控制图表显示的关联槽函数
void TestQChartLineSeries::on_LegendMarkerClicked()
{
      // 获取发送者后设置其可见性,依据可见性设置标签、填充、轮廓不同画刷透明度的性质
      QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());

      switch (marker->type()) //依据发送者的类型进行处理
      {
        case QLegendMarker::LegendMarkerTypeXY: // 如果是二维平面的图例(Line,Scatter,SplineLine)
        {
            marker->series()->setVisible(!marker->series()->isVisible()); // 取反操作,如果是显示状态就设为不显示,反之如此
            marker->setVisible(true); // 标记自身是可见的
            qreal alpha = 1.0;
            if (!marker->series()->isVisible()) // 如果是不可见的标记的透明度小一些
                alpha = 0.5;

            QColor color;
            QBrush brush = marker->labelBrush(); //返回用于绘制标签的画笔
            color = brush.color(); // 取出画笔的颜色
            color.setAlphaF(alpha); // 多加1条透明度的设置
            brush.setColor(color);// 再反馈回brush
            marker->setLabelBrush(brush);//使用更新的brush

            brush = marker->brush();// 返回用于填充图标的画笔,同理更新透明度反馈回去
            color = brush.color();
            color.setAlphaF(alpha);
            brush.setColor(color);
            marker->setBrush(brush);

            QPen pen = marker->pen();// 返回用于绘制图标轮廓的笔,同理
            color = pen.color();
            color.setAlphaF(alpha);
            pen.setColor(color);
            marker->setPen(pen);
            break;
        }
        default:break;
      }
}





