/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 15:27:35
 * @LastEditTime: 2022-05-26 08:35:30
 * @Description: \chapter4\main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter4\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <list>
#include <windows.h> // sleep
using namespace std;
const vector<int> shared_data_only_read = {1,2,3}; // 全局共享只读数据
vector<int> shared_data_read_write = {1,2,3}; // 全局共享可读可写数据
void printnum(int num){
    for(int i = 0; i<1000;++i){}
    cout<<"num = "<<num<<endl;
}
void create_wait_threads(){
    cout<<"1.------------------------------>\n";
    vector<thread> mythreads;
    for(int i = 0; i<10; i++){
        mythreads.push_back(thread(printnum,i+1));
    }
    for (auto &t : mythreads) t.join();
    cout<<"1.I love China!"<<endl;
}
void printid(){
    cout<<"thread's id = "<<this_thread::get_id()<<
        " vec[0] = "<<shared_data_only_read[0]<<
        " vec[1] = "<<shared_data_only_read[1]<<
        " vec[2] = "<<shared_data_only_read[2]<<endl;;
}
void data_only_read(){
    cout<<"2.------------------------------>\n";
    vector<thread> mythreads;
    for(int i = 0; i<10; i++){
        mythreads.push_back(thread(printid));
    }
    for (auto &t : mythreads) t.join();
    cout<<"2.I love China!"<<endl;
}
void data_enable_write(){
    // 例如2个线程写,8个线程读,没有特别处理就会崩溃
    // 1.读的时候不能写,写的时候不能读
    // 2.2个线程不能同时写,8个线程不能同时读
    // 3.由于任务切换会导致各种崩溃情况发生
    cout<<"3.------------------------------>\n";
    // ...做一些事情
    cout<<"3.I love China!"<<endl;
}
// 案例命令消息类
class Message{
    public:
        void collect_msg(){// 模拟收集过来的命令
            for(int i = 0; i<10000; ++i){
                msgQueue.push_back(i+1);
            }
        }
        void take_msg(){ // 模拟取出命令
            for(int i = 0; i<10000; ++i){
                if (!msgQueue.empty()){
                    int command = msgQueue.front(); // 取出最早的命令
                    // 依据命令...做一些事情
                    // 例如打印命令值
                    cout<<"msg["<<i<<"] = "<<command<<endl;
                    msgQueue.pop_front(); 
                }
                else{cout<<"msg queue is empty!"<<endl;}   
            }
            return;
        }
    private:
        list<int> msgQueue; // 存储发送来的命令容器
};
void example(){
    // 创建2个线程
    Message msg;
    thread collect_msg(&Message::collect_msg,std::ref(msg));
    thread take_msg(&Message::take_msg,std::ref(msg)); // 必须在后边,否则打印消息队列为空
    // 实际上这段代码是可能报错的,因为存在写入数据时候也会读取数据,所以引入互斥量解决这个问题
    take_msg.join();
    collect_msg.join();
    
}
int main(){
    /*
        (1) 创建和等待多个线程
            多个线程执行顺序是乱的这与操作系统内部对线程的运行调度有关
            主线程等待所有子线程运行结束，最后主线程结束，推荐create_wait_threads这种写法
            将线程放在容器中方便管理，一次性join
        (2) 数据共享问题分析
            (2.1) 只读数据
                安全稳定的,无需任何处理,直接读取数据即可,根据printid情况,数据读取的都是正确的
            (2.2) 可读可写
                1.读的时候不能写,写的时候不能读
                2.多个线程不能同时写
                3.多个线程不能同时读
                4.由于任务切换会导致各种崩溃情况发生
        (3) 共享数据的保护案例代码
            例如网络游戏2个线程,1个线程收集玩家命令,写入队列,另1个线程取出命令并执行
            这里使用list,频繁的插入和删除时比vector效率高
            使用成员函数作为线程函数的方法来写线程
            互斥量：解决多线程保护共享数据问题,chapter5继续讲解
    */
    // (1) 创建和等待多个线程
    create_wait_threads();
    // (2) 数据共享问题
    // (2.1) 只读数据
    data_only_read();
    // (2.2) 可读可写
    data_enable_write();
    // (3) 案例
    example();
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/