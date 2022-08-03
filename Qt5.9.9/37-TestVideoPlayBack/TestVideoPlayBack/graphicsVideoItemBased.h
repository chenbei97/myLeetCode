#ifndef GRAPHICSVIDEOITEM_H
#define GRAPHICSVIDEOITEM_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QGraphicsScene>

namespace Ui {
  class graphicsVideoItem;
}

class graphicsVideoItem : public QMainWindow
{
  Q_OBJECT
protected:
    void closeEvent(QCloseEvent * event);
    void showEvent(QShowEvent*event);
private:
    QGraphicsScene *scene;
    QGraphicsVideoItem *videoItem; // 输出组件(代替了myVideoWidget)
    QMediaPlayer *player;// 播放器
    QString durationTime;//视频总时长
    QString positionTime;// 视频当前播放进度
public:
  explicit graphicsVideoItem(QWidget *parent = nullptr);
  ~graphicsVideoItem();
private slots://自定义槽函数响应player的3个信号
    void onStateChanged(QMediaPlayer::State state);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
private slots:
    void on_btnAdd__clicked();
    void on_btnPlay__clicked();
    void on_btnPause__clicked();
    void on_btnStop__clicked();
    void on_btnSound__clicked();
    void on_sliderVolumn__valueChanged(int value);
    void on_sliderPosition__valueChanged(int value);
signals:
    void windowClosed(bool close);
private:
  Ui::graphicsVideoItem *ui;
  void initGraphicsScene();
};

#endif // GRAPHICSVIDEOITEM_H
