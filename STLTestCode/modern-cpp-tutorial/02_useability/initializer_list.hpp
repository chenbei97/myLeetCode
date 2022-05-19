/*** 
 * @Author: chenbei
 * @Date: 2022-05-19 10:48:28
 * @LastEditTime: 2022-05-19 10:54:23
 * @Description: initializer_list.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\02_useability\initializer_list.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <initializer_list>
class Foo {
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};
class MagicFoo {
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list) { // 允许初始化列表构造
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }
    void foo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();
            it != list.end(); ++it) vec.push_back(*it);
    }
};
void test_initializer_list(){
    // before C++11
    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout<<std::endl;

    // now use initializer_list
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    magicFoo.foo({6,7,8,9});
}
