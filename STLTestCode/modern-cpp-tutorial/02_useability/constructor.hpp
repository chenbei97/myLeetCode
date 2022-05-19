/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 14:40:17
 * @LastEditTime: 2022-05-19 15:02:53
 * @Description: constructor.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\constructor.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
using namespace std;
// 委托构造的概念，这使得构造函数可以在同一个类中一个构造函数调用另一个构造函数，从而达到简化代码的目的
class Base {
public:
    int value1;
    int value2;
    Base() {
        value1 = 1;
    }
    Base(int value) : Base() { // 委托 Base() 构造函数
        value2 = value;
    }
    void print(){
        cout<<"value1 = "<<value1<<" value2 = "<<value2<<endl;
    }
};

// 在传统 C++ 中，构造函数如果需要继承是需要将参数一一传递的，这将导致效率低下
// C++11 利用关键字 using 引入了继承构造函数的概念
class Subclass : public Base {
public:
    using Base::Base; // 继承构造
    int value3 = 2;
    void print(){
        cout<<"value1 = "<<value1<<" value2 = "<<value2<<" value3 = "<<value3<<endl;
    }
};

// 在传统 C++ 中，经常容易发生意外重载虚函数的事情
// 可能并不是程序员尝试重载虚函数，只是恰好加入了一个具有相同名字的函数
// 另一个可能的情形是,当基类的虚函数被删除后,子类拥有旧的函数就不再重载该虚拟函数并摇身一变成为了一个普通的类方法
// C++11 引入了 override 和 final 这两个关键字来防止上述情形的发生
struct Base_s {
    virtual void foo(int);
};
struct SubClass_s final: Base_s { // 类被限定不能被继承
    void foo(float,float){ // 本意不是想重载虚函数,只是恰好同名foo
        cout<<"float"<<endl;
    }
    virtual void foo(int) override final{// 合法,限定函数不能再被重载
        cout<<"SubClass_s::foo(int)"<<endl;
    } 
    // virtual void foo(float) override; // 非法, 父类没有此虚函数
};

// 引入显式禁用默认函数
class Magic_c {
    public:
    Magic_c() = default; // 显式声明使用编译器生成的构造
    Magic_c& operator=(const Magic_c&) = delete; // 显式声明拒绝编译器生成构造
    Magic_c(int magic_number);
};
void test_constructor(){
    Base b1(10);
    b1.print();
    Subclass s1(10);
    s1.print();

    SubClass_s s2;
    s2.foo(10); // SubClass_s::foo(int)
    s2.foo(10.0,11.0); // float
}