/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 13:54:01
 * @LastEditTime: 2022-05-19 14:38:53
 * @Description: template.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\template.hpp
 * @Signature: A boy without dreams
 */
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;
// 模板只有在使用时才会被编译器实例化
// 只要在每个编译单元（文件）中编译的代码中遇到了被完整定义的模板，都会实例化
// 这就产生了重复实例化而导致的编译时间的增加,并且，我们没有办法通知编译器不要触发模板的实例化
// C++11引入了外部模板,扩充了原来的强制编译器在特定位置实例化模板的语法
// 使我们能够显式的通知编译器何时进行模板的实例化
template class std::vector<bool>;          // 强行实例化
extern template class std::vector<double>; // 不在该当前编译文件中实例化模板

// 尖括号 ">",C++11 开始，连续的右尖括号将变得合法，并且能够顺利通过编译
std::vector<std::vector<int>> matrix;

// 类型别名模板,模板是用来产生类型的
// typedef 可以为类型定义一个新的名称，但是却没有办法为模板定义一个新的名称。因为，模板不是类型
template<typename T, typename U>
class MagicType {
public:
    T dark;
    U magic;
};
// 不合法
// template<typename T>
// typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;

// C++11 使用 using 引入了下面这种形式的写法，并且同时支持对传统 typedef 相同的功效
typedef int (*process)(void *); // 函数指针的别名是process
using NewProcess = int(*)(void *); // 使用using代替typedef也可以
template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>; // using允许模板别名

// 一个比较常用的黑魔法为变长参数模板,即template<typename... Ts> class Magic
// 模板类 Magic 的对象，能够接受不受限制个数的 typename 作为模板的形式参数
template<typename... Ts> class Magic;

// class Magic<int,std::vector<int>,
//             std::map<std::string,std::vector<int>>>
//             darkMagic; // 定义模板类的实例,可以传入任意个参数进行实例化
// 既然是任意形式，所以个数为 0 的模板参数也是可以的：class Magic<> nothing;
// class Magic<> nothing; 
// 不过实际测试来看g++不允许这种形式的模板类的实例化,has incomplete type and cannot be defined

// 如果不希望产生的模板参数个数为 0，可以手动的定义至少一个模板参数
template<typename Require, typename... Args> class newMagic;

// 变长参数模板也能被直接调整到到模板函数上
template<typename T, typename... Ts>
void printf1(T value, Ts... args);
template<typename... Args> void newPrintf(const std::string &str, Args... args){
    printf1(str, args...);
    printf("\n");
}
// 定义了变长的模板参数，如何对参数进行解包
// 可以使用 sizeof... 来计算参数的个数
template<typename... Ts> // 可以传递任意个参数给 magic 函数
void magic(Ts... args) {
    std::cout << sizeof...(args) << " ";
}

// 递归模板函数
template<typename T0>
void printf1(T0 value) {
    std::cout << value << " ";
}
template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << " ";
    printf1(args...);
}

// 变模参数展开
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << " ";
    if constexpr (sizeof...(t) > 0) printf2(t...); // 如果确实有参数，就递归调用
}

 // 递归模板函数是一种标准的做法，但缺点显而易见的在于必须定义一个终止递归的函数
 template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << " ";
    (void) std::initializer_list<T>{([&args] { // 引用捕获了args,然后打印args
        std::cout << args << " "; 
    }(), value)...}; // 额外使用了 C++11 中提供的初始化列表以及 Lambda 表达式的特性,(lambda 表达式, value)... 将会被展开
}
// 由于逗号表达式的出现，首先会执行前面的 lambda 表达式，完成参数的输出
// 为了避免编译器警告，我们可以将 std::initializer_list 显式的转为 void

// 折叠表达式
template<typename ... T>
auto sum_t(T ... t) {
    return (t + ...);
}

// 非类型模板参数推导
// 1.这是类型模板参数
template <typename T, typename U>
auto add_t(T t, U u) {
    return t+u;
}
// 2.这是非类型模板参数
template <typename T, int BufSize>
class buffer_t {
public:
    T& alloc();
    void free(T& item);
private:
    T data[BufSize];
};
buffer_t<int, 100> buf; // 这种模板参数形式下，我们可以将 100 作为模板的参数进行传递
// 配合auto也是可以的
template <auto value> void foo_t() {
    std::cout << value << std::endl;
    return;
}
void test_template(){
    std::cout<<"magic()---------------->\n";
    magic(1,2,3,4,5,6,7,8,9,10); 
    magic(); 
    magic(1); 
    magic(1, ""); 
    printf("\n"); // 10,0,1,2
    const string onetwothree = string("onetwothree");
    newPrintf<const char*,double,int,char,float,bool>
        (onetwothree,"hello",1.3,5,'b',3.7f,true); // 输出onetwothree hello 1.3 5 b 3.7 1
    printf1(1, 2, "123", 1.1); // 输出1 2 123 1.1
    printf("\n"); 
    printf2(1, 2, "123", 1.1); // 输出1 2 123 1.1
    printf("\n");
    printf3(1, 2, "123", 1.1); // 输出1 2 123 1.1
    printf("\n");
    std::cout << sum_t(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
    foo_t<1>();
}