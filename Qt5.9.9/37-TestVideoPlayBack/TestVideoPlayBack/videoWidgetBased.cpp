#include "videoWidgetBased.h"
#include "ui_videoWidgetBased.h"
#include <QFileDialog>
#include <QCloseEvent>
#include <QShowEvent>

videoWidgetBased::videoWidgetBased(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::videoWidgetBased)
{
      ui->setupUi(this);
      this->player = new QMediaPlayer(this);//创建视频播放器
      this->player->setNotifyInterval(2000);//通知属性更新的周期2s一次
      this->player->setVideoOutput(ui->videoWidget);//播放器设置视频输出组件
      ui->videoWidget->setMediaPlayer(this->player);//输出组件也关联播放器
      connect(this->player,SIGNAL(stateChanged(QMediaPlayer::State)),this, SLOT(onStateChanged(QMediaPlayer::State)));
      connect(this->player,SIGNAL(positionChanged(qint64)),this, SLOT(onPositionChanged(qint64)));
      connect(this->player,SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));
}

videoWidgetBased::~videoWidgetBased()
{
      delete ui;
}

void videoWidgetBased::showEvent(QShowEvent *event)
{
    emit windowClosed(false);
    event->accept();
}
void videoWidgetBased::closeEvent(QCloseEvent *event)
{
    emit windowClosed(true);
    event->accept();
}

// （1）player的3个信号
void videoWidgetBased::onStateChanged(QMediaPlayer::State state)
{
      // 状态变化后更改播放的使能
      ui->btnPlay->setEnabled(!(state==QMediaPlayer::PlayingState));
      ui->btnPause->setEnabled(state==QMediaPlayer::PlayingState);
      ui->btnStop->setEnabled(state==QMediaPlayer::PlayingState);
}
void videoWidgetBased::onDurationChanged(qint64 duration)
{
    // 文件总时长更新
    ui->sliderPosition->setMaximum(duration);
    int secs=duration/1000;//秒
    int mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    this->durationTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(this->positionTime+"/"+this->durationTime);
}
void videoWidgetBased::onPositionChanged(qint64 position)
{
    // 播放进度更新
    if (ui->sliderPosition->isSliderDown())
        return; //如果正在拖动滑条，退出
    ui->sliderPosition->setSliderPosition(position);//更新进度
    int secs=position/1000;//秒
    int mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    positionTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(this->positionTime+"/"+this->durationTime);
}

// （2）播放功能：添加播放文件、开始播放、暂停播放、停止播放、静音功能以及全屏播放
void videoWidgetBased::on_btnAdd_clicked()
{
    QString curPath=QDir::homePath();//获取系统当前目录
    QString dlgTitle="选择视频文件"; //对话框标题
    QString filter="wmv文件(*.wmv);;mp3文件(*.mp3);;mp4文件(*.mp4);;所有文件(*.*)"; //文件过滤器
    QString aFile=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if (aFile.isEmpty())
      return;
    QFileInfo fileInfo(aFile);
    ui->LabCurMedia->setText("正在播放的视频："+fileInfo.fileName()); //获取文件信息显示
    this->player->setMedia(QUrl::fromLocalFile(aFile));//设置播放文件
    // this->player->play();
}
void videoWidgetBased::on_btnSound_clicked()
{
    bool mute=player->isMuted(); // 与静音状态互斥的点击
    player->setMuted(!mute);
    if (mute) ui->btnSound->setIcon(QIcon(":/images/volumn.bmp"));
    else ui->btnSound->setIcon(QIcon(":/images/mute.bmp"));
}
void videoWidgetBased::on_btnPlay_clicked(){this->player->play();}
void videoWidgetBased::on_btnPause_clicked(){this->player->pause();}
void videoWidgetBased::on_btnStop_clicked(){this->player->stop();}
void videoWidgetBased::on_pushButton_clicked(){ui->videoWidget->setFullScreen(true);}

// （3）2个滑动条，调节音量和调节播放进度
void videoWidgetBased::on_sliderVolumn_valueChanged(int value){ this->player->setVolume(value); }
void videoWidgetBased::on_sliderPosition_valueChanged(int value){ this->player->setPosition(value); }
