/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 10:04:50
 * @LastEditTime: 2022-05-23 10:30:30
 * @Description: mutex.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\07-thread\mutex.hpp
 * @Signature: A boy without dreams
 */
#include <thread>
#include <mutex>
#include <iostream>
using namespace std;
// RAII 用法下，对于临界区的互斥量的创建只需要在作用域的开始部分
int v = 1;
void critical_section(int change_v) {
    static std::mutex mtx; // 临界区的互斥量
    std::lock_guard<std::mutex> lock(mtx); // 临界区的互斥量的锁

    // 执行竞争操作
    v = change_v;
    // 离开此作用域后 mtx 会被释放
}
void test_critical_section(){
    // 创建2个线程,以函数和参数的形式传递给线程
    std::thread t1(critical_section, 2), t2(critical_section, 3);
    t1.join();
    t2.join();
    // 输出结果
    std::cout << v << std::endl; // 3
    // 保证了所有栈对象在生命周期结束时会被销毁，所以这样的代码也是异常安全的
    // 无论 critical_section() 正常返回、还是在中途抛出异常，都会引发堆栈回退
    // 也就自动调用了 unlock()
}

// std::unique_lock 则相对于 std::lock_guard 出现的，std::unique_lock 更加灵活
// std::unique_lock 的对象会以独占所有权的方式管理 mutex 对象上的上锁和解锁的操作
// std::lock_guard 不能显式的调用 lock 和 unlock， 而 std::unique_lock 可以在声明后的任意位置调用
// 可以缩小锁的作用范围，提供更高的并发度
// 如果用到了条件变量 std::condition_variable::wait 则必须使用 std::unique_lock 作为参数
// 所以在并发编程中，推荐使用 std::unique_lock
void _critical_section_(int change_v) {
    static std::mutex _mtx_;
    std::unique_lock<std::mutex> lock(_mtx_);
    // 执行竞争操作
    v = change_v;
    std::cout << v << std::endl; // 3
    // 将锁进行释放
    lock.unlock();

    // 在此期间，任何人都可以抢夺 v 的持有权

    // 开始另一组竞争操作，再次加锁
    lock.lock();
    v += 1;
    std::cout << v << std::endl; // 4
}
void test_critical_section_(){
    std::thread t1(_critical_section_, 2), t2(_critical_section_, 3);
    t1.join(); 
    cout<<"1.<----------------------------->.1"<<endl;
    t2.join(); 
}
void test_mutex(){
    test_critical_section(); 
    cout<<"<---------------------------->"<<endl;
    test_critical_section_(); 
}