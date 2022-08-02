#include "TestQAudioInput.h"
#include "ui_TestQAudioInput.h"
#include  <QAudioFormat>
#include  <QMessageBox>

TestQAudioInput::TestQAudioInput(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestQAudioInput)
{
      ui->setupUi(this);
      setCentralWidget(ui->splitter);
      this->initAudioChart();
      this->initDeviceList();
}

TestQAudioInput::~TestQAudioInput()
{
  delete ui;
}

// 初始化音频图表
void TestQAudioInput::initAudioChart()
{
    //创建显示图表
    QChart *chart = new QChart;
    chart->setTitle("音频输入原始信号");
    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing); // 开渲染提示
    this->lineSeries= new QLineSeries(); // 曲线
    chart->addSeries(lineSeries);

    QValueAxis *axisX = new QValueAxis;  //X坐标轴
    axisX->setRange(0, this->audioInputBufferSize); //chart显示4000个采样点数据
    axisX->setLabelFormat("%g");
    axisX->setTitleText("采样点数");
    QValueAxis *axisY = new QValueAxis;  //Y坐标轴
    axisY->setRange(0, 256); // UnSingedInt采样，数据范围0-255
    axisY->setTitleText("音量");

    // 2个坐标轴添加进图表和曲线
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    this->lineSeries->attachAxis(axisX);
    this->lineSeries->attachAxis(axisY);

    chart->legend()->hide(); // 隐藏图例
}

// 2. 初始化设备列表
void TestQAudioInput::initDeviceList()
{
    ui->comboDevices->clear(); // 清空当前设备选择
    this->deviceList=QAudioDeviceInfo::availableDevices(QAudio::AudioInput);//有效的输入设备列表
    for(int i=0;i<deviceList.count();i++)
    {
       QAudioDeviceInfo device=this->deviceList.at(i);
       ui->comboDevices->addItem(device.deviceName()); // 添加进去显示
     }

    if (this->deviceList.size()>0)
    {
        ui->comboDevices->setCurrentIndex(0); //触发comboDevices的信号currentIndexChanged()这样能够调用1次初始化其它变量
        this->curDevice =deviceList.at(0);
    }
    else
    {
        // 没有可用设备,设置使能
        ui->actStart->setEnabled(false);
        ui->actDeviceTest->setEnabled(false);
        ui->groupBoxDevice->setTitle("支持的音频输入设置(无设备)");
    }
}

// 3. 测试音频设置是否被支持
void TestQAudioInput::on_actDeviceTest_triggered()
{
    // UI界面的设置传入
    QAudioFormat settings;
    settings.setCodec(ui->comboCodec->currentText());
    settings.setSampleRate(ui->comboSampleRate->currentText().toInt());
    settings.setChannelCount(ui->comboChannels->currentText().toInt());
    settings.setSampleType(QAudioFormat::SampleType(ui->comboSampleTypes->currentData().toInt()));
    settings.setSampleSize(ui->comboSampleSizes->currentText().toInt());

    if (ui->comboByteOrder->currentText()=="低字节序")
       settings.setByteOrder(QAudioFormat::LittleEndian);
    else settings.setByteOrder(QAudioFormat::BigEndian);

    if (this->curDevice.isFormatSupported(settings))
      QMessageBox::information(this,"音频输入设置测试","测试成功，输入设备支持此设置");
    else QMessageBox::critical(this,"音频输入设置测试","测试失败，输入设备不支持此设置");
}

// 4. 开始输入音频
void TestQAudioInput::on_actStart_triggered()
{
      // 设置音频采样的格式,采样数=帧数*通道数，字节数=采样数*采样字节数
      // 固定采样800字节，传入writedata的字节就是800
      QAudioFormat defaultAudioFormat; //缺省格式
      defaultAudioFormat.setSampleRate(8000);
      defaultAudioFormat.setChannelCount(1);
      defaultAudioFormat.setSampleSize(8);
      defaultAudioFormat.setCodec("audio/pcm");
      defaultAudioFormat.setByteOrder(QAudioFormat::LittleEndian);
      defaultAudioFormat.setSampleType(QAudioFormat::UnSignedInt);

      if (!this->curDevice.isFormatSupported(defaultAudioFormat))
      {
          QMessageBox::critical(this,"音频输入设置测试","测试失败，输入设备不支持此设置");
          return;
      }

      // 传递自定义的格式和当前设备创建音频输入对象
      this->audioInput = new QAudioInput(this->curDevice,defaultAudioFormat, this);
      this->audioInput->setBufferSize(this->audioInputBufferSize); // 设置缓冲区大小固定4000
      // 创建接收音频输入数据的流设备,把坐标轴指针传进去,显示设备内自动会对其数据更新
      this->displayDevice = new myIODevice(this->lineSeries, this->audioInputBufferSize,this);
      // 连接好接收设备的信号和槽函数
      connect(this->displayDevice,SIGNAL(updateBlockSize(qint64)),this,SLOT(on_IODevice_UpdateBlockSize(qint64)));
      this->displayDevice->open(QIODevice::WriteOnly); //必须以写方式打开
      this->audioInput->start(this->displayDevice); //指定数据输出对象，就会自动给输出设备传入数据writeData(const char * data, qint64 maxSize)

      // 更新使能
      ui->actStart->setEnabled(false);
      ui->actStop->setEnabled(true);
}

