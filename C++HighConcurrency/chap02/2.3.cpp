/*
 * @Author: chenbei
 * @Date: 2022-08-08 10:31:20
 * @LastEditTime: 2022-08-08 11:10:28
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap02\\2.3.cpp
 * @Description: 移交线程归属权
 * @Signature: A boy without dreams
 */
#include <thread>
#include <vector>

void f1();
void f2();
std::thread t1(f1);
std::thread t2 = std::move(t1); // t1=>nullptr，t2=>f1
t1 = std::thread(f2); // 无需显式使用move函数,会自动发生t1=>f2，t2=>f1
std::thread t3;
t3 = std::move(t2); // t1=>f2，t2=>nullptr, t3=>f1

t1 = std::move(t3); //会直接终止整个程序,如果一个thread对象正在管控1个线程不能简单的向它赋予新值

// std::thread支持移动操作的意义是函数可以便捷的向外部转移线程的归属权
// 从函数内部返回std::thread对象
std::thread f()
{
    void some_function();
    return std::thread(some_function);//返回局部构造的线程对象
}
// std::thread对象转移给函数
void f(std::thread t);
void g()
{
    void some_function();
    f(std::thread(some_function)); // 传入匿名对象

    std::thread t(some_function);
    f(std::move(t)); // 传入具名对象使用move
}

// 移动语义的好处在于使用RAII手法时可以对2.1cpp中的thread_guard类稍作修改就可以构建线程并交给该类掌管
// 一旦线程归属权交给了thread_gurad类其他对象就不能进行汇合和分离操作
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
// 修改
class scoped_thread
{
    std::thread t; //无需使用&
public:
    explicit scoped_thread(std::thread t_):t(std::move(t_)) // 使用move
    {
        if (!t.joinable())
        {
            throw std::logic_error("No Thread");
        }
    }
    ~scoped_thread(){t.join();}
    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};
struct func{int val;};
void do_something_in_current_thread();
void ff()
{
    int some_local_state;
    scoped_thread t{std::thread(func(some_local_state))};//把func(int)函数对象的匿名变量直接传递
    do_something_in_current_thread();
}


// 线程可以集中分配给容器存放,例如对某个算法切分任务时常常使用
void do_work(unsigned int id);
void f()
{
    std::vector<std::thread> threads;
    for(unsigned int i = 0; i< 20; ++i)
        threads.emplace_back(do_work,i);
    for(auto &entry: threads)
        entry.join();//不过必须等待所有线程都结束以后才能查看共享数据,第4章会讨论线程之间传递参数的方法
}