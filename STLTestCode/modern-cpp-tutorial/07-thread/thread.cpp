/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 09:55:07
 * @LastEditTime: 2022-05-23 10:48:35
 * @Description: thread.cpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\07-thread\thread.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o thread -std=c++20 thread.cpp
.\thread
*/
#include <iostream>
#include <thread>
#include <mutex>
#include "mutex.hpp"
#include "future.hpp"
#include "condition_variable.hpp"
using namespace std;
// 构建1个输出hello world的函数类对象
class print_hello{
public:
    void operator()(){
        cout << "hello world" << endl;
    }
};
// 使用using 指明一个输入int型返回void的函数指针
using func_ptr = void(*)(int);
void print_num(int num){
    cout << num << endl;
}
int main()
{
    /*
        std::thread 用于创建一个执行的线程实例，所以它是一切并发编程的基础，使用时需要包含 <thread> 头文件
        get_id() 来获取所创建线程的线程 ID，使用 join() 来加入一个线程等等
        thread的构造函数可以接受一个函数指针，也可以接受一个 lambda 函数,但是不接受一个函数对象

        互斥量与临界区：
        C++11 引入了 mutex 相关的类，其所有相关的函数都放在 <mutex> 头文件中
        通过实例化 std::mutex 可以创建互斥量， 而通过其成员函数 lock() 可以进行上锁，unlock() 可以进行解锁
        但是在实际编写代码的过程中，最好不去直接调用成员函数， 因为调用成员函数就需要在每个临界区的出口处调用 unlock()
        C++11 还为互斥量提供了一个 RAII 语法的模板类 std::lock_guard。 RAII 在不失代码简洁性的同时，很好的保证了代码的异常安全性。
        RAII 用法下，对于临界区的互斥量的创建只需要在作用域的开始部分
        std::unique_lock 则相对于 std::lock_guard 出现的，std::unique_lock 更加灵活
        std::unique_lock 的对象会以独占所有权的方式管理 mutex 对象上的上锁和解锁的操作
        std::lock_guard 不能显式的调用 lock 和 unlock， 而 std::unique_lock 可以在声明后的任意位置调用
        可以缩小锁的作用范围，提供更高的并发度
        如果用到了条件变量 std::condition_variable::wait 则必须使用 std::unique_lock 作为参数
        所以在并发编程中，推荐使用 std::unique_lock

        期物（Future）表现为 std::future，它提供了一个访问异步操作结果的途径
        主线程 A 希望新开辟一个线程 B 去执行某个我们预期的任务，并返回我一个结果
        线程 A 可能正在忙其他的事情，无暇顾及 B 的结果
        所以我们会很自然的希望能够在某个特定的时间获得线程 B 的结果
        在封装好要调用的目标后，可以使用 get_future() 来获得一个 std::future 对象，以便之后实施线程同步

        条件变量 std::condition_variable 是为了解决死锁而生，当互斥操作不够用而引入的
        比如，线程可能需要等待某个条件为真才能继续执行
        而一个忙等待循环中可能会导致所有其他线程都无法进入临界区使得条件为真时，就会发生死锁
        所以，condition_variable 实例被创建出现主要就是用于唤醒等待线程从而避免死锁
        std::condition_variable的 notify_one() 用于唤醒一个线程
        notify_all() 则是通知所有线程
        生产者中我们虽然可以使用 notify_one()，但实际上并不建议在此处使用
        因为在多消费者的情况下，我们的消费者实现中简单放弃了锁的持有
        这使得可能让其他消费者争夺此锁，从而更好的利用多个消费者之间的并发

        原子操作与内存模型
        原子操作:
            提供线程间自动的状态转换，即『锁住』这个状态
            保障在互斥锁操作期间，所操作变量的内存与临界区外进行隔离
        一致性模型:
            并行执行的多个线程，从某种宏观层面上讨论，可以粗略的视为一种分布式系统
            在分布式系统中，任何通信乃至本地操作都需要消耗一定时间，甚至出现不可靠的通信
            一致性包括线性一致性、顺序一致性、因果一致性和最终一致性
        内存顺序：C++11 为原子操作定义了六种不同的内存顺序 std::memory_order 的选项，表达了四种多线程间的同步模型
            宽松模型、释放/消费模型、释放/获取模型和顺序一致性模型
    */      
    // 1. 以lambda表达式的形式创建线程
    std::thread t1([]() {
        std::cout << "Hello from thread 1" << std::endl;
    });
    // 2. 不能以函数对象的形式创建线程
    // std::thread t2(print_hello());
    // 3. 以函数指针的形式创建线程
    std::thread t3(print_num, 10);
    // 加入线程使用join
    t1.join();
    // t2.join(); 非法, 因为t2是一个函数对象，不能加入线程
    t3.join();
    // 获取线程ID
    std::cout << "thread t1's id : " << t1.get_id() << std::endl;
    // std::cout << "thread t2's id : " << t2.get_id() << std::endl; 非法，因为t2是一个函数对象，不能获取线程ID
    std::cout << "thread t3's id: " << t3.get_id() << std::endl;
    
    // 测试互斥量
    test_mutex();

    // 测试期物
    test_future();

    // 测试条件变量
    test_condition_variable();
    return 0;
}