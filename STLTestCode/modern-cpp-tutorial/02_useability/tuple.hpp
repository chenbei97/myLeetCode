/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 11:38:39
 * @LastEditTime: 2022-05-19 11:38:39
 * @Description: tuple.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\tuple.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <tuple>
std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}
void test_tuple(){
    auto [x, y, z] = f();
    std::cout << x << ", " << y << ", " << z << std::endl;
}