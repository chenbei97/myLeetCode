(1) 传递临时对象作为线程参数
    (1.1) 避免的陷阱 解释1
    (1.2) 避免的陷阱 解释2
(2) 临时对象作为线程参数继续讲
    (2.1) 线程id概念
    (2.2) 临时对象构造时机抓捕
(3) 传递类对象、智能制造作为线程参数
(4) 使用成员函数指针作为线程函数

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <windows.h> // sleep
using namespace std;
int main(){
    /*
        
    */
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/
cd STLTestCode\\thread\\c++11并发与多线程_bilibili\\chapter3