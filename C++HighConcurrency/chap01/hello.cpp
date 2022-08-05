/*
 * @Author: chenbei
 * @Date: 2022-08-05 15:12:13
 * @LastEditTime: 2022-08-05 15:19:28
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap01\\hello.cpp
 * @Description: 第一章,C++并发世界
 * @Signature: A boy without dreams
 */
#include <thread>
#include <iostream>
using std::cout;
using std::thread;
void hello()
{
    cout<<"Hello Concurrent World!\n";
}
int main()
{
    thread t(hello);
    t.join(); // 让主线程等待子线程
}

/*
cd C++HighConcurrency/chap01
g++ -o hello.o hello.cpp
.\hello.o
*/