/*** 
 * @Author: chenbei
 * @Date: 2022-05-20 17:07:51
 * @LastEditTime: 2022-05-20 17:43:52
 * @Description: left_right_ref.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\03-runtime\left_right_ref.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include<functional> // std::function
#include <memory>  // std::make_unique
#include <utility> // std::move
#include <vector>
#include <string> // std::string
using namespace std;
// 左值:左值是表达式（不一定是赋值表达式）后依然存在的持久对象
// 右值:指表达式结束后就不再存在的临时对象
//     纯右值:纯粹的右值,要么是纯粹的字面量,例如10,true,nullptr,要么是右值表达式,例如10+20
//         非引用返回的临时变量、运算表达式产生的临时变量、 原始字面量、Lambda 表达式都属于纯右值
//         需要注意的是，字符串字面量只有在类中才是右值，当其位于普通函数中是左值
//     将亡值:是C++11为了引入右值引用而提出的概念,也就是即将被销毁、却能够被移动的值
class FooLRV {
    const char*&& right = "this is a rvalue"; // 此处字符串字面量为右值
    public:
            void bar() {
                right = "still rvalue"; // 此处字符串字面量为右值
            } 
};
std::vector<int> foo_lrv() {
    std::vector<int> temp = {1, 2, 3, 4};
    return temp; // 会被拷贝返回,返回的纯右值
}
void compare_right(){
    const char* const &left_lrv = "this is an lvalue"; // 此处字符串字面量为左值
    std::vector<int> v = foo_lrv(); // v是左值,复制了这个临时的纯右值后,纯右值就会被销毁无法获取也不能修改
    // c++11之后编译器为我们做了一些工作,此处的左值temp会被进行此隐式右值转换,等价于static_cast<std::vector<int> &&>(temp)
    // v 会将 foo局部返回的值进行移动,也就是后面我们将会提到的移动语义,这样无需先创建副本再拷贝再销毁副本,提高效率
}

// 要拿到一个将亡值,就需要用到右值引用T &&，其中T是类型
// 右值引用的声明让这个临时值的生命周期得以延长、只要变量还活着，那么将亡值将继续存活
// C++11 提供了 std::move 这个方法将左值参数无条件的转换为右值,有了它我们就能够方便的获得一个右值临时对象
void reference(std::string& str) {
    std::cout << "left value" << std::endl;
}
void reference(std::string&& str) {
    std::cout << "right value" << std::endl;
}
void test_reference() {
    std::string lv1 = "string,"; // lv1 是一个左值
    // std::string&& r1 = lv1; // 非法,右值引用不能引用左值
    std::string&& rv1 = std::move(lv1); // 合法, std::move可以将左值转移为右值
    std::cout << rv1 << std::endl; // string,

    const std::string& lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test"; // 非法, 常量引用无法被修改
    std::cout << lv2 << std::endl; // string,string,

    std::string&& rv2 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期
    rv2 += "Test"; // 合法, 非常量引用能够修改临时变量
    std::cout << rv2 << std::endl; // string,string,string,Test

    // rv2 虽然引用了一个右值，但由于它是一个引用，所以 rv2 依然是一个左值
    reference(rv2); // 输出左值，left value

    // int &a = std::move(1);    // 不合法，非常量左引用无法引用右值
    const int &b = std::move(1); // 合法, 常量左引用允许引用右值
    cout <<"b = "<< b << endl; // 1
}

// 移动语义
// 传统 C++ 通过拷贝构造函数和赋值操作符为类对象设计了拷贝/复制的概念，但为了实现对资源的移动操作
// 调用者必须使用先复制、再析构的方式，否则就需要自己实现移动对象的接口
// 搬家的时候是把家里的东西直接搬到新家去，而不是将所有东西复制一份（重买）再放到新家、 再把原来的东西全部扔掉（销毁），这是非常反人类的一件事情
// 传统的 C++ 没有区分『移动』和『拷贝』的概念，造成了大量的数据拷贝，浪费时间和空间。 右值引用的出现恰好就解决了这两个概念的混淆问题
class A {
public:
    int *pointer;
    A():pointer(new int(1)) { 
        std::cout << "constructor" << pointer << std::endl; 
    }
    A(A& a):pointer(new int(*a.pointer)) { 
        std::cout << "copy" << pointer << std::endl; 
    } // 无意义的对象拷贝
    A(A&& a):pointer(a.pointer) { 
        a.pointer = nullptr;
        std::cout << "move" << pointer << std::endl; 
    }
    ~A(){ 
        std::cout << "destroy" << pointer << std::endl; 
        delete pointer; 
    }
};
// 防止编译器优化
A return_rvalue(bool test) {
    A a,b;
    if(test) return a; // 等价于 static_cast<A&&>(a);
    else return b;     // 等价于 static_cast<A&&>(b);
}
void test_move(){
    A obj = return_rvalue(false); // 首先会在 return_rvalue 内部构造两个 A 对象，于是获得两个构造函数的输出
    std::cout << "obj:" << std::endl;
    // 函数返回后，产生一个将亡值，被 A 的移动构造（A(A&&)）引用，从而延长生命周期
    // 并将这个右值中的指针拿到，保存到了 obj 中，而将亡值的指针被设置为 nullptr，防止了这块内存区域被销毁
    // 从而避免了无意义的拷贝构造，加强了性能
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;

    // STL标准库的例子
    std::string str = "Hello world.";
    std::vector<std::string> v;
    // 将使用 push_back(const T&), 即产生拷贝行为
    v.push_back(str);
    // 将输出 "str: Hello world."
    std::cout << "str: " << str << std::endl; // Hello world.
    // 将使用 push_back(const T&&), 不会出现拷贝行为
    // 而整个字符串会被移动到 vector 中，所以有时候 std::move 会用来减少拷贝出现的开销
    // 这步操作后, str 中的值会变为空
    v.push_back(std::move(str));
    // 将输出 "str: "
    std::cout << "str: " << str << std::endl; // 啥也没有
}

// 完美转发
// 一个声明的右值引用其实是一个左值。这就为我们进行参数转发（传递）造成了问题
/*
    pass(l)而言，l是一个左值，为什么会成功传递给 pass(T&&)?
    这是基于引用坍缩规则的：在传统 C++ 中，我们不能够对一个引用类型继续进行引用
    但 C++ 由于右值引用的出现而放宽了这一做法，从而产生了引用坍缩规则
    允许我们对引用进行引用， 既能左引用，又能右引用。但是却遵循如下规则
    函数形参类型	实参参数类型	推导后函数形参类型
        T&	        左引用	            T&
        T&	        右引用	            T&
        T&&	        左引用	            T&
        T&&	        右引用	            T&&
    因此，模板函数中使用 T&& 不一定能进行右值引用，当传入左值时，此函数的引用将被推导为左值
    更准确的讲，无论模板参数是什么类型的引用，当且仅当实参类型为右引用时，模板参数才能被推导为右引用类型
    这才使得 v 作为左值的成功传递
    完美转发就是基于上述规律产生的
    所谓完美转发，就是为了让我们在传递参数的时候，保持原来的参数类型（左引用保持左引用，右引用保持右引用）
    为了解决这个问题，我们应该使用 std::forward 来进行参数的转发（传递）
*/
void reference(int& v) {std::cout << "left value" << std::endl;}
void reference(int&& v) {std::cout << "right value" << std::endl;}
template <typename T>
void pass(T&& v) {
    std::cout << "normal pass_value:";
    reference(v); // 始终调用 reference(int&)
}
void test_pass(){
       // 不能使用完美转发,右值会当作左值传递
        std::cout << "pass right vaue:" << std::endl;
        pass(1); // 1是右值, 但输出是左值
        std::cout << "pass left value:" << std::endl;
        int l = 1;
        pass(l); // l 是左值, 输出左值
        /*
            output:
                pass right vaue:
                normal pass_value:left value
                pass left value:
                normal pass_value:left value
        */
}
// 使用std::forward传参
template <typename T>
void pass_forward(T&& v) {
    std::cout << "normal pass value: ";
    reference(v);
    std::cout << "move pass value: ";
    reference(std::move(v));
    std::cout << "forward pass value: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> pass value: ";
    reference(static_cast<T&&>(v));
}
void test_pass_forward(){
    std::cout << "pass right value:" << std::endl;
    pass_forward(1);
    std::cout << "pass left value:" << std::endl;
    int v = 1;
    pass_forward(v);
    /*
        现在可以实现完美转发
        output:
            pass right value: 只要不是普通传递,3个都是右值
            normal pass value: left value
            move pass value: right value
            forward pass value: right value
            static_cast<T&&> pass value: right value

            pass left value: // 传递左值除了move以外都是左值
            normal pass value: left value
            move pass value: right value
            forward pass value: left value
            static_cast<T&&> pass value: left value
    */
}
// 无论传递参数为左值还是右值，普通传参都会将参数作为左值进行转发
// 所以 std::move 总会接受到一个左值，从而转发调用了reference(int&&) 输出右值引用
// 只有std::forward 即没有造成任何多余的拷贝，同时完美转发(传递)了函数的实参给了内部调用的其他函数
// std::forward 和 std::move 一样，没有做任何事情，std::move 单纯的将左值转化为右值
// std::forward 也只是单纯的将参数做了一个类型的转
// 从现象上来看， std::forward<T>(v) 和 static_cast<T&&>(v) 是完全一样的
void test_left_right_ref(){
    compare_right();
    test_reference();
    test_move();
    test_pass();
    cout<<"---------------------"<<endl;
    test_pass_forward();
}

