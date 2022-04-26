/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 11:08:02
 * @LastEditTime: 2022-04-26 11:44:26
 * @Description: test array<T,size>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\array.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\array_g++ array.cpp
..\output\array_g++.exe
cl /Fo"..\output\array_cl" /Fe"..\output\array_cl.exe" /std:c++latest ".\array.cpp"
..\output\array_cl.exe
*/
#include <iostream>
#include <array>
using namespace std;
int main()
{
    // array要求给出类型和大小,因为array是固定size的类
    // 如果不给出size,则默认为0
    // 如果给出size,则不能再改变size
    array<int, 5> a = {1, 2, 3, 4, 5};
    // 有一些方法
    cout<<"a.size() = "<<a.size()<<endl; // 5
    cout<<"a.max_size() = "<<a.max_size()<<endl; // 5
    cout<<"a.empty() = "<<a.empty()<<endl; // 0
    cout<<"a.front() = "<<a.front()<<endl;// 1
    cout<<"a.back() = "<<a.back()<<endl; // 5
    cout<<"a.data() = "<<a.data()<<endl; // 0xe15f3ff7c0
    // 可以使用begin和end来访问数组
    cout<<"a.begin() = "<<*a.begin()<<endl; // 1
    cout<<"a.end() = "<<*a.end()<<endl; // 32758
    // 可以使用at来访问数组
    cout<<"a.at(1) = "<<a.at(1)<<endl; // 2
    // 使用fill来填充数组
    a.fill(0);
    for(auto i : a) cout<<i<<" "; // 0 0 0 0 0
    cout<<endl;
    // 要求访问数组迭代器不改变数组元素可以使用cbegin和cend
    a[0] = 1;a[1] = 2;a[2] = 3;a[3] = 4;a[4] = 5;
    cout<<"a.cbegin() = "<<*a.cbegin()<<endl; // 1
    cout<<"a.cend() = "<<*a.cend()<<endl;// 32758
    // 还使用rbegin和rend来访问数组,这两个迭代器是反向迭代器,可以倒序访问
    array<int,5>::const_reverse_iterator rit = a.rbegin(); // 指向最后一个元素
    while (rit != a.rend())
    {
        cout<<*rit<<" "; // 5 4 3 2 1
        ++rit; // 从后向前移动一个元素
    }
    cout<<endl;
    return 0;
}