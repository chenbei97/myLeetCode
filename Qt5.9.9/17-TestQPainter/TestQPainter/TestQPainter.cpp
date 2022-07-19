#include "TestQPainter.h"
#include "ui_TestQPainter.h"

TestQPainter::TestQPainter(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestQPainter)
{
      ui->setupUi(this);
      setPalette(QPalette(Qt::white)); //设置窗口背景色
      setAutoFillBackground(true);
      this->starPath = new QPainterPath;


      resize(800,550); //固定初始化窗口大小宽度800,高度550比较紧凑
      this->design_pentagram();
}

TestQPainter::~TestQPainter()
{
    delete ui;
}

void TestQPainter::paintEvent(QPaintEvent *event)
{
      Q_UNUSED(event);
      // this->paint(); // 坐标变换看这个函数
      this->viewPort_window(); // 视口与窗口的关系看这个
}

void TestQPainter::design_pentagram()
{
      QFont   font;
      font.setPointSize(12);
      font.setBold(true);

      // 五角星的5个顶点的角度是36°
      // 5个顶点和中心进行连线,则连线之间5等分360°,所以每个角是72°
      // 这里是假设五角星稍微有些倾斜(左高右低),让最右边的顶点在水平线上
      // 如果半径为R的话,显然右边的第个顶点位置是(R,0),因为中心位置为原点(0,0)
      // 然后逆时针,第2个顶点和中心的连线与水平线的夹角是72°,所以顶点的水平位置就是Rcos(72°),而垂直位置因为向上是-y轴,所以是-Rsin(72°)
      // 第3个顶点的话只需要角度×2即可,也就是144°,以此类推可以得到后边每个点的坐标
      qreal   R=100; //半径
      const   qreal Pi=3.14159;
      qreal   deg=Pi*72/180;//5等分的夹角
      QPoint points[5]={
          QPoint(R,0), // 第1个点的坐标在水平位置
          QPoint(R*qCos(deg),     -R*qSin(deg)), // 第2个点
          QPoint(R*qCos(2*deg),   -R*qSin(2*deg)),
          QPoint(R*qCos(3*deg),   -R*qSin(3*deg)),
          QPoint(R*qCos(4*deg),   -R*qSin(4*deg))
      };

       //设计绘制五角星的PainterPath，以便重复使用
      starPath->moveTo(points[0]); // 绘制线按照0,2,4,1,3才能画出五角星
      starPath->lineTo(points[2]);
      starPath->lineTo(points[4]);
      starPath->lineTo(points[1]);
      starPath->lineTo(points[3]);
      starPath->closeSubpath(); //闭合路径，最后一个点与第一个点相连

      starPath->addText(points[0],font,"0"); //显示端点编号
      starPath->addText(points[1],font,"1");
      starPath->addText(points[2],font,"2");
      starPath->addText(points[3],font,"3");
      starPath->addText(points[4],font,"4");
}

