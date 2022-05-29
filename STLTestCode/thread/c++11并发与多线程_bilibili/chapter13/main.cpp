/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:36:46
 * @LastEditTime: 2022-05-29 12:14:36
 * @Description: /chapter13/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter13\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <future>
#include <list>
#include <functional>
using namespace std;
class A{
    public:
        atomic<int> ata;
        A(){
            ata = 0;
            // auto ata1 = ata;//拷贝函数被delete了,所以这里不能用auto
            // 以原子方式读取和构造
            atomic<int> ata2(ata.load()); // ok
            auto ata3(ata.load()); // ok
            // 以原子方式写入
            ata2.store(12); // ok
            ata2 = 12; // ok
        }
        void accept(){
            for(int i = 0; i< 100 ; ++i){
                cout<<"accept msg "<<i+1<<endl;
                unique_lock<mutex> lck(mtx);
                msgQueue.push_back(i+1);
                cond.notify_one(); // 使用条件变量
            }
        }
        void send(){
            for(int i = 0; i < 105 ; ++i){
                sleep(10); // 适当的延时可以让send成功发送消息
                int command = 0;
                bool flag = get(command);
                if (flag){
                    cout<<"get msg is end,the last command is "<<command<<endl;
                    return;
                }
                else{
                    cout<<"no msg "<<i+1<<endl;
                    return;
                }
            }
        }
        bool get(int& command){
            while (1){
                unique_lock<mutex> lck(mtx); // 等待消息
                cond.wait(lck,[this]{ // 拿到锁再去判断
                    if (!msgQueue.empty()) 
                        return true;
                    return false;
                }); // 等待消息队列不为空
                
                command = msgQueue.front();
                msgQueue.pop_front();
                lck.unlock(); // 由于unique_lock的灵活性可以随时unlock解锁防止锁住太长时间
                cout<< "get msg "<<command<<endl;
                if (msgQueue.empty()){ // 这可以防止程序一直卡着不退出循环
                    break; 
                }
            }
            return true;
        }
        void sleep(int ms){
            this_thread::sleep_for(chrono::milliseconds(ms));
        }
    private:
        list<int> msgQueue;
        mutex mtx;
        condition_variable cond; // 条件变量
};
void test(){
    A a;
    thread t1(bind(&A::accept,&a));
    thread t2(bind(&A::send,&a));
    t1.join();
    t2.join();
}
int main(){
    /*
        (1) 补充知识点
            (1.1) 虚假唤醒
                前伸知识就是wait(),notify()和notify_all(),唤醒线程
            (1.2) atomic
                cout<<atm<<endl;不是原子操作,会出现脏读
                禁止了拷贝操作,原子对象不允许被拷贝
                以原子的方式读写atomic对象的值：
                // 以原子方式读取和构造
                atomic<int> ata2(ata.load()); // ok
                auto ata3(ata.load()); // ok
                // 以原子方式写入
                ata2.store(12); // ok
                ata2 = 12; // ok
        (2) 浅谈线程池
            (2.1) 场景设想
                服务器程序,每来一个客户端就创建一个线程为客户提供服务，这样系统资源是不够的
                偶尔创建一个线程的写法虽然可以，但是不安全，有时候不稳定
                把线程一起管理，统一管理，循环利用就叫线程池
            (2.2) 实现方式
                在程序启动时就一次性创建好一定数量的线程
        (3) 线程创建数量谈
            2000个线程基本是极限
            或者依据厂商的要求，例如创建线程数量等于cpu数量，或者cpu*2等等
            不要超过500个，尽量控制在200个
        (4) c++11多线程总结
            windows和linux有些不同
    */
    test();
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/
