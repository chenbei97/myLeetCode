#include "myVideoWidget.h"
#include <QKeyEvent>
#include <QMouseEvent>

myVideoWidget::myVideoWidget(QWidget*parent):QVideoWidget(parent)
{

}

// 按键事件,按下ESC可以退出全屏状态
void myVideoWidget::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Escape)&&(this->isFullScreen()))
    {
        this->setFullScreen(false);
        event->accept();
        QVideoWidget::keyPressEvent(event);
    }
}

// 鼠标单击可以控制暂停和继续播放
void myVideoWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    {
        if (thePlayer->state()==QMediaPlayer::PlayingState) //如果是播放状态,视频暂停
          thePlayer->pause();
        else
          thePlayer->play();
    }
    QVideoWidget::mousePressEvent(event); // 事件传递给父对象
}

void myVideoWidget::setMediaPlayer(QMediaPlayer *player)
{
    this->thePlayer = player;
}
