#ifndef TESTVIDEOPLAYBACK_H
#define TESTVIDEOPLAYBACK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TestVideoPlayBack; }
QT_END_NAMESPACE

class TestVideoPlayBack : public QMainWindow
{
  Q_OBJECT
public:
  explicit TestVideoPlayBack(QWidget *parent = nullptr);
  ~TestVideoPlayBack();
private slots:
  void on_actVideoWidget_triggered();
  void on_actGraphicsVideoItem_triggered();
  void onAct1WindowClosed(bool close);
  void onAct2WindowClosed(bool close);
  void onAct3WindowClosed(bool close);
  void on_actOperateCamera_triggered();
private:
  Ui::TestVideoPlayBack *ui;
};
#endif // TESTVIDEOPLAYBACK_H
