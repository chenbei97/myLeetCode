#include "Test3DSurface.h"
#include "ui_Test3DSurface.h"
#include    <QSplitter>
#include    <QColorDialog>

Test3DSurface::Test3DSurface(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Test3DSurface)
{
      ui->setupUi(this);
      this->setWindowIcon(QIcon(":/images/3DSurface.jpg"));
      this->initBtnGrad();
      this->iniGraph3D();
      QSplitter   *splitter=new QSplitter(Qt::Horizontal);
      splitter->addWidget(ui->groupBox);
      splitter->addWidget(graphContainer);
      this->setCentralWidget(splitter);
}

Test3DSurface::~Test3DSurface()
{
   delete ui;
}

// 1. 初始化三维曲面图
void Test3DSurface::iniGraph3D()
{
    this->graph3D = new Q3DSurface();
    this->graphContainer = QWidget::createWindowContainer(this->graph3D); //Q3DBars继承自QWindow，必须如此创建

    //创建坐标轴
    QValue3DAxis *axisX=new QValue3DAxis;
    axisX->setTitle("X轴");
    axisX->setTitleVisible(true);
    axisX->setRange(-11,11);
    axisX->setAutoAdjustRange(true);
    graph3D->setAxisX(axisX);

    QValue3DAxis *axisY=new QValue3DAxis;
    axisY->setTitle("Y轴");
    axisY->setTitleVisible(true);
    axisY->setRange(-10,10);
    axisY->setAutoAdjustRange(true);
    graph3D->setAxisY(axisY);

    QValue3DAxis *axisZ=new QValue3DAxis;
    axisZ->setTitle("Z轴");
    axisZ->setTitleVisible(true);
    axisZ->setRange(-11,11);
    axisZ->setAutoAdjustRange(true);
    graph3D->setAxisZ(axisZ);

    //创建数据代理->序列->图表
    this->proxy = new QSurfaceDataProxy();
    this->series = new QSurface3DSeries(this->proxy);
    this->series->setItemLabelFormat("(@xLabel @yLabel @zLabel)");
    this->series->setMeshSmooth(true);
    this->series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    this->series->setBaseColor(Qt::red);
    this-> graph3D->activeTheme()->setLabelBackgroundEnabled(false);
    this->graph3D->addSeries(series);


    //创建数据, 墨西哥草帽
    int N=41;//-10:0.5:10, N个数据点
    QSurfaceDataArray *dataArray = new QSurfaceDataArray; //数组
    dataArray->reserve(N);
    float x=-10,y,z;
    int i,j;
    for (i =1 ; i <=N; i++)
    {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(N); //一行的数据
        y=-10;
        int index=0;
        for (j = 1; j <=N; j++)
        {
            z=qSqrt(x*x+y*y);
            if (z!=0)
                z=10*qSin(z)/z;
            else
                z=10;
            (*newRow)[index++].setPosition(QVector3D(x, z, y));
            y=y+0.5;
        }
        x=x+0.5;
        *dataArray << newRow;
    }
    this->proxy->resetArray(dataArray);
}

// 2. 视角改变
void Test3DSurface::on_comboBox_currentIndexChanged(int index)
{
     this->graph3D->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPreset(index));
}

// 3. 水平旋转
void Test3DSurface::on_sliderH_valueChanged(int value)
{
    Q_UNUSED(value);
    int xRot =ui->sliderH->value(); // 水平旋转
    int yRot=ui->sliderV->value(); // 垂直旋转
    int zoom=ui->sliderZoom->value(); //缩放
    graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot,zoom);
}

// 4. 垂直旋转
void Test3DSurface::on_sliderV_valueChanged(int value)
{
    this->on_sliderH_valueChanged(value);
}

// 5. 缩放
void Test3DSurface::on_sliderZoom_valueChanged(int value)
{
     this->on_sliderH_valueChanged(value);
}

// 6.主题样式
void Test3DSurface::on_cBoxTheme_currentIndexChanged(int index)
{
     Q3DTheme *currentTheme = this->graph3D->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(index));
}

// 7. 棒图样式
void Test3DSurface::on_cBoxBarStyle_currentIndexChanged(int index)
{
    QAbstract3DSeries::Mesh aMesh;
    aMesh=QAbstract3DSeries::Mesh(index);
    this->series->setMesh(aMesh);
}

// 8.选择模式
void Test3DSurface::on_cBoxSelectionMode_currentIndexChanged(int index)
{
    switch(index)
    {
     case 0:
        this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionNone);
        break;
     case 1:
        this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionItem);
        break;
     case 2:
       this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionItemAndRow | QAbstract3DGraph::SelectionSlice);
        break;
     case 3:
        this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionItemAndColumn | QAbstract3DGraph::SelectionSlice);
    default:
        break;
    }
}

