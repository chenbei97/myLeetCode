(1) 互斥量mutex的基本概念
(2) 互斥量的用法
    (2.1) lock(),unlock()
    (2.2) std::lock_guard类模板
(3) 死锁
    (3.1) 死锁演示
    (3.2) 死锁的一般解决方案
    (3.3) std::lock()函数模板
    (3.4) std::lock_guard的std::adopt_lock参数

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <list>
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
cd STLTestCode\\thread\\c++11并发与多线程_bilibili\\chapter5