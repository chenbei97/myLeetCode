/*
 * @Author: chenbei
 * @Date: 2022-08-08 08:17:58
 * @LastEditTime: 2022-08-08 09:46:16
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap02\\2.1.cpp
 * @Description: 2.1 线程的基本管控
 * @Signature: A boy without dreams
 */
#include <thread>
void do_something();
void do_something_else(int i);
std::thread mythread(do_something); // 函数指针

class backTask{
    public:
        void operator()()const{
            do_something();
            //...
        }
};

backTask task;
std::thread my_thread(task); // 函数对象

// thread构造函数可以使用函数指针、函数对象和匿名函数
// 如果传入的临时变量而不是具名变量，那么调用构造函数的语法可能与函数声明相同
// 这种情况，编译器依据规则：针对存在二义性的C+++语句，只要它可能被解释成函数声明，编译器就一定会解释为函数声明，这样就不是定义对象

std::thread myt(backTask()); // 解释成接收1个函数指针参数(函数指针是无输入参数返回backTask对象的函数)返回thread对象的函数声明
// 解决方法是多加一组圆括号或者使用花括号或者使用匿名函数
std::thread myt1((backTask()));
std::thread myt2{backTask()};
std::thread myt3([]{
    do_something();
    //...
});

// 线程启动之后可以汇合也可以分离,如果没有选择其中之一,std::thread会调用std::terminate()终止整个程序

struct func
{
    int & i;
    func(int& i_):i(i_){}
    void operator()()
    {
        for (unsigned int j = 0 ;j<100000; ++j)
        {
            do_something_else(i); // 隐患: 很可能是悬空引用
        }
    }
};
void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func); 
    mythread.detach();//不等待新线程结束,那么很可能主线程调用oops结束后新线程还在执行
                      // 此时局部变量已被销毁还在被使用就会未定义行为
}

// 避免这种问题出现就是，线程函数完全自含，即在func的operator()函数中用自己的数据而不是共享数据

// 让主线程能够等待新线程结束可以调用join()函数,那么可以保证oops()函数退出前新线程会结束
// 一旦调用了join函数那么隶属于该线程的【任何存储空间】会立即清除，thrad对象不再关联已结束的(主)线程
// 事实上,此时thread对象与任何线程都均无关联,其意义是对于某个给定的线程join()只能调用1次
// 且join调用过就不可再汇合(joinable),joinable()成员函数将返回false


// 线程启动以后如果有异常抛出但是join函数还没执行就会被略过
// 为了保证无论是正常退出还是异常退出都能保证主线程退出之前新线程先退出可以使用try_catch
void do_something_in_current_thread();
void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch(...)
    {
        t.join(); //异常退出也要先加入
        throw;// 然后抛出异常
    }
    t.join();//正常退出
}

// 还可以设计一个类,使用RAII手法简化f()函数
class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_): t(t_){}
    ~thread_guard()
    {
        if (t.joinable())
            t.join();
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};
void f() // 简化的f
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t); // 析构函数管理t对象的joinable
    do_something_in_current_thread();
}

// 如果想在后台运行线程应当使用detach函数，此函数会切断线程华人std::thread对象之间的关联
// 假如线程被分离,就无法等待它完结,也不可能获得与它关联的std::thread对象,因而不能汇合该线程
// 此时分离的线程归属权和控制权都转交给C++运行时库(runtime library)保证一旦线程退出与之关联的资源都会被正确回收