// 5. 停止音频输入
void TestQAudioInput::on_actStop_triggered()
{
      this->audioInput->stop(); //停止音频输入设备并删除对象
      this->audioInput->deleteLater();
      this->displayDevice->close(); // 显示对象也关闭
      // 断开显示设备信号和槽函数的绑定关系
      disconnect(displayDevice,SIGNAL(updateBlockSize(qint64)),this,SLOT(on_IODevice_UpdateBlockSize(qint64)));
      this->displayDevice->deleteLater();
      // 更新使能
      ui->actStart->setEnabled(true);
      ui->actStop->setEnabled(false);
}

// 6. 响应显示设备的updateBlockSize信号的槽函数
void TestQAudioInput::on_IODevice_UpdateBlockSize(qint64 blockSize)
{
    // 信号会把缓冲区的大小和数据块的大小带出来,用于QLabel显示
    ui->LabBufferSize->setText(QString::asprintf("音频输入设备缓冲区大小为%d bytes",
                                                 audioInput->bufferSize()));
    ui->LabBlockSize->setText( QString("数据块大小为%1 bytes").arg(blockSize));
}

//  7. 重新选择音频输入设备更新输入UI信息
void TestQAudioInput::on_comboDevices_currentIndexChanged(int index)
{
    this->curDevice =deviceList.at(index);//当前音频设备

    ui->comboCodec->clear(); //先清空
    QStringList codecs = curDevice.supportedCodecs();
    for (int i = 0; i < codecs.size(); ++i)
         ui->comboCodec->addItem(codecs.at(i));// 更新对应的支持编码格式

    ui->comboSampleRate->clear(); //同理更新采样率
    QList<int> sampleRate = curDevice.supportedSampleRates();
    for (int i = 0; i < sampleRate.size(); ++i)
        ui->comboSampleRate->addItem(QString("%1").arg(sampleRate.at(i)));

    ui->comboChannels->clear();//更新支持的通道数
    QList<int> Channels = curDevice.supportedChannelCounts();
    for (int i = 0; i < Channels.size(); ++i)
        ui->comboChannels->addItem(QString("%1").arg(Channels.at(i)));

    ui->comboSampleTypes->clear(); //更新支持的采样点类型
    QList<QAudioFormat::SampleType> sampleTypes = curDevice.supportedSampleTypes();
    for (int i = 0; i < sampleTypes.size(); ++i)
        ui->comboSampleTypes->addItem(SampleTypeString(sampleTypes.at(i)),QVariant(sampleTypes.at(i)));

    ui->comboSampleSizes->clear();// 更新支持的采样点大小
    QList<int> sampleSizes = curDevice.supportedSampleSizes();
    for (int i = 0; i < sampleSizes.size(); ++i)
        ui->comboSampleSizes->addItem(QString("%1").arg(sampleSizes.at(i)));

    ui->comboByteOrder->clear();// 更新支持的字节序
    QList<QAudioFormat::Endian> endians = curDevice.supportedByteOrders();
    for (int i = 0; i < endians.size(); ++i)
        ui->comboByteOrder->addItem(ByteOrderString(endians.at(i)));
}

//  8. 采样率（返回字符串用于显示）
QString TestQAudioInput::SampleTypeString(QAudioFormat::SampleType sampleType)
{
    QString result("未知");
    switch (sampleType)
    {
        case QAudioFormat::SignedInt:
            result = "有符号整数";
            break;
        case QAudioFormat::UnSignedInt:
            result = "无符号整数";
            break;
        case QAudioFormat::Float:
            result = "浮点数";
            break;
        case QAudioFormat::Unknown:
            result = "未知类型";
    }
    return result;
}

// 9. 字节序（返回字符串用于显示）
QString TestQAudioInput::ByteOrderString(QAudioFormat::Endian endian)
{
    if (endian==QAudioFormat::LittleEndian)
      return "低字节序";
    else if (endian==QAudioFormat::BigEndian)
      return "高字节序";
    else
      return "未知字节序";
}
