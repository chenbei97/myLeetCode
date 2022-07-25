#include "Test3DMap.h"
#include "ui_Test3DMap.h"
#include  <QSplitter>
#include  <QColorDialog>

Test3DMap::Test3DMap(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Test3DMap)
{
       ui->setupUi(this);
       this->setWindowIcon(QIcon(":/images/3DMap.jpg"));
      this->initBtnGrad();
      this->iniGraph3D();
      QSplitter   *splitter=new QSplitter(Qt::Horizontal);
      splitter->addWidget(ui->groupBox);
      splitter->addWidget(graphContainer);
      this->setCentralWidget(splitter);
}

Test3DMap::~Test3DMap()
{
      delete ui;
}
// 0. 接收来自主窗口的信号
void Test3DMap::on_mapImageName(QString name)
{
    this->imageName = name;
    this->iniGraph3D();

}
// 1. 初始化2个渐变色btn
void Test3DMap::initBtnGrad()
{
    QLinearGradient grBtoY(0, 0, 100, 0);
    grBtoY.setColorAt(1.0, Qt::black);
    grBtoY.setColorAt(0.67, Qt::blue);
    grBtoY.setColorAt(0.33, Qt::red);
    grBtoY.setColorAt(0.0, Qt::yellow);

     int width = ui->btnGrad1->width(), height =ui->btnGrad1->height();
    QPixmap pm(width, height); // 空图片
    QPainter pmp(&pm); // 对图片填充
    pmp.setBrush(QBrush(grBtoY));
    pmp.setPen(Qt::NoPen);
    pmp.drawRect(0, 0, width, height);
    ui->btnGrad1->setIcon(QIcon(pm));
    ui->btnGrad1->setIconSize(QSize(width, height));

    QLinearGradient grGtoR(0, 0, 100, 0);
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);
    pmp.setBrush(QBrush(grGtoR));
    width = ui->btnGrad2->width(); height = ui->btnGrad2->height();
    pmp.drawRect(0, 0, height, width);
    ui->btnGrad2->setIcon(QIcon(pm));
    ui->btnGrad2->setIconSize(QSize(width, height));
}

// 2. 初始化地形图
void Test3DMap::iniGraph3D()
{
    if (this->graph3D == nullptr) this->graph3D = new Q3DSurface(); // 选择新的图片不需要更新graph3D,graphContainer,proxy和series
    if (this->graphContainer == nullptr)this->graphContainer = QWidget::createWindowContainer(this->graph3D); //Q3DBars继承自QWindow，必须如此创建

    //创建坐标轴
    QValue3DAxis *axisX=new QValue3DAxis;   //X,东西方向
    axisX->setTitle("东--西");
    axisX->setTitleVisible(true);
    axisX->setLabelFormat("%.1f 米");
    axisX->setRange(-5000,5000);
    this->graph3D->setAxisX(axisX);
    QValue3DAxis *axisY=new QValue3DAxis; //Y，深度
    axisY->setTitle("深度");
    axisY->setTitleVisible(true);
    axisY->setAutoAdjustRange(true);
    this->graph3D->setAxisY(axisY);
    QValue3DAxis *axisZ=new QValue3DAxis;   //Z, 南北
    axisZ->setTitle("南--北");
    axisZ->setLabelFormat("%.1f 米");
    axisZ->setTitleVisible(true);
    axisZ->setRange(-5000,5000);
    this->graph3D->setAxisZ(axisZ);
    this-> graph3D->activeTheme()->setLabelBackgroundEnabled(false);

    //创建数据代理
    QString filename = ":/images/"+this->imageName;// sea.png,mountain.png和eagray.png
    QImage heightMapImage(filename);
    if (this->proxy == nullptr) this->proxy = new QHeightMapSurfaceDataProxy(heightMapImage);
    else {this->proxy->setHeightMap(heightMapImage);} // 只需要单纯更新proxy的图片即可即可,不需要new,因为新new的跟之前的不一样了
    this->proxy->setValueRanges(-5000, 5000, -5000, 5000);
    if (this->series == nullptr) this->series = new QSurface3DSeries(this->proxy);
    this->series->setItemLabelFormat("(@xLabel, @zLabel): @yLabel");
    this->series->setFlatShadingEnabled(false);
    this->series->setMeshSmooth(true);
    this-> series->setDrawMode(QSurface3DSeries::DrawSurface);

    this->graph3D->addSeries(this->series);
}

// 3. 视角
void Test3DMap::on_comboBox_currentIndexChanged(int index)
{
    this->graph3D->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPreset(index));
}

// 4. 水平旋转
void Test3DMap::on_sliderH_valueChanged(int value)
{
    Q_UNUSED(value);
    int xRot =ui->sliderH->value(); // 水平旋转
    int yRot=ui->sliderV->value(); // 垂直旋转
    int zoom=ui->sliderZoom->value(); //缩放
    this->graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot,zoom);
}

