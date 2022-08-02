#ifndef TESTQAUDIORECORDER_H
#define TESTQAUDIORECORDER_H

#include <QMainWindow>
#include <QAudioRecorder>
#include <QAudioProbe>

QT_BEGIN_NAMESPACE
namespace Ui { class TestQAudioRecorder; }
QT_END_NAMESPACE

class TestQAudioRecorder : public QMainWindow
{
  Q_OBJECT
private:
    QAudioRecorder *recorder;//音频录音
    QAudioProbe *probe; //探测器
    void initRecorderSettings();
public:
  explicit TestQAudioRecorder(QWidget *parent = nullptr);
  ~TestQAudioRecorder();
private slots://自定义槽函数
    void onStateChanged(QMediaRecorder::State state);//录制状态改变通知动作使能
    void onDurationChanged(qint64 duration);//录制长度改变通知QLabel
    void onAudioBufferProbed(const QAudioBuffer& buffer);//使用探针获取处理音视频的一些信息
    void on_actRecord_triggered();
    void on_actPause_triggered();
    void on_actStop_triggered();
    void on_btnGetFile_clicked();

private:
  Ui::TestQAudioRecorder *ui;
};
#endif // TESTQAUDIORECORDER_H
