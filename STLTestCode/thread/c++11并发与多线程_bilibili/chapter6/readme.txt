(1) unique_lock取代lock_guard
(2) unique_lock的第2个参数
    (2.1) std::adopt_lock
    (2.2) std::try_to_lock
    (2.3) std::defer_lock
(3) unique_lock的成员函数
    (3.1) lock()
    (3.2) unlock()
    (3.3) try_lock()
    (3.4) release()
(4) unique_lock所有权的传递

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
cd STLTestCode\\thread\\c++11并发与多线程_bilibili\\chapter6