// 5. 垂直旋转
void Test3DMap::on_sliderV_valueChanged(int value)
{
    this->on_sliderH_valueChanged(value);
}

// 6. 缩放
void Test3DMap::on_sliderZoom_valueChanged(int value)
{
    this->on_sliderH_valueChanged(value);
}

// 7. 主题样式
void Test3DMap::on_cBoxTheme_currentIndexChanged(int index)
{
    Q3DTheme *currentTheme = this->graph3D->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(index));
}

// 8. 棒图风格
void Test3DMap::on_cBoxBarStyle_currentIndexChanged(int index)
{
    QAbstract3DSeries::Mesh aMesh;
    aMesh=QAbstract3DSeries::Mesh(index+1);
    this->series->setMesh(aMesh);
}

// 9. 选择模式
void Test3DMap::on_cBoxSelectionMode_currentIndexChanged(int index)
{
     switch(index)
    {
     case 0:    //none
        this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionNone);
        break;
     case 1:    //Item
        this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionItem);
        break;
     case 2:    //Row Slice
        this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionItemAndRow
                                  | QAbstract3DGraph::SelectionSlice);
        break;
     case 3:    //Column Slice
        this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionItemAndColumn
                                 | QAbstract3DGraph::SelectionSlice);
    default:
        break;
    }
}

// 10. 字体大小
void Test3DMap::on_spinFontSize_valueChanged(int arg1)
{
    QFont font = this->graph3D->activeTheme()->font();
    font.setPointSize(arg1);
    this->graph3D->activeTheme()->setFont(font);
}

// 11. 曲面样式
void Test3DMap::on_comboDrawMode_currentIndexChanged(int index)
{
    if (index==0)
        this->series->setDrawMode(QSurface3DSeries::DrawWireframe);
    else if (index==1)
        this->series->setDrawMode(QSurface3DSeries::DrawSurface);
    else
        this->series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
}

// 12. 显示背景
void Test3DMap::on_chkBoxBackground_clicked(bool checked)
{
    this->graph3D->activeTheme()->setBackgroundEnabled(checked);
}

// 13. 显示网格
void Test3DMap::on_chkBoxGrid_clicked(bool checked)
{
    this->graph3D->activeTheme()->setGridEnabled(checked);
}

// 14. 显示阴影
void Test3DMap::on_chkBoxShadow_clicked(bool checked)
{
    if (checked)
       this->graph3D->setShadowQuality(QAbstract3DGraph::ShadowQualityMedium);
    else
       this->graph3D->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
}

// 15. 显示倒影
void Test3DMap::on_chkBoxReflection_clicked(bool checked)
{
    this->graph3D->setReflection(checked);
}

// 16. 平滑效果
void Test3DMap::on_chkBoxSmooth_clicked(bool checked)
{
    this->series->setMeshSmooth(checked);
}

// 17. Y轴反转
void Test3DMap::on_chkBoxReverse_clicked(bool checked)
{
    graph3D->axisY()->setReversed(checked);
}

// 18. 轴标签可见
void Test3DMap::on_chkBoxItemLabel_clicked(bool checked)
{
    this->series->setItemLabelVisible(checked);
}

// 19. 轴标题可见
void Test3DMap::on_chkBoxAxisTitle_clicked(bool checked)
{
    this->graph3D->axisX()->setTitleVisible(checked);
    this->graph3D->axisY()->setTitleVisible(checked);
    this->graph3D->axisZ()->setTitleVisible(checked);
}

//  20. 轴背景可见
void Test3DMap::on_chkBoxAxisBackground_clicked(bool checked)
{
    this->graph3D->activeTheme()->setLabelBackgroundEnabled(checked);
}

// 21. 渐变色1
void Test3DMap::on_btnGrad1_clicked()
{
    QLinearGradient gr;
    gr.setColorAt(0.0, Qt::black);
    gr.setColorAt(0.33, Qt::blue);
    gr.setColorAt(0.67, Qt::red);
    gr.setColorAt(1.0, Qt::yellow);

    this->series->setBaseGradient(gr);
    this->series->setColorStyle(Q3DTheme::ColorStyleRangeGradient); // 按照高度渐变
}

// 22. 渐变色2
void Test3DMap::on_btnGrad2_clicked()
{
    QLinearGradient grGtoR;
    grGtoR.setColorAt(1.0, Qt::darkGreen);
    grGtoR.setColorAt(0.5, Qt::yellow);
    grGtoR.setColorAt(0.2, Qt::red);
    grGtoR.setColorAt(0.0, Qt::darkRed);

    this->series->setBaseGradient(grGtoR);
    this->series->setColorStyle(Q3DTheme::ColorStyleRangeGradient);// 按照高度渐变
}

// 23. 设置颜色
void Test3DMap::on_btnBarColor_clicked()
{
    QColor  color=this->series->baseColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
    {
        this->series->setBaseColor(color);
        this->series->setColorStyle(Q3DTheme::ColorStyleUniform); // 单一颜色
    }
}
