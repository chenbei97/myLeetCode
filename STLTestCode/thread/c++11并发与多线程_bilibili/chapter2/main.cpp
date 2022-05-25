/*** 
 * @Author: chenbei
 * @Date: 2022-05-25 07:55:08
 * @LastEditTime: 2022-05-25 09:53:41
 * @Description: \chapter2\main.cpp
 * @FilePath: \myLeetCode\STLTestCode\thread\c++11并发与多线程_bilibili\chapter2\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <windows.h> // sleep
using namespace std;
// 创建自己的线程从函数开始执行,这里建立1个线程
void myPrint(){
    cout<<"this is my thread is called"<<endl;
    cout<<"my thread id is "<<this_thread::get_id()<<endl;
    cout << "my thread is running" << endl;
    cout << "my thread is end" << endl;
}
void myPrint1(){
    string str = "this is my thread is called";
    for (int i = 0; i<25; ++i){
        string tem = str+to_string(i+1);
        cout<<tem<<endl;
    }
}
class myThread{
    public:
        myThread(){}
        myThread(const string &str):str_(str){}
        void operator()(){ // 要求不带参数,也就是实现为仿函数对象
            cout<<"class myThread's operator() is called, str = "<<str_<<endl;
        }
    private:
        string str_ = "hello, lao baby";
};
class myThread1{
    public:
        myThread1(string &str):str_(str){cout<<"myThread1's default constructor is called"<<endl;}
        myThread1(const myThread1 & rhs):str_(rhs.str_){cout<<"myThread1's copy constructor is called!"<<endl;} // 拷贝构造
        ~myThread1(){cout<<"myThread1's destructor is called"<<endl;}
        void operator()(){ // 要求不带参数,也就是实现为仿函数对象
            string str = "class myThread's operator() is called, str = " + str_;
            for (int i = 0; i<10; ++i){
                string tem = str+to_string(i+1);
                cout<<tem<<endl;
            }
        }
    private:
        string &str_ ;
};
int main(){
    /*
    (1) 范例演示线程运行的开始和结束
        (1.1)主线程从main()运行,自己创建的线程也要从1个函数开始执行
        这个函数执行完毕就代表这个线程结束，该函数一般也叫做初始化函数
        
        (1.2)join函数的意思是阻塞主线程,让主线程等待子线程执行完毕,然后子线程和主线程合并
        如果没有join,输出结果：
            main thread is called
            tterminate called without an active exception
            his is my thread is called
            my thread id is 2
            my thread is running
            my thread is end
            相当于主线程先干掉了子线程，再执行主线程
        有join，输出结果是正常的：
            this is my thread is called
            my thread id is 2
            my thread is running
            my thread is end
            main thread is called
        
        (1.3)如果希望主线程无需等待子线程执行完毕，可以使用detach函数
        主线程和子线程最后不会汇合，各走各的，主线程无需等待子线程结束
        这是因为创建了很多子线程，让主线程逐个等待耗时，所以引入detach函数
        子线程与主线程分离之后，子线程会在后台驻留执行，子线程结束运行后，运行时库会接管负责清理该线程相关的资源
        还要注意，如果调用了detach就不能再调用join函数了，否则会报错
        输出结果：
            ------------------------------------->
            main thread is called again1this is my thread is called1 主线程和子线程发生了竞争
            this is my thread is called2 子线程
            this is my thread is called3
            this is my thread is called4
            this is my thread is called5
            this is my thread is called6
            this is my thread is called7
            this is my thread is called8
            this is my thread is called9
            this is my thread is called16
            this is my thread is called17
            this is my thread is called18
            this is my thread is called19
            this is my thread is called20
            this is my thread is called21
            this is my thread is called22
            this is my thread is called23
            this is my thread is called24
            this is my thread is called25

            main thread is called again2 主线程
            main thread is called again3
            after sleep 1s main thread id called again
            可以发现，主线程并没有等待子线程，子线程也没有等待主线程，各走各的
        (1.4) joinable可以判断线程是否可以使用join()或detach()函数
        返回true说明可以join或detach，返回false说明不可以join和detach
    (2) 其他创建线程的手法
        (2.1) 使用类的示例
            首先是myThread类可以重载operator()实现仿函数对象,也可以被线程调用
            但是要注意如果类的构造函数参数是一个引用,也就是引用了主线程的某个变量
            那么主线程结束后这个变量会被销毁，但是该类对象依然还在子线程的话就会出现不可预料的后果
            再就是，类对象在主线程结束后也会被销毁，不过类对象被子线程调用其实是一个复制值传递，所以子线程还是存在的
            但是如果类对象存在引用和指针就可能因为不是深拷贝的原因造成复制错误
    */
    // (1.1) create a thread
    thread mythread(myPrint); // 从该函数开始执行,入口myPrint()
    if (mythread.joinable()){
        cout<<"mythread is joinable"<<endl; // mythread is joinable
    }
    else{
        cout<<"mythread is not joinable"<<endl;
    }
    // (1.2) block the main thread
    mythread.join(); // 等待子线程结束
    cout<<"main thread is called"<<endl; // 主线程

    cout<<"------------------------------------->\n";
    // (1.3) detach the thread
    thread  newthread(myPrint1); // 创建新线程
    newthread.detach(); // 取消该子线程与主线程的关联
    if (newthread.joinable()){
        cout<<"newthread is joinable"<<endl;
    }
    else{
        cout<<"newthread is not joinable"<<endl; // newthread is not joinable
    }
    cout<<"main thread is called again1"<<endl;
    cout<<"main thread is called again2"<<endl;
    cout<<"main thread is called again3"<<endl;
    // 延迟1s
    Sleep(1000);
    cout<<"after sleep 1s main thread is called again"<<endl;
    
    cout<<"------------------------------------->\n";
    // (2.1) 使用仿函数对象
    myThread mt;
    mt(); // class myThread's operator() is called, str = hello, lao baby
    mt = string("hello, new baby"); // 隐式转换
    thread t1(mt); // mt是可调用对象
    t1.join(); // class myThread's operator() is called, str = hello, new baby
    cout <<"after class function obeject is called, main thread is called"<<endl;
    
    // 类带引用参数,也就是类引用了主线程的变量mystring,结束后它被销毁
    // 但是如果子线程还在内部使用了这个变量(引用),且主线程结束后还在调用就会不可预料结果
    // 下边这段程序每次运行的结果都不一样,类中的子线程可能打印不完整
    cout<<"------------------------------------->\n";
    string mystring = "hello, world!";
    myThread1 mt1(mystring); // 调用参数构造 myThread1's default constructor is called
    thread t2(mt1); // 注意，类对象是被复制进这个子线程的,属于值传递,调用了复制构造函数
    t2.detach();
    for(int i = 0 ; i<5; ++i){
        cout<<"mystring"+to_string(i+1)<<" = "<<mystring<<endl; 
    }
    mystring.~basic_string(); 
    cout <<"mystring is destroyed!"<<endl;// 紧接着调用了线程myThread1的析构函数 myThread1's destructor is called

    // (2.2) 使用lambda表达式
    cout<<"------------------------------------->\n";
    thread t3([](){
        cout<<"lambda expression is called"<<endl;
    });
    t3.detach();
    cout<<"after lambda expression is called, main thread is called again"<<endl;
    // 输出结果也是很乱,因为lambda表达式是在子线程中执行的,每次运行结果不一样
    return 0;
}
/*
g++ -o main_g++ main.cpp
.\main_g++.exe
cl /Fo".\main_cl" /Fe".\main_cl.exe" /std:c++latest ".\main.cpp"
.\main_cl.exe
*/