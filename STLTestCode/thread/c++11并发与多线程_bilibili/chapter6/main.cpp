/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 16:32:36
 * @LastEditTime: 2022-05-26 11:34:47
 * @Description: /chapter6/main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter6\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <chrono>
using namespace std;
class Message{
    public:
        std::unique_lock<std::mutex> rtn_unique_lock(){
            std::unique_lock<std::mutex> tem(mtx);
            return tem; // 移动构造是允许的
        }
        void collect_msg(int param){
            for(int i = 0; i<100; ++i){
                cout<<"collect msg "<<i+1<<endl;
                if (param){ // std::adopt_lock,std::defer_lock,std::try_to_lock
                    bool res = which_param(param);
                    cout<<boolalpha<<"collect res = "<<res<<endl;
                    if (res) msgQueue.push_back(i+1);
                    else {cout<<"can't collect msg"<<endl;break;}
                }
                else{ // release()
                    std::unique_lock<std::mutex> lck(mtx);
                    std::mutex * pmtx = lck.release();
                    msgQueue.push_back(i+1);
                    pmtx->unlock(); // 有责任自己解锁
                }

            }
        }
        void take_msg(int param){ 
            for(int i = 0; i<110; ++i){
                int command = 0;
                bool result = exec_command(command,param);
                if (!result){
                    cout<<"can't take msg"<<endl; 
                    break;
                }
                cout<<"take msg "<<command<<endl;
            }
            return;
        }
        bool exec_command(int &command,int param){ 
            if (param){ // std::adopt_lock,std::defer_lock,std::try_to_lock
                bool res = which_param(param);
                cout<<boolalpha<<"take res = "<<res<<endl;
                if (!res) return false;
                else{
                    sleep(1); // sleep可以用在take_msg也可以用在collect_msg,可以让线程先休息,这样可以使得collect执行完了再执行take
                    if (!msgQueue.empty()){
                        command = msgQueue.front(); // 取出最早的命令
                        msgQueue.pop_front();
                        return true;
                    }
                }
            }
            else{ // release()
                std::unique_lock<std::mutex> lck(mtx);
                std::mutex * pmtx = lck.release();
                if (!msgQueue.empty()){
                    command = msgQueue.front();
                    msgQueue.pop_front();
                    return true;
                }
            }
            return false;
        }
        bool param1(){ // std::adopt_lock
            sleep(100);
            cout<<"param1 is called"<<endl;
            mtx.lock();
            std::unique_lock<std::mutex> lk(mtx,std::adopt_lock);
            if (!lk.owns_lock()){
                cout<<"param1: lock failed"<<endl;
                return false;
            }
            return true;
        }
        bool param2(){ // std::try_lock
            sleep(100);
            cout<<"param2 is called"<<endl;
            mtx.lock();
            std::unique_lock<std::mutex> lk(mtx,std::try_to_lock);
            if (!lk.owns_lock()){
                cout<<"param2: lock failed"<<endl;
                return false;
            }
            return true;
        }
        bool param3(){ // std::defer_lock
            sleep(100);
            cout<<"param3 is called"<<endl; // 这里不要加锁
            std::unique_lock<std::mutex> lk(mtx,std::defer_lock);
            lk.lock(); // 在这里加锁
            if (!lk.owns_lock()){
                cout<<"param3: lock failed"<<endl;
                return false;
            }
            return true;
        }
        void sleep(int ms){
            std::chrono::milliseconds dura(ms); // 1ms
            std::this_thread::sleep_for(dura);
        }
    private:
        list<int> msgQueue; 
        mutex mtx; 
        // 定义输入void返回bool的函数指针
        // typedef bool (Message::*pf)();
        bool which_param(int param){
            bool res;
            switch(param){
                case 1:
                    res = this->param1();
                    break;
                case 2:
                    res = this->param2();
                    break;
                case 3:
                    res = this->param3();
                    break;
                default:
                    break;
            }
            return res;
        }
        // 依据传递的param参数让pf分别指向param1,param2,param3
        // pf pf_array[3] = {&Message::param1,&Message::param2,&Message::param3};

};
void example(int param){
    Message msg;
    thread collect_msg(&Message::collect_msg,std::ref(msg),param);
    thread take_msg(&Message::take_msg,std::ref(msg),param);
    take_msg.join();
    collect_msg.join();
}
int main(){
    /*
        (1) unique_lock取代lock_guard
            unique_lock是个类模板,更灵活,不过效率差一些内存占用多一些
        (2) unique_lock的第2个参数
            (2.1) std::adopt_lock
                chapter5已介绍过,起到标记作用,如果已经lock,则不会再lock
                但是确实之前被lock否则会报异常
            (2.2) std::try_to_lock
                尝试锁定互斥量,如果没有锁定成功就会立即返回不会阻塞在那里
                前提是互斥量不能已经上锁
            (2.3) std::defer_lock
                即会初始化1个unique_lock对象,但是不会加锁
        (3) unique_lock的成员函数
            (3.1) lock()
            (3.2) unlock()
            (3.3) try_lock()
            (3.4) release()
                注意和unlock()的区别,它需要自己手动解除
                也就是说如果原来的mutex处于加锁状态有责任接管过来并负责解锁
                release()返回的是原始mutex的指针而不是unique_lock对象
                std::mutext * pmtx = lk.release();
                ... // 做一些事情
                pmtx->unlock(); // 有责任自己解锁
        (4) unique_lock所有权的传递
            不能连续的2个unique_lock对象占有同一个mutex,否则会报错
            所有权可以转移但是不能复制,和unique_ptr类似,可以通过move进行转移
            std::unique_lock<std::mutex> rtn_unique_lock()
            {
                std::unique_lock<std::mutex> tem(mtx);
                return tem; // 移动构造是允许的
            }
            std::unique_lock<std::mutex> lck = rtn_unique_lock(); // 某个位置调用该成员函数是ok的
    */
    mutex mtx;
    unique_lock<mutex> lk(mtx);
    // unique_lock<mutex> lk2(mtx); // 报错
    unique_lock<mutex> lk2(std::move(lk)); // 正确

    cout<<"example(1)"<<endl;
    example(1);
    cout<<"example(3)"<<endl;
    std::chrono::milliseconds dura1(2000); // 2s
    std::this_thread::sleep_for(dura1);
    example(3);
    cout<<"example(2)"<<endl;
    std::chrono::milliseconds dura2(2000); // 2s
    std::this_thread::sleep_for(dura2);
    example(2); // 这个运行会出问题,尝试上锁失败然后卡住了
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/