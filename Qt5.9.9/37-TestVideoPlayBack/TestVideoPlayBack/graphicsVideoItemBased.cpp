#include "graphicsVideoItemBased.h"
#include "ui_graphicsVideoItemBased.h"
#include <QFileDialog>
#include <QCloseEvent>
#include <QShowEvent>

graphicsVideoItem::graphicsVideoItem(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::graphicsVideoItem)
{
      ui->setupUi(this);
      this->player = new QMediaPlayer(this);//创建视频播放器
      this->player->setNotifyInterval(2000);//通知属性更新的周期2s一次
      this->initGraphicsScene();
      this->player->setVideoOutput(this->videoItem);//播放器关联输出设备
      connect(this->player,SIGNAL(stateChanged(QMediaPlayer::State)),this, SLOT(onStateChanged(QMediaPlayer::State)));
      connect(this->player,SIGNAL(positionChanged(qint64)),this, SLOT(onPositionChanged(qint64)));
      connect(this->player,SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));
}

graphicsVideoItem::~graphicsVideoItem()
{
  delete ui;
}

void graphicsVideoItem::showEvent(QShowEvent *event)
{
    emit windowClosed(false);
    event->accept();
}
void graphicsVideoItem::closeEvent(QCloseEvent *event)
{
    emit windowClosed(true);
    event->accept();
}

void graphicsVideoItem::initGraphicsScene()
{
      this->scene = new QGraphicsScene(this); // 新建场景
      ui->graphicsView->setScene(scene); // 视图设置场景
      this->videoItem = new QGraphicsVideoItem;
      this->videoItem->setFlags(QGraphicsItem::ItemIsMovable // 设置图形项可移动/可选择以及可聚焦
                     | QGraphicsItem::ItemIsSelectable
                     | QGraphicsItem::ItemIsFocusable);
      this->videoItem->setSize(QSize(760,420));
      scene->addItem(videoItem); // 把图形项加入场景

//    QGraphicsEllipseItem *item1=new QGraphicsEllipseItem(0,0,100,50); //局部逻辑坐标,宽200高100
//    item1->setPos(0,0); // 局部坐标系的中心位置
//    item1->setBrush(QBrush(Qt::blue));
//    item1->setFlags(QGraphicsItem::ItemIsMovable
//                   | QGraphicsItem::ItemIsSelectable
//                   | QGraphicsItem::ItemIsFocusable);
//    scene->addItem(item1); // 添加椭圆图形项

//    QGraphicsEllipseItem   *item2=new QGraphicsEllipseItem(50,50,50,50); //正圆,半径50
//    item2->setPos(100,100);
//    item2->setBrush(QBrush(Qt::red));
//    item2->setFlags(QGraphicsItem::ItemIsMovable
//                   | QGraphicsItem::ItemIsSelectable
//                   | QGraphicsItem::ItemIsFocusable);
//    scene->addItem(item2);
}
// （1）player的3个信号
void graphicsVideoItem::onStateChanged(QMediaPlayer::State state)
{
      // 状态变化后更改播放的使能
      ui->btnPlay_->setEnabled(!(state==QMediaPlayer::PlayingState));
      ui->btnPause_->setEnabled(state==QMediaPlayer::PlayingState);
      ui->btnStop_->setEnabled(state==QMediaPlayer::PlayingState);
}
void graphicsVideoItem::onDurationChanged(qint64 duration)
{
    // 文件总时长更新
    ui->sliderPosition_->setMaximum(duration);
    int secs=duration/1000;//秒
    int mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    this->durationTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio_->setText(this->positionTime+"/"+this->durationTime);
}
void graphicsVideoItem::onPositionChanged(qint64 position)
{
    // 播放进度更新
    if (ui->sliderPosition_->isSliderDown())
        return; //如果正在拖动滑条，退出
    ui->sliderPosition_->setSliderPosition(position);//更新进度
    int secs=position/1000;//秒
    int mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    positionTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio_->setText(this->positionTime+"/"+this->durationTime);
}

// （2）播放功能：添加播放文件、开始播放、暂停播放、停止播放、静音功能
void graphicsVideoItem::on_btnAdd__clicked()
{
    QString curPath=QDir::homePath();//获取系统当前目录
    QString dlgTitle="选择视频文件"; //对话框标题
    QString filter="wmv文件(*.wmv);;mp3文件(*.mp3);;mp4文件(*.mp4);;所有文件(*.*)"; //文件过滤器
    QString aFile=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if (aFile.isEmpty())
      return;
    QFileInfo fileInfo(aFile);
    ui->LabCurMedia_->setText("正在播放的视频："+fileInfo.fileName()); //获取文件信息显示
    this->player->setMedia(QUrl::fromLocalFile(aFile));//设置播放文件
    // this->player->play();
}
void graphicsVideoItem::on_btnSound__clicked()
{
    bool mute=player->isMuted(); // 与静音状态互斥的点击
    player->setMuted(!mute);
    if (mute) ui->btnSound_->setIcon(QIcon(":/images/volumn.bmp"));
    else ui->btnSound_->setIcon(QIcon(":/images/mute.bmp"));
}
void graphicsVideoItem::on_btnPlay__clicked(){this->player->play();}
void graphicsVideoItem::on_btnPause__clicked(){this->player->pause();}
void graphicsVideoItem::on_btnStop__clicked(){this->player->stop();}

// （3）2个滑动条，调节音量和调节播放进度
void graphicsVideoItem::on_sliderVolumn__valueChanged(int value){ this->player->setVolume(value); }
void graphicsVideoItem::on_sliderPosition__valueChanged(int value){ this->player->setPosition(value); }
