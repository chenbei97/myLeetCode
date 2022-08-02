#ifndef TESTQMEDIAPLAYER_H
#define TESTQMEDIAPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class TestQMediaPlayer; }
QT_END_NAMESPACE

class TestQMediaPlayer : public QMainWindow
{
  Q_OBJECT
private slots://自定义槽函数
    void onStateChanged(QMediaPlayer::State state);
    void onPlaylistChanged(int position);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
public:
  explicit TestQMediaPlayer(QWidget *parent = nullptr);
  ~TestQMediaPlayer();
private:
  QMediaPlayer *player;//播放器
  QMediaPlaylist *playlist;//播放列表
  QString durationTime;//总长度
  QString positionTime;//当前播放位置
private:
  QSoundEffect * sound;
  QString  soundSourcePath;
  void playSound(QString weapon);
private slots:
  void on_btnAdd_clicked();
  void on_btnRemove_clicked();
  void on_btnClear_clicked();
  void on_btnPlay_clicked();
  void on_btnPause_clicked();
  void on_btnStop_clicked();
  void on_btnPrevious_clicked();
  void on_btnNext_clicked();
  void on_listWidget_doubleClicked(const QModelIndex &index);
  void on_sliderVolumn_valueChanged(int value);
  void on_btnSound_clicked();
  void on_sliderPosition_valueChanged(int value);
  void on_pushButton1_clicked();
  void on_pushButton2_clicked();
  void on_pushButton3_clicked();
  void on_pushButton4_clicked();
  void on_pushButton5_clicked();
  void on_pushButton6_clicked();
  void on_pushButton7_clicked();
  void on_pushButton8_clicked();
  void on_pushButton9_clicked();
  void on_pushButton10_clicked();
private:
  Ui::TestQMediaPlayer *ui;
};
#endif // TESTQMEDIAPLAYER_H
