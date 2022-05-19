/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 10:30:24
 * @LastEditTime: 2022-05-19 10:39:26
 * @Description: constexpr.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\constexpr.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#define LEN 10

int len_foo() {
    int i = 2;
    return i;
}
constexpr int len_foo_constexpr() {
    return 5;
}

constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n-1)+fibonacci(n-2);
}
void test_constexpr(){
    char arr_1[10];                      // 合法
    char arr_2[LEN];                     // 合法

    int len = 10;
    char arr_3[len] = {'1','2','3'};                  // 现在合法,以前不合法
    std::cout <<"arr_3[0] = " << arr_3[0] << std::endl; // 1
    
    const int len_2 = len + 1;
    char arr_4[len_2] = {'a','b'};                // 现在合法,以前不合法
    std::cout<<"arr_4[1] = " << arr_4[1] << std::endl; // b
    
    constexpr int len_2_constexpr = 1 + 2 + 3;
    char arr_4_[len_2_constexpr]={'a','b','c','d','e','f'};         // 以前也合法
    std::cout<<"arr_4_[0] = " << arr_4_[0] << std::endl; // a

    char arr_5[len_foo()+5];          // 以前非法,现在合法
    char arr_6[len_foo_constexpr() + 1]; // 以前也合法

    std::cout << fibonacci(10) << std::endl; // 55
    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    std::cout << fibonacci(LEN+3) << std::endl; // 233
}