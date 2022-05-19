/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 13:43:50
 * @LastEditTime: 2022-05-19 13:49:40
 * @Description: if_constexpr.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\if_constexpr.hpp
 * @Signature: A boy without dreams
 */
//  C++11 引入了 constexpr 关键字，它将表达式或函数编译为常量结果
// 如果我们把这一特性引入到条件判断中去，让代码在编译时就完成分支判断，能让程序效率更高
// C++17 将 constexpr 这个关键字引入到 if 语句中，允许在代码中声明常量表达式的判断条件
#include <iostream>
template<typename T>
auto print_type_info_(const T& t) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "integral type" << std::endl;
        return t + 1; // 是整数编译此语句
    } else { // 是浮点数编译此语句
        std::cout << "floating-point type" << std::endl;
        return t + 0.001;
    }
}
template<typename T>
auto print_type_info(const T& t) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "integral type" << std::endl;
        return t + 1; // 是整数编译此语句
    } else { // 是浮点数编译此语句
        std::cout << "floating-point type" << std::endl;
        return t + 0.001;
    }
}
// 编译时，实际代码就会表现为如下
int print_type_info(const int& t) {
    printf("it's an int\n");
    return t + 1;
}
double print_type_info(const double& t) {
    printf("it's a double\n");
    return t + 0.001;
}
void test_if_constexpr(){
    int i = 1;
    double d = 1.0;
    print_type_info(i); // it's an int
    print_type_info(d); // it's a double
    // 三个函数同时存在的话,因为后两个函数更匹配,调用了后2个
    // 如果注释掉后2个函数,输出如下
    print_type_info_(i); // integral type
    print_type_info_(d); // floating-point type
}