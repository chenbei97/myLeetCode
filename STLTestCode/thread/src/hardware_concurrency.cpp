/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 08:01:35
 * @LastEditTime: 2022-05-19 08:05:36
 * @Description: hardware_concurrency.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\src\hardware_concurrency.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\hardware_concurrency hardware_concurrency.cpp
..\output\hardware_concurrency.exe
*/
#include <iostream>
#include <thread>
using namespace std;
int main()
{
    /*
        hardware_concurrency函数可以返回硬件所支持的并发线程数量
    */
    cout << "hardware_concurrency: " << thread::hardware_concurrency() << endl; // 16
    return 0;
}
