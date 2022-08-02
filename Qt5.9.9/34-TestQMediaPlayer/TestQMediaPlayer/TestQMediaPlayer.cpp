#include "TestQMediaPlayer.h"
#include "ui_TestQMediaPlayer.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>

TestQMediaPlayer::TestQMediaPlayer(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestQMediaPlayer)
{
      ui->setupUi(this);
      ui->btnSound->setIcon(QIcon(":/images/volumn.bmp"));

      QDir appPath = QDir::current();
      appPath.cdUp();
      appPath.cd(QCoreApplication::applicationName()+"/sound");
      // qDebug()<<appPath.path();
      this->soundSourcePath = appPath.path()+"/"; // 音效文件的所在位置
      this->sound=new QSoundEffect;
      this->sound->setLoopCount(3);

      this->player = new QMediaPlayer(this);//播放器
      this->playlist = new QMediaPlaylist(this);//播放列表
      this->playlist->setPlaybackMode(QMediaPlaylist::Loop); //循环模式
      player->setPlaylist(playlist); // 播放器设置好播放列表
      // 连接好播放器的3个信号和播放列表的1个信号和槽函数
      connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this, SLOT(onStateChanged(QMediaPlayer::State)));
      connect(player,SIGNAL(positionChanged(qint64)),this, SLOT(onPositionChanged(qint64)));
      connect(player,SIGNAL(durationChanged(qint64)),this, SLOT(onDurationChanged(qint64)));
      connect(playlist,SIGNAL(currentIndexChanged(int)),this, SLOT(onPlaylistChanged(int)));
}

TestQMediaPlayer::~TestQMediaPlayer()
{
      delete ui;
}

// 1. 自定义槽函数之播放状态变化
void TestQMediaPlayer::onStateChanged(QMediaPlayer::State state)
{
    ui->btnPlay->setEnabled(!(state==QMediaPlayer::PlayingState)); // 播放模式时,播放模式不可用
    ui->btnPause->setEnabled(state==QMediaPlayer::PlayingState); // 是播放模式,停止可用;否则说明是暂停或停止了不需要停止
    ui->btnStop->setEnabled(state==QMediaPlayer::PlayingState); // 同理
}

// 2. 自定义槽函数之播放列表变化
void TestQMediaPlayer::onPlaylistChanged(int position)
{
    // postion是playlist正在播放的位置,如果有变化,把listWidget和playlist同步同时更新显示信息
    ui->listWidget->setCurrentRow(position); // listWdiget当前聚焦行
    QListWidgetItem  *item=ui->listWidget->currentItem();
    if (item) // 如果不为空
        ui->LabCurMedia->setText("当前播放曲目："+item->text());//同步更新正在播放的文件名
}

// 3. 自定义槽函数之文件长度变化
void TestQMediaPlayer::onDurationChanged(qint64 duration)
{
    ui->sliderPosition->setMaximum(duration); //文件总长度影响的是滑动条的最大值
     int   secs=duration/1000;//秒
     int   mins=secs/60; //分钟
     secs=secs % 60;//余数秒
     this->durationTime=QString::asprintf("%d:%d",mins,secs); //durationTim需要调整
     ui->LabRatio->setText("进度："+this->positionTime+"/"+durationTime); //进度：当前播放位置/总时长
}

// 4. 自定义槽函数之播放位置变化
void TestQMediaPlayer::onPositionChanged(qint64 position)
{
    if (ui->sliderPosition->isSliderDown()) // 滑动条滑块如果是按下状态就返回
        return;
    ui->sliderPosition->setSliderPosition(position);//设置当前位置
    int   secs=position/1000;//秒
    int   mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    this->positionTime=QString::asprintf("%d:%d",mins,secs); // 播放位置需要调整
    ui->LabRatio->setText("进度："+this->positionTime+"/"+this->durationTime);
}

// 5. listWdiget的添加功能
void TestQMediaPlayer::on_btnAdd_clicked()
{
     QString curPath=QDir::homePath();//获取系统当前目录
     QString dlgTitle="选择音频文件"; //对话框标题
     QString filter="音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)"; //文件过滤器
     QStringList fileList=QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter); // 支持一次性打开多个文件

     if (fileList.count()<1)
         return;

     for (int i=0; i<fileList.count();i++)
     {
        QString aFile=fileList.at(i);
        playlist->addMedia(QUrl::fromLocalFile(aFile));//添加文件,利用QUrl的静态函数获取本地文件（也可以是网络文件）
        QFileInfo   fileInfo(aFile); // 文件信息
        ui->listWidget->addItem(fileInfo.fileName());//播放文件的名称添加进去
     }

     if (player->state()!=QMediaPlayer::PlayingState) // 如果不是播放状态就从头开始播放
         playlist->setCurrentIndex(0);
     // player->play(); //开始播放
}

