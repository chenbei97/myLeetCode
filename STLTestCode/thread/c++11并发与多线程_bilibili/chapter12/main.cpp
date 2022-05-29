/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:36:27
 * @LastEditTime: 2022-05-29 11:40:03
 * @Description: /chapter12/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter12\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <future>
#include <list>
#include <windows.h> // 这个头文件可以
#include <minwinbase.h> // include CRITICAL_SECTION,但是只包含这个头文件会有问题
#include <functional>
using namespace std; 
// #define _WINDOWSJQ_
class Message;
void test_thread();
class releaseWinLock // 自动释放临界区的类,防止忘记LeaveCriticalSection{
{
    public:
        releaseWinLock(CRITICAL_SECTION *cs):cs(cs){
            EnterCriticalSection(cs);
        }
        ~releaseWinLock(){
            LeaveCriticalSection(cs);
        }
    private:
        CRITICAL_SECTION *cs;
};
int main(){
    /*
        (1) windows临界区
            访问临界资源的那段代码，进入临界区就和加锁是一样的
        (2) 多次进入临界区试验
            要在同一线程进入临界区，否则会卡住
            而且必须是同一临界区变量，不能定义2个临界区使用
            不过同一临界区是可以多次使用的，但是进入和离开是成对的
            但是mutex是不允许多次lock的，有所区别
        (3) 自动析构技术
            mutex存在lock_guard允许自动析构，无需手动调用unlock
            使用unique_lock也可以自动析构
            如果是临界区就自己定义RAII类来管理
        (4) recursive_mutex递归的独占互斥量
            如果某个函数内部调用了另一个函数就可能导致多次lock的情况
            所以引入可递归的锁,即独占互斥量，允许同一互斥量多次lock
            但是效率很低,栈空间满的话就会卡住
        (5) 带超时的互斥量std::timed_mutex和std::recursive_timed_mutex 
            std::timed_mutex：带超时功能的递归独占互斥量，以前拿不到锁就会卡住，现在是超时就会跳过继续执行
                try_lock_for(std::chrono::milliseconds(100)) 等待一段时间,没拿到锁就跳过
                try_lock_until(std::chrono::system_clock::now() + std::chrono::milliseconds(100)) 从现在开始直到一段时间后
            std::recursive_timed_mutex：
                用法和timed_mutex类似，也是带超时功能的递归独占互斥量，允许同一线程多次获取这个互斥量
    */
    test_thread();
    return 0;
}
class Message{
    public:
        void collect_msg(){
            for(int i = 0; i<100; ++i){
#ifdef _WINDOWSJQ_
                // EnterCriticalSection(&cs); // 进入临界区, 其他线程不能进入,好像拿到锁一样
                // msgQueue.push_back(i+1);
                // LeaveCriticalSection(&cs); // 退出临界区

                // 或者这样用,使用资源管理类
                releaseWinLock lock(&cs);
                msgQueue.push_back(i+1);
#else
                // std::lock_guard<std::mutex> lock(mtx); // 1.互斥锁写法
               
                std::lock_guard<std::recursive_mutex> lock(rmtx); // 2.递归互斥锁写法
                // testfunc1(); // 这里相当于加了3次锁,如果使用的是mtx就会出问题,rmtx没事
                // 不过由于栈空间满效率低仍然会卡住,所以testfunc1()不能用
                
                // mtx.lock(); // 3.保护锁常规写法 

                // 4.超时写法,不过这里try_lock_for成员函数说已经被移除了就注释掉
                // std::chrono::milliseconds timeout(100);
                // if(mtx.try_lock_for(timeout)){ / 100ms拿到了锁就
                //     msgQueue.push_back(i+1);
                //     mtx.unlock();
                // }
                // else{ // 休息一段时间,没拿到锁
                //     std::chrono::microseconds sleep_time(100);
                //     std::this_thread::sleep_for(sleep_time);
                // }

                
                msgQueue.push_back(i+1);
                
                // mtx.unlock(); // 3.保护锁常规写法
#endif
            }
        }
        void take_msg(){ // 模拟取出命令
            for(int i = 0; i<105; ++i){ 
                int command = 0;
                bool result = exec_command(command);
                if (result){
                    cout<<"take msg "<<command<<endl;
                }
                else{cout<<"no msg"<<endl;}
            }
            return;
        }
        bool exec_command(int &command){
#ifdef _WINDOWSJQ_
            // EnterCriticalSection(&cs); // 进入临界区, 其他线程不能进入,好像拿到锁一样
            releaseWinLock lock(&cs);
            if(msgQueue.empty()){ // 代码相同,抄过来
                command = msgQueue.front();
                msgQueue.pop_front();
                // LeaveCriticalSection(&cs); // 退出临界区
                return true;
            }
            // LeaveCriticalSection(&cs); // 退出临界区
#else
            // std::lock_guard<std::mutex> lock(mtx); // 互斥锁
            std::lock_guard<std::recursive_mutex> lock(rmtx); // 递归互斥锁
            // mtx.lock();
            if (!msgQueue.empty()){
                command = msgQueue.front(); // 取出最早的命令
                msgQueue.pop_front();
                // mtx.unlock(); // 注意2个分支都要unlock
                return true;
            }
            // mtx.unlock();
#endif
            return false;
        }
        Message(){ // 构造函数
#ifdef _WINDOWSJQ_
        InitializeCriticalSection(&cs); // 用临界区前先初始化
#endif
        }

        void testfunc1(){
            std::lock_guard<std::mutex> lck(mtx); 
            // ...干一些事情
            testfunc2(); // 这里可能会异常崩溃
        }
        void testfunc2(){
            std::lock_guard<std::mutex> lck(mtx); 
            // ...干另一些事情
        }


    private:
        list<int> msgQueue; // 存储发送来的命令容器
        mutex mtx; // 互斥锁
        std::recursive_mutex rmtx; // 递归互斥锁
#ifdef _WINDOWSJQ_ 
        // 如果定义了_WINDOWSJQ_，则使用windows临界区
        CRITICAL_SECTION cs; // dinginesswindows临界区,和c++11的mutex很像
#endif
};

void test_thread(){
    Message msg;
    thread t1(bind(&Message::collect_msg, &msg));
    thread t2(bind(&Message::take_msg, &msg));
    t1.join();
    t2.join();
}
/*
g++ -o main_g++  main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/
