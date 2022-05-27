/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:34:58
 * @LastEditTime: 2022-05-27 09:17:19
 * @Description: /chapter8/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter8\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <functional> // bind
#include <chrono>
#include <condition_variable>
using namespace std;
class A{
    public:
        void accept(){
            for(int i = 0; i< 100 ; ++i){
                cout<<"accept msg "<<i+1<<endl;
                unique_lock<mutex> lck(mtx);
                msgQueue.push_back(i+1);
            }
        }
        void send(){
            for(int i = 0; i < 100 ; ++i){
                sleep(10); // 适当的延时可以让send成功发送消息
                int command = 0;
                bool flag = get(command);
                if (flag){
                    cout<<"send msg "<<command<<endl;
                }
                else{
                    cout<<"no msg "<<i+1<<endl;
                }
            }
        }
        void receive(){
            for(int i = 0; i< 100 ; ++i){
                cout<<"accept msg "<<i+1<<endl;
                unique_lock<mutex> lck(mtx);
                cond.notify_one(); // 唤醒wait()的线程
                msgQueue.push_back(i+1);
            }
        }
        void receive1(){
            for(int i = 0; i< 100 ; ++i){
                cout<<"accept msg "<<i+1<<endl;
                unique_lock<mutex> lck(mtx);
                cond.notify_all(); // 唤醒wait()的所有线程
                msgQueue.push_back(i+1);
            }
        }
        void transmit(){ // send的翻版,利用condition_variable实现,比sleep速度快
            int command = 0;
            while (1){
                unique_lock<mutex> lck(mtx);
                // 如果不为空就返回true那么就可以获取到消息,否则就等待
                // 返回false会卡在这里,即消息队列为空的时候并释放这个互斥量unlock,让别的线程可以获取到这个互斥量
                cond.wait(lck,[this]{return !msgQueue.empty();}); // 等待消息队列不为空
                // 相对于之前的sleep其实也是等待消息队列不为空,如果之前不加sleep
                // 那么就会出现消息队列为空的情况,会打印很多no msg的情况

                // 如果代码执行到这,说明互斥锁一定是lock的状态
                command = msgQueue.front();
                msgQueue.pop_front();
                lck.unlock(); // 由于unique_lock的灵活性可以随时unlock解锁防止锁住太长时间
                cout<< "transmit msg "<<command<<endl;

                // 不要使用msgQueue.empty()判断,因为可能只是来不及插入消息,队列才为空
                // 但是如果命令能获得100说明已经100插入过了,程序可以结束了
                if (command == 100){ // 这可以防止程序一直卡着不退出循环
                    break; 
                }
            }
        }
        void transmit1(){ // 处理多线程的情况
            // 也就是这里transmit1被2个线程调用了
            int command = 0;
            while (1){
                unique_lock<mutex> lck(mtx);
                // 2个线程都会被卡在这里
                cond.wait(lck,[this]{return !msgQueue.empty();}); 
                command = msgQueue.front();
                msgQueue.pop_front();
                lck.unlock(); 
                cout<< "transmit msg "<<command<<" thread id = "<<this_thread::get_id()<<endl;
                // if (command == 100){ // 这里没用,因为2个线程随机有1个被唤醒,最后1个命令未必是100
                //     break; 
                // }
            }
        }
        bool get(int& command){
            if (!msgQueue.empty()){ // 双重锁定
                unique_lock<mutex> lck(mtx); // 不为空的时候才加锁
                if(msgQueue.empty()){
                    return false;
                }
                command = msgQueue.front();
                msgQueue.pop_front();
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
void example_sleep(){
    A a;
    thread t1(bind(&A::accept,std::ref(a))); // 使用引用保证引用同1对象
    thread t2(bind(&A::send,std::ref(a)));
    t1.join();
    t2.join();

}
void example_condition_variable(){
    A a;
    thread t1(bind(&A::receive,std::ref(a)));
    thread t2(bind(&A::transmit,std::ref(a)));
    t1.join();
    t2.join();
}
void example_condition_variable_1(){
    // 区别是发送消息有2个线程,接收消息有1个线程
    // 2个线程随机有1个被唤醒,运行结果会发现这里会卡住
    A a;
    thread t1(bind(&A::receive,std::ref(a)));
    thread t2(bind(&A::transmit1,std::ref(a)));
    thread t3(bind(&A::transmit1,std::ref(a)));
    t1.join();
    t2.join();
    t3.join();
}
void example_condition_variable_2(){
    // 区别是使用receive1函数,会唤醒所有线程
    A a;
    thread t1(bind(&A::receive1,std::ref(a)));
    thread t2(bind(&A::transmit1,std::ref(a)));
    thread t3(bind(&A::transmit1,std::ref(a)));
    t1.join();
    t2.join();
    t3.join();
}
int main(){
    /*
        (1) 条件变量 condition_variable、wait()、notify_one()
            线程A等待一个条件满足，线程B往消息队列中扔消息
            线程A收到消息后，通知线程B，线程B收到消息后，通知线程A
            需要和互斥量配合使用,详见submit()的实现
            (1.1) wait()
                用来等待一个东西,第一参数是智能锁或者mutex,第二参数是可调用对象,常用lambda表达式
                如果lambda表达式返回值为false就解锁互斥量(可以让其他线程获取到)并持续等待,直到某个线程调用notify_one()为止
                如果没有第2个参数,就和第2参数返回false的效果一样
            (1.2) notify_one()
                唤醒一个等待的线程,可以唤醒wait()的线程
            (1.3) notify_all()
                唤醒所有等待的线程
        (2) notify_all()
    */
    example_sleep(); // 使用sleep等待
    example_condition_variable(); // 使用condition_variable等待,速度更快
    // example_condition_variable_1(); // 接收单线程,发送多线程,单线程唤醒,运行会卡住
    example_condition_variable_2(); // 接收单线程,发送多线程,所有线程被唤醒,运行也会卡住
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/