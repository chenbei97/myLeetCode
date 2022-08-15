/*
 * @Author: chenbei
 * @Date: 2022-08-15 10:05:46
 * @LastEditTime: 2022-08-15 13:35:38
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap03\\3.6.cpp
 * @Description: 防范死锁的准则
 * @Signature: A boy without dreams
 */
// （1）避免嵌套锁：假如已经持有一个锁，就不要试图获取第二个锁
// 每个线程至多持有一个锁，仅锁的本身不会导致死锁，如果有需要使用多个锁就应该使用std::lock()函数
// 借助单独的调用动作一次获取全部锁来避免死锁

// （2）一旦持有锁，就避免调用用户提供的程序接口：如果用户自定义的接口需要获取锁，就有可能发生死锁
// 不过使用用户的接口是难以避免的，所以需要第（3）条准则

// （3）如果获取多个锁是必要的，且无法通过std::lock()在一步操作中全部获取
// 就只能让每个线程内部按照固定顺序获取这些锁。例如，对于双向链表，至少3个节点需要获取锁，当前节点和前后的2个节点
// 遍历链表时，线程先持有当前节点的锁，然后尝试获取下一个节点的锁，一旦获取当前节点的锁也没有必要可以释放
// 这样允许多个线程一起访问链表，前提是它们不会同时访问一个节点，如果2个线程按照相反的方式遍历链表并采用交替前进的加锁方式
// 到某个节点B时，线程1已经锁定了节点A，然后尝试获取节点B的锁；与此同时，线程2已锁定了节点B，尝试获取节点A的锁，那么就会发生死锁
// 所以必须规定遍历的方向，例如禁止逆向遍历为代价防范可能的死锁

// （4）按层级加锁：锁的层级划分就是按特定方式规定加锁次序，若某线程已经对低层级互斥加锁就不允许再对高层级互斥加锁
#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>
#include <climits>
class hierarchical_mutex // 定义自己的互斥型别,C++没有直接提供对层级互斥锁的支持
{
private:
    std::mutex internal_mutex;
    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;
    // 使用thread_local修饰表示当前线程的层级编号,每个线程都有这个变量的副本(线程局部变量,故与另一线程的值无关),初始化为ulong可表示的最大值
    // 这样最开始时任意hierarchical_mutex互斥都可被加锁,因为初始时线程的等级高于任意hierarchical_mutex
    static thread_local unsigned long this_thread_hierarchy_value; 
    void check_for_hierarchy_violation() 
    {
        // 第一次锁住hierarchical_mutex的某个实例时这个值是ULONG_MAX,一定会通过检查
        if(this_thread_hierarchy_value <= hierarchy_value) // 如果这个线程的层级比当前互斥锁层级低是不能锁定当前的锁的
        {
            throw std::logic_error("mutex hierarchy violated");//违反互斥体层次结构
        }
        // 假设有个线程已经锁定了一个hierarchical_mutex1
        // 如果不是第一次被调用,this_thread_hierarchy_value的值反映了这个hierarchical_mutex1的等级
        // 现在线程尝试锁定第2个互斥hierarchical_mutex2(构造的时候层级已经传递给了hierarchy_value)
        // 那么比较的就是之前的互斥量和现在的互斥量的层级
    }
    void update_hierarchy_value()
    {
        previous_hierarchy_value=this_thread_hierarchy_value;// 之前互斥量的层级保留
        this_thread_hierarchy_value=hierarchy_value; // 现在的等级使用新互斥量的层级
    }
public:
    explicit hierarchical_mutex(unsigned level):
        hierarchy_value(level),previous_hierarchy_value(0){} // 构造时初始化互斥量等级和先前的互斥量等级为0
    void lock()
    {
        check_for_hierarchy_violation(); // 尝试加锁时检查加锁的互斥量和之前的互斥量等级
        internal_mutex.lock();// 通过就可以加锁
        update_hierarchy_value(); // 然后更新加锁后的新互斥量等级
    }
    void unlock() 
    {
        this_thread_hierarchy_value=previous_hierarchy_value; // 解锁就是回到之前的互斥量等级
        internal_mutex.unlock();
    }
    bool try_lock()
    {
        check_for_hierarchy_violation(); // 尝试加锁先检查等级
        if(!internal_mutex.try_lock()) // 通过以后调用内部的try_lock
            return false; // 没锁上就返回false,但是不阻塞
        update_hierarchy_value(); // 锁上了更新
        return true;
    }
};
thread_local unsigned long // 静态值初始化
    hierarchical_mutex::this_thread_hierarchy_value(ULONG_MAX); 

