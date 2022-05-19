/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 08:29:44
 * @LastEditTime: 2022-05-19 10:07:55
 * @Description: intro.cpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\01_introduction\intro.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o intro intro.cpp
.\intro
*/
#include <iostream>
#include <vector>
#include <memory> // contains unique_ptr<T>
#include <functional>
#include "c_c++_differ.h"
using namespace std;
void my_unexpected() noexcept; // 声明函数也要带上noexcept关键字
class Foo {
public:
    Foo() { cout << "Foo()" << endl; }
    virtual ~Foo() { cout << "~Foo()" << endl;}
    virtual void print() { cout << "Foo::print()" << endl; }
};
class subFoo : public Foo {
public:
    subFoo() { cout << "subFoo()" << endl; }
    ~subFoo() { cout << "~subFoo()" << endl; }
    void print() override { cout << "subFoo::print()" << endl; }
};
int main()
{
    /*
        一、说明被弃用的特性
            1. 不能使用char*来定义常量字符串,而应使用const char* 或auto
            2. unexpected_handler和set_unexpected()2个异常处理函数被弃用,新增noexcept版本
            3. 智能指针auto_ptr被弃用,新增unique_ptr,表示独占一份内存的指针
            4. register关键字被弃用,可以使用但不再具备任何实际含义
            5. bool类型的operator++被弃用
            6. 如果类有析构函数,为其生成的拷贝构造函数和拷贝赋值运算符的特性被弃用
            7. C语言风格的类型转换被弃用,即(type)运算,改用static_cast、dynamic_cast、const_cast、reinterpret_cast
            8. std::bind,std::function被弃用
            9. c++不应该是c的一个超集,如果是2种代码应分开编译
    */
    // 1. 不能使用char*来定义常量字符串,而应使用const char* 或auto
    const char* str = "hello"; // ok
    // char *str1 = "hello"; // warning
    char str2[] = "hello"; // ok
    cout <<str2<<endl;
    auto str3 = "hello"; // ok
    // 2. unexpected_handler和set_unexpected()2个异常处理函数被弃用,新增noexcept版本
    my_unexpected();
    // 3. 智能指针auto_ptr被弃用,新增unique_ptr,表示独占一份内存的指针
    // auto_ptr<int> p(new int(10)); // error
    unique_ptr<int> p(new int(10)); // ok
    // 4. register关键字被弃用,可以使用但不再具备任何实际含义
    // register int i = 10; // error,c++17进一步弃用,不允许使用
    // 5. bool类型的operator++被弃用
    bool b = true;
    // b++; // error
    // 6. 如果类有析构函数,为其生成的拷贝构造函数和拷贝赋值运算符的特性被弃用
    struct intro
    {
        int i;
        ~intro()
        {
            cout << "intro destructor" << endl;
        }
    } myintro;
    intro myintro1 = myintro; // ok
    // 7. C语言风格的类型转换被弃用,即(type)运算,改用static_cast、dynamic_cast、const_cast、reinterpret_cast
    // 7.1 使用static_cast,常用于静态转换,比如int->char,char->int,但是运行时不能检查转换的安全性
    unsigned char c = 'a';
    int c1 = (int)c; // 旧式C风格
    int c2 = static_cast<int>(c); // c++ 风格 ok
    // 7.2 使用dynamic_cast,常用于动态转换,比如父类指针指向子类对象
    // 如果是上行转换,例如指针指向子类对象,则返回子类对象的指针,如果是下行转换,例如指针指向父类对象,则返回父类对象的指针
    // 相比static_cast在下行转换时有类型检查的功能
    cout<<"pf---------------->\n";
    Foo *pf = new Foo(); // pf是个指向Foo对象的指针 Foo(),构造函数被调用
    pf->print(); // Foo::print()
    cout<<"ps---------------->\n";
    Foo *ps = new subFoo(); // ps是个指向subFoo对象的指针 先输出Foo(),再输出subFoo(),构造函数被调用
    ps->print(); // subFoo::print()
    // 如果一定要让ps调用父类的print函数,可以使用解引用强制转换
    cout<<"pf1---------------->\n";
    Foo pf1 = *ps; // pf1是个指向Foo对象的指针
    pf1.print(); // Foo::print()

    // 9. c++不应该是c的一个超集,如果是2种代码应分开编译
    [out = std::ref(std::cout << "Result from C code: " << add_byC(1, 2))](){
        out.get() << ".\n"; // Result from C code: 3.
    }();

    // 直接g++ -o intro intro.cpp .\intro 是行不通的
    // 应先使用 gcc 编译 C 语言的代码
    // gcc -c c_c++_differ.c -o c_differ ,编译出c_differ.o 文件
    // 再使用g++将C++代码和.o 文件链接起来或者都编译为.o再统一链接
    // g++ -o intro intro.cpp c_differ .\intro
    return 0; // ~Foo(),intro destructor,析构函数被调用
}
// 2.unexpected_handler和set_unexpected()2个异常处理函数被弃用,新增noexcept版本
// 定义一个保证不抛出异常的函数
void my_unexpected() noexcept
{
    cout << "my_unexpected() called" << endl;
}