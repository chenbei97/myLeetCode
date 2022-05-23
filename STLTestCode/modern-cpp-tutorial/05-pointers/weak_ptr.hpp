/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 09:13:07
 * @LastEditTime: 2022-05-23 09:31:59
 * @Description: weak_ptr.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\05-pointers\weak_ptr.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <memory>
using namespace std;
struct A;
struct B;
struct A {
    std::shared_ptr<B> pointer;
    ~A() {
        std::cout << "A is destroyed" << std::endl;
    }
};
struct B {
    std::shared_ptr<A> pointer;
    ~B() {
        std::cout << "B is destroyed" << std::endl;
    }
};
void shared_ptr_problem(){
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->pointer = b;
    b->pointer = a;
    //运行结果是 A, B 都不会被销毁
    // 这是因为 a,b 内部的 pointer 同时又引用了 a,b，这使得 a,b 的引用计数均变为了 2
    // 离开作用域时，a,b 智能指针被析构，却只能造成这块区域的引用计数减一
    // 这样就导致了 a,b 对象指向的内存区域引用计数不为零
    // 外部已经没有办法找到这块区域了，也就造成了内存泄露
    // 解决这个问题的办法就是使用弱引用指针 std::weak_ptr
    // std::weak_ptr是一种弱引用（相比较而言 std::shared_ptr 就是一种强引用）
    // 弱引用不会引起引用计数增加
}
void test_weak_ptr_api(){
    std::shared_ptr<A> a = std::make_shared<A>();
    std::weak_ptr<A> wp = a;
    std::cout << "a.use_count() = " << a.use_count() << std::endl; // 1
    std::cout << "wp.use_count() = " << wp.use_count() << std::endl; // 1

    cout<<"wp.expired() = "<<wp.expired()<<endl; // false
    auto p1 = wp.lock(); // 因为是锁住的状态,所以weak_ptr不能操作资源
    cout<<"wp.lock() = "<<p1<<endl; // 获取指向 A 对象的智能指针shared_ptr,0x12c49646920
    auto p2 = p1->pointer; // 获取p1的属性pointer指向了B对象
    cout<<"wp.lock()->pointer = "<<p2<<endl; // 0
}
void test_weak_ptr(){
    shared_ptr_problem();
    test_weak_ptr_api();
}