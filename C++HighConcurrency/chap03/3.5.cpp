/*
 * @Author: chenbei
 * @Date: 2022-08-09 13:27:51
 * @LastEditTime: 2022-08-15 10:04:32
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap03\\3.5.cpp
 * @Description: 使用std::lock和std::scoped_lock<>避免死锁
 * @Signature: A boy without dreams
 */
#include <mutex>

// 避免死锁的建议通常是始终按照相同顺序对两个互斥加锁
// 但是有时候这样无法避免死锁,例如需要多个互斥量保护多个独立的实例时,且实例属于一个类
// 假设有一个函数操作了类的2个实例,例如swap用于交换2个实例内部的数据
// 此时按照顺序依次加锁,但是调用的参数顺序相反,例如线程1调用swap(A,B),线程2调用swap(B,A)
// 那么A想要交换需要等待B加锁,B想要交换也在等待A加锁,就会出现死锁问题

class some_big_object{};

void swap(some_big_object& lhs,some_big_object& rhs){};

class X
{
private:
    some_big_object some_detail; // 数据
    mutable std::mutex m;
public:
    X(some_big_object const& sd):some_detail(sd){} // 使用传入的sd初始化私有属性some_detail

    friend void swap(X& lhs, X& rhs)
    {
        if(&lhs==&rhs)
            return;
        std::lock(lhs.m,rhs.m); //可以使用std::lock函数同时锁住2个互斥量,如果有一个锁住另一个因为异常没锁柱,那么锁住的也会释放
        std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock); // adopt_lock告知lock_guard互斥量已上锁不必重复加锁
        std::lock_guard<std::mutex> lock_b(rhs.m,std::adopt_lock);
        swap(lhs.some_detail,rhs.some_detail); //交换
    }
};

// 解决此问题的方法是使用std::lock同时锁住多个互斥量
// 或者使用c++17引入的新特性std::scoped_lock<>,对于简单模板参数也可以省略<>指定类型
// 上述的swap代码可以改写如下
/*
void swap(X& lhs, X& rhs)
    {
        if(&lhs==&rhs)
            return;
        std::scoped_lock guard(lhs.m,rhs.m); // 同时锁住2个m
        // 等价于std::scoped_lock<std::mutex,std::mutex> guard(lhs.m,rhs.m);
        swap(lhs.some_detail,rhs.some_detail); //交换
    }
*/

// 锁操作可能是导致死锁的原因，但是也可以不涉及锁操作就导致死锁
// 例如2个线程各自关联了thread实例,若它们同时再对方的thread 实例调用join函数就能制造死锁又不涉及锁操作
// 总结下来就是只要有一个线程在等待另一个线程，那么这个线程就不能反过来等待这个线程
// 3.6.cpp给出了具体的细分条目来判断其它线程是否正在等待当前线程