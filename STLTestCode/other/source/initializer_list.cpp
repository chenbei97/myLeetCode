/*
 * @Author: chenbei
 * @Date: 2022-04-30 21:39:26
 * @LastEditTime: 2022-04-30 22:00:05
 * @FilePath: \myLeetCode\STLTestCode\other\source\initializer_list.cpp
 * @Description: test for initializer_list
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\initializer_list_g++ initializer_list.cpp
..\output\initializer_list_g++.exe
cl /Fo"..\output\initializer_list_cl" /Fe"..\output\initializer_list_cl.exe" /std:c++latest ".\initializer_list.cpp"
..\output\initializer_list_cl.exe
*/
#include <iostream>
#include <initializer_list>
#include <iterator>
#include <vector>
using namespace std;
// 定义一个结构体
template <class T>
struct S {
    // 构建一个支持初始化列表的结构体
    std::vector<T> v;
    S(std::initializer_list<T> l) : v(l) { // 成员列表初始化
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<T> l) { // 定义个append方法
        v.insert(v.end(), l.begin(), l.end()); // 在v的末尾插入l的元素
    }
    std::pair<const T*, std::size_t> c_arr() const { // 返回pair,其中first是一个指向数组的指针,second是数组的大小
        return {&v[0], v.size()};  // return语句中的复制列表初始化,不是不是std:：initializer_list的用法
    }
};
// 声明一个函数,但是没有实现
template <typename T>
void templated_fn(T) {}
int main()
{
    /*
        初始化列表内部定义的类型
        value_type	T
        reference	const T&
        const_reference	const T&
        size_type	std::size_t
        iterator	const T*
        const_iterator	const T*
    */
    // 初始化列表的构造函数
    initializer_list<int> ilist1 = {1,2,3,4,5};
    // 支持复制构造和等式赋值
    initializer_list<int> ilist2 = ilist1;
    initializer_list<int> ilist3(ilist1);
    
    // 可以通过size获取大小
    cout<<"ilist3 size: "<<ilist3.size()<<endl;

    // 支持迭代器遍历
    for(auto it = ilist3.begin(); it != ilist3.end(); it++)
    {
        cout<<*it<<" "; // 1 2 3 4 5
    }
    cout<<endl;
    // 没有cbegin,cend,rbegin,rend,但是可以借助std::begin,end,rbegin,rend来访问
    for(auto it = std::rbegin(ilist3); it != std::rend(ilist3); it++)
    {
        cout<<*it<<" ";// 5 4 3 2 1
    }
    cout<<endl;

    // 支持列表初始化的结构体测试
    S<int> s = {1, 2, 3, 4, 5}; // 列表初始化
    s.append({6, 7, 8});      // 使用成员方法,就可以添加{}列表了
    std::cout << "The vector size is now " << s.c_arr().second << " ints:\n"; // 返回数组大小
    for (auto n : s.v) // 遍历其成员遍历
        std::cout << n << ' ';
    std::cout << '\n';

    std::cout << "you can directly traverse the range list: \n";
    for (int x : {-1, -2, -3}) // 可以直接遍历范围列表
        std::cout << x << ' ';
    std::cout << '\n';

    auto a1 = {10, 11, 12};   // auto
    std::initializer_list<int> a2 = a1; // 初始化列表
    std::cout << "The list bound to auto has size() = " << a1.size() << '\n';  // 输出列表大小 
    
    // templated_fn({1, 2, 3}); // 不可以使用初始化列表初始化模板函数
    // {1, 2, 3}"不是表达式,所以没有类型也就不能推断T
    // 但是下边的2个做法是可以的,使用std::initializer_list声明或者用其他容器以列表构造出的对象
    templated_fn<std::initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<std::vector<int>>({1, 2, 3});           // also OK

    return 0;
}