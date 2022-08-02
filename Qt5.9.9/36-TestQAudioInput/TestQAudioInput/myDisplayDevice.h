#ifndef MYIODEVICE_H
#define MYIODEVICE_H
#include  <QtCharts>
#include  <QIODevice>
using namespace  QtCharts;

class myIODevice:public QIODevice
{
  Q_OBJECT
public:
  // 自定义设备需要指定XY轴,音频输入缓存字节数
  explicit myIODevice(QXYSeries * series, qint64 audioInputBufferSize,QObject *parent = 0);
protected:
    // 定义自己的读取和写入方式
    qint64 readData(char * data, qint64 maxSize);
    qint64 writeData(const char * data, qint64 maxSize);
private:
    QXYSeries *m_series; //保存传入的坐标轴变量
    qint64 m_audioInputBufferSize=4000; // 范围固定
signals:
    void  updateBlockSize(qint64 blockSize);
};

#endif // MYIODEVICE_H
