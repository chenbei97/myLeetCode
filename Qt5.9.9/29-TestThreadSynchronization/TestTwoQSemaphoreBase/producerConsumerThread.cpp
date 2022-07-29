#include "producerConsumerThread.h"
#include <QSemaphore>
#include <QTime>

// DataSize 是生产者将生成的数据量,为了尽可能简单,将其设为常量
 const int DataSize = 200;
// BufferSize是循环缓冲区的大小,小于 DataSize,生产者到达缓冲区末尾时重新启动
const int BufferSize = 30;
char buffer[BufferSize];

// 为了同步生产者和消费者需要两个信号量
// freeBytes信号量控制缓冲区的"空闲"区域(生产者尚未填充数据或消费者已读取的区域)
QSemaphore freeBytes(BufferSize); //用 BufferSize初始化的,因为最初整个缓冲区是空的
// usedBytes信号量控制缓冲区的"已使用"区域(生产者已填充但消费者尚未读取的区域)
QSemaphore usedBytes; // 初始已使用字节为0
// 2个信号量确保生产者永远不会超过消费者的 BufferSize 字节
// 且消费者永远不会读取生产者尚未生成的数据

// （1）生产者模型
// 生产者生成 DataSize字节的数据,在向循环缓冲区写入一个字节之前
// 它必须使用 freeBytes 信号量获取一个"空闲"字节
// usedBytes信号量释放一个字节,"空闲"字节转换为"已使用"字节供消费者读取
void Producer::run()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < DataSize; ++i) {
        freeBytes.acquire(); // 获取一个空闲的字节来写入数据,如果不空闲会阻塞
        buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4];
        emit stringProduced(QString(buffer[i%BufferSize]));
        usedBytes.release(); // 同时释放1个已使用字节可供消费者acquire读取
        msleep(50);//写入稍微的慢一些
    }
}

// （2）消费者模型
// 代码与生产者非常相似,只是这次获取一个"已使用"字节,并释放一个"空闲"字节
void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        usedBytes.acquire(); // 如果有已经使用字节说明可以读取了,否则可能阻塞
        fprintf(stderr, "%c", buffer[i % BufferSize]);
        emit stringConsumed(QString(buffer[i%BufferSize]));
        freeBytes.release(); // 读取完毕之后,字节空闲要释放掉供生产者使用
        msleep(30);//读取的速度比写入速度稍快就行
    }
    fprintf(stderr, "\n");
}
