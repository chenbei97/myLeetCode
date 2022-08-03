#include "operateCamera.h"
#include "ui_operateCamera.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSoundEffect>
#include <QSound>
#include <QCloseEvent>
#include <QShowEvent>

operateCamera::operateCamera(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::operateCamera)
{
      ui->setupUi(this);
      this->LabCameraState=new QLabel;
      this->LabCameraState->setMinimumWidth(150);
      ui->statusBar->addWidget(this->LabCameraState);
      this->LabCameraMode=new QLabel;
      this->LabCameraMode->setMinimumWidth(150);
      ui->statusBar->addWidget(this->LabCameraMode);
      this->LabInfo=new QLabel;
      ui->statusBar->addPermanentWidget(this->LabInfo);

      QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
      if (cameras.size()>0)
      {
          this->iniCamera();  //初始化摄像头
          this->iniImageCapture();//初始化抓图
          this->iniVideoRecorder();//初始化视频录制
          this->curCamera->start();
          qDebug()<<curCamera->captureMode();
          qDebug()<<curCamera->lockStatus();
          qDebug()<<curCamera->state();
          qDebug()<<curCamera->status();
      }
      else{
          qDebug()<<"don't habe available cameras!";
      }
}

operateCamera::~operateCamera()
{
    if (curCamera) curCamera->stop();
    delete ui;
}

void operateCamera::showEvent(QShowEvent *event)
{
    emit windowClosed(false);
    event->accept();
}
void operateCamera::closeEvent(QCloseEvent *event)
{
    emit windowClosed(true);
    event->accept();
}

// （1）初始化摄像机和涉及的槽函数
void operateCamera::iniCamera()
{
    QCameraInfo curCameraInfo=QCameraInfo::defaultCamera(); //获取缺省摄像头
    ui->comboCamera->addItem(curCameraInfo.description());//摄像头描述
    ui->comboCamera->setCurrentIndex(0); // 触发1次操作更新
    this->curCamera=new QCamera(curCameraInfo,this); //创建摄像头对象

    QCameraViewfinderSettings viewfinderSettings; // 摄像头参数设置
    // qDebug()<<this->curCamera->supportedViewfinderResolutions();

//    foreach(auto & resolution , this->curCamera->supportedViewfinderFrameRateRanges())
//    {
//          qDebug()<<resolution.minimumFrameRate<<" "<<resolution.maximumFrameRate;
//    }

     viewfinderSettings.setResolution(450, 350);
     viewfinderSettings.setMinimumFrameRate(15.0);
     viewfinderSettings.setMaximumFrameRate(30.0);
     // this->curCamera->setViewfinderSettings(viewfinderSettings); // 不支持此设置
     this->curCamera->setViewfinder(ui->viewFinder); //设置取景框预览
     this->curCamera->setCaptureMode(QCamera::CaptureStillImage);//设置为抓图模式,其它模式是显示和视频捕获模式

    ui->checkStillImage->setChecked(this->curCamera->isCaptureModeSupported(QCamera::CaptureStillImage)); //是否支持抓图
    ui->checkVideo->setChecked(this->curCamera->isCaptureModeSupported(QCamera::CaptureVideo));//是否支持视频录制

    connect(curCamera,SIGNAL(stateChanged(QCamera::State)), this,SLOT(on_cameraStateChanged(QCamera::State)));
    connect(curCamera,SIGNAL(captureModeChanged(QCamera::CaptureModes)),this,SLOT(on_cameraCaptureModeChanged(QCamera::CaptureModes)));
}

void operateCamera::on_cameraStateChanged(QCamera::State state)
{
    // 摄像头状态改变的槽函数
      switch (state)
      {
          case QCamera::UnloadedState:
            LabCameraState->setText("摄像头状态：未加载");
            break;
          case QCamera::LoadedState:
            LabCameraState->setText("摄像头状态：已加载");
            break;
          case QCamera::ActiveState:
            LabCameraState->setText("摄像头状态：活动状态");
            break;
      }
      ui->actStartCamera->setEnabled(state!=QCamera::ActiveState);
      ui->actStopCamera->setEnabled(state==QCamera::ActiveState);
}

void operateCamera::on_cameraCaptureModeChanged(QCamera::CaptureModes mode)
{
    // 摄像头抓取模式的改变(Windows平台不会发射因为不支持视频捕获)
    if (mode==QCamera::CaptureStillImage)
        LabCameraMode->setText("摄像机模式：图片捕获模式");
    else if (mode==QCamera::CaptureVideo)
        LabCameraMode->setText("摄像机模式：视频捕获模式");
    else LabCameraMode->setText("摄像机模式：取景模式");
}

// （2）初始化抓图对象和涉及槽函数
void operateCamera::iniImageCapture()
{
    imageCapture = new QCameraImageCapture(curCamera,this);
    //qDebug()<<imageCapture->supportedImageCodecs();
    //qDebug()<<imageCapture->supportedResolutions();
    //qDebug()<<imageCapture->supportedBufferFormats();
    QImageEncoderSettings   imageSettings;
    imageSettings.setCodec("image/jpeg");   //设置抓图图形编码
    imageSettings.setResolution(640, 480);  //分辨率
    imageSettings.setQuality(QMultimedia::HighQuality);//图片质量
    imageCapture->setEncodingSettings(imageSettings); //设置抓图格式

    imageCapture->setBufferFormat(QVideoFrame::Format_Jpeg); //缓冲区格式
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile); //是捕获到缓冲区还是直接保存为图片

    connect(imageCapture, SIGNAL(readyForCaptureChanged(bool)),this, SLOT(on_imageReadyForCapture(bool)));
    connect(imageCapture,SIGNAL(imageCaptured(int, const QImage &)),this,SLOT(on_imageCaptured(int, const QImage &)));
    connect(imageCapture,SIGNAL(imageSaved(int, const QString &)),this,SLOT(on_imageSaved(int, const QString &)));
}

