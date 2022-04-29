/*** 
 * @Author: chenbei
 * @Date: 2022-04-29 10:57:22
 * @LastEditTime: 2022-04-29 11:19:42
 * @Description: test optional
 * @FilePath: \myLeetCode\STLTestCode\containers\source\optional.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\optional_g++ optional.cpp
..\output\optional_g++.exe
cl /Fo"..\output\optional_cl" /Fe"..\output\optional_cl.exe" /std:c++latest ".\optional.cpp"
..\output\optional_cl.exe
*/
#include <iostream>
#include <vector>
#include <optional>
#include <iterator>
using namespace std;
int main()
{
    // optional可用于任何类型,可以有值也可以没有值
    optional<int> a;
    cout << "a.has_value() = " << a.has_value() << endl; // 0
    // value_or() 如果optional有值,则返回值,如果没有值,则返回默认值
    cout << "a.value_or(0) = " << a.value_or(0) << endl; // 0
    a = 2;
    cout << "a.has_value() = " << a.has_value() << endl; // 1
    cout << "a.value_or(0) = " << a.value_or(0) << endl; // 2

    
    cout<<"a.value() = "<<a.value()<<endl; // 2
    // 如果optional没有值,则抛出异常
    optional<int> b;
    // cout << "b.value() = " << b.value() << endl; // exception

    // 可以重置optional
    b.reset();
    cout << "b.has_value() = " << b.has_value() << endl; // 0

    // optional还支持emplace
    b.emplace(3);// 如果optional没有值,则把值赋给optional,如果有值,则把值替换
    cout << "b.has_value() = " << b.has_value() << endl; // 1
    cout << "b.value() = " << b.value() << endl; // 3
    b.emplace(4);
    cout << "b.has_value() = " << b.has_value() << endl; // 1
    cout << "b.value() = " << b.value() << endl; // 4

    // optional还支持拷贝
    optional<int> c(2);
    optional<int> d(c);
    cout << "c.has_value() = " << c.has_value() << endl; // 1
    cout << "d.has_value() = " << d.has_value() << endl; // 1
    cout << "c.value() = " << c.value() << endl; // 2
    cout << "d.value() = " << d.value() << endl; // 2

    return 0;
}
