#ifndef VIDEOWIDGETBASED_H
#define VIDEOWIDGETBASED_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include "myVideoWidget.h"

namespace Ui {
  class videoWidgetBased;
}

class videoWidgetBased : public QMainWindow
{
  Q_OBJECT
protected:
    void closeEvent(QCloseEvent * event);
    void showEvent(QShowEvent*event);
private:
    QMediaPlayer *player;//视频播放器
    QString durationTime;//视频总时长
    QString positionTime;// 视频当前播放进度
public:
    explicit videoWidgetBased(QWidget *parent = nullptr);
    ~videoWidgetBased();
private slots://自定义槽函数响应player的3个信号
    void onStateChanged(QMediaPlayer::State state);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
private slots:
    void on_btnAdd_clicked();
    void on_btnPlay_clicked();
    void on_btnPause_clicked();
    void on_btnStop_clicked();
    void on_btnSound_clicked();
    void on_pushButton_clicked();
    void on_sliderVolumn_valueChanged(int value);
    void on_sliderPosition_valueChanged(int value);
signals:
    void windowClosed(bool close);
private:
    Ui::videoWidgetBased *ui;
};

#endif // VIDEOWIDGETBASED_H
