/*
g++ -o ..\output\weak_ptr_g++ weak_ptr.cpp
..\output\weak_ptr_g++.exe
cl /Fo"..\output\weak_ptr_cl" /Fe"..\output\weak_ptr_cl.exe" /std:c++latest ".\weak_ptr.cpp"
..\output\weak_ptr_cl.exe
*/
#include <iostream>
#include <memory>
using namespace std;
struct A;
struct B;
struct A {
    std::shared_ptr<B> pointer;
    ~A() {std::cout << "A is destroyed" << std::endl;}
};
struct B {
    std::shared_ptr<A> pointer;
    ~B() {std::cout << "B is destroyed" << std::endl;}
};
struct A_weak;
struct B_weak;
struct A_weak {
    std::weak_ptr<B_weak> pointer;
    ~A_weak() {std::cout << "A_weak is destroyed" << std::endl;}
};
struct B_weak {
    std::weak_ptr<A_weak> pointer;
    ~B_weak() {std::cout << "B_weak is destroyed" << std::endl;}
};
int main()
{
    // 仔细思考 std::shared_ptr 就会发现依然存在着资源无法释放的问题,参考下方例子
    // 结构体A、B内部都有一个智能指针,互相指向对方
    // 创建2个指针a,b,分别指向结构体A、B
    auto a = std::make_shared<A>(); // auto = std::shared_ptr<A>
    auto b = std::make_shared<B>();
    a->pointer = b; // a->pointer指向a
    b->pointer = a; // b指向a
    cout<<"a.use_count() = "<<a.use_count()<<endl; // 2
    cout<<"b.use_count() = "<<b.use_count()<<endl; // 2

    // 可以使用weak_ptr来解决这个问题
    auto a_weak = std::weak_ptr<A_weak>();
    auto b_weak = std::weak_ptr<B_weak>();
    // a_weak->pointer = b_weak; // 没有指针类型,只能借助lock
    a_weak.lock()->pointer = b_weak; // a_weak指向b_weak
    b_weak.lock()->pointer = a_weak; // b_weak指向a_weak
    cout<<"a_weak.use_count() = "<<a_weak.use_count()<<endl; // 0
    cout<<"b_weak.use_count() = "<<b_weak.use_count()<<endl; // 0
    /*
        运行结果是 A, B 都不会被销毁，这是因为 a,b 内部的 pointer 同时又引用了 a,b，这使得 a,b 的引
        用计数均变为了 2，而离开作用域时，a,b 智能指针被析构，只能造成这块区域的引用计数减1，这样
        就导致 a,b 对象指向的内存区域引用计数不为零，而外部已经无法找到这块区域，造成内存泄露
        
        解决这个问题的办法就是使用弱引用指针 std::weak_ptr，std::weak_ptr 是一种弱引用（相比较
        而言 std::shared_ptr 就是一种强引用）。弱引用不会引起引用计数增加

        std::weak_ptr 没有 * 运算符和 -> 运算符，所以不能够对资源进行操作，它可以用于检查
        std::shared_ptr 是否存在，其 expired() 方法能在资源未被释放时，会返回 false，否则返回 true；
        除此之外，它也可以用于获取指向原始对象的 std::shared_ptr 指针，其 lock() 方法在原始对象未
        被释放时，返回一个指向原始对象的 std::shared_ptr 指针，进而访问原始对象的资源，否则返回nullptr
    */
    return 0;
}

