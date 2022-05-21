/*** 
 * @Author: chenbei
 * @Date: 2022-05-21 09:02:52
 * @LastEditTime: 2022-05-21 09:49:27
 * @Description: containers.cpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\04-containers\containers.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o containers -std=c++20 containers.cpp
.\containers
*/
#include <iostream>
#include <vector>
#include "array_vector.hpp"
#include "tuple_variant.hpp"
using namespace std;
int main()
{
    /*
        1. 为什么要引入 std::array 而不是直接使用 std::vector
            与 std::vector 不同，std::array 对象的大小是固定的
            std::vector 是自动扩容的，当存入大量的数据后，并且对容器进行了删除操作
            容器并不会自动归还被删除元素相应的内存，这时候就需要手动运行 shrink_to_fit() 释放这部分内存
        2. 已经有了传统数组，为什么要用 std::array
            使用 std::array 能够让代码变得更加现代化，而且封装了一些操作函数，比如获取数组大小以及检查是否非空
            还能够友好的使用标准库中的容器算法，比如 std::sort()
            兼容C风格数组,可以使用&array[0]或者array.data()来传递数组的首地址
        3. std::forward_list 是一个列表容器，使用方法和 std::list 基本类似
           和 std::list 的双向链表的实现不同，std::forward_list 使用单向链表进行实现
           提供了 O(1) 复杂度的元素插入，不支持快速随机访问（这也是链表的特点）
           也是标准库容器中唯一一个不提供 size() 方法的容器
           当不需要双向迭代时，具有比 std::list 更高的空间利用率
        4. 无序容器，unordered_set, unordered_map,unordered_multimap, unordered_multiset
            传统 C++ 中的有序容器std::map/std::set，这些元素内部通过红黑树进行实现
            插入和搜索的平均复杂度均为 O(log(size))
            无序容器中的元素是不进行排序的,内部通过 Hash 表实现，插入和搜索元素的平均复杂度为 O(constant)
            在不关心容器内部元素顺序时，能够获得显著的性能提升
            用法上和set,map区别不大,这里不再说明,可见STLTestCode\\containers\\source\\unordered_set.cpp等
        5. 元组,替代std::pair只能存放2个元素的数据结构
            关于元组的使用有三个核心的函数,std::get(),std::tie(),std::make_tuple()
            分别是获取元素某个元素的值,元组拆包,构造元组
            其中get()传入要获取的元素的索引,c++14之后还支持使用类型来获取变量
            std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
            std::cout << std::get<std::string>(t) << std::endl; // 获取string类型的元素
            std::cout << std::get<3>(t) << std::endl; // 获取第四个元素
            std::cout << std::get<double>(t) << std::endl; // 非法, 引发编译期错误,如果有多个相同类型的就不能使用这种方式

            元组合并与遍历,std::tuple_cat()
            std::tuple 虽然有效，但是标准库提供的功能有限，没办法满足运行期索引和迭代的需求，好在我们还有其他的方法可以自行实现
            
    */
    test_array_vector();
    test_tuple_variant();
    return 0;
}