// 6. listWdiget的移除功能
void TestQMediaPlayer::on_btnRemove_clicked()
{
    int pos=ui->listWidget->currentRow(); // 获取当前选中的曲目位置
    QListWidgetItem *item=ui->listWidget->takeItem(pos); // 取出然后删除
    delete item;//从listWidget里删除

    if (playlist->currentIndex()==pos) //如果移除的正好是是当前播放的曲目
    {
        playlist->removeMedia(pos);//从播放列表里移除

        int nextPos=0; //新的播放位置默认是0
        if (pos>=1) // 如果之前的播放位置不是第1首,那么当前播放的可以调整为原来播放位置的前1个
            nextPos=pos-1;

        if (ui->listWidget->count()>0) //如果还有至少曲目,那么nextPos=0表示的是第一首
        {
            playlist->setCurrentIndex(nextPos); // 设置该位置的曲目为当前播放曲目(nextPos=0说明只有1首,不为0说明≥2首)
            this->onPlaylistChanged(nextPos); // 更新当前播放的曲目
        }
        else
        {
            player->stop(); // 如果没有曲目了,比如说原来只有1首还移除了就不用再播放了
            ui->LabCurMedia->setText("当前播放曲目：无曲目");
        }
    }
    else
        playlist->removeMedia(pos); // 如果移除的不是当前播放的曲目,位置不需要更新直接移除就像
}

// 7. listWdiget的清除功能
void TestQMediaPlayer::on_btnClear_clicked()
{
    playlist->clear();
    ui->listWidget->clear();
    player->stop();
}

// 8.双击listWidget项时播放曲目
void TestQMediaPlayer::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int rowNow=index.row();
    playlist->setCurrentIndex(rowNow);
    // qDebug()<<"playlist's error : "<<playlist->errorString();
    player->play();
    // qDebug()<<"player's error : "<<player->errorString();
}

// 9. 开始播放
void TestQMediaPlayer::on_btnPlay_clicked()
{
    if (playlist->currentIndex()<0) // 因为前一首功能很可能变成<0
        playlist->setCurrentIndex(0);
    player->play();
}

// 10. 暂停播放
void TestQMediaPlayer::on_btnPause_clicked()
{
    player->pause();
}

// 11. 停止播放
void TestQMediaPlayer::on_btnStop_clicked()
{
    player->stop();
}

// 12. 播放进度控制
void TestQMediaPlayer::on_sliderPosition_valueChanged(int value)
{
    player->setPosition(value);
}

// 13. 上一首
void TestQMediaPlayer::on_btnPrevious_clicked()
{
    playlist->previous();
}

// 14.下一首
void TestQMediaPlayer::on_btnNext_clicked()
{
    playlist->next();
}

// 15. 调整音量
void TestQMediaPlayer::on_sliderVolumn_valueChanged(int value)
{
    player->setVolume(value);
}

// 16. 静音控制
void TestQMediaPlayer::on_btnSound_clicked()
{
    bool mute=player->isMuted();
    player->setMuted(!mute); // 与当前勾选的互斥
    if (mute)
        ui->btnSound->setIcon(QIcon(":/images/volumn.bmp"));
    else
        ui->btnSound->setIcon(QIcon(":/images/mute.bmp"));
}

// 17. 播放音效（用于其它音效按钮调用）
void TestQMediaPlayer::playSound(QString weapon)
{
    QString filename=this->soundSourcePath+weapon;
    QSound::play(filename); //QSound只能播放本地WAV文件,且是异步方式
}

// 18.以下是各种音效,依次是AK47,机枪.开枪,炮弹,地雷,坦克,火攻12,爆炸12
void TestQMediaPlayer::on_pushButton1_clicked()
{
    playSound("Ak7.wav");
}

void TestQMediaPlayer::on_pushButton2_clicked()
{
    playSound("machinegun.wav");
}

void TestQMediaPlayer::on_pushButton3_clicked()
{
    playSound("gun.wav");
}

void TestQMediaPlayer::on_pushButton4_clicked()
{
    playSound("shell.wav");
}

void TestQMediaPlayer::on_pushButton5_clicked()
{
    playSound("mine.wav");
}

void TestQMediaPlayer::on_pushButton6_clicked()
{
    playSound("fire.wav");
}

void TestQMediaPlayer::on_pushButton7_clicked()
{
    playSound("fire2.wav");
}

void TestQMediaPlayer::on_pushButton8_clicked()
{
    playSound("blast.wav");
}

void TestQMediaPlayer::on_pushButton9_clicked()
{
    playSound("blast2.wav");
}

void TestQMediaPlayer::on_pushButton10_clicked()
{
    playSound("Ak7.wav");
}
