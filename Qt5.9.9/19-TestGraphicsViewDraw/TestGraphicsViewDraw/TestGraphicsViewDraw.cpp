#include "TestGraphicsViewDraw.h"
#include "ui_TestGraphicsViewDraw.h"
#include <QTime>
TestGraphicsViewDraw::TestGraphicsViewDraw(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestGraphicsViewDraw)
{
        ui->setupUi(this);
        qsrand(QTime::currentTime().second()); // 随机种子
        this->initViewScene();
        this->initStatusBar();
        this->initMouseEventConnection();
}

TestGraphicsViewDraw::~TestGraphicsViewDraw()
{
      delete ui;
}

// 1. 初始化视图、场景
void TestGraphicsViewDraw::initViewScene()
{
      this->resize(1200,600);
      ui->graphicsView->resize(1100,500); // 左边和上方工具栏占据了100
      this->scene=new QGraphicsScene(-550,-250,1100,500); //创建QGraphicsScene
      ui->graphicsView->setScene(this->scene); //与graphicsView关联
      ui->graphicsView->setCursor(Qt::CrossCursor); //设置鼠标样式
      ui->graphicsView->setMouseTracking(true); // 必须wei true,否则鼠标移动事件无法响应
      ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
      this->setCentralWidget(ui->graphicsView);
}

// 2. 初始化状态栏
void TestGraphicsViewDraw::initStatusBar()
{
    this->labViewCord=new QLabel("视图(物理)坐标："); //创建状态栏标签
    this->labViewCord->setMinimumWidth(200);
    ui->statusbar->addWidget(this->labViewCord);

    this->labSceneCord=new QLabel("场景(逻辑)坐标：");
    this->labSceneCord->setMinimumWidth(200);
    ui->statusbar->addWidget(this->labSceneCord);

    this->labItemCord=new QLabel("图形项(局部逻辑)坐标：");
    this->labItemCord->setMinimumWidth(200);
    ui->statusbar->addWidget(this->labItemCord);

    this->labItemInfo=new QLabel("图形项信息: ");
    this->labItemInfo->setMinimumWidth(200);
    ui->statusbar->addWidget(this->labItemInfo);
}

// 3. 初始化鼠标事件连接
void TestGraphicsViewDraw::initMouseEventConnection()
{
    QObject::connect(ui->graphicsView,SIGNAL(mouseMovePoint(QPoint)),
                     this, SLOT(on_mouseMovePoint(QPoint)));
    QObject::connect(ui->graphicsView,SIGNAL(mouseClicked(QPoint)),
                     this, SLOT(on_mouseClicked(QPoint)));
    QObject::connect(ui->graphicsView,SIGNAL(mouseDoubleClick(QPoint)),
                     this, SLOT(on_mouseDoubleClick(QPoint)));
    QObject::connect(ui->graphicsView,SIGNAL(keyPress(QKeyEvent*)),
                     this, SLOT(on_keyPress(QKeyEvent*)));
}
