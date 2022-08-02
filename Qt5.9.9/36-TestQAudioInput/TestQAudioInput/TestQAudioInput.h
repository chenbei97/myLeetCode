#ifndef TESTQAUDIOINPUT_H
#define TESTQAUDIOINPUT_H

#include <QMainWindow>
#include <QtCharts>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include "myDisplayDevice.h"

using namespace  QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class TestQAudioInput; }
QT_END_NAMESPACE

class TestQAudioInput : public QMainWindow
{
  Q_OBJECT
private:
    const qint64  audioInputBufferSize=4000;
    QLineSeries *lineSeries;//曲线
    QList<QAudioDeviceInfo> deviceList;  //音频录入设备列表
    QAudioDeviceInfo curDevice;//当前输入设备
    myIODevice *displayDevice; //用于显示的IODevice
    QAudioInput  *audioInput;//音频输入设备
    void initAudioChart();
    void initDeviceList();
    QString SampleTypeString(QAudioFormat::SampleType sampleType);
    QString ByteOrderString(QAudioFormat::Endian endian);
public:
    explicit TestQAudioInput(QWidget *parent = nullptr);
    ~TestQAudioInput();
private slots://自定义槽函数
    void on_IODevice_UpdateBlockSize(qint64 blockSize); //响应自定义设备的信号
private slots:
    void on_actDeviceTest_triggered();
    void on_actStart_triggered();
    void on_actStop_triggered();
    void on_comboDevices_currentIndexChanged(int index);

private:
    Ui::TestQAudioInput *ui;
};
#endif // TESTQAUDIOINPUT_H