void TestQPainter::paint()
{
          QPainter  painter(this);//创建QPainter对象
          painter.setRenderHint(QPainter::Antialiasing);//渲染效果:指示引擎应尽可能消除图元边缘的锯齿
          painter.setRenderHint(QPainter::TextAntialiasing); // 渲染效果:指示引擎应尽可能消除文本锯齿

          // 1. 画家第一步设置字体
          QFont font;
          font.setPointSize(12);
          font.setBold(true);
          painter.setFont(font);

          // 2. 第二步设置画笔
          QPen    penLine;
          penLine.setWidth(2); //线宽
          penLine.setColor(Qt::blue); //划线颜色
          //Qt::NoPen,Qt::SolidLine, Qt::DashLine, Qt::DotLine,Qt::DashDotLine,Qt::DashDotDotLine,Qt::CustomDashLine
          penLine.setStyle(Qt::SolidLine);//线的类型，实线、虚线等
          //Qt::FlatCap, Qt::SquareCap,Qt::RoundCap
          penLine.setCapStyle(Qt::FlatCap);//线端点样式
          //Qt::MiterJoin,Qt::BevelJoin,Qt::RoundJoin,Qt::SvgMiterJoin
          penLine.setJoinStyle(Qt::BevelJoin);//线的连接点样式
          painter.setPen(penLine);

          // 3. 第三步设置画刷,设置填充颜色、填充样式等
          QBrush  brush;
          brush.setColor(Qt::green); //画刷颜色
          brush.setStyle(Qt::SolidPattern); //画刷填充样式
          painter.setBrush(brush);

            // 4. 绘制3个星星
          painter.save(); //保存第一个星星绘制之前的状态

          // 第一个星星绘制
          painter.translate(100,120); // 右平移100,下平移120
          painter.drawPath(*starPath); //画星星
          painter.drawText(0,0,"S1"); // 在当前坐标系统下的(0,0)位置,也就是五角星的中心位置

          painter.restore(); //绘制完第一个恢复之前的状态来绘制第2个
          painter.translate(300,120); //右平移300,下平移120不变
          painter.scale(0.8,0.8); //缩放一些比例
          painter.rotate(90); //顺时针旋转90°
          painter.drawPath(*starPath);//画星星
          painter.drawText(0,0,"S2");

          painter.resetTransform(); //复位所有坐标变换,绘制第3个
          painter.translate(500,120); //右平移500,下平移120不变
          painter.rotate(-145); //逆时针旋转
          painter.drawPath(*starPath);//画星星
          painter.drawText(0,0,"S3");

          painter.resetTransform(); // 复位
          painter.translate(600,120);//右平移600,下平移120不变
          QRect rect(0,0,200,200);
          int startAngle = 30 * 16, spanAngle = 150 * 16; // 必须指定为16的倍数,该函数认为360*16=5760°是完整的圆
          painter.drawPie(rect,startAngle,spanAngle);
          painter.drawText(100,100,"Pie");

          painter.resetTransform();
          painter.translate(0,300);
          painter.drawChord(0,0,200,200,90*16,180*16); // 起始90°跨度180°画一段弦就是半圆
          painter.drawText(50,100,"Chord");

          painter.resetTransform();
          painter.translate(150,300);
          QRect rect1(0,0,200,200); // 预设矩形的4个顶点
          QVector<QLine>Lines; // 一批直线
          Lines.append(QLine(rect1.topLeft(),rect1.bottomRight())); // 矩形左上角到右下角连一根线
          Lines.append(QLine(rect1.bottomLeft(),rect1.topRight()));// 左下角到右上角
          Lines.append(QLine(rect1.topLeft(),rect1.bottomLeft())); // 左垂直线
          Lines.append(QLine(rect1.topRight(),rect1.bottomRight())); // 右垂直线
          painter.drawLines(Lines);
          painter.drawText(100,100,"Lines");

          painter.resetTransform();
          painter.translate(400,300);
          QRect rect2(0,0,300,200);
          QPainterPath path;
          path.addEllipse(rect2);//添加1个椭圆
          path.addRect(rect2) ;//加1个矩形
          painter.fillPath(path,Qt::red); // 填充绘图路径
          painter.drawText(150,150,"fillPath");
}

void TestQPainter::viewPort_window()
{
    QPainter p(this);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    p.setPen(pen);
    p.setRenderHint(QPainter::Antialiasing);


    int width = this->width(), height = this->height();
    int length = qMin(width,height);// 更小的作为正方形的边长
    // x,y有1个是0,如果窗口比较宽,那么窗口高度作为边长,否则窗口宽度作为边长
    int x = (width - length)/2; // x起始位置
    int y = (height-length)/ 2; // y起始位置
    QRect rect(x,y,length,length); // 正方形

    p.drawRect(rect);// 画矩形
    p.setViewport(rect); // 这个区域看作视口,坐标系统默认,其实就是从整个窗口取一块区域
    //现在左上角的位置就是(x,0),这个是相对于主窗口的左上角(0,0)来说的

    // 引入线性渐变效果还可以继续
    QLinearGradient lgrd(0,0,length/2,0); //(x1,y1,x2,y2),构造一个线性梯度，插值区域介于 (x1, y1) 和 (x2, y2) 之间
    lgrd.setColorAt(0,Qt::cyan);//起点颜色
    lgrd.setColorAt(0.5,Qt::blue); // 中间层颜色
    lgrd.setColorAt(1,Qt::yellow); // 终点颜色
    lgrd.setSpread(QGradient::RepeatSpread); // 渐变反映在渐变区域之外
    p.setBrush(lgrd);

    // 还可以设置复合模式
    p.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);

    // 现在想要画36个圆,每10°画1个圆
    // 如果不设置为窗口系统,这些圆其实画在了(0,0)为中心,半径length/4的范围内
    p.setWindow(-length/2,-length/2,length,length); // 左上角是(-len/2,-len/2),整个长度和宽度都是len
    for (int i = 0; i < 36; ++i)
    {
        p.drawEllipse(QPoint(length/4,0),length/4,length/4); // 初始圆心位置选在(len/4,0),圆的直径正好是len/2,所以半径len/4,
        p.rotate(10);
    }
}












