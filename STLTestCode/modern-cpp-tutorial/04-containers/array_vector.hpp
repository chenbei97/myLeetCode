/*** 
 * @Author: chenbei
 * @Date: 2022-05-21 09:04:50
 * @LastEditTime: 2022-05-21 09:38:47
 * @Description: array_vector.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\04-containers\array_vector.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
// 1. 为什么要引入 std::array 而不是直接使用 std::vector
// 与 std::vector 不同，std::array 对象的大小是固定的
// std::vector 是自动扩容的，当存入大量的数据后，并且对容器进行了删除操作
// 容器并不会自动归还被删除元素相应的内存，这时候就需要手动运行 shrink_to_fit() 释放这部分内存
void test_vector(){
    std::vector<int> v;
    std::cout << "size:" << v.size() << std::endl;         // 输出 0
    std::cout << "capacity:" << v.capacity() << std::endl; // 输出 0

    // 如下可看出 std::vector 的存储是自动管理的，按需自动扩张
    // 但是如果空间不足，需要重新分配更多内存，而重分配内存通常是性能上有开销的操作
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout<<"after push_back:\n";
    std::cout << "size:" << v.size() << std::endl;         // 输出 3
    std::cout << "capacity:" << v.capacity() << std::endl; // 输出 4
    // 这里的自动扩张逻辑与 Golang 的 slice 很像
    std::cout<<"continue push_back:\n";
    v.push_back(4);
    v.push_back(5);
    std::cout << "size:" << v.size() << std::endl;         // 输出 5
    std::cout << "capacity:" << v.capacity() << std::endl; // 输出 8

    // 如下可看出容器虽然清空了元素，但是被清空元素的内存并没有归还
    v.clear();                                             
    std::cout << "size:" << v.size() << std::endl;         // 输出 0
    std::cout << "capacity:" << v.capacity() << std::endl; // 输出 8

    // 额外内存可通过 shrink_to_fit() 调用返回给系统
    v.shrink_to_fit();
    std::cout << "size:" << v.size() << std::endl;         // 输出 0
    std::cout << "capacity:" << v.capacity() << std::endl; // 输出 0
}
// 2. 已经有了传统数组，为什么要用 std::array
// 使用 std::array 能够让代码变得更加现代化，而且封装了一些操作函数，比如获取数组大小以及检查是否非空
// 还能够友好的使用标准库中的容器算法，比如 std::sort()
void test_array(){
    std::array<int, 4> arr = {1, 2, 3, 4};

    cout<<boolalpha<<"is empty? "<<arr.empty()<<endl; // 检查容器是否为空
    cout<<"size = " << arr.size() << endl;  // 返回容纳的元素数

    // 迭代器支持
    for (auto &i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    // 可以用 lambda 表达式排序,因为array有迭代器begin,end支持
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return b < a;
    });

    // 数组大小参数必须是常量表达式
    constexpr int len = 4;
    std::array<int, len> arr1 = {1, 2, 3, 4};
    const int len1 = 5;
    std::array<int, len1> arr2 = {1, 2, 3, 4, 5};

    // 非法,不同于 C 风格数组，std::array 不会自动退化成 T*
    // int *arr_p = arr;
}
// 用上了 std::array 时，难免会遇到要将其兼容 C 风格的接口,可以使用2种方法
void foo_array(int *p, int len) {
    cout<<"p's addr = "<<p<<" len = "<<len<<endl;
    return;
}
void test_array_interface(){
    std::array<int, 4> arr = {1,2,3,4};
    // C 风格接口传参
    // foo_array(arr, arr.size()); // 非法, 无法隐式转换
    foo_array(&arr[0], arr.size()); // 1.可以取地址传递,显式传递1个int*指针
    foo_array(arr.data(), arr.size()); // 2.可以使用data()方法传递,显式传递1个int*指针 
}





void test_array_vector(){
    test_vector();
    test_array();
    test_array_interface();
}