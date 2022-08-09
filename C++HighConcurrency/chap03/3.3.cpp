/*
 * @Author: chenbei
 * @Date: 2022-08-09 10:13:42
 * @LastEditTime: 2022-08-09 13:52:10
 * @FilePath: \\myLeetCode\\C++HighConcurrency\\chap03\\3.3.cpp
 * @Description: 认识设计接口可能存在的固有条件竞争
 * @Signature: A boy without dreams
 */
#include <deque>
#include <stack>
#include <cstddef>
#include <iostream>
#include <thread>

template<typename T,typename Container=std::deque<T> >
class myStack
{
public:
    explicit myStack(const Container&);
    explicit myStack(Container&& = Container());
    template <class Alloc> explicit myStack(const Alloc&);
    template <class Alloc> myStack(const Container&, const Alloc&);
    template <class Alloc> myStack(Container&&, const Alloc&);
    template <class Alloc> myStack(myStack&&, const Alloc&);

    bool empty() const; //empty和size的结果在多线程中是不可信的
    size_t size() const;
    T& top(); // 返回栈顶元素的引用
    T const& top() const;
    void push(T const&);
    void push(T&&);
    void pop();
    void swap(myStack&&);
};

void do_something(int val){std::cout<<"val is "<<val<<"\n";}
void fc(std::stack<int> & s)
{
    if (!s.empty()) // ①
    {
        const int val = s.top(); // ②
        s.pop(); //③
        do_something(val);
    }
    else{
        std::cout<<"the stack is empty!\n";
    }
}
int main()
{
    std::stack<int> s;
    s.push(1);s.push(2);
    std::thread t1(fc,std::ref(s));
    std::thread t2(fc,std::ref(s));
    std::thread t3(fc,std::ref(s));
    try 
    {
        std::cout<<std::boolalpha<<s.empty()<<"\n";
    }
    catch(...)
    {
        t1.join();
        t2.join();
        t3.join();
        throw;
    }
    t2.join(); // 特意的调换,先加入t2后t3再t1,每次运行的结果会有不同
    t3.join();
    t1.join();
    std::cout<<std::boolalpha<<s.empty()<<"\n";
}

// 在①和②之间可能有另一个线程调用pop(),那么上述代码不再安全,这是典型的条件竞争
// 其根本原因在于函数接口,即使在内部使用互斥保护栈容器中的元素也无法防范
// 只能改变接口来解决这种问题,一种方法是将top函数可以改写为一旦空栈调用就抛出异常
// 不过这种方法比较暴力,因为即使非空的栈调用top时也可能发生异常,也就是引入了新的麻烦必须考虑
// 另外明知道栈是空的,调用top后就会抛出异常,这就是额外开销,故引入异常处理不是好的方法

// 除了①和②之间的条件竞争，②和③的条件竞争隐藏的更深
// 假设栈数据一开始有2个数据,2个线程运行相同的代码(这是可能的,因为多线程提升性能的一种方式就是切分工作调用相同的代码)
// 那么2个线程可能执行的一种顺序是这样的
/*
    线程1                           线程2
    if (!s.empty())      
                                if (!s.empty())
    const int val = s.top();
                                const int val = s.top();
    s.pop();
    do_something(val);          s.pop();
                                do_something(val);
*/
// 这样导致的结果就是可能2个线程读取到的数据都是第1个数据,第2个数据并没有被读取所以被丢弃
// 不过诱发错误的原因不明显,造成什么后果还取决于do_something(int)的操作
// 这里我相对书上的代码特别的添加了1个线程以使结果更明显,一共3个线程,且join的顺序不按照初始化线程的顺序
// 会发现每次运行结果都是不同的

// 解决这个问题的一种方式是将top和pop合并，也就是pop返回栈顶元素的同时将栈顶元素删除
// 这就可能造成隐患,可能pop返回的数据因为某种原因并未被外界复制成功,但是栈顶元素却已被删除,就会导致数据丢失
// 考虑vector<statck<int>>,vector会动态调整大小,复制vector容器时可能因为内存不够引发bad_alloc异常
// 那么复制数据的时候就会出现问题,所以stack的设计者一开始将top和pop一分为二的操作是正确的,即使不能安全的复制数据也不会导致数据的丢失
// 一方面试图避免分割操作才能消除条件竞争,一方面避免分割操作又会造成一系列别的安全问题

// 所以为了能够解决这类问题，还有一些新的方法可以消除条件竞争，但是都不完美
// 这些方法在3.4.cpp中介绍
/*
cd C++HighConcurrency/chap03
g++ 3.3.cpp -o 3.3.exe
.\3.3
*/