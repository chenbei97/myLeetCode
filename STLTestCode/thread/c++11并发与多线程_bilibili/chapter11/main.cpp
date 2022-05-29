/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:36:08
 * @LastEditTime: 2022-05-29 10:22:55
 * @Description: /chapter11/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter11\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <future>
using namespace std;
std::atomic<int> g_async = 0;
// 上节课的例子
void mythread1();
void test_mythread1();
void mythread2();
void test_mythread2();
int mythread3();
void test_mythread3();
int main(){
    /*
        (1) std::atomic续谈
            一般原子操作，对++,--,+=,-=,|=是支持的
            其它的写法不支持,例如i=i+1,i=i-1,i=i&1,i=i^1,i=i<<1,i=i>>1
        (2) std::async深入谈
            (2.1) std::async参数说明
                std::launch::async: 异步执行,创建1个异步任务,一般不叫创建新线程,但是确实会强制异步任务在新线程中执行
                因为线程资源紧张时stf::thread可能会创建失败,所以可以使用std::launch::async
                std::launch::deferred: 延迟执行,直到调用std::future::get()时才执行,或者.wait()时才执行mythread()
                也可以2个参数同时执行,也就是使用或运算,一般跟随async,它话语权更大
                如果没有参数,默认是std::launch::async这句话其实也不完全对,其实默认值就是2个参数取或运算
            (2.2) 和std::thread的区别
                std::thread创建可能会失败,而且如果线程返回值,不好拿到这个值
                一般线程数量不超过100-200,
            (2.3) 不确定性问题的解决
                不加额外参数的std::async,让系统自行决定是否创建新线程
                再来说明future对象的wait_for函数，可以通过等例如2s来判断线程的状态
                也就是future_status::timeout,这个状态表示线程还没有执行完毕,等待2s后还是timeout
                valid可以判断线程是否可以get,如果可以get,那么就可以get到线程的返回值
    */
    // (1) std::atomic续谈
    test_mythread1(); // chapter10的例子
    test_mythread2(); // 改变写法就可能出错,atomic不支持i=i+1等
    // (2) std::async深入谈
    test_mythread3();
    return 0;
}
void mythread1(){
    for(int i = 0 ; i < 1000000; i++){
        g_async++;
    }
}
void test_mythread1(){
    std::thread t1(mythread1);
    std::thread t2(mythread1);
    t1.join();
    t2.join();
    cout << "g_async = "<< g_async << endl;
    g_async = 0;
}

void mythread2(){
    for(int i = 0 ; i < 1000000; i++){
        g_async = g_async + 1; // 这种写法就可能出错
    }
}
void test_mythread2(){
    std::thread t1(mythread2);
    std::thread t2(mythread2);
    t1.join();
    t2.join();
    cout << "g_async = "<< g_async << endl;
    g_async = 0;
}

int mythread3(){
    cout<<"thread3's id = "<<std::this_thread::get_id()<<endl;
    return 1;
}
void test_mythread3(){
    cout<<"test thread3's id = "<<std::this_thread::get_id()<<endl;
    // 如果使用deferred参数,thread3的id就是main的id,否则2个线程的id不一样
    // 如果2个合到一起或运算,会跟随async运算,也就是还会创建新的线程,async话语权更大一些,也是不传递枚举值的默认参数
    std::future<int> f = std::async(std::launch::async|std::launch::deferred,mythread3);
    std::future_status status = f.wait_for(std::chrono::seconds(2));
    if(status == std::future_status::timeout){
        cout<<"thread3's status = timeout"<<endl;
    }
    else if (status == std::future_status::ready){
        cout<<"thread3's status = ready"<<endl;
        cout<<"thread3's value = "<<f.get()<<endl;
    }
    else{
        cout<<"thread3's status = deferred"<<endl;
    }
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/