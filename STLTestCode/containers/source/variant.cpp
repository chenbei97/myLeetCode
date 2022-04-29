/*** 
 * @Author: chenbei
 * @Date: 2022-04-29 11:24:18
 * @LastEditTime: 2022-04-29 11:34:24
 * @Description: test for variant
 * @FilePath: \myLeetCode\STLTestCode\containers\source\variant.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\variant_g++ variant.cpp
..\output\variant_g++.exe
cl /Fo"..\output\variant_cl" /Fe"..\output\variant_cl.exe" /std:c++latest ".\variant.cpp"
..\output\variant_cl.exe
*/
#include <iostream>
#include <variant>
#include <string>
#include <iterator>
using namespace std;
int main()
{
    // variant可以存储任意类型的值,和optional的区别是:optional只能存储一个值,而variant可以存储多个值
    variant<int, double,string> a;
    cout << "a.index() = " << a.index() << endl; // 0,默认使用的第0种类型
    // 可以初始化为任意一种类型
    a = 1;
    cout << "a.index() = " << a.index() << endl; // 0
    a = 2.0;
    cout << "a.index() = " << a.index() << endl; // 1
    a = "hello";
    cout << "a.index() = " << a.index() << endl; // 2

    // 可以插入任意一种类型
    a.emplace<int>(3);
    cout << "a.index() = " << a.index() << endl; // 0
    a.emplace<double>(4.0);
    cout << "a.index() = " << a.index() << endl; // 1
    a.emplace<string>("world");
    cout << "a.index() = " << a.index() << endl; // 2
    
    // 可以进行交换
    // variant<string,int,double> b;
    // b.emplace<double>(5.5);
    // a = 3.14;
    // a.swap(b); // 但是必须是同顺序的,这里不通过
    variant<int, double,string> b;
    b.emplace<double>(5.5);
    a = 3;
    a.swap(b);
    cout << "a.index() = " << a.index() << endl; // 1
    cout << "b.index() = " << b.index() << endl; // 0

    b = a; // 可以赋值
    cout << "b.index() = " << b.index() << endl; // 1

    bool it = b.valueless_by_exception(); // 判断是否为空
    cout << "b.valueless_by_exception() = " << it << endl; // false

    return 0;
}