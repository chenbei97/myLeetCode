#include "TestGraphicsViewCooridate.h"
#include "ui_TestGraphicsViewCooridate.h"
#include    <QGraphicsEllipseItem>
#include <QDebug>

TestGraphicsViewCooridate::TestGraphicsViewCooridate(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestGraphicsViewCooridate)
{
      ui->setupUi(this);
      ui->graphicsView->setCursor(Qt::CrossCursor); // 设置鼠标类型为'+'
      ui->graphicsView->setMouseTracking(true); // 是否启用鼠标跟踪,如果禁用的话必须按下鼠标才能接受鼠标事件
      ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);// 设置鼠标左键在场景拖动的行为，将出现1根橡皮筋
      this->resize(1000,800);
      this->scene=new QGraphicsScene(QRect(-450,-320,900,640)); //场景逻辑坐标系定义
      ui->graphicsView->setScene(scene);
      this->initStatusBar();
      this->iniGraphicsSystem();
      QObject::connect(ui->graphicsView,SIGNAL(mouseMovePoint(QPoint)), this, SLOT(on_mouseMovePoint(QPoint)));
      QObject::connect(ui->graphicsView,SIGNAL(mouseClicked(QPoint)),this, SLOT(on_mouseClicked(QPoint)));
}

TestGraphicsViewCooridate::~TestGraphicsViewCooridate()
{
     delete ui;
}

// 1. 重载调整窗口事件(启动栅格布局就可以让组件随着窗口自适应调整了)
void TestGraphicsViewCooridate::resizeEvent(QResizeEvent *event)
{
    ui->LabView->setText(QString::asprintf("视图(物理)坐标,原点在左上角,视图宽度=%d,视图高度=%d",
                ui->graphicsView->width(),ui->graphicsView->height()));

    QRectF  rectF=ui->graphicsView->sceneRect(); // 获取视图的场景的矩形区
    ui->LabScene->setText(QString::asprintf("场景(逻辑)矩形区坐标=(Left,Top,Width,Height)=(%.0f,%.0f,%.0f,%.0f)",
                                                rectF.left(),rectF.top(),rectF.width(),rectF.height()));
}

// 2. 初始化状态栏
void TestGraphicsViewCooridate::initStatusBar()
{
    labViewCord=new QLabel("视图(物理)坐标：");
    labViewCord->setMinimumWidth(200);
    ui->statusbar->addWidget(labViewCord);

    labSceneCord=new QLabel("场景(逻辑)坐标：");
    labSceneCord->setMinimumWidth(200);
    ui->statusbar->addWidget(labSceneCord);

    labItemCord=new QLabel("图形项(局部逻辑)坐标：");
    labItemCord->setMinimumWidth(200);
    ui->statusbar->addWidget(labItemCord);
}

// 3. 鼠标移动事件
void TestGraphicsViewCooridate::on_mouseMovePoint(QPoint point)
{
    // point传进来的是视图坐标
    this->labViewCord->setText(QString::asprintf("视图(物理)坐标：(%d,%d)",point.x(),point.y()));
    QPointF pointScene=ui->graphicsView->mapToScene(point); //转换到场景坐标
    labSceneCord->setText(QString::asprintf("场景(逻辑)坐标：(%.0f,%.0f)", pointScene.x(),pointScene.y()));
}

// 4. 鼠标单击事件
void TestGraphicsViewCooridate::on_mouseClicked(QPoint point)
{
    // point传进来的是视图坐标
    QPointF pointScene=ui->graphicsView->mapToScene(point); // 转换为场景坐标
    QGraphicsItem  *item=nullptr; // 图形项

    // QGraphicsItem *QGraphicsScene::itemAt(const QPointF &position, const QTransform &deviceTransform) const;
    // 返回指定位置的顶层图形项，如果此位置没有图形项，则返回 0
    // deviceTransform 是应用于视图的转换，如果场景包含忽略转换的项目，则需要提供该转换
    item=scene->itemAt(pointScene,ui->graphicsView->transform()); //获取指定位置的图形项
    // qDebug()<<"mouse is pressed";
    if (item != nullptr) //有图形项
    {
        QPointF pointItem=item->mapFromScene(pointScene); //继续转换为图形项的局部逻辑坐标
        labItemCord->setText(QString::asprintf("图形项(局部逻辑)坐标：(%.0f,%.0f)", pointItem.x(),pointItem.y()));
    }
}

// 5. 在视图上绘制一些图形
void TestGraphicsViewCooridate::iniGraphicsSystem()
{
    // 1.画一个矩形框大小等于scene
    QGraphicsRectItem   *item1=new QGraphicsRectItem(QRect(-400,-300,800,600)); //使用场景坐标,稍小于视图的大小,(-400,-300)是场景坐标
    item1->setFlags(QGraphicsItem::ItemIsSelectable     //可选,可以有焦点,但是不能移动
                   | QGraphicsItem::ItemIsFocusable);
    QPen    pen;
    pen.setWidth(2);
    item1->setPen(pen);
    scene->addItem(item1);

    // 2. 画一个位于场景中心的椭圆,测试局部坐标
    QGraphicsEllipseItem   *item2=new QGraphicsEllipseItem(-200,-100,400,200); // (-200,-100)是场景坐标
    item2->setPos(0,0); // 设置在中心(场景坐标),缺省时也是(0,0)
    item2->setBrush(QBrush(Qt::blue));
    item2->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);
    scene->addItem(item2);

    // 4. 一个圆，中心位于场景的边缘
    QGraphicsEllipseItem   *item3=new QGraphicsEllipseItem(-100,-100,200,200); //
    item3->setPos(300,200); // 圆的半径100,右下角坐标(400,300),相切时中心的坐标应该在(400-100,300-100)
    item3->setBrush(QBrush(Qt::red));
    item3->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   /*| QGraphicsItem::ItemIsFocusable*/);
    scene->addItem(item3);

    scene->clearSelection(); // 清除当前选择
}
