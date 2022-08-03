#ifndef OPERATECAMERA_H
#define OPERATECAMERA_H

#include <QMainWindow>
#include <QCameraInfo>
#include <QCamera>
#include <QLabel>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>

namespace Ui {
  class operateCamera;
}

class operateCamera : public QMainWindow
{
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent * event);
    void showEvent(QShowEvent*event);
private:
    QCamera *curCamera=Q_NULLPTR;//相机
    QCameraImageCapture *imageCapture; //抓图
    QMediaRecorder* mediaRecorder;//录像
    QLabel *LabCameraState; // 相机状态
    QLabel *LabInfo;// 相机信息
    QLabel *LabCameraMode; // 相机模式
    void  iniCamera();//初始化相机
    void  iniImageCapture();//初始化静态画图
    void  iniVideoRecorder();//初始化视频录制
public:
    explicit operateCamera(QWidget *parent = nullptr);
    ~operateCamera();
private slots: // 自定义槽函数
    // QCamera的槽函数
    void on_cameraStateChanged(QCamera::State state);
    void on_cameraCaptureModeChanged(QCamera::CaptureModes mode);
    // QCameraImageCapture的槽函数
    void on_imageReadyForCapture(bool ready);
    void on_imageCaptured(int id, const QImage &preview);
    void on_imageSaved(int id, const QString &fileName);
    // QMediaRecorder的槽函数
    void on_videoStateChanged(QMediaRecorder::State state);
    void on_videoDurationChanged(qint64 duration);
private slots:
    void on_actStartCamera_triggered();
    void on_actStopCamera_triggered();
    void on_actVideoRecord_triggered();
    void on_actVideoStop_triggered();
    void on_actCapture_triggered();
    void on_btnVideoFile_clicked();
    void on_chkMute_clicked(bool checked);
signals:
    void windowClosed(bool close);
private:
  Ui::operateCamera *ui;
};

#endif // OPERATECAMERA_H
