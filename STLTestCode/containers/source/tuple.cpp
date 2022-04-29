/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:56:35
 * @LastEditTime: 2022-04-29 10:30:32
 * @Description: test tuple<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\tuple.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\tuple_g++ tuple.cpp
..\output\tuple_g++.exe
cl /Fo"..\output\tuple_cl" /Fe"..\output\tuple_cl.exe" /std:c++latest ".\tuple.cpp"
..\output\tuple_cl.exe
*/
#include <iostream>
#include <tuple>
#include <string>
#include <iterator>
using namespace std;
int main()
{
    // 主要是替代pair,不仅支持2个还可以支持多个模板参数
    tuple<int, string, double> t1(1, "hello", 3.14);
    cout<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1)<<endl; // 1 hello 3.14
    // 还可以借助tie来获取元素的值
    int a;
    string b;
    double c;
    std::tie(a, b, c) = t1;
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl; // a = 1 b = hello c = 3.14
    a = 0;
    // 如果不想要某个位置的值，可以用ignore来忽略
    std::tie(std::ignore, b, c);
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl; // a = 0 b = hello c = 3.14

    // 因为支持多个,所以取消了first,second来访问元素

    // 类似make_pair,可以通过make_tuple来创建tuple
    tuple<int, string, double> t2 = make_tuple(2, "world", 3.14);
    cout<<get<0>(t2)<<" "<<get<1>(t2)<<" "<<get<2>(t2)<<endl; // 2 world 3.14

    // tuple的构造函数
    tuple<int, string, double> t3(t1);
    tuple<int, string, double> t4 = t1;

    // forward_as_tuple也可以接收右值引用,tie函数就只能接受左值
    tuple<int, string, double> t5 = forward_as_tuple(1, "hello", 3.14);
    tie(a, b, c) = forward_as_tuple(1, "hello", 3.14);
    cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl; // a = 1 b = hello c = 3.14

    std::tuple<int, std::string, double, int, std::string, double> t6 = tuple_cat(t1, t2); // 将t1和t2连接起来
    auto t7 = tuple_cat(t1, t2, t3); // 将t1,t2,t3连接起来

    tuple_element<0, tuple<int, string, double>>::type a1; // 获取第一个元素的类型
    tuple_element<1, tuple<int, string, double>>::type b1; // 获取第二个元素的类型
    cout<<"decltype(a1) = "<<typeid(decltype(a1)).name()<<endl; // decltype(a1) = int
    cout<<"decltype(b1) = "<<typeid(decltype(b1)).name()<<endl; // decltype(b1) = class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
    
    // 可以通过tuple_size来获取元素个数
    cout<<"tuple_size(t1) = "<<tuple_size<decltype(t1)>::value<<endl; // tuple_size(t1) = 3
    return 0;
}