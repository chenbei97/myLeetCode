/*** 
 * @Author: chenbei
 * @Date: 2022-05-20 16:06:25
 * @LastEditTime: 2022-05-20 17:40:49
 * @Description: runtime.cpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\03-runtime\runtime.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o runtime -std=c++20 runtime.cpp
.\runtime
*/
#include <iostream>
#include <vector>
#include "lambda.hpp"
#include "function.hpp"
#include "left_right_ref.hpp"
using namespace std;
int main()
{
    /*
        1. Lambda 表达式
            [捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {函数体}
            按值捕获:
                类似于值传递,但是值传递是调用时才进行拷贝,而按值捕获是在定义lambda表达式时就进行拷贝
            按引用捕获:
                类似于引用传递,但是内部可以影响外部的值
            隐式捕获:
                使用&,=让编译器自行捕获
            泛型捕获:
                使用auto,返回参数和参数列表都可以是auto
        2. 函数对象包装器
            std::function是一个函数容器,可以包装函数指针也可以包装lambda表达式,比直接使用它们更加安全
            需要头文件<functional>,同时std::bind和std::placeholder可以用于函数参数绑定与参数占位
        3. 左值引用和右值引用
            解决了C++中大量的历史遗留问题,消除了诸如 std::vector、std::string 之类的额外开销
            也使得函数对象容器 std::function 成为了可能
            左值:左值是表达式（不一定是赋值表达式）后依然存在的持久对象
            右值:指表达式结束后就不再存在的临时对象
                纯右值:纯粹的右值,要么是纯粹的字面量,例如10,true,nullptr,要么是右值表达式,例如10+20
                    非引用返回的临时变量、运算表达式产生的临时变量、 原始字面量、Lambda 表达式都属于纯右值
                    需要注意的是，字符串字面量只有在类中才是右值，当其位于普通函数中是左值
                    class Foo {
                        const char*&& right = "this is a rvalue"; // 此处字符串字面量为右值
                        public:
                                void bar() {
                                    right = "still rvalue"; // 此处字符串字面量为右值
                                } 
                    };
                    const char* const &left = "this is an lvalue"; // 此处字符串字面量为左值
                将亡值:是C++11为了引入右值引用而提出的概念,也就是即将被销毁、却能够被移动的值
            左值引用:
                    // int &a = std::move(1);    // 不合法，非常量左引用无法引用右值
                    const int &b = std::move(1); // 合法, 常量左引用允许引用右值
            右值引用:右值引用不能引用左值,但是可以用move函数转为右值被引用
                要拿到一个将亡值,就需要用到右值引用T &&，其中T是类型
                右值引用的声明让这个临时值的生命周期得以延长、只要变量还活着，那么将亡值将继续存活
                C++11 提供了std::move 这个方法将左值参数无条件的转换为右值,有了它我们就能够方便的获得一个右值临时对象
        4. 移动语义
            传统 C++ 通过拷贝构造函数和赋值操作符为类对象设计了拷贝/复制的概念，但为了实现对资源的移动操作
            调用者必须使用先复制、再析构的方式，否则就需要自己实现移动对象的接口
            搬家的时候是把家里的东西直接搬到新家去，而不是将所有东西复制一份（重买）再放到新家、 再把原来的东西全部扔掉（销毁），这是非常反人类的一件事情
            传统的 C++ 没有区分『移动』和『拷贝』的概念，造成了大量的数据拷贝，浪费时间和空间。 右值引用的出现恰好就解决了这两个概念的混淆问题
        5. 完美转发
            一个声明的右值引用其实是一个左值。这就为我们进行参数转发（传递）造成了问题
            void reference(int& v) {std::cout << "左值" << std::endl;}
            void reference(int&& v) {std::cout << "右值" << std::endl;}
            template <typename T>
            void pass(T&& v) {
                std::cout << "普通传参:";
                reference(v); // 始终调用 reference(int&)
            }
            int main(){
                std::cout << "传递右值:" << std::endl;
                pass(1); // 1是右值, 但输出是左值

                std::cout << "传递左值:" << std::endl;
                int l = 1;
                pass(l); // l 是左值, 输出左值
                return 0;
            }
    */
    test_lambda();
    test_function();
    test_left_right_ref();
    return 0;
}