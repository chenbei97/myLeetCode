/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:32:04
 * @LastEditTime: 2022-05-26 09:24:28
 * @Description: /chapter5/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter5\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>
#include "dead_lock.hpp"
using namespace std;
class Message{
    public:
        void collect_msg(){// 模拟收集过来的命令
            for(int i = 0; i<10000; ++i){
                // 如果不使用智能锁,一前一后用lock和unlock
                // 如果需要智能锁最好加上{},这样可以离开{}作用域时析构
                cout<<"collect msg "<<i+1<<endl;
                {
                    std::lock_guard<std::mutex> lk(mtx);
                    // mtx.lock(); // 保护锁
                    msgQueue.push_back(i+1);
                }
                // mtx.unlock(); // 解锁
            }
        }
        void take_msg(){ // 模拟取出命令
            int command = 0;
            // 取出命令似乎比收集命令慢,取出停止后还在收集,所以这里循环适当延长
            // 运行结果会显示最后的消息都是no msg而不是collect msg
            for(int i = 0; i<80000; ++i){
                bool result = exec_command(command);
                if (result){
                    cout<<"take msg "<<command<<endl;
                }
                else{cout<<"no msg"<<endl;}
            }
            return;
        }
        bool exec_command(int &command){ // 注意是引用,所以command在外部会更改
            std::lock_guard<std::mutex> lck(mtx); // 智能锁
            // mtx.lock();
            if (!msgQueue.empty()){
                int command = msgQueue.front(); // 取出最早的命令
                msgQueue.pop_front();
                // mtx.unlock(); // 注意2个分支都要unlock
                return true;
            }
            // mtx.unlock();
            return false;
        }
    private:
        list<int> msgQueue; // 存储发送来的命令容器
        mutex mtx; // 互斥锁
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
        接着chapter4的案例说明互斥量的作用
        (1) 互斥量mutex的基本概念
            可以先用锁将共享数据锁住，阻止其他线程对共享数据的访问，直到解锁为止
            互斥量是个类对象，可以使用lock成员函数加锁,unlock成员函数解锁
            多个线程可以同时去锁定，但是只有1个线程可以锁定，如果lock函数返回了说明锁定成功，否则卡在这里就一直等待尝试去锁定
            互斥量使用时要注意保护的数据恰到好处,保护的太多了可能会导致卡住导致效率低下,保护的少了没有效果
        (2) 互斥量的用法
            (2.1) lock(),unlock()
                先lock然后unlock,这样就可以保证数据的安全,必须成对使用
            (2.2) std::lock_guard类模板
                这个类模板相当于智能锁,可以自动锁定和解除锁定,不需要自己去解锁
                构造函数中调用了lock函数,析构函数中调用了unlock函数
        (3) 死锁
            (3.1) 死锁演示
                至少2把锁会产生死锁问题
                线程1将第1把锁锁住,然后尝试锁第2把锁,不过这把锁是线程2的锁,所以线程1会等待线程2释放锁
                线程2事先已经锁定了第2把锁,现在尝试锁第1把,也就是等待线程1释放锁,这样就产生了死锁
            (3.2) 死锁的一般解决方案
                保证2把锁上锁的顺序都是一致的,就不会造成死锁
            (3.3) std::lock()函数模板
                可以代替成员函数lock,一次性加多个锁
            (3.4) std::lock_guard的std::adopt_lock参数
                可以在已经加锁的情况下不调用lock，它本身是一个结构体对象是个标记作用
                作用是表示这个互斥量已经lock了,不需要再次lock
                例如
                std::lock(mtx1,mtx2);//已经上锁
                // 继续上智能锁
                std::lock_guard<std::mutex> lck1(mtx1,std::adopt_lock);//不需要调用lock
                std::lock_guard<std::mutex> lck2(mtx2,std::adopt_lock);//不需要调用lock
        
    */
    // 如何使用互斥锁
    example(); //相比chapter4运行之后会有no msg被打印出来
    // 死锁问题的演示
    new_example();
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/