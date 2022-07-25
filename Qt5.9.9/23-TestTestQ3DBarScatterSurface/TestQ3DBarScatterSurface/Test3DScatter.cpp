#include "Test3DScatter.h"
#include "ui_Test3DScatter.h"
#include    <QSplitter>
#include    <QColorDialog>
Test3DScatter::Test3DScatter(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Test3DScatter)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/3DScatter.jpg"));
    this->iniGraph3D();
    QSplitter   *splitter=new QSplitter(Qt::Horizontal);
    splitter->addWidget(ui->groupBox);
    splitter->addWidget(graphContainer);
    this->setCentralWidget(splitter);
}

Test3DScatter::~Test3DScatter()
{
    delete ui;
}

// 0. 初始化三维散点图
void Test3DScatter::iniGraph3D()
{
    this->graph3D = new Q3DScatter();
    this->graphContainer = QWidget::createWindowContainer(graph3D); //Q3DBars继承自QWindow，必须如此创建

    QScatterDataProxy *proxy = new QScatterDataProxy(); //数据代理
    this->series = new QScatter3DSeries(proxy);  //创建序列

    this->series->setItemLabelFormat("(@xLabel @yLabel @zLabel)");
    this->series->setMeshSmooth(true);
    this->series->setBaseColor(Qt::blue);
    this->series->setMesh(QAbstract3DSeries::MeshSphere); //MeshPoint, MeshCylinder
    this->series->setItemSize(0.2);//default 0. value 0~1
    this->graph3D->axisX()->setTitle("X轴");
    this->graph3D->axisX()->setTitleVisible(true);
    this->graph3D->axisY()->setTitle("Y轴");
    this->graph3D->axisY()->setTitleVisible(true);
    this->graph3D->axisZ()->setTitle("Z轴");
    this->graph3D->axisZ()->setTitleVisible(true);
    this->graph3D->activeTheme()->setLabelBackgroundEnabled(false);

    //墨西哥草帽,-10:0.5:10， N=41
    int N=41;
    int itemCount=N*N;
    QScatterDataArray *dataArray = new QScatterDataArray();
    dataArray->resize(itemCount); // 41×41个点
    QScatterDataItem *ptrToDataArray = &dataArray->first(); // 指向存储点的首个地址指针
    float x,y,z;
    int i,j;
    x=-10;
    for (i=1 ; i <=N; i++)
    {
        y=-10;
        for ( j =1; j <=N; j++)
        {
            z=qSqrt(x*x+y*y);
            if (z!=0)
                z=10*qSin(z)/z;
            else
                z=10;
            ptrToDataArray->setPosition(QVector3D(x,z,y)); // 指针在此位置设置的至为(x,z,y)+this->randVector()
            ptrToDataArray++;
            y+=0.5;
        }
        x+=0.5;
    }
    this->series->dataProxy()->resetArray(dataArray); // 把数据存入序列
    this->graph3D->addSeries(series);
}

// 1. 设置视角
void Test3DScatter::on_comboBox_currentIndexChanged(int index)
{
      this->graph3D->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPreset(index));
}

// 2. 水平旋转
void Test3DScatter::on_sliderH_valueChanged(int value)
{
    Q_UNUSED(value);
    int xRot =ui->sliderH->value(); // 水平旋转
    int yRot=ui->sliderV->value(); // 垂直旋转
    int zoom=ui->sliderZoom->value(); //缩放
    this->graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot,zoom);
}

// 3. 垂直旋转
void Test3DScatter::on_sliderV_valueChanged(int value)
{
      this->on_sliderH_valueChanged(value);
}

// 4. 缩放
void Test3DScatter::on_sliderZoom_valueChanged(int value)
{
    this->on_sliderH_valueChanged(value);
}

// 5.设置主题样式
void Test3DScatter::on_cBoxTheme_currentIndexChanged(int index)
{
    Q3DTheme *currentTheme = this->graph3D->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(index));
}

// 6.设置棒图样式
void Test3DScatter::on_cBoxBarStyle_currentIndexChanged(int index)
{
    QAbstract3DSeries::Mesh aMesh;
    aMesh=QAbstract3DSeries::Mesh(index);
    this->series->setMesh(aMesh);
}

// 7. 设置项选择模式
void Test3DScatter::on_cBoxSelectionMode_currentIndexChanged(int index)
{
      this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionFlags(index));
}

// 8. 设置字体大小
void Test3DScatter::on_spinFontSize_valueChanged(int arg1)
{
    QFont font = graph3D->activeTheme()->font();
    font.setPointSize(arg1);
    this->graph3D->activeTheme()->setFont(font);
}

// 9. 设置散点大小
void Test3DScatter::on_spinItemSize_valueChanged(double arg1)
{
    this->series->setItemSize(arg1);//default 0. value 0~1
}

// 10. 设置项颜色
void Test3DScatter::on_btnBarColor_clicked()
{
    QColor  color=series->baseColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
         this->series->setBaseColor(color);
}

// 11. 设置背景显示
void Test3DScatter::on_chkBoxBackground_clicked(bool checked)
{
      this->graph3D->activeTheme()->setBackgroundEnabled(checked);
}

// 12. 设置网格显示
void Test3DScatter::on_chkBoxGrid_clicked(bool checked)
{
    this->graph3D->activeTheme()->setGridEnabled(checked);
}

// 13. 设置阴影显示
void Test3DScatter::on_chkBoxShadow_clicked(bool checked)
{
    if (checked)
         this->graph3D->setShadowQuality(QAbstract3DGraph::ShadowQualityMedium);
    else
         this->graph3D->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
}

// 14. 设置倒影显示
void Test3DScatter::on_chkBoxReflection_clicked(bool checked)
{
      this->graph3D->setReflection(checked);
}

// 15. 设置平滑效果
void Test3DScatter::on_chkBoxSmooth_clicked(bool checked)
{
        this->series->setMeshSmooth(checked);
}

// 16. 设置Z轴反转
void Test3DScatter::on_chkBoxReverse_clicked(bool checked)
{
       this->graph3D->axisZ()->setReversed(checked);
}

// 17. 设置项标签显示
void Test3DScatter::on_chkBoxItemLabel_clicked(bool checked)
{
      this->series->setItemLabelVisible(checked);
}

// 18. 设置轴标题显示
void Test3DScatter::on_chkBoxAxisTitle_clicked(bool checked)
{
    this->graph3D->axisX()->setTitleVisible(checked);
    this->graph3D->axisY()->setTitleVisible(checked);
    this->graph3D->axisZ()->setTitleVisible(checked);
}

// 19.设置轴标签背景显示
void Test3DScatter::on_chkBoxAxisBackground_clicked(bool checked)
{
      this->graph3D->activeTheme()->setLabelBackgroundEnabled(checked);
}

// 20. 随机散点坐标向量
QVector3D Test3DScatter::randVector()
{
      return QVector3D(
                (float)(rand() % 100) / 2.0f - (float)(rand() % 100) / 2.0f,
                (float)(rand() % 100) / 100.0f - (float)(rand() % 100) / 100.0f,
                (float)(rand() % 100) / 2.0f - (float)(rand() % 100) / 2.0f);
}
