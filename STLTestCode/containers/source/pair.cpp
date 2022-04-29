/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:57:24
 * @LastEditTime: 2022-04-29 09:50:47
 * @Description: test pair<A,B>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\pair.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\pair_g++ pair.cpp
..\output\pair_g++.exe
cl /Fo"..\output\pair_cl" /Fe"..\output\pair_cl.exe" /std:c++latest ".\pair.cpp"
..\output\pair_cl.exe
*/
#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <tuple> // include tie
using namespace std;
int main()
{
    // 是个成对的元素,可以指定不同类型,获取元素的值可以通过first,second以及get函数
    pair<int, string> p1(1, "hello");
    cout<<p1.first<<" "<<p1.second<<endl; // 1 hello
    cout<<get<0>(p1)<<" "<<get<1>(p1)<<endl; // 1 hello
    // 还可以借助tie来获取元素的值
    int a;
    string b;
    std::tie(a, b) = p1;
    cout<<"a = "<<a<<" b = "<<b<<endl; // a = 1 b = hello

    // 还可以借助make_pair函数创建pair
    pair<int, string> p2 = make_pair(2, "world");
    cout<<p2.first<<" "<<p2.second<<endl; // 2 world
    // 还可以通过swap函数交换两个pair
    pair<int, string> p3(3, "c++");
    swap(p1, p3);
    cout<<p1.first<<" "<<p1.second<<endl; // 3 c++

    // 支持拷贝构造函数
    pair<int, string> p5(p1);
    // 支持赋值运算符
    p5 = p2;

    // pair的元素可以被赋值
    p1.first = 4;
    p1.second = "c++";
    cout<<p1.first<<" "<<p1.second<<endl; // 4 c++
    // pair的元素可以被比较
    pair<int, string> p4(4, "c++");
    if(p1 == p4)
        cout<<"p1 == p4"<<endl;
    else
        cout<<"p1 != p4"<<endl;

    // pair现在主要被tuple替代,可以见tuple.cpp的使用
    return 0;
}