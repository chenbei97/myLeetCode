/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 09:01:52
 * @LastEditTime: 2022-05-23 09:12:05
 * @Description: unique_ptr.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\05-pointers\unique_ptr.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <memory>
// make_unique 并不复杂，C++11 没有提供 std::make_unique，可以自行实现
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args ) { // 右值引用
  return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) ); // forward用于完美转发
}

// 既然是独占，换句话说就是不可复制。但是，我们可以利用 std::move 将其转移给其他的 unique_ptr
struct Foo_unique {
    Foo_unique() { std::cout << "Foo_unique::Foo_unique" << std::endl; }
    ~Foo_unique() { std::cout << "Foo_unique::~Foo_unique" << std::endl; }
    void foo_unique() { std::cout << "Foo_unique::foo_unique" << std::endl; }
};
void f_unique(const Foo_unique &) {
    std::cout << "f_unique(const Foo&)" << std::endl;
}
void test_unique_ptr_move(){
    std::unique_ptr<Foo_unique> p1(std::make_unique<Foo_unique>());
    if (p1) p1->foo_unique();// p1 不空, 输出
    {
        std::unique_ptr<Foo_unique> p2(std::move(p1)); // 把p1移动给p2
        f_unique(*p2);// p2 不空, 输出
        if(p2) p2->foo_unique();// p2 不空, 输出
        if(p1) p1->foo_unique();// p1 为空, 无输出
        p1 = std::move(p2); // 再交回给p1
        if(p2) p2->foo_unique();// p2 为空, 无输出
        std::cout << "p2 is destroyed" << std::endl;
    }
    if (p1) p1->foo_unique();// p1 不空, 输出
    // Foo_unique 的实例会在离开作用域时被销毁
}
void test_unique_ptr(){
    auto pointer = std::make_unique<int>(11);
    std::cout<<"*pointer = "<<*pointer<<std::endl;

    test_unique_ptr_move();
}