// 9. 字体大小
void Test3DSurface::on_spinFontSize_valueChanged(int arg1)
{
    QFont font = graph3D->activeTheme()->font();
    font.setPointSize(arg1);
    this->graph3D->activeTheme()->setFont(font);
}

// 10.曲面样式
void Test3DSurface::on_comboDrawMode_currentIndexChanged(int index)
{
     if (index==0)
        this->series->setDrawMode(QSurface3DSeries::DrawWireframe);
    else if (index==1)
        this->series->setDrawMode(QSurface3DSeries::DrawSurface);
    else
        this->series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
}

// 11. 图表背景
void Test3DSurface::on_chkBoxBackground_clicked(bool checked)
{
    this->graph3D->activeTheme()->setBackgroundEnabled(checked);
}

// 12. 网格线显示
void Test3DSurface::on_chkBoxGrid_clicked(bool checked)
{
    this->graph3D->activeTheme()->setGridEnabled(checked);
}

// 13. 设置阴影
void Test3DSurface::on_chkBoxShadow_clicked(bool checked)
{
     if (checked)
        this->graph3D->setShadowQuality(QAbstract3DGraph::ShadowQualityMedium);
    else
        this->graph3D->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
}

// 14. 倒影
void Test3DSurface::on_chkBoxReflection_clicked(bool checked)
{
    this->graph3D->setReflection(checked);
}

// 15. 平滑效果
void Test3DSurface::on_chkBoxSmooth_clicked(bool checked)
{
    this->series->setMeshSmooth(checked);
}

// 16. Y轴反转
void Test3DSurface::on_chkBoxReverse_clicked(bool checked)
{
    this->graph3D->axisY()->setReversed(checked);
}

// 17. 项标签可见
void Test3DSurface::on_chkBoxItemLabel_clicked(bool checked)
{
    this->series->setItemLabelVisible(checked);
}

// 18. 轴标题可见
void Test3DSurface::on_chkBoxAxisTitle_clicked(bool checked)
{
    this->graph3D->axisX()->setTitleVisible(checked);
    this->graph3D->axisY()->setTitleVisible(checked);
    this->graph3D->axisZ()->setTitleVisible(checked);
}

// 19.轴背景可见
void Test3DSurface::on_chkBoxAxisBackground_clicked(bool checked)
{
    this->graph3D->activeTheme()->setLabelBackgroundEnabled(checked);
}

// 20. 设置曲面颜色
void Test3DSurface::on_btnBarColor_clicked()
{
    QColor  color= this->series->baseColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
    {
        this->series->setBaseColor(color);
        this->series->setColorStyle(Q3DTheme::ColorStyleUniform);
    }
}

// 21. 设置曲面渐变色1
void Test3DSurface::on_btnGrad1_clicked()
{
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::black);
    gr.setColorAt(0.33, Qt::blue);
    gr.setColorAt(0.67, Qt::red);
    gr.setColorAt(1.0, Qt::yellow);

    series->setBaseGradient(gr);
    series->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
    // series->setColorStyle(Q3DTheme::ColorStyleUniform);
}

// 22. 设置曲面渐变色2
void Test3DSurface::on_btnGrad2_clicked()
{
    QLinearGradient grGtoR;
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);

    this->series->setBaseGradient(grGtoR);
    this->series->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
}

// 23. 对2个按钮的颜色初始化操作
void Test3DSurface::initBtnGrad()
{
    QLinearGradient grBtoY(0, 0, 100, 0);   //渐变颜色1
    grBtoY.setColorAt(1.0, Qt::black);
    grBtoY.setColorAt(0.67, Qt::blue);
    grBtoY.setColorAt(0.33, Qt::red);
    grBtoY.setColorAt(0.0, Qt::yellow);

    int width = ui->btnGrad1->width(), height =ui->btnGrad1->height();
    QPixmap pm(width, height);    // 空图片
    QPainter pmp(&pm); // 对图片进行填充
    pmp.setBrush(QBrush(grBtoY)); //渐变颜色
    pmp.setPen(Qt::NoPen);
    pmp.drawRect(0, 0, width, height);
    ui->btnGrad1->setIcon(QIcon(pm));   // 图片设置为图标
    ui->btnGrad1->setIconSize(QSize(width, height));

    QLinearGradient grGtoR(0, 0, 100, 0);  //渐变颜色2
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);
    width = ui->btnGrad2->width(); height = ui->btnGrad2->height();
    pmp.setBrush(QBrush(grGtoR));
    pmp.drawRect(0, 0, width,height);
    ui->btnGrad2->setIcon(QIcon(pm));       //渐变颜色按钮2
    ui->btnGrad2->setIconSize(QSize(width,height));
}
