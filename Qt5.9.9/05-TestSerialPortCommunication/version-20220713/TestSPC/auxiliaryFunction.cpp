#include "serialPortCommunication.h"
#include "ui_serialPortCommunication.h"
#include <QList>

/*
************* 定义了一些辅助函数
************* 例如格式转换、创建延时等，是一些与UI无关的函数
************* 可以看成是一类方便使用的脚本函数
*/
static const  int  _auxliary_functions_num = 4;

static const QList<const char *> __auxiliary__functions__ = {
        "delay",
        "sleep",
        "strcpy(char*,char*)",
        "strcpy(int*,char*)"
};

// 1. 延时函数 delay
void SerialPortCommunication::delay(unsigned int msec)
{
      //定义一个新的事件循环
      QEventLoop loop;
      //创建单次定时器,槽函数为事件循环的退出函数
      QTimer::singleShot(msec, &loop, SLOT(quit()));
      //事件循环开始执行,程序会卡在这里,直到定时时间到,本循环被退出
      loop.exec();
}

// 2. 延时函数sleep
void SerialPortCommunication::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    {
        //强制进入当前线程的事件循环,这样可以把堵塞的事件都处理掉,从而避免程序卡死。
        QCoreApplication::processEvents();// QEventLoop::AllEvents, 100
        //如果去掉QCoreApplication::processEvents; 可以延时,但会阻塞线程
    }
}

// 3.复制字符串到字符串
bool SerialPortCommunication::strcpy(char *dst, char *src)
{
   if (src == nullptr){
        dst = nullptr;
        return false;
   }
   if (dst == nullptr){
      return false;
   }
   while ((*(dst++) = *(src++))){}; // 多加1层括号,解决警告信息
   return true;
}

// 4.复制字符串到整型数组
bool SerialPortCommunication::strcpy(int *dst, char *src)
{
     if (src == nullptr){
        dst = nullptr;
        return false;
   }
   if (dst == nullptr){
      return false;
   }
   while (*src != '\0'){
          *dst = static_cast<int>(*src) - static_cast<int>('0'); // 将其转为int类型
          ++dst;
          ++src;
   }
   return true;
}
