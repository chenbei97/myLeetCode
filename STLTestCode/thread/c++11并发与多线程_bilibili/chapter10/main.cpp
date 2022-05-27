/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:35:45
 * @LastEditTime: 2022-05-27 17:33:55
 * @Description: /chapter10/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter10\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <future>
using namespace std;
int g_sync = 0; // 全局量
std::mutex g_mutex; // 全局互斥量
std::atomic<int> g_atomic(0); // 原子类型
std::atomic<bool> g_bool(false); // 原子类型
int mythread1(int async);
void mythread2(std::future<int> &fut);
void mythread3(std::shared_future<int> &fut);
void mythread4();
void mythread5();
void mythread6();
void test_mythread1_future_status();
void test_thread1_shared_future();
void test_unstable();
void test_stable();
void test_atomic();
int main(){
    /*
        (1) future其它成员函数
            (1.1) future_status
            枚举类型，表示future对象的状态，有如下几种状态：
                enum class future_status
                {
                    ready,
                    timeout,
                    deferred
                };
                future_status::ready: 表示future对象已经被设置，并且可以获取其值,使用get()
                future_status::timeout: 表示future对象在指定的时间内没有被设置，超时
                future_status::deferred: 对应std::async第1个参数为launch::deferred的情况
            (1.2) get_future
                返回一个future对象，该对象可以获取future对象的值
            (1.3) wait_for
                等待一段时间，返回一个future_status类型的值,表明future对象是否已经执行完成
            (1.4) wait_until
                和wait_for的区别是，wait_until可以指定一个时间点，在该时间点之前，future对象是否已经执行完成
            (1.5) wait
                wait和wait_for的区别是，wait会一直等待，直到future对象执行完成
            (1.6) valid
                判断future对象是否被设置
            (1.7) get
                获取future对象的值,内部实现是移动语义,所以不能多次get
            (1.8) share
                获取future对象的引用
        (2) shared_future
            可以智能的get,get()函数是复制数据而不是移动语义
            可以从packaged_task中的get_future()获取shared_future
            也可以从future的share()获取shared_future
            最后可以从future通过move()获取shared_future
        (3) 原子操作atomic
            (3.1) 原子操作概念
                互斥量用于多线程中保护共享数据,可以不通过加锁和解锁来实现互斥量
                互斥量针对一个代码段，而原子操作只对变量有效
                而且对基础类型相对比较好，如果是结构体等复杂对象还是互斥量比较好
                原子操作是一种不可分割的操作，要么完成要么没完成，不存在半完成的情况，例如deferre的情况
            (3.2) 用法示例
    */
    // 测试future_status
    cout<<"1.---------------------------"<<endl;
    // test_mythread1_future_status();
    // 测试shared_future
    cout<<"2.---------------------------"<<endl;
    test_thread1_shared_future();
    // 测试不稳定性案例
    cout<<"3.---------------------------"<<endl;
    test_unstable();
    g_sync = 0; // 恢复初始值
    // 测试稳定性案例
    cout<<"4.---------------------------"<<endl;
    test_stable();
    // 测试原子操作
    cout<<"5.---------------------------"<<endl;
    test_atomic();
    return 0;
}
int mythread1(int async){
    // 第1个线程函数
    cout<<"mythread1() is called, thread_id = "<<this_thread::get_id()<<endl;
    cout << "async = " << async << endl;
    std::chrono::milliseconds dura(2000);
    std::this_thread::sleep_for(dura);
    cout<<"mythread1() is end, thread_id = "<<this_thread::get_id()<<endl;
    return async;
}
void mythread2(std::future<int> &fut){
    // 第2个线程函数,会把第1个线程函数的async参数接收
    cout<<"mythread2() is called, thread_id = "<<this_thread::get_id()<<endl;
    cout << "accept async = " << fut.get() << endl;
}
void mythread3(std::shared_future<int> &fut){
    // 第3个线程函数,会把第1个线程函数的async参数接收
    // 相比第2个线程函数可以返回get()
    cout<<"mythread3() is called, thread_id = "<<this_thread::get_id()<<endl;
    cout << "accept async = " << fut.get() << endl;
    cout << "accept async again = " << fut.get() << endl;
}
void mythread4(){
    // 不稳定的线程函数
    for(int i = 0; i< 1000000; i++){
        g_sync++;
    }
}
void mythread5(){
    // 稳定的线程函数
    for(int i = 0; i< 1000000; i++){
        g_mutex.lock();
        g_sync++;
        g_mutex.unlock();
    }
}
void mythread6(){
    // 原子类型的线程函数
    for(int i = 0; i< 1000000; i++){
        g_atomic++; // 直接调用原子类型的原子操作
    }

    std::chrono::microseconds dura(1000);
    while (g_bool == false) {
        cout<<"thread id = "<<this_thread::get_id()<<" continue working ..."<<endl;
        std::this_thread::sleep_for(dura);
    }
}
void test_mythread1_future_status(){
    // 测试future_status
    cout<<"test future_status is called, main thread_id = "<<this_thread::get_id()<<endl;
    std::future<int> f = std::async(std::launch::deferred,mythread1,10);
    cout<<"continue.........~"<<endl;

    // 枚举类型
    std::future_status status = f.wait_for(std::chrono::seconds(1)); // 等待1秒
    // 返回的状态如果是timeout，则表示在指定的时间内没有被设置，超时,这里线程内要等待2s,这里是最多等待1s
    // 所以是超时的,下方语句第1条if成立
    if(status == std::future_status::timeout){
        cout<<"thread is timeout"<<endl;
    }else if(status == std::future_status::ready){ // 如果等待设置的是3s那么这条语句会被执行
        cout<<"thread is ready"<<endl;
        cout<<"future result = "<<f.get()<<endl;
    }
    else{
        cout<<"thread is deferred"<<endl; // 对应std::async第1个参数为launch::deferred的情况
        cout<<"future result = "<<f.get()<<endl;
    }
    cout<<"test future_status is end\n";
}
void test_thread1_shared_future(){
    // 主线程
    cout<<"test shared_future is called, main thread_id = "<<this_thread::get_id()<<endl;
    
    // 封装好第1个线程函数用于传递值
    std::packaged_task<int(int)> task1(mythread1); // 包装第一个函数mythread1
    std::thread t1(std::ref(task1),15); // 创建一个线程
    t1.join(); // 等待线程结束
    std::future<int> f1 = task1.get_future(); // 获取future对象

    // 使用shared_future包装获得的future对象,3种写法都可以
    // std::shared_future<int> sf1 = f1.share(); // 1.使用share()发方法
    // std::shared_future<int> sf1(task1.get_future()); // 2.直接从get_future()获取
    std::shared_future<int> sf1(std::move(f1)); // 3.使用move构造函数
    bool isvalid = f1.valid(); // 判断future对象是否被设置
    cout<<boolalpha<<"future is valid = "<<isvalid<<endl; // false
    cout<<boolalpha<<"shared_future is valid = "<<sf1.valid()<<endl; // true,转移到shared_future对象中
    auto result = sf1.get(); // 获取shared_future对象的值
    result = sf1.get(); // 再次获取shared_future对象的值也是ok的
    cout<<"get result = "<<result<<endl; // 15
    
    // 第2个线程函数用于接收值,不需要使用packaged_task封装
    // std::thread t2(mythread2,std::ref(f1)); // 把线程1得到的future对象传递给线程2
    std::thread t2(mythread3,std::ref(sf1)); // 注意mythread3参数也变为shared_future对象
    t2.join();

    cout<<"test shared_future is end\n";
}
void test_unstable(){
    // 很可能造成线程安全问题
    // 一个不稳定测试的案例
    thread t1 (mythread4);
    thread t2 (mythread4);
    t1.join();
    t2.join();
    cout<<"unstable = > two thread is end, g_sync = "<<g_sync<<endl; // 结果不是200万
}
void test_stable(){
    // 不会造成线程安全问题
    // 一个稳定测试的案例
    thread t1 (mythread5);
    thread t2 (mythread5);
    t1.join();
    t2.join();
    cout<<"stable = > two thread is end, g_sync = "<<g_sync<<endl; // 结果是200万
}
void test_atomic(){
    // 不会造成线程安全问题
    // 一个稳定测试的原子操作案例
    thread t1 (mythread6);
    thread t2 (mythread6);
    std::chrono::milliseconds dura(2000);
    this_thread::sleep_for(dura);
    g_bool = true; // 进行写操作,让线程直接自行结束
    t1.join();
    t2.join();
    cout<<"atomic = > two thread is end, g_atomic = "<<g_atomic<<endl; // 结果是200万
    cout<<"test atomic is end\n";
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/