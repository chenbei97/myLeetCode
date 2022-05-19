/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 10:43:00
 * @LastEditTime: 2022-05-19 10:46:23
 * @Description: if_switch.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\if_switch.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <algorithm>
void test_if_switch(){
    std::vector<int> vec = {1, 2, 3, 4};

    // 在 c++17 之前
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    // 需要重新定义一个新的变量
    const std::vector<int>::iterator itr2 = std::find(vec.begin(), vec.end(), 3);
    if (itr2 != vec.end()) {
        *itr2 = 4;
    }

    // // 将临时变量放到 if 语句内,将输出 1, 4, 3, 4
    for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
        std::cout << *element << std::endl;
}