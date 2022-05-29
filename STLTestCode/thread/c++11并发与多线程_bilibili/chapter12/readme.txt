(1) windows临界区
(2) 多次进入临界区试验
(3) 自动析构技术
(4) recursive_mutex递归的独占互斥量
(5) 带超时的互斥量std::timed_mutex和std::recursive_timed_mutex

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <future>
#include <minwinbase.h> // include CRITICAL_SECTION
#include <list>
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
cd STLTestCode\\thread\\c++11并发与多线程_bilibili\\chapter12