hierarchical_mutex hmtx(10000);
hierarchical_mutex lmtx(5000);
hierarchical_mutex omtx(6000); // 6000会有逻辑错误,16000不会有错误

int f1(){std::cout<<"f1 is called\n";return 1;} // 低层级函数
int low_level()
{
    std::cout<<"low_level is called\n";
    std::lock_guard<hierarchical_mutex> lock(lmtx); // 锁住低层级的锁
    return f1(); // 无嵌套+低层级函数f1调用,return 1
}

int f2(int param){std::cout<<"f2 is called\n";return 1+param;} // 高层级函数
int high_level()
{
    std::cout<<"high_level is called\n";
    std::lock_guard<hierarchical_mutex> lock(hmtx);// 锁住高层级的锁
    return f2(low_level()); // 嵌套低层级函数low_level+高层级函数f2调用,return 2
}
void mythreadA() // 调用高层级的线程函数
{
    std::cout<<"mythreadA is called\n";
    high_level(); // 高层级=>低层级 先对hmtx加锁然后对lmtx加锁,不会出错
}

void f3(){std::cout<<"f3 is called\n";} // 其他层级函数
void other_level()
{
    std::cout<<"other level is called\n";
    high_level(); // 嵌套高层级函数high_level+其他层级函数f3调用
    f3();
}
void mythreadB()// 调用其它层级的线程函数
{
    std::cout<<"mythreadB is called\n";
    std::lock_guard<hierarchical_mutex> lock(omtx);// 锁住其它层级的锁
    other_level(); // 其它层级=>高层级=>低层级,先对omtx加锁然后对hmtx和lmtx加锁违反了层级规则
}

int main()
{
    std::cout<<"t1 is construct\n";
    std::thread t1(mythreadA);
    std::cout<<"t2 is construct\n";
    std::thread t2(mythreadB);
    std::cout<<"t1 is join\n";
    t1.join();
    std::cout<<"t2 is join\n";
    // hierarchical_mutex omtx(6000); // 6000会有逻辑错误,16000不会有错误
    t2.join();
}

// （5）使用unique_lock<>灵活加锁，以前是先使用std::lock给2个互斥量一次性加锁,然后再使用lock_guard<>指定第2参数std::adopt_lock声明不必重复加锁
// 现在可以使用unique_lock指定第2参数为std::defer_lock,然后使用std::lock对2个锁上锁
// 区别在于unique_lock比lock_guard具有灵活性可以不占有关联的互斥,但是灵活性需要代价也就是比lock_guard慢
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
        /*
        std::lock(lhs.m,rhs.m); //可以使用std::lock函数同时锁住2个互斥量,如果有一个锁住另一个因为异常没锁柱,那么锁住的也会释放
        std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock); // adopt_lock告知lock_guard互斥量已上锁不必重复加锁
        std::lock_guard<std::mutex> lock_b(rhs.m,std::adopt_lock);
        swap(lhs.some_detail,rhs.some_detail); //交换
        */
        std::unique_lock<std::mutex> lock1(lhs.m,std::defer_lock); // 保留为无锁状态
        std::unique_lock<std::mutex> lock2(rhs.m,std::defer_lock);       
        std::lock(lock1,lock2); // 再一次性上锁
    }
};
/*n
cd C++HighConcurrency/chap03
g++ 3.6.cpp -o 3.6.exe
.\3.6
*/