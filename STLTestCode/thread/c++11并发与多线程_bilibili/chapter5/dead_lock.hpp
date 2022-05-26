/*** 
 * @Author: chenbei
 * @Date: 2022-05-26 08:56:50
 * @LastEditTime: 2022-05-26 10:04:47
 * @Description: dead_lock.hpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter5\dead_lock.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>
using namespace std;
class NewMessage{
    public:
        void collect_msg(){// 模拟收集过来的命令
            for(int i = 0; i<1000; ++i){
                cout<<"collect msg "<<i+1<<endl;
                {
                    mtx1.lock(); // 至少2把锁,这里先锁1再锁2
                    // // ....实际过程中中间会有一些其它事在这里处理,2把锁不一定挨着
                    mtx2.lock();
                    // 还可以同时锁住
                    // std::lock(mtx1,mtx2); // it's ok
                    msgQueue.push_back(i+1);
                    mtx1.unlock();// 解锁顺序无所谓
                    // 同理,这里会处理一些事情...
                    mtx2.unlock();
                }
            }
        }
        void take_msg(){ // 模拟取出命令
            for(int i = 0; i<10000; ++i){
                int command = 0;
                bool result = exec_command(command);
                if (result){
                    cout<<"take msg "<<command<<endl;
                }
                else{cout<<"no msg"<<endl;}
            }
            return;
        }
        bool exec_command(int &command){ // 注意是引用,所以command在外部会更改
            mtx1.lock(); // 这里是先锁2再锁1,会造成死锁问题,虽然演示起来好像没有
            mtx2.lock();
            // std::lock(mtx2,mtx1); // 这里是先锁1再锁2,会造成死锁
            if (!msgQueue.empty()){
                command = msgQueue.front(); // 取出最早的命令
                msgQueue.pop_front();
                mtx1.unlock(); // 解锁顺序无所谓
                mtx2.unlock();
                return true;
            }
            mtx1.unlock();// 解锁顺序无所谓
            mtx2.unlock();
            return false;
        }
    private:
        list<int> msgQueue; // 存储发送来的命令容器
        mutex mtx1; 
        mutex mtx2;
};
void new_example(){
    NewMessage msg;
    thread collect_msg(&NewMessage::collect_msg,std::ref(msg));
    thread take_msg(&NewMessage::take_msg,std::ref(msg)); 
    take_msg.join();
    collect_msg.join();
}