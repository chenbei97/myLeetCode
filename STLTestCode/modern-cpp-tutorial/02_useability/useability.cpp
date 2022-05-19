/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 10:17:35
 * @LastEditTime: 2022-05-19 15:02:43
 * @Description: useability.cpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\useability.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o useability -std=c++20 useability.cpp
.\useability
*/
#include <iostream>
#include <vector>
#include "nullptr_NULL.hpp"
#include "constexpr.hpp"
#include "if_switch.hpp"
#include "initializer_list.hpp"
#include "tuple.hpp"
#include "auto_decltype.hpp"
#include "if_constexpr.hpp"
#include "template.hpp"
#include "constructor.hpp"
#include "enum_class.hpp"
using namespace std;
int main()
{
    /*
        这里主要谈及语言可用性的强化
        1. nullptr和NULL,0是不同的
            传统c++会认为NULL是((void*)0),也有直接定义为0的情况
            C++不允许直接将 void * 隐式转换到其他类型,例如
                char *ch = NULL; // 没有了void*隐式转换的C++只好将NULL定义为 0
            那么foo(NULL),这个语句将会去调用foo(int)，从而导致代码违反直觉
            为了解决这个问题,C++11引入了nullptr关键字,专门用来区分空指针、0
            而nullptr的类型为 nullptr_t,能够隐式的转换为任何指针或成员指针的类型,也能和他们进行相等或者不等的比较
        2. C++本身已经具备了常量表达式的概念constexpr
            编译器能够在编译时就把这些表达式直接优化并植入到程序运行时，将能增加程序的性能
            constexpr关键字可以在if语句中声明常量表达式的判断条件,可见if_constexpr.hpp
        3. if_switch语句强化
            在传统C++ 中,变量的声明虽然能够位于任何位置
            甚至于for语句内能够声明一个临时变量int,但始终没有办法在 if 和 switch 语句中声明一个临时的变量
            代码中可以看到itr这一变量是定义在整个test_if_switch()的作用域内的
            这导致当我们需要再次遍历整个 std::vector时,需要重新命名另一个变量
            C++17 消除了这一限制，使得我们可以在 if（或 switch）中完成这一操作
        4. 允许初始化列表initializer_list
        5. 允许结构化绑定
            结构化绑定提供了类似其他语言中提供的多返回值的功能
            C++11 新增了 std::tuple 容器用于构造一个元组,但C++11/14 并没有提供一种简单的方法直接从元组中拿到并定义元组中的元素
            尽管我们可以使用 std::tie 对元组进行拆包，但我们依然必须非常清楚这个元组包含多少个对象，各个对象是什么类型，非常麻烦
            现在允许使用auto[x,y,z]来自动拆包推导
        6.  引入了auto和 decltype实现类型推导
            使用 auto 进行类型推导的一个最为常见而且显著的例子就是迭代器
            for(vector<int>::const_iterator it = vec.cbegin(); itr != vec.cend(); ++it)
            使用for (auto it = vec.cbegin(); it != vec.cend(); ++it)更简洁
            C++ 20 起，auto 甚至能用于函数传参
            auto 还不能用于推导数组类型
            decltype 关键字是为了解决auto关键字只能对变量进行类型推导的缺陷而出现的
            还可以进行尾类型推导,利用auto关键字将返回类型后置
            c++14之后支持decltype(auto),用于对转发函数或封装的返回类型进行推导
                使我们无需显式的指定 decltype 的参数表达式
        7.  模板特性增强
            支持外部模板,连续的右尖括号将变得合法,支持类型别名模板(using实现)
            一个比较常用的黑魔法为变长参数模板,即template<typename... Ts> class Magic
            模板类 Magic 的对象，能够接受不受限制个数的 typename 作为模板的形式参数
            还引入递归模板参数,变模参数展开,初始化列表展开,折叠表达式和非类型模板参数推导
        8. 面向对象增强
            引入委托构造函数,引入继承构造函数
            C++11引入了 override 和 final 避免意外重载虚函数并限定不允许再重载
            引入显式禁用默认函数
        9. 强类型枚举
    */
   // 1. nullptr和NULL,0是不同的
    compare_nullptr_NULL(); // 输出中我们可以看出,NULL不同于0与 nullptr
    // 2. C++本身已经具备了常量表达式的概念
    test_constexpr();
    test_if_constexpr();
    // 3. if_switch语句强化
    test_if_switch();
    // 4. 允许初始化列表initializer_list
    test_initializer_list();
    // 5. 允许结构化绑定
    test_tuple();
    // 6.  引入了auto和 decltype实现类型推导
    test_auto_deltype();
    // 7. 模板特性增强
    test_template();
    // 8. 面向对象增强
    test_constructor();
    // 9. 强类型枚举
    test_enum_class();
    return 0;
}