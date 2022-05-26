/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:34:35
 * @LastEditTime: 2022-05-26 17:44:57
 * @Description: /chapter7/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter7\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <mutex>
#include "SingleSlacker.h"
#include "SingleSlackerGC.h"
#include "SingleSlackerMutex.h"
#include "SingleHungry.h"
#include "SingleHungryMeyer.h"
#include "SingleSlackerCallOnce.h"
using namespace std;
void test_single_mode(){
    // 单例设计模式
    SingleSlacker *ps1 = SingleSlacker::getInstance();
    SingleSlacker *ps2 = SingleSlacker::getInstance();
    cout <<"ps1 = "<<ps1<<" ps2 = "<<ps2<<endl; // ps1和ps2是同一个对象

    SingleHungry * ps3 = SingleHungry::getInstance();
    SingleHungry * ps4 = SingleHungry::getInstance();
    cout <<"ps3 = "<<ps3<<" ps4 = "<<ps4<<endl; // ps3和ps4是同一对象

    SingleSlackerGC * ps5 = SingleSlackerGC::getInstance();
    SingleSlackerGC * ps6 = SingleSlackerGC::getInstance();
    cout <<"ps5 = "<<ps5<<" ps6 = "<<ps6<<endl; // ps5和ps6是同一对象

    SignleHungryMeyer &ps7 = SignleHungryMeyer::getInstance(); // 这里要注意局部静态对象要用&来接受
    SignleHungryMeyer &ps8 = SignleHungryMeyer::getInstance();
    cout <<"&ps7 = "<<&ps7<<" &ps8 = "<<&ps8<<endl; // ps7和ps8是同一对象

    SingleSlackerMutex *ps9 = SingleSlackerMutex::getInstance();
    SingleSlackerMutex *ps10 = SingleSlackerMutex::getInstance();
    cout <<"ps9 = "<<ps9<<" ps10 = "<<ps10<<endl; // ps7和ps8是同一对象
}
void myprint(){
    // 线程入口函数
    cout <<"my thread is start\n";
    SingleSlackerCallOnce * p = SingleSlackerCallOnce::getInstance();
    cout<<"my thread is end\n";
}
void test_double_thread(){
    // 可能会初始化多次
    std::thread t1(myprint);
    std::thread t2(myprint);
    t1.join();
    t2.join();
}
int main(){
    /*
        (1) 设计模式概况
            单例模式相对来说是比较常用的
        (2) 单例设计模式
            1.私有化构造函数 2.创建静态成员变量 3.创建静态变量获取函数,为空就new1个否则直接返回
            参见 https://zhuanlan.zhihu.com/p/51534041的写法 以及https://wenku.baidu.com/view/69ed3a025bfb770bf78a6529647d27284b73379b.html meyer的写法
        (3) 单例设计模式共享数据问题分享和解决
            需要创建自己的线程来创建单例模式的实例对象，线程至少2个，此时可能需要getInstance()函数互斥
        (4) std::call_once()
            第2个参数是一个函数指针func,功能上保证调用的函数func只被调用1次
            具备互斥量这种能力，效率比互斥量消耗的资源更少
            它需要和一个标记结合使用，也就是std::once_flag，是一个结构体
            通过这个标记来决定func函数是否执行
    */
    // 单例模式
    test_single_mode();
    // 多线程的情况
    test_double_thread();
    return 0;
}
/*
g++ -o main_g++ main.cpp SingleHungry.cpp SingleHungryMeyer.cpp SingleSlacker.cpp SingleSlackerGC.cpp SingleSlackerMutex.cpp SingleSlackerCallOnce.cpp
.\main_g++.exe

可以分别编译然后链接
cl /Fo".\SingleHungry_cl" /Fe".\SingleHungry_cl.exe" /std:c++latest ".\SingleHungry.cpp"
cl /Fo".\SingleSlackerGC_cl" /Fe".\SingleSlackerGC_cl.exe" /std:c++latest ".\SingleSlackerGC.cpp"
cl /Fo".\SingleHungryMeyer_cl" /Fe".\SingleHungryMeyer_cl.exe" /std:c++latest ".\SingleHungryMeyer.cpp"
cl /Fo".\SingleSlacker_cl" /Fe".\SingleSlacker_cl.exe" /std:c++latest ".\SingleSlacker.cpp"
cl /Fo".\SingleSlackerMutex_cl" /Fe".\SingleSlackerMutex_cl.exe" /std:c++latest ".\SingleSlackerMutex.cpp"
cl /Fo".\SingleSlackerCallOnce_cl" /Fe".\SingleSlackerCallOnce_cl.exe" /std:c++latest ".\SingleSlackerCallOnce.cpp"
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
link *obj 
也可以直接全部编译并链接
cl *.cpp -o main_cl
.\main_cl.exe
del *.obj
*/