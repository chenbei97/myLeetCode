/*** 
 * @Author: chenbei
 * @Date: 2022-05-24 15:34:37
 * @LastEditTime: 2022-05-24 16:22:31
 * @Description: chapter1\main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter1\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int main(){
    /*
        (1)并发、进程和线程的基本概念和综述
            (1.1)并发：指2个或者多个任务同时进行,1个程序可以同时执行多个独立的任务
                并发需要上下文切换，保存切换任务时的进度和各种状态信息
            (1.2)可执行文件：.exe文件
            (1.3)进程：一个可执行程序运行起来了就叫1个进程，一个进程有一个堆空间
            (1.4)线程：每个进程中只能有唯一的主线程,有进程必然有线程
                运行代码时实际上就是主线程调用了main函数中的代码去执行
                线程就是去执行的，main中函数return之后主线程结束，进程也结束
                除了主线程以外，可以自己写代码创建其它线程，走其他通路，也就是并发
                线程不是越多越好，每个线程需要独立的栈空间，大约需要1M的内存
        (2)并发的实现方法
            (2.1)多进程并发
                多个进程实现，进程之间可以进行通信
                同一电脑可以通过管道、文件、消息队列和共享内存等通信
                不同的电脑之间通过socket通信技术
            (2.2)多线程并发
                单个进程有多个线程，所有线程共享相同的地址空间
                例如全局变量、指针和引用都可以在线程之间传递
                多线程的内存开销远小于多进程，但是会造成数据一致性问题，需要互斥锁来解决这个问题
        (3)c++11标准线程库thread
            以往windows借助CreateThread创建线程，线程的创建和结束都是需要等待的
            还有_beginthread(),_beginthreadexe()等
            linux下借助pthread_create()创建线程
            以往多线程代码不可跨平台,或者需要POSIX thread(pthread)作一番配置实现跨平台
            C++11之后,多线程被支持,意味着可移植性,可以跨平台
    */
    return 0;
}
/*
g++ -o main main.cpp
.\main.exe
cl /Fo"..\output\main" /Fe"..\output\main.exe" /std:c++latest ".\main.cpp"
.\main.exe
*/
