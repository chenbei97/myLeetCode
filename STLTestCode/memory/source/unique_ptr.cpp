/*
g++ -o ..\output\unique_ptr_g++ unique_ptr.cpp
..\output\unique_ptr_g++.exe
cl /Fo"..\output\unique_ptr_cl" /Fe"..\output\unique_ptr_cl.exe" /std:c++latest ".\unique_ptr.cpp"
..\output\unique_ptr_cl.exe
*/
#include <iostream>
#include <memory>
#include <iterator>
using namespace std;
namespace make_unique_test {
    template<typename T, typename ...Args>
    std::unique_ptr<T> make_unique( Args&& ...args ) {
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
    }
}
struct Foo {
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};
void f(const Foo &) {
    std::cout << "f(const Foo&)" << std::endl;
}
int main()
{
    /*
        std::unique_ptr 是一种独占的智能指针，它禁止其他智能指针与其共享同一个对象，从而保证代码的安全

        make_unique 并不复杂，C++11 没有提供 std::make_unique，可以自行实现
        template<typename T, typename ...Args>
        std::unique_ptr<T> make_unique( Args&& ...args ) {
            return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
        
        既然是独占，换句话说就是不可复制。但是，我们可以利用 std::move 将其转移给其他的unique_ptr
    }
    */
    std::unique_ptr<int> pointer = std::make_unique<int>(10); // make_unique 从 C++14 引入
    cout<<"*pointer = "<<*pointer<<endl; // 10
    cout <<"pointer.get() = "<<pointer.get()<<endl; // 0x20d4f4b6250
    // auto pointer1 = pointer; // 非法，不能将一个 unique_ptr 赋值给另一个 unique_ptr
    // 可以使用move转移
    std::unique_ptr<int> pointer1 = std::move(pointer); // ok
    cout<<"*pointer1 = "<<*pointer1<<endl; // 10
    cout<<"1.-----------------------------------------------------"<<endl;
    std::unique_ptr<Foo> p1(std::make_unique<Foo>()); // 调用构造输出:Foo::Foo
    cout<<"2.-----------------------------------------------------"<<endl;
    if (p1) p1->foo(); //  p1不空,调用foo函数成功输出 Foo::foo
    std::unique_ptr<Foo> p2(std::move(p1)); // 把p1转移给p2
    cout<<"3.-----------------------------------------------------"<<endl;
    f(*p2); // p2不空,可以被f函数调用输出:f(const Foo&)
    cout<<"4.-----------------------------------------------------"<<endl;
    if(p2) p2->foo(); // p2不空可以调用foo函数, 输出:Foo::foo
    if(p1) p1->foo(); // p1此时已为空, 无输出
    p1 = std::move(p2); // 再移动回来
    if(p2) p2->foo(); // p2为空,无输出
    std::cout << "p2 is destroyed" << std::endl;
    if (p1) p1->foo(); // p1不空可调用foo函数, 输出:Foo::foo
    //Foo 的实例会在离开作用域时被销毁,输出:Foo::~Foo
    return 0;
}