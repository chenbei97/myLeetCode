#include "myDisplayDevice.h"

myIODevice::myIODevice(QXYSeries * series, qint64 audioInputBufferSize, QObject *parent) :
    QIODevice(parent)
{
   this->m_series= series;
   this->m_audioInputBufferSize=audioInputBufferSize;
}

qint64 myIODevice::readData(char * data, qint64 maxSize)
{// 流的读 操作不处理
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    return -1;
}

qint64 myIODevice::writeData(const char * data, qint64 maxSize)
{
    //读取数据块内的数据，更新到序列（这里maxSize=800）
    QVector<QPointF> oldPoints = this->m_series->pointsVector(); //坐标轴上的所有点
    QVector<QPointF> points;

    if (oldPoints.count() < this->m_audioInputBufferSize)
    { //m_series序列的数据未满4000点，缓冲区没满
       points = m_series->pointsVector(); // 就继续保存
    }
    else
    {// 缓冲区已经超出,先入先出,那么将原来800至4000的数据点前移,因为最早的800个点不要了
       for (int i = maxSize; i < oldPoints.count(); i++) //从800-4000移动3200个点到0-3200的未知
          points.append(QPointF(i - maxSize, oldPoints.at(i).y())); // 所以位置自然是800-800,4000-800,就对的上了(i-maxSize)
    }

    qint64 size = points.count(); // 现在的点数有3200个点,新来的数据800个点放在后边
    for (int k = 0; k < maxSize; k++) //数据块内的数据填充序列的尾部
        points.append(QPointF(k + size, (quint8)data[k])); // 自然位置是3200开始也就是size开始

    this->m_series->replace(points); //最快的方式,就可以把更新的点数替换
    emit updateBlockSize(maxSize); // 数据块大小发射出去
    return maxSize;
}
