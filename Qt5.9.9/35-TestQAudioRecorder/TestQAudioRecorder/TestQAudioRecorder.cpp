#include "TestQAudioRecorder.h"
#include "ui_TestQAudioRecorder.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

TestQAudioRecorder::TestQAudioRecorder(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestQAudioRecorder)
{
      ui->setupUi(this);
      this->recorder = new QAudioRecorder(this); // 录制器
      this->probe = new QAudioProbe;//探测器
      this->probe->setSource(recorder);
      connect(probe, SIGNAL(audioBufferProbed(QAudioBuffer)),this, SLOT(onAudioBufferProbed(QAudioBuffer)));
      connect(recorder,SIGNAL(stateChanged(QMediaRecorder::State)),this,SLOT(onStateChanged(QMediaRecorder::State)));
      connect(recorder, SIGNAL(durationChanged(qint64)), this,SLOT(onDurationChanged(qint64)));
      if (recorder->defaultAudioInput().isEmpty())
          return;  //无音频录入设备
      // qDebug()<<"here";
      this->initRecorderSettings();
}

TestQAudioRecorder::~TestQAudioRecorder()
{
    delete ui;
}

// 1. 初始化录音设置
void TestQAudioRecorder::initRecorderSettings()
{
    foreach (const QString &device, recorder->audioInputs())
        ui->comboDevices->addItem(device); //音频录入设备列表都添加进来

    foreach (const QString &codecName, recorder->supportedAudioCodecs())
        ui->comboCodec->addItem(codecName); //支持的音频编码添加进来

    foreach (int sampleRate, recorder->supportedAudioSampleRates())
        ui->comboSampleRate->addItem(QString::number(sampleRate)); //支持的采样率添加进来

    //手动设置可用通道数,一般是1,2.4通道
    ui->comboChannels->addItem("1");
    ui->comboChannels->addItem("2");
    ui->comboChannels->addItem("4");

    //设置音频质量当前为正常质量,可调至最高质量
    ui->sliderQuality->setRange(0, int(QMultimedia::VeryHighQuality));
    ui->sliderQuality->setValue(int(QMultimedia::NormalQuality));

    //手动设置可用压缩传输比特率
    ui->comboBitrate->addItem("32000");
    ui->comboBitrate->addItem("64000");
    ui->comboBitrate->addItem("96000");
    ui->comboBitrate->addItem("128000");
}

// 2. 录制状态改变(信号继承QMediaRecorder)
void TestQAudioRecorder::onStateChanged(QMediaRecorder::State state)
{
    // 控制3个录制动作、设置录音输出文件按钮以及对应的文本编辑框QLineEdit的使能状态

    ui->actRecord->setEnabled(state!=QMediaRecorder::RecordingState);
    ui->actPause->setEnabled(state==QMediaRecorder::RecordingState);
    ui->actStop->setEnabled(state==QMediaRecorder::RecordingState);
    ui->btnGetFile->setEnabled(state==QMediaRecorder::StoppedState); // 停止录制的时候才能再次设置
    ui->editOutputFile->setEnabled(state==QMediaRecorder::StoppedState);
}

// 3. 录制长度改变(信号继承QMediaRecorder)
void TestQAudioRecorder::onDurationChanged(qint64 duration)
{
      // 通知QLabel
      ui->LabPassTime->setText(QString("已录制 %1 秒").arg(duration / 1000));
}

// 4. 使用探针进行缓冲区检测（显示录制的各种信息）
void TestQAudioRecorder::onAudioBufferProbed(const QAudioBuffer& buffer)
{
    ui->spin_byteCount->setValue(buffer.byteCount());//缓冲区字节数
    ui->spin_duration->setValue(buffer.duration()/1000);//缓冲区时长
    ui->spin_frameCount->setValue(buffer.frameCount());//缓冲区帧数
    ui->spin_sampleCount->setValue(buffer.sampleCount());//缓冲区采样数

    QAudioFormat audioFormat=buffer.format();//缓冲区的其它格式
    ui->spin_channelCount->setValue(audioFormat.channelCount()); //通道数
    ui->spin_sampleSize->setValue(audioFormat.sampleSize());//采样大小
    ui->spin_sampleRate->setValue(audioFormat.sampleRate());//采样率
    ui->spin_bytesPerFrame->setValue(audioFormat.bytesPerFrame());//每帧字节数
    ui->edit_codec->setText(audioFormat.codec());//编码格式
    if (audioFormat.byteOrder()==QAudioFormat::LittleEndian)
        ui->edit_byteOrder->setText("低字节序");//字节序
    else
        ui->edit_byteOrder->setText("高字节序");
    if (audioFormat.sampleType()==QAudioFormat::SignedInt)//采样点类型
        ui->edit_sampleType->setText("有符号整型");
    else if(audioFormat.sampleType()==QAudioFormat::UnSignedInt)
        ui->edit_sampleType->setText("无符号整型");
    else if(audioFormat.sampleType()==QAudioFormat::Float)
        ui->edit_sampleType->setText("浮点型");
    else
        ui->edit_sampleType->setText("位置");
}

// 5.开始录制
void TestQAudioRecorder::on_actRecord_triggered()
{
     if (recorder->state() == QMediaRecorder::StoppedState) // 说明是重新录制而不是继续录制
    {
        QString selectedFile=ui->editOutputFile->text().trimmed(); // 保存录制结果的文件(绝对路径)
        if (selectedFile.isEmpty())
        {
            QMessageBox::critical(this,"错误","请先设置录音输出文件");
            return;
        }

        if (QFile::exists(selectedFile)) // 如果文件存在
           if (!QFile::remove(selectedFile)) // 不能够移动的话说明处于占用状态
           {
               QMessageBox::critical(this,"错误","所设置录音输出文件被占用，无法删除");
                return;
           }

        this->recorder->setOutputLocation(QUrl::fromLocalFile(selectedFile));//设置输出文件
        this->recorder->setAudioInput(ui->comboDevices->currentText()); //设置录入设备

        QAudioEncoderSettings settings; //音频编码设置
        settings.setCodec(ui->comboCodec->currentText());//编码格式
        settings.setSampleRate(ui->comboSampleRate->currentText().toInt());//采样率设置
        settings.setBitRate(ui->comboBitrate->currentText().toInt());//压缩比特率设置
        settings.setChannelCount(ui->comboChannels->currentText().toInt()); //采样通道数设置
        settings.setQuality(QMultimedia::EncodingQuality(ui->sliderQuality->value())); //采样品质设置
        if (ui->radioQuality->isChecked())//编码模式为固定品质还是固定比特率,只能二选一
            settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);
        else
            settings.setEncodingMode(QMultimedia::ConstantBitRateEncoding);//固定比特率
        recorder->setAudioSettings(settings); //音频设置
    }
    recorder->record(); // 开始录制
}

// 6. 暂停录制
void TestQAudioRecorder::on_actPause_triggered()
{
    recorder->pause();
}

// 7. 停止录制
void TestQAudioRecorder::on_actStop_triggered()
{
    recorder->stop();
}

// 8. 设置保存录制结果的文件
void TestQAudioRecorder::on_btnGetFile_clicked()
{
     QDir cur = QDir::current();
     cur.cdUp();
     cur.cd(QCoreApplication::applicationName());
    QString curPath=cur.path();//获取系统当前目录
    QString dlgTitle="选择输出文件"; //对话框标题
    QString filter="wav文件(*.wav)"; //文件过滤器
    QString selectedFile=QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);//一个保存文件的对话框
    if (!selectedFile.isEmpty())
        ui->editOutputFile->setText(selectedFile);
}
