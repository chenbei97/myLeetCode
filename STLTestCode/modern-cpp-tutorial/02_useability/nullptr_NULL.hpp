/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 10:20:49
 * @LastEditTime: 2022-05-19 10:26:42
 * @Description: nullptr_NULL.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\nullptr_NULL.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <type_traits>
void foo(char *) {
    std::cout << "foo(char*) is called" << std::endl;
}
void foo(int i) {
    std::cout << "foo(int) is called" << std::endl;
}
void compare_nullptr_NULL(){
    if (std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl; // 如果NULL和0是同一类型，则输出"NULL == 0"
    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == (void *)0" << std::endl; // 如果NULL和(void *)0是同一类型，则输出"NULL == (void *)0"
    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
        std::cout << "NULL == nullptr" << std::endl; // 如果NULL和nullptr是同一类型，则输出"NULL == nullptr"

    foo(0);          // 调用 foo(int)
    //foo(NULL);    // 该行不能通过编译
    foo(nullptr);    // 调用 foo(char*)
    // 输出中我们可以看出,NULL不同于0与 nullptr
}