#include "Test3DBar.h"
#include "ui_Test3DBar.h"
#include    <QSplitter>
#include    <QColorDialog>

Test3DBar::Test3DBar(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Test3DBar)
{
      ui->setupUi(this);
      this->setWindowIcon(QIcon(":/images/3DBar.jpg"));
      this->iniGraph3D();
      QSplitter * splitter = new QSplitter(Qt::Horizontal);//水平分割
      splitter->addWidget(ui->groupBox); // groupBox是左侧的属性控制面板,与之分隔
      splitter->addWidget(this->graphContainer) ; //右侧图表预留空间,分隔
      this->setCentralWidget(splitter);
}

Test3DBar::~Test3DBar()
{
    delete ui;
}

// 1. 创建图表
void Test3DBar::iniGraph3D()
{
    this->graph3D = new Q3DBars();
    // 因为三维图形类都是从QWindow继承而来不能简单使用QWidget部件作为Q3DBars组件的容器
    // 也就是不能主窗口放置一个QWidget组件然后作为Q3DBars组件的容器
    // 必须使用QWidget::createWindowContainer动态创建QWidget作为容器
    this->graphContainer = QWidget::createWindowContainer(this->graph3D); //Q3DBars继承自QWindow
    // 此属性设置从什么视觉来看三维图,鼠标右键就可以直接控制
    this->graph3D->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFrontHigh);
    this->graph3D->setFlags(this->graph3D->flags() ^ Qt::FramelessWindowHint);

    // Z轴设置
    QValue3DAxis *axisV=new QValue3DAxis; //数值坐标
    axisV->setTitle("Z轴");
    axisV->setTitleVisible(true);

    // X轴设置
    QCategory3DAxis *axisRow=new QCategory3DAxis; // 文字坐标
    axisRow->setTitle("X轴");
    QStringList rowLabs;  rowLabs << "x1" << "x2"<<"x3"; // X轴标签
    axisRow->setLabels(rowLabs);
    axisRow->setTitleVisible(true);

    // Y轴设置
    QCategory3DAxis *axisCol=new QCategory3DAxis;
    QStringList colLabs; colLabs << "y1" << "y2" << "y3" << "y4"<<"y5";
    axisCol->setTitle("Y轴");
    axisCol->setLabels(colLabs);
    axisCol->setTitleVisible(true);

    this->graph3D->setValueAxis(axisV);
    this->graph3D->setRowAxis(axisRow);
    this->graph3D->setColumnAxis(axisCol);

    // 创建序列
    this->series = new QBar3DSeries;
    // 此属性改变显示的样式是长方体、圆柱体、金字塔型
    this->series->setMesh(QAbstract3DSeries::MeshBar); //MeshBar,MeshPyramid,MeshCylinder
    this->series->setItemLabelFormat("(@rowLabel,@colLabel): %.1f"); //项的标签显示格式
   // @rowTitle,@colTitle,@valueTitle,@rowIdx,@colIdx,@rowLabel,@colLabel,@valueLabel,@seriesName,%<format spec>;
    QBarDataArray *dataSet = new QBarDataArray; //数据代理
    dataSet->reserve(rowLabs.count());// 预留指定的行数
    QBarDataRow *dataRow = new QBarDataRow;
    *dataRow << 1 << 2<< 3<< 4<<5; //第1行数据，有5列
    dataSet->append(dataRow);
    QBarDataRow *dataRow2 = new QBarDataRow;
    *dataRow2 << 5<< 5<< 5<< 5<<5; //第2行数据，有5列
    dataSet->append(dataRow2);
    QBarDataRow *dataRow3 = new QBarDataRow;
    *dataRow3 << 1<< 5<< 9<< 5<<1; //第3行数据，有5列
    dataSet->append(dataRow3);

    this->series->dataProxy()->resetArray(dataSet);
    this->graph3D->addSeries(series);
}

// 2. 图表的视角设定
void Test3DBar::on_comboCamera_currentIndexChanged(int index)
{
     Q3DCamera::CameraPreset  cameraPos=Q3DCamera::CameraPreset(index);
     this->graph3D->scene()->activeCamera()->setCameraPreset(cameraPos);
}

// 3. 水平旋转
void Test3DBar::on_sliderH_valueChanged(int value)
{
      Q_UNUSED(value);
      int xRot =ui->sliderH->value();//水平
      int yRot=ui->sliderV->value(); //垂直
      int zoom=ui->sliderZoom->value(); //缩放
      graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot,zoom); // 设置视角位置
}

// 4. 垂直旋转
void Test3DBar::on_sliderV_valueChanged(int value)
{
    this->on_sliderH_valueChanged(value); // 共用1个即可
}

// 5. 缩放
void Test3DBar::on_sliderZoom_valueChanged(int value)
{
    this->on_sliderH_valueChanged(value); // 共用1个即可
}

// 6. 主题样式
void Test3DBar::on_cBoxTheme_currentIndexChanged(int index)
{
    Q3DTheme *currentTheme = this->graph3D->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(index));
}

// 7. 棒图样式
void Test3DBar::on_cBoxBarStyle_currentIndexChanged(int index)
{
    QAbstract3DSeries::Mesh aMesh=QAbstract3DSeries::Mesh(index);
    this->series->setMesh(aMesh);
}

// 8. 选择模式
void Test3DBar::on_cBoxSelectionMode_currentIndexChanged(int index)
{
    this->graph3D->setSelectionMode(QAbstract3DGraph::SelectionFlags(index));
}

// 9. 字体大小
void Test3DBar::on_spinFontSize_valueChanged(int arg1)
{
    QFont font = graph3D->activeTheme()->font();
    font.setPointSize(arg1);
    this->graph3D->activeTheme()->setFont(font);
}

// 10. 设置序列项颜色
void Test3DBar::on_btnBarColor_clicked()
{
    QColor  color=series->baseColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
        this->series->setBaseColor(color);
}

// 11. 显示背景
void Test3DBar::on_chkBoxBackground_clicked(bool checked)
{
    this->graph3D->activeTheme()->setBackgroundEnabled(checked);
}

// 12. 显示背景网格
void Test3DBar::on_chkBoxGrid_clicked(bool checked)
{
     this->graph3D->activeTheme()->setGridEnabled(checked);
}

// 13. 光滑效果
void Test3DBar::on_chkBoxSmooth_clicked(bool checked)
{
       this->series->setMeshSmooth(checked);
      // this->graph3D->seriesList().at(0)->setMeshSmooth(checked);
}

// 14. 反射效果显示倒影
void Test3DBar::on_chkBoxReflection_clicked(bool checked)
{
     this->graph3D->setReflection(checked);
}

// 15. 数值坐标轴反向
void Test3DBar::on_chkBoxReverse_clicked(bool checked)
{
    this->graph3D->valueAxis()->setReversed(checked);
}

// 16. 项标签可见
void Test3DBar::on_chkBoxItemLabel_clicked(bool checked)
{
    this->series->setItemLabelFormat("value at (@rowLabel,@colLabel): %.1f");
    this->series->setItemLabelVisible(checked);
}

// 17. 轴标题
void Test3DBar::on_chkBoxAxisTitle_clicked(bool checked)
{
    this->graph3D->valueAxis()->setTitleVisible(checked);
    this->graph3D->rowAxis()->setTitleVisible(checked);
    this->graph3D->columnAxis()->setTitleVisible(checked);
}

// 18. 轴标签背景可见
void Test3DBar::on_chkBoxAxisBackground_clicked(bool checked)
{
    this->graph3D->activeTheme()->setLabelBackgroundEnabled(checked);
}
