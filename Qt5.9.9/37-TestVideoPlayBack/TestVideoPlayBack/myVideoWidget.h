#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H

#include <QVideoWidget>
#include <QMediaPlayer>

class myVideoWidget : public QVideoWidget
{
  Q_OBJECT
public:
    explicit myVideoWidget(QWidget * parent = Q_NULLPTR);
    void setMediaPlayer(QMediaPlayer *player); // 视频播放组件可以设置播放器对象
private:
    QMediaPlayer *thePlayer;//视频播放器作为组合关系使用
protected: // 定义自己的鼠标事件,是QVideoWidget原本没有的
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MYVIDEOWIDGET_H