void operateCamera::on_imageCaptured(int id, const QImage &preview)
{
    Q_UNUSED(id);
    QImage scaledImage = preview.scaled(ui->LabCapturedImage->size(),
                     Qt::KeepAspectRatio,  Qt::SmoothTransformation);
    ui->LabCapturedImage->setPixmap(QPixmap::fromImage(scaledImage)); // 显示抓取的图像
}

void operateCamera::on_imageReadyForCapture(bool ready)
{
    ui->actCapture->setEnabled(ready);
}

void operateCamera::on_imageSaved(int id, const QString &fileName)
{
    Q_UNUSED(id); // fileName是自动保存到用户文件夹下的图片文件夹
    LabInfo->setText("图片保存地址为： "+fileName); //
}

// （3）初始化录制器和涉及的槽函数
void operateCamera::iniVideoRecorder()
{
      this->mediaRecorder = new QMediaRecorder(this->curCamera,this); // 创建录制对象
      qDebug()<<mediaRecorder->supportedContainers();
      qDebug()<<mediaRecorder->supportedFrameRates();
      qDebug()<<mediaRecorder->supportedAudioCodecs();
      qDebug()<<mediaRecorder->supportedResolutions();
      qDebug()<<mediaRecorder->supportedVideoCodecs();
      qDebug()<<mediaRecorder->supportedAudioSampleRates();
      // 录制格式
      QAudioEncoderSettings audioSettings;
      audioSettings.setCodec("video/mpeg2");
      audioSettings.setQuality(QMultimedia::HighQuality);
      this->mediaRecorder->setAudioSettings(audioSettings);

     ui->chkMute->setChecked(this->mediaRecorder->isMuted());
     // 录制对象的2个信号
     connect(mediaRecorder, SIGNAL(stateChanged(QMediaRecorder::State)),this, SLOT(on_videoStateChanged(QMediaRecorder::State)));
     connect(mediaRecorder, SIGNAL(durationChanged(qint64)),this, SLOT(on_videoDurationChanged(qint64)));
}

void operateCamera::on_videoStateChanged(QMediaRecorder::State state)
{
    ui->actVideoRecord->setEnabled(state!=QMediaRecorder::RecordingState);
    ui->actVideoStop->setEnabled(state==QMediaRecorder::RecordingState);
    ui->chkMute->setEnabled(ui->actVideoRecord->isEnabled());
}

void operateCamera::on_videoDurationChanged(qint64 duration)
{
    ui->LabDuration->setText(QString("录制时间:%1 秒").arg(duration/1000));
}

// （4）开启、关闭摄像头，录像、停止录像和抓图的5个动作
void operateCamera::on_actStartCamera_triggered()
{
    this->curCamera->start();
}

void operateCamera::on_actStopCamera_triggered()
{
    this->curCamera->stop();
}

void operateCamera::on_actVideoRecord_triggered()
{
    if (!mediaRecorder->isAvailable())
    {
        QMessageBox::critical(this,"错误", "不支持视频录制!");
        return;
    }
    if (curCamera->captureMode()!=QCamera::CaptureVideo)
    {
        curCamera->setCaptureMode(QCamera::CaptureVideo);
        return;
    }

    QString selectedFile=ui->editOutputFile->text().trimmed();
    if (selectedFile.isEmpty())
    {
        QMessageBox::critical(this,"错误","请先设置录像输出文件");
        return;
    }

    if (QFile::exists(selectedFile))
       if (!QFile::remove(selectedFile))
       {
         QMessageBox::critical(this,"错误","所设置录音输出文件被占用，无法删除");
          return;
       }
    mediaRecorder->setOutputLocation(QUrl::fromLocalFile(selectedFile)); //输出设备
    mediaRecorder->record(); // 开始录制
}

void operateCamera::on_actVideoStop_triggered()
{
    this->mediaRecorder->stop();
}

void operateCamera::on_actCapture_triggered()
{
    if (curCamera->captureMode()!=QCamera::CaptureStillImage)
    {
        curCamera->setCaptureMode(QCamera::CaptureStillImage);
        return;
    }
    QDir curPath=QDir::current();//获取系统当前目录
    curPath.cdUp();
    curPath.cd(QCoreApplication::applicationName());
    QString filename=curPath.path()+"/shutter.wav";
    QSound::play(filename); //播放快门音效
    this->imageCapture->capture();
}

// （5）设置视频保存文件
void operateCamera::on_btnVideoFile_clicked()
{
    QDir curPath=QDir::current();//获取系统当前目录
    curPath.cdUp();
    curPath.cd(QCoreApplication::applicationName());
    QString dlgTitle="选择保存文件"; //对话框标题
    QString filter="ogg(*.ogg)"; //文件过滤器
    QString selectedFile=QFileDialog::getSaveFileName(this,dlgTitle,curPath.path(),filter);
    if (!selectedFile.isEmpty())
        ui->editOutputFile->setText(selectedFile);
}

// （6）摄像是否静音
void operateCamera::on_chkMute_clicked(bool checked)
{
    mediaRecorder->setMuted(checked);
}
