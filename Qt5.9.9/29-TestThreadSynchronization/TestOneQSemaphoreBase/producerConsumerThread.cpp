#include "producerConsumerThread.h"
#include    <QSemaphore>

const int BufferSize = 8;
int buffer1[BufferSize]; // 双缓冲区
int buffer2[BufferSize];
int curBuf; //当前正在写入的Buffer
int bufCount; // 表示累计的缓冲区个数编号
quint8   counter;// 数据生成器(模拟采集数据)
QSemaphore emptyBufs(2);//初始空缓冲区资源数量为2
QSemaphore fullBufs; // 初始满缓冲区资源数量为0

// （1）生产者模型
void Producer::stopProduce()
{
    isProduce = false;
}
void Producer::run()
{
    bufCount=0;// 累计缓冲区数量从0开始计算
    curBuf=1; //当前写入使用的缓冲区
    counter=0;// 初始化写入的数据为0
    this->isProduce = true;
    // 因为首次读取数据的时候,必然是2个空的缓冲资源
    // 但是为了避免可能的意外导致并不是2个非空缓冲区,可以先初始化为2
    // 不过一般不会出现这种意外,注释掉也没什么
    int n=emptyBufs.available(); // 空缓冲资源个数
    if (n<2)  //初始化
        emptyBufs.release(2-n); // 如果不是2个先释放掉,以便写入数据可以使用

    while (isProduce)
    {
        emptyBufs.acquire(1);//尝试获取1个空缓冲区用于写入数据,如果没有会在这里阻塞
        for(int i=0;i<BufferSize;i++) //产生一个缓冲区的数据
        {
            if (curBuf==1) buffer1[i]=counter; // 向1号缓冲区写入数据
            else buffer2[i]=counter; // 向1号缓冲区写入数据
            counter++; // 模拟数据采集卡产生数据
            msleep(20); //每20ms产生一个数
        }

        // 这里for循环结束后,表示一个缓冲数组满了
        bufCount++; // 累积缓冲区个数++(为了后边传递数据用)

        if (curBuf==1) curBuf=2; // 切换当前写入缓冲区用于下次使用
        else curBuf=1;

        // 对于release,如果资源已全部可以用(因为初始化为0)就会增加可用资源个数
        fullBufs.release(); // 一个满缓冲区资源被释放,就会从变成1,可以被消费者acquire
        msleep(50);
    }
    quit();
}

// （2）消费者模型
void Consumer::stopConsume()
{
    isConsumed = false;
}
void Consumer::run()
{
    this->isConsumed = true;
    // 下方3行代码可以注释掉,仅仅是为了第1次读取数据时初始化满缓冲区资源为0
    // 避免意外读取了并非生产者提供的满缓冲区资源,因为读取的前提必须先写入
    // 所以最初最初的时候,fullBufs.acquire(1);是一定会阻塞并等待通知的
    // 不过一般不会出现这种意外,所以注释掉也没什么影响
    int n=fullBufs.available();
    if (n>0)
        fullBufs.acquire(n); // 如果n>0就先锁定,这样满缓冲区资源数初始化为0
    while (isConsumed)
    {
        fullBufs.acquire(1); // 尝试获取1个可用的满缓冲区,如果没有会阻塞
        int bufferData[BufferSize]; // 用于传递数据的临时数组
        int id=bufCount;
        if(curBuf==1) //当前在写入的缓冲区是1，那么满的缓冲区是2
            for (int i=0;i<BufferSize;i++)
                bufferData[i]=buffer2[i]; //快速拷贝缓冲区数据
        else
            for (int i=0;i<BufferSize;i++)
                bufferData[i]=buffer1[i];
        emptyBufs.release();// 读取完毕,缓冲区空闲,还回去给生产者使用
        emit  newValue(bufferData,BufferSize,id);//给主线程传递数据(一维数组,数组长度,缓冲区编号)
        msleep(10);
    }
    quit();
}
