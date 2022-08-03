#include "TestVideoPlayBack.h"
#include "ui_TestVideoPlayBack.h"
#include <QDebug>
#include "videoWidgetBased.h"
#include "graphicsVideoItemBased.h"
#include "operateCamera.h"

TestVideoPlayBack::TestVideoPlayBack(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestVideoPlayBack)
{
    ui->setupUi(this);
}

TestVideoPlayBack::~TestVideoPlayBack()
{
    delete ui;
}

// 基于VideoWidget的视频播放器
void TestVideoPlayBack::on_actVideoWidget_triggered()
{
    videoWidgetBased *videoWidget = new videoWidgetBased;
    videoWidget->setWindowTitle("基于VideoWidget的视频播放器");
    videoWidget->setAttribute(Qt::WA_DeleteOnClose);
    connect(videoWidget,SIGNAL(windowClosed(bool)),this,SLOT(onAct1WindowClosed(bool)));
    videoWidget->show();
}

// 基于GraphicsVideoItem的视频播放器
void TestVideoPlayBack::on_actGraphicsVideoItem_triggered()
{
    graphicsVideoItem * videoItem = new graphicsVideoItem;
    videoItem->setWindowTitle("基于GraphicsVideoItem的视频播放器");
    videoItem->setAttribute(Qt::WA_DeleteOnClose);
    connect(videoItem,SIGNAL(windowClosed(bool)),this,SLOT(onAct2WindowClosed(bool)));
    videoItem->show();
}

// 摄像头操作
void TestVideoPlayBack::on_actOperateCamera_triggered()
{
    operateCamera * camera = new operateCamera;
    camera->setWindowTitle("摄像头操作");
    camera->setAttribute(Qt::WA_DeleteOnClose);
    connect(camera,SIGNAL(windowClosed(bool)),this,SLOT(onAct3WindowClosed(bool)));
    camera->show();
}

void TestVideoPlayBack::onAct1WindowClosed(bool close)
{
    ui->actVideoWidget->setEnabled(close);
}

void TestVideoPlayBack::onAct2WindowClosed(bool close)
{
    ui->actGraphicsVideoItem->setEnabled(close);
}

void TestVideoPlayBack::onAct3WindowClosed(bool close)
{
    ui->actOperateCamera->setEnabled(close);
}

